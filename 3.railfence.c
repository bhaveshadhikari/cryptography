#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define size 10
char plainText[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int len = sizeof(plainText)/sizeof(plainText[0])-1;
char railFence[size][sizeof(plainText)/sizeof(plainText[0])-1];
char railFenceCipher[size][sizeof(plainText)/sizeof(plainText[0])-1];
char railFenceDecry[size][sizeof(plainText)/sizeof(plainText[0])-1];
char cipherText[sizeof(plainText)/sizeof(plainText[0])];
char decryptedText[sizeof(plainText)/sizeof(plainText[0])];

void createRailFence(){
    int ptr = 0;
    bool decrease = false;
    
    for(int i= 0; i < len; i++){
        railFence[ptr][i]='x';
        
        if (ptr == 0) decrease = false;
        if (ptr == size-1) decrease = true;
        
        ptr = (decrease == true)? ptr-1 : ptr+1;
    }
}

void railFenceEncryption(){
    int x = 0;
    //traverse columnwise
    for(int i = 0; i<len;i++)
        for(int j = 0; j< size; j++)
            if (railFence[j][i] == 'x')
                railFenceCipher[j][i] = plainText[x++];
                x++;
    
    int y = 0;
    for(int i = 0; i<size;i++)
        for(int j = 0; j< len; j++)
            if(railFenceCipher[i][j]>='A' && railFenceCipher[i][j]<='Z')
                cipherText[y++] = railFenceCipher[i][j];
    
}

void railFenceDecryption(){
    int x = 0;
    //traverse rowwise
    for(int i = 0; i<size;i++)
        for(int j = 0; j< len; j++)
            if (railFence[i][j] == 'x')
                railFenceDecry[i][j] = cipherText[x++];
                x++;
    
    int y = 0;
    for(int i = 0; i<len;i++)
        for(int j = 0; j< size; j++)
            if(railFenceDecry[j][i]>='A' && railFenceDecry[j][i]<='Z')
                decryptedText[y++] = railFenceDecry[j][i];
            
}

int main(){
    memset(railFence,'.',sizeof(railFence));
    memset(railFenceCipher,'.',sizeof(railFenceCipher));
    memset(railFenceDecry,'.',sizeof(railFenceDecry));
    printf("plain text: %s\n",plainText);
    createRailFence();
    printf("general rail fence grid for %d rails:\n",size );
    for(int i = 0; i<size;i++){
        for(int j = 0; j< len; j++){
            printf("%c ",railFence[i][j]);
        }
        printf("\n");
    }
    railFenceEncryption();
    printf("cipher rail fence grid:\n");
    for(int i = 0; i<size;i++){
        for(int j = 0; j< len; j++){
            printf("%c ",railFenceCipher[i][j]);
        }
        printf("\n");
    }
    printf("cipher text: %s\n",cipherText);
    
    
    railFenceDecryption();
    
    printf("decryption rail fence grid:\n");
    for(int i = 0; i<size;i++){
        for(int j = 0; j< len; j++){
            printf("%c ",railFenceDecry[i][j]);
        }
        printf("\n");
    }
    printf("decry text: %s\n",decryptedText);
    return 0;
}

/*
plain text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
general rail fence grid for 5 rails:
x . . . . . . . x . . . . . . . x . . . . . . . x . 
. x . . . . . x . x . . . . . x . x . . . . . x . x 
. . x . . . x . . . x . . . x . . . x . . . x . . . 
. . . x . x . . . . . x . x . . . . . x . x . . . . 
. . . . x . . . . . . . x . . . . . . . x . . . . . 
cipher rail fence grid:
A . . . . . . . I . . . . . . . Q . . . . . . . Y . 
. B . . . . . H . J . . . . . P . R . . . . . X . Z 
. . C . . . G . . . K . . . O . . . S . . . W . . . 
. . . D . F . . . . . L . N . . . . . T . V . . . . 
. . . . E . . . . . . . M . . . . . . . U . . . . . 
cipher text: AIQYBHJPRXZCGKOSWDFLNTVEMU
decryption rail fence grid:
A . . . . . . . I . . . . . . . Q . . . . . . . Y . 
. B . . . . . H . J . . . . . P . R . . . . . X . Z 
. . C . . . G . . . K . . . O . . . S . . . W . . . 
. . . D . F . . . . . L . N . . . . . T . V . . . . 
. . . . E . . . . . . . M . . . . . . . U . . . . . 
decry text: ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
