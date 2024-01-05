#include <stdio.h>
#include <conio.h>
int main()
{
    int i, j, n, t, max, bu[10], wa[10], tat[10], ct[10];
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];
        wa[i] = 0; // Initialize waiting time
    }

    printf("Enter time quantum: ");
    scanf("%d", &t);

    for (i = 0; i < n; i++)
    {
        max = (bu[i] > max) ? bu[i] : max;
    }

    for (j = 0; j < (max / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (bu[i] != 0)
            {
                if (bu[i] <= t)
                {
                    temp += bu[i];
                    tat[i] = temp;
                    bu[i] = 0;
                }
                else
                {
                    bu[i] -= t;
                    temp += t;
                }
                wa[i] = tat[i] - ct[i];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        awt += wa[i];
        att += tat[i];
    }


    printf("The Average Turnaround time is: %f\n", att/=n);
    printf("The Average Waiting time is: %f\n", awt/=n);
    printf("PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
