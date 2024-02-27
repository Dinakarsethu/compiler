#include <stdio.h>
#include <regex.h>

int main() {
    regex_t digit_regex, word_regex;
    regmatch_t match;
    char text[100];

    // Compile the regular expressions
    regcomp(&digit_regex, "[0-9]+", REG_EXTENDED);
    regcomp(&word_regex, "[a-zA-Z]+", REG_EXTENDED);

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Iterate through the text, matching digits and words
    while (regexec(&digit_regex, text, 1, &match, 0) == 0) {
        printf("Number: %.*s\n", match.rm_eo - match.rm_so, text + match.rm_so);
        text += match.rm_eo;  // Move to the end of the matched text
    }

    while (regexec(&word_regex, text, 1, &match, 0) == 0) {
        printf("Word: %.*s\n", match.rm_eo - match.rm_so, text + match.rm_so);
        text += match.rm_eo;
    }

    // Free the compiled regular expressions
    regfree(&digit_regex);
    regfree(&word_regex);

    return 0;
}
