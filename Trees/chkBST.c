#include <stdio.h>
#include <stdlib.h>
int arr[100];
int i = 0;
struct node
{
    int data;
    struct node *right;
    struct node *left;

}; 
int chkBST(struct node **head)
{
    static struct node *prev = NULL;
    if (*head != NULL)
    {
        if (!chkBST(&(*head)->left))
        {
            return 0;
        }
        if (prev != NULL && (*head)->data <= prev->data)
        {
            return 0;
        }
        prev = (*head);
        return chkBST(&(*head)->right);
    }
    else
    {
        return 1;
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
int main()
{
    /*struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->right = NULL;
    head->left = NULL;
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    head->right = second;
    second->data = 6;
    second->right = NULL;
    second->left = NULL;
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));
    third->data = 3;
    head->left = third;
    third->right = NULL;
    third->left = NULL;
    struct node *fourth;
    fourth = (struct node *)malloc(sizeof(struct node));
    fourth->data = 4;
    third->right = fourth;
    fourth->right = NULL;
    fourth->left = NULL;
    struct node *fifth;
    fifth = (struct node *)malloc(sizeof(struct node));
    fifth->data = 1;
    third->left = fifth;
    fifth->right = NULL;
    fifth->left = NULL;*/

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->right = NULL;
    head->left = NULL;
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    head->right = second;
    second->data = 8;
    second->right = NULL;
    second->left = NULL;
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));
    third->data = 3;
    head->left = third;
    third->right = NULL;
    third->left = NULL;
    struct node *fourth;
    fourth = (struct node *)malloc(sizeof(struct node));
    fourth->data = 6;
    third->right = fourth;
    fourth->right = NULL;
    fourth->left = NULL;
    struct node *fifth;
    fifth = (struct node *)malloc(sizeof(struct node));
    fifth->data = 2;
    third->left = fifth;
    fifth->right = NULL;
    fifth->left = NULL;
    printf("%d", chkBST(&head));
    printf("\n");
    displayIn(&head);

    return 0;
}