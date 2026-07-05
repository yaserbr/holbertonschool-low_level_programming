#include <stdio.h>

int main(void) {
    int option = -1;

    while (option != 0) {
        printf("Calculator Menu\n");
        printf("1. Add\n");
        printf("2. Subt\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &option);

        if (option == 0) {
            printf("Bye!\n");
            return 0;
        } 
        else if (option < 0 || option > 4) {
            printf("Invalid choice\n");
        } 
        else {
            printf("You selected option %d\n\n", option);
        }
    }

    return 0;
}