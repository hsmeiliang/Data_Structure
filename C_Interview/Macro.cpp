# include <stdio.h>

# define Max(x, y) ((x) > (y)) ? (x) : (y)

#define Mul(a,b)  a*b

#define PI 3.1415926    //±`¼Æ¥¨¶°

int main(){
    int x = Max(1, 2);
    printf("%d\n", x);
    printf("%f\n", PI);
    printf("%d\n", Mul(2+3, 3+2));
    return 0;
}
