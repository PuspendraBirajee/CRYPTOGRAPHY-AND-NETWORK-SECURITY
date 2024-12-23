//Stream Ciphers
//1.1)Write a C Program to implement Shift Cipher

#include <stdio.h>
#include <string.h>

// Function to encrypt the plain text using Shift Cipher
void encryption(char plainText[], int key, char ciphertext[]) {
    int i;
    for (i = 0; i < strlen(plainText); i++) {
        char ch = plainText[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + key) % 26 + 'a';
        }
        // Leave other characters unchanged (e.g., punctuation, spaces)
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

// Function to decrypt the ciphertext back to plain text
void decryption(char ciphertext[], int key, char decryptedText[]) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        char ch = ciphertext[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            decryptedText[i] = (ch - 'A' - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            decryptedText[i] = (ch - 'a' - key + 26) % 26 + 'a';
        }
        // Leave other characters unchanged (e.g., punctuation, spaces)
        else {
            decryptedText[i] = ch;
        }
    }
    decryptedText[i] = '\0'; // Null-terminate the decrypted text string
}

int main() {
    char plainText[50], ciphertext[50], decryptedText[50];
    int key;

    // Read the plaintext
    printf("Enter the Plain text: ");
    scanf("%[^\n]", plainText);  // Read input including spaces

    // Read the key
    printf("Enter the key (integer value): ");
    scanf("%d", &key);

    // Perform encryption
    encryption(plainText, key, ciphertext);
    printf("\nEncrypted text (Ciphertext): %s\n", ciphertext);

    // Perform decryption
    decryption(ciphertext, key, decryptedText);
    printf("Decrypted text (Plaintext): %s\n", decryptedText);

    return 0;
}

