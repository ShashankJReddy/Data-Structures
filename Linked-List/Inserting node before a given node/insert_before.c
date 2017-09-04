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
struct node *create_ll(struct node *);      //For creating a linked list
struct node *display_ll(struct node *);     //For displaying a linked list
struct node *insert_beg_ll(struct node *);  //For inserting an element at beginning og list
struct node *insert_end_ll(struct node *);  //For inserting an element at end of linked list    
struct node *insert_before(struct node *);  //For inserting a node before a given node

int main()
{
  start=create_ll(start);
  printf("The linked list conatins the elements \n");
  start=display_ll(start);
  printf("Consider to insert an element at the beginning of the linked list\n");
  start=insert_beg_ll(start);
  printf("The List after insertion at beginning is\n");
  start=display_ll(start);
  printf("Now consider to insert an element at end of the Linked-List\n");
  start=insert_end_ll(start);
  printf("The linked list after insertion at end is\n");
  start=display_ll(start);
  printf("Lets try inserting a node before a given node\n");
  start=insert_before(start);
  printf("The List after the insertion id\n");
  start=display_ll(start);
  return 0; //because main function declared as int
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
    new_node=(struct node *)malloc(sizeof(struct node));    //creating a node and type casting 
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
        ptr=ptr->next;          //making pointer ptr to point to last node
      }
      ptr->next=new_node;       //Inserting the node
      new_node->next=NULL;
    }
    printf("\nEnter the data\n");
    scanf("%d",&num);
  }
  return start;                 //returning starting node address of the linked list
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
  return start;                 //Note here we return starting address for furthur opeartions
}

struct node *insert_beg_ll(struct node *start)
{
    struct node *new_node;
    int num;
    printf("Enter the data\n");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;       //Connecting new_node to start
    start=new_node;             //Connecting start to new_node
    return start;
}

struct node *insert_end_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data\n");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;          //Making ptr point to last node
    }
    ptr->next=new_node;         //Linking the last node to newly created node
    new_node->next=NULL;
    return start;               //returning the address of the starting node
}