#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int msgLen = strlen(message);
    char encrypted[msgLen];

    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int row = col; row < msgLen; row += key) {
            encrypted[index++] = message[row];
        }
    }

    encrypted[index] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char encrypted[], int key) {
    int msgLen = strlen(encrypted);
    char decrypted[msgLen];

    int numRows = msgLen / key;
    if (msgLen % key != 0) {
        numRows++;
    }

    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int row = col; row < msgLen; row += key) {
            decrypted[row] = encrypted[index++];
        }
    }

    decrypted[msgLen] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100];
    int key;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove newline character

    printf("Enter the key (number of columns): ");
    scanf("%d", &key);

    encrypt(message, key);

    // For simplicity, we'll use the same function to get the encrypted message again
    char encrypted[100];
    printf("Enter the encrypted message for decryption: ");
    scanf("%s", encrypted);

    decrypt(encrypted, key);

    return 0;
}
