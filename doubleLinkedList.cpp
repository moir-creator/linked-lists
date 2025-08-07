#include <iostream>
struct Node {
    Node* prev;
    int data;
    Node* next;
};

Node* head = nullptr;

void addFirst(int data) {
    head = new Node(nullptr, data, head);
}

void add(int data) {
    if (head == nullptr) {
        head = new Node(nullptr, data, nullptr);
        return;
    }
    else {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(tmp, data, nullptr);
    }
}

void addSorted(int data) {
if (head == nullptr) {
    head = new Node(nullptr, data, nullptr);
    return;
}
if (data < head->data) {
    head = new Node(nullptr, data, head);
    head->next->prev = head;
    return;
    }
Node* tmp = head->next;
Node* prev = head;
    while (tmp != nullptr && tmp->data < data) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = new Node(prev->prev, data, tmp);
    prev->next->prev = prev;
}

void bubleSort_() {
    Node* tmp = head;
    head = nullptr;
    while (tmp != nullptr) {
    addSorted(tmp->data);
        //tmp->prev = tmp;
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
            tmp->prev = head;
            head->next = tmp;
            head->prev = nullptr;
            tmp->next->prev = tmp;
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
                tmp->next->next = t;
                changed = true;
            }
            tmp = tmp->next;
        }
    }
}

void output() {
        Node* tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
}


int main() {

    add(8);
    add(2);
    add(3);
    add(4);
    add(10);
    add(1);
    bubleSort();

    /*addSorted(6);
    addSorted(3);
    addSorted(4);
    addSorted(5);
    addSorted(10);
    addSorted(8);
    addSorted(7);
    addSorted(2);*/



    output();
    return 0;
}
