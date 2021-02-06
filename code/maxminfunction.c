/*ss
Write a program that uses a function template called max to determine the larger of two arguments.
Write another function template called min to determine the smaller of two arguments. Test the program using integer, character, and floating-point number arguments.
*/
#include <iostream>
using namespace std;
// definition of function template minimum; finds the smaller value
template < class T >
T minimum( T value1, T value2 )
{
 if ( value1 < value2 )
 return value1;
 else
 return value2;
}
int main()
{
 // demonstrate minimum with int values
 int int1 = 0; // first int value
 int int2 = 0; // second int value
 cout << "Input two integer values: ";
 cin >> int1 >> int2;
cout << "The smaller integer value is: " << minimum( int1, int2 );
char char1 = ' '; // first char value
 char char2 = ' '; // second char value
 cout << "\n\nInput two characters: ";
 cin >> char1 >> char2;
 cout << "The smaller character value is: " << minimum( char1, char2 );
double double1 = 0; // first double value
 double double2 = 0; // second double value
 cout << "\n\nInput two double values: ";
 cin >> double1 >> double2;
cout << "The smaller double value is: " << minimum( double1, double2 )
 << endl;
}
