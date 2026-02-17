#ifndef NODE_H
#define NODE_H
//Hash node so template Node.
template <typename T, typename V>
class hashNode {
 public:
  T first;
  V second;
  hashNode(T first, V second);
  hashNode(T first);
  hashNode() = default;
};
//Takes in the value and puts it in.
template <typename T, typename V>
hashNode<T, V>::hashNode(T first, V second) {
  this->first = first;
  this->second = second;
}
//reads in the vlaue if there is only one.
template <typename T, typename V>
hashNode<T, V>::hashNode(T first) {
  this->first = first;
  this->second = V();
}

#endif