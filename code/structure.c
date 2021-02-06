/* a. Write C codes to create LinkedList that contains student nodes. The program should read the values for the studentName and courseName from the user, assign a random number between 1 – 100 to the studentId and random number between 100 – 1000 to the courseId. The next pointer to be assigned NULL as the value.
b. Write C codes to create a Linked List of 10 students. Student nodes in the Linked List to be sorted based on the studentId.
c. Write C code to write the student list on to a text file.
d. Write C code to read a student name. Search for the student name in the list and if found, delete the node from the list.
e. Write C code to read a student name. Search for the student name in the list and if found, allow the user to edit the studentId. (Ensure the new ID is between 1 – 100). Reposition the student node based on the new studentId.
Code:
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//You can define your own numbers but keep it less than 100
#define countOfStudent 10
struct personal{
    char studentName[20];
    char studentId[10];
};
struct course{
        char courseName[20];
        char courseId[10];
};
struct student{
    struct personal studentInfo;
    struct course courseInfo;
    struct student *next;
};
//Global Variables
//needed to keep the randomised uniques student Ids
char vector[countOfStudent][5];
int i=0;
typedef struct student Student;
Student  *head =NULL;
//creation of new node
Student* createNode(){
    Student *node = (Student*)malloc(sizeof(Student));
    //copy the random value from random array to this value
    strcpy(node->studentInfo.studentId,vector[i++]);
    printf("Enter the Student Name: ");
    scanf("%[^\n]%*c",node->studentInfo.studentName);
    printf("Enter the course name: ");
    scanf("%[^\n]%*c",node->courseInfo.courseName);
    printf("\n");
    int num = (rand() %(1000 - 100 + 1)) + 100;
    sprintf(node->courseInfo.courseId,"%d",num);
    node->next=NULL;
    return node;
}
//Inserting the node value according to their student id
void insert(Student *node){
    Student *temp=head;
    if(head==NULL){
        head=node;
    }
    else if(strcmp(node->studentInfo.studentId,head->studentInfo.studentId)<0){
        node->next=head;
        head=node;
    }
    else
        {
            while(temp->next!=NULL && strcmp(temp->next->studentInfo.studentId,node->studentInfo.studentId)<0 ){
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
    }
}
/* Given a reference (pointer to pointer) to the head of a list and a key, deletes the first occurrence of key in linked list */
int deleteNode( char key[])
{
    Student * temp = head, *prev;
    // If head node itself holds the key to be deleted
    if (temp != NULL && strcmp(head->studentInfo.studentName,key)==0)
    {
        head= temp->next;   // Changed head
        free(temp);               // free old head
        return 1;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && strcmp(temp->studentInfo.studentName,key)!=0)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL) {
        return -1;
    }
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    return 1;
}
void printLL(){
    if(head==NULL){
        printf("Empty List\n");
    }
    else{
        Student *temp=head;
        printf("%-20s%-20s%-20s%-20s\n","Student ID","Student Name","Course Id","Course Name");
        while (temp!=NULL){
            printf("%-20s%-20s%-20s%-20s\n",temp->studentInfo.studentId,temp->studentInfo.studentName,temp->courseInfo.courseId,temp->courseInfo.courseName);
            temp=temp->next;
        }
        printf("\n");
    }
}
void delAndRep(char key[]){
    Student * temp = head, *prev;
    char newkey[5];
    Student *node=(Student*)malloc(sizeof(Student));
    node->next=NULL;
    // If head node itself holds the key to be deleted
    if (temp != NULL && strcmp(head->studentInfo.studentId,key)==0)
    {
        printf("Key Found!!! Enter the new key: ");
        gets(newkey);
        head= temp->next;
        strcpy(node->studentInfo.studentId,newkey);
        strcpy(node->studentInfo.studentName,temp->studentInfo.studentName);
        strcpy(node->courseInfo.courseName,temp->courseInfo.courseName);
        strcpy(node->courseInfo.courseId,temp->courseInfo.courseId);
        // Changed head
        free(temp);
        insert(node);
        return;// free old head
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && strcmp(temp->studentInfo.studentId,key)!=0)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL) {
        printf("The Given ID is not available \n");
        return;
    }
    printf("Key Found!!! Enter the new key: ");
    gets(newkey);
    //copying the old values to new values
    strcpy(node->studentInfo.studentId,newkey);
    strcpy(node->studentInfo.studentName,temp->studentInfo.studentName);
    strcpy(node->courseInfo.courseName,temp->courseInfo.courseName);
    strcpy(node->courseInfo.courseId,temp->courseInfo.courseId);
    insert(node);
    prev->next = temp->next;
    free(temp);
}
void writeInFile(){
    Student *temp=head;
    FILE *fptr;
    fptr=fopen("listOfStudent.txt","w+");
    fprintf(fptr,"%-20s%-20s%-20s%-20s\n","Student ID","Student Name","Course Id","Course Name");
   while(temp!=NULL){
        fprintf(fptr,"%-20s%-20s%-20s%-20s\n",temp->studentInfo.studentId,temp->studentInfo.studentName,temp->courseInfo.courseId,temp->courseInfo.courseName);
        temp=temp->next;
    }
   fclose(fptr);
}
//here generating random number is very easy but generating unique random numbers is a difficult one
void uniqueRandomNum(){
    int list[100];
    for(int i=0;i<100;i++){
        list[i]=i;
    }
    for(int i=0;i<100;i++){
        int j=i+rand()%(100-i);
        int temp=list[i];
        list[i]=list[j];
        list[j]=temp;
    }
    for(int i=0;i<countOfStudent;i++){
        sprintf(vector[i],"%d",list[i]);
    }
}
int main() {
    //calling unique number creator
    uniqueRandomNum();
    for(int i=0;i<countOfStudent;i++){
        insert(createNode());
    }
    printLL();
    //writting the list in the file
    writeInFile();
    printf("Enter the name student to be deleted:");
    char name[20];
    gets(name);
    int verify=deleteNode(name);
    if(verify==1){
        printf("Student Deleted \n");
    }
    else if(verify==-1){
        printf("Student Not Present in the List\n");
    }
    printf("After Deletion Operation:\n");
    printLL();
    printf("Enter the student Id to be replaced: ");
    char idtoreplace[5];
    gets(idtoreplace);
    delAndRep(idtoreplace);
    printf("After replacement: \n");
    printLL();
}

