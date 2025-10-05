#include<stdio.h>
int main(){
    int a[5][5],i,j,p,path[5][5],st=1,ed=5,stp,edp,t[5],index,min;
    printf("\nEnter Cost Matrix:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter Paths: ");
    scanf("%d",&p);

    printf("\nEnter possible paths: \n");
    for(i=0;i<p;i++){
        printf("\nEnter Path %d: ",i+1);
        for(j=0;j<5;j++){
            scanf("%d",&path[i][j]);
            if(path[i][j]==ed) break;
        }
    }

    //Path cost calculation
   for(int i=0;i<p;i++){
    t[i]=0;
    stp=st;
    for(int j=0;j<4;j++){
        edp=path[i][j+1];
        t[i]+=a[stp-1][edp-1];
        if(edp==ed) break;
        else{
            stp=edp;
        }
    }
   }

    //Find min
    min=t[0];
    index=0;
    for(i=1;i<p;i++){
        if(min>t[i]) {
            min=t[i];
            index=i;
        }
    }

    //Print
    printf("\nMinimum Cost: %d",min);
    printf("\nMinimum Path: ");
    for(i=0;i<5;i++){
        printf("->%d",path[index][i]);
        if(path[index][i]==ed) break;
    }
    return 0;
}