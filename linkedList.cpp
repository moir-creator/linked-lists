#include<iostream>

struct Node {

    int data;
    Node* next;
};

Node* head = nullptr;

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

void addSorted() {
    //как сортировка пузырьком bubblesort
    //по возрастанию 1 .. 10
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

bool removeAll(int value) {
    //минимум двумя способами
    // один способ в 1 строчку или во много строчек (подсказка - bool)
}


void output() {
    Node* tmp = head;
    for ( ; tmp != nullptr; tmp = tmp->next) {
      std::cout << tmp->data << " ";}
}


//+ 1. Сделать вывод отдельным методом output
//2. Сделать метод addFirst (вставлять новые элементы в начало списка) вывод должен получится 3,2,1
//3. Удаление по значению (сделать дистракт ячейки и сохранить целостность списка); методом remove
//4.

int main() {

   addFirst(2);
   addFirst(3);
   addFirst(1);
   /*addFirst(2);
    addFirst(3);
    addFirst(4);
    addFirst(5);*/

    remove(3);
    output();

    //2 шаг
    /*Node* first = new Node (1, nullptr);
   head = first;

   Node* second = new Node (2, nullptr);
   head = second;
   second->next = first;

   Node* third = new Node (3, nullptr);
   head = third;
   third->next = second;*/

    //1 шаг
    /*Node first = {1, nullptr};
    head = &first;

    Node second = {2, nullptr};
    head = &second;
    second.next = &first;

    Node third = {3, nullptr};
    head = &third;
    third.next = &second;*/




    return 0;
}