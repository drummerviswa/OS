#include <stdio.h>
#include <string.h>
void main(){
    int p[20],bt[20], at[10], n, i, j, temp, ct[10], wt[10], tat[10],t[10];
    float avgwt=0,avgtat=0;
    printf("Enter the number of process:");
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
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            if (bt[i] < bt[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    for (i = 0; i < n; i++){
        if (i == 0)
            t[i] = at[i];
        else
            t[i] = ct[i - 1];
        wt[i] = t[i] - at[i];
        ct[i] = t[i] + bt[i];
        tat[i] = ct[i] - at[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }
    avgwt /= n;
    avgtat /= n;
    printf("P ID:\tArrival time\tBurst time\tWaiting time\tTurn Around time\n");
    for (i = 0; i < n; i++){
        printf("\%d\t%5d\t\t%5d\t\t%5d\t\t%5d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %f", avgwt);
    printf("\nAverage turnaroundtime: %f", avgtat);
}