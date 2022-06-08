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
    // int ncolumns = 0;

    while ((len = mygetline()) > 0)
    {
        replacetabs(len);
        putline();
    }

    return 0;
}

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
            int pos = i;
            for (int j = 0; j < (TABSTOP - ncolumns); ++j)
            {
                ++len;
                // shift elts:
                int z;
                for (z = len-1; z < i; --z)
                {
                    line[z] = line[z - 1];
                }

                line[i] = '_';
            }
            
            // line[i] = ' ';

            // total spaces required = spacesrequired + prev space added:
            // int spacesrequired = TABSTOP - ncolumns;
            // printf("spaces req: %d\n", spacesrequired);
            // char temp;

            // for (int z = 0; z < spacesrequired; ++z)
            // {
            //     // -1 is \0, and -2 is \n:
            //     temp = line[len - 3];
            //     for (int j = len - 3; j > 0; --j)
            //     {
            //         // not checking for overflow!
            //         line[j] = line[j - 1];
            //     }
            //     line[len+z-1] = temp;
            // }
        }
    }
}

int mygetline(void)
{
    extern char line[];

    int c, i;

    for (i = 0; (i < MAXLEN - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c = '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void putline(void){
    printf("%s", line);
}
