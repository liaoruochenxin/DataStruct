#include <stdio.h>
#include <stdlib.h>

#define eleType char

struct TreeNode;

// 子节点结构
typedef struct ListNode {
    struct TreeNode *data;
    struct ListNode *next;
} ListNode;

// 树节点结构
typedef struct TreeNode {
    eleType data;
    ListNode *childHead;
} TreeNode;

// 添加树边操作
void AddTreeChild(TreeNode *parent, TreeNode *child) {
    ListNode *childNode = malloc(sizeof(ListNode));
    childNode->next = NULL;
    childNode->data = child;

    if (parent->childHead == NULL) {
        parent->childHead = childNode;
    } else {
        childNode->next = parent->childHead;
        parent->childHead = childNode;
    }
}

// 树结构
typedef struct Tree {
    TreeNode *nodes;
    TreeNode *root;
} Tree;

// 树初始化
void TreeCreate(Tree *tree, int size) {
    tree->nodes = malloc(sizeof(TreeNode) * size);
    tree->root = NULL;

    for (int i = 0; i < size; i++) {
        tree->nodes[i].childHead = NULL;
    }
}

// 树销毁
void TreeDestory(Tree *tree) {
    free(tree->nodes);
    tree->nodes = NULL;
    tree->root = NULL;
}

// 按照索引获取树节点
TreeNode *GetTreeNode(Tree *tree, int index) {
    return &tree->nodes[index];
}

// 设置根节点
void TreeSetRoot(Tree *tree, int index) {
    tree->root = GetTreeNode(tree, index);
}

// 设置树边
void TreeAddChild(Tree *tree, int parentIndex, int childIndex) {
    TreeNode *parent = GetTreeNode(tree, parentIndex);
    TreeNode *child = GetTreeNode(tree, childIndex);
    AddTreeChild(parent, child);
}

// 设置树节点值
void TreeAssignData(Tree *tree, int index, eleType data) {
    TreeNode *tree_node = GetTreeNode(tree, index);
    tree_node->data = data;
}

// 深度优先遍历
void TreePrint(Tree *tree, TreeNode *node) {
    if (node == NULL) {
        node = tree->root;
    }
    printf("%c", node->data);
    ListNode *tmp = node->childHead;
    while (tmp) {
        TreePrint(tree, tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Tree T;
    TreeCreate(&T, 9);
    TreeSetRoot(&T, 0);
    TreeAssignData(&T, 0, 'a');
    TreeAssignData(&T, 1, 'b');
    TreeAssignData(&T, 2, 'c');
    TreeAssignData(&T, 3, 'd');
    TreeAssignData(&T, 4, 'e');
    TreeAssignData(&T, 5, 'f');
    TreeAssignData(&T, 6, 'g');
    TreeAssignData(&T, 7, 'h');
    TreeAssignData(&T, 8, 'i');
    TreeAddChild(&T, 0, 2);
    TreeAddChild(&T, 0, 1);
    TreeAddChild(&T, 1, 3);
    TreeAddChild(&T, 2, 5);
    TreeAddChild(&T, 2, 4);
    TreeAddChild(&T, 3, 8);
    TreeAddChild(&T, 3, 7);
    TreeAddChild(&T, 3, 6);
    TreePrint(&T, T.root);
    return 0;
}
