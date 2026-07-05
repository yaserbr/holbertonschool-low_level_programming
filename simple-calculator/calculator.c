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
            
            case 1: { 
                int a, b, sum;
                
                printf("A: ");
                scanf("%d", &a);
                
                printf("B: ");
                scanf("%d", &b);
                
                sum = a + b;
                printf("Result: %d\n\n", sum);
                break;
            }
            
            case 2: { /* تمت إضافة الأقواس هنا */
                int a, b, result;
                
                printf("A: ");
                scanf("%d", &a);
                
                printf("B: ");
                scanf("%d", &b);
                
                result = a - b;
                printf("Result: %d\n\n", result);
                break;
            }
            
            case 3: { 
                int a, b, result;
                
                printf("A: ");
                scanf("%d", &a);
                
                printf("B: ");
                scanf("%d", &b);
                
                result = a * b;
                printf("Result: %d\n\n", result);
                break;
            }
            
            case 4: { 
                int a, b, result;
                
                printf("A: ");
                scanf("%d", &a);
                
                printf("B: ");
                scanf("%d", &b);
                
              
                if (b == 0) {
                    printf("Error: Cannot divide by zero\n\n");
                } else {
                    result = a / b;
                    printf("Result: %d\n\n", result);
                }
                break;
            }
            
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }

    return 0;
}