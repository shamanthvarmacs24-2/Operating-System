

#include<stdio.h>

int main() {
    int b[20], p[20], allocation[20];
    int m, n, i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for(i = 0; i < n; i++) {
        allocation[i] = -1;

        best = -1;
        for(j = 0; j < m; j++) {
            if(b[j] >= p[i]) {
                if(best == -1 || b[j] < b[best])
                    best = j;
            }
        }

        if(best != -1) {
            allocation[i] = best;
            b[best] -= p[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, p[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
