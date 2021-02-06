/* Create a linked list using the following structure
struct studentname {
char letter;
struct studentname *next;
};
typedef struct studentname STUDENTName;
typedef STUDENTName *STUDENTNamePtr;
Create a linked list manually (without using any loops or recursive functions or any functions) that contains five nodes where the data part (structure element letter) of the nodes should be the first five letters of yourlast name. One letter will go to one node and the node insertion should happen one after another in alphabetical order. When you insert a new node, it should be in the right place to get alphabetical order as shown in previous task. If your last name doesn’t have five letters fill the remaining nodes with letters from your first name starting from the first letter (Eg: if your name is Devin Ly, then nodes will contain L, y, D, e and v).

*/
#include <iostream>
using namespace std;

struct studentname {
char letter;
struct studentname *next;
};
int i;
struct studentname *head,*curr, *c, *c1;

int main() {

char name[50]="PONTING";
head->letter = name[0];
if(name[i]=='\0')
{
i=0;
}
curr = new struct studentname;
curr->letter = name[i];
if(curr->letter < head->letter) {
// set current as head
curr->next = head;
head = curr;

} else { c = head;
c1 = c->next;
while( c1->letter < name[i])
    {
        c = c->next;
if(c1->next==NULL)
{
break;	// break if end of string
}
else
{
c1=c1->next;
}
}
c->next = curr;
curr->next = c1;
}
}
c = head;
i=0;
while(i<5) {

cout<<c->letter<<" ";
c = c->next;
i++;
}
return(0);
}

