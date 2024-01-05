#include <stdio.h>

int main()
{
    int i, k, n, temp, bt[20], wt[20], tat[20], p[20], pri[20];
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter Burst Time and Priority for Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (pri[i] > pri[k])
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("PROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("The Average Turnaround time is: %f\n", tatavg / n);
    printf("The Average Waiting time is: %f\n", wtavg / n);

    return 0;
}
