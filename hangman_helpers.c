#include "hangman_helpers.h"

bool is_lowercase_letter(char c) {
    if (c > 96 && c < 123)
        return true;
    else
        return false;
}

bool is_valid_secret(const char *secret) {
    // is only getting the first letter
    int x = 0;
    while (*(secret + x) != 0) {
        if (*(secret + x) != '-' && *(secret + x) != '\'' && *(secret + x) != ' '
            && !is_lowercase_letter(*(secret + x))) {
            printf("invalid character: '%c'\n", *(secret + x));
            printf("the secret phrase must contain only lowercase letters, spaces, hyphens, and "
                   "apostrophes\n");
            return false;
        }
        x++;
    }

    if (x > 256) {
        printf("the secret phrase is over 256 characters\n");
        return false;
    }
    return true;
}

bool string_contains_character(const char *s, char c) {
    int x = 0;
    while (*(s + x) != 0) {
        if (*(s + x) == c) {
            return true;
        }
        x++;
    }
    return false;
}

char read_letter(void) {
    char guess = '\n';
    printf("Guess a letter: ");
    while (guess == '\n') {
        scanf("%c", &guess);
    }
    return guess;
}

void display_art(int count) {
    // int a = 0;
    // while (*(arts[count]+a) != 0) {
    //     printf("%c", *(arts[count]+a));
    //     a++;
    // }
    printf("%s", arts[count]);
}

void print_e(char eliminated[]) {
    printf("Eliminated: ");
    for (int k = 0; k < LOSING_MISTAKE; k++) {
        if (eliminated[k] != '{') {
            printf("%c", eliminated[k]);
        }
    }
    printf("\n\n");
}

void print_eliminated(char eliminated[], int length) {
    printf("Eliminated: ");
    int min;
    for (int i = 0; i < length - 1; i++) {

        min = i;
        for (int j = i + 1; j < length; j++) {
            if (eliminated[j] < eliminated[i]) {
                min = j;
                char temp = eliminated[i];
                eliminated[i] = eliminated[min];
                eliminated[min] = temp;
            }
        }
    }
    // print

    for (int k = 0; k < length; k++) {
        if (eliminated[k] != '{') {
            printf("%c", eliminated[k]);
        }
    }

    printf("\n\n");
}

void print_phrase(char display[], int length) {
    printf("\n");
    printf("    Phrase: ");
    for (int k = 0; k < length; k++) {
        if (display[k] != 0) {
            printf("%c", display[k]);
        }
    }
    printf("\n");
}

bool array_contains_character(char eliminated[], int length, char c) {
    for (int k = 0; k < length; k++) {
        if (eliminated[k] == c) {
            return true;
        }
    }
    return false;
}
