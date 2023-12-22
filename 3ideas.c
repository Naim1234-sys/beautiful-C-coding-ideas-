#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    char *token=strtok(s, " ");
    while(token!=NULL){
        printf("%s\n",token);
        token=strtok(NULL, " ");
    }

    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i] ==' ' ? '\n':s[i]);
    }
    
    for(char *c=s;*c != '\0';c++){
        if(*c==' '){
            *c='\n';
        }
        printf("%s",s);
    }
        return 0;
}
