# Leak report

_Use this document to describe whatever memory leaks
you find in `clean_whitespace.c` and how you might fix
them. You should also probably remove this explanatory
text._

<!-- In this lab, I encountered memory leaks in the strip() function because it allocates memory dynamically using calloc() but doesn't free it later. This caused the program to lose memory as it ran, which would be problematic, especially for long-running programs. Specifically, memory was being allocated for the stripped version of the string, but there was no mechanism to free it once it was no longer needed. -->
<!-- 
Steps I Took to Fix the Memory Errors are:

   1. Fixing the is_clean Function: In the is_clean function, I called strip() to remove leading and trailing whitespace from the string, but I didn't free the memory returned by strip(). To fix this, I made sure to free the memory after comparing the stripped string to the original. If the result was not an empty string (""), I freed the allocated memory to prevent memory leaks.
    2. Fixing the Test Cases: Similarly, in my unit tests, I was calling strip() but wasn't freeing the allocated memory after verifying the test results. To fix this, I ensured that each test case freed the dynamically allocated memory after the test assertions.

By properly freeing memory in both the is_clean function and my test cases, I kinda resolved all memory leaks, as confirmed by running Valgrind. Valgrind reported that all heap memory was freed, and there were no memory leaks left in the program. -->