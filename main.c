#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "path_cal.h"

//#define DEBUG_AJ_MATRIX

int main(int argc, char const *argv[])
{
    Edge_cost G[MAX][MAX];
    Route R[MAX];
    int i,j,n,start_node, end_node, num_of_routes = 0;
    
    initial_adjacency_matrix(G);
    initial_route_table(R);

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

#ifdef DEBUG
    printf("\nprint the adjacency matrix:\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",G[i][j].cost);
        }
        printf("\n");
    }
#endif
    
    printf("\n------------------------------------------End of topology create------------------------------------------\n");
    
    
    while(printf("\nEnter flow's start node(1~%d)(0 for terminate): ", n)){
        if(scanf("%d", &start_node) && start_node != 0){
            printf("Enter flow's end node(1~%d): ", n);
            scanf("%d", &end_node);

            if(start_node >= 1 && start_node <= n && end_node >= 1 && end_node <= n && start_node != end_node){
                R[num_of_routes].start_node = start_node;
                R[num_of_routes].end_node = end_node;

                dijkstra(G, n, &(R[num_of_routes]));
                Route_print(R[num_of_routes]);
                R[num_of_routes].route_age = 1;
                num_of_routes++;
            }else{
                printf("!!!!!!!! No good input !!!!!!!!\n");
            }
            
        }else{
            break;
        }

#ifdef DEBUG_AJ_MATRIX
        printf("\nprint the adjacency matrix:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",G[i][j].cost);
            }
            printf("\n");
        }
#endif
        printf("\n***** Other links *****\n");
        for(i = 0; i < num_of_routes-1; i++){
            dijkstra(G, n, &(R[i]));
            Route_print(R[i]);
        }
    }
    
    return 0;
}