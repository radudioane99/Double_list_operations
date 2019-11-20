#include <stdio.h>
#include <stdlib.h>
struct nod{
   char nume[30];
   int key;
   struct nod *next;
   struct nod *prev;
};
struct nod *head=NULL;
struct nod *current=NULL;
void printlist()
{
   struct nod *ptr=head;
    int i=1;
    if (head!=NULL)
    {
        printf("The list is : \n");
       while(ptr != NULL)
       {
        printf(" \n The element number :");
        printf("%d",i);
        printf("\n The key value :");
        printf("%d",ptr->key);
        printf("\n The name value :");
        printf("%s",ptr->nume);
        printf("\n \n");
        ptr=ptr->next;
        i++;
       }
    }
    else{printf("The list is empty!!! \n");}

}
void insertfirst()
{
    struct nod *link = (struct nod*)malloc(sizeof(struct nod));

     printf("\n Give the new element key :");
     scanf("%d",&link->key);
     printf("\n Give the new element name :");
     scanf("%s",link->nume);

     link->next=head;
     link->prev=NULL;
     ///Very important!!!!!!!!!!!!
    if(head!=NULL)
    {
     head->prev=link;
    }
     head=link;

}
void insertlast()
{
    struct nod *link = (struct nod*)malloc(sizeof(struct nod));

    printf("\n Give the new element key :");
    scanf("%d",&link->key);
    printf("\n Give the new element name :");
    scanf("%s",link->nume);

    struct nod *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=link;
    link->next=NULL;
    link->prev=current;
}
void deletefirst ()
{
    if(head->next!=NULL)
    {
     struct nod *temp;
     head->next->prev=NULL;
     temp=head;
     head=head->next;
     free(temp);
    }
    else {head=NULL;}
}
void deletelast ()
{
    if(head->next!=NULL)
    {
        struct nod *current;
        current=head;
        while(current->next!=NULL)
        {
        current=current->next;
        }
        current->prev->next=NULL;
        free(current);
    }
    else {head=NULL;}

}
int length()
{
    /// traverse the list and count the elements
    int len=0;
    struct nod *current;
    for(current=head;current!=NULL;current=current->next)
    {
        len++;
    }
    return len;
}
void insertafterkey(int key)
{
    if(length()>=2)
    {
        struct nod* link = (struct nod*)malloc(sizeof(struct nod));

        printf("\n Give the new element key :");
        scanf("%d",&link->key);
        printf("\n Give the new element name :");
        scanf("%s",link->nume);

        struct nod* current= head;
        while(current->key != key)
        {
         current=current->next;
        }

        link->next=current->next;
        link->prev=current;
        current->next->prev=link;
        current->next=link;

    }
    else {printf("\n List too short!!");}


}
void deletekey(int key)
{
    if(head==NULL) {printf("THE LIST IS EMPTY!! \n");return;}
    if(head->next==NULL) {head=NULL;return;}
    struct nod *current=head;
    while (current->key!=key)
    {
        current=current->next;
    }
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(current);

}
int main()
{
    int op = 0;
    printf("\n                   LISTE DUBLU INLANTUITE                \n");
    while (op!=9)
    {
         printf("MENU:  \n\n");
         printf("1.PRINT \n");
         printf("2.INSERT FIRST \n");
         printf("3.INSERT LAST \n");
         printf("4.DELETE THE FIRST ELEMENT \n");
         printf("5.DELETE THE LAST ELEMENT \n");
         printf("6.INSERT AFTER KEY \n");
         printf("7.DELETE THE ELEMENT WITH KEY \n");
         printf("Give operation :");
         scanf("%d",&op);

         switch (op)
         {
             case 1: {printlist();break;}
             case 2: {insertfirst();break;}
             case 3: {insertlast();break;}
             case 4: {deletefirst();break;}
             case 5: {deletelast();break;}
             case 6: {
                       int key;
                       printf("\n Give the key of the element after you want to insert :");
                       scanf ("%d",&key);
                       insertafterkey(key);
                       break;
                      }
             case 7:  {
                        int key;
                        printf("\n Give the key of the element you want to delete :");
                        scanf ("%d",&key);
                        deletekey(key);
                        break;
                      }
             case 9: {return 0;}
         }
      printf("\n\n");
    }
    return 0;
}
