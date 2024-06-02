#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

void menu();
void get_input_num(int32_t *num);
char* convert_decimal_to_other(int32_t num, uint8_t base);
void get_input_base(uint8_t *base);

#endif