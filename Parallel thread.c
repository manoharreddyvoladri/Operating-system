//Parallel thread management, Dynamic memory allocation

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
void fact()
{
    printf("Enter the number for factorial : ");
    int n,fact=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        fact = fact*i;
    }
    printf("The factorial of %d is %d\n",n,fact);
}
void prime()
{
    printf("Enter the number to be checked : ");
    int n,flag=0;
    scanf("%d",&n);
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("The given number %d is not Prime\n",n);
    }
    else
    {
        printf("The given number %d is Prime\n",n);
    }
}
void reg()
{
    printf("Enter the Register Number to be analysed : ");
    char reg[10],dept[3];
    int year[4],roll[4],x;
    scanf("%s",&reg);
    printf("20");
    for(int i=0;i<2;i++)
    {
        x=(int)reg[i];
        year[i]=x;
        printf("%d",(year[i]-48));
    }
    x=0;
    printf("\nThe department is ");
    for(int i=2;i<5;i++)
    {
        dept[x]=reg[i];
        x++;
        printf("%c",dept[x-1]);
    }
    printf("\n");
    int y=0;
    printf("The roll No is ");
    for(int i=5;i<9;i++)
    {
        x=(int)reg[i];
        roll[y]=x;
        printf("%d",(roll[y]-48));
        y++;
    }
    if(x%2==0)
    {
        printf(" and its even");
    }
    else
    {
        printf(" and its odd");
    }
}
int main()
{
    printf("Dhanush Sriram G - 21BRS1177\n\n");
    pthread_t p1,p2,p3;
    pthread_create(&p1,NULL,fact,NULL);
    pthread_join(p1,NULL);
    pthread_create(&p2,NULL,prime,NULL);
    pthread_join(p2,NULL);
    pthread_create(&p3,NULL,reg,NULL);
    pthread_join(p3,NULL);
}
