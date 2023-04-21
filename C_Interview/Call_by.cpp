# include <stdio.h>
# include <stdlib.h>
# include <cstring>
//call by value
//   �̱`�����禡�g�k�A�I�s�̩M�Q�I�s�̪��ܼƦU�ۦ����O����A�N�Ѽƽƻs�A�ǵ��禡�C

int swap_1 (int c , int d){
   int temp=c;
   c=d;
   d=temp;
   return c;
}

//Call by address
//    �ǫ��СA���M�]�Ocall by value�A�u���L�ƻs����Value��n�N�O��}address

int swap_2(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return *a;
}

//Call by reference
//    �I�s�̩M�Q�I�s�̪��ܼƨϥάۦP���O�����}�A�]���b�Q�I�s�禡�������ܼƮɡA�ܰʵ��G�|�O�d�C
//    �`�N���O�A�@�ܼƤw�g�O�O���ܼƪ��ѦҡA�N���i�H�A�ѦҧO���ܼ�
//    �ǰѦҥ����b�ŧi���ɭԴN�@�_���ѦҪ���H�A�S��k����A���C

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


