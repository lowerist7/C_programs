#include<stdio.h>

int main(){
    int n=25;
    int arr[n],i;

    printf("enter 5 elements of array (numbers only):");
    for ( i = 0; i < n; i++) // loop to take input

    {
        /* code */
        if(scanf("%d",&arr[i])!=1){ // check if input is a number
            printf("invalid input, please enter numbers only\n");
            return 1;// exit the program
        }
    }
    printf("the array in reverse order is:\n");
    for (i =4; i>=0; i--)
    {
        printf("%d",arr[i]);

    }
    printf("\n");
    return 0;  
    
}