#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;

struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
    struct Tree* parent;
};


Tree* root_create(int value);
Tree* tree_add_element(Tree* root, int father,  int value);
void delete_node_interface(Tree **root, int value);
void destroy(Tree *tree);
void tree_print(Tree* t, int n);
Tree* search_in_tree(Tree* t, int value);

Tree *root_create(int value)
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->data = value;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;
    return tree;
}

// печать дерева
void tree_print(Tree *root, int n)
{
    if (root != NULL)
    {
        tree_print(root->right, n + 1);
        for (int i = 0; i < n; i++)
            printf("\t");
        printf("%d\n", root->data);
        tree_print(root->left, n + 1);
    }
}

// добавление узла в дерево
Tree *tree_add_element(Tree *root, int father, int value)
{
    if (root == NULL)
    {
        return root_create(value);
    }
    Tree *tree2 = root;
    Tree *father_tree = search_in_tree(tree2, father);
    if (father_tree == NULL)
    {
        printf("Такого отца нет!\n");
        return root;
    }
    Tree *NewTree = (Tree *)malloc(sizeof(Tree));
    NewTree->data = value;
    NewTree->left = NULL;
    NewTree->right = NULL;
    if (father_tree->left == NULL && father_tree->right != NULL)
    {
        NewTree->parent = father_tree;
        father_tree->left = NewTree;
    }
    else if (father_tree->left != NULL && father_tree->right == NULL)
    {
        NewTree->parent = father_tree;
        father_tree->right = NewTree;
    }
    else if (father_tree->left == NULL && father_tree->right == NULL)
    {
        NewTree->parent = father_tree;
        father_tree->left = NewTree;
    }
    else if (father_tree->left != NULL && father_tree->right != NULL)
    {
        printf("У этого отца уже есть 2 сына, укажите другого\n");
        return root;
    }
    return root;
}

//функция поиска
Tree *search_in_tree(Tree *tree, int value)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->data == value)
    {
        return tree;
    }
    Tree *finder = NULL;
    if (tree->left != NULL)
    {
        finder = search_in_tree(tree->left, value);
        if (finder != NULL)
        {
            return finder;
        }
    }
    if (tree->right != NULL)
    {
        finder = search_in_tree(tree->right, value);
    }
    return finder;
}

// удаление узла в дереве
void delete_node_interface(Tree **root, int value)
{
    Tree *srch = search_in_tree(*root, value);
    if(srch == NULL){
        printf("А такого у нас нет..\n");
        return;
    }
    Tree *prnt = srch->parent;
    int delleft = 0;
    if (prnt == NULL)
    {
        destroy(*root);
        *root = NULL;
        return;
    }
    Tree *tree1 = prnt->left;
    if (tree1->data == value)
        delleft = 1;
    destroy(srch);
    if (delleft)
        prnt->left = NULL;
    else
        prnt->right = NULL;
}

// удаление
void destroy(Tree *tree)
{
    if (tree->left != NULL)
    {
        destroy(tree->left);
    }
    if (tree->right != NULL)
    {
        destroy(tree->right);
    }
    free(tree);
    tree = NULL;
}

// Определить уровень дерева, на котором максимальное количество вершин
int task_var34(Tree *root)
{
    if (root == NULL)
    {
        printf("Дерево ещё не посажено\n");
        return 0;
    }
    int maxlevel = 0;
    int maxWidth = 0;
    int width;
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if (width > maxWidth)
        {
            maxWidth = width;
            maxlevel = i;
        }
    }
    return maxlevel;
}

// ширина заданного уровня
int getWidth(Tree *tree, int level)
{
    if (tree == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
    {
        return getWidth(tree->left, level - 1) + getWidth(tree->right, level - 1);
    }
}

// вычисление высоты дерева
int height(Tree *tree)
{
    if (tree == NULL)
        return 0;
    else
    {
        int lHeight = height(tree->left);
        int rHeight = height(tree->right);
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}

#endif // TREE_H_INCLUDED
