#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main(){
    int n;
    printf("Read number of frames you want to send: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\nFrame %d send",i);
        int wait=rand()%8;
        sleep(5);
        if(wait>5){
            i--;
        }else{
            printf("\nAck recieved for frame %d",i);
        }
    }

    return 0;
}