#include <iostream>

struct DNode {
  int data;
  DNode *next;
  DNode *prev;
  DNode(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DLinkedList {
private:
  DNode *head;
  DNode *tail;
  int len = 0;

public:
  DLinkedList() {
    head = nullptr;
    tail = nullptr;
  }
  void append(int value) {
    DNode *newNode = new DNode(value);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
      len++;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    len++;
  }
  void display() {
    DNode *probe = head;
    if (probe == nullptr)
      std::cout << "list empty! \n";
    while (probe != nullptr) {
      std::cout << probe->data << " -> ";
      probe = probe->next;
    }
    std::cout << "NULL\n";
  }
  void remove(int value) {
    DNode *probe = head;
    if (probe->data == value) {
      head = head->next;
      head->prev = nullptr;
      delete probe;
      len--;
      return;
    }
    probe = probe->next;
    while (probe != nullptr) {
      if (probe->data == value) {
        if (probe->next == nullptr) {
          tail = probe->prev;
          tail->next = nullptr;
          delete probe;
          len--;
          return;
        }
        probe->next->prev = probe->prev;
        probe->prev->next = probe->next;
        delete probe;
        len--;
        return;
      }
      probe = probe->next;
    }
    std::cout << "value not found! \n";
    return;
  }
  void insert(int index, int value) {
    DNode *newNode = new DNode(value);
    if (index < 0) {
      std::cout << "error \n";
      return;
    } else if (index == 0) {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
      len++;
      return;
    } else {
      DNode *probe = head;
      for (int i = 1; i < index; i++) {
        if (probe == nullptr) {
          std::cout << "out of range \n";
          return;
        }
        probe = probe->next;
      }
      if (probe->next == nullptr) {
        probe->next = newNode;
        newNode->prev = probe->next;
        tail = newNode;
        len++;
        return;
      }
      newNode->next = probe->next;
      newNode->prev = probe;
      probe->next->prev = newNode;
      probe->next = newNode;
      len++;
      return;
    }
  }
  void reverse() {
    if (len < 2) {
      return;
    }

    DNode *a = head;
    DNode *b = a->next;
    a->prev = b;
    a->next = nullptr;
    tail = a;

    while (b->next != nullptr) {
      a = b;
      b = b->next;
      a->next = a->prev;
      a->prev = b;
    }
    b->next = a;
    b->prev = nullptr;
    head = b;
  }
  ~DLinkedList() {
    DNode *probe = head->next;
    while (probe->next != nullptr) {
      delete probe->prev;
      probe = probe->next;
    }
    delete probe;
  }
};

int main() {
  DLinkedList dll;
  dll.append(1);
  dll.append(2);
  dll.append(3);
  dll.remove(2);
  dll.display();
  dll.reverse();
  dll.display();
  dll.insert(1, 2);
  dll.display();
  dll.reverse();
  dll.display();
}
