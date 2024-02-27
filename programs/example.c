#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100  // Adjust as needed

int find_longest_word_length(const char *str) {
    int current_word_length = 0;
    int max_word_length = 0;

    while (*str != '\0') {
        // Check for word start
        if (isalpha(*str)) {
            current_word_length = 1;  // Initialize for the first character
        }

        // Increment word length only within a word
        if (current_word_length > 0 && isalpha(*str)) {
            current_word_length++;
        }

        // Update max length if necessary
        if (current_word_length > max_word_length) {
            max_word_length = current_word_length;
        }

        str++;  // Move to the next character
    }

    return max_word_length;
}

int main() {
    char str[100];  // Adjust size as needed

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline, if present
    str[strcspn(str, "\n")] = '\0';

    int longest_word_length = find_longest_word_length(str);

    if (longest_word_length > 0) {
        printf("Length of the longest word: %d\n", longest_word_length);
    } else {
        printf("No words found in the string.\n");
    }

    return 0;
}