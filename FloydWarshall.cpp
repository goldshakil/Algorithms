#include <bits/stdc++.h> 
using namespace std; 
   
#define V 5  
#define INF 99999  

void printSolution(int dist[][V])  
{  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<" ";  
            else
                cout<<dist[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
}  
  

void floydWarshall (int graph[][V])  
{  
   
    int dist[V][V], i, j, k;  
  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {            
            for (j = 0; j < V; j++)  
            {               
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    
    printSolution(dist);  
}  
  

void transitiveClosure(int graph[][V]) 
{ 
  
    int reach[V][V], i, j, k; 

    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            reach[i][j] = graph[i][j]; 
  
    for (k = 0; k < V; k++) 
    {        
        for (i = 0; i < V; i++) 
        { 
            for (j = 0; j < V; j++) 
            {               
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]); 
            } 
        } 
    } 
  
    printSolution(reach); 
} 
  

int main()  
{   
    // In this matrix, we use 0 to present the distance from one vertex to itself, 
    // INF to present if the vertex i is not reachable to vertex j, reachable mean that there is a path from vertex i to j. 
    int graph[V][V] = { {0, 10, 5, INF,INF},  
                        {INF, 0, 3, 1,INF},  
                        {INF, 2, 0, 9, 2}, 
                        {INF, INF, INF,0, 6},
                        {7, INF, INF,4, 0}  
                    }; 
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    floydWarshall(graph);
    
    //This matrix is modified from the above matrix to achieve transitive closure, 
    //here we neglect the exact distance but just use 1 to present if 
    //there's a path from vertex i to j, and 0 to present if the vertex i is not reachable to vertex j.
    //Note that here we regard every vertex is reachable to itself.
    int closure[V][V] = { {1, 1, 1, 0, 0},  
                        {0, 1, 1, 1, 0},  
                        {0, 1, 1, 1, 1}, 
                        {0, 0, 0, 1, 1},
                        {1, 0, 0, 1, 1}  
                    };  
    //The explanation and example for Transitive Closure is in the slides. Please check that. 
    cout<<"Following matrix is transitive closure of the given graph\n"; 
    transitiveClosure(closure); 
    return 0;  
}  
  
