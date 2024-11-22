#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define I 73

char playfairGrid[5][5]={' '};

bool isInGrid( char ptr){
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if(*(*(playfairGrid+i)+j) == ptr)
                return true;
    return false;
}

void railFenceEncry(char a, char b) {
    int iA = -1, jA = -1, iB = -1, jB = -1;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (playfairGrid[i][j] == a ) {
                iA = i;
                jA = j;
            }
            if (playfairGrid[i][j] == b) {
                iB = i;
                jB = j;
            }
        }
    }
    
    if (iA == -1 || jA == -1 || iB == -1 || jB == -1) {
        printf("Characters not found in grid\n");
        return;
    }
    
    // Same row rule
    if (iA == iB) {
        jA = (jA + 1) % 5;
        jB = (jB + 1) % 5;
        printf("%c%c  ", playfairGrid[iA][jA], playfairGrid[iB][jB]);
    }
    // Same column rule
    else if (jA == jB) {
        iA = (iA + 1) % 5;
        iB = (iB + 1) % 5;
        printf("%c%c  ", playfairGrid[iA][jA], playfairGrid[iB][jB]);
    }
    // Rectangular rule
    else {
        // Swap columns while keeping row the same
        printf("%c%c  ", playfairGrid[iA][jB], playfairGrid[iB][jA]);
    }
}

int main(){

    int defaultPtr=65;
    char plain[]= "ENCRYPTION";
    char *plainText = plain;
    int len= strlen(plainText);
    int _=0;
    
    
    while (*plainText != '\0') {
        char current = *plainText;
        
        if (current == 'J') // Replace J with I
            current = 'I';
        
        if (!isInGrid(current)) // Skip if already in grid
            playfairGrid[_/5][_++%5] = current;
    
        plainText++;
    }
   
    while (_ < 25) {
        if (defaultPtr == 'J') defaultPtr++;

        if (!isInGrid(defaultPtr))
            playfairGrid[_/5][_++%5] = defaultPtr;
     
        defaultPtr++;
    }

    printf("GRid : \n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            printf("%c ",playfairGrid[i][j]);
        printf("\n");
    }
    
    printf("\nplaintext: %s\n",plain);
    printf("\ncipher: ");
    for (int i = 0; i < len; i+=2)
    {
        char a = plain[i] == 'J' ? 'I' : plain[i];
        char b = plain[i+1] == 'J' ? 'I' : plain[i+1];

        b = b == '\0' ? 'X' : b;

        railFenceEncry(a,b);
    }
    return 0;
}

/*

GRid : 
E N C R Y 
P T I O A 
B D F G H 
K L M Q S 
U V W X Z 

plaintext: ENCRYPTION

cipher: NC  RY  EA  IO  TR 

*/
