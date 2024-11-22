#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int modular_exponentiation(int base, int exp, int mod) {
    if (exp == 0)
        return 1; // Base case: anything raised to 0 is 1
    int half = modular_exponentiation(base, exp / 2, mod);
    half = (half * half) % mod; // Square the result
    if (exp % 2 != 0) // If exponent is odd
        half = (half * base) % mod;
    return half;
}


int main() {
  
    int p = 13, q = 17;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 3; // Common choice for e
    while (gcd(e, phi) != 1) {
        e++;
    }

    int k =1,d;
    while (1) {
        if ((1 + k * phi) % e == 0) {
            d = (1 + k * phi) / e;
            break;
        }
        k++;
    }

    printf("decrypt key: %d\n",d);
   
    int msg = 12;

    // Encryption
    int c = modular_exponentiation(msg, e, n);
    printf("Encrypted message = %d\n", c);

    // Decryption
    int m = modular_exponentiation(c, d, n);
    printf("Decrypted message = %d\n", m);

    return 0;
}

/*

decrypt key: 77
Encrypted message = 207
Decrypted message = 12
*/
