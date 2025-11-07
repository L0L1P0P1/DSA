#include <iostream>
#include <vector>

class Heap {
public:
  std::vector<int> harray;
  Heap(int size) : harray(size) {}

  int size() { return harray.size(); }
  int parent(int i) { return harray[(i + 1) / 2]; }
  int left(int i) { return harray[(i + 1) * 2]; }
  int right(int i) { return harray[(i + 2) * 2]; }

  void max_heapify(int index) {}
};
