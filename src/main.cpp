#include "hashMap.h"
// Test Funtion
int main() {
  hashMap<int, int> a;
  for (int i = 0; i < 40; i++) {
    a.insert(i, i * 3);
  }
  for (int i = 0; i < 40; i++) {
    a.search(i) += 43;
  }
  for (int i = 0; i < 40; i++) {
    cout << a.search(i) << endl;
  }
  a.clear();
  return 0;
}