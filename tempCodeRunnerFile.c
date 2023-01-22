// #include<stdio.h>
// #include<stdlib.h>
// struct stack{
//     int size;
//     int *arr;
//     int top;

// };
// void push(int d,struct stack){
//     if(top==s.size-1){
//     printf("overflow");
//     return;}
//     else{
//         top++;
//         s.arr[top]=d;
//         return;
//     }
// }
// void pop(struct stack *s){
//     if(top==-1){
//         printf("underflow");
//         return;
//     }else{
//         printf("the element to be poped is %d",s->top);
//         top--;
//     }
// }
// void display(struct stack *s){
//  if(top==-1){
//     printf("stack empty");
//     return ;
//  }
//  else{
//     while()
//  }
// }
// int main(){
//     struct stack s;
//     s.size=10;
//     s.top=-1;
//     s.arr=(int*)malloc(s.size*sizeof(int));    
   
//     return 0;

// }
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
void push(int data,struct stack**sp){
    if((*sp)->top==(*sp)->size-1){
        printf("stackoverflow");
        return ;
    }
    (*sp)->top++;
    (*sp)->arr[(*sp)->top]=data;

}
void pop(struct stack**sp){
    if((*sp)->top==-1){
        return ;
    }printf("%d is popped",(*sp)->arr[(*sp)->top]);
    (*sp)->top--;
}
int isEmpty(struct stack*ptr){
    if(ptr->top==-1){
        return 1;
    }return 0;
}int isFull(struct stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }return 0;
}
void display(struct stack **sp){
    for(int i=0;i<=(*sp)->top;i++){
        printf(" %d -",(*sp)->arr[i]); 
    }
}
int main(){
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sizeof(struct stack)*sp->size);
    push(23,&sp);

    printf("%d",sp->arr[0]);
    printf("\n");
    printf("%d",isEmpty(sp));
    printf("\n");
    printf("%d",isFull(sp));
    printf("\n");
    
    pop(&sp);
    push(45,&sp);
    push(34,&sp);
    printf("\n");
    display(&sp);
     push(4,&sp);
     push(47,&sp);
     push(40,&sp);
     push(34,&sp);
     printf("\n");
     display(&sp);
     printf("\n");
     push(6,&sp);
     push(87,&sp);
     push(90,&sp);
     push(94,&sp);
      printf("\n");
      push(56,&sp);
       printf("\n");
     display(&sp);
    return 0;
}