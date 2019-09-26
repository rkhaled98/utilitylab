/*********************************************************
* vgrep.c 
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
        printf("vgrep: searchterm [file ...]\n");
        exit(1);
    }

    // the case in which no files are provided - read from stdin
    else if (argc == 2)
    {
        while (1)
        {
            // allocate vars for getline
            char *line = NULL;
            size_t len = 0;
            size_t nread;

            nread = getline(&line, &len, stdin);

            if (nread == -1)
            {
                break;
            }

            // search for the word given
            char *res;
            res = strstr(line, argv[1]);

            // if it is available, then print it
            if (res)
            {
                fwrite(line, nread, 1, stdout);
            }

            free(line);
        }
    }

    else
    {
        for (size_t i = 2; i < argc; i++)
        {
            FILE *fp = fopen(argv[i], "r");

            if (fp == NULL)
            {
                printf("vgrep: cannot open file\n");
                exit(1);
            }
            else
            {
                while (1)
                {
                    // allocate vars for getline
                    char *line = NULL;
                    size_t len = 0;
                    size_t nread;

                    nread = getline(&line, &len, fp);

                    if (nread == -1)
                    {
                        break;
                    }

                    // search for the word given
                    char *res;
                    res = strstr(line, argv[1]);

                    // if it is available, then print it
                    if (res)
                    {
                        fwrite(line, nread, 1, stdout);
                    }

                    free(line);
                }
            }
        }
    }
}
