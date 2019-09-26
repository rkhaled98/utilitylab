/*********************************************************
* vcat.c 
*
* Your Name: Rafi Khaled
*********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("vcat: cannot open file\n");
            exit(1);
        }
        else
        {
            while (1)
            {
                // allocate 64 bytes
                char *newline = (char *)malloc(64);

                // read 64 characters at most per time
                newline = fgets(newline, 64, fp);

                // fgets has rc value of null when reaching the end of file
                if (newline == NULL)
                {
                    break;
                }

                // print the newline
                printf("%s", newline);

                free(newline);
            }
        }

        fclose(fp);
    }

    return 0;
}
