#include <stdio.h>

typedef struct {
    int id;
    int arrival;
    int deadline;
    int execution;
    int remaining;
    int completed;
} Process;

void EDF_Scheduler(Process p[], int n) {
    float U = 0;

    // Step 1: CPU Utilization
    for (int i = 0; i < n; i++) {
        U += (float)p[i].execution / p[i].deadline;
        p[i].remaining = p[i].execution;
        p[i].completed = 0;
    }

    // Step 2: Feasibility Check
    if (U > 1) {
        printf("Scheduling not feasible\n");
        return;
    } else {
        printf("Scheduling feasible\n");
    }

    int t = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_deadline = 99999;

        // Find earliest deadline process
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= t && p[i].completed == 0) {
                if (p[i].deadline < min_deadline) {
                    min_deadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            t++;
            continue;
        }

        // Execute for 1 unit
        printf("Time %d: Running P%d\n", t, p[idx].id);
        p[idx].remaining--;

        if (p[idx].remaining == 0) {
            p[idx].completed = 1;
            completed++;
            printf("P%d completed at time %d\n", p[idx].id, t + 1);
        }

        t++;
    }
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        p[i].id = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);

        printf("Execution Time: ");
        scanf("%d", &p[i].execution);

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);

    EDF_Scheduler(p, n);

    return 0;
}
