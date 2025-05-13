#include <stdio.h>
#include <time.h> //for clock

int main(){
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    clock_t start,end;
    double cpu_time_used;
    start=clock(); //start time
    int n1=0, n2=1;
    int n3;
    if (n==0) {
        printf("fibonoci is 0");
    }
    else if (n==1) {
        printf("fibonoci is 1");
    }
    else {
        printf("fibonacci %d, %d",n1, n2);
        for (int i=2; i<=n; i++) {
            n3=n1+n2;
            printf(" ,%d",n3);
            n1=n2;
            n2=n3;
        }
        printf("\n");
        /*printf("%d\n",n1);
        printf("%d\n",n2);
        printf("%d\n",n3);*/
    }
    end=clock(); //end time
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken:%.6f seconds\n",cpu_time_used);
    return 0;
}
