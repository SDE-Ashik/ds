#include<stdio.h>
int matrix[50][50],indegree[50],n;

void find_degree()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        indegree[i]=0;
        for(j=0;j<n;j++)
        {
            indegree[i]=indegree[i]+matrix[j][i];
        }
    }
}



int topo()
{
    int stack[50],top=-1,u,v,t[50],i,k=0;
    find_degree();
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            stack[++top]=i;
        }
    }
        while(top!=-1)
        {
            u = stack[top--];
            t[k++]=u;
            for(v=0;v<n;v++)
            {
                if(matrix[u][v]!=0)
                {
                    indegree[v]--;
                    if(indegree[v]==0)
                    {
                        stack[++top]=v;
                    }
                }
            }
        }
      if (k != n) {
        return 0;  // graph contains a cycle
    }

    printf("Topological ordering: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 1;
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (!topo()) {
        printf("Graph contains a cycle!\n");
    }
    return 0;
}



// This code is an implementation of the topological sorting algorithm using adjacency matrix representation of a directed graph. Topological sorting is an ordering of vertices in a directed graph such that for every directed edge (u,v), vertex u comes before vertex v in the ordering.

// The program starts by declaring some global variables - matrix, indegree, and n.

// The find_degree() function calculates the indegree of each vertex in the graph by summing the values in the corresponding column of the adjacency matrix.

// The topo() function initializes an empty stack and an empty array t. It calls find_degree() to calculate the indegree of each vertex. It then pushes all the vertices with an indegree of 0 onto the stack.

// The algorithm starts by popping a vertex u from the stack and adding it to the array t. For each vertex v adjacent to u, it decreases the indegree of v by 1. If the indegree of v becomes 0, it pushes v onto the stack.

// Steps 4 and 5 are repeated until the stack is empty. If the number of vertices added to t is less than n, it means that the graph contains a cycle, and the function returns 0. Otherwise, it prints the topological ordering and returns 1.

// In the main() function, the user inputs the number of vertices and the adjacency matrix. It then calls topo() to perform the topological sorting. If the function returns 0, it means that the graph contains a cycle, and the program prints a message to inform the user.




// OUTPUT 
// Enter the number of vertices: 4
// Enter the adjacency matrix:
// 0 1 0 0
// 0 0 1 0 
// 0 0 0 0
// 0 0 1 0
