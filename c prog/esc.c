/*
//fibinacci series
#include <stdio.h>

int main(void)
{
    int i,n,j,k;
    printf("enter a number:");
    scanf("%d",&n);
    i = 0;
    j = 1;
    while (k<=n)
    {
        printf("%d\n",k);
        i=j;
        j=k;
        k=i+j;
    }
    return 0;
}*/

/*
//sum of n natural numbers
#include <stdio.h>

int main(void)
{
    int i,n,sum;
    printf("enter number:");
    scanf("%i",&n);
    i=1;
    sum= 0;
    while (i<=n)
    {
        sum += i;
        ++i;
    }
    printf("sum= %i",sum);
    return 0;
}*/

/*//sum of numbers from m to n

#include <stdio.h>

int main(void)
{
    int m,n,sum;
    printf("enter lower limit number:");
    scanf("%i",&m);
    printf("enter upper limit number:");
    scanf("%i",&n);
    sum = 0;
    while (m<=n)
    {
        sum+=m;
        ++m;
    }
    printf("sum= %i",sum);
    return 0;
}*/


/*
     1
    12
   123
  1234
 12345
*/
/*
#include<stdio.h>
#define N 5
int main()
{
    int i, j, k;
    for (i=1;i<=N;i++)
    {
        for(k=N;k>=i;k--)
            printf(" ");
            for(j=1;j<=i;j++)
                printf("%d",j);
                printf("\n");
    }
return 0;
}*/

/*
    1
   121
  12321
 1234321
123454321 
*/
/*
#include <stdio.h>
#define N 5

int main(void)
{
    int i,j,k,l;
    for(i=1;i<=N;i++)
    {
        for(k=N;k>=i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        for(l=j-2;l>0;l--)
        {
            printf("%d",l);
        }
        printf("\n");
    }
    return 0;
}*/



/*
#include <stdio.h>
#include <conio.h>
int main()
{
int i, n, arr[20];
printf("\n Enter the number of elements in the array : ");
scanf("%d", &n);
for(i=0; i<n; i++)
{
printf("\n arr[%d] = ", i);
scanf("%d",&arr[i]);
}
printf("\n The array elements are ");
for(i=0; i<n; i++)
printf("\t %d", arr[i]);
return 0; }
*/