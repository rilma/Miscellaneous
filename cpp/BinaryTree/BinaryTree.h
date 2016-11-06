
#include <iostream>

using namespace std;


class BinaryTreeClass {

 public:

  // prototype
  BinaryTreeClass(); // constructor
  void AddLeafNode( int key );
  void PrintInOrder();
  int ReturnRootKey();
  void PrintChildren( int key );

 private:

  struct BinaryNode {

   int key;	// Integer value to identify the node
   BinaryNode* left;
   BinaryNode* right;
   
  }; 

  BinaryNode* rootNode;

  // prototype (defined in private because it returns a type 'BinaryNode*', 
  // which is also private)
  BinaryNode* CreateLeafNode( int key ); // Leaf Node
  void AddLeafNodePrivate( int key, BinaryNode* Ptr );
  void PrintInOrderPrivate( BinaryNode* Ptr );
  BinaryNode* ReturnNode( int key );
  BinaryNode* ReturnNodePrivate( int key, BinaryNode* Ptr );

};
