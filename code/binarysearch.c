/*Binary Search
a. The function should receive an integer array, a search key, the starting subscript and ending subscript as arguments.
b. If the search key is found, return the location in the array where the search key is found; otherwise, return -1.
*/
#include <stdio.h>
int main()
{
  int c, first, last, middle, n, search, array[10];

  printf("Enter number of elements of an array:\n");
  scanf("%d", &n);

  printf("Enter %d elements:\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("Enter item to search\n");
  scanf("%d", &search);

  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("Item found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last) {
    return -1;
  }
return 0;
}

