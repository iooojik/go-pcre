#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>

#define OVECCOUNT 30 /* should be a multiple of 3 */

int match_pcre2(const char *pattern, const char *input)
{
    pcre *re;
    const char *error;
    int erroffset;
    int rc;
    int ovector[OVECCOUNT];

    // Compile the regular expression
    re = pcre_compile(pattern, 0, &error, &erroffset, NULL);
    if (re == NULL)
    {
        printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
        return -1;
    }

    // Execute the regular expression match
    rc = pcre_exec(re, NULL, input, strlen(input), 0, 0, ovector, OVECCOUNT);
    if (rc < 0)
    {
        pcre_free(re);
        if (rc == PCRE_ERROR_NOMATCH)
        {
            printf("No match\n");
            return 0;
        }
        else
        {
            printf("Matching error: %d\n", rc);
        }
        return rc;
    }

    // Print match details
    printf("Match succeeded at offset %d\n", ovector[0]);

    // Free the compiled regular expression
    pcre_free(re);

    return 1;
}
