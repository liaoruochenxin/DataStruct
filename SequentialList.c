#include <stdio.h>
#include <stdlib.h>

// 定义顺序表结构
typedef struct {
    int *element;
    size_t size;
    size_t capicity;
} SequentialList;
//初始化
void Init(SequentialList *list, int capicity) {
    list->element = (int*)malloc(sizeof(int)*capicity);
    list->size=0;
    list->capicity=capicity;
}
// 销毁
void Destroy(SequentialList *list) {
    if (list->element != NULL) {
        free(list->element);
        list->element = NULL;
    }
}
// 获取元素数量
size_t SequentialListSize(const SequentialList *list) {
    return list->size;
}
// 新增
void Insert(SequentialList *list, int num, int index) {
    // 索引检查
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
    }
    //
    if (list->size == list->capicity) {
        int *newElement = (int*)realloc(list->element, sizeof(int)*2*list->capicity);
        if (newElement == NULL) {
            printf("Failed to realloc memory\n");
            return;
        }
        list->element = newElement;
        list->capicity *= 2;
    }

    for (size_t i = list->size; i > index; i--) {
        list->element[i] = list->element[i-1];
    }
    list->element[index] = num;
    list->size++;
}

// 删除
void Delete(SequentialList *list, int index) {
    // 索引检查
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
    }
    for (int i = index; i < list->size; i++) {
        list->element[i] = list->element[i+1];
    }
    list->size--;
}

// 查找
int Find(const SequentialList *list, int num) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->element[i] == num) {
            return i;
        }
    }
    return -1;
}

// 获取对应索引处的值
int Index(const SequentialList *list, int index) {
    // 索引检查
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
    }
    return list->element[index];
}

// 修改
void Edit(SequentialList *list, int num, int index) {
    // 索引检查
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
    }
    list->element[index] = num;
}

int main() {
    SequentialList sequential_list;
    Init(&sequential_list, 10);
    Insert(&sequential_list, 77, 0);
    Insert(&sequential_list, 128, 1);
    Insert(&sequential_list, 1114, 2);
    printf("where is 77: %d\n", Find(&sequential_list, 77));
    printf("index2%d\n", Index(&sequential_list, 2));
    Edit(&sequential_list, 66, 0);
    printf("where is 77: %d\n", Find(&sequential_list, 77));
    Delete(&sequential_list, 2);
    Index(&sequential_list, 2);
    Destroy(&sequential_list);
    return 0;
}