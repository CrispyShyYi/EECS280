#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    return first == nullptr;
  };

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
  int size() const {
    return List_size;
  };

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    assert(!empty());
    return first->datum;
  };

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    assert(!empty());
    return last->datum;
  };

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    Node *NewFrontNode = new Node;

    NewFrontNode->prev = nullptr;
    NewFrontNode->next = first;
    NewFrontNode->datum = datum;

    if(empty()) {
      last = NewFrontNode;
    } else {
      first->prev = NewFrontNode;
    }

    first = NewFrontNode;
    List_size++;
  };

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *NewBackNode = new Node;

    NewBackNode->prev = last;
    NewBackNode->next = nullptr;
    NewBackNode->datum = datum;

    if(empty()) {
      first = NewBackNode;
    } else {
      last->next = NewBackNode;
    }

    last = NewBackNode;
    List_size++;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    assert(!empty());
    Node *PopFrontNode = first;

    if(first == last) {
      first = nullptr;
      last = nullptr;
    } else {
      first = first->next;
      first->prev = nullptr;
    }
    delete PopFrontNode;
    List_size--;
  };

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    assert(!empty());
    Node *PopBackNode = last;

    if(first == last) {
      first = nullptr;
      last = nullptr;
    } else {
      last = last->prev;
      last->next = nullptr;
    }
    delete PopBackNode;
    List_size--;
  };

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while(!empty()){
      pop_front(); 
    }
  };

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.
  
  //Zitong: Add default constructor
  List() : first(nullptr), last(nullptr), List_size(0){}

  //Zitong: Add destructor
  ~List() {
    clear();
  }

  //Zitong: Add overloaded assignment operator
  List & operator = (const List &other) {
    if (this == &other) return *this;
    clear();
    copy_all(other);
    return *this;
  }

  //Zitong: Add copy constructor
  List(const List &other) : first(nullptr), last(nullptr), List_size(0) {
    copy_all(other);
  }

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    assert(empty());
    Node *first = other.first; 
    while (first != nullptr) {
      push_back(first->datum);
      first = first->next;
    }
  };

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  int List_size; // Zitong: add a private member variable to track of the size

public:
  ////////////////////////////////////////
  class Iterator {
  public:
    //OVERVIEW: Iterator interface to List
  
    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.

    // Add custom implementations of the destructor, copy constructor, and
    // overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to copy, assign, and destroy Iterators.
  

    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.



    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator():list_ptr(nullptr),node_ptr(nullptr){};
    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator& operator--() { // prefix -- (e.g. --it)
      assert(list_ptr);
      if (node_ptr) {
        node_ptr = node_ptr->prev;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->last;
      }
      return *this;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator--();
      return copy;
    }

    T& operator *() const{
      assert(node_ptr != nullptr);
      return node_ptr->datum;
    }

    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
      return &operator*();  
    }

    bool operator==(Iterator rhs) const{
      if (list_ptr != nullptr && node_ptr == nullptr &&
          rhs.list_ptr == nullptr && rhs.node_ptr == nullptr){
        return false;
      }
      else if (list_ptr == nullptr && node_ptr == nullptr &&
          rhs.list_ptr != nullptr && rhs.node_ptr == nullptr){
        return false;
      }
      else if (list_ptr == rhs.list_ptr){
        return node_ptr == rhs.node_ptr;
      }
      return list_ptr == rhs.list_ptr && node_ptr == rhs.node_ptr;
    }

    bool operator!=(Iterator rhs) const{
      if (list_ptr != nullptr && node_ptr == nullptr &&
          rhs.list_ptr == nullptr && rhs.node_ptr == nullptr){
        return true;
      }
      else if (list_ptr == nullptr && node_ptr == nullptr &&
          rhs.list_ptr != nullptr && rhs.node_ptr == nullptr){
        return true;
      }
      return node_ptr != rhs.node_ptr;
    }

    Iterator & operator++() {
      assert(node_ptr != nullptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    Iterator operator++(int /*postfix*/){
      Iterator copy = *this;
      ++(*this);
      return copy;
    }

  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here
    // add any additional necessary member variables here


    // add any friend declarations here
    friend class List;   

    // construct an Iterator at a specific position in the given List
    Iterator(const List *lp, Node *np):list_ptr(lp),node_ptr(np){};

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const{
    return Iterator(this, first);
  };

  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator(this, nullptr);
  };

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i){
    if (!i.node_ptr) return end();
    else{
      Node * nextNode = i.node_ptr->next;
      // if nextNode is nullptr;
      if(!nextNode && first == last){
        first = nullptr;
        last = nullptr;
      }
      else if(!nextNode){
        i.node_ptr->prev->next = nullptr;
        last = i.node_ptr->prev;
      }
      else if (nextNode && i.node_ptr == first){
        first = nextNode;
        nextNode->prev = i.node_ptr->prev;
      }
      else if(nextNode){
        i.node_ptr->prev->next = nextNode;
        nextNode->prev = i.node_ptr->prev;
      }
      delete i.node_ptr;
      List_size--;
      return Iterator(this, nextNode);
    }
  };

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum){
    if (!i.node_ptr){
      push_back(datum);
      return Iterator(this, last);
    }
    if (i.node_ptr == first){
      push_front(datum);
      return Iterator(this, first);
    }
    Node * prev_node = i.node_ptr->prev;
    Node * node_in = new Node;
    node_in->datum = datum;
    node_in->prev = prev_node;
    node_in->next = i.node_ptr;
    prev_node->next = node_in;
    i.node_ptr->prev = node_in;
    List_size++;
    return Iterator(this, node_in);
  };

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
