#include<stdio.h>
#include<stdlib.h>
void create(int n);
void display();
void delete_a_node_at_beginning();
void delete_a_node_at_end();
void delete_a_node_at_given_position();
struct node
{
int data;
struct node *nextptr;
} *firstnode;

int main()
{
int n;
printf("Input the number of node:\n");
scanf("%d",&n);
if(n<=0)
{
printf("Invalid\n");
exit(0);
}
create(n);
do
{
int ch;
printf("Input the desired operation:\n1.  DELETE A NODE AT THE BEGINNING\n2.  DELETE A NODE AT THE END\n3.  DELETE A NODE AT GIVEN POSITION\n4.  DISPLAY\n5.  EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
delete_a_node_at_beginning();
break;
case 2:
delete_a_node_at_end();
break;
case 3:
delete_a_node_at_given_position();
break;
case 4:
display();
break;
case 5:
printf("PROGRAM TERMINATED");
exit(0);
}
}
while(1);
return 0;
}
void create(int n)
{
struct node *node,*temp;
int num,i;
firstnode=(struct node *)malloc(sizeof(struct node));
if(firstnode==NULL)
{
printf("Memory can't be allocated.");
}
else
{
printf("Input data for node 1:   ");
scanf("%d",&num);
firstnode->data=num;
firstnode->nextptr=NULL;
temp=firstnode;
for(i=2;i<=n;i++)
{
node=(struct node *)malloc(sizeof(struct node));
if(node==NULL)
{
printf("Memory can't be alocated.");
break;
}
else
{
printf("Input data for node %d:   ",i);
scanf("%d",&num);
node->data=num;
node->nextptr=NULL;
temp->nextptr=node;
temp=temp->nextptr;
}
}
}
}
void display()
{
struct node *temp;
temp=firstnode;
if(temp==NULL)
{
printf("Empty linked-list");
exit(0);
}
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->nextptr;
}
}

void delete_a_node_at_beginning()
{
struct node *temp;
if(firstnode==NULL)
{
printf("List is empty.");
}
else
{
temp=firstnode;
printf("Deleted data is %d.",firstnode->data);
firstnode=firstnode->nextptr;
free(temp);
}
}
void delete_a_node_at_end()
{
struct node *temp,*firstnode,*tail;
if(firstnode==NULL)
{
printf("List is empty.");
}
else
{
temp=firstnode;
while(temp->nextptr!=NULL)
{
tail=temp;
temp=temp->nextptr;
}
free(tail);
tail->nextptr=NULL;
}
}
void delete_a_node_at_given_position()
{
struct node *temp,*position,*firstnode;
int i=1,pos;
if(firstnode==NULL)
{
printf("List is empty.");
}
else
{
printf("Input the position:\n");
scanf("%d",&pos);
position=malloc(sizeof(struct node));
temp=firstnode;
while(i<pos-1)
{
temp=temp->nextptr;
i++;
}
position=temp->nextptr;
temp->nextptr=position->nextptr;
free(position);
}
}