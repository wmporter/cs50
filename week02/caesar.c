#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    // Exactly 1 command line argument supplied
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // The argument is a number
    for(int i = 0; i < strlen(argv[1]); i++) {
        if(argv[1][i] < '0' || argv[1][i] > '9') {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int rot = atoi(argv[1]);

    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    for(int j = 0; j < strlen(plain); j++) {
        if(islower(plain[j]))
            printf("%c", (plain[j] - 'a' + rot) % 26 + 'a');
        else if(isupper(plain[j]))
            printf("%c", (plain[j] - 'A' + rot) % 26 + 'A');
        else
            printf("%c", plain[j]);
    }
    printf("\n");
}