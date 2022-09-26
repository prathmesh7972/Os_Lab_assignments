/*
P AT BT
4 0 3 
2 2 6
3 4 4 
0 6 5 
1 8 2



*/

#include <stdio.h>
#include <stdlib.h>
struct process
{
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int TAT;
    int WT;
};


int main()
{
    int current = 0, n;
    float avgturnar = 0, avgwaiting = 0;

    printf("Enter number of processors :");
    scanf("%d", &n);

    struct process p[n];

    printf("Arrival Time and Burst Time");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival_time > current)
        {
            current = p[i].arrival_time;
        }
        p[i].start_time = current;
        current = current + p[i].burst_time;
        p[i].end_time = current;
        p[i].TAT = p[i].end_time - p[i].arrival_time;
        p[i].WT = p[i].TAT - p[i].burst_time;
        avgturnar = (avgturnar + p[i].TAT);
        avgwaiting = (avgwaiting + p[i].WT);
    }
    printf("Arrival\t Burst Time\tstart Time\tEnd Time\tTurn around\t\twaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t\n", p[i].arrival_time, p[i].burst_time, p[i].start_time, p[i].end_time, p[i].TAT, p[i].WT);
    }
    printf("\n");
    printf("%f\n", avgturnar / n);
    printf("%f\n", avgwaiting / n);
    return 0;
}
