#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Strips spaces from both the front and back of a string,
 * leaving any internal spaces alone.
 */
char const *strip(char const *str) {
    int size = strlen(str);

    // Count the number of leading and trailing spaces
    int first_non_space = 0;
    while (first_non_space < size && str[first_non_space] == ' ') {
        ++first_non_space;
    }

    int last_non_space = size - 1;
    while (last_non_space >= 0 && str[last_non_space] == ' ') {
        --last_non_space;
    }

    // If the string is just spaces, return an empty string
    if (first_non_space > last_non_space) {
        return "";
    }

    // Allocate space for the resulting stripped string
    int new_size = last_non_space - first_non_space + 1;
    char *result = (char *) calloc(new_size + 1, sizeof(char)); // +1 for null terminator

    // Copy the trimmed portion
    strncpy(result, &str[first_non_space], new_size);
    result[new_size] = '\0';  // Null-terminate the new string

    return result;  // The caller is responsible for freeing this memory
}

/*
 * Return true (1) if the given string is "clean", i.e., has
 * no spaces at the front or the back of the string.
 */
int is_clean(char const *str) {
    char const *cleaned = strip(str);  // Dynamically allocated string

    // Compare the original string with the cleaned one
    int result = strcmp(str, cleaned);

    // Free the memory allocated by strip (if not returning "")
    if (cleaned[0] != '\0') {
        free((void *)cleaned);
    }

    return result == 0;
}
