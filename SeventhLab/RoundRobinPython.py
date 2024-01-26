class Process:
    def __init__(self, id, burst_time):
        self.id = id
        self.burst_time = burst_time
        self.remaining_time = burst_time


def round_robin_scheduling(processes, time_quantum):
    remaining_processes = len(processes)
    current_time = 0

    print()

    while remaining_processes > 0:
        for proc in processes:
            if proc.remaining_time > 0:
                execution_time = min(proc.remaining_time, time_quantum)
                proc.remaining_time -= execution_time
                current_time += execution_time

                print(
                    f"Executing process P{proc.id} for {execution_time} units of time."
                )

                if proc.remaining_time == 0:
                    remaining_processes -= 1
                    print(f"Process P{proc.id} completed at time {current_time}.")


if __name__ == "__main__":
    n = int(input("Enter the number of processes: "))

    processes = []
    for i in range(n):
        id = i + 1
        burst_time = int(input(f"Enter burst time for process P{id}: "))
        processes.append(Process(id, burst_time))

    time_quantum = int(input("Enter the time quantum: "))

    round_robin_scheduling(processes, time_quantum)
