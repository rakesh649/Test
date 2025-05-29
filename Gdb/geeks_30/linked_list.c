#include "header.h"
typedef struct dat {
    int num;
    struct dat *link;
}node;

static node *add(node *ptr) {
    node *new=NULL,*temp=NULL;
    new=(node *)calloc(1,sizeof(node));
    printf("Enter val\n");
    scanf("%d",&new->num);
    if(ptr == NULL)
        ptr=new;
    else {
        for(temp=ptr;temp->link != NULL;temp = temp->link);
        temp->link=new;
    }
    return ptr;
}

static void display(node *ptr) {
    while(ptr) {
        printf("val = %d\n",ptr->num);
        ptr=ptr->link;
    }
}
node *do_modify(node *prev,node *temp,node *next,node *ptr) {
    node *itr=NULL;
        if(temp == prev) {
        ptr=ptr->link;
    }
    else
        prev->link=next;
    
    for(itr=ptr;itr->link != NULL;itr=itr->link);
    itr->link=temp;
    itr->link->link=NULL;
    
    return ptr;
}
node *mv_key_end(node *ptr,int key) {
    node *temp=ptr,*prev=NULL,*next=NULL;
    int cnt=0,occu=0,posn=0;
    for(temp;temp != NULL;temp = temp->link) {
        cnt++;
        if(temp->num == key)
            occu++;
    }
    printf("Total nodes = %d occu = %d\n",cnt,occu);
    temp=ptr;
    prev=temp;
    next=temp->link;
    while(next) {
        posn++;
        if((temp->num == key) && (posn <= (cnt-occu))) {
            ptr=do_modify(prev,temp,next,ptr);
            // posn=0;
            temp=ptr;
            next=temp->link;
        }
        prev=temp;
        temp=next;
        next=next->link;
    }
    return ptr;
}

void mv_key_end_ll() {
    int i,n;
    node *head=NULL;
    printf("Enter num of nodes you want to add\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head=add(head);
    display(head);
    printf("Enter key val to move at end\n");
    scanf("%d",&n);
    head=mv_key_end(head,n);
    display(head);
}

node *top=NULL;
#define STACK_LIMIT 5
void push(int n) {
    static int cnt=0;
    if(cnt == STACK_LIMIT) {
         printf("STACK OVERFLOW\n");
         return;
    }
    node *new=calloc(1,sizeof(node));
    new->num=n;
    cnt++;
    if(top == NULL)
        top=new;
    else {
        new->link=top;
        top=new;
    }
}
void pop() {
    node *temp=NULL;
    if(top == NULL) {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    temp=top;
    top=top->link;
    free(temp);
}
int peek() {
    
    if(top == NULL) {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    return top->num;
}
void stack() {
    int i,data=0;
    for(i=0;i<=STACK_LIMIT;i++) {
        printf("Enter node to be pushed\n");
        scanf("%d",&data);
        push(data);
    }
    pop(); 
    data=peek();
    printf("Current top of the stack = %d\n",data);
}
void reverse_linkedlist_ustack() {
    int i,n;
    node *head=NULL,*temp=NULL;
    printf("Enter num of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        head=add(head);
    // printf("display the nodes\n");
    // display(head);
    temp=head;
    while(temp) {
        push(temp->num);
        temp=temp->link;
    }
    temp=head;
    while(temp) {
        temp->num=top->num;
        // printf("Data popped = %d\n",top->num);
        pop();
        temp=temp->link;
    }
    printf("Data after reversing stack\n");
    display(head);
    
}
node *insert(node *ptr) {
    node *new=NULL;
    new=(node *)calloc(1,sizeof(node));
    printf("Enter num\n");
    scanf("%d",&new->num);
    return new;
}
node *remove_loop(node *sptr,node *head,node *fptr) {
    node *loop_ptr=NULL,*ptr=head;
    sptr=head;
    if(sptr == fptr) {
        while(sptr != fptr->link)
            fptr=fptr->link;
    }
    else {
        while(sptr->link != fptr->link) {
            sptr=sptr->link;
            fptr=fptr->link;
        }
    }
    fptr->link=NULL;
    return ptr;
}
node *find_loop(node *ptr) {
    node *sptr,*fptr;
    sptr=fptr=ptr;
    sptr=sptr->link;
    fptr=fptr->link->link;
    
    while(fptr && fptr->link) {
        if(sptr == fptr)
            break;
        sptr=sptr->link;
        fptr=fptr->link->link;
    }
    printf("\nfptr = %p val = %d and sptr = %p val = %d\n",fptr,fptr->num,sptr,sptr->num);
    if(fptr != NULL) {
      printf("loop found\n");
      ptr=remove_loop(sptr,ptr,fptr);
    }
    else
        printf("loop not found\n");
    return ptr;
}
void find_loop_ll() {
    node *loop=NULL;
    loop=insert(loop);
    loop->link=insert(loop);
    loop->link->link=insert(loop);
    loop->link->link->link=insert(loop);
    loop->link->link->link->link=insert(loop);
    loop->link->link->link->link->link=insert(loop);
    loop->link->link->link->link->link->link=loop->link->link;
    // printf("%d & %d\n",loop->link->link->link->link->link->link->num,loop->link->link->num);
    // loop->link->link->link=loop;
    loop=find_loop(loop);
    display(loop);
}
