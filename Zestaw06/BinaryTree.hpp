#include <iostream>

class BinaryTree
{
private:
    struct TreeNode
    {
        int key;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root = nullptr;
    int _size = 0;

public:
    ~BinaryTree()
    {
        cleaner(root);
    }

    void insert(int x)
    {
        TreeNode *newNode = new TreeNode;
        newNode->key = x;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr)
        {
            root = newNode;
            _size++;
            return;
        }

        TreeNode *tmp = root;

        while (true)
        {
            if (x < tmp->key)
            {
                if (tmp->left == nullptr)
                {
                    tmp->left = newNode;
                    _size++;
                    return;
                }
                tmp = tmp->left;
            }
            else
            {
                if (tmp->right == nullptr)
                {
                    tmp->right = newNode;
                    _size++;
                    return;
                }
                tmp = tmp->right;
            }
        }
    }

    TreeNode *search(int x)
    {
        TreeNode *tmp = root;

        while (tmp != nullptr)
        {
            if (tmp->key == x)
            {
                return tmp;
            }
            else
            {
                if (x < tmp->key)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
        }

        return nullptr;
    }

    TreeNode *searchRecursive(int x)
    {
        return searchRecursive(this->root, x);
    }

    int size()
    {
        return _size;
    }

    int minimum()
    {
        TreeNode *tmp = root;

        while (tmp->left != nullptr)
            tmp = tmp->left;

        return tmp->key;
    }

    int maximum()
    {
        TreeNode *tmp = root;

        while (tmp->right != nullptr)
            tmp = tmp->right;

        return tmp->key;
    }

    int depth()
    {
        return depth(root);
    }

    void inorder()
    {
        inorder(root);
    }
    void preorder()
    {
        preorder(root);
    }
    void postorder()
    {
        postorder(root);
    }

private:
    TreeNode *searchRecursive(TreeNode *smallRoot, int x)
    {
        if (smallRoot == nullptr)
            return nullptr;

        else if (smallRoot->key == x)
            return smallRoot;

        else
            return (x < smallRoot->key) ? searchRecursive(smallRoot->left, x) : searchRecursive(smallRoot->right, x);
    }

    int depth(TreeNode *tmp)
    {
        if (tmp == nullptr)
            return 0;
        int lDepth = depth(tmp->left) + 1;
        int rDepth = depth(tmp->right) + 1;
        return lDepth < rDepth ? rDepth : lDepth;
    }

    void inorder(TreeNode *tmp)
    {
        if (tmp != nullptr)
        {
            inorder(tmp->left);
            std::cout << tmp->key << std::endl;
            inorder(tmp->right);
        }
    }
    void preorder(TreeNode *tmp)
    {
        if (tmp != nullptr)
        {
            std::cout << tmp->key << std::endl;
            preorder(tmp->left);
            preorder(tmp->right);
        }
    }

    void postorder(TreeNode *tmp)
    {
        if (tmp != nullptr)
        {
            postorder(tmp->left);
            postorder(tmp->right);
            std::cout << tmp->key << std::endl;
        }
    }

    void cleaner(TreeNode *tmp)
    {
        if (tmp != nullptr)
        {
            cleaner(tmp->left);
            cleaner(tmp->right);
            delete tmp;
        }
    }
};