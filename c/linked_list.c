#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node* next;
};

typedef struct node nd;
nd *head = NULL;
nd* create (nd* head)  {

   nd * cur = (nd *)malloc(sizeof(nd));
   // printf("enter the data value ");
   // scanf("%d",&cur->data );
   cur->data = rand()%20000;
   cur->next = NULL;
   if(head == NULL)
      head = cur;
   else  {
      nd *temp = head;
      while (temp->next != NULL)
         temp = temp->next;

      temp->next = cur;
   }
   return head;
}

void print(nd *head) {
   if(head == NULL)
      return ;
   nd *temp = head;
   printf("elements are ");
   while (temp != NULL) {
      printf("%d  ",temp->data );
      temp=temp->next;
   }
}

nd* del(nd* head) {
   nd* temp = head;
   if(head == NULL)
      printf("there are no elements for delete an elements \n" );

   else if(head->next == NULL)
      head = NULL;

   else {
      int item;
      printf("enter the elements which you what to delete ");
      scanf("%d",&item);
      if(head->data == item)
         head = head->next;

      else {
         while(temp->next->data != item && temp->next != NULL)
            temp = temp->next;

         nd* p = temp->next;
         temp->next = temp->next->next;
         temp = p;
      }
   }

   free(temp);
   return head;
}

nd* insert(nd *head) {
   nd* newnode=(nd*)malloc(sizeof(nd));
   nd* temp = head;
   int item = 0;
   printf("enter the element before that you want to enter the new element " );
   scanf("%d",&item );
   if(item < 0 )
   {
      head = create(head);
      return head;
   }
   printf("enter the data value \n" );
   scanf("%d",&newnode->data );
   
   if(head->data == item)   {
      newnode->next = head;
      head = newnode;
   }
   else  {
      while(temp->next->data != item)
         temp = temp->next;

      newnode->next = temp->next;
      temp->next = newnode;
   }
   return head;
}

nd* reverse(nd* head)
{
   if(head == NULL || head->next == NULL)
         return head;
   nd* pev = NULL;
   nd* next = NULL;
   nd* cur = head;
   while(cur != NULL)  {
      next = cur->next;
      cur->next = pev;
      pev = cur;
      cur = next;
   }
   return pev;
}

void reverse_recursion(nd* pev,nd* cur)
{
   if(cur) {
      reverse_recursion(cur,cur->next);
      cur->next = pev;
   }
   else
      head = pev;
}

int main()  {
   int ch = 10;
   while(ch > 1)
   {
      ch--;
      head = create(head);
   }
   printf("1 for create \n" );
   printf("2 for view \n" );
   printf("3 for delete \n" );
   printf("4 for insert \n" );
   printf("5 for reverse \n" );
   printf("6 for reverse using recurison \n" );
   printf("0 for exit \n" );
   printf("enter your choice " );

   scanf("%d",&ch );
   while(ch != 0)
   {
      switch (ch) {
         case 1 : head = create(head);
                  break;
         case 2 : print(head);
                  printf("\n");
                  break;
         case 3 : head = del(head);
                  break;
         case 4 : head = insert(head);
                  break;
         case 5 : head = reverse(head);
                  break;
         case 6 : reverse_recursion(NULL,head);
                  break;
      }
      printf("enter your choice " );
      scanf("%d",&ch );
   }
   return 0;
}
