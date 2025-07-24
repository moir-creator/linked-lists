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
   //сортировка элементов списка по их значению

   Node* tmp = head;
   Node* m = head;
   Node* prev = nullptr;
   //поиск самого минимального значения, и его отдельное сохранение
   while (tmp->next != nullptr) {
       if (tmp->next->data < m->data) {
           prev = tmp;
           m = tmp->next;
       }
       tmp = tmp->next;
   }
    //назначаем в head минимальный элемент списка сохраняя целостность списка
   prev->next = prev->next->next;
   m->next = head;
   head = m;

   //новый цикл для сортировки тела списка
   tmp = head;
   prev = head;
   m = head;
   Node* maximum = nullptr;
   Node* maximum2 = nullptr;

   //вывод на экран для самопроверки:
   /*std::cout << "tmp->data: " << tmp->data << std::endl;
   std::cout << "tmp->next->data: " << tmp->next->data << std::endl;
   std::cout << "preview value: " << prev->data << std::endl;*/

   while (tmp->next->next != nullptr) {
       if (tmp->data > tmp->next->data) {
               m = tmp->next;
               maximum = tmp;
               maximum2 = tmp->next->next;
               prev->next = m;
               m->next = maximum;
               maximum->next = maximum2;

               tmp = head;

               //вывод значений внутри цикла для самоконтроля
               std::cout << "preview next: " << prev->next->data << std::endl;
               std::cout << "maximum next after: " << maximum->next->data << std::endl;

               std::cout << "minimal value: " << m->data << std::endl;
               std::cout << "preview value: " << prev->data << std::endl;
               //return для отслеживания первой итерации и порядка связывания элементов:
               //return;
           }
           prev = tmp;
           tmp = tmp->next;
           std::cout << "exit->tmp->next->data: " << tmp->next->data << std::endl;
   }
            //проверка вывода итераций после выхода из цикла, tmp находится на последних элементах
            std::cout << "FINAL exit->tmp->data: " << tmp->data << std::endl;
            std::cout << "FINAL exit->tmp->next->data: " << tmp->next->data << std::endl;
		    std::cout << "FINAL preview value: " << prev->data << std::endl;

   //работа с конечными элементами списка, где tmp->next == nullptr;
   if (tmp->data > tmp->next->data) {
			    maximum = tmp;
				m = tmp->next;

			    prev->next = tmp->next;
				tmp->next = nullptr;
				prev->next->next = tmp;
                //контрольный вывод tmp для определения его точного значения
				std::cout << "exit->tmp->data: " << tmp->data << std::endl;
			    std::cout << "cycle nullptr is done  " << std::endl;
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

bool removeAll (int value) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == value) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    Node* tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->data == value) {
            Node* t = tmp->next;
            tmp->next = tmp->next->next;
            delete t;
        }
        tmp = tmp->next;
    }
    return true;
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

   //список для проверки меотда removeAll:
   /*add(7);
   add(1);
   add(2);
   add(7);
   add(3);
   add(4);
   add(7);
   add(5);*/

   add(6);
   add(2);
   add(7);
   add(3);
   add(1);
   add(4);
   add(5);
   add(9);
   add(8);

    addSorted();
    //removeAll(7);
    output();

    return 0;
}