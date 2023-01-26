#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
void insertathead(struct node** head,int d){
   struct node* temp;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=d;
   temp->right=*head;
   (*head)->left=temp;
   *head=temp;
}
void display(struct node**head){
    if(*head==NULL){
        printf("linked list is empty");
    }
    struct node*ptr=*head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->right;
    }
}
void insertatend(struct node**head,int d){
    struct node*ptr=*head;
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->right=NULL;
    temp->left=NULL;

    while(ptr->right!=NULL){
        ptr=ptr->right;

    }
    ptr->right=temp;
    temp->left=ptr;
}
void insertatindex(struct node**head,int index,int d){
 int counter=1;
 if(index==1){
    insertathead(&(*head),d);
 }struct node*temp;
 temp=(struct node* )malloc(sizeof(struct node));
 temp->data=d;
 struct node*ptr=*head;
 struct node*prevptr=*head;
 while(ptr!=NULL && counter<index){
    counter++;
    prevptr=ptr;
    ptr=ptr->right;

 }
 prevptr->right=temp;
 temp->right=ptr;
 temp->left=prevptr;
 ptr->left=temp;
}
void deleteathead(struct node**head){
    struct node*ptr=*head;
    *head=(*head)->right;
    free(ptr);
}
void deleteatindex(struct node**head,int index){
    int counter=1;
    struct node*ptr=*head;
    struct node*prevptr=*head;
    while(ptr!=NULL){
        counter++;
        prevptr=ptr;
        ptr=ptr->right;
    }
    prevptr->right=ptr->right;
    ptr->right->left=prevptr;
    
    
    free(ptr);
}
int search(struct node **head, int d)
{
    if (*head == NULL)
    {
        printf("element not found");
        return 0;
    }
    struct node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == d)
        {
            printf("element found");
            return 1;
        }
        temp = temp->right;
    }
    printf("element not found");
    return 0;
}
int main(){
     struct node *head;
     head=(struct node*)malloc(sizeof(struct node));
     head->data=23;
     head->right=NULL;
     head->left=NULL;
    insertathead(&head,67);
    insertathead(&head,68);
    insertathead(&head,60);
    insertatend(&head,90);
    insertatindex(&head,2,100);
    deleteathead(&head);
    deleteatindex(&head,3);
    display(&head);
    return 0;

}