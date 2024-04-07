#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct AmgGraph{
    int vex_num, edge_num;
    char Vex[MAX];
    int Edge[MAX][MAX];
};
struct AmgGraph* Create_AMG_Graph(void);
void ShowAmgGraph(struct AmgGraph *graph);
int search_vex(struct AmgGraph *graph, char c);
int main(){

    struct AmgGraph *ud_graph;
    ud_graph = Create_AMG_Graph();
    ShowAmgGraph(ud_graph);
    return 0;
}


struct AmgGraph* Create_AMG_Graph(void){

    struct AmgGraph *graph;
    char u,v;
    int i, j;
    graph = (struct AmgGraph *)malloc(sizeof(struct AmgGraph));
    printf("Please enter the number of vex: ");
    scanf("%d", &graph->vex_num);
    printf("Please enter the number of edge: ");
    scanf("%d", &graph->edge_num);
    while (getchar() != '\n');

    for(int i = 0; i < graph->vex_num; i++) {
        graph->Vex[i] = getchar();
         while (getchar() != '\n');

    }
    for(int i = 0; i < graph->vex_num; i++) {
        for(int j = 0; j < graph->vex_num; j++)
            graph->Edge[i][j] = 0;
    }
    while (graph->edge_num--)
    {
        printf("Please enter edge that connect each other by edge\n");
        u = getchar();
        while (getchar() != '\n');
        v = getchar();
        while (getchar() != '\n');

        i = search_vex(graph, u);
        j = search_vex(graph, v);
        if(i != -1 && j != -1) {
            //undirected_graph
            graph->Edge[i][j] = graph->Edge[j][i] = 1; 
            //directed_graph
            // graph->Edge[i][j] = 1;
        }
        else 
        {
            printf("You have entered wrong edge: please enter again!!!");
            graph->edge_num ++;
        }
    }
    

    return graph;

}

void ShowAmgGraph(struct AmgGraph *graph) {
    int i, j;
    printf("Show the vex: \n");
    for(int i = 0; i < graph->vex_num; i++)
        printf("%c ", graph->Vex[i]);
    printf("\n");
    printf("Show the edge: \n");

    for(int i = 0; i < graph->vex_num; i++) {
        for(int j = 0; j < graph->vex_num; j++)
           printf("%d\t", graph->Edge[i][j]);
        printf("\n");
        
    }


}

int search_vex(struct AmgGraph *graph, char c) {
    int i;
    for(int j = 0; i < graph->vex_num; i++) {
        if(c == graph->Vex[j])
            i = j;
    }
    return -1;
}