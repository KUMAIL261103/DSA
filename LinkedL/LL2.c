#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return;
}
void insertatend(struct node *head, int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    // if(head==NULL){
    //     head->next=temp;
    // }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct node *insertatfront(struct node *head, int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = d;
    // temp->next=NULL;
    // if(head==NULL){
    //     head->next=temp;
    //     head=temp;
    // }
    temp->next = ptr;
    return temp;
}
void deleteatfront(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}
void deleteatindex(struct node *head, int d)
{
    if (d == 1)
    {
        deleteatfront(head);
    }
    else
    {
        struct node *ptr = head;
        struct node *store;
        while (ptr != NULL && d != 0)
        {
            d--;
            store = ptr;
            ptr = ptr->next;
        }
        store->next = ptr->next;
        free(ptr);
    }
}
int search(struct node *head, int d)
{
    if (head == NULL)
    {
        printf("element not found");
        return 0;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == d)
        {
            printf("element found");
            return 1;
        }
        temp = temp->next;
    }
    printf("element not found");
    return 0;
}

int main()
{
    struct node *head;

    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    display(head);
    insertatend(head, 55);
    printf("\n");
    insertatend(head, 98);
    insertatend(head, 78);
    insertatend(head, 67);
    insertatend(head, 100);
    //  deleteatfront(head);
    head = insertatfront(head, 65);
    display(head);
    printf("\n");
    // printf("\n%d", search(head, 66));
    return 0;
}