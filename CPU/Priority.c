#include <stdio.h>

void main(){
    int n, i, j, temp, at[10], bt[10], p[10], wt[10], tat[10], pri[10], sum = 0, tot = 0;
    float avgwt, avgtat;
    printf("enter no of process:");
    scanf("%d", &n);
    printf("Enter Arrival time: \n");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i);
        scanf("%d",&at[i]);
    }
    printf("Enter Burst time: \n");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    printf("Enter Priority: \n");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i);
        scanf("%d",&pri[i]);
        p[i]=i;
    }
    for (i = 0; i <n; i++){
        for (j = 0; j < n; j++){
            if (pri[i] < pri[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[1];
    for (i = 1; i < n; i++){
        wt[i] = tat[i - 1];
        tat[i] = bt[i] + wt[i];
    }
    for (i = 0; i < n; i++){
        sum = sum + wt[i];
        tot = tot + tat[i];
    }
    avgwt = sum / n;
    avgtat = tot / n;
    printf("P ID:\tArrival time\tBurst time\tWaiting time\tTurn Around time\tPriority\n");
    for (i = 0; i < n; i++){
        printf("%d\t\%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i], pri[i]);
    }
    printf("Average Waiiting time=%f\nAverage Turnaround time=%f\n", avgwt, avgtat);
}