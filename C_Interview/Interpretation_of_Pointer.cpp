/*
int a; // �@�Ӿ㫬��

int *a; // �@�ӫ��V��ƪ�����
int **a; // �@�ӫ��V���Ъ����СA�����V�����ЬO���V�@�Ӿ㫬��

int a[10]; // �@�Ӧ�10�Ӿ�ƫ����}�C
int *a[10]; // �@�Ӧ�10�ӫ��Ъ��}�C�A�ӫ��ЬO���V�@�Ӿ�ƫ���

int (*a)[10]; // �@�ӫ��V��10�Ӿ�ƫ��}�C������

int (*a)(int); // �@�ӫ��V��ƪ����СA�Ө�Ʀ��@�Ӿ�ƫ��Ѽƨê�^�@�Ӿ��
int (*a[10])(int); // �@�Ӧ�10�ӫ��Ъ��}�C�A�ӫ��Ы��V�@�Ө�ơA�Ө�Ʀ��@�Ӿ�ƫ��Ѽƨê�^�@�Ӿ��

const int *foo; // �@�� pointer�A���V const int �ܼơC
int const *foo; // �@�� pointer�A���V const int �ܼơC
// ���Ы������e���i�ܰ�

int* const foo; // �@�� const pointer�A���V int �ܼơC
// ���Ф��i�ܰ�

int const *const foo; // �@�� const pointer�A���V const int �ܼơC
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
    ptr = &a; // �]�w�����ܼƪ���
    *ptr = 9; //�]�w�����ܼƫ��V����
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
        *p++ = *(p++)	�����ȡA����ФU��
        *++p = *(++p)	���ФU���A�����
        ++*p = ++(*p)	����ӭ�+1�A�����
        (*p)++	�����ȡA��ӭ�+1
    */
}
