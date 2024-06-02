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
    printf("6.Convert hexa to binary\n");
    printf("7.Exit program\n");
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
bool check_octal(char *str)
{
    for (int8_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' ||  str[i] > '7')
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
        case 8:
        {
            check_string_input(str, check_octal);
            break;
        }
    }
}

void get_input_base(uint8_t *base)
{
    int8_t check = 0;
    do
    {
        printf("\nEnter base wanted convert (base = 2 or 8 or 10 or 16): ");
        check = (int8_t)scanf("%hhu", base);
        while (getchar() != '\n')
            ;
    } while (check == 0 || (*base != 2 && *base !=  8 && *base != 10 && *base != 16));
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

char binary_to_hex_char(char* bin_4)
{
    uint8_t result = 0;
    size_t len = strlen(bin_4);
    char hex[] = "0123456789abcdef";
    for(uint8_t i = 0; i < len; i++)
    {
        if(bin_4[i] == '1')
        {
            result += (uint8_t)(1 << (len - i - 1));
        }
       
    }

    return hex[result];
}

void binary_to_hex(char *bin, char **hex)
{
    size_t len = strlen(bin);
    uint8_t padding = 0;
    if(len % 4)
    {
        padding = (uint8_t)(4 - len % 4);
    }
    const size_t new_len = len + padding;
    char new_bin[new_len];
    for(uint8_t i = 0; i < padding; i++)
    {
        new_bin[i] = '0';
    }
    strcpy(new_bin + padding, bin);
    char hex_char = 0;
    char bin_4[5];
    uint8_t index = 0;
    *hex = (char*) malloc(((new_len / 4) + 1) * sizeof(char));
    for(uint8_t i = 0; i < new_len; i += 4)
    {
        strncpy(bin_4, new_bin + i, 4);
        hex_char = binary_to_hex_char(bin_4);
        (*hex)[index++] = hex_char;
    }
    (*hex)[index] = '\0';

}

char* octal_char_to_bin(char octal_char)
{
    char *result = NULL;
    switch(octal_char)
    {
        case '0':
        {
            result = "000";
            break;
        }
        case '1':
        {
            result = "001";
            break;
        }
        case '2':
        {
            result = "010";
            break;
        }
        case '3':
        {
            result = "011";
            break;
        }
        case '4':
        {
            result = "100";
            break;
        }
        case '5':
        {
            result = "101";
            break;
        }
        case '6':
        {
            result = "110";
            break;
        }
        case '7':
        {
            result = "111";
            break;
        }
        
    }
    return result;
}

char* octal_to_binary(char *octal)
{
    size_t len = strlen(octal);
    char *result = NULL;
    result = (char*)malloc((len * 3 + 1 ) * sizeof(char));
    for(uint8_t i = 0; i < len; i++)
    {
        char *temp = octal_char_to_bin(octal[i]);
        strcpy(result + 3 * i, temp);
        puts(result);
    }
    return result;
}

char* hex_char_to_bin(char hex_char)
{
    char *result = NULL;
    switch(hex_char)
    {
        case '0':
        {
            result = "0000";
            break;
        }
        case '1':
        {
            result = "0001";
            break;
        }
        case '2':
        {
            result = "0010";
            break;
        }
        case '3':
        {
            result = "0011";
            break;
        }
        case '4':
        {
            result = "0100";
            break;
        }
        case '5':
        {
            result = "0101";
            break;
        }
        case '6':
        {
            result = "0110";
            break;
        }
        case '7':
        {
            result = "0111";
            break;
        }
        
        case '8':
        {
            result = "1000";
            break;
        }
        case '9':
        {
            result = "1001";
            break;
        }
        case 'a': case 'A':
        {
            result = "1010";
            break;
        }
        case 'b' : case 'B':
        {
            result = "1011";
            break;
        }
        case 'c': case 'C':
        {
            result = "1100";
            break;
        }
        case 'd': case 'D':
        {
            result = "1101";
            break;
        }
        case 'e': case 'E':
        {
            result = "1110";
            break;
        }
        case 'f': case 'F':
        {
            result = "1111";
            break;
        }
        
    }
    return result;
}

char* hex_to_binary(char *hex)
{
    size_t len = strlen(hex);
    char *result = NULL;
    result = (char*)malloc((len * 4 + 1 ) * sizeof(char));
    for(uint8_t i = 0; i < len; i++)
    {
        char *temp = hex_char_to_bin(hex[i]);
        strcpy(result + 4 * i, temp);
        puts(result);
    }
    return result;
}