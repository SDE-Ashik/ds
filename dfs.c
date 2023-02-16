#include<stdio.h>

int stack[50], visited[50], matrix[50][50], i, j, n, v, top = -1;

void dfs(int s)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(matrix[s][i] != 0 && visited[i] == 0)
        {
            top++;
            printf("%d->", i);
            visited[i] = 1;
            stack[top] = i;
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter the total number of vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the data in matrix format:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d->%d= ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    top=0;
    visited[v] = 1;
    stack[top] = v;

    printf("DFS traversal: %d->", v);
    dfs(v);
    if(top!=n-1)
{
    printf("\nnot possible");
}


    return 0;
}
// using adjacent matrix.....
