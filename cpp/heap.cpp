#include <iostream>
#include <utility>
#include <vector>

class Heap {
public:
  std::vector<int> harray;
  Heap(int size) : harray(size) {}

  int size() { return harray.size(); }
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }

  void max_heapify(int index, int size) {
    if (index >= size) {
      std::cout << "invalid size";
      return;
    }
    int l = left(index);
    int r = right(index);
    int max = index;
    if (l < size && harray[max] < harray[l])
      max = l;
    if (r < size && harray[max] < harray[r])
      max = r;
    if (max != index) {
      std::swap(harray[max], harray[index]);
      max_heapify(max, size);
    }
  }

  void heap_sort() {
    int n = size();

    for (int i = n / 2 - 1; i >= 0; i--)
      max_heapify(i, n);
    for (int i = n - 1; i > 0; i--) {
      std::swap(harray[0], harray[i]);
      max_heapify(0, i);
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> v = std::vector({2, 3, 7, 5, 1, 12, 4, 21, 13, 76, 34});
  Heap heap(v.size());
  heap.harray = v;

  heap.heap_sort();

  for (auto i : heap.harray)
    std::cout << i << " ";

  std::cout << std::endl;
}
