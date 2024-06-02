#include "main.h"


void menu()
{

    printf("\n\t\t\tCONVERT BASE PROGRAM\n\n");
    printf("----------------------------------------------------------------\n\n");
    printf("1.Convert decimal to other base\n");
    printf("2.Convert other base to decimal\n");
    printf("3.Convert binary to octal\n");
    printf("4.Convert binary to hexa\n");
    printf("5.Convert octal to binary\n");
    printf("6.Exit program\n");
}

bool check_hexa(char *str)
{
    for (int8_t i = 0; str[i] != '\0'; i++)
    {
        if (!isxdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
bool check_other_base(char *str)
{
    for (int8_t i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
bool check_binary(char *str)
{
    for (int8_t i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] == '0' || str[i] == '1'))
        {
            return false;
        }
    }
    return true;
}
void check_string_input(char *str, check_string func)
{
    while (!func(str))
    {
        printf("\nRe-enter input which is correct: ");
        fgets(str, sizeof(str), stdin);
        if (str[strlen(str) - 1] == '\n')
        {
            str[strlen(str) - 1] = '\0';
        }
    }
}

void get_input_string(char *str, uint8_t base)
{
    printf("\nEnter input string: ");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
    switch (base)
    {
        case 2:
        {
            check_string_input(str, check_binary);
            break;
        }
        case 16:
        {
            check_string_input(str, check_hexa);
            break;
           
        } 
        default:
        {
            check_string_input(str, check_other_base);
            break;
        }
    }
}

void get_input_base(uint8_t *base)
{
    int8_t check = 0;
    do
    {
        printf("\nEnter base wanted convert (base > 1): ");
        check = (int8_t)scanf("%hhu", base);
        while (getchar() != '\n')
            ;
    } while (check == 0 || *base == 1);
}
void get_input_num(int32_t *num)
{
    int8_t check = 0;
    do
    {
        printf("\nEnter number: ");
        check = (int8_t)scanf("%d", num);
        while (getchar() != '\n')
            ;
    } while (*num < 0 || check == 0);
}
char *convert_decimal_to_other(int32_t num, uint8_t base)
{
    static char buffer[33];
    if (num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }
    else
    {
        uint8_t len = 0, last = 0;
        char hex[] = "0123456789abcdef";
        while (num > 0)
        {
            last = (uint8_t)(num % base);
            buffer[len++] = hex[last];
            num /= base;
        }
        buffer[len] = '\0';
        for (uint8_t i = 0; i < len / 2; i++)
        {
            char temp = buffer[i];
            buffer[i] = buffer[len - 1 - i];
            buffer[len - 1 - i] = temp;
        }
    }
    return buffer;
}

uint32_t convert_other_base_to_decimal(char *str, uint8_t base)
{
    uint32_t result = 0;
    uint8_t temp = 0;
    size_t len = strlen(str);
    for(uint8_t i = 0; i < len; i++)
    {
        temp = (uint8_t)(str[i] - '0');
        if(base == 16)
        {
            switch(str[i])
            {
                case 'a': case 'A':
                {
                    temp = 10;
                    break;
                }
                case 'b': case 'B':
                {
                    temp = 11;
                    break;
                }
                case 'c': case 'C':
                {
                    temp = 12;
                    break;
                }
                case 'd': case 'D':
                {
                    temp = 13;
                    break;
                }
                case 'e': case 'E':
                {
                    temp = 14;
                    break;

                }
                case 'f': case 'F':
                {
                    temp = 15;
                    break;
                }
            }
        }
        result += (uint32_t)(temp * pow(base,  (double)len - 1 - i));
    }
    return result;
}

char binary_to_octal_char(char* bin_3)
{
    uint8_t result = 0;
    size_t len = strlen(bin_3);
    uint8_t temp = 0;
    for(uint8_t i = 0; i < len; i++)
    {
        temp =(uint8_t) bin_3[i] - '0';
         result += (uint8_t)(temp * pow(2,  (double)len - 1 - i));
    }
    return (char)(result + '0');
}

void binary_to_octal(char *bin, char **octal)
{
    size_t len = strlen(bin);
    uint8_t padding = 0;
    if(len % 3)
    {
        padding =(uint8_t) (3 - (len % 3));
    }
    const uint8_t new_len = (uint8_t)len + padding;
    char new_bin[new_len + 1];
    for(uint8_t i = 0; i < padding; i++)
    {
        new_bin[i] = '0';
    }
    strcpy(new_bin + padding, bin);
    char octal_char = 0;
    char bin_3[4];
    uint8_t index = 0;
    *octal = (char*) malloc(((new_len / 3) + 1) * sizeof(char));
    for(uint8_t i = 0; i < new_len; i += 3)
    {
        strncpy(bin_3, new_bin + i, 3);
        
        
        octal_char = binary_to_octal_char(bin_3);
       
        (*octal)[index++] = octal_char;
       
    }
    (*octal)[index] = '\0';
    
}