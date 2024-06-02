#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef bool (*check_string)(char *);

void menu();
bool check_hexa(char* str);
bool check_binary(char* str);
bool check_other_base(char *str);

void get_input_num(int32_t *num);
void get_input_base(uint8_t *base);
void get_input_string(char *str, uint8_t base);
void check_string_input(char *str, check_string func);

char* convert_decimal_to_other(int32_t num, uint8_t base);
uint32_t convert_other_base_to_decimal(char *str, uint8_t base);
char binary_to_octal_char(char* bin_3);
void binary_to_octal(char *bin, char **octal);
char binary_to_hex_char(char* bin_4);
void binary_to_hex(char *bin, char **hex);
#endif