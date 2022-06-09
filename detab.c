//* cd "C:\Users\Jalal\OneDrive\Programing\C\detab" && gcc -o output "detab.c" && output

#include <stdio.h>

#define TABSTOP 8
#define MAXLEN 1000

void replacetabs(int len);
int mygetline(void);
void putline(void);

char line[MAXLEN];

int main()
{
    extern char line[];
    int len;

    while ((len = mygetline()) > 0)
    {
        replacetabs(len);
        putline();
    }

    return 0;
}

/**
 * @brief Replace every tab character with the corresponding number of spaces.
 *
 * @param len length of line input.
 */
void replacetabs(int len)
{
    extern char line[];

    int i;
    int ncolumns = 0;

    for (i = 0; i < len; ++i)
    {
        ++ncolumns;
        if (ncolumns == TABSTOP)
        {
            ncolumns = 0;
        }

        if (line[i] == '\t')
        {

            int spacesneeded = (TABSTOP - ncolumns);
            int pos = i;

            while (spacesneeded > 0)
            {
                line[pos] = ' ';

                for (int j = len - 1; j > i; --j)
                {
                    //! no overflow checking - MAXLEN:
                    line[j + 1] = line[j];
                }

                --spacesneeded;
                ++pos;
                ++len;
            }
        }
    }
}

/**
 * @brief get a line of input, defined by a newline.
 *
 * @return int length of input line.
 */
int mygetline(void)
{
    int c, i;

    extern char line[];

    for (i = 0; (i < MAXLEN - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
    {
        line[i] = c;
    }

    if (c = '\n')
    {
        line[i] = c;
        // ++i;
    }

    line[i + 1] = '\0';

    return i;
}

/**
 * @brief Prints line as a string. Takes no args.
 *
 */
void putline(void)
{
    printf("%s\n", line);
}
