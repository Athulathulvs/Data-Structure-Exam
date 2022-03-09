    #include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>

    void insertionfirst();
    void insertatany();
    void display();
    void delet();

    struct Node
    {
    int data;
    struct Node *next;
    }*head = NULL;

    void main()
    {
    int choice,value,choice1,loc1,loc2;
    clrscr();
    while(1){
    mainMenu: printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
	    case 1:printf("Enter the value to be insert: ");
		   scanf("%d",&value);
		   while(1){
		   printf("Where you want to insert: \n1.At Beginning\n2.At any position\nEnter your choice: ");
		   scanf("%d",&choice1);
		   switch(choice1)
	    {
	    case 1:insertionfirst(value);
		   break;


	    case 2:printf("Enter the two values where you wanto insert: ");
		   scanf("%d%d",&loc1,&loc2);
		   insertatany(value,loc1,loc2);
		   break;
	    default:printf("\nWrong Input!! Try again!!!\n\n");
		    goto mainMenu;
	    }
	    goto subMenuEnd;
	    }
	    subMenuEnd:
	    break;

	case 2:
		display();
		break;
	case 3:
		delet();
		break;

	case 4:
		exit(0);
	default:
	    printf("\nWrong input!!! Try again!!\n\n");
    }
    }
    }

    void insertionfirst(int value)
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
    void insertatany(int value, int loc1, int loc2)
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
    void delet()
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
