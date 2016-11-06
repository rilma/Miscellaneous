
#include <iostream>
#include <cstdlib>

#include "BinaryTree.h"

using namespace std;


int main() {

 int treeKeys[ 16 ] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

 BinaryTreeClass treeObj;

 cout << "\nPrinting the tree in order \n before adding numbers\n";
 treeObj.PrintInOrder();

 for ( int i = 0; i < 16; i++ )
  treeObj.AddLeafNode( treeKeys[ i ] );

 cout << "\nPrinting the tree in order\nafter adding numbers\n";
 treeObj.PrintInOrder();
 cout << endl;

 treeObj.PrintChildren( treeObj.ReturnRootKey() );


 // Print all children corresponding to a key value
 for ( int i = 0; i < 16; i++ )
  treeObj.PrintChildren( treeKeys[ i ] );


 return 0;

}
