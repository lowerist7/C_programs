#include <inttypes.h>
#include <stdio.h>
//#include <stdlib.h>

int fib(int n){
    int a=0, b=1, c,i;
    if (n==0) {
        return a;
    }
    for (i=2; i<=n; i++) {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    int result=fib(n);
    printf("fibonacci numver at position %d is %d\n",n,result);
    return 0;
}
