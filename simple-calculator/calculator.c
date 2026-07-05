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

        switch (option) {
            case 0:
                printf("Bye!\n");
                return 0;
            
            case 1: { /* فتح أقواس معقوفة ضروري لتعريف متغيرات جديدة هنا حسب معيار gnu89 */
                int a, b, sum;
                
                printf("A: ");
                scanf("%d", &a);
                
                printf("B: ");
                scanf("%d", &b);
                
                sum = a + b;
                printf("Result: %d\n\n", sum);
                
                break;
            }
            
            case 2:
                printf("You selected option 2 (Subtract)\n\n");
                break;
            
            case 3:
                printf("You selected option 3 (Multiply)\n\n");
                break;
            
            case 4:
                printf("You selected option 4 (Divide)\n\n");
                break;
            
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }

    return 0;
}