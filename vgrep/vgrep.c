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

    else if (argc == 2)
    {
        while (1)
        {
            char *newline = (char *)malloc(128);

            newline = fgets(newline, 128, stdin);

            if (newline == NULL)
            {
                break;
            }

            char *res = strstr(newline, argv[1]);

            if (res)
            {
                printf("%s", newline);
            }

            free(newline);
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
                    char *line = NULL;
                    size_t len = 2;
                    size_t nread;

                    nread = getline(&line, &len, fp);

                    if (nread == -1)
                    {
                        break;
                    }

                    char *res;
                    res = strstr(line, argv[1]);

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
