#include <iostream>
struct Node {
    Node* prev;
    int data;
    Node* next;
};

//добавить tail и его обработку
//Output в прямом и обратном порядке
Node* head = nullptr;
Node* tail = nullptr;

void addFirst(int data) {
    head = new Node(nullptr, data, head);
}

void add(int data) {
    if (head == nullptr) {
        head = new Node(nullptr, data, nullptr);
        tail = head;
        return;
    }
    else {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(tmp, data, nullptr);
        tail = tmp->next;
    }
}

void addSorted(int data) {
if (head == nullptr) {
    head = new Node(nullptr, data, nullptr);
    tail = head;
    return;
}
if (data < head->data) {
    head = new Node(nullptr, data, head);
    head->next->prev = head;
    //tail = head->next;
    return;
    }
Node* tmp = head->next;
Node* p = head;
    while (tmp != nullptr && tmp->data < data) {
        p = tmp;
        tmp = tmp->next;
    }
    p->next = new Node(p->prev, data, tmp);
    p->next->prev = p;
    if (tmp == nullptr) {
        tail = p->next;
    }
    if (p->next->next != nullptr) {
        p->next->next->prev = p->next;
        if (tmp == nullptr) {
            tail = tmp;
        }
    }

}

void bubleSort_() {
    Node* tmp = head;
    head = nullptr;
    while (tmp != nullptr) {
    addSorted(tmp->data);
        tmp = tmp->next;
    }
}

void bubleSort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    bool changed = true;
    while (changed) {
        changed = false;
        if (head->data > head->next->data) {
            Node* tmp = head;
            head = head->next;
            tmp->next = head->next;
            tmp->next->prev = head;
            head->next = tmp;
            head->prev = nullptr;
            head->next->prev = head;
            head->next->next->prev = head->next;
            changed = true;
        }
        Node* tmp = head;
        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            if (tmp->next->data > tmp->next->next->data) {
                Node* t = tmp->next;
                tmp->next = tmp->next->next;
                tmp->next->prev = tmp;
                t->next = tmp->next->next;
                t->prev = tmp->next;
                if (t->next != nullptr) {
                    t->next->prev = t;
                }
                tmp->next->next = t;
                changed = true;
            }
            tmp = tmp->next;
            tail = tmp->next;
        }
    }
}

bool remove (int value) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == value) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
        head->prev = nullptr;
        return true;
    }
    Node* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->data == value) {
            Node* t = tmp->next;
            tmp->next = tmp->next->next;
            tmp->next->prev = tmp;
            delete t;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void removeAll2 (int value) {
    while (remove(value));
}

void output() {
    Node* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void outputReverse() {
    Node* tmp = tail;
    while (tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->prev;
    }
}

int main() {

    add(8);
    add(2);
    //add(4);
    add(3);
    add(4);
    add(10);
    add(1);
    //add(4);
    bubleSort();
    //removeAll2(4);

    /*addSorted(6);
    addSorted(3);
    addSorted(4);
    addSorted(8);
    addSorted(5);
    addSorted(10);
    addSorted(7);
    addSorted(2);
    remove(4);*/



    output();
    outputReverse();

    return 0;
}
