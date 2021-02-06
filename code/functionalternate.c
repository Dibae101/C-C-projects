
/* Write a complete C++ program with the two alternate functions specified below.
These functions will double the variable count defined in main.
a. Function doubleByValue that passes a copy of count by value, double the copy and returns the new value.
b. Function doubleByReference that passes count by reference via a reference parameter, double the original value of count through its alias, i.e. the reference parameter.
*/
#include <iostream>
using namespace std;

int doubleByValue(int num);
void doubleByReference(int &num);
int main()
{
	int num = 5;

	int result_by_val = doubleByValue(num);
	cout << "Return pass by value: " << result_by_val << endl;

	int result_by_ref = num;
	doubleByReference(result_by_ref);
	cout << "Return pass by ref: " << result_by_ref  << endl;

	return 0;
}

int doubleByValue(int num)
{
	return num*2;
}
void doubleByReference(int &num)
{
	num = num*2;
}
