#include <gtest/gtest.h>
#include <string.h>
#include <stdlib.h>

extern char const *strip(char const *str);
extern int is_clean(char const *str);

TEST(Strip, WhitespaceOnBothEnds) {
    char *result = (char *)strip("  frog     ");
    ASSERT_STREQ("frog", result);
    free(result);  // Free the allocated memory
}

TEST(IsClean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(IsClean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("  frog"));
}

TEST(IsClean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("frog  "));
}

TEST(IsClean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean("  frog  "));
}
