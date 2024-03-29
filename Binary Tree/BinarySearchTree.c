#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTree BinaryTree;

struct BinaryTree
{
  int item;
  BinaryTree *left;
  BinaryTree *right;
};

int is_empty(BinaryTree *tree)
{
  return (tree == NULL);
}

BinaryTree* create_empty_binary_tree()
{
  return NULL;
}

BinaryTree* create_binary_tree(int item, BinaryTree *left, BinaryTree *right)
{
  BinaryTree *new_binary_tree = (BinaryTree *) malloc(sizeof(BinaryTree));
  new_binary_tree -> item = item;
  new_binary_tree -> left = left;
  new_binary_tree -> right = right;
  return new_binary_tree;
}

void print_preorder(BinaryTree *tree)
{
  if(!is_empty(tree))
  {
    printf("%d\n", tree -> item);
    print_preorder(tree -> left);
    print_preorder(tree -> right);
  }
}

void print_postorder(BinaryTree *tree)
{
    if(!is_empty(tree))
    {
        print_postorder(tree -> left);
        print_postorder(tree -> right);
        printf("%d\n", tree -> item);
    }
}

void print_inorder(BinaryTree *tree)
{
    if(!is_empty(tree))
    {
        print_inorder(tree -> left);
        printf("%d\n", tree -> item);
        print_inorder(tree -> right);
    }
}

BinaryTree* search(BinaryTree *tree, int item)
{
  if(tree == NULL || tree -> item == item)
    return tree;
  else if(tree -> item > item)
    return search(tree -> left, item);
  else if(tree -> item < item)
    return search(tree -> right, item);
}

BinaryTree* add(BinaryTree *tree, int item)
{
  if(tree == NULL)
    tree = create_binary_tree(item, NULL, NULL);
  else if(tree -> item > item)
    tree -> left = add(tree -> left, item);
  else
    tree -> right = add(tree -> right, item);
  return tree;
}

void remove_leaf(BinaryTree *tree, int item)
{
  if(tree -> item == item)
    free(tree);
  else if(tree -> item > item)
    remove_leaf(tree -> left, item);
  else if(tree -> item < item)
    remove_leaf(tree -> right, item);
}

int main()
{
  BinaryTree *tree = create_empty_binary_tree();
  //tree = create_binary_tree(2, create_binary_tree(1, NULL, NULL), create_binary_tree(3, NULL, NULL));
  //print_postorder(tree);
  //print_inorder(tree);
  tree = add(tree, 5);
  tree = add(tree, 3);
  tree = add(tree, 7);
  print_inorder(tree);
  remove_leaf(tree, 7);
  print_inorder(tree);
  return 0;
}