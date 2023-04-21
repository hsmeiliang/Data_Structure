# include <stdio.h>
# include <stdlib.h>

void strcpy(char* t, char* s){
    while((*t=*s) != '\0'){
        s++;
        t++;
    }
}

int strlength(char* s){
    int len = 0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}

int main(){
    char str1[10]="123456789";
    char *str2 = (char*) malloc(sizeof(char)*10);

    strcpy(str2, str1);
    printf("%s\n", str2);
    printf("%d\n", strlength(str1));
    free(str2);

}
