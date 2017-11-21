#ifndef _PATH_CAL_
#define _PATH_CAL_
/*Include files*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*constant definition*/
#define INFINITY 9999
#define MAX 10

#define TenMbps_cost 100
#define OneHoudardMbps_cost 10
#define OneGigaMbps_cost 1


//#define DEBUG

/*
 * Usage: declare edges
 */
typedef struct _C_{
    int cost;//cost of the link, this variable will be varied by network usage.
    int capacity;// link capacity, such as 10Mbps.
}Edge_cost;


/*
 * Usage: declare route
 */
typedef struct _R_
{
	int start_node;//the start node.
	int end_node;//the end node.
	int path[MAX];
	int number_of_count;
	int min_capacity;//the minimum capacity on the route.
	int route_age;//to store the route is old or new.
	int target_capacity;//user wanted capacicy.
}Route;

/*Function definition*/

/*
 * Print routing informations
 */
void Route_print(Route R, int serial_number);

/*
 * calculate how many cost should be added.
 */
int path_cost_addition(int target_capacity);

/*
 * routing table calculation
 */
void dijkstra(Edge_cost G[MAX][MAX],int n, Route *R);

/*
 * convert link capacity(such as 10Mbps) to link cost
 */
int link_cost_calculate(int link_capacity);

/*
 * initial adjacency matrix.
 */
void initial_adjacency_matrix(Edge_cost G[MAX][MAX]);

/*
 * initial routing table.
 */
void initial_route_table(Route R[MAX]);

#endif

