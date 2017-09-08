#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_d_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);

int main()
{
    printf("First Consider creating a Doubly-Linked-List\n");
    start=create_d_ll(start);
    printf("The elements of the Doubly linked list are\n");
    start=display(start);
    printf("Consider inserting a node at beginning\n");
    start=insert_beg(start);
    printf("The Doubly-Linked-List now is\n");
    start=display(start);
}

struct node *create_d_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter -1 to End \n");
    printf("Enter the data\n");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
            new_node=(struct node *)malloc(sizeof(struct node *));
            new_node->prev=NULL;
            new_node->data=num;
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            new_node=(struct node *)malloc(sizeof(struct node));
            new_node->data=num;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("Enter the data\n");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return start;

}

struct node *insert_beg(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data\n");
    scanf("%d",&num);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    start->prev=new_node;
    new_node->next=start;
    new_node->prev=NULL;
    start=new_node;
    return start;
}
