#include<stdio.h>

/*int main (void)
{
     int  number;

     printf ("Type in your number: ");
     scanf ("%i", &number);

     if ( number < 0 )
          number = -number;

     printf ("The absolute value is %i\n", number);

     return 0;
}*/

/* Program to calculate the average of a set of grades and count
   the number of failing test grades     */

/*int main (void)
{
    int       numberOfGrades, i, grade;
    int       gradeTotal = 0;
    int       failureCount = 0;
    float     average;

    printf ("How many grades will you be entering? ");
    scanf ("%i", &numberOfGrades);

    for ( i = 1;  i <= numberOfGrades;  ++i ) {
         printf ("Enter grade #%i: ", i);
         scanf ("%i", &grade);

         gradeTotal += grade;

         if ( grade < 65 )
             ++failureCount;
     }

    average = (float) gradeTotal / numberOfGrades;

    printf ("\nGrade average = %.2f\n", average);
    printf ("Number of failures = %i\n", failureCount);

    return 0;
}*/

// program to determine is a year is a leap year

/*int main(void)
{
    int year,rem_4,rem_100,rem_400;

    printf("enter a year: ");
    scanf("%i", &year);

    rem_4 = year%4;
    rem_100 = year%100;
    rem_400 = year%400;

    if ((rem_4 == 0 && rem_100 != 0) || rem_400 == 0)
//  if ( ( year % 4 == 0  &&  year % 100 != 0 )  || year % 400 == 0 )  //alternative
        printf("it is a leap year\n");
    else
        printf("it is not a leap year\n");

    return 0;
}*/


// Program to categorize a single character that is entered at the terminal

/*int main (void)
{
     char  c;

     printf ("Enter a single character:\n");
     scanf ("%c", &c);

     if ( (c >= 'a'  &&  c <= 'z') || (c >= 'A'  &&  c <= 'Z') )
          printf ("It's an alphabetic character.\n");
     else if  ( c >= '0'  &&  c <= '9' )
          printf ("It's a digit.\n");
     else
          printf ("It's a special character.\n");

     return 0;
}*/

/* Program to evaluate simple expressions of the form
               number  operator  number                */

/*int main (void)
{
     float  value1, value2;
     char   operator;

     printf ("Type in your expression.\n");
     scanf ("%f %c %f", &value1, &operator, &value2);

     if ( operator == '+' )
          printf ("%.2f\n", value1 + value2);
     else if ( operator == '-' )
          printf ("%.2f\n", value1 - value2);
     else if ( operator == '*' )
          printf ("%.2f\n", value1 * value2);
     else if ( operator == '/' )
          printf ("%.2f\n", value1 / value2);

     return 0;
}*/

/*int main (void)
{
     float  value1, value2;
     char   operator;

     printf ("Type in your expression.\n");
     scanf ("%f %c %f", &value1, &operator, &value2);

     if ( operator == '+' )
          printf ("%.2f\n", value1 + value2);
     else if ( operator == '-' )
          printf ("%.2f\n", value1 - value2);
     else if ( operator == '*' )
          printf ("%.2f\n", value1 * value2);
     else if ( operator == '/' )
          if ( value2 == 0 )
               printf ("Division by zero.\n");
          else
               printf ("%.2f\n", value1 / value2);
     else
          printf ("Unknown operator.\n");

     return 0;
}*/


//  Program to generate a table of prime numbers
/*int main(void)
{
    int i,j;
    _Bool isPrime;

    for (i = 2; i <= 50; ++i)
        {
        isPrime = 1;
        for (j = 2; j < i; ++j)
            if (i % j == 0)
                isPrime = 0;
        if (isPrime != 0)
            printf("%i ",i);            
        }
    printf("\n");
    return 0;        
}*/

//  Program to generate a table of prime numbers

#include <stdio.h>
#include <stdbool.h>

int main (void)
{
     int   i, j;
     bool  isPrime;

     for ( i = 2;  i <= 50;  ++i ) 
     {
         isPrime = true;
         for ( j = 2;  j < i;  ++j )
              if ( i % j  ==  0 )
                  isPrime = false;

              if ( isPrime != false )
                  printf ("%i  ", i);
     }

     printf ("\n");
     return 0;
}

/*1.Write a program that asks the user to type in two integer values at the terminal.
Test these two numbers to determine if the first is evenly divisible by the second,
and then display an appropriate message at the terminal.*/

/*2.Write a program that accepts two integer values typed in by the user. Display
the result of dividing the first integer by the second, to three-decimal-place
accuracy. Remember to have the program check for division by zero.*/

/*3. Write a program that acts as a simple “printing” calculator. The program 
should allow the user to type in expressions of the form 
        number   operator
The following operators should be recognized by the program: 
        +     -     *     /     S     E
The S operator tells the program to set the “accumulator” to the typed-in number.
The E operator tells the program that execution is to end. The arithmetic operations
are performed on the contents of the accumulator with the number that was keyed in
acting as the second operand. The following is a “sample run” showing how the program should operate:

Begin Calculations
10 S           Set Accumulator to 10
= 10.000000    Contents of Accumulator
2 /            Divide by 2
= 5.000000     Contents of Accumulator
55 -           Subtract 55
-50.000000
100.25 S       Set Accumulator to 100.25
= 100.250000
4 *            Multiply by 4
= 401.000000
0 E            End of program
= 401.000000
End of Calculations.

Make certain that the program detects division by zero and also checks for unknown operators.*/

/*4. You developed a program to reverse the digits of an integer typed in from the terminal.
However, this program does not function well if you type in a negative number. Find out what
happens in such a case and then modify the program so that negative numbers are correctly handled.
For example, if the number −8645 is typed in, the output of the program should be 5468−.*/

/*5. Write a program that takes an integer keyed in from the terminal and extracts and displays
each digit of the integer in English. So, if the user types in 932, the program should display
        nine three two
Remember to display “zero” if the user types in just a 0. (Note: This exercise is a hard one!)*/

/*6. The prime number program has several inefficiencies. One inefficiency results from checking
even numbers. Because it is obvious that any even number greater than 2 cannot be prime, the
program could simply skip all even numbers as possible primes and as possible divisors. The inner
for loop is also inefficient because the value of i is always divided by all values of j from 2
through i−1. This inefficiency could be avoided by adding a test for the value of isPrime in the
conditions of the for loop. In this manner, the for loop could be set up to continue as long as
no divisor was found and the value of j was less than i. Modify the program to incorporate these
two changes. Then run the program to verify its operation.*/