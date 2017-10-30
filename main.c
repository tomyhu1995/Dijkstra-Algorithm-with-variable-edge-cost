#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INFINITY 9999
#define MAX 10

#define TenMbps_cost 100.0
#define OneHoudardMbps_cost 19
#define OneGigaMbps_cost 4

void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    
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
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of node%d=%d",i+1,distance[i]);
            printf("\nPath=%d",i+1);
            
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j+1);
            }while(j!=startnode);
    }
}

int link_cost_calculate(int link_capacity){
    int link_cost = 0;

    switch(link_capacity){
        case 10:
            link_cost += TenMbps_cost;
            break;
        case 100:
            link_cost += OneHoudardMbps_cost;
            break;
        case 1000:
            link_cost += OneGigaMbps_cost;
            break;
        default:
            break;
    }


    return link_cost;
}

void initial_adjacency_matrix(int G[MAX][MAX]){
    int i, j;

    for(i=0;i < MAX;i++){
        for(j=0;j < MAX;j++){
            G[i][j] = INT_MAX;   
        }
    }
}
 
int main()
{
    int G[MAX][MAX],i,j,n,start_node, end_node;
    initial_adjacency_matrix(G);
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    

    for(i = 0; i < n; i++){
        int tmp, link_capacity, link_length;
        printf("Please enter which nodes link to %d\n", i+1);
        printf("Input can be terminated by entering 0\n");

        while(printf("Node number(1~%d): ", n)){

            if(scanf("%d", &tmp) && tmp != 0){
                printf("link capacity(10 - 10Mbps, 100 - 100Mpbs, 1000 - 1Gbps): ");
                scanf("%d", &link_capacity);
                G[i][tmp-1] = link_cost_calculate(link_capacity);
            }else{
                break;
            }
        }
    }

    /*printf("\nprint the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            printf("%d",G[i][j]);
    */
    
    printf("\nEnter flow's start node(1~%d): ", n);
    scanf("%d", &start_node);
    printf("\nEnter flow's end node(1~%d): ", n);
    scanf("%d", &end_node);
    dijkstra(G,n,start_node-1);
    
    return 0;
}