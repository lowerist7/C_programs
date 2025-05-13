#include <stdio.h>

/*int main(){
    int n=5;
    int sum = (n*(n+1))/2;
    printf("sum of %d is %d\n",n,sum);
    return 0;
}
*/

int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    while (n>0) {
        sum+=n;
        n--;
        //printf("sum is %d",sum);
    }
    printf("sum is %d\n",sum);
    return 0;
}
