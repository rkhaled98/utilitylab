/*********************************************************
* vzip.c 
*
* Your Name: Rafi Khaled
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                // printf("%ld", strlen(line));
                // printf("%c \n", *(lineptr++));
                // printf("%c \n", *(lineptr++));
                // printf("%c \n", *(lineptr++));

                char *i;

                if (!prev || prev == '\n')
                {
                    i = (lineptr);
                    lineptr++;
                    prev = *i;
                }

                // char prev;
                for (i = lineptr; *i != '\0'; i++)
                {

                    if (*i != prev)
                    {
                        if (*i == '\n')
                        {
                            printf("%d%c", count, prev);
                            printf("\n");
                            prev = *i;
                            count = 1;
                            // continue;
                        }
                        else
                        {
                            printf("%d%c", count, prev);
                            prev = *i;
                            count = 1;
                        }
                        // fwrite(&count, 4, 1, stdout);
                        // fwrite(&prev, 1, 1, stdout);
                        // use fwrite with 5 bytes? so
                        // fwrite (line, 5, 1, stdout)
                    }
                    else
                    {
                        count++;
                    }

                    // printf("%c", *i);
                    // printf("%d", (*i == 'v'));
                }

                // if (count > 1)
                // {
                //     // fwrite(&count, 4, 1, stdout);
                //     // fwrite(&prev, 1, 1, stdout);
                //     printf("%d%c", count, prev);
                // }

                free(line);
                // free(lineptr);
            }
        }
        // return 0;
        fclose(fp);
    }
    if (count > 1)
    {
        // fwrite(&count, 4, 1, stdout);
        // fwrite(&prev, 1, 1, stdout);
        printf("%d%c", count, prev);
    }
    // if (count > 0)
    // {
    //     // fwrite(&count, 4, 1, stdout);
    //     // fwrite(&prev, 1, 1, stdout);
    //     printf("%d%c", count, prev);
    // }
    return 0;
}
