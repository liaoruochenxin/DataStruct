#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct Node {
    eleType data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

// ��������
void Init(Queue *queue) {
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

// ����
void Destroy(Queue *queue) {
    while (queue->front) {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    queue->rear = NULL;
    queue->size = 0;
}

// ���
void Push(Queue *queue, eleType value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = value;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// ����
eleType Pop(Queue *queue) {
    if (queue->front == NULL) {
        printf("queue is empty");
        exit(1);
    }
    Node *temp = queue->front;
    eleType res = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (queue->size == 0) {
        queue->rear = NULL;
    }
    return res;
}

// ��ȡ����
eleType Front(Queue *queue) {
    if (queue->front == NULL) {
        printf("queue is empty");
        exit(1);
    }
    return queue->front->data;
}

// ��ȡ���д�С
size_t Size(Queue *queue) {
    return queue->size;
}

int main() {
    Queue queue;
    Init(&queue);
    Push(&queue, 1);
    Push(&queue, 2);
    Push(&queue, 3);
    printf("����Ԫ��: %d\n", Pop(&queue));
    printf("����Ԫ��: %d\n", Front(&queue));
    printf("���д�С: %zu\n", Size(&queue));
}