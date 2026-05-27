#include<stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f, i, j, k, pos, faults = 0, count = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                count++;
                time[j] = count;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
    }
