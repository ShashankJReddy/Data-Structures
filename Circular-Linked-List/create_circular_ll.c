#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;                    
struct node *create_ll(struct node *);              //to create Cirular Linked Lst
struct node *display_ll(struct node *);             //to display the created Circular Linked list
struct node *rotate_ll(struct node *,int n);        //to perform a rotation of a list

int main()
{
    printf("Creating a circular Linked list\n");

    /* Create Cricular Linked list */
    start=create_ll(start);

    printf("The Circular Linked List created is\n");

    /*Displaying the Cricular Linked List */
    start=display_ll(start);

    /* For rotating the List */
    printf("Now Consider rotating the list \n");
    printf("Enter the number of rotations\n");
    scanf("%d",&n);
    start=rotate_ll(start,n);

    /* Display the List after performing Rotation */
    printf("The Linked List after rotating is\n");
    start=display_ll(start);
    
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *ptr,*new_node;
    int num;
    printf("Enter -1 to Quit\n");
    printf("Enter the number\n");
    scanf("%d",&num);

    while(num!=-1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;

        if(start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        
        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=start;               //Making the new_node point to the beginning.
        }
        printf("Enter the number\n");
        scanf("%d",&num);
    }
    return start;
}

struct node *display_ll(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    return start;
}

struct node *rotate_ll(struct node *start,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        start=start->next;
    }
    return start;
}
