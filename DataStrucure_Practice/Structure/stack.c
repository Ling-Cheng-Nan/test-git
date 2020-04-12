#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

typedef struct node Node;

typedef struct node{
    Node* pre;
    int data;
} Node;

typedef struct stack{ 
    Node* top;
    int count;
} Stack;

/*function prototype*/
int ask_for_options();
void init_stack(Stack* );
void push(Stack*, int);
Node* pop(Stack* );
void display(Stack* );

int main(){
    int option, value;
    Node extracted_node;
    Stack stack;
    Stack* ptr = &stack;
    
    init_stack(ptr);

    while(1){

        switch (ask_for_options()){
            case 1:
                /* push */
                printf("Enter the value you want to push into the stack : \n");
                scanf("%d", &value);
                push(ptr, value);
                break;
            case 2:
                /* pop */
                pop(ptr);
                break;
            case 3:
                /* show elements in stack */
                printf("The elements extracted from top of Stack are : \n");
                display(ptr);
                break;
            case 4:
                /* exit */
                printf("You are gonna leave this program.\n");
                exit(0);
                break;    
            default:
                printf("Error option, try again.\n");
                break;
        }    
    }



    return 0 ;
}

int ask_for_options(){

    int opt;

    printf("\nStack Operations : \n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    printf("====================\n");
    scanf("%d", &opt);

    return opt;
}

void init_stack(Stack* st){
    st->top = NULL;
    st->count = 0;
}

void push(Stack* st, int val){
    Node n;
    Node* p = &n;
    p->data = val;
    p->pre = NULL;

    /*check the stack is full or not*/
    if(st->count == STACK_SIZE){
        printf("Stack is full.\n");
    }else {
        printf("before insertion, the top node : %p\n",st->top);
        
        /*insert data*/
        if(st->count == 0 && st->top == NULL){
            st->top = p; //first
        }else {
            p->pre = st->top;
            (st->top) = p;
        }

        
        printf("after insertion, the top node : %p\n",st->top);
        
        printf("the data just stored in : %d\n",(p)->data);

        printf("the data just stored in : %d\n",(st->top)->data);
        
        st->count ++;
        printf("Stack count increase.\n");

    }

}


Node* pop(Stack* st){

    /*check the stack is empty or not*/
    if(st->count == 0){
        printf("Stack is empty! Cannot pop out any element.\n");
    }
    else{
        /*extract element on top of the stack*/
        
        st->count --;
        printf("Stack count decrease.\n");
    }
}

void display(Stack* st){
    printf("%d", (st->top)->data);
}

