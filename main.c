#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "path_cal.h"

 
int main()
{
    Edge_cost G[MAX][MAX];
    int i,j,n,start_node, end_node;
    initial_adjacency_matrix(G);
    printf("\n------------------------------------------Topology create------------------------------------------\n");
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    

    for(i = 0; i < n; i++){
        int tmp, link_capacity, link_length;
        printf("Please enter which nodes link to %d\n", i+1);
        printf("Input can be terminated by entering 0\n");

        while(printf("Node number(1~%d): ", n)){

            if(scanf("%d", &tmp) && tmp != 0){
                if(tmp == i+1){
                    printf("No good input\n");
                }else{
                    printf("link capacity(10 - 10Mbps, 100 - 100Mpbs, 1000 - 1Gbps): ");
                    scanf("%d", &link_capacity);
                    G[i][tmp-1].cost = link_cost_calculate(link_capacity);
                    G[i][tmp-1].capacity = link_capacity;
                }
            }else{
                break;
            }
        }
    }

    printf("\nprint the adjacency matrix:\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",G[i][j].cost);
        }
        printf("\n");
    }
    
    printf("\n------------------------------------------End of topology create------------------------------------------\n");
    
    
    while(printf("\nEnter flow's start node(1~%d)(0 for terminate): ", n)){
        if(scanf("%d", &start_node) && start_node != 0){
            printf("Enter flow's end node(1~%d): ", n);
            scanf("%d", &end_node);
            dijkstra(G,n,start_node-1, end_node-1);
        }else{
            break;
        }

        printf("\nprint the adjacency matrix:\n");
    
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",G[i][j].cost);
            }
            printf("\n");
        }
    }

    //printf("\nEnter flow's start node(1~%d): ", n);
    //scanf("%d", &start_node);
    //printf("Enter flow's end node(1~%d): ", n);
    //scanf("%d", &end_node);
    //dijkstra(G,n,start_node-1, end_node-1);
    
    return 0;
}