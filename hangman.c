#include "hangman_helpers.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // check the number of inputs
    if (argc != 2)
        return 1;

    if (!is_valid_secret(argv[1]))
        return 1;

    char eliminated[LOSING_MISTAKE] = { '{', '{', '{', '{', '{', '{' };
    char *secret = argv[1];

    int count = 0;
    char guess;
    // printf("%lu\n", sizeof(secret));
    //convert to array of char
    int j = 0;
    int length = (int) strlen(secret);
    char display[length];

    while (*(secret + j) != 0) {
        display[j] = *(secret + j);
        j++;
    }

    for (int k = 0; k < length; ++k) {
        if (display[k] != '-' && display[k] != '\'' && display[k] != ' ') {
            display[k] = '_';
        }
    }
    // to convert
    char *p = &display[0];
    int flag = 1;

    display_art(count);
    print_phrase(display, length);
    printf("Eliminated: \n\n");
    // print_e(eliminated);
    // print_eliminated(eliminated, LOSING_MISTAKE);

    while (string_contains_character(p, '_')) {
        guess = read_letter();
        // checks if the character has been guessed before, if so prompt the user again
        while (array_contains_character(eliminated, LOSING_MISTAKE, guess)
               || array_contains_character(display, length, guess) || !is_lowercase_letter(guess)) {
            guess = read_letter();
        }
        // checks whether secret phrase contains the character
        if (!string_contains_character(secret, guess)) {
            eliminated[count] = guess;
            count++;
        } else {
            //update display
            for (int k = 0; k < (int) strlen(secret); k++) {
                if (*(secret + k) == guess) {
                    display[k] = guess;
                }
            }
        }

        display_art(count);
        print_phrase(display, length);
        // int n = sizeof(eliminated)/sizeof(eliminated[0]);
        print_eliminated(eliminated, LOSING_MISTAKE);
        // print_e(eliminated);
        // print_eliminated(eliminated, n);

        if (count >= LOSING_MISTAKE) {
            flag = 0;
            printf("You lose! The secret phrase was: %s\n", secret);
            break;
        }
    }

    if (flag) {
        printf("You win! The secret phrase was: %s\n", secret);
    }

    return 0;
}
