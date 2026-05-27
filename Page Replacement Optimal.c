#include<stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k, farthest, pos, faults = 0, flag;

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
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            pos = -1;
            farthest = i + 1;

            for(j = 0; j < f; j++) {
                int found = 0;

                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            faults++;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d\t", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
