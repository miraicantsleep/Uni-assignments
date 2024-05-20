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
bool soalPH = false;
bool soalRK = false;
vector<int> urutan;
bool soalFD = false;
int level = 0;

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
            {
                if (soalPH)
                {
                    cout << "L";
                }
                root = root->left;
            }

            else if (value > root->key)
            {
                if (soalPH)
                {
                    cout << "R";
                }
                root = root->right;
            }
            else
            {
                if (soalFD)
                {
                    level++;
                }
                return root;
            }
            if (soalFD)
            {
                level++;
            }
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
            urutan.push_back(root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            // printf("%d ", root->key);
            // level++;
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    string query;
    int value;
    cin >> query;

    while (true)
    {
        if (query == "IN")
        {
            cin >> value;
            set.insert(value);
        }
        else if (query == "PH")
        {
            cin >> value;
            if (set.find(value))
            {
                soalPH = true;
                set.find(value);
                cout << "S\n";
                soalPH = false;
            }
            else
            {
                cout << "no " << value << "\n";
            }
        }
        else if (query == "RK")
        {
            cin >> value;
            soalRK = true;
            set.traverseInorder();
            if (value > urutan.size())
            {
                cout << "-1\n";
            }
            else
            {
                cout << urutan[value - 1] << "\n";
            }
            soalRK = false;
            urutan.clear();
        }
        else if (query == "FD")
        {
            level = 0;
            cin >> value;
            if (set.find(value))
            {
                soalFD = true;
                set.find(value);
                cout << "on level " << level << "\n";
                soalFD = false;
            }
            else
            {
                cout << "no " << value << "\n";
            }
        }

        cin >> query;
        if (query == "STOP")
        {
            cout << "done\n";
            break;
        }
    }
}