#include <stdio.h>
#include <stdlib.h>

#define eleType int

// 链表节点
typedef struct ListNode {
    eleType elem;
    struct ListNode *next;
} ListNode;

// 单向链表
typedef struct LinkedList {
    struct ListNode *head;
    eleType size;
} LinkedList;

// 创建
void Init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

// 销毁
void Destroy(LinkedList *list) {
    while (list->head) {
        ListNode *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->size = 0;
}

// 新增(往链表的指定位置插入节点)
void Insert(LinkedList *list, int index, eleType value) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->elem = value;
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        ListNode *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// 删除
void Delete(LinkedList *list, int index) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }
    ListNode *current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
    } else {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ListNode *next = current->next->next;
        free(current->next);
        current->next = next;
    }
    list->size--;
}

// 查找元素为value
ListNode *Find(LinkedList *list, int value) {
    ListNode *current = list->head;
    // for (int i = 0; i < list->size; i++) {
    //     if (current->elem == value) {
    //         return i;
    //     }
    //     current = current->next;
    // }
    while (current) {
        if (current->elem == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 获取第index的节点
ListNode *Index(LinkedList *list, int index) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return NULL;
    }
    ListNode *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

// 修改第index个节点的元素
void Edit(LinkedList *list, int index, eleType value) {
    ListNode *node = Index(list, index);
    if (node == NULL) {
        printf("Invalid index\n");
    } else {
        node->elem = value;
    }
}

// 打印链表
void PrintList(LinkedList *list) {
    ListNode *current = list->head;
    while (current) {
        printf("%d ->", current->elem);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    Init(&list);

    Insert(&list, 0, 77);
    Insert(&list, 1, 66);
    Insert(&list, 2, 55);
    Insert(&list, 3, 444);
    PrintList(&list);
    Delete(&list, 2);
    Edit(&list, 1, 33);
    ListNode *node = Find(&list, 77);
    if (node != NULL) {
        printf("%d\n", node->elem);
    } else {
        printf("not found\n");
    }
    PrintList(&list);
    return 0;
}
