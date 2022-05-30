//  BST.cpp
//  Binary Search Tree implement
//  Author is Mei
//  Created by Mei on 10.06.17.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct bst_node_t {
  int value;                    // data;
  struct bst_node_t* left;      // left child;
  struct bst_node_t* right;     // right child;
} bst_node;

// Inserts the given value into the (sub)tree rooted by node.
bst_node* insert(bst_node* node, const int value);
// Outputs the values stored in the tree rooted by node.
void print_tree(bst_node* node);
// Returns the number of nodes stored in the tree
int get_node_count(bst_node* node);
// Deletes all nodes in tree, freeing their memory
void delete_tree(bst_node* node);
// Returns true if given value is in the tree
bool is_in_tree(bst_node* node, int value);
// Returns the height of the tree in nodes, 0 if empty
int get_height(bst_node* node);
// Returns the greater of 2 values
int max_num(int, int);
// Returns the minimum value in the tree, 0 if empty
int get_min(bst_node* node);
// Returns the maximum value in the tree, 0 if empty
int get_max(bst_node* node);
// Returns true if given node is root of a binary search tree
bool is_binary_search_tree(bst_node* node);
// Returns true if the node's value is between a min and max
bool is_between(bst_node* node, int min, int max);
// Deletes the given value from the tree
bst_node* delete_value(bst_node* node, int value);
// Returns the node containing the minimum value in the tree rooted by the given
// node.
void get_min_node(bst_node* node);
// Returns next-highest value in tree after given value, -1 if none
int get_successor(bst_node* node, int value);

int main(int argc, char*argv[])
{
    const int arr_size = 10;
    int arr[arr_size] = {4, 12, 162, 0, 3, 11, 16, 5, 2, 32};

    bst_node* root = NULL;

    for(int i = 0; i < arr_size; i++)
        root = insert(root, arr[i]);

    if(!is_binary_search_tree(root))
    {
        printf("Error!\n");
        return 0;
    }

    printf("BST contains %d nodes.\n", get_node_count(root));
    // BST contains 10 nodes.
    printf("The height of the BST is %d.\n", get_height(root));
    // The height of the BST is 5.
    printf("sort: ");
    print_tree(root); // 0 2 3 4 5 11 12 16 32 162
    printf("\n");

    printf("%d is the minimum.\n", get_min(root));
    // 2 is the minimum in the array.

    printf("%d is the maximum.\n", get_max(root));
    // 32 is the maximum in the array

    printf("%d is left child of %d.\n", get_successor(root, 2), 2);
    // 2 is left child of 3

    delete_tree(root);

    return 0;
}// end main
//*********************************************************************************/

bst_node* insert(bst_node* node, const int value)
{
    if(node == 0)
    {
        bst_node* new_node = (bst_node*) malloc(sizeof(bst_node));
        assert(new_node);

        new_node->value = value;
        new_node->left = 0;
        new_node->right = 0;

        node = new_node;
        return node;
    }

    if(value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else if(value > node->value)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

void print_tree(bst_node* node)
{
    if(node == NULL)
        return;

    print_tree(node->left);
    printf("%d ", node->value);
    print_tree(node->right);
}

int get_node_count(bst_node* node)
{
    if(node == NULL)
        return 0;

    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void delete_tree(bst_node* node)
{
    if(node == NULL)
        return;

    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
}

bool is_in_tree(bst_node* node, int value)
{
    if(node == NULL)
        return false;

    if(value < node->value)
    {
        return is_in_tree(node->left, value);
    }
    else if(value > node->value)
    {
        return is_in_tree(node->right, value);
    }
    else
        return true;
}

int max_num(int val1, int val2)
{
    if(val1 >= val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

int get_height(bst_node* node)
{
    if(node == NULL)
        return 0;

    return 1 + max_num(get_height(node->left), get_height(node->right));
}

int get_min(bst_node* node)
{
    if(node == NULL)
        return 0;

    bst_node* current = node;

    while(current->left != NULL)
    {
        current = current->left;
    }

    return current->value;
}

int get_max(bst_node* node)
{
    if(node == NULL)
    {
        return 0;
    }

    bst_node* current = node;

    while(current->right != NULL)
    {
        current = current->right;
    }

    return current->value;
}

bool is_between(bst_node* node, int min, int max)
{
    if(node == NULL)
        return true;
    // ensure subtrees are not hiding a value lower or higher than the subtree
    // allows
    return node->value > min && node->value < max && is_between(node->left, min, node->value) && is_between(node->right, node->value, max);
}

bool is_binary_search_tree(bst_node* node)
{
    if(node == NULL)
        return true;

    return is_between(node, INT_MIN, INT_MAX);
}

bst_node* delete_value(bst_node* node, int value)
{
    if(node == NULL)
        return node;

    if(value < node->value)
    {
        node->left = delete_value(node->left, value);
    }
    else if(value > node->value)
    {
        node->right = delete_value(node->right, value);
    }
    else
    {
        // found value
        if(node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
        }
        else if(node->left == NULL)
        {
            bst_node* temp = node;
            node = node->right;
            free(temp);
        }
        else if(node->right == NULL)
        {
            bst_node* temp = node;
            node = node->left;
            free(temp);
        }
        else
        {
            // 2 children -- get min node of right subtree
            int right_min = get_min(node->right);
            node->value = right_min;
            node->right = delete_value(node->right, right_min);
        }
    }
    return node;
}

int get_successor(bst_node* node, int value)
{
    if(node == NULL)
        return -1;

    bst_node* target = node;

    while(target->value != value)
    {
        if(value < target->value)
            target = target->left;
        else if(value > target->value)
            target = target->right;
    }

    // arrived at target node
    if(target->right != NULL)
    {
        // get min value of right subtree
        return get_min(target->right);
    }
    else
    {
        // get lowest ancestor that is a left child in the path to target value
        bst_node* successor = NULL;
        bst_node* ancestor = node;
        while(ancestor != NULL)
        {
            if(value < ancestor->value)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor->value;
    }
}
