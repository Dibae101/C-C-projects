
/*Write a function printlistBackward that recursively outputs the items in a list in reverse order. Use your function in a test program that creates a sorted list of integers and prints the list in reverse order. (Recursively Print a List Backward)
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the reverse
int printlistBackward(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

// Function to sort the array according to
// the reverse of elements
void sortArr(int arr[], int n)
{
    // Vector to store the reverse
    vector<pair<int, int> > vp;

    // Inserting reverse with elements
    // in the vector pair
    for (int i = 0; i < n; i++) {
        vp.push_back(
            make_pair(printlistBackward(arr[i]),
                      arr[i]));
    }

    // Sort the vector, this will sort the pair
    // according to the reverse of elements
    sort(vp.begin(), vp.end());

    // Print the sorted vector content
    for (int i = 0; i < vp.size(); i++)
        cout << vp[i].second << " ";
}

// Driver code
int main()
{
    int arr[] = { 15,5,78,445,256,412,55,62,45,213 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, n);

    return 0;
}
