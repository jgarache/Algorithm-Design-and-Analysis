#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
  root = NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  // Write code to remove and deallocate all nodes in the tree
  Destroy(root);
  root = NULL;
}

void BST::Destroy(Node *Leaf){  //destroys in postOrder

  if(Leaf != NULL){
    Destroy(Leaf->left);
    Destroy(Leaf->right);
    delete Leaf;
  }

}

void BST::Insert(int toInsert) {
  // Write your code here
    if(root == NULL)
        root = CreateLeaf(toInsert);
    else
        InsertAtSomewhere(toInsert,root);

}

void BST::InsertAtSomewhere(int toInsert, Node* Leaf){   //goes through the tree

    if(toInsert < Leaf->val){ //go left
        if(Leaf->left != NULL)
            InsertAtSomewhere(toInsert,Leaf->left);
        else{
            Leaf->left = CreateLeaf(toInsert);
            Leaf -> left ->parent = Leaf;
        }
    }

    else if(toInsert >= Leaf ->val){ //go right
        if(Leaf->right !=NULL)
            InsertAtSomewhere(toInsert,Leaf->right);
        else{
          Leaf->right = CreateLeaf(toInsert);
          Leaf -> right ->parent = Leaf;
        }
            
    }

}

Node *BST::CreateLeaf(int key){

    Node* n = new Node;     //new pointer
    n -> val = key;         //n points to key
    n -> left = n-> right = NULL;   //left and right leafs point to null
    n -> parent = NULL;
    return n;

}

void BST::Delete(int toDelete) {
  // Write your code here

  Node* z = Search(toDelete);
  if(z->left == NULL)
    Transplant(z, z->right);
  else if(z->right == NULL)
    Transplant(z, z->left);
  else{
    Node* y = Minimum(z->right);
    if(y->parent != z){
      Transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    Transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
  }
  delete z;
}

void BST::Transplant(Node *u, Node *v) {
  // Write your code here

  if (u -> parent == NULL)
    root = v;
  else if (u == u -> parent -> left)
    u -> parent -> left = v;
  else 
    u -> parent-> right = v;
  if(v != NULL)
    v -> parent = u -> parent;
}

Node *BST::Successor(Node *x) {
  // Write your code here

  if (x -> right != NULL)
    return Minimum(x ->right);

  Node* y = new Node;

  y = x -> parent;

  while(y != NULL && x == y->right){
    x =y;
    y = y ->parent;
  }

  return y;
}

Node *BST::Minimum(Node *x) {
  // Write your code here

  while(x -> left != NULL)
    x = x->left;

  return x;
}

Node *BST::Maximum(Node *x) {
  // Write your code here

  while(x -> right != NULL)
      x = x->right;

    return x;
}

Node *BST::Search(int toFind) {
  
  return SearchHelp(toFind, root);

}

Node *BST::SearchHelp(int toFind,Node *Leaf) {
  if(toFind == Leaf->val || Leaf == NULL){
    return Leaf;
  }else if(toFind < Leaf->val){
    SearchHelp(toFind,Leaf->left);
  }else{
    SearchHelp(toFind,Leaf->right);
  }
}

void BST::Print(TraversalOrder Order) {
  if(Order==InOrderTrav)
    InOrder(root);
  else if(Order==PreOrderTrav)
    PreOrder(root);
  else if(Order==PostOrderTrav)
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  // Write your code here

  if(x !=NULL){
    cout << x->val << endl;
    PreOrder(x->left);
    PreOrder(x ->right);
  }

}

void BST::InOrder(Node *x) {
  // Write your code here

  if (x != NULL){
      InOrder(x->left);
      cout << x->val <<endl;
      InOrder(x->right);
   }
}

void BST::PostOrder(Node *x) {
  // Write your code here

  if(x!=NULL){
    PostOrder(x->left);
    PostOrder(x->right);
    cout << x -> val << endl;
  }
}
