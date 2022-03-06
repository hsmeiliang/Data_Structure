#include "test.h"
#include "link_list.h"

void run_all_tests()
{
    test_size();
    test_push_front();
    test_empty();
    test_front();
    test_back();
    test_pop_front();
    test_push_back();
    test_pop_back();
    test_insert();
    test_value_at();
    test_erase();
    test_value_n_from_end();
    test_reverse();
    test_reverse_single();
    test_reverse_empty();
    test_remove();
}

void test_size()
{
    int size = 0;

    ForwardList *ll = list_new();
    size = list_size(ll);
    assert(size == 0);

    list_append(ll, 12);
    assert(list_size(ll) == 1);

    list_clear(ll);
}

void test_push_front()
{
    ForwardList *ll = list_new();
    assert(list_size(ll) == 0);

    list_push_front(ll, 6);
    assert(list_size(ll) == 1);

    list_push_front(ll, 2);
    list_push_front(ll, 32);
    assert(list_size(ll) == 3);

    list_clear(ll);
}

void test_empty()
{
    ForwardList *ll = list_new();
    assert(list_empty(ll) == 1);

    list_push_front(ll, 32);
    assert(list_empty(ll) == 0);

    list_clear(ll);

}

void test_front()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 12);
    assert(list_front(ll) == 12);

    list_push_front(ll, 212);
    assert(list_front(ll) == 212);
    list_clear(ll);
}

void test_back()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 12);
    assert(list_back(ll) == 12);

    list_push_front(ll, 212);
    assert(list_back(ll) == 12);
    list_clear(ll);
}

void test_pop_front()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 12);
    list_push_front(ll, 13);
    assert(list_front(ll) == 13);

    list_pop_front(ll);
    assert(list_front(ll) == 12);
    list_clear(ll);
}

void test_push_back()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 11);
    list_push_front(ll, 12);
    assert(list_back(ll) == 11);

    list_append(ll, 323);
    assert(list_back(ll) == 323);

    list_clear(ll);
}

void test_pop_back()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 11);
    list_push_front(ll, 12);
    assert(list_back(ll) == 11);

    list_append(ll, 323);
    assert(list_back(ll) == 323);

    list_pop_end(ll);
    assert(list_back(ll) == 11);
    assert(list_size(ll) == 2);
    list_pop_end(ll);
    list_pop_end(ll);
    assert(list_empty(ll));

    list_clear(ll);
}

void test_value_at()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 11);
    list_push_front(ll, 12);

    assert(list_index(ll, 1) == 11);
    assert(list_index(ll, 0) == 12);

    list_clear(ll);
}

void test_insert()
{
    ForwardList *ll = list_new();
    list_insert(ll, 0, 5);
    assert(list_size(ll) == 1);
    assert(list_index(ll, 0) == 5);

    list_insert(ll, 0, 3);
    assert(list_index(ll, 0) == 3);
    assert(list_index(ll, 1) == 5);

    list_insert(ll, 1, 4);
    assert(list_index(ll, 1) == 4);

    list_push_front(ll, 50);
    assert(list_index(ll, 2) == 4);

    list_clear(ll);
}

void test_erase()
{
    ForwardList *ll = list_new();
    list_push_front(ll, 5);
    list_delet_node(ll, 0);
    assert(list_empty(ll));

    list_append(ll, 1);
    list_append(ll, 2);
    list_delet_node(ll, 0);
    assert(list_index(ll, 0) == 2);

    list_append(ll, 3);
    list_delet_node(ll, 1);
    assert(list_index(ll, 0) == 2);

    list_append(ll, 3);
    list_append(ll, 4);
    list_delet_node(ll, 2);
    assert(list_index(ll, 1) == 3);

    list_clear(ll);
}

void test_value_n_from_end()
{
    ForwardList *ll = list_new();

    list_append(ll, 123);
    assert(list_value_n_from_end(ll, 1) == 123);

    list_append(ll, 2);
    list_append(ll, 332);
    list_append(ll, 4);
    list_append(ll, 5645);
    list_append(ll, 63);

    assert(list_value_n_from_end(ll, 4) == 332);
    assert(list_value_n_from_end(ll, 2) == 5645);
    assert(list_value_n_from_end(ll, 6) == 123);

    list_clear(ll);
}

void test_reverse()
{
    ForwardList *ll = list_new();
    list_append(ll, 2);
    list_append(ll, 3);
    list_append(ll, 4);
    list_append(ll, 5);
    list_append(ll, 6);
    list_reverse(ll);

    assert(list_index(ll, 0) == 6);
    assert(list_index(ll, 1) == 5);
    assert(list_index(ll, 2) == 4);
    assert(list_index(ll, 3) == 3);
    assert(list_index(ll, 4) == 2);

    list_clear(ll);
}

void test_reverse_single()
{
    ForwardList *ll = list_new();
    list_append(ll, 2);
    list_reverse(ll);
    assert(list_index(ll, 0) == 2);
    list_clear(ll);
}

void test_reverse_empty()
{
    ForwardList *ll = list_new();
    list_reverse(ll);
    list_clear(ll);
}

void test_remove()
{
    ForwardList *ll = list_new();
    list_append(ll, 2);
    list_append(ll, 4);
    list_append(ll, 6);
    list_remove(ll, 6);
    assert(list_size(ll) == 2);
    assert(list_index(ll, 0) == 2);
    assert(list_index(ll, 1) == 4);
    assert(list_back(ll) == 4);

    list_remove(ll, 2);
    assert(list_size(ll) == 1);
    assert(list_index(ll, 0) == 4);
    list_remove(ll, 4);
    assert(list_empty(ll));
    list_clear(ll);
}
