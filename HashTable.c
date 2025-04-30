#define maxHashSize 100000
#define eleType int
#define empty -191028223
#include <stdio.h>
int hashArray[maxHashSize];

int hashFunc(eleType value) {
    int x = value % value;
    if (x < 0)
        x += maxHashSize;
    return x;
}

// 初始化
void HashInit() {
    for (int i = 0; i < maxHashSize; ++i) {
        hashArray[i] = empty;
    }
}

// 插入
int HashInsert(eleType value) {
    int index = hashFunc(value);
    while (1) {
        if (hashArray[index] == empty) {
            hashArray[index] = value;
            return index;
        } else if(hashArray[index] == value) {
            return index;
        }
        index += 1;
        if (index > maxHashSize) {
            index = 0;
        }
    }
}

// 删除
int HashDelete(eleType value) {
    int index = hashFunc(value);
    while (1) {
        if (hashArray[index] == empty) {
            return 0;
        } else if (hashArray[index] == value) {
            hashArray[index] = empty;
            return 1;
        }
        index += 1;
        if (index > maxHashSize) {
            index = 0;
        }
    }
}

// 查找
int HashFind(eleType value, int *hasFind) {
    int index = hashFunc(value);
    while (1) {
        if (hashArray[index] == empty) {
            *hasFind = 0;
            return index;
        } else if (hashArray[index] == value) {
            *hasFind = 1;
            return index;
        }
        index += 1;
        if (index > maxHashSize) {
            index = 0;
        }
    }
}

int main() {
    HashInit();
    int x1 = HashInsert(123);
    int x2 = HashInsert (35435);
    int x3 = HashInsert(315435);
    int x4 = HashInsert (353435);
    printf("%d %d %d %d\n",x1,x2,x3,x4);
    HashDelete(123);
    int isFind;
    HashFind(123,&isFind);
    printf("%d\n",isFind);
    return 0;
}
