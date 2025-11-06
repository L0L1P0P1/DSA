#include <iostream>

struct Node {
  int data;
  Node *next;
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
  Node *sentinel;
  Node *&head;
  Node *tail;
  int len;

public:
  LinkedList() : sentinel(new Node(0)), head(sentinel), tail(sentinel), len(0) {
    sentinel->next = sentinel;
  }

  void append(int value) {
    Node *newNode = new Node(value);
    newNode->next = sentinel;
    if (len == 0) {
      sentinel->next = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    len++;
  }
  void display() {
    if (len == 0) {
      std::cout << "List is empty\n";
      return;
    }

    Node *probe = sentinel->next;
    while (probe != sentinel) {
      std::cout << probe->data;
      if (probe->next != sentinel)
        std::cout << " -> ";
      probe = probe->next;
    }
    std::cout << " -> sentinel\n";
  }
  int &operator[](int index) {
    if (index < 0 || index >= len) {
      std::cout << "out of range";
    }
    Node *probe = head;
    for (int i = 0; i < index; i++)
      probe = probe->next;
    return probe->data;
  }

  int pop(int index) {
    if (index < 0 || index >= len) {
      std::cout << "out of range";
      return -1;
    }
    Node *probe = sentinel;
    for (int i = 0; i < index; i++)
      probe = probe->next;
    Node *target = probe->next;
    probe->next = target->next;
    if (target == tail) {
      tail = probe;
    }
    int value = target->data;
    delete target;
    len--;
    return value;
  }

  void insert(int index, int value) {
    if (index < 0 || index > len) {
      std::cout << "out of range \n";
      return;
    }
    if (index == len) {
      append(value);
      return;
    }
    Node *newNode = new Node(value);
    Node *probe = sentinel;
    for (int i = 0; i < index; i++)
      probe = probe->next;
    Node *temp = probe->next;
    probe->next = newNode;
    newNode->next = temp;
    len++;
  }

  void push(int value) { insert(0, value); }

  void reverse() {
    if (len < 2)
      return;
    tail = head;

    Node *a = sentinel;
    Node *b = head;
    Node *c = head->next;

    while (c != sentinel) {
      b->next = a;
      a = b;
      b = c;
      c = c->next;
    }
    c->next = b;
    b->next = a;
  }

  ~LinkedList() {
    if (len == 0) {
      delete sentinel;
      return;
    }
    Node *a = head;
    while (a != sentinel) {
      Node *target = a;
      a = a->next;
      delete target;
    }
    delete sentinel;
  }
};

int main() {
  LinkedList dll;
  dll.append(1);
  dll.append(2);
  dll.append(3);
  dll.append(4);
  dll.append(5);
  dll.append(6);
  dll.pop(0);
  dll.display();
  dll.reverse();
  dll.display();
  dll.insert(1, 2);
  dll.display();
  dll.reverse();
  dll.display();
}
