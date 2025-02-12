/*1.Write a program to calculate sum of N natural numbers.

2. Write a program to calculate sum of numbers from m to n.

3. Write a program to read the numbers until -1 is encountered. Also count the number of negatives, positives and zeros entered by user.
 
4. Write a program to print sum and average of the numbers entered by user.

5. Write a program to print the N numbers in reverse order using While Loop

6. Write a program to print Fibonacci series using While Loop
*/

//finding smallest number

// #include <stdio.h>
// int main(void){
//     int arr[5]={9,15,4,72,84};
//     int small,i;
//     small = arr[0];
//     for(i=1;i<5;++i){
//         if(arr[i]<small){
//             small = arr[i];
//         }
//     }
//     printf("smallest no: %d ",small);
//     return 0;
// }

// recurssive functions


//5 = 5 x 4 x 3 x 2 x 1

// #include <stdio.h>
// int fact(int n){
//     if (n == 1)
//         return 1;
//     else
//         return(n * fact(n-1))
// }

//multiplication table:

// #include <stdio.h>

// int main(void){
//     int i,n;
//     printf("multiplication table number:");
//     scanf("%d",&n);
//     for(i=1;i<11;++i){
//         printf("%d x %2d = %d\n",n,i,n*i);
//     }
//     return 0;
// }


//calculator

// #include <stdio.h>

// int main(void){
//     int num1, num2;
//     char operator;
//     printf("enter the two numbers:");
//     scanf("%d %d", &num1, &num2);
//     printf("enter the operator (+,-,*,/) ");
//     scanf(" %c",&operator);

//     switch(operator){
//         case '+':
//             printf("sum is %d\n",num1+num2);
//             break;
//         case '-':
//             printf("diff is %d\n",num1-num2);
//             break;
//         case '*':
//             printf("mutiplication is %d\n",num1*num2);
//             break;
//         case '/':
//             if(num2!=0){
//                 printf("division is %.2f\n",(float)num1/num2);
//                 break;
//             }
//             else
//                 printf("division by 0\n");
//         default:
//             printf("enter a valid operator among the options\n");
//     }
//     return 0;   
// }

//strlen() and strcat()

// #include <stdio.h>
// #include <string.h>

// int main(void){
//     char str1[100], str2[100];
//     printf("enter string1: ");
//     scanf(" %s",str1);
//     printf("enter string2: ");
//     scanf(" %s",str2);

//     printf("length of string1 is: %lu\n",strlen(str1));

//     strcat(str1, str2);
//     printf("concating str2 and str1: %s\n",str1);

//     return 0;
// }

//recursion

// #include <stdio.h>

// int sum(int n){
//     if(n==0)
//         return 0;
//     else
//         return n + sum(n-1);
// }

// int main(void){
//     int sum(int n);
//     int num;
//     printf("enter a value to find sum of range: ");
//     scanf("%d",&num);
//     printf("sum: %d\n",sum(num));

//     return 0;
// }

//swapping using pointers

// #include <stdio.h>
// void swap(int *a, int *b){
//     int temp;
//     temp = *b;
//     *b = *a;
//     *a = temp;
// }

// int main(void){
//     int num1, num2;
//     printf("enter two numbers: ");
//     scanf("%d %d",&num1, &num2);
//     swap(&num1,&num2);
//     printf("after swapping: %d %d\n",num1,num2);

//     return 0;
// }

//add two numbers and return the sum using pointers

// #include <stdio.h>

// int sum(int *n1, int *n2){
//     return *n1 + *n2;
// }

// int main(void){
//     int num1, num2;
//     printf("enter 2 numbers: ");
//     scanf("%d %d",&num1,&num2);
//     printf("sum: %d\n",sum(&num1,&num2));
//     return 0;
// }

//structure distance

// #include <stdio.h>
// #include <math.h>

// struct point{
//     float x,y;
// };

// int main(void){
//     struct point point1,point2;
//     printf("enter the x and y coordinates of point1: ");
//     scanf("%f %f",&point1.x,&point1.y);
//     printf("enter the x and y coordinates of point2: ");
//     scanf("%f %f",&point2.x,&point2.y);

//     printf("distance: %.2f\n",sqrt(pow(point2.x-point1.x,2) + pow(point2.y - point1.y,2)));
    
//     return 0;
// }