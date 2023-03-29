#include<stdio.h>
#include<stdlib.h>
void create(int n);
void display();

void insert_a_node_at_beginning();
void insert_a_node_at_end();
void insert_a_node_at_given_position();


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
printf("Input the desired operation:\n1.  INSERT A NODE AT THE BEGINNING\n2.  INSERT A NODE AT THE END\n3.  INSERT A NODE AT GIVEN POSITION\n4.  DISPLAY\n5.  EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert_a_node_at_beginning();
break;
case 2:
insert_a_node_at_end();
break;
case 3:
insert_a_node_at_given_position();
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
printf("Input data for node %d:   ",i);
scanf("%d",&num);
node->data=num;
node->nextptr=NULL;
temp->nextptr=node;
temp=temp->nextptr;
   }
 }
 }


void display()
{
struct node *temp;
if(temp==NULL)
{
printf("Empty linked-list");
exit(0);
}
temp=firstnode;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->nextptr;
}
}


void insert_a_node_at_beginning()
{
int value;
struct node *newnode;//*node;
//node=firstnode;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("Can't insert a node");
}
else{
printf("Input the value to insert:");
scanf("%d",&value);
newnode->data=value;
newnode->nextptr=firstnode;
firstnode=newnode;
printf("\nNew element inserted successfully at beginning !!!");
}
}


void insert_a_node_at_end()
{
int value;
struct node *newnode,*temp;
newnode=(struct node *)malloc(sizeof(struct node));
printf("Input the value to insert:   ");
scanf("%d",&value);
newnode->data=value;
newnode->nextptr=NULL;
temp=firstnode;
while(temp->nextptr=NULL)
{
printf("%d\n",temp->data);
temp=temp->nextptr;
}
temp->nextptr=newnode;
printf("\n\nInsertion at End Done\n\n");
//node->nextptr=newnode;
}


void insert_a_node_at_given_position()
{
int value,position,n;
printf("Input the position to insert:   ");
scanf("%d",&position);
/*if(position<1||position>n+1)
{
printf("INVALID");
exit(0);
}*/
if(firstnode==NULL)
{
printf("Empty Linklist position Invalid..");
return;
}

printf("Input the value to insert:   ");
scanf("%d",&value);
}