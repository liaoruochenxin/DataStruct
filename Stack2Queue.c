#include <stdbool.h>
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

typedef struct Queue {
    Stack s1;
    Stack s2;
} Queue;

Queue *QueueInit() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    Init(&queue->s1, 10);
    Init(&queue->s2, 10);
    return queue;
}

void QueuePush(Queue *queue, eleType value) {
    Push(&queue->s1, value);
}

eleType QueuePop(Queue *queue) {
    if (GetSize(&queue->s2) == 0) {
        while (GetSize(&queue->s1)) {
            Push(&queue->s2, Pop(&queue->s1));
        }
    }
    return Pop(&queue->s2);
}

eleType QueuePeek(Queue *queue) {
    if (GetSize(&queue->s2) == 0) {
        while (GetSize(&queue->s1)) {
            Push(&queue->s2, Pop(&queue->s1));
        }
    }
    return Top(&queue->s2);
}

bool QueueIsEmpty(Queue *queue) {
    return GetSize(&queue->s1) == 0 && GetSize(&queue->s2) == 0;
}

void QueueFree(Queue *queue) {
    Destroy(&queue->s1);
    Destroy(&queue->s2);
}

int main() {
    Stack stack;
    Init(&stack, 10);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    printf("栈顶: %d\n", Top(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Size: %d\n", GetSize(&stack));
    Destroy(&stack);
}
