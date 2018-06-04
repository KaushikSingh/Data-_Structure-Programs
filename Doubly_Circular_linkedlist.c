#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* rlink;
        struct node* llink;
};
typedef struct node* nodeptr;
void insert(int item, nodeptr *first)
{
    nodeptr temp;                                                                                //our basic new_node
    nodeptr last;                                                                                   //keeps track of the last node inserted
    temp=(nodeptr)malloc(sizeof(struct node));                            //appoint memory to temporary variable
    last=*first;                                                                                       //appoint data of last as first pointer's data
    temp->data=item;                                                                         //allocate data to be inserted as new node's data
    temp->rlink=NULL;               //this is insertion at the end, so in any case the last pointer's right link should point to NULL
    if(first==NULL)                                                                                //if theres no node present in the list
    {
        temp->llink=NULL;                                                                      //make temp's previous link variable as NULL
        *first=temp;                                                                                 //make temp the new beginning head
        return;
    }
    if(*first)
    {
        temp->rlink=*first;                                       //insertion at the beginning. if 23,43,54 are inserted, the list holds 54,43,23
        (last->llink)=temp;
    }
    *first=temp;
    return;

}
void delete(nodeptr* head, int key)
{
        nodeptr node=*head;
        for(;node;node=node->rlink)
        {
                if(node->data==key)
                {
                        if(node->llink)
                                node->llink->rlink=node->rlink;                               //point both links to the next right link
                        else
                                *head=node->rlink;                                                   //new head points to node
                        if(node->rlink)
                                node->rlink->llink=node->llink;
                        free(node);
                }
        }                                           //all possible node links have been searched. Now if data wasnt found, data doesnt exist
        printf("Given node data wasnt found in the list \n");
}
void display(nodeptr node) //forward display of the list
{
        for(;node;node=node->rlink)                                           //traverse all of the list in r->direction till node is not null.
        {
                printf("%d\t",node->data);
        }
        printf("\n");
}
void displayr(nodeptr first)                                                     //reverse display of the list
{
    if(first==NULL)
        return;
    else                                                                                         //use recursion to cleverly print reverse of a list.
    {
        displayr(first->rlink);                      //recursive call to function.Function calls itself to next node, which calls next node.                                                                  
        printf("%d\t",first->data);             //most recent data call ,i.e, last node's data is called. Then all previous 
//executions are carried out
     }
}
int main()
{
        nodeptr head,pos;
        int choice,key,num;
        head=(nodeptr)malloc(sizeof(struct node));
        head->rlink=NULL;
        head->llink=NULL;
        while(1)
        {
                printf("\nMENU : ");
                printf("\n1. Insert \n2. Delete \n3. Display in the forward direction \n4. Display in Reverse direction\n");
                printf("Your Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter data to be inserted : ");
                                scanf("%d",&num);
                                insert(num,&head);
                                break;
                        case 2:
                                printf("Enter item to be deleted : ");
                                scanf("%d",&key);
                                delete(&head, key);
                                break;
                        case 3: printf("Displaying list in the forward direction: \n");
                                displayr(head);
                                break;
                        case 4: printf("Displaying list in the reverse direction : \n");
                                display(head);
                                printf("\n");
                                break;
                        default : printf("Invalid data choice \n");
                                break;
                } } }
