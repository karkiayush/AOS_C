/*
Here we are implementing the SRTF algo which is the premptive version of SJF.
*/

#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int process_id;
    int burst_time;
    int remaining_time;
    bool completed;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_remaining_time(struct Process process[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (process[j].remaining_time > process[j + 1].remaining_time)
            {
                swap(&process[j], &process[j + 1]);
            }
        }
    }
}

void srtf(struct Process process[], int n)
{
    int current_time = 1;

    while (true)
    {
        int shortest = -1;

        // find the process with the shortest remaining time
        for (int i = 0; i < n; i++)
        {
            if (!process[i].completed && process[i].burst_time > 0 && (shortest == -1 || process[i].remaining_time < process[shortest].remaining_time))
            {
                shortest = i;
            }
        }

        if (shortest == -1)
        {
            // All process are completed
            break;
        }

        // Execute the process
        process[shortest].burst_time--;
        process[shortest].remaining_time--;

        printf("Time %d: Process%d\n", current_time, process[shortest].process_id);
        current_time++;

        // Check if the process is completed
        if (process[shortest].burst_time == 0)
        {
            process[shortest].completed == true;
        }

        // sort process based on remaining time for the next iteration
        sort_by_remaining_time(process, n);
    }
}

int main()
{
    int n;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++)
    {
        processes[i].process_id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }

    // Sort process based on burst time for the initial state
    sort_by_remaining_time(processes, n);

    // execute processes using SRTF
    srtf(processes, n);

    return 0;
}