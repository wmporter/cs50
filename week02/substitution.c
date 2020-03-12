#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    // Exactly 1 command line argument supplied
    if(argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    
    // The argument is 26 
    if(strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    for(int i = 0; i < 26; i++) {
        if(!isalpha(argv[1][i])) {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        key[i] = tolower(argv[1][i]);
    }
    for(int k = 0; k < 26; k++) {
        if(strchr(key, 'a'+k) == NULL) {
            printf("Key must contain each alphabetic character exactly once.\n");
            return 1;
        }
    }
    

    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    for(int j = 0; j < strlen(plain); j++) {
        if(isupper(plain[j]))
            printf("%c", 'A' + key[plain[j] - 'A'] - 'a');
        else if(islower(plain[j]))
            printf("%c", 'a' + key[plain[j] - 'a'] - 'a');
        else
            printf("%c", plain[j]);
    }
    printf("\n");
}