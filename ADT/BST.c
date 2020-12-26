#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

// creates a Binary Search Tree
BST_t* create_BST() {
  BST_t* tree = (BST_t*) malloc(sizeof(BST_t));
  tree->root = NULL;
  return tree;
}

// find an item in the binary tree
BTnode_t* find(BST_t* tree, int item) {
  BTnode_t* current = tree->root;
  while (current!=NULL) {
    if (current->value == item)
      return current;
    if (current->value > item)
      current = current->left;
    else
      current = current->right;
  }
  // item not found
  return NULL;
}

// inserts item into the Binary Search Tree
void BST_insert(BST_t* tree, int item) {
  if (tree->root == NULL) {
    tree->root = create_node(item);
  } else {
    BTnode_t* current = tree->root;
    BTnode_t* prev = NULL;
    while (current != NULL) {
      prev = current;
      // decide to go left or right in the next step 
      if (current->value > item)
        current = current->left;
      else
        current = current->right;
    }
    
    if (prev->value > item) {
      set_left_child(prev, create_node(item));
    } else {
      set_right_child(prev, create_node(item));
    }
  }
}

// removes item from the Binary Search Tree
void BST_remove(BST_t* tree, int item) {
  // finds the node
  BTnode_t* node = find(tree, item);

  // if doesn't exist, do nothing. 
  if (node == NULL) {
    return;
  }
  
  // if it has 2 children
  if (node->left && node->right) {
    // find the predecessor, replace value with the node, do nothing else 
    BTnode_t* el = node->left->left; 
    BTnode_t* pred = node->left;

    // find predecessor 
    while (el) {
      pred = el;
      el = el->left;
    }

    node->value = pred->value;
    free(pred);
    pred = NULL;
  } else if (node->left || node->right) {  // if it has one child
    // find the correct child
    BTnode_t* child = node->left;
    if (node->right) {
      child = node->right;
    }

    // "replace" node with child 
    node->left = child->left;
    node->right = child->right; 
    node->value = child->value;

    // remove node
    free(child);
    child = NULL;
  } else { // it has no children, remove node
    free(node);
    node = NULL;
  }
}
