
/*
struct student {
char name[10];
int rank;
};
Using the student structure given above, create an array of size 5 students. Then write a complete C program to sort the students array based on the students rank. Use the following sorting techniques in your code.
Don’t forget to print initial array and final (sorted) array.
a. Bubble sort
b. Selection sort

*/

#include <stdio.h>
struct student {
    int rank;
    char name[10];
};
// bubble sort function
void sortbubb(struct student class_record[5], int s)
{
    int i, j;
    struct student t;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1 - i); j++)
        {
            if (class_record[j].rank > class_record[j + 1].rank)
            {
                t = class_record[j];
                class_record[j] = class_record[j + 1];
                class_record[j + 1] = t;
            }
        }
    }
}
// selection sort function
void sortsel(struct student class_record[5], int s)
{
    int i, j, min_idx;
    struct student t;
    for (i = 0; i < s - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < s; j++)
            if (class_record[j].rank < class_record[min_idx].rank)
                min_idx = j;// finding minimum element from array

        t = class_record[i];// swapping minimum element with first element
        class_record[i] = class_record[min_idx];
        class_record[min_idx] = t;
    }
}
// Function to displays the contents of the array of structures
void display(struct student class_record[5])
{
    int i, len = 5;
    for (i = 0; i < len; i++) {
        printf("Roll number : %d",
               class_record[i].rank);
        printf(" Name: %s",
               class_record[i].name);
        printf("\n");
    }
}
// Driver Code
int main()
{
    // Initialize of an array of structures
    int choice;
    struct student class_record[5]
        = { { 3, "Json" },
        { 2, "Hope" },
        { 1, "Batman" },
        { 4, "Hose" },
        { 5, "William" }
    };
    display(class_record);
    printf("Which technique to use for sorting: 1. Bubble sort\n2.Selection sort\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("After Bubble Sort\n");
        sortbubb(class_record, 5);
    }
    if (choice == 2) {
        printf("After Selection Sort\n");
        sortsel(class_record, 5);
    }
    display(class_record);
    return 0;
}

