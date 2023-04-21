# include <stdio.h>
# include <stdlib.h>
# include <cstring>
//call by value
//   最常見的函式寫法，呼叫者和被呼叫者的變數各自佔有記憶體，將參數複製再傳給函式。

int swap_1 (int c , int d){
   int temp=c;
   c=d;
   d=temp;
   return c;
}

//Call by address
//    傳指標，仍然也是call by value，只不過複製的值Value剛好就是位址address

int swap_2(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return *a;
}

//Call by reference
//    呼叫者和被呼叫者的變數使用相同的記憶體位址，因此在被呼叫函式中改變變數時，變動結果會保留。
//    注意的是，一變數已經是別的變數的參考，就不可以再參考別的變數
//    傳參考必須在宣告的時候就一起給參考的對象，沒辦法之後再給。

int swap_3(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
    return a;
}

void GetMemory(char *p) {
	p=(char *)malloc(100);
}
void GetMem_2(char **p){
    *p = (char *)malloc(100);
}
void test() {
	char *str = NULL;
	//GetMemory(str);   (x)
	GetMem_2(&str);
	strcpy(str,"hello world");
	printf(str);
}

int main(){
    int a = 5, b = 10;
    int a2 = 0;
    a2 = swap_1(a, b);
    printf(" %d %d %d \n", a,b, a2);

    a = 5, b = 10;
    a2 = 0;
    a2 = swap_2(&a, &b);
    printf(" %d %d %d \n", a,b, a2);

    a = 5, b = 10;
    a2 = 0;
    a2 = swap_3(a, b);
    printf(" %d %d %d \n", a,b, a2);

    test();
}


