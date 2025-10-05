#include<stdio.h>
#include<stdlib.h>
int main(){
    int incoming,outgoing_rate,bucket_size,n,store=0;
    printf("Enter Bucket size,Outing rate,number of incoming packet bursts: ");
    scanf("%d%d%d",&bucket_size,&outgoing_rate,&n);
    while(n>0){
        printf("\nEnter incoming packet size for this burst: ");
        scanf("%d",&incoming);
        printf("\nIncoming packet size: %d",incoming);
        if(incoming<=(bucket_size-store)){
            store+=incoming;
            printf("\nPacket added to bucket.Current bucket buffer size: %d out of %d\n",store,bucket_size);
        }else{
            int dropped_packet=incoming-(bucket_size-store);
            printf("Bucket Overflow!!! Droped %d packets\n",dropped_packet);
            store=bucket_size;
            printf("Current bucket buffer size: %d out of %d",store,bucket_size);
        }
        store-=outgoing_rate;
        if(store<0) store=0;
        printf("After Outgoing packets, %d packets left in buffer out of %d\n",store,bucket_size);
        n--;
    }
    }
