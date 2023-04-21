/*
int a; // 一個整型數

int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個整型數

int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的

int (*a)[10]; // 一個指向有10個整數型陣列的指標

int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數

const int *foo; // 一個 pointer，指向 const int 變數。
int const *foo; // 一個 pointer，指向 const int 變數。
// 指標指的內容不可變動

int* const foo; // 一個 const pointer，指向 int 變數。
// 指標不可變動

int const *const foo; // 一個 const pointer，指向 const int 變數。
*/
# include <stdio.h>
int main()
{
    int a = 5;            // &a = memory position of a         a = 5
    int *p2a = &a;        // &p2a = memory position of p2a     p2a = mem of a
    int **p2p = &p2a;     // &p2p = memory position of p2p     p2p = mem of p2a
    printf("%d, %d, %d\n", a, *p2a, **p2p);
    printf("%d, %d, %d\n", &a, &p2a, &p2p);
    printf("%d, %d, %d\n", &a, p2a, p2p);
    int *ptr;
    ptr = &a; // 設定指標變數的值
    *ptr = 9; //設定指標變數指向的值
    printf("%d, %d, %d\n", a, *ptr, ptr);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &(arr + 1)[3];
    printf("%d\n", *p);

    char s[] = "0113256";
    char *c = s;
    printf("%c", *c++);
    printf("%c", *(c++));
    printf("%c", (*c)++);
    printf("%c", *++c);
    printf("%c", *(++c));
    printf("%c", ++*c);
    printf("%c", ++(*c));
    printf("\n");
    printf(s);

    /*
        *p++ = *(p++)	先取值，後指標下移
        *++p = *(++p)	指標下移，後取值
        ++*p = ++(*p)	先把該值+1，後取值
        (*p)++	先取值，後該值+1
    */
}
