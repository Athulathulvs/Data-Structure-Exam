#include<stdio.h>
#include<conio.h>
struct Node
{
  int data;
  struct Node *next;
};
typedef struct Node node;
node *getnode();
void main()
{
  int item,pos,ch,i;
  node *first=NULL,*current,*prev,*temp;
  clrscr();
  do
  {
    printf("Enter your choice");
    printf("\n1.insert at beginning\n 2.insert at particular position\n 3.delete at end\n 4.display\n 5.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter the item to insert");
	     scanf("%d",&item);
	     temp=getnode();
	     temp->data=item;
	     temp->next=first;
	     first=temp;
	     break;
      case 2:printf("enter the item to insert");
	     scanf("%d",&item);
	     printf("enter the place to insert\n");
	     scanf("%d\n",&pos);
	     temp=getnode();
	     temp->data=item;
	     current=first;
	     if(pos==1)
	     {
	       temp->next=first;
	       first=temp;
	     }
	     else
	     {
	       i=2;
	       current=first->next;
	       prev=first;
	       while(current!=NULL)
	       {
		 if(pos==i)
		 {
		   temp->next=prev->next;
		   prev->next=temp;
		   break;
		 }
		 prev=current;
		 current=current->next;
		 i++;
	       }
	       if(current==NULL)
	       {
		temp->next=NULL;
		prev->next=temp;
	       }
	     }
	     break;
    case 3:if(first==NULL)
	   {
	     printf("list is empty\n");
	   }
	   else
	   {
	     current=first;
	     prev=current;
	     while(current->next!=NULL)
	     {
	       prev=current;
	       current=current->next;
	     }
	     prev->next=NULL;
	     free(current);
	   }
	   break;
    case 4:if(first==NULL)
	   {
	     printf("the list is empty\n");
	   }
	   else
	   {
	     printf("the list:\n");
	     current=first;
	     while(current!=NULL)
	     {
	       printf("%d-",current->data);
	       current=current->next;
	     }
	   }
	   break;
    case 5:exit(0);
    default:printf("wrong input\n");
    }
  }
  while(ch!=6);
  getch();
}
node *getnode()
{
  node *p;
  p=(node*)malloc(sizeof(node));
  return p;
}