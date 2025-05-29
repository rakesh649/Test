#include "header.h"
void rotate_arr_left() {
    int n,i,temp=0,posn=0;
    printf("Enter num of ele's & no's posn to shift\n");
    scanf("%d %d",&n,&posn);
    int arr[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    
    while(posn > 0) {
        temp=arr[0];
        for(i=0;i<n;i++) {
            arr[i]=arr[i+1];
        }
        arr[i-1]=temp;
        posn--;
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void remove_arr_dup() {
   int n,i,j=0,k=0;
    printf("Enter num of ele's\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i] == arr[j]) {
                k=j;
                for(k;k<n-1;k++)
                    arr[k]=arr[k+1];
                j--;
                n--;
            }
        }
    }
    for(i=0;i<n;i++) 
        printf("%d ",arr[i]);
}

int search(int *arr, int x,int up) {
    int low=0,mid=0,end=up;
    
    while(low <= end) {
        mid=(low+end)/2;
        
        if(x < arr[mid])
            end=mid-1;
        else if(x > arr[mid])
            low=mid+1;
        else 
            return mid;
            
    }
    return -1;
}
void search_ele_bst() {
    int n,i,j=0,k=0;
    printf("Enter num of ele's and ele to be found\n");
    scanf("%d %d",&n,&k);
    int arr[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    j=search(arr,k,n-1);
    if(j == -1 )
        printf("Element not found\n");
    else
        printf("%d is found at index:%d\n",k,j);
}
typedef struct stu {
    int num;
    struct stu *link;
}st;

st *head=NULL;
st *add(int n) {
    st *new=NULL,*temp=NULL;
    new=(st *)calloc(1,sizeof(st));
    new->num=n;
    if(head == NULL)
        head=new;
    else {
        for(temp=head;temp->link != NULL;temp=temp->link);
        temp->link=new;
    }
    return head;
}
void display(st *ptr) {
    while(ptr) {
        printf("num = %d\n",ptr->num);
        ptr=ptr->link;
    }
}
static st *reverse(st *ptr) {
    st *next=NULL,*prev=NULL,*cur=NULL;
    next=cur=ptr;
    while(next) {
        next=next->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
void reverse_rec(st *ptr,st *prev) {
    if(ptr->link)
        reverse_rec(ptr->link,ptr);
    else
        head=ptr;
    ptr->link=prev;
}
void rev_ll() {
    st *prev=NULL;
    int i,n=5;
    for(i=0;i<n;i++)
        head=add(i+1);
    display(head);
    head=reverse(head);
    // reverse_rec(head,prev);
    printf("After reversing\n");
    display(head);
}
#define row 3
#define col 3
void transpose_mat() {
    int i=0,j=0,k=0,arr[row][col],tra[row][col];
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++)
            scanf("%d",&arr[i][j]);
    }
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++)
            tra[i][j]=arr[j][i];
    }
    printf("After transport\n");
    for(i=0;i<row;i++,printf("\n")) {
        for(j=0;j<col;j++)
            printf("%d ",tra[i][j]);
    }
}

void u_strcat() {
    char str[64],str1[32];
    int i=0,j=0;
    printf("Enter two strings\n");
    scanf("%s %s",str,str1);
    while(str[i++] != '\0');
    i--;
    while(str1[j] != '\0') {
        str[i++]=str1[j++];
    }
        
    str[i]='\0';
    printf("Concatinated str = %s\n",str);
}

void nthrow_pascal() {
    int n,i=0,j=0,x=1;
    printf("Enter nth row\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        x=1;
        for(j=1;j<=i;j++) {
            if(i == n) {
                printf("%d ",x);
            }
             x=x*(i-j)/j;
        }
    }
}
#define size 8
void find_repeating_ele() {
    int i,arr[size],j;
    for(i=0;i<size;i++)
        scanf("%d",arr+i);
    for(i=0;i<size;i++) {
        for(j=i+1;j<size;j++) {
            if(arr[i] == arr[j])
                printf("%d ",arr[i]);
        }
    }
}