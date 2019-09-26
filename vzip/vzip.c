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
                char *line = NULL;
                size_t len = 0;
                size_t nread;

                nread = getline(&line, &len, fp);

                if (nread == -1)
                {
                    break;
                }

                char *lineptr = line;
                char *i;

                if (!prev)
                {
                    i = (lineptr);
                    lineptr++;
                    prev = *i;
                }

                for (i = lineptr; *i != '\0'; i++)
                {

                    if (*i != prev)
                    {
                        fwrite(&count, 4, 1, stdout);
                        fwrite(&prev, 1, 1, stdout);

                        prev = *i;
                        count = 1;
                    }
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

    if (count > 1 || prev == '\n')
    {
        fwrite(&count, 4, 1, stdout);
        fwrite(&prev, 1, 1, stdout);
    }

    return 0;
}
