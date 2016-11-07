

#include <string>

using namespace std;


class HashTable {

 public:

  HashTable();	// constructor
  int HashFunction( string key );
  void addItem( string name, string dance );
  int numberItemsIndex( int index );
  void printTable();
  void printItemsIndex( int index );
  void findDance( string name );
  void removeItem( string name );

 private:

  // No. of buckets in the hash
  static const int tableSize = 5;

  // define things to store in the hash table
  struct HashItem {

   string name;
   string dance;
   HashItem* next;

  };

  // define a hash table array with 'n' buckets ( size given by 'tableSize' )
  HashItem* hashTable[ tableSize ];

};
