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
    // char *find = argv[1];
    // printf("%s", find);
    // printf("%d", argc);
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
                    // allocate 64 bytes
                    char *newline = (char *)malloc(256);

                    // read 64 characters at most per time
                    newline = fgets(newline, 256, fp);

                    // fgets has rc value of null when reaching the end of file
                    if (newline == NULL)
                    {
                        break;
                    }

                    char *res;
                    res = strstr((char *)newline, (char *)argv[1]);

                    // printf("%s", res);

                    if (res)
                    {
                        printf("%s", newline);
                    }
                    // else
                    // {
                    //     printf("%s", "hello");
                    //     // printf("%s", newline);
                    // }

                    free(newline);
                }
            }
        }
    }

    // char *arg1 = argv[2];
    // printf("%s", arg1);
    // return 0;
}
