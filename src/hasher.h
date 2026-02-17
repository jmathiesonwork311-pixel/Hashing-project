
#include <functional>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename hashVal>

// Not calling by reference as making a pointer is inneficient.
size_t myHash(hashVal value) {
  // In-built has function
  return std::hash<hashVal>{}(value);
}

// Calling by reference since faster for list values
template <typename hashVal>
size_t myHash(vector<hashVal>& value) {
  size_t seed = 0;
  for (auto& x : value) {
    seed ^= myHash(x);
  }
  return seed;
}

template <typename hashVal>
// Hashing by sets needs to be done through conisstent methods as order doesn't
// matter
size_t myHash(unordered_set<hashVal>& value) {
  size_t seed = 0;
  for (auto& x : value) {
    seed += myHash(x);
  }
  return seed;
}
template <typename hashVal>
// Hashing by sets needs to be done through conisstent methods as order doesn't
// matter
size_t myHash(set<hashVal>& value) {
  size_t seed = 0;
  for (auto& x : value) {
    seed += myHash(x);
  }
  return seed;
}
