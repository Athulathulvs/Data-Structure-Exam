#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertAtFront();
void insertAnyPos();
void display();
void deleteAtEnd();
struct Node
{
 int data;
 struct Node *next;
 }*head = NULL;

void main()
{
 int ch,value,loc1,loc2;
 clrscr();
 while(1)
 {
 printf("\n1. Insert at Front\n2. Insert at any position\n3. Delete at the end\n4.Display\n5.Exit \nEnter your choice: ");
 scanf("%d",&ch);
 switch(ch)
   {
    case 1:  printf("Enter the value you want to insert:");
     scanf("%d",&value);
     insertAtFront(value);
     break;
    case 2:
     printf("Enter the two values where you want to insert: ");
     scanf("%d%d",&loc1,&loc2);
     insertAnyPos(value,loc1,loc2);
     break;
    case 3:
    deleteAtEnd();
    case 4:
     display();
     break;
    case 5:
     exit(0);
    default:
     printf("\nWrong input!!! Try again!!\n\n");
    }
   }
 }

void insertAtFront(int value)
{
 struct Node *newNode;
 newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 if(head == NULL)
 {
  newNode->next = NULL;
  head = newNode;
 }
 else
 {
  newNode->next = head;
  head = newNode;
 }
  printf("\nOne node inserted!!!\n");
}
void insertAnyPos(int value, int loc1, int loc2)
{
 struct Node *newNode;
 newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 if(head == NULL)
 {
  newNode->next = NULL;
  head = newNode;
 }
 else
 {
  struct Node *temp = head;
  while(temp->data != loc1 && temp->data != loc2)
  temp = temp->next;
  newNode->next = temp->next;
  temp->next = newNode;
 }
 printf("\nOne node inserted!!!\n");
}
void deleteAtEnd()
{
 if(head == NULL)
 {
  printf("\nList is Empty!!!\n");
 }
 else
 {
  struct Node *temp1 = head,*temp2;
  if(head->next == NULL)
  head = NULL;
  else
  {
   while(temp1->next != NULL)
   {
    temp2 = temp1;
    temp1 = temp1->next;
   }
    temp2->next = NULL;
  }
  free(temp1);
  printf("\nOne node deleted!!!\n\n");
  }
 }

void display()
{
 if(head == NULL)
 {
  printf("\nList is Empty\n");
 }
 else
 {
  struct Node *temp = head;
  printf("\n\nList elements are - \n");
  while(temp->next != NULL)
  {
   printf("%d --->",temp->data);
   temp = temp->next;
  }
  printf("%d --->NULL",temp->data);
  }
}