#include<iostream>
struct Node {
    int data;
    Node* next;
};

// 1. сделать 2 списка с двумя head
// 2. объединить два списка в один
// 3. объединить с сортировкой

Node* head = nullptr;
Node* headTwo = nullptr;

void addFirst(int data) {
    head = new Node(data, head);
}

void add(int data) {
    if (head == nullptr) {
        head = new Node (data, nullptr);
    } else {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node (data, nullptr);
    }
}

void addSorted(int value) {

    if (head == nullptr) {
        head = new Node (value, nullptr);
        return;
    }
    if (value < head->data) {
        head = new Node (value, head);
        return;
    }
    Node* tmp = head->next;
    Node* prev = head;
    while (tmp != nullptr && tmp->data < value) {
        prev = tmp;
        tmp = tmp->next;
    }
    tmp = new Node (value, prev->next);
    prev->next = tmp;
}

void bubleSort_() {
    Node* tmp = head;
    head = nullptr;
    while (tmp != nullptr) {
        addSorted(tmp->data);
        Node* t = tmp;
        tmp = tmp->next;
        delete t;
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
            head->next = tmp;
            changed = true;
        }
        Node* tmp = head;
        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            if (tmp->next->data > tmp->next->next->data) {
                Node* t = tmp->next;
                tmp->next = tmp->next->next;
                t->next = tmp->next->next;
                tmp->next->next = t;
                changed = true;
            }
            tmp = tmp->next;
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
        return true;
    }
    Node* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->data == value) {
            Node* t = tmp->next;
            tmp->next = tmp->next->next;
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

bool removeAll (int value) {
    bool result = false;
    if (head == nullptr) {
        return result;
    }
    while (head !=nullptr && head->data == value) {
        result = true;
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    if (head == nullptr) {
        return result;
    }
    Node* tmp = head;
    while (tmp != nullptr) {
        if (tmp->next != nullptr && tmp->next->data == value) {
            result = true;
            Node* t = tmp->next;
            tmp->next = tmp->next->next;
            delete t;
        }
        tmp = tmp->next;
    }
    return result;
}


void output() {
    Node* tmp = head;
    std::cout << "list One: ";
    for ( ; tmp != nullptr; tmp = tmp->next) {
      std::cout << tmp->data << " ";}
    std::cout << std::endl;
}

void outputTwo() {
    Node* tmp = headTwo;
    std::cout << "list Two: ";
    for ( ; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->data << " ";}
    std::cout << std::endl;
}

void copyList() {
    headTwo = head;
    head = nullptr;
}

void addTwo(int data) {
    if (headTwo == nullptr) {
        headTwo = new Node (data, nullptr);
    } else {
        Node* tmp = headTwo;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node (data, nullptr);
    }
}


void join() {
    Node* tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }   tmp->next = headTwo;
        headTwo = nullptr;
}

void joinSorted() {
    join();
    bubleSort_();
    }

int main() {

    add(9);
    add(7);
    add(3);
    add(5);
    copyList();

    add(19);
    add(15);
    add(17);
    add(13);

    output();
    outputTwo();

    joinSorted();
    //std::cout << "Join is done!" << std::endl;
    output();
    outputTwo();
    //bubleSort();
    //std::cout << "Sort is done!" << std::endl;
    //output();

   //список для проверки меотда removeAll:
   /*add(7);
   add(1);
   add(3);
   add(7);
   add(3);
   add(4);
   add(3);
   add(5);
   removeAll2(3);//*/

   /*
   add(4);
   add(7);
   add(3);
   add(5);
   add(2);
   add(6);
   add(1);
   bubleSort();
   */

    /*addSorted(1);
    addSorted(3);
    addSorted(4);
    addSorted(2);
    addSorted(6);
    addSorted(8);
    addSorted(1);
    addSorted(14);
    addSorted(10);
    addSorted(2);
    addSorted(16);*/

    //std::cout << removeAll(6) << std::endl;

    return 0;
}
