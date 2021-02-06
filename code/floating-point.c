
/* Write a complete C program that inserts 10 random integers between 0 and 50 in order in a linked list.
Create a separate function to calculate the floating-point average of the elements.
You must use a self-referential structure to create the linked list for this program */
#include<bits/stdc++.h>

using namespace std;

//Declaring Node as structure

struct Node

{

int data;

struct Node*next; //pointer to next link

};

//creating function to insert node into the linked list/

void insert_no(struct Node** head_ref, struct Node* node_new)

{

struct Node* current;

/*checking that node is first node in the linked list OR data of node_new is

less or equal to the data of that node which head_ref is pointing*/

if (*head_ref == NULL || (*head_ref)->data >= node_new->data)

{

//node_new will point to that node which is pointed by head_ref pointer/

node_new->next = *head_ref;

/* head_ref will now point to node_new*/

*head_ref = node_new;

}

else

{

current = *head_ref;

/*if new node has to be inserted in between two node,

find its correct inorder position in the linked list */

while (current->next!=NULL && current->next->data < node_new->data)

{

current = current->next;

}

//insert node to its correct position/

node_new->next = current->next;

current->next = node_new;

}

}

/*function to create a new node with randomly generated data

and this will return newly created node*/

struct Node *newNode(int new_data)

{

//creating a new node/

struct Node* node_new = new struct Node;

//assigning data to newly created node/

node_new->data = new_data;

//making its pointer NULL/

node_new->next = NULL;

return node_new;

}

// Function to find floating-point average of all the values in the linked list

float avg(struct Node** head_ref)

{

int sum=0;

Node *h=*head_ref ;

/*Checking h is not equal to NULL as we are traversing to end */

while(h!=NULL)

{

sum=sum+h->data;

h=h->next;

}

// returning Average

return (float)sum/10;

}

//driver function

int main()

{

// creating pointers

struct Node*head=NULL,*temp,*newnode;

int d;

for(int i=0;i<10;i++)

{

// generating random values from range 0 to 50

d=rand()%51;

// Calling function for inserting 10 random integer inorder(ascending)

insert_no(&head,newNode(d));

}

temp=head;

// Loop for printing the random values

while(temp)

{

cout<<temp->data<<" ";

temp=temp->next;

}

cout<<endl;

// Calling avg function and printing the value

cout<<"Average of numbers in the above linked list is : "<<avg(&head)<<endl;

}
