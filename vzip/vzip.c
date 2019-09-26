/*********************************************************
* vzip.c 
*
* Your Name: Rafi Khaled
*********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("vzip: file1 [file2 ...]\n");
        exit(1);
    }

    // set up the default counts and values for vars
    int count = 1;
    char prev = '\0';

    for (size_t i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("vzip: cannot open file\n");
            exit(1);
        }
        else
        {

            while (1)
            {
                // set up the vars for getline
                char *line = NULL;
                size_t len = 0;
                size_t nread;

                nread = getline(&line, &len, fp);

                if (nread == -1)
                {
                    break;
                }

                // we have a lineptr to the line to use in the for loop
                char *lineptr = line;
                // this will be our variable for the for loop
                char *i;

                // if we do not have a previous character stored, then
                // lets initialize things!
                if (!prev)
                {
                    i = (lineptr);
                    lineptr++;
                    prev = *i;
                }

                for (i = lineptr; *i != '\0'; i++)
                {
                    // if the previous character is not the same as the current one,
                    // then we need to record the previous and the count
                    if (*i != prev)
                    {
                        fwrite(&count, 4, 1, stdout);
                        fwrite(&prev, 1, 1, stdout);

                        prev = *i;
                        count = 1;
                    }
                    // otherwise, keep counting up
                    else
                    {
                        count++;
                    }
                }

                free(line);
            }
        }
        fclose(fp);
    }

    // the other cases are if, for example there is a newline that ends the file, then still record that.
    if (count > 1 || prev == '\n')
    {
        fwrite(&count, 4, 1, stdout);
        fwrite(&prev, 1, 1, stdout);
    }

    return 0;
}
