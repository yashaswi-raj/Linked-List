#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*firstnode;
int creation(int n);
int display();
int search(int key);
int main()
{
int n,key;
printf("Input the number of node>>>");
scanf("%d",&n);
if(n<=0)
{
printf("Invalid");
exit(0);
}
creation(n);
printf("Data in the list is>>>\n");
display();
printf("Enter the data to search>>>");
scanf("%d",&key);
search(key);
return 0;
}
int creation(int n)
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
printf("Input data for node 1>>>");
scanf("%d",&num);
firstnode->data=num;
firstnode->next=NULL;
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
printf("Input data for node %d>>>",i);
scanf("%d",&num);
node->data=num;
node->next=NULL;
temp->next=node;
temp=temp->next;
}
}
}
}
int display()
{
struct node *temp;
temp=firstnode;
if(temp==NULL)
{
printf("List is empty.");
exit(0);
}
while(temp!=NULL)
{
printf("Data>>>%d\n",temp->data);
temp=temp->next;
}
}
int search(int key)
{
//int key;
struct node *temp;
temp=firstnode;
if(temp==NULL)
{
printf("List is empty.");
exit(0);
}
while(temp!=NULL)
{
if(temp->data==key)
{
printf("Data is found.");
exit(0);
}
else
{
printf("Data is not found.");
exit(0);
}
temp=temp->next;
}
}