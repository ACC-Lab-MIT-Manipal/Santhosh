#include <stdio.h>

// Initial permutation (IP) table
int IP[] = {1, 5, 2, 0, 3, 7, 4, 6};

// Inverse initial permutation (IP^-1) table
int IP_INV[] = {3, 0, 2, 4, 6, 1, 7, 5};

// Perform initial permutation
unsigned char initialPermutation(unsigned char input) {
    unsigned char output = 0;
    for (int i = 0; i < 8; i++) {
        output |= ((input >> (7 - IP[i])) & 0x01) << i;
    }
    return output;
}

// Perform inverse initial permutation
unsigned char inverseInitialPermutation(unsigned char input) {
    unsigned char output = 0;
    for (int i = 0; i < 8; i++) {
        output |= ((input >> (7 - IP_INV[i])) & 0x01) << i;
    }
    return output;
}

// Encrypt using SDES
unsigned char encryptSDES(unsigned char plaintext, unsigned char key) {
    // Initial permutation
    unsigned char permutedPlaintext = initialPermutation(plaintext);

    // Your SDES encryption logic here...

    // Inverse initial permutation
    unsigned char ciphertext = inverseInitialPermutation(permutedPlaintext);
    return ciphertext;
}

// Decrypt using SDES
unsigned char decryptSDES(unsigned char ciphertext, unsigned char key) {
    // Your SDES decryption logic here...
}

int main() {
    unsigned char key = 0x1A; // 8-bit key for SDES
    unsigned char plaintext = 'C'; // Change this to your desired plaintext character

    // Encryption
    unsigned char encrypted = encryptSDES(plaintext, key);
    printf("Encrypted: 0x%X\n", encrypted);

    // Decryption
    unsigned char decrypted = decryptSDES(encrypted, key);
    printf("Decrypted: %c\n", decrypted);

    return 0;
}
