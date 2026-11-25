
#include <stdio.h>
#include <stdlib.h>

// NORMAL CALCULATOR
void normalCalculator()
{
    int choice;
    double a, b;

    printf("\n--- NORMAL CALCULATOR ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    switch(choice)
    {
        case 1:
            printf("Result = %.2lf", a + b);
            break;

        case 2:
            printf("Result = %.2lf", a - b);
            break;

        case 3:
            printf("Result = %.2lf", a * b);
            break;

        case 4:
            if(b != 0)
                printf("Result = %.2lf", a / b);
            else
                printf("Cannot divide by zero!");
            break;

        case 5:
            if(b != 0)
                printf("Result = %d",
                       (int)a % (int)b);
            else
                printf("Cannot divide by zero!");
            break;

        default:
            printf("Invalid choice!");
    }
}

// NUMBER SYSTEM CALCULATOR
void numberSystemCalculator()
{
    int choice;
    unsigned long long num;
    char str[100];
    char *end;

    printf("\n--- NUMBER SYSTEM CALCULATOR ---\n");
    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Octal\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Binary to Decimal\n");
    printf("5. Octal to Decimal\n");
    printf("6. Hexadecimal to Decimal\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= 3)
    {
        printf("Enter decimal number: ");
        scanf("%llu", &num);

        switch(choice)
        {
            case 1:
                printf("Binary = ");
                if(num == 0)
                    printf("0");
                else
                {
                    int binary[64], i = 0;

                    while(num > 0)
                    {
                        binary[i] = num % 2;
                        num = num / 2;
                        i++;
                    }

                    while(i > 0)
                    {
                        printf("%d", binary[--i]);
                    }
                }
                break;

            case 2:
                printf("Octal = %llo", num);
                break;

            case 3:
                printf("Hexadecimal = %llX", num);
                break;
        }
    }
    else if(choice >= 4 && choice <= 6)
    {
        int base;

        if(choice == 4)
            base = 2;
        else if(choice == 5)
            base = 8;
        else
            base = 16;

        printf("Enter number: ");
        scanf("%99s", str);

        num = strtoull(str, &end, base);

        if(str[0] == '-' || end == str || *end != '\0')
        {
            printf("Invalid number!");
        }
        else
        {
            printf("Decimal = %llu", num);
        }
    }
    else
    {
        printf("Invalid choice!");
    }
}

// MEASUREMENT CALCULATOR
void measurementCalculator()
{
    int from, to;
    double value, meter;
    double units[] = {0.001, 0.01, 1, 1000};

    printf("\n--- MEASUREMENT CALCULATOR ---\n");

    printf("1. Millimeter\n");
    printf("2. Centimeter\n");
    printf("3. Meter\n");
    printf("4. Kilometer\n");

    printf("Enter value: ");
    scanf("%lf", &value);

    printf("Convert from (1-4): ");
    scanf("%d", &from);

    printf("Convert to (1-4): ");
    scanf("%d", &to);

    if(from < 1 || from > 4 ||
       to < 1 || to > 4 || value < 0)
    {
        printf("Invalid input!");
        return;
    }

    meter = value * units[from - 1];

    printf("Converted value = %.4lf",
           meter / units[to - 1]);
}

// MAIN FUNCTION
int main()
{
    int choice;

    do
    {
        printf("\n\n============================\n");
        printf("     ALL IN ONE CALCULATOR\n");
        printf("============================\n");

        printf("1. Normal Calculator\n");
        printf("2. Number System Calculator\n");
        printf("3. Measurement Calculator\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                normalCalculator();
                break;

            case 2:
                numberSystemCalculator();
                break;

            case 3:
                measurementCalculator();
                break;

            case 4:
                printf("Thank you for using calculator!");
                break;

            default:
                printf("Invalid choice! Try again.");
        }

    } while(choice != 4);

    return 0;
}
