#include <stdio.h>
int main(void){
    int option;
printf("Calculator Menu\n");
printf("1. Add\n");
printf("2. Subt\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("0. Exit\n");
printf("Choose an option: ");
        scanf("%d", &option);
if (option == 0)
        {
            printf("bye!\n");
            return (0);
        }

        printf("You selected option %d\n\n", option);
return (0);
}