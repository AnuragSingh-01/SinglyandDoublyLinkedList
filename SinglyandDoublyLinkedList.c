#include <stdio.h>
#include <stdlib.h>
#include<process.h>

//Code by Anurag Singh 
//@AnuragSingh-01

//In this project, I am trying to implement different type of operation on the Singly and Doubly LinkedList.


//*****************************************Singly LinkedList***************************************************
//*************************************************************************************************************

//creating a node.
struct node
{
  int data;
  struct node *next;
};

//create a function that supply node to our program.
struct node * create_node(int x)
{
  struct node *ptr;
  ptr=(struct node*)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
    printf("\n Sorry there is no space in the memory.\n");
	exit(0);
  }
  else
  {
    ptr->data=x;
	ptr->next=NULL;
  }

  return ptr;

}

// ------------display Function---------------------
void show(struct node *ptr)
{

  if(ptr==NULL)
  {
    printf("\nSorry there is no element in the linked list.\n");
	return ;
  }
  printf("\n");
  while(ptr!=NULL)
  {
    if(ptr->next==NULL)
	{
	  printf("%d->NULL",ptr->data);
	}
	else
	{
	  printf("%d->",ptr->data);
	}
	ptr=ptr->next;
  }
  printf("\n\n\n");
}


//-------------------Add operations----------------------
struct node * add_last(struct node *ptr,int x)
{
   struct node *new,*p=ptr;
   new=create_node(x);
   if(ptr==NULL)
   {
     ptr=new;
   }
   else
   {

    while(p->next!=NULL)
	 {
	   p=p->next;
	 }
	 p->next=new;
   }
   return ptr;
}

struct node * add_beg(struct node *ptr,int x)
{
  struct node *new,*p=ptr;
  new=create_node(x);
  if(ptr==NULL)
  {
    ptr=new;
  }
  else
  {
     new->next=ptr;
	 ptr=new;
  }
  return ptr;
}

//Here y is the data of the node after which we need to insert the new node.

struct node * add_after_node(struct node *ptr,int x,int y)
{
  struct node *new,*p;
  new=create_node(x);
  if(ptr==NULL)
  {
    printf("\nSorry there is no element in the linkedlist.\nSo inserting element at begning.\n");
	ptr=new;
  }
  else
  {
    p=ptr;
	while((p!=NULL)&&(p->data!=y))
	{
	  p=p->next;
	}
	if(p==NULL)
	{
	  printf("\nSorry the value after which we need to insert our node is not in the linkedlist.\n");
	}
	else
	{
	  new->next=p->next;
	  p->next=new;
	}
  }
return ptr;
}


//Here y is the data of the node before which we need to insert the new node.

struct node * add_before_node(struct node *ptr,int x,int y)
{
  struct node *new,*p;
  new=create_node(x);
  if(ptr==NULL)
  {
    printf("\nSorry there is no element in the linkedlist.\nSo inserting element at begning.\n");
	ptr=new;
  }
  else if(ptr->data==y)
  {
     new->next=ptr;
	 ptr=new;
  }
  else
  {
    p=ptr;
    while((p!=NULL)&&(p->next!=NULL)&&(p->next->data!=y))
	{
	  p=p->next;
	}
	if((p==NULL)||(p->next==NULL))
	{
	      printf("\nSorry the value before which we need to insert our node is not in the linked list.\n");
	}
	else
	{
	  new->next=p->next;
	  p->next=new;
	}
  }

  return ptr;
}

//--------------------sorting operation------------------------
void sorting(struct node *ptr)
{
	int temp;
	struct node *p,*s;
	for(p=ptr;p!=NULL;p=p->next)
	{
		for(s=ptr;s->next!=NULL;s=s->next)
		{
			if((s->data)>(s->next->data))
			{
			   temp=s->data;
		       s->data=s->next->data;
			   s->next->data=temp;
			}
		}
	}

}


//---------------------Delete Operations------------------------\\

struct node * delete_node(struct node *ptr,int y)
{
    struct node *p=ptr;
    if(ptr==NULL)
    {
        printf("\n\nSorry There is no element in the linkedlist...\n");
    }
    else if(ptr->data==y)
    {
        ptr=ptr->next;
    }
    else
    {
        while((p!=NULL)&&(p->next!=NULL)&&(p->next->data!=y))
        {
            p=p->next;
        }
        if((p==NULL)||(p->next==NULL))
            {
             printf("\nSorry this element is not available in the linked list\n");
            }
        else
             {p->next=p->next->next;}
    }
    return ptr;
}

struct node * delete_beg(struct node *ptr)
{
  if(ptr==NULL)
  {
	printf("\nSorry there is no element to delete.\n");
  }
  else
    ptr=ptr->next;

  return ptr;
}


struct node * delete_last(struct node *ptr)
{
	struct node *p=ptr;

   if(ptr==NULL)
   {
	printf("\nSorry there is no element to delete.\n");
   }
   else if(ptr->next==NULL)
   {
       ptr=NULL;
   }
   else
   {
	  while(p->next->next!=NULL)
	  {
		p=p->next;
	  }
	  p->next=NULL;
   }

   return ptr;
}



//Here y is the data of the node before which we need to delete the new node.

void delete_before_node(struct node *start,int y)
{
    struct node *ptr=start,*ctr;
    if(start==NULL)
    {
        printf("\n\nSorry there is no element in the linked list\n\n");
    }
    else if(start->data==y)
    {
        printf("\nSorry anything cannot be deleted because it is the very first node..\n");
    }
    else
    {
        while((ptr!=NULL)&&(ptr->data!=y))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\nSorry element not found..\n");
        }
        else
        {
            ctr=start;
            while(ctr->next!=ptr)
            {
                ctr=ctr->next;
            }
            ctr->next=ptr->next;
            ptr->next=NULL;
            free(ptr);
        }
    }
}

//Here y is the data of the node after which we need to delete the new node.


void delete_after_node(struct node *ptr,int y)
{
    struct node *p=ptr;
   if(ptr==NULL)
   {
	  printf("\nSorry there is no element to delete.\n");
   }
   else if(ptr->next==NULL)
   {
	   printf("\nSorry There is no node after after the first node,so we can't delete any node here.");
   }
   else
   {
	   while((p!=NULL)&&(p->data!=y))
	   {
		 p=p->next;
	   }
	   if((p==NULL)||(p->next==NULL))
	   {
		   printf("\nThere is no element to delete after it.\n");
	   }
	   else
	   {
		   p->next=p->next->next;
	   }
   }
}

//***************************************Doubly Linked List***************************************************
//************************************************************************************************************
struct node_d
{
    struct node_d *prev;
    int data;
    struct node_d *next;
};


//creating doubly linked list node supplier
struct node_d * create_node_d(int x)
{
    struct node_d *ptr=(struct node_d *)malloc(sizeof(struct node_d));
    if(ptr==NULL)
    {
        printf("\nSorry not able to make the doubly linked list project..\n\n");
    }
    else
    {
        ptr->prev=NULL;
        ptr->data=x;
        ptr->next=NULL;
    }
    return ptr;

}


//-------------------------------------Adding operations----------------------------------------

//Add beginning

struct node * add_beg_d(struct node_d *start,int x)
{
   struct node_d *ptr;
   ptr=create_node_d(x);
   if(start==NULL)
   {
       start=ptr;
   }
   else
   {
       ptr->next=start;
       start->prev=ptr;
       start=ptr;
   }

  return start;
}


// add last

struct node_d * add_last_d(struct node_d *start,int x)
{
    struct node_d *ptr,*p=start;
    ptr=create_node_d(x);
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->prev=p;
    }
    return start;

}



//Add node after a given node

struct node * add_after_node_d(struct node_d *start,int x,int y)
{
    struct node_d *new,*ptr;
    new=create_node_d(x);
    if(start==NULL)
    {
        printf("\n---------------------------------------------------------\nThere is no element in the linked list.\n-------------------------------------------------------\n");
    }
    else
    {
        ptr=start;
        while((ptr!=NULL)&&(ptr->data!=y))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\nSorry We cannot find your element..\n");
        }
        else if(ptr->next==NULL)
        {
            ptr->next=new;
            new->prev=ptr;
        }
        else
        {
           new->next=ptr->next;
           new->prev=ptr;
           ptr->next=new;
           new->next->prev=new;
        }
        return start;
    }

}

//Add before a given node

struct node * add_before_node_d(struct node_d *start,int x,int y)
{
   struct node_d *ptr,*new;
   new=create_node_d(x);
   if(start==NULL)
   {
     printf("\nSorry there is no element in the LinkedList.\n");
   }
   else if(start->data==y)
   {
       new->next=start;
       start->prev=new;
       start=new;
   }
   else
   {
       ptr=start;
       while((ptr!=NULL)&&(ptr->data!=y ))
       {
           ptr=ptr->next;
       }
       if(ptr==NULL)
       {
           printf("\n\nSorry the element before you want to our new node is not available in LinkedList. \n\n");
       }
       else
       {
           ptr=ptr->prev;
           new->next=ptr->next;
           new->prev=ptr;
           ptr->next=new;
           new->next->prev=new;
       }
     }

   return start;
}





//--------------------sorting operation------------------------


void sorting_d(struct node_d *ptr)
{
	int temp;
	struct node_d *p,*s;
	for(p=ptr;p!=NULL;p=p->next)
	{
		for(s=ptr;s->next!=NULL;s=s->next)
		{
			if((s->data)>(s->next->data))
			{
			   temp=s->data;
		       s->data=s->next->data;
			   s->next->data=temp;
			}
		}
	}

}


//----------- forward display function--------------------------------


void show_d_for(struct node_d *start)
{
   if(start==NULL)
   {
       printf("\nSorry there is no element in this doubly linked list..\n");
       return;
   }
    printf("\n\nThe Element of Doubly linked list in forword direction..\n\nstart-->");
    while(start!=NULL)
    {
      if(start->next==NULL)
      {
          printf("%d<-->NULL",start->data);
      }
      else
      {
          printf("%d<-->",start->data);
      }
      start=start->next;
    }

    printf("\n---------------------------------------------------------------------------\n");
}


//--------------reverse display function for doubly linked list.-----------------------

void show_d_back(struct node_d *start)
{

    printf("\n\nThe Element of Doubly linked list in reverse direction..\n\nNULL--");
    while(start->next!=NULL)
    {
       start=start->next;
    }
    while(start!=NULL)
    {
        if(start->prev==NULL)
        {
          printf("%d<--start",start->data);
        }
        else
        {
            printf("%d<-->",start->data);
        }
        start=start->prev;
    }
    printf("\n---------------------------------------------------------------------------\n");
}





//-------------------------Deletion Operations---------------------------------


//deletion from beginning

struct node_d * delete_beg_d(struct node_d *start)
{
    struct node_d *ptr;
    if(start==NULL)
    {
        printf("\nSorry there is no element in the linked list..\n");
    }
    else if(start->next==NULL)
    {
        start=NULL;
    }
    else
    {
        ptr=start;
        start=start->next;
        start->prev=NULL;
        ptr->next=NULL;
        free(ptr);
    }
    return start;
}


//deletion from end...
struct node_d * delete_last_d(struct node_d *start)
{
  if(start==NULL)
  {
      printf("\nSorry there is no element in the list\n");
  }
  else if(start->next==NULL)
  {
     start=NULL;
  }
  else
  {   struct node_d *ptr=start,*ctr;;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr=ptr->prev;
      ctr=ptr->next;
      ptr->next=NULL;
      ctr->prev=NULL;
      free(ctr);
  }
  return start;
}



//delete before a node..

struct node_d * delete_before_node_d(struct node_d *start,int y)
{ /*
    struct node_d *ptr,*ctr,*dtr;
    if(start==NULL)
    {
        printf("\nSorry there is no element in the linked list");
    }
    else if(start->data==y)
    {
        printf("\nsorry not possible to delete because it the very first node..\n");
    }
    else if(start->next->data==y)
    {
       ctr=start;
       start=start->next;
       start->prev=NULL;
       ctr->next=NULL;
       free(ctr);
    }
    else
    {
        ptr=start;
        while((ptr!=NULL)&&(ptr->data!=y))
        {
            ptr=ptr->next;
        }



       if(ptr==NULL)
       {
         printf("\nSorry not found..\n");
       }
       else
       {
        dtr=ptr->prev;
        ctr=ptr->prev->prev;
        ctr->next=ptr;
        ptr->prev=ctr;
        dtr->next=NULL;
        dtr->prev=NULL;
        free(dtr);
       }

    }
    return start;
    */
    struct node_d *ptr,*ctr,*dtr;

    if(start==NULL)
    {
        printf("\nSorry there is no element in the linked list\n--------------------------------------------------------------------------------\n");
    }
    else if(start->data==y)
    {

        printf("\nIt is not possible to delete because it is only one node in the list.\n-----------------------------------------------------------------\n");
    }
    else
    {
        ptr=start;
        ctr=start;
        while((ptr!=NULL)&&(ptr->data!=y))
        {
          ptr=ptr->next;
        }

       if(ptr==NULL)
       {
           printf("\nSorry not Found...\n----------------------------------------------------------------------------------\n");
       }
       else
       {
        ctr=ptr->prev;
        if(ctr==start)
        {
            start=start->next;
            ctr->next=NULL;
            start->prev=NULL;
            free(ctr);
        }
        else
        {
            dtr=ctr;
            ctr=ctr->prev;
            ctr->next=ptr;
            ptr->prev;
            ctr=ptr;
            dtr->prev=NULL;
            dtr->next=NULL;
            free(dtr);
        }
    }
    }
return start;


}

//deletion after a node..


struct node_d * delete_after_node_d(struct node_d *start,int y)
{
  struct node_d *ptr,*ctr;
    if(start==NULL)
    {
        printf("\nSorry there is no element in the linked list\n--------------------------------------------------------------------------------\n");
    }
    else if(start->data==y)
    {
        if(start->next!=NULL)
        {
            ptr=start;
            start=start->next;
            start->prev=NULL;
            ptr->next=NULL;
            free(ptr);
        }
        else
        {
          printf("\nSorry there is no element after it,So we cannot delete any thing here.\n--------------------------------------------------------------------------------\n");
        }
    }
    else
    {
        ptr=start;
        while((ptr!=NULL)&&(ptr->data!=y))
        {
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\nSorry Element not found..\n-----------------------------------------------------------------------------------\n");
        }
        else
        {
            if(ptr->next==NULL)
            {
                printf("\nSorry there is no element after it...\n---------------------------------------------------------------------------------\n");
            }
            else
            {
                ctr=ptr->next;
                ptr->next=ctr->next;
                ctr->prev=ptr;
                ctr->next=NULL;
                ctr->prev=NULL;
                free(ctr);
            }
        }
    }
    return start;
}



int main()
{
  int x,choice,y,choice2;
  struct node *start=NULL;
  struct node_d *start_d=NULL;

  while(1)
  {

	printf("\n---------------------------------------------------------------------------------\n");
    printf("\nPlease Enter your choice");
	printf("\n1.For Singly LinkedList\n2.For Doubly LinkedList\n3.Exit\n");
	printf("\n---------------------------------------------------------------------------------\n");
	scanf("%d",&choice);
    switch(choice)
	{
       case 1:
          printf("\nWelcome to Singly Linked List\n");
          while(1)
          {

             printf("---------------------------------------------------------------------------------");
              printf("\n1.View\n2.Add node at Beginning\n3.Add node After Given Node\n4.Add node Before a given node\n5.Add node at Last\n6.Sorting\n7.Delete a Node\n8.Delete node from beginning\n9.Delete node before a given node\n10.Delete node After node\n11.Delete node from last\n12.Back\n");
             scanf("%d",&choice2);
             printf("\n---------------------------------------------------------------------------------\n");


                  switch(choice2)
                  {
                      case 1:
                            show(start);
                            break;
                       case 2:
                            printf("\nEnter the data:");
                            scanf("%d",&x);
                            start=add_beg(start,x);
                            break;
                       case 3:
                            printf("\nEnter the data:");
                            scanf("%d",&x);
                            printf("\nEnter the value of after which you wants to add your new node:");
                            scanf("%d",&y);
                            start=add_after_node(start,x,y);
                            break;
                       case 4:
                            printf("\nEnter the data:");
                            scanf("%d",&x);
                            printf("\nEnter the value of before which you wants to add your new node:");
                            scanf("%d",&y);
                            start=add_before_node(start,x,y);
                            break;
                       case 5:
                            printf("\nEnter the data:");
                            scanf("%d",&x);
                            start=add_last(start,x);
                            break;
                       case 6:
                            sorting(start);
                            break;
                       case 8:
                            start=delete_beg(start);
                            break;

                       case 7:
                           printf("\nEnter the node do you want to delete...\n");
                           scanf("%d",&y);
                           start=delete_node(start,y);
                           break;
                       case 9:
                            printf("\nenter the node value before which you wants to delete:");
                            scanf("%d",&y);
                            delete_before_node(start,y);
                            break;
                       case 10:
                            printf("\nenter the node value after which you wants to delete:");
                            scanf("%d",&y);
                            delete_after_node(start,y);
                            break;
                       case 11:
                            start=delete_last(start);
                            break;
                  }
                if(choice2==12)
                {
                    break;
                }
          }
             break;



	   case 2:
         printf("\n\n\n\nWelcome to Doubly Linked List\nPlease Select\n");
         while(1)
         {
             printf("\n1.Add element to Beginning\n2.Add Element to Last\n3.Add node after a node\n4.Add node before Node\n5.Forward View\n6.Backward View\n7.sorting\n8.Delete from Beginning\n9.Delete From last\n10.Delete node before a node\n11.Delete a node after a given node\n12.Back\n\n");
             scanf("%d",&choice2);
             printf("\n---------------------------------------------------------------------------------\n");

                switch(choice2)
                {
                   case 1:
                        printf("\nEnter the value :");
                        scanf("%d",&x);
                        start_d=add_beg_d(start_d,x);
                        break;
                   case 2:
                        printf("\nEnter the value :");
                        scanf("%d",&x);
                        start_d=add_last_d(start_d,x);
                        break;
                   case 3:
                         printf("\nEnter the node value :");
                         scanf("%d",&x);
                         printf("\nEnter the node value after which you want to add new node :");
                         scanf("%d",&y);
                         start_d=add_after_node_d(start_d,x,y);
                         break;

                   case 4:
                         printf("\nEnter the node value :");
                         scanf("%d",&x);
                         printf("\nEnter the node value before which you want to add new node :");
                         scanf("%d",&y);
                         start_d=add_before_node_d(start_d,x,y);
                         break;
                   case 5:
                          show_d_for(start_d);
                          break;
                   case 6:
                         show_d_back(start_d);
                         break;
                   case 7:
                         sorting_d(start_d);
                         break;
                   case 8:
                         start_d=delete_beg_d(start_d);
                         break;
                   case 9:
                         start_d=delete_last_d(start_d);
                         break;
                   case 10:
                        printf("\nPlease enter the value before which you want to delete..\n");
                         scanf("%d",&y);
                         start_d=delete_before_node_d(start_d,y);
                         break;
                   case 11:
                         printf("\nPlease enter the value after which you want to delete..\n");
                         scanf("%d",&y);
                         start_d=delete_after_node_d(start_d,y);
                         break;
                   case 12:
                         break;

                }
               if(choice2==12)
               {
                   break;
               }
         }

			 break;

       case 3:
            break;

	}
	if(choice==3)
    {
        break;
    }
  }

  return 0;
}
