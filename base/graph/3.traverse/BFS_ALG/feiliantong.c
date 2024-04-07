#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX 100

struct AdjNode{
    int index;
    struct AdjNode *next;
};

struct VexNode{
    char node;
    struct AdjNode *first;
};

struct AlgGraph{
    int vex_num, edge_num;
    struct VexNode Vex[MAX];

};

struct AlgGraph * CreateAlgGraph(void);
int search_vex(struct AlgGraph *graph, char c);
void create_adj_node_list(struct AlgGraph *graph, int i, int j);
void ShowAlgGraph(struct AlgGraph *graph);
void BFS_ALG(struct AlgGraph *graph);

int main(void){
    struct AlgGraph *graph;
    graph = CreateAlgGraph();
    ShowAlgGraph(graph);

    printf("Traverse the graph through BFS:\n");
    BFS_ALG(graph);




    return 0;
}

struct AlgGraph * CreateAlgGraph(void){
    struct AlgGraph *graph;
    char u, v;
    int i, j;
    graph = (struct AlgGraph*)malloc(sizeof(struct AlgGraph));
    printf("Please enter the number of vex: ");
    scanf("%d", &graph->vex_num);
    printf("Please enter the number of edge: ");
    scanf("%d", &graph->edge_num);
    while (getchar() != '\n');

    //node list init
    printf("Please enter vex\n");
    for(int i = 0; i < graph->vex_num; i++) {
        graph->Vex[i].node = getchar();
         while (getchar() != '\n');
    }
    for(int i = 0; i < graph->vex_num; i++) {
        for(int j = 0; j < graph->vex_num; j++)
            graph->Vex[i].first = NULL;
    }

    while (graph->edge_num--) {
        printf("Please enter edge that connect each other by edge\n");
        u = getchar();
        while (getchar() != '\n');
        v = getchar();
        while (getchar() != '\n');

        i = search_vex(graph, u);
        j = search_vex(graph, v);
        //directed graph
        if(i != -1 && j != -1) {
            create_adj_node_list(graph, i, j);
        }
        //undirected graph
        // if(i != -1 && j != -1) {
        //     create_adj_node_list(graph, i, j);
        //     create_adj_node_list(graph, j, i);

        // }
        else 
        {
            printf("You have entered wrong edge: please enter again!!!");
            graph->edge_num ++;
        }
    }
    


    return graph;
}


int search_vex(struct AlgGraph *graph, char c) {
    int i;
    for(int j = 0; i < graph->vex_num; i++) {
        if(c == graph->Vex[j].node)
            return i;
    }
    return -1;
}

void create_adj_node_list(struct AlgGraph *graph, int i, int j){
    struct AdjNode *s = (struct AdjNode *)malloc(sizeof(struct AdjNode));
    s->index = j;
    s->next = graph->Vex[i].first;
    graph->Vex[i].first = s;
}

void ShowAlgGraph(struct AlgGraph *graph){
    struct AdjNode *t;
    printf("Show the Alg Graph:\n");
    for (int i = 0; i < graph->vex_num; i++) {
        printf("%c: ", graph->Vex[i].node);
        t = graph->Vex[i].first;
        while (t != NULL)
        {
            printf("%d ", t->index);
            t = t->next;
        }
        printf("\n");
    }
}

void BFS_ALG(struct AlgGraph *graph){
    int visited[MAX] = {0};
    int u;
    struct AdjNode *p;
    int i = 0;
    for(i; i < graph->vex_num; i++) {
        if (visited[i] == 0) {
            printf("%c ", graph->Vex[i].node);
            visited[i] = 1;
            enqueue(i);
            while(!isempty()) {
                u = dequeue();
                p = graph->Vex[u].first;
                while(p != NULL)
                {
                    if(visited[p->index] == 0) {
                        printf("%c ", graph->Vex[p->index].node);
                        enqueue(p->index);
                        visited[p->index] = 1;
                        p = p->next;
                    }
                }
            }
        }
    }
}

