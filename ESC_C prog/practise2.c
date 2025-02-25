//3c
// #include <stdio.h>
// #include <ctype.h>
// int main(void){
//     int c=0,v=0, i=0;
//     char s[50];
//     printf("enter a string:");
//     scanf("%49s",s);
//     while (s[i] != '\0'){
//         char ch = tolower(s[i]);

//         if (ch>='a' && ch<='z'){
//             if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
//                 v++;
//             else
//                 c++;
//         }
//         i++;
//     }
//     printf("no of vowels: %d\n",v);
//     printf("no of consonants: %d\n",c);
//     return 0;
// }

// 5a
// #include <stdio.h>
// void mtable(void){
//     int num,i;
//     printf("enter no:");
//     scanf("%d",&num);
    
//     printf("multiplication table of %d\n",num);
//     printf("----------------------------\n");
//     for(i=1;i<=10;i++)
//         printf("%d x %d = %d\n",num,i,num*i);
// }

// int main(void){
//     char ch;
//     do{
//         mtable();
//         printf("do you want to continue?[y/n]:");
//         scanf(" %c",&ch);
//     }while (ch=='y' || ch=='Y');

//     return 0;
// }

//Write a program to sort names of students using Array of Strings.
// #include <stdio.h>
// #include <string.h>

// int main(void){
//     char name[5][50],temp[50];
//     int i,j;

//     printf("enter names:");
//     for (i=0;i<5;i++){
//         scanf("%s",name[i]);
//     }
//     for(i=0;i<5;i++){
//         for(j=0;j<5-i-1;j++){
//             if (strcmp(name[j],name[i])>0){
//                 strcpy(temp,name[j]);
//                 strcpy(name[j],name[j+1]);
//                 strcpy(name[j+1],temp);
//             }
//         }
//     } 
//     printf("sorted:");
//     for(i=0;i<5;i++){
//         printf("%s\n",name[i]);
//     }   
//     return 0;
// }


//selection sort
// 7,6,5,1,2,3

#include <stdio.h>
#define n 6

int main(void){
    int i,j;
    int arr[]={7,6,5,1,2,3};
    for(i=0;i<n;i++){
        int small=i;
        for(j=i;j<n;j++){
            if(arr[small]>arr[j]){
                small = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i]=arr[small];
        arr[small]=temp;   
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

//bubble sort

// #include <stdio.h>
// #define n 6

// int main(void){
//     int i,j;
//     int arr[]={7,6,5,1,2,3};
//     for(i=0;i<n-1;i++){
//         for(j=0;j<n-1-i;j++){
//             if (arr[j]>arr[j+1]){
//                 int temp = arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
//     for(i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }



