#include<stdio.h>
int main(){
    int data[7],recieved[7];
    int p1,p2,p4,syndrome;
    printf("Haming (7,4) code using Even parity at position 1,2 and 4\n");
    printf("Enter 4 data bits one by one (D1,D2,D3,D4)\n");
    scanf("%d",&data[2]);
    scanf("%d",&data[4]);
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);

    //p1 covers bits: 1,3,5,7 position:0,2,4,6
    //p2 covers bits: 2,3,6,7 position:1,2,5,6
    //p4 covers bits: 4,5,6,7 position:3,4,5,6

    data[0]=data[2]^data[4]^data[6];
    data[1]=data[2]^data[5]^data[6];
    data[3]=data[4]^data[5]^data[6];

    printf("Encoded 7-bit Hamming code:\n");
    for(int i=0;i<7;i++){
        printf("%d ",data[i]);
    }

    printf("\nEnter Recieved 7-bits Hamming code: ");
    for(int i=0;i<7;i++){
        scanf("%d",&recieved[i]);
    }

    p1=recieved[0]^recieved[2]^recieved[4]^recieved[6];
    p2=recieved[1]^recieved[2]^recieved[5]^recieved[6];
    p4=recieved[3]^recieved[4]^recieved[5]^recieved[6];

    //binary value of error postion 
    syndrome=p4*4+p2*2+p1;

    if(syndrome==0){
        printf("No Error detected.... Message is correct\n");
    }else{
        printf("Error detected at bit position: %d\n",syndrome);
        recieved[syndrome-1]^=1;
        printf("Corrected 7-bits Message: ");
        for(int i=0;i<7;i++){
            printf("%d",recieved[i]);
        }
    }
}