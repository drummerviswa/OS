#include <stdio.h>
#define n 20
void swap(int *a,int *b){
    int *x=a;
    a=b;
    b=x;
}
void main(){
    int num,i,j,p[n],at[n],wt[n],bt[n],tat[n],ct[n];
    float avwt=0,avtat=0;
    printf("Enter the no.of process: ");
    scanf("%d",&num);
    printf("Enter Arrival time: \n");
    for(i=0;i<num;i++){
        printf("P[%d]: ",i);
        scanf("%d",&at[i]);
    }
    printf("Enter Burst time: \n");
    for(i=0;i<num;i++){
        printf("P[%d]: ",i);
        scanf("%d",&bt[i]);
        ct[i]=0;
        p[i]=i;
    }
    for(i=0;i<num;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                swap(&at[i],&at[j]);
                swap(&bt[i],&bt[j]);
                swap(&p[i],&p[j]);
            }
        }
    }
    ct[0]=bt[0];
    for(i=1;i<num;i++)
        ct[i]=ct[i-1]+bt[i];
    for(i=0;i<num;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process\t\tArriaval\tBurst\t\tCT\t\tTAT\t\tWT\n");
    for(i=0;i<num;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    for(i=0;i<num;i++){
        avwt+=wt[i];
        avtat+=tat[i];
    }
    avwt/=num;
    avtat/=num;
    printf("Average Waiting Time: %f\nAverage Turn Around Time: %f\n",avwt,avtat);
}