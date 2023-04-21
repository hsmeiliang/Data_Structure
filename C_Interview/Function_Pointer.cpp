# include <stdio.h>

//Function Pointer
//    void (*fptr)(type_a, type_b) = &func;

//Function Pointer Type
//    typedef void(Fp)(void);

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int main(){
    int (*op)(int a, int b);
    op = add;
    printf("%d\n", op(1,2));

    op = sub;
    printf("%d\n", op(1,2));

    typedef int(*fp)(int, int);

    fp fpa[2];
    fpa[0] = add;
    fpa[1] = sub;

    for(int i = 0; i<2; i++){
        printf("%d\n", fpa[i](1,2));
    }

}
