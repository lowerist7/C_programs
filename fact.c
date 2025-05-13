#include<stdio.h>

int fact(int n){
    if (n==0){
        return 1;
    }
    int sum = 1;
    for(int i = 1;i <=n; i++){

        sum = sum*i;

    }
    return sum;

}
int main(){
    int n;
    printf("enter a number:");
    scanf("%d", &n);
    printf("factorial of %d is %d\n", n, fact(n));
    return 0;
}