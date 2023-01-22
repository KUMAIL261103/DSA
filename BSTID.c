#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int d)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}
void insertNode(struct node **head, int d)
{
    struct node *temp = createNode(d);
    if (*head == NULL)
    {
        (*head)->right = temp;
        *head = temp;
        return;
    }
    struct node *ptr = *head;
    struct node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        if (d == ptr->data)
        {
            return;
        }
        else if (d < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (prev->data > d)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
}
void displayIn(struct node **head)
{
    if (*head == NULL)
    {
        return;
    }

    displayIn(&((*head)->left));
    printf("%d -> ", (*head)->data);
    displayIn(&((*head)->right));
}
void deleteNode(struct node **head, int d)
{
}
int main()
{
    struct node *head = createNode(7);
    struct node *sec = createNode(8);
    struct node *third = createNode(4);
    struct node *fourth = createNode(5);
    struct node *fifth = createNode(2);
    head->right = sec;
    head->left = third;
    third->right = fourth;
    third->left = fifth;
    insertNode(&head, 3);
    insertNode(&head, 33);
    insertNode(&head, 12);
    displayIn(&head);
    return 0;
}
