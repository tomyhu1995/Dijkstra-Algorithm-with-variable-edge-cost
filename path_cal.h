#ifndef _PATH_CAL_
#define _PATH_CAL_
/*Include files*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*constant definition*/
#define INFINITY 9999
#define MAX 10

#define TenMbps_cost 25
#define OneHoudardMbps_cost 19
#define OneGigaMbps_cost 4

typedef struct _C_{
    int cost;//cost of the link, this variable will be varied by network usage.
    int capacity;// link capacity, such as 10Mbps.
}Edge_cost;

/*Function definition*/

/*
 * calculate how many cost should be added.
 */
int path_cost_addition(void);

/*
 * routing table calculation
 */
void dijkstra(Edge_cost G[MAX][MAX],int n,int startnode, int endnode);

/*
 * convert link capacity(such as 10Mbps) to link cost
 */
int link_cost_calculate(int link_capacity);

/*
 * initial adjacency matrix.
 */
void initial_adjacency_matrix(Edge_cost G[MAX][MAX]);

#endif

