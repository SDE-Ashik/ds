#include<stdio.h>
int queue[50],adjmatrix[50][50],visited[50],rear=-1,front=-1,i,n,j,v;

int bfs(int V)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(adjmatrix[V][i]!=0 && visited[i]==0)
        {
            rear=rear+1;
            visited[i]=1;
            queue[rear]=i;
            printf("%d-->",i);
        }
        front=front+1;
        if(front<=rear)
        {
            bfs(queue[front]);
        }
    }
}

int main()
{
    printf("enter the total vertex:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        visited[i]=0;    //now all vertex are unvisited ie..0=0,1=0,2=0... so if vertex is visited 0 changes to 1(mark all vertex as unvisited)
    }

    printf("enter graph data in matrix form\n");   
     printf(" if these vertex have no connection then press 0  :");
    for(i=0;i<n;i++)
    {   
        for(j=0;j<n;j++)
        {
        printf("%d---%d=",i,j);
        scanf("%d",&adjmatrix[i][j]);
        printf("\n");
       
        }
    }
    // graph data in matrix format like this
      printf("V\t");                 //45-67 (adjacent matrix )
    for ( i = 0; i < n; i++)                                    
    {
        printf("%d \t", i);
    }
    printf("\n");
    printf("\t");
     for ( i = 0; i < n; i++)
     {
        printf("______");
     }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t|",i);
        for ( j = 0; j < n; j++)
        {
            printf("%d\t|",adjmatrix[i][j]);
        }
        printf("\n");
        
    }

// 
    printf("enter the starting vertex:");
    scanf("%d",&v);
    visited[v]=1;
    front=rear=0;

    printf("bfs travels are");
    printf("\n%d-->",v);
    bfs(v);
    if(rear!=n-1)
    {
        printf("\n BFS NOT POSSIBLE");
    }
}





// This program implements the Breadth First Search (BFS) algorithm to traverse a graph in C. Some important points to note about the program are:

// The program uses an adjacency matrix to represent the graph.
// The program initializes an array called visited to keep track of which vertices have been visited during the BFS traversal.
// The program uses a queue data structure to keep track of the order in which vertices are visited during the BFS traversal.
// The bfs function is a recursive function that takes a vertex as an input and traverses its adjacent vertices using BFS.
// The program prompts the user to enter the graph data in matrix form.
// The program prompts the user to enter the starting vertex.
// The program prints the BFS traversal of the graph, starting from the starting vertex.
// The program checks if all vertices have been visited during the BFS traversal by checking the size of the queue. If the size of the queue is not equal to n-1, where n is the total number of vertices in the graph, then the BFS traversal is not possible.
