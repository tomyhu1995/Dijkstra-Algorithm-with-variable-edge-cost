#include "path_cal.h"

void Route_print(Route R){
    int i;

    printf("----------------------------------\n");
    printf("Start node: %d\n", R.start_node);
    printf("End node: %d\n", R.end_node);
    printf("minimum link capacity: %d\n", R.min_capacity);
    printf("Hops: %d\n", R.number_of_count);
    printf("Path: %d", R.end_node);
    for(i = 1; i < R.number_of_count; i++){
        printf("<-%d", R.path[i]);
    }
    printf("\n----------------------------------\n");
}

int path_cost_addition(void){
    return 1;
}

void dijkstra(Edge_cost G[MAX][MAX],int n, Route *R)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX], path[MAX] = {0};
    int visited[MAX],count,mindistance,nextnode,i,j;
    R->min_capacity = INFINITY;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(G[i][j].cost==0){
                cost[i][j]=INFINITY;
            }else{
                cost[i][j]=G[i][j].cost;
            }
        }
    }
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[R->start_node-1][i];
        pred[i]=R->start_node-1;
        visited[i]=0;
    }
    
    distance[R->start_node-1]=0;
    visited[R->start_node-1]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    //for(i=0;i<n;i++){
        //if(i==endnode)
        //{
#ifdef DEBUG
    printf("\nDistance of node%d=%d\n\n", R->end_node, distance[R->end_node-1]);
    //printf("\nDistance from %d to %d is: %d", startnode+1, endnode+1, distance[endnode]);
    printf("\nPath=%d",R->end_node);
#endif 
    
    R->path[0] = R->end_node;
    count = 1;

    j = R->end_node-1;
    do
    {
        j=pred[j];
        R->path[count++] = j + 1;
#ifdef DEBUG
        printf("<-%d",j+1);
#endif
    }while(j!=R->start_node-1);

    R->number_of_count = count - 2;

    for(i = 0; i < count - 1; i++){
        G[R->path[i]-1][R->path[i+1]-1].cost += path_cost_addition();//add path cost
        G[R->path[i+1]-1][R->path[i]-1].cost += path_cost_addition();//add path cost

        if(G[R->path[i]-1][R->path[i+1]-1].capacity <= R->min_capacity){
            R->min_capacity = G[R->path[i]-1][R->path[i+1]-1].capacity;
        }
    }

#ifdef DEBUG
    printf("\nmin capacity = %d\n", R->min_capacity);
#endif

}

int link_cost_calculate(int link_capacity){
    int link_cost = 0;

    switch(link_capacity){
        case 10:
            link_cost = TenMbps_cost;
            break;
        case 100:
            link_cost = OneHoudardMbps_cost;
            break;
        case 1000:
            link_cost = OneGigaMbps_cost;
            break;
        default:
            link_cost = TenMbps_cost;
            break;
    }


    return link_cost;
}

void initial_adjacency_matrix(Edge_cost G[MAX][MAX]){
    int i, j;

    for(i=0;i < MAX;i++){
        for(j=0;j < MAX;j++){
            G[i][j].cost = 0;
            G[i][j].capacity = 0;   
        }
    }
}

void initial_route_table(Route R[MAX]){
    int i,j;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            R[i].path[j] = 0;
        }
    }
}