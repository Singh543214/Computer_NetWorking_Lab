#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WINDOW_SIZE 4
void sender_sr(int total_frame){
    int next_frame_to_send=0;
    int base=0;
    int frame_sent[total_frame];
    for (int i = 0; i < total_frame; i++)
        frame_sent[i] = 0;
    while(base<total_frame){
        for(int i=0;i<WINDOW_SIZE && (next_frame_to_send<total_frame);i++){
            if(frame_sent[next_frame_to_send]==0){
                printf("\n Frame %d send",next_frame_to_send);
                frame_sent[next_frame_to_send]=1;
            }
            next_frame_to_send++;
        }
            for(int i=base;i<total_frame && i<next_frame_to_send;i++){
                if(frame_sent[i]==1){
                    if(rand()%3!=0){
                        printf("\n ACK for Frame %d received",i);
                        frame_sent[i]=2;
                    }else{
                        printf("\n NAK from frame %d retransmiting",i);
                        frame_sent[i]=0;
                    }
                }
            }
            while(base<total_frame && frame_sent[base]==2){
                base++;
            }
            next_frame_to_send=base;
        }

    }

int main(){
    srand(time(NULL));
    int total_frame;
    printf("Enter total frames: ");
    scanf("%d",&total_frame);
    printf("\n----Selective Repeat protocal----\n");
    sender_sr(total_frame);
}