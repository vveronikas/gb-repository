#include <iostream>

struct TreeNode
{
    int key;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* treeInsert(TreeNode* t, int data)
{
    TreeNode* newNode = new TreeNode;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    TreeNode* current = new TreeNode;
    current = t;
    TreeNode* parent = new TreeNode;
    current = t;

    if (t == NULL)
        t = newNode;
    else
    {
        while (current->key != data)
        {
            parent = current;
            if (current->key > data) 
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return t;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode* root)
{
    if (root)
    {
        std::cout << root->key;
        if (root->left || root->right)
        {
            std::cout << "(";
            if (root->left)
                printTree(root->left);
            else
                std::cout << "NULL";
            std::cout << ",";
            if (root->right)
                printTree(root->right);
            else
                std::cout << "NULL";
            std::cout << ")";
        }
    }
}

bool binSearch(TreeNode* root, int value)
{
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;

    TreeNode* current = root;
    while (current->key != value)
    {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;
        if (current == NULL)
            return false;
    }
}

int height(TreeNode* t)
{
    if (t == NULL)
        return 0;
    else if (t->left == NULL && t->right == NULL)
        return 0;
    else if (height(t->left) < height(t->right))
        return height(t->right) + 1;
    else
        return height(t->left) + 1;
}

bool isBalanced(TreeNode* t)
{
    if (abs(height(t->left) - height(t->right)) > 1)
        return false;
    else
        return true;

}

int main()
{
    //Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
    //-создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями;
    //-рассчитает, какой процент из созданных деревьев является сбалансированными.

    TreeNode** treeArr = new TreeNode* [50];
    int count = 0;
    for (size_t i = 0; i < 50; i++)
    {
        treeArr[i] = new TreeNode;
        treeArr[i] = NULL;
        for (size_t j = 0; j < 1000; j++)
        {
            treeArr[i] = treeInsert(treeArr[i], rand() % 10);
        }
        printTree(treeArr[i]);
        std::cout << std::endl;
        if (isBalanced(treeArr[i]))
            count++;
    }

    std::cout << count * 100 / 50 << "% of trees is balaneced" << std::endl;
  
   //Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
    TreeNode* binTree = new TreeNode;
    binTree = NULL;
    for (size_t i = 0; i < 10; i++)
    {
        binTree = treeInsert(binTree, rand() % 10);
    }
    printTree(binTree);
    std::cout << std::endl;
    int n = 9;
    if (binSearch(binTree, n))
        std::cout << n << " is found" << std::endl;
    else
        std::cout << n << " is not found" << std::endl;
}

