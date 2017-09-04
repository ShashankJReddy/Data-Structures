//A simple program to create a linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;                     //For storing the data
  struct node *next;            //For storing the address of the next node
};

/* Function prototypes goes here and the functions
    are defined as function to pointers as we return the
    address of the starting node
 */

struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);

int main()
{
  start=create_ll(start);
  printf("The linked list conatins the elements \n");
  start=display_ll(start);
  return 0; //as main function declared as int
}

struct node *create_ll(struct node *start)
{
  struct node *new_node,*ptr;
  int num;
  printf("Enter -1 to quit\n");
  printf("Enter the data\n");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));    //type-casting
    new_node->data=num;

    if(start==NULL)
    {
      new_node->next=NULL;
      start=new_node;
    }
    else
    {
      ptr=start;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->next=NULL;
    }
    printf("\nEnter the data\n");
    scanf("%d",&num);
  }
  return start;
}

struct node *display_ll(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;            //making ptr to point to next node
  }
}