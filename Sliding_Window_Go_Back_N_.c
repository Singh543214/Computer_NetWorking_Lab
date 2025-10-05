#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WINDOW_SIZE 4
void sender(int total_frame){
    int frame_sent=0;
    int next_frame_to_send=0;
    int ack_expected=0;
    while(ack_expected<total_frame){
        for(int i=0;i<WINDOW_SIZE && (next_frame_to_send<total_frame);i++){
            printf("Sender: Frame send %d\n",next_frame_to_send);
            frame_sent++;
            next_frame_to_send++;
        }
        if(rand()%5 != 0){
            printf("Receiver: Ack received for Frame %d\n",ack_expected);
            ack_expected++;
        }else{
            printf("Sender: TimeOut!... Retransmiting for frame %d\n",ack_expected);
            next_frame_to_send=ack_expected;
        }
        printf("\n");
    }
    printf("Sender: All frame transmitted Successfully!... with total %d transmission\n",frame_sent);
}
int main(){
    srand(time(NULL));
    int total_frame;
    printf("Enter total number of frames: ");
    scanf("%d",&total_frame);
    sender(total_frame);
    return 0;
}