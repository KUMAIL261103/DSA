#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*left;
struct node* right;
};

void displayPre(struct node**head){
    if(*head==NULL){
        return;

    }
    printf("%d -> ",(*head)->data);
    displayPre(&((*head)->left));
    displayPre(&((*head)->right));
}
void displayPost(struct node**head){
    if(*head==NULL){
        return;

    }
    
    displayPost(&((*head)->left));
    displayPost(&((*head)->right));
     printf("%d -> ",(*head)->data);
}
void displayIn(struct node**head){
    if(*head==NULL){
        return;

    }
    
    displayIn(&((*head)->left));
    printf("%d -> ",(*head)->data);
    displayIn(&((*head)->right));
  
}
int main(){
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=23;
    head->right=NULL;
    head->left=NULL;
    struct node*second;
    second=(struct node*)malloc(sizeof(struct node));
    head->right=second;
    second->data=11;
    second->right=NULL;
    second->left=NULL;
    struct node*third;
    third=(struct node*)malloc(sizeof(struct node));
    third->data=55;
    head->left=third;
    third->right=NULL;
    third->left=NULL;
    struct node*fourth;
    fourth=(struct node*)malloc(sizeof(struct node));
    fourth->data=66;
    second->right=fourth;
    fourth->right=NULL;
    fourth->left=NULL;
    //preorder traversal root --left --right
    displayPre(&head);
    printf("\n");
    //postorder traversal left --right--root
    displayPost(&head);
    printf("\n");
    //inorder traversal left--root--right
    displayIn(&head);
    return 0;
}