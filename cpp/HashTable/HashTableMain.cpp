

#include <iostream>
#include "HashTable.h"


int main() {

 HashTable hashObj;
 string name = "";
 int index;

 // Finds index in a hash table
 index = hashObj.HashFunction("Denmark");
 cout << "Index = " << index << endl << endl << endl;

 cout << "\nThe main program has added items to the hash table:\n\n";
 
 // Adding items to the hash table
 hashObj.addItem( "Angola", "Kuduro" );
 hashObj.addItem( "Argentina", "Tango" );
 hashObj.addItem( "Brazil", "Samba" );
 hashObj.addItem( "Colombia", "Cumbia" );
 hashObj.addItem( "India", "Bhangra" );
 hashObj.addItem( "Jamaica", "Reggae" );
 hashObj.addItem( "Peru", "Marinera" );
 hashObj.addItem( "Puerto Rico", "Salsa" );
 hashObj.addItem( "Spain", "Flamenco" );
 hashObj.addItem( "USA", "Swing" );

 // print a Hash Table
 cout << "\nPrinting the items in the hash:\n\n";
 hashObj.printTable();

 // print items in a slot of a Hash Table
 cout << "\nPrinting items inside a slot:\n\n";
 hashObj.printItemsIndex( 2 );

 
 // Search for country (slot) in a Hash Table
 while ( name != "exit")  {

  cout << "Search for a country (Enter 'exit' to quit!): ";
  cin >> name;

  if ( name != "exit" )
   hashObj.findDance( name );
 
 }
 

 /*
 // Remove a person (slot) in a Hash Table
 while ( name != "exit")  {

  cout << "Remove a country (Enter 'exit' to quit!):";
  cin >> name;

  if ( name != "exit" )
   hashObj.removeItem( name );

 }
 */

}
