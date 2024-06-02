#include "main.h"

void get_input_num(int32_t *num)
{
    int8_t check = 0;
    do
    {
        printf("\nNhap 1 so khong am: ");
        check = ("%d", num);
        while(getchar() != '\n');
    }while(num < 0 || check == 0);
}
