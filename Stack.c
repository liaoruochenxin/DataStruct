#include <stdio.h>
#include <stdlib.h>

#define eleType int

// 定义栈结构
typedef struct {
    eleType *element;
    size_t size;
    size_t capicity;
} Stack;

//初始化
void Init(Stack *stack, int capicity) {
    stack->element = (int *) malloc(sizeof(int) * capicity);
    stack->size = 0;
    stack->capicity = capicity;
}

// 销毁
void Destroy(Stack *stack) {
    if (stack->element != NULL) {
        free(stack->element);
        stack->element = NULL;
        stack->size = 0;
        stack->capicity = 0;
    } else {
        printf("Stack is not be inited\n");
    }
}

// 扩容
void StackResize(Stack *stack) {
    eleType *new_stack = (eleType *) realloc(stack->element, sizeof(eleType) * stack->capicity * 2);
    stack->element = new_stack;
    stack->capicity *= 2;
}

// 入栈
void Push(Stack *stack, eleType element) {
    if (stack->size == stack->capicity) {
        StackResize(stack);
    }
    stack->element[stack->size++] = element;
}

// 出栈
eleType Pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is under flow\n");
        exit(1);
    }
    return stack->element[--stack->size];
}

// 获取栈顶元素
eleType Top(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->element[stack->size - 1];
}

// 获取元素个数
int GetSize(Stack *stack) {
    return stack->size;
}

int main() {
    Stack stack;
    Init(&stack, 10);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    printf("Top: %d\n", Top(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Size: %d\n", GetSize(&stack));
    Destroy(&stack);
}
