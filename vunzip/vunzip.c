/*********************************************************
* vunzip.c 
*
* Your Name: Rafi Khaled
*********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("vunzip: file1 [file2 ...]\n");
        exit(1);
    }

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
            size_t bytes_readn;
            size_t bytes_readi;
            char buf[1];
            int num;

            while (1)
            {
                bytes_readi = fread(&num, sizeof(num), 1, fp);
                bytes_readn = fread(buf, sizeof(buf), 1, fp);

                if (bytes_readi == 0 || bytes_readn == 0)
                {
                    break;
                }

                for (size_t i = 0; i < num; i++)
                {
                    printf("%s", buf);
                }
            }
        }
    }
    return 0;
}
