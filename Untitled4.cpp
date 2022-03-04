#include <stdio.h>
#include <stdlib.h>
enum VALID {FALSE, TRUE};
typedef struct {
    int valid;
    int *data;
    size_t size;
} MyObject;

int main() {
    int *tmp = NULL;
    MyObject *my1 = malloc(sizeof(MyObject));

    my1->valid = TRUE;
    my1->data = tmp;
    my1->size = sizeof tmp;

    free(my1);
    exit(EXIT_SUCCESS);
}
