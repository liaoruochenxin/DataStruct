#include <stdio.h>
#include <stdlib.h>

//��ʾ��������û�б�
#define inf -1;

typedef struct Graph {
    // ͼ��������
    int vertices;
    // ��ά�������ڴ洢����
    int **edges;
} Graph;

//����
void GraphCreate(Graph *g, int vertices) {
    g->vertices = vertices;
    g->edges = malloc(sizeof(int *) * vertices);
    for (int i = 0; i < vertices; i++) {
        g->edges[i] = malloc(sizeof(int) * vertices);
        for (int j = 0; j < vertices; j++) {
            g->edges[i][j] = inf;
        }
    }
}

// ����
void GraphDestory(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    g->edges = NULL;
}

// �ߵ����
void GraphAddEdge(Graph *g, int u, int v, int w) {
    g->edges[u][v] = w;
}

// ��ӡ
void GraphPrint(Graph *g) {
    for (int i = 0; i < g->vertices; ++i) {
        for (int j = 0; j < g->vertices; ++j) {
            printf("%d ", g->edges[i][j]);
        }
    }
}

int main() {
    Graph graph;
    GraphCreate(&graph, 5);
    GraphAddEdge(&graph, 0, 1, 1);
    GraphAddEdge(&graph, 0, 2, 3);
    GraphAddEdge(&graph, 1, 2, 2);
    GraphAddEdge(&graph, 2, 3, 7);
    GraphAddEdge(&graph, 3, 4, 9);
    GraphAddEdge(&graph, 4, 0, 4);
    GraphAddEdge(&graph, 4, 2, 5);
    printf("�ڽӾ����ʾ��ͼ��\n");
    GraphPrint(&graph);
    GraphDestory(&graph);
    return 0;
}
