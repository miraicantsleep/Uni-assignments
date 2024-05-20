/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 *
 * Implementasi untuk Bahasa C++
 */

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

/* Node structure */

struct BSTNode
{
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST
{
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(int value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, int value)
    {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode *__findMinNode(BSTNode *node)
    {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode *__remove(BSTNode *root, int value)
    {
        if (root == NULL)
            return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else
        {

            if (root->left == NULL)
            {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL)
            {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    unordered_map<int, bool> yellow;
    unordered_map<int, bool> purple;
    unordered_map<int, bool> orange;

    int value;
    string color;
    cin >> value >> color;
    while (true)
    {

        if (value == -1 && color == "null")
        {
            string banned;
            cin >> banned;
            if (banned == "yellow")
            {
                for (auto i = yellow.begin(); i != yellow.end(); i++)
                {
                    if (!purple[i->first] && !orange[i->first])
                    {
                        set.remove(i->first);
                    }
                }
            }
            else if (banned == "purple")
            {
                for (auto i = purple.begin(); i != purple.end(); i++)
                {
                    if (!yellow[i->first] && !orange[i->first])
                    {
                        set.remove(i->first);
                    }
                }
            }
            else if (banned == "orange")
            {
                for (auto i = orange.begin(); i != orange.end(); i++)
                {
                    if (!purple[i->first] && !yellow[i->first])
                    {
                        set.remove(i->first);
                    }
                }
            }
            break;
        }
        else
        {
            set.insert(value);
            if (color == "yellow")
            {
                yellow[value] = true;
            }
            else if (color == "purple")
            {
                purple[value] = true;
            }
            else if (color == "orange")
            {
                orange[value] = true;
            }
        }
        cin >> value >> color;
    }

    cout << "Preorder : ";
    set.traversePreorder();
    cout << endl;
    cout << "Inorder : ";
    set.traverseInorder();
    cout << endl;
    cout << "Postorder : ";
    set.traversePostorder();
    cout << endl;
    return 0;
}