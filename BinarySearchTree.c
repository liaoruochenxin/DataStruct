#include <stdio.h>
#include <stdlib.h>

#define eleType int
#define bool int

// 树节点结构
typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    eleType data;
} TreeNode;

// 二叉搜索树结构体
typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

// 创建
void BSTCreate(BinarySearchTree *tree) {
    tree->root = NULL;
}

// 节点删除
void BSTRemove(BinarySearchTree *tree, eleType value);

void BSTDestory(BinarySearchTree *tree) {
    while (tree->root) {
        BSTRemove(tree, tree->root->data);
    }
}

TreeNode *insertNode(BinarySearchTree *tree, TreeNode *node, eleType value) {
    if (node == NULL) {
        TreeNode *tn = malloc(sizeof(TreeNode));
        tn->data = value;
        tn->left = NULL;
        tn->right = NULL;
        return tn;
    }
    if (value < node->data) {
        node->left = insertNode(tree, node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(tree, node->right, value);
    }
    return node;
}

void BSTInsert(BinarySearchTree *tree, eleType value) {
    tree->root = insertNode(tree, tree->root, value);
}

// 节点删除
TreeNode *removeNode(BinarySearchTree *tree, TreeNode *node, eleType value) {
    if (node == NULL) {
        return NULL;
    }
    if (value < node->data) {
        node->left = removeNode(tree, node->left, value);
    } else if (value > node->data) {
        node->right = removeNode(tree, node->right, value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
            return NULL;
        } else if (node->left == NULL) {
            TreeNode *rightChild = node->right;
            free(node);
            node = rightChild;
            return node;
        } else if (node->right == NULL) {
            TreeNode *leftChild = node->left;
            free(node);
            node = leftChild;
            return node;
        } else {
            TreeNode *replacement = node->right;
            while (replacement->left) {
                replacement = replacement->left;
            }
            node->data = replacement->data;
            node->right = removeNode(tree, node->right, replacement->data);
        }
    }
    return node;
}

void BSTRemove(BinarySearchTree *tree, eleType value) {
    tree->root = removeNode(tree, tree->root, value);
}

// 节点查找
bool searchNode(BinarySearchTree *tree, TreeNode *node, eleType value) {
    if (node == NULL) {
        return 0;
    }
    if (value < node->data) {
        return searchNode(tree, node->left, value);
    } else if (value > node->data) {
        return searchNode(tree, node->right, value);
    }
    return 1;
}

bool BSTSearch(BinarySearchTree *tree, eleType value) {
    return searchNode(tree, tree->root, value);
}

// 中序遍历
void inOrder(BinarySearchTree *tree, TreeNode *node) {
    if (node) {
        inOrder(tree, node->left);
        printf("%d", node->data);
        inOrder(tree, node->right);
    }
}

void BSTInOrder(BinarySearchTree *tree) {
    inOrder(tree, tree->root);
}

int main() {
    BinarySearchTree bst;
    BSTCreate(&bst);
    BSTInsert(&bst, 50);
    BSTInsert(&bst, 30);
    BSTInsert(&bst, 70);
    BSTInsert(&bst, 40);
    BSTInsert(&bst, 80);
    BSTInsert(&bst, 60);
    BSTInsert(&bst, 100);
    printf("中序遍历：");
    BSTInOrder(&bst);
    printf("查找100:%d\n", BSTSearch(&bst, 100));
    printf("查找5l:%dn", BSTSearch(&bst, 51));
    BSTRemove(&bst, 70);
    printf("中序遍历：");
    BSTInOrder(&bst);
    BSTInsert(&bst, 65);
    printf("中序遍历：");
    BSTInOrder(&bst);
}
