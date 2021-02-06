
/* Using the student structure given above, create an array of size 5 students. Then write a complete C program to sort the students array based on the students rank. Use the following sorting techniques in your code.
Don’t forget to print initial array and final (sorted) array.
a. Insertion sort
b. Merge sort
c. Quick sort
*/
#include<stdio.h>

struct grade
{ char id[1];
int marks;
};

// FUNCTION DECLARATIONS
void insertion_sort(struct grade students[]);
void merge(struct grade students[], int left, int middle, int right); void swap(int* a, int* b);
void print(struct grade students[]);
void merge_sort(struct grade students[],int left,int right); void quick_sort(struct grade students[], int low, int high); int partition (struct grade students[], int low, int high);


int main()
{
int i,n=0;
struct grade students[5];

for(i=0;i<5;i++)
{
printf("Enter id and marks of student %d:-\n",i+1); scanf("%s",&students[i].id); scanf("%d",&students[i].marks);

}
// UNSORTED DATA
printf("(UNSORTED  DATA)\n");
printf("ID\tMarks\n");

for(i=0;i<5;i++)
{
printf("%s\t",students[i].id); printf("%d\n",students[i].marks);

}

printf("\nEnter 1 for insertion sort.\nEnter 2 for merge sort.\nEnter 3 for Quick sort sort.\n"); scanf("%d",&n);
switch(n)
{

case 1:
// SORTING VIA INSERTION SORT
insertion_sort(students);
printf("\n(SORTING METHOD= INSERTION SORT)\n");
print(students); break;

case 2:
//SORTING VIA MERGE SORT
merge_sort(students, 0,4);
printf("\n(SORTING METHOD= MERGE SORT)\n");
print(students); break;

case 3:
// SORTING VIA QUICK SORT
merge_sort(students, 0,4);
printf("\n(SORTING METHOD= QUICK SORT)\n");
print(students);
break;
default:
printf("Enter valid option.\n");

}

}

// INSERTION SORT FUNCTION
void insertion_sort(struct grade students[])

{

int i, key, j;
for (i = 1; i < 5; i++) { key = students[i].marks; j = i - 1;
while (j >= 0 && students[j].marks > key) { students[j+1].marks = students[j].marks;
j = j - 1;
}
students[j+1].marks = key;
}

}

//FUNCTIONS REQUIRED FOR MERGE SORT->
void merge(struct grade students[], int left, int middle, int right)
{
int i, j, k;
int n1 = middle - left + 1; int n2 = right - middle;

/* create temp arrays */ struct grade L[n1]; struct grade R[n2];

/* Copy data to temp arrays L[] and R[] */ for (i = 0; i < n1; i++)
L[i].marks = students[left + i].marks; for (j = 0; j < n2; j++)
R[j].marks = students[middle + 1 + j].marks;

/* Merge the temp arrays back into arr[l..r]*/
i = 0;
j = 0; // Initial index of second subarray
k = left; // Initial index of merged subarray
while (i < n1 && j < n2) {
if (L[i].marks <= R[j].marks) { students[k].marks = L[i].marks; i++;
}
else {
students[k].marks = R[j].marks; j++;
} k++;
}

/* Copy the remaining elements of L[], if there are any */
while (i < n1) { students[k].marks = L[i].marks; i++;
k++;
}

/* Copy the remaining elements of R[], if there are any */
while (j < n2) { students[k].marks = R[j].marks; j++;
k++;
}
}


// MERGE SORT FUNCTION
void merge_sort(struct grade students[],int left,int right)

{
if (left < right) {

// large l and h
int middle = left + (right - left) / 2;
// Sort first and second halves merge_sort(students, left, middle); merge_sort(students, middle + 1, right);

merge(students, left, middle, right);
}

}

// FUNCTIONS REQUIRED FOR QUICK SORT->

void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right of pivot */
int partition (struct grade students[], int low, int high)
{
int pivot = students[high].marks; // pivot
int i = (low - 1);

for (int j = low; j <= high- 1; j++)
{
// If current element is smaller than the pivot if (students[j].marks < pivot)
{
i++; // increment index of smaller element
swap(&students[i].marks, &students[j].marks);
}
}
swap(&students[i + 1].marks, &students[high].marks); return (i + 1);
}


void quick_sort(struct grade students[], int low, int high)
{
if (low < high)
{
/* pi is partitioning index, arr[p] is now at right place */
int pi = partition(students, low, high);

// Separately sort elements before
// partition and after partition quick_sort(students, low, pi - 1); quick_sort(students, pi + 1, high);
}
}

void print(struct grade students[])
{ int i; printf("\nID\tMarks\n"); for(i=0;i<5;i++)
{
printf("%s\t",students[i].id); printf("%d\n",students[i].marks);

}
}
