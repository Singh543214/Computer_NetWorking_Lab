#include<stdio.h>
int main(){
    int n,a[20],b[20];
    printf("Enter length: ");
    scanf("%d",&n);
    printf("Enter Bits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int i=0,j=0,count=1;
    while(i<n){
        if(a[i]==1){
            b[j]=a[i];
            for(int k=i+1;k<n && count<=5 && a[k]==1;k++){
                j++;
                b[j]=a[k];
                count++;
                if(count==5){
                    j++;
                    b[j]=0;
                }
                i=k;
            }
        }
        else{
            b[j]=a[i];
        }
        i++;
        j++;
    }
    printf("After Stuffing: ");
    for(i=0;i<j;i++){
        printf("%d ",b[i]);
    }
}