#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node d;
    b.next=&d;
    d.value = 11; //or b->next->value = 11; or (*%d).value or a.next->next->next->value=11 or head->next->next->value=11
    d.next=NULL;
    printf("ex.1 11 at the end\n");
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value); //ex1
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    struct node e;
    e.value=2;
    e.next=&a;
    head=&e;
    printf("ex.2 2 at the begin\n");
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value); //ex1
    printf("%d\n", head ->next->next->next->value);//ex2

    /*  Exercise 2.5
        1. Insert 7 in middle
*/
    struct node f;
    f.value=7;
    f.next=&b;
    a.next=&f;
    printf("ex.2.5 7 at the middle\n");
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value); //ex1
    printf("%d\n", head ->next->next->next->value);//ex2
    printf("%d\n", head ->next->next->next->next->value);//ex2.5

    typedef struct node Node;
    typedef Node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
    */
    printf("ex.3 using loop\n");
    int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }
    printf("\n");
    
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
    */
    printf("ex.4 using while loop\n");
    tmp=head;
    while(tmp){//tmp!=NULL
            printf("%3d", tmp->value);
            tmp=tmp->next;
        }
    printf("\n");
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    printf("ex.5 create node by malloc\n");
    NodePtr temp;
    head = (NodePtr) malloc(sizeof(struct node));
    temp = head;
    n=5;
    for (i = 0; i < n; i++){
        temp->value = 7+i*2;
        temp ->next = (NodePtr) malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->value = 7+i*2;
    temp->next = NULL; // Set last node's next to NULL
    temp = head;
    while(temp){ // tmp=NULL
        printf("%5d", temp->value);
        temp = temp->next;
    }
    printf("\n");



    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    tmp=head;
    while(tmp){
        head=head->next;
        printf("Freezing %d\n",tmp->value);
        free(tmp);
        tmp=head;
    }
    return 0;
}