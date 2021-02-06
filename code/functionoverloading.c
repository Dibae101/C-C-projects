/*Write two overloaded functions named countNegative. The first function receives one integer array and size of the array as parameters and returns the number of negative numbers in the array. The second function receives floating point array and size of the array as parameters and returns the number of negative numbers in the array. Then write a main function to test these functions. The program should be able to check and report the cases when there are no negative numbers in the array. All printing happens in the main function.
*/
#include <iostream>

using namespace std;

//function to count the negative values in the int array
int countNegative (int arr[], int size)
{
int count=0;
for(int i=0;i<size;i++)
{
if(arr[i]<0)
count++;
}
return count;
}
//overloaded function to count the negative values in the float array
int countNegative (float arr[], int size)
{
int count=0;
for(int i=0;i<size;i++)
{
if(arr[i]<0)
count++;
}
return count;
}

int main()
{
int arr1[]={2,3,-3,-2,8,9,-34};

float arr2[]={23.5,-8.4,21.2,90.4,-23.4,-1,-22};

//value returned by the first function
int neg_values=countNegative(arr1,7);
//value returnred by the deconds function
int neg_value=countNegative(arr2,7);

//when there are no neg_values in the int array
if(neg_values==0)
cout<<"\nThere are no negative values in the array ";
else
cout<<"\n"<<neg_values<<" elements in the int array are negative";

//when there are no neg_values in the float array
if(neg_value==0)
cout<<"\nThere are no negative values in the array ";
else
cout<<"\n"<<neg_value<<" elements in the float array are negative";
return 0;
}

