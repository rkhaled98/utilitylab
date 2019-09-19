/*********************************************************
* vcat.c 
*
* Your Name: Rafi Khaled
*********************************************************/
#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    int i;
    for (i=1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
                printf("vcat: cannot open file\n");
                exit(1);
        }
        else{
            char *newline = malloc(300);
            char *line;
            while (1) {
                line = fgets(newline, 300, fp);

                if (line == NULL){
                    break;
                }

                printf("%s", line);
                free(newline);
                newline = malloc(64);
            }

        }

        fclose(fp);
        
        }

        return 0;
    

    
}
