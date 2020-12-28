#include <stdlib.h>

struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
}; typedef struct BTnode BTnode_t;

// queue stores a struct with the layer and pointer to element next element
// basically implemented using a linked list
struct queue_Node {
  BTnode_t* el;
  struct queue_Node* next;
}; typedef struct queue_Node queue_element; 

// this is the actual queue struct with head and tail of queue elements, basically linked list
typedef struct {
  queue_element* head;
  queue_element* tail;
} queue_m;

// adds an element to the queue, allocates memory
void addToQueue(BTnode_t* element, queue_m* queue) {
  // create queue element 
  queue_element* el = malloc(sizeof(queue_element));
  // OS cannot allocate memory 
  if (!el) {
    return;
  }
  
  el->el = element;
  el->next = NULL;

  // list is empty
  if (queue->head == NULL) {
    queue->head = el;
  } 
  
  // tail is not defined, list is empty, set to element 
  if (!queue->tail) {
    queue->tail = el;
  } else { 
    // queue element normally
    queue->tail->next = el;
    queue->tail = queue->tail->next;
  }
}

// remove head element in queue and clean memory 
void dequeue(queue_m* queue) {
  queue_element* previousHead = queue->head;
  // queue is empty, don't need to do anything
  if (!previousHead) {
    return;
  }
  // move head up to next element 
  queue->head = queue->head->next;
  // free memory and set to NULL 
  free(previousHead);
  previousHead = NULL;
}

// breadth first search using a queue
void breadthFirstSearch(BTnode_t* root) {
  if (!root) {
    return;
  }
  // create queue
  queue_m queue;
  queue.head = NULL;
  queue.tail = NULL;
  // add root to queue, it is not NULL
  addToQueue(root, &queue);

  // while queue is not empty
  while (queue.head) {
    // if left and right child exists, add to queue
    if (queue.head->el->left) {
      addToQueue(queue.head->el->left, &queue);
    }
  
    if (queue.head->el->right) {
      addToQueue(queue.head->el->right, &queue);
    }
    // dequeue element 
    dequeue(&queue);
  }
}

