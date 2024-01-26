#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process process[],
                          // n is the total number of process
                          int n, int time_quantum)
{
    int remaining_process = n;
    int current_time = 0;

    printf("\n");
    while (remaining_process > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (process[i].remaining_time > 0)
            {
                // execute the process for the time quantum or remaining time whichever is smaller

                int execution_time = (process[i].remaining_time < time_quantum) ? process[i].remaining_time : time_quantum;

                process[i].remaining_time -= execution_time;

                current_time += execution_time;

                // Display the execution
                printf("Executing process P%d for %d units of time.\n", process[i].id, execution_time);

                if (process[i].remaining_time == 0)
                {
                    remaining_process--;
                    printf("Process P%d completed at time %d.\n", process[i].id, current_time);
                }
            }
        }
    }
}

int main()
{
    int n, time_quantum;

    // Input number of process
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process process[n];

    // Input details of each process
    for (int i = 0; i < n; i++)
    {
        process[i].id = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &process[i].burst_time);
        process[i].remaining_time = process[i].burst_time;
    }

    // Taking input of time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // Perform round robin scheduling
    roundRobinScheduling(process, n, time_quantum);

    return 0;
}