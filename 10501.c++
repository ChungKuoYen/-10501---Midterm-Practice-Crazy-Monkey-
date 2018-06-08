#include <stdio.h>
#include <stdlib.h>

typedef struct monkey {
    char a;
    struct monkey* next;
    struct monkey* prev;
} monkey;

monkey *head, *curr, *tail, *tmp=NULL, *tmp2=NULL;

int main(void)
{
    int n,m;

    char current;
  //  freopen("test.txt","r",stdin);

    head = (monkey*)malloc(sizeof(monkey));
    curr = head;
    tail = head;

    curr->next=NULL;
    curr->prev=NULL;

scanf("%c",&current);

    while(m!=EOF){

        if(current=='@')
        {

           curr = head;

        }
        else if(current=='#')
        {

          curr = tail;


        }
        else if(current=='%')
        {
            if(curr==tail)
                curr=tail;
            else if(curr->next->next!=NULL){
                tmp=curr->next;
            curr->next=tmp->next;
            curr->next->next->prev=tmp->prev;
           // tmp=tmp->next;
            free(tmp);

            }
            else{
                tmp=curr->next;
                curr->next=NULL;

                free(tmp);
                tail=curr;

            }



        }
        else{
                tmp=curr;
                if(curr->next!=NULL)
                {

                curr = (monkey*)malloc(sizeof(monkey));

                curr->prev=tmp;
                curr->next=tmp->next;
                tmp->next->prev=curr;
                tmp->next=curr;
                curr->a=current;

                }
                if(curr->next==NULL)
               {
                   tmp=curr;
                   curr = (monkey*)malloc(sizeof(monkey));

                curr->next=NULL;
                curr->prev=tmp;
                tmp->next=curr;
                curr->a=current;
                tail=curr;
                }




        }

       m = scanf("%c",&current);



    }
    tmp2=head->next;
while(tmp2!=NULL){
    printf("%c",tmp2->a);
tmp2=tmp2->next;

  }
printf("\n");
    return 0;
}

/*192.168.136.1*//*CSY103062316*/
