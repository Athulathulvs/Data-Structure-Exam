 #include<stdio.h>
 #include<conio.h>
 int ch,pos,n,m;
 int info,data,start,node;
 int i,tmp;
 struct node
 {
  int data;
  struct node*link;
 };
 main()
 {
  int i,ch;
  while(ch!=7)
  {
   printf("1.creation\n");
   printf("2.insert at begining\n");
   printf("3.insert at any position\n");
   printf("4.deletion at the end\n");
   printf("5.display\n");
   printf("6.Quit\n");
   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
     {
       printf("enthe the number of nodes to be entered");
       scanf("%d",&n);
       create(m);
       break;
     }
     case 2:
     {
       printf("enter the node to add at start");
       scanf("%d",&m);
       add_beg(m);
       break;
     }
     case 3:
     {
       printf("enter the node to be  added");
       scanf("%d",&m);
       add_at_any(m);
       break;
     }
     case 4:
     {
       printf("the deleted node is %d",&m);
       del_last(m);
       break;
     }
     case 5:
       display();
       break;
     case 6:
       exit();
       break;
     default:
       printf("invalid choice");
   }
  }
  getch();
}
create()
 {
 struct node *tmp,*q;
 tmp=(node*)malloc(sizeof(node*));
 tmp->info=data;
 tmp->link=start;
 q=start;
 while(start!=NULL)
  {
   q=q->link;
   q->link=tmp;
   }
printf("the node are",q->link);
}
add_beg()
{
  struct node*tmp,*q;
  tmp=(node*)malloc(sizeof(node*));
  tmp->info=data;
  tmp->link=start;
}
add_at_any()
 {
  printf("enter the position to add the node");
  scanf("%d",&pos);
  for(i=0;i<pos;i++)
  {
    if(pos>n)
      printf("node cannot be entered");
   
    else
     {
      tmp->info=data;
      tmp->link=next;
      prev->link=tmp;
     }
  }
  }
del_last()
{
if(start==NULL)
  print("list is empty");
else
  struct node *tmp;
  if(start->next=NULL)
  start=NULL;
  while(start->next!=NULL)
  {
  start=q;
  q=q->link;
  q->link=tmp;
  free(tmp);
}
dispaly()
  {
  while(start=NULL)
   printf("list is empty")
  printf("the list is:");
  for(i=0;i<n;i++)
   printf("%d"q->link);
  }
