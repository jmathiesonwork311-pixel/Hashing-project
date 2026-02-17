#ifndef HASHMAP_H
#define HASHMAP_H
#include <bits/stdc++.h>

#include <iostream>
#include <utility>

#include "hashNode.h"
#include "hasher.h"
using namespace std;

enum state { GRAVEYARD, USED, EMPTY };
#include "hashNode.h"
template <typename T, typename V>
class hashMap {
 private:
  int total;
  int space;
  pair<hashNode<T, V>, state>* table;
  void increaseSize();
  void decreaseSize();

 public:
  hashMap();
  void erase(size_t index);
  void insert(T first);
  void insert(T first, V second);
  void clear();
  ~hashMap();
};

template <typename T, typename V>

void hashMap<T, V>::increaseSize() {
  total = 0;
  pair<hashNode<T, V>, state>* temp = table;
  //New table, so doubling the hashTable.
  table = new pair<hashNode<T, V>, state>[space << 1];
  int oldSize = space;
  //Double space
  space <<= 1;

  for (int i = 0; i < space; i++) {
    table[i].second = state::EMPTY;
  }
  //Reinserts all values.
  for (int i = 0; i < oldSize; i++) {

    if (temp[i].second == state::USED) {

      insert(temp[i].first.first, temp[i].first.second);
    }
  }
  delete[] temp;
}

template <typename T, typename V>

hashMap<T, V>::hashMap() {
  //Constructs table starting ith ten values.
  table = new pair<hashNode<T, V>, state>[10];
  for (int i = 0; i < 10; i++) {
    //Sets values to empty state.
    table[i].second = state::EMPTY;
  }
  space = 10;
  total = 0;
}
template <typename T, typename V>
//Can't really do deletion so it sets to graveyard.
void hashMap<T, V>::erase(std::size_t index) {
  table[index].second = state::GRAVEYARD;
  return;
}
template <typename T, typename V>
//Hashes the values then inserts using quadratic probing open addressing.
void hashMap<T, V>::insert(T first) {
  int position = myHash(first) % space;
  int quadratic = 0;
  int temp = 0;

  while (table[(position + temp) % space].second == state::USED) {
    quadratic++;
    temp = (quadratic * quadratic);
  }

  table[(position + temp) % space] = {hashNode<T, V>(first), state::USED};
  total++;
  if (total >= 0.75 * space) increaseSize();

  return;
}
template <typename T, typename V>
//Same insertion as before but ith a second value.
void hashMap<T, V>::insert(T first, V second) {
  int position = myHash(first) % space;
  int quadratic = 0;
  int temp = 0;

  while (table[(position + temp) % space].second == state::USED) {
    quadratic++;
    temp = (quadratic * quadratic);
  }
  table[(position + temp) % space] = {hashNode<T, V>(first, second),
                                      state::USED};
  total++;
  if (total >= 0.75 * space) increaseSize();
  return;
}
template <typename T, typename V>
//Clears the values and resets the table.
void hashMap<T, V>::clear() {
  delete[] table;
  table = new pair<hashNode<T, V>, state>[10];
  for (int j = 0; j < 10; j++) {
    table[j].second = state::EMPTY;
  }
  space = 10;
  total = 0;
}
template <typename T, typename V>
//Deletes it.
hashMap<T, V>::~hashMap() {
  delete[] table;
}
#endif