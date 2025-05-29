#include "header.h"
struct dll {
    int num;
    char name[64];
    struct dll *prev;
    struct dll *next;
};

void dll_display(struct dll *ptr) {
    while(ptr) {
        printf("num = %d name = %s\n",ptr->num,ptr->name);
        ptr=ptr->next;
    }
}

struct dll *add_dll_last(struct dll *ptr) {
    struct dll *newnode=NULL,*temp=NULL;
    newnode=(struct dll *)calloc(1,sizeof(struct dll));
    if(newnode == NULL) {
        fprintf(stderr,"Memory allcoation failed\n");
        return -1;
    }
    printf("Enter number & name\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL) 
        ptr=newnode;
    else {
        for(temp=ptr;temp->next != NULL;temp=temp->next);
            temp->next=newnode;
            newnode->prev=temp;
           // ptr=newnode;
    }
    return ptr;
}

struct dll *add_dll_beg(struct dll *ptr) {
    struct dll *newnode=NULL,*temp=NULL;
    newnode=(struct dll *)calloc(1,sizeof(struct dll));
    if(newnode == NULL) {
        fprintf(stderr,"Memory allcoation failed\n");
        return -1;
    }
    printf("Enter number & name to add at beg\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL)
        ptr=newnode;
    else {
        newnode->next=ptr;
        ptr->prev=newnode;
        ptr=newnode;
    }
    return ptr;
}

struct dll *add_dll_posn(struct dll *ptr, int posn) {
    struct dll *newnode=NULL,*temp=NULL,*prev=NULL;
    int cnt=0;
    newnode=(struct dll *)calloc(1,sizeof(struct dll));
    if(newnode == NULL)  {
        fprintf(stderr,"Memory allcoation failed\n");
        return NULL;
    }
    printf("Enter number & name\n");
    scanf("%d %s",&newnode->num,newnode->name);
    if(ptr == NULL) 
        ptr=newnode;
    else if(posn == 0) {
        newnode->next=ptr;
        ptr->prev=newnode;
        ptr=newnode;
    }
    else {
        for(temp=ptr;( (cnt<posn) && temp);cnt++,temp=temp->next) {
            prev=temp;
        }
        prev->next->prev=newnode;
        newnode->next=prev->next;
        prev->next=newnode;
        newnode->prev=prev;
    }
    return ptr;
}

struct dll *delete_dll_beg(struct dll *ptr) {
    struct dll *temp=NULL;
    temp=ptr;
    ptr=ptr->next;
    ptr->prev=NULL;
    free(temp);
    return ptr;
}

struct dll *delete_dll_last(struct dll *ptr) {
    struct dll *prev=NULL,*temp=NULL;
        for(temp=ptr;temp->next != NULL;temp=temp->next)
            prev=temp;
        prev->next=NULL;
        free(temp);
    return ptr;
}

struct dll *delete_dll_posn(struct dll *ptr,int posn) {
    struct dll *temp=NULL,*prev=NULL;
    int cnt=0;
    for(temp=ptr;( (cnt<posn) && temp);cnt++,temp=temp->next) {
        prev=temp;
    }
    if(posn == 0) {
        ptr=delete_dll_beg(ptr);
        return ptr;
    }
    prev->next->next->prev=prev;
    prev->next=prev->next->next;
    free(temp);
    return ptr;
}

void dll() {
    int i,n,posn=0;
    struct dll *head=NULL;
    printf("Enter number of nodes to be added\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        head=add_dll_last(head);
    }
    dll_display(head);
    //head=add_dll_beg(head);
    //dll_display(head);
    //printf("Enter posn to add\n");
    //scanf("%d",&posn);
    //head=add_dll_posn(head,posn);
    //dll_display(head);
    //head=delete_dll_beg(head);
    //printf("Nodes after fst deletion\n");
    //dll_display(head);
    head=delete_dll_last(head);
    printf("Nodes after last deletion\n");
    dll_display(head);
    printf("Enter posn to del\n");
    scanf("%d",&posn);
    head=delete_dll_posn(head,posn);
    dll_display(head);
}