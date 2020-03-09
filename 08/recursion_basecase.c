#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Node{
	struct BST_Node *left;
	struct BST_Node *right;
} Node;

void recursion_1(Node *root){
  // one way to check that a recursive call is within bounds is to check
  // that the recursive calls will still be within bounds before making them
  
  if(root->left != NULL){
	recursion_1(root->left);
  }
  
  if(root->right != NULL){
	recursion_1(root->right);
  }
}

void recursion_2(Node *root){
 // another (often simpler) way is to check if the current call is itself out of
 // bounds
 if (root == NULL) return;
}