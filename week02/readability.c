#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string s = get_string("Text: ");
    int letter_ct = 0;
    int word_ct = 0;
    int sent_ct = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            letter_ct ++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            letter_ct ++;
        }
        else if(s[i] == '?' || s[i] == '.' || s[i] == '!') {
            sent_ct ++;
        }
        else if(s[i] == ' ') {
            word_ct ++;
        }
    }
    // The word count so far just counts spaces, but there is 1 more word than spaces
    word_ct++;
    float L = (float)letter_ct / word_ct * 100;
    float S = (float)sent_ct / word_ct * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    if(index < 1.0) {
        printf("Before Grade 1\n");
    }
    else if(index >= 16.0) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", (int)(index + 0.5));
    }
}