#include <stdio.h>
#define KEY 3
char plainText[]="THISISPLAINTEXT";
int len = sizeof(plainText)/sizeof(plainText[0])-1;
char cipherText[sizeof(plainText)/sizeof(plainText[0])];
char decryText[sizeof(plainText)/sizeof(plainText[0])];

void ceaserCipherEncry(){
    for(int i = 0; i < len; i++){
        cipherText[i] = ((plainText[i]+KEY)-'A')%26+'A';
    }
    
}
void ceaserCipherDecry() {
    for (int i = 0; i < len; i++) {
        decryText[i] = ((cipherText[i] - KEY - 'A' + 26) % 26) + 'A';
    }
}
int main() {
    
    printf("simulation of hill cipher\n");
    printf("key(shift) : %d\n",KEY);
    printf("plain  text: %s\n",plainText);
    ceaserCipherEncry();
    printf("cipher text: %s\n",cipherText);
    ceaserCipherDecry();
    printf("decrypted text: %s\n",decryText);

    return 0;
}

/*
simulation of hill cipher
key(shift) : 3
plain  text: THISISPLAINTEXT
cipher text: WKLVLVSODLQWHAW
decrypted text: THISISPLAINTEXT
*/
