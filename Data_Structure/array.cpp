#include <string.h>
#include <stdio.h>

#include"array.h"


my_Array *array_new(int capacity)
{
    int arr_capacity = array_set_capacity(capacity);

    my_Array *arr = (my_Array *) malloc(sizeof(my_Array));
    check_mem_address(arr);

    arr->size = 0;
    arr->capacity = arr_capacity;
    arr->data = (int *) malloc(sizeof(int) * arr_capacity);
    check_mem_address(arr);

    return arr;
}

void array_clear(my_Array *arrptr)
{
    free(arrptr->data);
    free(arrptr);
}

void check_mem_address(void *p)
{
    if(p == NULL)
    {
        printf("Unable to allocate mem.\n");
        exit(EXIT_FAILURE);
    }
}

int array_set_capacity(int capacity)
{
    const int kMinInitCapacity = 1;
    int normal = kMinCapacity;

    if(capacity < kMinInitCapacity)
    {
        exit(EXIT_FAILURE);
    }

    while(capacity > normal/kGrowthFactor)
    {
        normal *= kGrowthFactor;
    }

    return normal;
}

void array_set_size(my_Array *arrptr, int re_size)
{
    if(arrptr->size < re_size)
    {
        if(arrptr->size == re_size)
        {
            array_upsize(arrptr);
        }
    }
    else if(arrptr->size > re_size)
    {
        if(arrptr->size < arrptr->capacity / kShrinkFactor)
        {
            array_downsize(arrptr);
        }
    }
}

void array_upsize(my_Array *arrptr)
{
    int old_cap = arrptr->capacity;
    int new_cap = array_set_capacity(old_cap);

    int *new_data = (int *)realloc(arrptr->data, sizeof(int) * new_cap);
    check_mem_address(new_data);

    arrptr->data = new_data;
    arrptr->capacity = new_cap;
}

void array_downsize(my_Array *arrptr)
{
    int old_cap = arrptr->capacity;
    int new_cap = arrptr->capacity / kGrowthFactor;

    if(new_cap < kMinCapacity)
    {
        new_cap = kMinCapacity;
    }

    if(new_cap != old_cap)
    {
        int *new_data = (int *)realloc(arrptr->data, sizeof(int) * new_cap);
        check_mem_address(new_data);

        arrptr->data = new_data;
        arrptr->capacity = new_cap;
    }
}

int array_size(my_Array *arrptr)
{
    return arrptr->size;
}

int array_capacity(my_Array *arrptr)
{
    return arrptr->capacity;
}

void array_append(my_Array *arrptr, int item)
{
    array_set_size(arrptr, arrptr->size + 1);
    *(arrptr->data + arrptr->size) = item;
    ++(arrptr->size);
}

void array_print(my_Array *arrptr)
{
    printf("Size: %d\n", arrptr->size);
    printf("Capacity: %d\n", arrptr->capacity);
    printf("Item:\n");
    for(int i = 0; i < arrptr->size; i++)
        printf("[%d]: %d\n", i, *(arrptr->data + i));
    printf("-----");
}

bool array_is_empty(my_Array *arrptr)
{
    return arrptr->size == 0;
}

int array_index(my_Array *arrptr, int index)
{
    if(index < 0 || index >= arrptr->size)
    {
        exit(EXIT_FAILURE);
    }
    return *(arrptr->data + index);
}

void array_insert(my_Array *arrptr, int index, int value)
{
    if(index < 0 || index >= arrptr->size)
    {
        exit(EXIT_FAILURE);
    }

    array_set_size(arrptr, arrptr->size+1);

    memmove(arrptr->data + index + 1, arrptr->data + index, (arrptr->size - index) * sizeof(int));

    *(arrptr->data + index) = value;
    arrptr->size += 1;
}

void array_prepend(my_Array *arrptr, int value)
{
    array_insert(arrptr, 0, value);
}

int array_pop(my_Array *arrptr)
{
    if(arrptr->size == 0)
        exit(EXIT_FAILURE);

    array_set_size(arrptr, arrptr->size-1);

    int value = *(arrptr->data + arrptr->size-1);
    arrptr->size --;

    return value;
}

void array_delete(my_Array *arrptr, int index)
{
    if(index < 0 || index >= arrptr->size)
    {
        exit(EXIT_FAILURE);
    }

    array_set_size(arrptr, arrptr->size-1);
    memmove(arrptr->data + index, arrptr->data + index + 1, (arrptr->size - index) * sizeof(int));
    arrptr->size --;
}

void array_remove_all(my_Array *arrptr, int value)
{
    for(int i = 0; i < arrptr->size; i++)
    {
        int check = *(arrptr->data + i);
        if(check == value)
        {
            array_delete(arrptr, i);
            i--;
        }
    }
}

int array_find(my_Array *arrptr, int value)
{
    for(int i = 0; i < arrptr->size; i++)
    {
        int check = *(arrptr->data + i);
        if(check == value)
        {
            return i;
        }
    }
    return -1;
}


void run_all_tests() {
  test_size_init();
  test_append();
  test_empty();
  test_resize();
  test_at();
  test_insert();
  test_prepend();
  test_pop();
  test_remove();
  test_find_exists();
  test_find_not_exists();
}


void test_append()
{
    my_Array *arrptr = array_new(2);
    array_append(arrptr, 2);
    array_append(arrptr, 14);
    int new_size = array_size(arrptr);
    assert(new_size == 2);
    array_clear(arrptr);
}
void test_size_init()
{
    my_Array *arrptr = array_new(5);
    int initial_size = array_size(arrptr);
    assert(initial_size == 0);
    array_clear(arrptr);
}

void test_empty()
{
    my_Array *arrptr = array_new(2);
    bool empty = array_is_empty(arrptr);
    assert(empty == 1);
    array_append(arrptr, 3);
    empty = array_is_empty(arrptr);
    assert(empty == 0);
    array_clear(arrptr);
}
void test_resize()
{
    my_Array *arrptr = array_new(2);
    int old_cap = array_capacity(arrptr);
    assert(old_cap == 16);
    for(int i = 0; i<18; i++)
    {
        array_append(arrptr, i+1);
    }
    //assert(array_capacity(arrptr) == 32);
    printf("%d\n", array_capacity(arrptr));
    array_print(arrptr);
    for(int j = 0; j < 15; j++)
    {
        array_pop(arrptr);
    }
    assert(array_capacity(arrptr) == 16);
    array_clear(arrptr);
}
void test_at()
{
    my_Array *arrptr = array_new(12);
    for(int i = 0; i < 12; i++)
    {
        array_append(arrptr, i+3);
    }
    assert(array_index(arrptr, 6) == 9);
    array_clear(arrptr);
}
void test_insert()
{
    my_Array *arrptr = array_new(5);
    for(int i = 0; i < 5; i++)
        array_append(arrptr, i+5);
    array_insert(arrptr, 2, 47);
    assert(array_index(arrptr, 2) == 47);
    assert(array_index(arrptr, 3) == 7);
    array_clear(arrptr);
}
void test_prepend()
{
    my_Array *arrptr = array_new(2);
    for(int i = 0; i <2; i++)
    {
        array_append(arrptr, i + 1);
    }
    array_prepend(arrptr, 15);
    assert(array_index(arrptr, 0) == 15);
    assert(array_index(arrptr, 1) == 1);
    array_clear(arrptr);
}
void test_pop()
{
    my_Array *arrptr = array_new(5);
    for(int i = 0; i < 2; i++)
    {
        array_append(arrptr, i+1);
    }
    assert(arrptr->size == 2);
    for(int j = 0; j < 2; j++)
    {
        array_pop(arrptr);
    }
    assert(array_is_empty(arrptr) == 1);
    array_clear(arrptr);
}
void test_remove()
{
    my_Array *arrptr = array_new(5);
    array_append(arrptr, 2);
    array_append(arrptr, 3);
    array_append(arrptr, 2);
    array_append(arrptr, 1);
    array_append(arrptr, 2);
    array_remove_all(arrptr, 2);
    assert(array_size(arrptr) == 2);
    array_clear(arrptr);
}
void test_find_exists()
{
    my_Array *arrptr = array_new(5);
    array_append(arrptr, 2);
    array_append(arrptr, 3);
    array_append(arrptr, 2);
    array_append(arrptr, 1);
    array_append(arrptr, 2);
    assert(array_find(arrptr, 2) == 0);
    assert(array_find(arrptr, 1) == 3);
    array_clear(arrptr);
}
void test_find_not_exists()
{
    my_Array *arrptr = array_new(5);
    array_append(arrptr, 12);
    array_append(arrptr, 3);
    array_append(arrptr, 21);
    array_append(arrptr, 1);
    array_append(arrptr, 22);
    assert(array_find(arrptr, 2) == -1);
    array_clear(arrptr);
}
