#include <string.h>
#include <stdio.h>

void run_all_tests()
{
    printf("test\n");
}


my_Array *array_new(int capacity)
{
    int arr_capacity = array_set_capacity(capacity);

    my_Array *arr = malloc(sizeof(my_Array));
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
    int old_cap = arrptr->cap;
    int new_cap = array_set_capacity(old_cap);

    int *new_data = (int *)realloc(arrptr->data, sizeof(int) * new_cap);
    check_mem_address(new_data);

    arrptr->data = new_data;
    arrptr->capacity = new_cap;
}

void array_downsize(my_Array *arrptr)
{
    int old_cap = arrptr->cap;
    int new_cap = arrptr->cap / kGrowthFactor;

    if(new_cap < kMinCapacity)
    {
        new_cap = kMinCapacity;
    }

    if(new_cap != old_cap)
    {
        int *new_data = (int *)realloc(arrptr->data, sizeof(int) * new_cap);
        check_mem_address(new_data);
    }

    arrptr->data = new_data;
    arrptr->capacity = new_cap;
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
    return *(array->data + index);
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











