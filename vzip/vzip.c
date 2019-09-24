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

                char *i = (lineptr);
                lineptr++;

                char prev = *i;

                int count = 1;

                // char prev;
                for (i = lineptr; *i; i++)
                {
                    if (*i != prev)
                    {
                        printf("%d%c", count, prev);
                        prev = *i;
                        count = 0;
                    }
                    else
                    {
                        count++;
                    }

                    // printf("%c", *i);
                    // printf("%d", (*i == 'v'));
                }
                if (count > 0)
                {
                    printf("%d%c", count, prev);
                }

                // char *res;
                // res = strstr(line, argv[1]);

                // if (res)
                // {
                //     fwrite(line, nread, 1, stdout);
                // }

                free(line);
            }
        }
        // return 0;
        fclose(fp);
    }
    return 0;
}
