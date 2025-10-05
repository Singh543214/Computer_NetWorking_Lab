#include<stdio.h>
#include<string.h>
int main(){
    char a[20],b[20],sum[20],compliment[20];
    printf("Enter First Binary String : ");
    scanf("%s",a);
    printf("Enter Second Binary String : ");
    scanf("%s",b); 
    if(strlen(a)!=strlen(b)){
        printf("\nWrong Input Strings");
        return 0;
    }  
    int length=strlen(b),carry=0;
    sum[length]='\0';compliment[length]='\0';
    for(int i=length-1;i>=0;i--){
        int d1=a[i]-'0';
        int d2=b[i]-'0';
        sum[i]=((d1+d2+carry)%2)+'0';
        carry=(d1+d2+carry)/2;
    }
    printf("\nCarry: %d Sum: %s",carry,sum);
    if(carry==1){
        for(int i=length-1;i>=0;i--){
            if(sum[i]=='1') sum[i]='0';
            else{
                sum[i]='1';
                break;
            }
        }
    }

    for(int i=0;i<length;i++){
       if(sum[i]=='0') compliment[i]='1';
       else compliment[i]='0';
    }
    printf("\nChecksum: %s",compliment);

}