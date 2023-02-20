#include <stdio.h>

int a, b, u, v, i, j, ne = 1, n;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &u);
    visited[u] = 1;

    printf("\n");
    while (ne < n && u != -1) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (visited[v] == 0) {
            printf("Edge %d: (%d, %d) cost: %d\n", ne++, a, b, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    if (ne < n) {
        printf("\nMinimum spanning tree not possible\n");
    } else {
        printf("\nMinimum cost of spanning tree = %d\n", mincost);
    }

    return 0;
}
