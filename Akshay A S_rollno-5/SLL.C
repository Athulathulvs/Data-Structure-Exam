#include<stdio.h>
#include<conio.h>
struct Node
{
 int data;
 struct Node*next;
};
typedef struct Node node;
node *getnode();
void main()
{
  int item,pos,choice,i;
  node *first=NULL,*current,*prev,*temp;
  clrscr();
  do
  {
   printf("Enter your choice:\n");
   printf("1.Insertion at front:\n2.Insert at a position:\n3.Delete from end:\n4.Display\n5.Exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1:printf("Enter the item to be inserted:");
	    scanf("%d",&item);
	    temp=getnode();
	    temp->data=item;
	    temp->next=first;
	    first=temp;
	    break;
     case 2:printf("Enter the item to be inserted at a position");
	    scanf("%d",&item);
	    printf("Enter the position:");
	    scanf("%d",&pos);
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
	     while(current->next!=NULL)
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
	    printf("List is empty:\n");
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
	     printf("List is empty");
	    else
	    {
	     printf("Elements in the list are:\n");
	     current=first;
	     while(current!=NULL)
	     {
	      printf("%d\n",current->data);
	      current=current->next;
	     }
	    }
	    break;
     case 5:exit(0);
     default:printf("Invalid choice");
   }
  } while(choice!=6);
    getch();
}
node *getnode()
{
 node *p;
 p=(node*)malloc(sizeof(node));
 return p;
}