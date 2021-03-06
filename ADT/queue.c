#include <stdlib.h>

#include "queue.h"

// creates a new queue
// if malloc fails, returns NULL
queue_t* queue_create() {
  queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
  // if OS cannot allocate memory
  if (queue == NULL) {
    return NULL;
  }

  // sets head and tail
  queue->head = NULL; 
  queue->tail = NULL;
  return queue;
}

// add a given item to the queue
// if everything works ok, returns same q as the input
// if malloc fails, returns NULL
queue_t* enqueue(queue_t* q, void* item) {
  // validate parameters 
  if (q == NULL) {
    return NULL;
  }

  // create new node
  struct Node * node = (struct Node*) malloc(sizeof(struct Node));
  // if OS cannot allocate memory
  if (node == NULL) {
    return NULL;
  }
  
  node->data = item; 
  node->next = NULL;

  // if linked list is empty, then must add to head as well 
  if (q->head == NULL) {
    q->head = node;
    q->tail = node;
    return q;
  }

  // link the list!
  q->tail->next = node;
  q->tail = q->tail->next;
  return q;
}

// removes an element from the queue
// Pre condition: queue is not empty
int dequeue(queue_t* q) {
  // validate parameters 
  if (q == NULL) {
    return 0; 
  }

  // to dequeue: queue must not be empty 
  if (queue_is_empty(q)) {
    return 0;
  }
  
  int value = q->head->data;
  struct Node* prevHead = q->head;  
  q->head = q->head->next;

  free(prevHead);
  prevHead = NULL;  

  return value;
}

// checks if the queue is empty
bool queue_is_empty(queue_t* q) {
  if (q == NULL) {
    return true;
  }

  if (q->head == NULL) {
    return true;
  }

  return false;
}

// returns the length of the queue
// if q==NULL, returns -1
int queue_length(queue_t* q) {
  // validate parameters
  if (q == NULL) {
    return -1;
  }

  unsigned int length = 0;

  struct Node* node = q->head;

  while (node != NULL) {
    length++;
    node = node->next;
  }

  return length;  
}

// frees the queue
// if q==NULL, returns -1
void queue_free(queue_t* q) {
  if (q == NULL) {
    return; 
  }
  
  // need 2 pointers 
  struct Node* node = q->head;
  struct Node* prevNode = q->head;

  // free all nodes in queue
  while (node != NULL) {
    node = node->next;
    prevNode->next = NULL;
    // printf("Freeing node with value %d \n", prevNode->data);
    free(prevNode);
    prevNode = NULL;
    prevNode = node;
  }
  
  // free queue 
  q->head = NULL;
  q->tail = NULL;
  free(q);
  q = NULL;
}