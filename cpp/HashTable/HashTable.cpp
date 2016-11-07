

#include <iostream>
#include <string>
#include "HashTable.h"


// constructor
HashTable::HashTable() {

 for ( int i = 0; i < tableSize; i++ ) {

  hashTable[ i ] = new HashItem;

  hashTable[i]->name = "empty";
  hashTable[i]->dance = "empty";
  hashTable[i]->next = NULL;

 }

}

int HashTable::HashFunction( string key ) {

 int hash = 0;
 int index;

 index = key.length();

 for ( int i = 0; i < key.length(); i++ )
  hash += ( int ) key[ i ];

 index = hash % tableSize;

 return index;	// the output of the HashFunction refers to a 'slot' (not index!!!)

}


void HashTable::addItem( string name, string dance ) {

 int index = HashFunction( name );

 if ( hashTable[ index ]->name == "empty" ) {

  hashTable[ index ]->name = name;
  hashTable[ index ]->dance = dance;

 }

 else {

  HashItem* Ptr = hashTable[ index ];
  HashItem* n = new HashItem;
  n->name = name;
  n->dance = dance;
  n->next = NULL;

  while ( Ptr->next != NULL )  // condition to check if we are at the end of the list
   Ptr = Ptr->next;
  
  Ptr->next = n;

 }

}

int HashTable::numberItemsIndex ( int index ) {

 int counter = 0;

 if ( hashTable[ index ]->name == "empty" ) {

  return counter;

 }

 else {

   counter++;

   HashItem* Ptr = hashTable[ index ];

   while ( Ptr->next != NULL ) {
    counter++;
    Ptr = Ptr->next;
   }

 }

 return counter;

}


void HashTable::printTable() {

 int number;

 for ( int i = 0; i < tableSize; i++ ) {

  number = numberItemsIndex( i );

  cout << "-------\n";
  cout << " Index = " << i << endl;
  cout << hashTable[i]->name << endl;
  cout << hashTable[i]->dance << endl;
  cout << " # of Items = " << number << endl;

 }


}


void HashTable::printItemsIndex( int index ) {

 HashItem* Ptr = hashTable[ index ];

 if ( Ptr->name == "empty" )
  cout << "\nBucket = " << index << " is empty!\n" << endl;
 else {
  cout << "Bucket = " << index << " contains the following items: " << endl;
  while ( Ptr != NULL ) {
   cout << "---------------------\n";
   cout << Ptr->name << " dances "<< Ptr->dance << endl << endl;
   Ptr = Ptr->next;
  }
 }

}


void HashTable::findDance( string name ) {

 int slot = HashFunction( name );
 bool foundName = false;
 string dance;

 HashItem* Ptr = hashTable[ slot ];

 while ( Ptr != NULL ) {

  if ( Ptr->name == name ) {

   foundName = true;
   dance = Ptr->dance;

  } 

  Ptr = Ptr->next;

 }

 if ( foundName == true )
  cout << "Favorite dance in " << name << " is " << dance << endl;
 else
  cout << name << "'s info wasn't found in the Hash Table!\n" << endl;

}


void HashTable::removeItem( string name ) {

 int index = HashFunction( name );

 HashItem* delPtr;
 HashItem* Ptr1;
 HashItem* Ptr2;

 // case 0 ( slot is empty )
 if ( hashTable[ index ]->name == "empty" ) {
  cout << "Case 0\n";
  cout << name << " was not found in the Hash Table\n";
 }

 // case 1 ( only one item in the slot and item has a matching name ) 
 else if ( hashTable[ index ]->name == name && hashTable[ index ]->next == NULL ) {

  hashTable[ index ]->name == "empty";
  hashTable[ index ]->dance == "empty";

  cout << "Case 1\n";
  cout << name << " was removed from the Hash Table\n";

 }

 // case 2 ( match is located in the first item in the slot but 
 //          there are more items in the slot )
 else if ( hashTable[ index ]->name == name ) {

  delPtr = hashTable[ index ];

  // the 2nd item in the slot becomes first
  hashTable[ index ] = hashTable[ index ]->next;

  delete delPtr;
  cout << "Case 2\n";
  cout << name << " was removed from the Hash Table\n";

 }
 
 // case 3 ( slot contains items but first item is not a match )
 else {

  Ptr1 = hashTable[ index ]->next;	// point to the 2nd item
  Ptr2 = hashTable[ index ];

  // advance Ptr1 and Ptr2 one step by the time ...
  while ( Ptr1 != NULL && Ptr1->name != name ) {

   Ptr2 = Ptr1;
   Ptr1 = Ptr1->next;

  }

  // case 3.1 ( no match )
  if ( Ptr1 == NULL ) {
   cout << "Case 3.1\n";
   cout << name << " was not found in the Hash Table\n";
  }

  // case 3.2 ( match is found! )
  else {

   delPtr = Ptr1;
   Ptr1 = Ptr1->next;
   Ptr2->next = Ptr1;

   delete delPtr;
   cout << "Case 3.2\n";
   cout << name << " was removed from the Hash Table\n";

  }

 }

}


