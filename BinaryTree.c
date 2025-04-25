#include <stdio.h>
#include <stdlib.h>

#define eleType char

// 树节点结构
typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    eleType data;
} TreeNode;

// 树结构
typedef struct Tree {
    TreeNode *nodes;
    TreeNode *root;
    size_t nodeSize;
} Tree;

// 二叉树创建
void TreeInit(Tree *tree, int size) {
    tree->nodes = malloc(sizeof(TreeNode) * size);
    tree->root = NULL;
    tree->nodeSize = size;
}

// 二叉树销毁
void TreeDestory(Tree *tree) {
    free(tree->nodes);
    tree->nodes = NULL;
    tree->root = NULL;
    tree->nodeSize = 0;
}

// 获取二叉树节点
TreeNode *TreeGetNode(Tree *tree, int index) {
    if (index > tree->nodeSize) {
        printf("error");
    }
    return &tree->nodes[index];
}

//访问节点
void Visit(TreeNode *tree_node) {
    printf("%c\n", tree_node->data);
}

// 二叉树初始化
TreeNode *createRecursively(Tree *tree, eleType a[], int size, int nodeId, eleType nullNode) {
    if (nodeId > size || a[nodeId] == nullNode) {
        return NULL;
    }
    TreeNode *nowNode = TreeGetNode(tree, nodeId);
    nowNode->data = a[nodeId];
    nowNode->left = createRecursively(tree, a, size, nodeId * 2, nullNode);
    nowNode->right = createRecursively(tree, a, size, nodeId * 2 + 1, nullNode);
    return nowNode;
}

void TreeCreate(Tree *tree, eleType a[], int size, eleType nullNode) {
    createRecursively(tree, a, size, 1, nullNode);
}

// 前序遍历
void preOrder(Tree *tree, TreeNode *tree_node) {
    if (tree_node) {
        Visit(tree_node);
        preOrder(tree, tree_node->left);
        preOrder(tree, tree_node->right);
    }
}

void TreePreOrderTraversal(Tree *tree) {
    preOrder(tree, tree->root);
}

//中序遍历
void inOrder(Tree *tree, TreeNode *tree_node) {
    if (tree_node) {
        inOrder(tree, tree_node->left);
        Visit(tree_node);
        inOrder(tree, tree_node->right);
    }
}
void TreeInOrderTraversal(Tree *tree) {
    inOrder(tree, tree->root);
}

//后序遍历
void postOrder(Tree *tree, TreeNode *tree_node) {
    if (tree_node) {
        postOrder(tree, tree_node->left);
        postOrder(tree, tree_node->right);
        Visit(tree_node);
    }
}
void TreePostOrderTraversal(Tree *tree) {
    postOrder(tree, tree->root);
}