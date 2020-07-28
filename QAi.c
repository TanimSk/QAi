#include <stdio.h>
#include <string.h>
int main()
{
    int i, j;
    FILE *p;
    char string[150]="", string_handle[150]="";
    p = fopen("QA.qa", "a+");

    while(1){
        fseek(p, 0, 0);
        j = 1;
        printf("\nask< ");
        gets(string);
        if(strcmp(string, "exit")==0){
            fclose(p);
            break;
        }
        strcat(string, "\n");
        while(fgets(string_handle, 150, p)){
            if(strcmp(string, string_handle)==0){
                fgets(string_handle, 150, p);
                printf("\nans> %s\n", string_handle);
                j=0;
            }
        }                                    ////OK

        if(j==1){
            fprintf(p, "%s", string);
            printf("\nTeach me< ");
            gets(string_handle);
            fprintf(p, "%s\n", string_handle);
        }

    }
    return 0;
}
