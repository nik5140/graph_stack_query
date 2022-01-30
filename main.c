#include <stdio.h>
#include <stdlib.h>
#define Error 0x7FFF

typedef struct node {
int data;
struct node *next;

} Node;

Node *Add(Node *Top, int d)
{
    Node *newel = (Node*) malloc(sizeof(Node));
    newel->data = d;
    newel->next = Top;
    return newel;
}


void Show (Node *Top)
{
    while (Top){
        if (Top->next) printf("%3d", Top->data);
        else printf("%3d\n", Top->data);
        Top = Top->next;

    }
}


int Delete (Node **Top)
{
    int d;
    if ((*Top)!=NULL)
    {
        d = (*Top)->data;
        Node *temp = *Top;
        *Top = (*Top)->next;
        free(temp);
    }
    else {(printf("Error!!"));
    d = Error;
    }
    return d;

}

Node *Add_Q(Node *Top, int d)
{
    Node *newel = (Node*)malloc(sizeof(Node));
    newel->data = d;
    newel->next = NULL;

    if (Top==NULL) return newel;
    Node *temp = Top;
    while (temp->next)
        temp = temp->next;
    temp->next = newel;
    return Top;

}

int main()
{
   int **Msmejn;
   int n = 4;
   int m = 4;
   int i=0, k=0;

   Msmejn = (int**)malloc(sizeof(int)*n);
   for (i=0; i<n; i++)
     Msmejn[i] = (int*)malloc(sizeof(int)*m);

   // fill matrix with zeros
   for(i=0; i<n; i++)
    for (k=0; k<m; k++)
        Msmejn[i][k] = 0;

   // print matrix
   for(i=0; i<n; i++)
    for (k=0; k<m; k++)
        if ((k==3)||((k+1)%4==0))
            printf("%3d\n", Msmejn[i][k]);
        else
            printf("%3d", Msmejn[i][k]);

    printf("\n");

    Msmejn[0][1] = 1;
    Msmejn[0][2] = 1;
    Msmejn[0][3] = 1;
    Msmejn[1][0] = 1;
    Msmejn[1][3] = 1;
    Msmejn[2][0] = 1;
    Msmejn[3][0] = 1;
    Msmejn[3][1] = 1;
 //   Msmejn[2][3] = 1;
 //   Msmejn[3][2] = 1;

    // print matrix again
   for(i=0; i<n; i++)
    for (k=0; k<m; k++)
        if ((k==3)||((k+1)%4==0))
            printf("%3d\n", Msmejn[i][k]);
        else
            printf("%3d", Msmejn[i][k]);

    printf("\n");

    Node *T = NULL;
    Node *mpr = NULL;

    int a = 0; // 0,0
    int metki[4] = {0,0,0,0};
    int flag_go=1;

    T = Add(T,a);
    metki[a] = 1;
    while(T)

    {
        a = Delete(&T);
  //      printf("%3d",a);
        mpr = Add_Q(mpr,a);
        for (i=0; i<n; i++)
        {
            if ((Msmejn[a][i]==1)&&metki[i]==0)
            {
                T = Add(T,i);
                metki[i]=1;
        //        Show(T);
            }
        }
    }

    Show(mpr);

    system("chcp 1251 >0");

    return 0;
}
