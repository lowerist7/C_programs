#include <stdio.h>
#include <string.h>
/*
int main(){
    int n;
    scanf("%d",&n);
    int rem=0;
    int rev=0;
    int temp=n;
    while (n>0) {
        rem=n%10;
        n=n/10;
        rev=rev*10+rem;
    }
    if (rev==temp) {
        printf("%d is a palindrome.\n",temp);
    }
    else {
        printf("%d is not a palindrome.\n",temp);
    }
return 0;
}
*/

int main(){
    char name[25];
    printf("enter a character (maximum 24 letters):");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")]='\0';
    char rev[25];
    int len=strlen(name);

    for (int i=0; i<len; i++) {
        rev[i]=name[len-1-i];

    }
    rev[len]='\0';
    if (strcmp(name,rev)==0) {
        printf("%s is palindrome.\n",name);
    }
    else {
        printf("%s is not a palindrome,\n",name);
    }
    return 0;
}
