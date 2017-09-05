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
struct node *insert_after(struct node *);   //For inserting a node after a given node
struct node *delete_be(struct node *);      //For deleting the first node of the linked list

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
  printf("The List after the insertion is\n");
  start=display_ll(start);
  printf("Consider inserting a node after a given node\n");
  start=insert_after(start);
  printf("The List after insertion is\n");
  start=display_ll(start);
  printf("Now Deleting the First node i.e the beginning node of the Linked list\n");
  start=delete_be(start);
  printf("The Linked List after deleting the first node is\n");
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

struct node *insert_before(struct node *start)
{
  struct node *new_node,*ptr,*preptr; //preptr holds the address of the node that is before the node pointed by ptr
  int num,val;
  printf("Enter the data\n");
  scanf("%d",&num);
  printf("Enter the value or number before which the node has to be inserted\n");
  scanf("%d",&val);
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=num;
  ptr=start;
  
  while(ptr->data!=val)       //As to insert before the given node
  {
    preptr=ptr;               //assigning the address to preptr before moving ptr to next node
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node,*preptr,*ptr;
    int num,val;
    printf("Enter the data\n");
    scanf("%d",&num);
    printf("Enter the value after which the node is to be inserted\n");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)             /*Note that we traverse preptr to get the address of the node next to the one ptr points*/
    {                                     
        preptr=ptr;
        ptr=ptr->next;
    }

    preptr->next=new_node;
    new_node->next=ptr;
    return start;
}

struct node *delete_be(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    printf("The Data %d stored in first node is now Deleted\n",ptr->data);
    free(ptr);
    return start;
}
