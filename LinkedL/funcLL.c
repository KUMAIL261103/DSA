#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node **head)
{
    if (*head == NULL)
    {
        printf("linked list is empty");
        return;
    }
    struct node *ptr = *head;
    while (ptr)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
} /*
 void insertatend(struct node *head, int d)
 {
     struct node *temp;
     struct node *ptr = head;
     temp = (struct node *)malloc(sizeof(struct node));
     temp->data = d;
     temp->next = NULL;
     if (ptr == NULL)
     {
         ptr->next = temp;
     }
     while (ptr->next != NULL)
     {
         ptr = ptr->next;
     }
     ptr->next = temp;
 }*/
void insertatfront(struct node **head, int d)
{
    // struct node *temp;
    // temp = (struct node *)malloc(sizeof(struct node));
    // temp->data = d;

    // temp->next = head;
    // temp = head;
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = d;
    current->next = *head;
    *head = current;
}

void insertatmiddle(struct node **head, int d)
{
    struct node *temp;
    struct node *ptr;
    ptr = *head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->next = NULL;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    int c;
    if (count % 2 == 0)
    {
        c = count / 2;
    }
    else
    {
        c = (count + 1) / 2;
    }
    while (!c)
    {
        ptr = ptr->next;
        c--;
    }
    struct node *store;
    store = malloc(sizeof(struct node));
    store = ptr->next;
    ptr->next = temp;
    temp->next = store;
}
void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *ptr = *head;
    struct node *next = NULL;
    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
}
int main()
{

    struct node *head = NULL;
    insertatfront(&head, 1);
    insertatfront(&head, 2);
    display(&head);
    // struct node *reversel = reverse(&head);
    printf("\n");
    reverse(&head);
    display(&head);
    return 0;
}