#include <stdio.h>
void swap(int *a,int *b){
    int *x=a;
    a=b;
    b=x;
}
int main(){
    int i,j, n, total = 0, x, counter = 0, time_quantum,p[10];
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10],tat[10],wt[10], temp[10];
    float average_wait_time, average_turnaround_time;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);
    x = n;
    printf("Enter Arrival Time: \n");
    for (i = 0; i < n; i++){
        printf("Arrival Time p[%d]: ",i);
        scanf("%d", &arrival_time[i]);
    }
    printf("Enter Burst Time: \n");
    for(i=0;i<n;i++){
        printf("Burst Time p[%d]: ",i);
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
        p[i]=i;
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arrival_time[i]>arrival_time[j]){
                swap(&arrival_time[i],&arrival_time[j]);
                swap(&burst_time[i],&burst_time[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    printf("Process ID\t\tBurst Time\tTurnaround Time\tWaiting Time \n");
    for (total = 0, i = 0; x != 0;){
        if (temp[i] <= time_quantum && temp[i] > 0){
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if (temp[i] > 0){
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if (temp[i] == 0 && counter == 1){
            x--;
            tat[i]=total - arrival_time[i];
            wt[i]=total - arrival_time[i] - burst_time[i];
            printf("P[%d]\t\t\t%d\t\t\t %d\t\t\t %d\n", p[i], burst_time[i],tat[i], wt[i]);
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            counter = 0;
        }
        if (i == n - 1){
            i = 0;
        }
        else if (arrival_time[i + 1] <= total){
            i++;
        }
        else{
            i = 0;
        }
    }
    average_wait_time = wait_time * 1.0 / n;
    average_turnaround_time = turnaround_time * 1.0 / n;
    printf("Average Waiting Time: %f\n", average_wait_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);
    return 0;
}