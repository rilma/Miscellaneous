
/*

 Code Challenge

 "Find the greater number with same set of digits"

 Tested with GNU C++ compiler:

        $ g++ -std=c++11 wchclass.cpp -o wch
        $ ./wch

	// Example ....

	Enter an integer number: 1245673

	Enter the number of values greater than the previous entered number: 20
	Enter the number of digits: 11

	The next greater number of 1245673 is 1245736

	The next 20 greater numbers are:
	 1245736 1245763 1246357 1246375 1246537
	 1246573 1246735 1246753 1247356 1247365
	 1247536 1247563 1247635 1247653 1253467
	 1253476 1253647 1253674 1253746 1253764


	Let's generate a random number with 11 digits: 11530950365
	Its next greater number is 11530950536

	// End of Example ...

                Author: Ronald Ilma
                Date: June 15, 2016
*/


#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// class declaration

class WCCClass {

 public:

  // prototype constructor
  WCCClass( long long = 1234, int = 10, int = 5);
  // member function to set user defined inputs
  void SetInput( long long, int, int );
  // member function to request user defined inputs
  void Input();
  // member function to process input and present results
  void Process();

 private:

  long long Number;	// long long integer type
  int N;		// No. of numbers greater than 'Number'
  int ND;		// No. of digits  

  long long NextNumber;
  vector<long long> V;
  long long TempNumber, RandNumber;

  void FindBig();
  void FindBigN();
  void FindBigR();
  void PrintVector();

};

//---------------------------------------------------------------------

// class implementation

WCCClass::WCCClass( long long num, int nnum, int ndig ) {

 Number = num;
 N = nnum;
 ND = ndig;

} // set of 'WCCClass'

void WCCClass::SetInput( long long num, int nnum, int ndig ) {

 Number = num;
 N = nnum;
 ND = ndig;

} // end of 'SetInput'


void WCCClass::Input() {

 cout << "\n\n------- FIND NEXT GREATER NUMBER -------\n";
 cout << "\n Code Challenge\n";
 cout << "\n Author: Ronald Ilma";
 cout << "\n Date: June 15, 2016";
 cout << "\n\n";
 
 long long num;
 cout << "\nEnter an integer number: ";
 cin >> num;
 
 int nnum;
 cout << "\nEnter the number of values greater than the previous entered number: ";
 cin >> nnum;
 
 
 int ndig;
 cout << "Enter the number of digits: ";
 cin >> ndig;

 SetInput( num, nnum, ndig );

} // end of 'Input'
 

void WCCClass::FindBig() {

 /* 
  Find the smallest number greater than 'aInt' with 
  the same set of digits
 */



 try {

  if ( Number < 10 ) {
   NextNumber = -1;
   return;
  }

  // Convert an numeric representation to string
  string NumberStr = to_string( Number );

  // Find the next lexicographically greater permutation
  next_permutation( NumberStr.begin(), NumberStr.end() );

  // Return a long long integer value from a string
  NextNumber = stoll( NumberStr );

  // Return the next number only if it greater than input, otherwise returns -1
  if ( NextNumber < Number ) NextNumber = -1;

 }
 catch ( exception& e ) {

  // React to general exceptions, e.g. out of range ( std::stoll )
  cout << "\nException: " << e.what() << endl;

  NextNumber = -1;

 }

} // end of 'FindBig' 


void WCCClass::FindBigN() {

 /*
  Find the next 'N' numbers greater than 'Number' with the same set of digits
  Results are stored in a vector container.
 */

 TempNumber = Number;

 for ( int i = 0; i < N; i++ ) {
  
  // Calling a function which returns the next greater number 
  FindBig();

  if ( NextNumber != -1 ) {

   // Push new greater number back of data container
   V.push_back( NextNumber );
   Number = NextNumber;

  }
  
  else break;
  
 }

 Number = TempNumber;

} // end of 'FindBigN'


void WCCClass::FindBigR() {

 /*
  Generates a random number ('number') consisting in 'ND' digits and find 
  its immediate greater number ('nextNumber') while keeping same set of digits.
 */

 if ( ND > 1 && ND <= 18 ) {

  // scaling factor
  long long offset = pow( 10, ND );

  // Initializes seeding of random numbers with current time
  srand( time( 0 ) );

  // Random numer scaled to a number with 'ND' digits
  RandNumber = offset / 10  + rand() % offset;

  // Find the next greater number
  TempNumber = Number;
  Number = RandNumber;
  FindBig();
  Number = TempNumber;

 }
 else {

  /* Send a warning message when overflow occurs ( generally for ND > 18 ) 
  */

  cout << "\nWARNING!: Enter ND -> [2, 18] \n";

  NextNumber = -1;

 }
 
} // end of 'FindBigR'


void WCCClass::PrintVector() {

 for ( int i = 0; i < V.size(); i++ ) {

  cout << " " << V.at( i );
  if ( ( i + 1 )  % 5 == 0 ) cout << endl;

 }

 cout << endl;

} // end of 'PrintVector'


void WCCClass::Process() {


 // Find the next greater integer
 //

 FindBig();
 
 if ( NextNumber != -1 ) cout << "\nThe next greater number of "
  << Number << " is " << NextNumber << endl;
 else cout << "\nIt is not possible to compute the next greater number of "
  << Number << endl << endl;


 // Find the next N greater integers
 //
 
 FindBigN();

 if ( V.size() > 0 ) {

  if ( V.size() != N )
   cout << "\nOnly " << V.size() << " greater numbers are found:\n";
  else cout << "\nThe next " << N << " greater numbers are:\n";

  PrintVector();

 }
 else cout << "\nThere are not greater numbers!\n";


 // Find the greater number of a number consisting in 'ND' digits.
 // The initial number is random.

 FindBigR();

 if ( NextNumber != -1 ) cout << "\nLet's generate a random number with " 
  << ND << " digits: " << RandNumber << "\nIts next greater number is " 
  << NextNumber << endl << endl;
 else {
  if ( ND <= 1 ) cout << "\nNot possible to find next greater number of a number with "
   << ND << " digits!\n\n";
  else if ( ND >= 18 ) cout << "\nDue to overflow, it is not possible to find "
   << "the next greater number of a number with > 18 digits!\n\n";
 }

 cout << "\n\n------ END OF PROGRAM! ------\n\n";

} // end of 'Process'


//---------------------------------------------------------------------

// driver program

int main() {

 // Declare object
 WCCClass WCCObj;

 // Request user's input
 WCCObj.Input();

 // Execute process
 WCCObj.Process();

}

