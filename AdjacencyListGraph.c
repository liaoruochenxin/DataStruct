#include <stdio.h>
#include <stdlib.h>

// 边节点
typedef struct EdgeNode {
    int vertex; // 结尾顶点
    int weight; // 权重
    struct EdgeNode *next; // 下一个边节点
} EdgeNode;

// 顶点节点
typedef struct VertexNode {
    int vertex; // 该顶点索引
    EdgeNode *firstEdge; // 该顶点的第一个边节点
} VertexNode;

// 图结构
typedef struct Graph {
    int vertices; // 图的顶点数量
    VertexNode *nodes; // 图的顶点信息
} Graph;

// 创建
void GraphCreate(Graph *g, int vertices) {
    g->vertices = vertices;
    g->nodes = malloc(sizeof(Graph) * vertices);
    for (int i = 0; i < vertices; ++i) {
        g->nodes[i].vertex = i;
        g->nodes[i].firstEdge = NULL;
    }
}

// 销毁
void GraphDestroy(Graph *g) {
    for (int i = 0; i < g->vertices; ++i) {
        EdgeNode *curr = g->nodes[i].firstEdge;
        while (curr) {
            EdgeNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    g->vertices = 0;
    free(g->nodes);
    g->nodes = NULL;
}

/**
 * 边创建
 * @param g 图
 * @param u 起始节点索引
 * @param v 结尾节点索引
 * @param w 权重
 */
void GraphAddEdge(Graph *g, int u, int v, int w) {
    EdgeNode *edge_node = malloc(sizeof(EdgeNode));
    edge_node->vertex = v;
    edge_node->weight = w;
    // VertexNode *vertex_node = &g->nodes[u];
    // edge_node->next = vertex_node->firstEdge;
    // vertex_node->firstEdge = edge_node;
    edge_node->next = g->nodes[u].firstEdge;
    g->nodes[u].firstEdge = edge_node;
}

// 打印
void GraphPrint(Graph *g) {
    for (int i = 0; i < g->vertices; ++i) {
        printf("%d ", g->nodes[i].vertex);
        EdgeNode *edge_node = g->nodes[i].firstEdge;
        while (edge_node) {
            printf("%d ", edge_node->vertex);
            edge_node = edge_node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    GraphCreate(&g, 5);
    GraphAddEdge(&g, 0, 1, 4);
    GraphAddEdge(&g, 0, 2, 2);
    GraphAddEdge(&g, 1, 2, 3);
    GraphAddEdge(&g, 2, 3, 4);
    GraphAddEdge(&g, 3, 4, 2);
    GraphPrint(&g);
    GraphDestroy(&g);
    return 0;
}
