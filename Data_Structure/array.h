#ifndef PROJECT_ARRAY_H


#define PROJECT_ARRAY_H

#include <assert.h>
#include <stdbool.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;


typedef struct _my_Array
{
    int size;
    int capacity;
    int *data;
} my_Array;

// Array Function
my_Array *array_new(int capacity);
void array_clear(my_Array *arrptr);

// Checks to see if resizing is needed to support the candidate_size
// and resizes to accommodate.
void array_set_size(my_Array *arrptr, int re_size);

// Determines the actual capacity (in terms of the power of growth factor)
// required to accommodate a given capacity.
int array_set_capacity(int capacity);

// Increases the array size to size determined by growth factor
void array_upsize(my_Array *arrptr);

// Decreases the array size to size determined by growth factor
void array_downsize(my_Array *arrptr);

// Returns the number of elements managed in the array.
int array_size(my_Array *arrptr);

// Appends the given item to the end of the array.
void array_append(my_Array *arrptr, int item);

// Prints public information about the array for debug purposes.
void array_print(my_Array *arrptr);

// Returns the actual capacity the array can accommodate.
int array_capacity(my_Array *arrptr);

// Returns the value stored at the given index.
int array_index(my_Array *arrptr, int index);

// Returns true if array is empty.
bool array_is_empty(my_Array *arrptr);

// Inserts the given value at the given index, shifting
// current and trailing elements to the right.
void array_insert(my_Array *arrptr, int index, int value);

// Prepends the given value to the array, shifting trailing
// elements to the right.
void array_prepend(my_Array *arrptr, int value);

// Removes the last item from the array and returns its value.
int array_pop(my_Array *arrptr);

// Deletes the item stored at the given index, shifting trailing
// elements to the left.
void array_delete(my_Array *arrptr, int index);

// Removes the given value from the array, even if it appears more than once.
void array_remove_all(my_Array *arrptr, int value);

// Returns the index of the first occurrence of the given value in the array.
int array_find(my_Array *arrptr, int value);

// Checks to see if given value is valid for memory, and exits if so
void check_mem_address(void *p);


// Tests
void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();
void test_find_exists();
void test_find_not_exists();



#endif // PROJECT_ARRAY_H
