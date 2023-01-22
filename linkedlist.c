#include <stdio.h>
#include <stdlib.h>
/*struct node{
   int data;
   struct node *next;

};
int main(){
  struct node *head ;
  head= (struct node *)malloc(sizeof(struct node));
  head->data = 45;
  head->next=NULL;
  printf("%d",head->data);
  return 0;
}*/
struct node
{
    int data;
    struct node *next;
};
/*void addNode(struct node *head, int d)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = d;
    head->next = temp;
}
void print(struct node *head)
{
    struct node *temp = head;

    while (temp->next != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}*/
void count_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d", count);
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;
    // addNode(head, 11);
    //  addNode(&head,22);
    // print(head);
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 54;
    current->next = NULL;
    head->next = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 22;
    current->next = NULL;
    head->next->next = current;
    // printf("%d\n", head->data);
    // printf("%d\n", head->next->data);
    // printf("%d\n", head->next->next->data);
    // count_nodes(head);
    display(head);
    return 0;
}