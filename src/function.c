#include "main.h"


void menu()
{
	
    printf("\n\t\t\tCONVERT BASE PROGRAM\n\n");
    printf("----------------------------------------------------------------\n\n");
    printf("1.Convert decimal to other base\n");
    printf("2.Convert other base to decimal\n");
    printf("3.Convert binary to octal\n");
    printf("4.Convert binary to hexa\n");
    printf("6.Add new students\n");
    

}

void get_input_base(uint8_t *base)
{
    int8_t check = 0;
    do
    {
        printf("\nEnter base wanted convert: ");
        check = (int8_t)scanf("%hhu", base);
        while(getchar() != '\n');
    }while(check == 0);
}
void get_input_num(int32_t *num)
{
    int8_t check = 0;
    do
    {
        printf("\nEnter number: ");
        check = (int8_t)scanf("%d", num);
        while(getchar() != '\n');
    }while(*num < 0 || check == 0);
}
char* convert_decimal_to_other(int32_t num, uint8_t base)
{
    static char buffer[33];
    if(num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }
    else
    {
        uint8_t len = 0, last = 0;
        char hex[] = "0123456789abcdef";
        while(num > 0)
        {
            last =(uint8_t) (num % base);
            buffer[len++] = hex[last];
            num /= base;
        }
        buffer[len] = '\0';
        for(uint8_t i = 0; i < len / 2; i++)
        {
            char temp = buffer[i];
            buffer[i] = buffer[len - 1 - i];
            buffer[len - 1 - i] = temp;
        }
    }
    return buffer;
}
