#include "path_cal.h"

int path_cost_addition(void){
    return 1;
}

void dijkstra(Edge_cost G[MAX][MAX],int n,int startnode, int endnode)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX], path[MAX] = {0};
    int visited[MAX],count,mindistance,nextnode,i,j;
    int min_capacity = INFINITY;
    
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
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
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
    printf("\nDistance of node%d=%d\n\n", endnode+1, distance[endnode]);
    //printf("\nDistance from %d to %d is: %d", startnode+1, endnode+1, distance[endnode]);
    printf("\nPath=%d",endnode+1);
    
    path[0] = endnode+1;
    count = 1;

    j=endnode;
    do
    {
        j=pred[j];
        path[count++] = j + 1;
        printf("<-%d",j+1);
    }while(j!=startnode);

    for(i = 0; i < count - 1; i++){
        G[path[i]-1][path[i+1]-1].cost += path_cost_addition();//add path cost
        G[path[i+1]-1][path[i]-1].cost += path_cost_addition();//add path cost

        if(G[path[i]-1][path[i+1]-1].capacity <= min_capacity){
            min_capacity = G[path[i]-1][path[i+1]-1].capacity;
        }
    }
    printf("\nmin capacity = %d\n", min_capacity);
    //}
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