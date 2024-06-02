#include "main.h"

int main()
{
    int32_t select = '\0';
    int32_t num = 0;
    uint8_t base = 0;
    char input_string[100];

    while(1)
    {
        system("cls");
        menu();
        printf("\nEnter your selection: ");
        select = getche();
        switch(select)
        {
            case '1':
            {
                char *result = NULL;
                get_input_num(&num);
                get_input_base(&base);
                result = convert_decimal_to_other(num, base);
                printf("\nResult is: %s", result);
                break;
            }
            case '2':
            {
                uint32_t result = 0;
                get_input_base(&base);
                get_input_string(input_string, base);
                result = convert_other_base_to_decimal(input_string, base);
                printf("\nResult is: %u", result);
                break;
            }
            case '3':
            {
                char *result = NULL;
                uint8_t base = 2;
                get_input_string(input_string, base);
                binary_to_octal(input_string, &result);
                printf("\nResult is: %s", result);
                free(result);
                break;

            }
            case '4':
            {
                char *result = NULL;
                uint8_t base = 2;
                get_input_string(input_string, base);
                binary_to_hex(input_string, &result);
                printf("\nResult is: %s", result);
                free(result);
                break;

            }
            case '5':
            {
                printf("\nSee you again");
                return 0;
            }
        }
        getch();
    }
    return 0;
}