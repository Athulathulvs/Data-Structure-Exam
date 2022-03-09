#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertAtBeginning();
void insertBetween();
void display();
void removeEnd();
 struct Node
 {
   int data;
   struct Node *next;
   }*head = NULL;

   void main()
   {
    int choice,value,choice1,loc1,loc2;
    clrscr();
    while(1)
    {
    printf("\n_________________MAIN MENU_________________\n");
    printf("\n1. Insert\n2. Display\n3. insert between\n4. remove end\n5.exit\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:
       insertAtBeginning(value);
       break;
       case 2:
       display();
       break;
       case 3:
       insertBetween();
       break;
       case 4:
       removeEnd();
       break;
       case 5:
       exit(0);
       default:
       printf("\nWrong input!!! Try again!!\n\n");
    }
    }
    }

    void insertAtBeginning(int value)
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
    void insertBetween(int value, int loc1, int loc2)
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
    void removeEnd()
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
    if(head==NULL)
    {
	printf("\nList is Empty\n");
    }
    else
    {
	struct Node *temp = head;
	printf("\n\nList elements are - \n");
	while(temp->next != NULL)
	{
	printf("%d->",temp->data);
	temp=temp->next;
	}
	printf("%d->NULL",temp->data);
    }
    }
