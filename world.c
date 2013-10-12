#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct link
{
    int t;
    struct link * next;
};
struct link * g[100000];
int isConnected(int x,int y)
{
    struct link * q,* p;
    if (x==y) {return 1;}
    p = g[x];
    q = g[y];
    while (p!=NULL)
    {
        if (p->t==y) {return 1;}
        p=p->next;
    }
    while (q!=NULL)
    {
        if (q->t==x) {return 1;}
        q=q->next;
    }
    return 0;
}
int pure(int x)
{
    struct link * q,*r;
    q = g[x];
    while (q!=NULL)
    {
        r =g[x];
        while (r!=NULL)
        {
            if (isConnected(r->t,q->t)==0)
            {
                return 0;
            }
            r=r->next;
        }
        q = q->next;
    }
    return 1;
}
int main()
{
    int n,i,j,m,yes;
    struct link * q,* r;
    float p;
    int sum = 0;
    scanf("%d %d %f",&n,&m,&p);
    srand(time(0));
    for (i=0;i<n;i++)
    {
        g[i] = NULL;
        for (j=1;j<=m;j++)
        {
            q = (struct link*)malloc(sizeof(struct link));
            q->next = g[i];
            if (p<(rand()%10000)/10000.0)
            {
                q->t = (i+j+n)%n;
            }
            else
            {
                q->t = rand()%n;
            }
            q->next=g[i];
            g[i]=q;
        }
    }
    for (i=0;i<n;i++)
    {
        q = g[i];
        while (q!=NULL)
        {
            q=q->next;
        }
    }
    sum=0;
    for (i=0;i<n;i++)
    {
        if (pure(i))
        {
            sum++;
        }
    }
    printf("%d\n",sum);
}
