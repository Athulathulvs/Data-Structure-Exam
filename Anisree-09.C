#include<stdio.h>
#include<conio.h>
struct Node
{
  int data;
  struct Node *link;
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
    printf("\nSelect your choice");
    printf("\n\t1 insert at first\n\t2 insert at a position\n\t");
    printf("3 Delete at end\n\t4 Display\n\t5 Exit  ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nenter the item to insert ");
	     scanf("%d",&item);
	     temp=getnode();
	     temp->data=item;
	     temp->link=first;
	     first=temp;
	     break;
      case 2:printf("\nenter the item to insert ");
	     scanf("%d",&item);
	     printf("\nenter the position ");
	     scanf("%d",&pos);
	     temp=getnode();
	     temp->data=item;
	     current=first;
	     if(pos==1)
	     {
		temp->link=first;
		first=temp;
	     }
	     else
	     {
		i=2;
		current=first->link;
		prev=first;
		while(current!=NULL)
		{

		  if(pos==i)
		  {
		    temp->link=prev->link;
		    prev->link=temp;
		    break;
		  }
		  prev=current;
		  current=current->link;
		  i++;
		}
		if(current==NULL)
		{
		  temp->link=NULL;
		  prev->link=temp;
		}
	     }
	     break;
      case 3:if(first==NULL)
	       printf("\nthe linkedlist is empty\n");
	     else
	     {
	       current=first;
	       prev=current;
	       while(current->link!=NULL)
	       {
		 prev=current;
		 current=current->link;
	       }
	       prev->link=NULL;
	       free(current);
	     }
	     break;
      case 4:if(first==NULL)
	       printf("\nthe list is empty");
	     else
	     {
	       printf("\nthe list is\n");
	       current=first;
	       while(current!=NULL)
	       {
		 printf("%d->",current->data);
		 current=current->link;
	       }
	     }
	     break;
      case 5:exit(0);
      default:printf("\ninvalid input");
    }
  }while(ch!=6);
  getch();
}
node *getnode()
{
  node *p;
  p=(node*)malloc(sizeof(node));
  return p;
}
