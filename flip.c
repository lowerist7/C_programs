#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>//for random number generation
// function to convert a string to lower case
void to_lower(char *s){
    for(int i =0; s[i]; i++){
        s[i] = tolower(s[i]);
    }
}
int main(){
    char statement[100];
    srand((unsigned int)time(0));//seed for random number generation
    printf("Enter a statement: ");
    fgets(statement, 100, stdin);
    statement[strcspn(statement, "\n")] = '\0';
    to_lower(statement);
    if(strcmp(statement, "flip") == 0)//compare the string
    {
        /* code */
        int random = rand()%2;
        if (random == 0){

            printf("HEADS\n");
        }
        else{
            printf("TAILS\n");
        }
    }
    
    return 0;   

}