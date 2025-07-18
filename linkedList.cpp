#include<iostream>

struct Node {
    int data;
    Node* next;
    Node(int d, Node* n) : data (d), next(n) {}
};

Node* head = nullptr;

void addFirst(int data) {
    if (head == nullptr) {
        head = new Node(data, nullptr);
    } else {
        Node* tmp = new Node(data, head);
        head = tmp;
    }
}

void add(int data) {
    if (head == nullptr) {
        head = new Node(data, nullptr);
    } else {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node (data, nullptr);
    }
}

void output() {
    Node* tmp = head;
    for ( ; tmp!= nullptr; tmp = tmp->next) {
        std::cout << tmp->data << " ";
    }
}

void distruct(int number) {
    Node* prev = nullptr;
    Node* tmp = head;
    if (head->data == number) {
        head = head->next;
        delete tmp;
    } else {
        while (tmp != nullptr && tmp->data != number) {
            prev = tmp;
            tmp = tmp->next;
        } if (tmp == nullptr) {
            std::cout << "Value " << number << " not found" << std::endl;
        } else {
            prev->next = tmp->next;
            delete tmp;
        }
    }
}

int main() {
    
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    output();

    return 0;
}
