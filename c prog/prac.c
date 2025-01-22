/*#include <stdio.h>

int main(void)
{
    int i,j,n;
    printf("enter value of n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        for(j=i-1;j>=1;j--)
        {
            printf("%d",j);
        }
        printf("\n"); 
    }
    return 0;
}*/

/*#include <stdio.h>

int main(void)
{
    int i,num,isprime=1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for(i=2;i<=num/2;i++)
    {
        if (num%i==0){
            isprime=0;
            break;
        }
    }
    if (isprime==1){
        printf("prime");
    }
    else{
        printf("composite");
    }
    return 0;
}*/

/*#include <stdio.h>

int main(void){
    int i,j,n;
    printf("enter number:");
    scanf("%d",&n);
    for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}*/


#include <stdio.h>
int main(void){
int x=10;
while(x--){
    printf("%d",x);
    if (x==5)
    break;
}}