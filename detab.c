//* cd "C:\Users\Jalal\OneDrive\Programing\C\detab" && gcc -o output "detab.c" && output

#include <stdio.h>

void replacetabs();

int main()
{

    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 0; i < 4; i++)
            {
                replacetabs();
            }
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}

void replacetabs()
{
    putchar(' ');
}
