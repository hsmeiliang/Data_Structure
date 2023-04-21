# include <stdio.h>

void func(void){
    static int i = 0 ;
    i++ ;
    printf("%d" , i ) ;
}

int main(){
    for(int i =0; i<10; i++){
        func();
    }
    return 0;
}
