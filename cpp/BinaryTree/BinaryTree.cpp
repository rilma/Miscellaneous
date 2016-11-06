
#include <iostream>

#include "BinaryTree.h"

using namespace std;


// constructor
BinaryTreeClass::BinaryTreeClass() {

 rootNode = NULL;

}


BinaryTreeClass::BinaryNode* BinaryTreeClass::CreateLeafNode( int key ) {

 BinaryNode* n = new BinaryNode;
 n->key = key;
 n->left = NULL;
 n->right = NULL;

 return n;

}


void BinaryTreeClass::AddLeafNode( int key ) {

 AddLeafNodePrivate( key, rootNode );

}


void BinaryTreeClass::AddLeafNodePrivate( int key, BinaryNode* Ptr ) {

 // find if root pointer is pointing to anything

 if ( rootNode == NULL )
  rootNode = CreateLeafNode( key );
 else if ( key < Ptr->key ) {	// Move to the left

  if ( Ptr->left != NULL )
   AddLeafNodePrivate( key, Ptr->left );
  else
   Ptr->left = CreateLeafNode( key );

 }

 else if ( key > Ptr->key ) {	// Move to the right

  if ( Ptr->right != NULL )
   AddLeafNodePrivate( key, Ptr->right );
  else
   Ptr->right = CreateLeafNode( key );

 }
 else
  cout << "\nThe key " << key << " has already been added to the tree\n";

}


void BinaryTreeClass::PrintInOrder() {

 PrintInOrderPrivate( rootNode );

}


void BinaryTreeClass::PrintInOrderPrivate( BinaryNode* Ptr ) {

 if ( rootNode != NULL ) {

  if ( Ptr->left != NULL )
   PrintInOrderPrivate( Ptr->left );

  cout << Ptr->key << " ";

  if ( Ptr->right != NULL )
   PrintInOrderPrivate( Ptr->right );

 }
 else
  cout << "\nThe tree is empty\n";

}


BinaryTreeClass::BinaryNode* BinaryTreeClass::ReturnNode( int key ) {

 return ReturnNodePrivate( key, rootNode );

}

BinaryTreeClass::BinaryNode* BinaryTreeClass::ReturnNodePrivate( int key, BinaryNode* Ptr ) {

 if ( Ptr != NULL ) {

  if ( Ptr->key == key)
   return Ptr;
  else {

   if ( key < Ptr->key )
    return ReturnNodePrivate( key, Ptr->left );
   else
    return ReturnNodePrivate( key, Ptr->right );

  }
 }
 else
  return NULL;

}


int BinaryTreeClass::ReturnRootKey() {

 if ( rootNode != NULL )
  return rootNode->key;
 else
  return -1000;

}


void BinaryTreeClass::PrintChildren( int key ) {

 BinaryNode* Ptr = ReturnNode( key );

 if ( Ptr != NULL ) {

  cout << "\nParent node = " << Ptr->key << endl;

  Ptr->left == NULL ?
  cout << "\nLeft Child = NULL\n" :
  cout << "\nLeft Child = " << Ptr->left->key << endl;

  Ptr->right == NULL ?
  cout << "\nRight Child = NULL\n" :
  cout << "\nRight Child = " << Ptr->right->key << endl;

 }
 else
  cout << "\nKey " << key << " is not in the tree\n";

 cout << endl;

}
