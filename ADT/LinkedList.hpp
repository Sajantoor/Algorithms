#ifndef LL_HPP
#define LL_HPP
#define NULL 0

class LLnode {
  public:
    // constructor
    LLnode(int value) {
        setData(value);
        setNext(NULL);
    }

    // get node
    LLnode* getNext() {
        return next;
    }

    // set node
    void setNext(LLnode* n) {
        next = n;
    }

    // get data
    int getData() {
        return data;
    }

    // set data
    void setData(int value) {
        data = value;
    }

    // destructor
    ~LLnode() {
        delete this;
    }


  private:
	  int data;
	  LLnode* next;
};



class LL {
  public:
	  LLnode* head;

    // constructor
    LL() {
        head = NULL;
        size = 0;
    }

    // Adds a new element to the head of a list
    void add_to_head(int value) {
        LLnode* newNode = new LLnode(value);
        newNode->setNext(head);
        head = newNode;
        size++;
    }

    // Removes the first element from a list
    int remove_from_head() {
        int ret = head->getData();
        LLnode* tmp = head;
        head = head->getNext();
        size--;
        delete(tmp);
        return ret;
    }

    // Returns the size of the list
    int getSize() { 
        return size; 
    }

    // Outputs the list elements in order from head to tail
    void print() {
        LLnode* current = head;
        while (current) {
            cout << current->getData() << " -> ";
            current = current->getNext();
        }

        cout << "\n";
    }

    // destructor
    ~LL() {
        LLnode* current = head; 
        while (current) {
            LLnode* prev = current; 
            current = current->getNext();
            delete prev;
        }
    }

  private:
    int size;
};

#endif