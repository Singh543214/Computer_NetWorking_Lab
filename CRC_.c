#include <stdio.h>
#include <string.h>


void xOr(char *dividend, char *divisor, int length) {
    for (int i = 0; i < length; i++) {
        dividend[i] = ((dividend[i] - '0') ^ (divisor[i] - '0')) + '0';
    }
}


void computeCRC(char *data, char *poly, char *remainder, int polyLen) {
    int dataLen = strlen(data);
    char temp[256];

  
    strncpy(temp, data, polyLen);
    temp[polyLen] = '\0';

    for (int i = polyLen; i <= dataLen; i++) {

     
        if (temp[0] == '1') {
            xOr(temp, poly, polyLen);
        } else {
           
            for (int k = 0; k < polyLen; k++) {
                temp[k] = ((temp[k] - '0') ^ 0) + '0';
            }
        }

      
        for (int j = 0; j < polyLen - 1; j++) {
            temp[j] = temp[j + 1];
        }

      
        temp[polyLen - 1] = (i < dataLen) ? data[i] : '0';
    }

  
    strncpy(remainder, temp, polyLen - 1);
    remainder[polyLen - 1] = '\0';
}

int main() {
    char binData[128];
    printf("Enter binary string: ");
    scanf("%s", binData);

    char dataPadded[256], remainder[64];

   
    char crc12[] = "1100000001111"; // degree 12 → polynomial length = 13 bits
    strcpy(dataPadded, binData);
    strcat(dataPadded, "000000000000"); // append 12 zeros
    computeCRC(dataPadded, crc12, remainder, 13);
    printf("CRC-12 Checksum     : %s\n", remainder);

   
    char crc16[] = "11000000000000101"; // degree 16 → length = 17 bits
    strcpy(dataPadded, binData);
    strcat(dataPadded, "0000000000000000"); // append 16 zeros
    computeCRC(dataPadded, crc16, remainder, 17);
    printf("CRC-16 Checksum     : %s\n", remainder);

   
    char crcCCITT[] = "10001000000100001"; // degree 16 → length = 17 bits
    strcpy(dataPadded, binData);
    strcat(dataPadded, "0000000000000000"); // append 16 zeros
    computeCRC(dataPadded, crcCCITT, remainder, 17);
    printf("CRC-CCITT Checksum  : %s\n", remainder);

    return 0;
}
