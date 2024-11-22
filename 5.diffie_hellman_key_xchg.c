#include <stdio.h>

int modular_exponentiation(int base, int exp, int mod){
    if (exp == 0)
        return 1; // Base case: anything raised to 0 is 1
    int half = modular_exponentiation(base, exp / 2, mod);
    half = (half * half) % mod; // Square the result
    if (exp % 2 != 0)           // If exponent is odd
        half = (half * base) % mod;
    return half;
}

int main(){
    int P, G, x, a, y, b, ka, kb;

    // Public keys G and P
    P = 13;
    printf("The value of P : %d\n", P);
    G = 6;
    printf("The value of G : %d\n\n", G);

    a = 6;
    printf("The private key a for Alice : %d\n", a);
    x = modular_exponentiation(G, a, P); // Alice's public key
   
    b = 3;
    printf("The private key b for Bob : %d\n\n", b);
    y = modular_exponentiation(G, b, P); // Bob's public key

    // Secret keys
    ka = modular_exponentiation(y, a, P); // Secret key for Alice
    kb = modular_exponentiation(x, b, P); // Secret key for Bob

    printf("Secret key for the Alice is : %d\n", ka);
    printf("Secret Key for the Bob is : %d\n", kb);

    return 0;
}

/*
The value of P : 13
The value of G : 6

The private key a for Alice : 6
The private key b for Bob : 3

Secret key for the Alice is : 12
Secret Key for the Bob is : 12
*/
