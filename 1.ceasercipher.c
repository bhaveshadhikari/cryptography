
#include <stdio.h>
#define KEY 3
char plainText[]="THISTHEPLAINTEXT";
int len = sizeof(plainText)/sizeof(plainText[0])-1;
char cipherText[sizeof(plainText)/sizeof(plainText[0])];

void ceaserCipher(){
    for(int i = 0; i < len; i++){
        cipherText[i] = ((plainText[i]+KEY)-'A')%26+'A';
    }
    
}
int main() {
    
    printf("simulation of hill cipher\n");
    printf("key(shift) : %d\n",KEY);
    printf("plain  text: %s\n",plainText);
    ceaserCipher();
    printf("cipher text: %s\n",cipherText);

    return 0;
}

/*
simulation of hill cipher
key(shift) : 3
plain  text: THISTHEPLAINTEXT
cipher text: WKLVWKHSODLQWHAW
*/
