#ifndef STACK_HPP
#define STACK_HPP
#include "LinkedList.hpp"

class stack {
  public:
    //constructor
    stack() {
        list = new LL();
    }

    // pushes a given item to the stack
    // Pre condition: stack is not empty
    void push(int item) {
        list->add_to_head(item);
    }

    // pops the top element from the stack
    // Pre condition: stack is not empty
    int pop() {
        return list->remove_from_head();
    }

    // returns 1 if the stack is empty, and returns 0 otherwise
    int isEmpty() {
        return (list->getSize() == 0);
    }
    
    // destructor
    ~stack() {
        delete list;
    }

  private:
    LL* list;
}; 

#endif
