#include <stdio.h>
#include <stdlib.h>

extern char const *strip(char const *str);
extern int is_clean(char const *str);

int main() {
    char const *strings[] = {
        "Morris", 
        "  stuff", 
        "Minnesota", 
        "nonsense  ", 
        "USA", 
        "   ", 
        "     silliness    "
    };

    for (int i = 0; i < 7; ++i) {
        char const *s = strings[i];
        if (is_clean(s)) {
            printf("The string '%s' is clean.\n", s);
        } else {
            printf("The string '%s' is NOT clean.\n", s);
        }
    }

    return 0;
}
