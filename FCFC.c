
#include <stdio.h>

#define NUM_PROCESSES 5

struct process {
    int arrival_time;
    int burst_time;
    int start_time;
    int finish_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    struct process processes[NUM_PROCESSES];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int current_time = 0;

    // Sample input of 5 processes
    processes[0].arrival_time = 0;
    processes[0].burst_time = 6;
    processes[1].arrival_time = 3;
    processes[1].burst_time = 2;
    processes[2].arrival_time = 5;
    processes[2].burst_time = 1;
    processes[3].arrival_time = 6;
    processes[3].burst_time = 4;
    processes[4].arrival_time = 8;
    processes[4].burst_time = 3;

    // Calculate the start time, finish time, turnaround time, and waiting time
    for (int i = 0; i < NUM_PROCESSES; i++) {
        // If the current process arrives before the completion of the previous process,
        // set the current time to the arrival time of the current process
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].start_time = current_time;
        processes[i].finish_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        current_time = processes[i].finish_time;

        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    // Print the results
    printf("Process | Arrival Time | Burst Time | Start Time | Finish Time | Turnaround Time | Waiting Time\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d      | %d           | %d         | %d         | %d          | %d              | %d\n",
               i + 1,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].start_time,
               processes[i].finish_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    printf("\nAverage turnaround time: %.1f\n", (float) total_turnaround_time / NUM_PROCESSES);
    printf("Average waiting time: %.1f\n", (float) total_waiting_time / NUM_PROCESSES);

    return 0;
}
