#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
int n;

struct node *createNode(int d)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->right = NULL;
    ptr->left = NULL;
}
void displayIn(struct node **head)
{
    n = 0;
    if (*head == NULL)
    {
        return;
    }

    displayIn(&((*head)->left));
    printf("%d -> ", (*head)->data);
    n++;
    displayIn(&((*head)->right));
}
int search(struct node **head, int d)
{
    if ((*head) == NULL)
    {
        return 0;
    }
    if ((*head)->data == d)
    {
        return 1;
    }
    else if ((*head)->data > d)
    {
        return search(&((*head)->left), d);
    }
    else
    {
        return search(&((*head)->right), d);
    }
    return 0;
}
struct node *search2(struct node **head, int d)
{
    if ((*head) == NULL)
    {
        return NULL;
    }
    if ((*head)->data == d)
    {
        return (*head);
    }
    else if ((*head)->data < d)
    {
        return search2(&((*head)->right), d);
    }
    else
    {
        return search2(&((*head)->left), d);
    }
}
void findmix(struct node **head)
{
    if (*head == NULL)
    {
        printf("empty tree");
    }
    struct node *ptr = *head;
    struct node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->left;
    }
    printf("%d", prev->data);
}
void findmax(struct node **head)
{
    if (*head == NULL)
    {
        printf("empty tree");
    }
    struct node *ptr = *head;
    struct node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->right;
    }
    printf("%d", prev->data);
}
int findkthmin2(struct node **head, int key, int i)
{
    if (*head == NULL)
    {
        return -1;
    }
    int left = findkthmin2((*head)->left, key, i);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == key)
    {
        return (*head)->data;
    }
    return findkthmin2((*head)->right, key, i);
}
/*void findkthmin(struct node **head, int k)
{
    int counter = 0;
    struct node *ptr = *head;
    struct node *prev = NULL;
    while (ptr != NULL && counter <= k)
    {
        prev = ptr;
        ptr = ptr->left;
        counter++;
    }
    printf("%d", ptr->data);
}
*/
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
    displayIn(&head);
    printf("\n");
    printf("%d", search(&head, 5));
    printf("\n");
    struct node *temp = search2(&head, 5);
    if (temp == NULL)
    {
        printf("element not found");
    }
    else
    {
        printf("element found : %d", temp->data);
    }
    printf("\n");
    findmix(&head);
    findmax(&head);
    printf("\n");
    printf("%d", findkthmin2(&head, 2, 0));

    return 0;
}