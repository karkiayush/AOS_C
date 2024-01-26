#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

// Function to calculate waiting time and turn around time processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0; // waiting tiem for the first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

// Method to calculate the turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    // Turn arount time is the sum of waiting time and burst time
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

// Method for calculation of average time
void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];

    // Function calls to calculate waiting time and turn around time
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    // Calculate total waiting time and turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and avg turnaround time
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    // Display results
    printf("Process\t\tBurst Time\tWaiting time\t\tTurn Around Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("\nAverage turn around time: %.2f\n", avg_tat);
}

int main()
{
    // Number of processes
    int n;

    printf("Enter the number of prcoesses: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Process IDs starts from 1
    }

    // Function call to calculate average waiting time and turn around time
    findAverageTime(processes, n, burst_time);

    return 0;
}