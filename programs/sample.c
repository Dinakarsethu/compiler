#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50

// Function to check if a character is a valid operator
int is_operator(char ch) {
    char operators[] = "+-*/%=><!";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

// Function to check if a character is a valid delimiter
int is_delimiter(char ch) {
    char delimiters[] = " \t\n";
    for (int i = 0; i < strlen(delimiters); i++) {
        if (ch == delimiters[i])
            return 1;
    }
    return 0;
}

// Function to check if a character is a valid alphanumeric character
int is_alphanumeric(char ch) {
    return isalnum(ch) || ch == '_';
}

// Function to analyze the input string
void lexical_analyzer(char input[]) {
    int len = strlen(input);
    int i = 0;
    while (i < len) {
        // Ignore white spaces, tabs, and new lines
        if (isspace(input[i])) {
            i++;
            continue;
        }
        // Ignore comments
        if (input[i] == '/' && i + 1 < len && input[i + 1] == '/') {
            // Skip until the end of the line
            while (i < len && input[i] != '\n')
                i++;
            continue;
        }
        // Identify identifiers
        if (isalpha(input[i]) || input[i] == '_') {
            char identifier[MAX_IDENTIFIER_LENGTH + 1] = ""; // +1 for null terminator
            int j = 0;
            while (i < len && is_alphanumeric(input[i]) && j < MAX_IDENTIFIER_LENGTH) {
                identifier[j++] = input[i++];
            }
            identifier[j] = '\0'; // Null terminate the identifier
            printf("Identifier: %s\n", identifier);
            continue;
        }
        // Identify constants
        if (isdigit(input[i])) {
            char constant[20] = ""; // Assuming constant length <= 20
            int j = 0;
            while (i < len && isdigit(input[i])) {
                constant[j++] = input[i++];
            }
            constant[j] = '\0'; // Null terminate the constant
            printf("Constant: %s\n", constant);
            continue;
        }
        // Identify operators
        if (is_operator(input[i])) {
            printf("Operator: %c\n", input[i++]);
            continue;
        }
        // Move to the next character if none of the above conditions are met
        i++;
    }
}

int main() {
    char input[] = "int main() {\n// This is a comment\nint x = 10;\nint y = 20;\nprintf(\"Sum: %d\", x+y);\n}";
    lexical_analyzer(input);
    return 0;
}