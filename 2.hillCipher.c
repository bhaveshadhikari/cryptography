#include<stdio.h>

int key[][2]= {{3,3},{2,5}};

int invKey[][2]= {{15,17},{20,9}};

char plainText[]="HELPMECONQUER";
int len = sizeof(plainText)/sizeof(plainText[0])-1;
char cipherText[sizeof(plainText)/sizeof(plainText[0])];

char decryptedText[sizeof(plainText)];

void hillCipherEncryption() {

	if (len%2 !=0) plainText[len++]='X';

	for(int i = 0; i < len ; i+=2) {

		cipherText[i] = (key[0][0]*(plainText[i]-'A')+key[0][1]*(plainText[i+1]-'A'))%26+'A';
		cipherText[i+1] = (key[1][0]*(plainText[i]-'A')+key[1][1]*(plainText[i+1]-'A'))%26+'A';
	}
	cipherText[len]='\0';
}

void hillCipherDecryption() {
	for(int i = 0; i < len ; i+=2) {

		decryptedText[i] = (invKey[0][0]*(cipherText[i]-'A')+invKey[0][1]*(cipherText[i+1]-'A'))%26+'A';
		decryptedText[i+1] = (invKey[1][0]*(cipherText[i]-'A')+invKey[1][1]*(cipherText[i+1]-'A'))%26+'A';

	}
	decryptedText[len]='\0';

}

int main() {
	printf("plain text:   %s\n",plainText);
	hillCipherEncryption();
	printf("cipher text:  %s\n",cipherText);
	hillCipherDecryption();
	printf("decrypted :   %s",decryptedText);
	return 0;
}

/*
plain text:   HELPMECONQUER
cipher text:  HIATWSWWJCUIQT
decrypted :   HELPMECONQUERX
*/
}
