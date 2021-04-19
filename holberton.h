#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct vtype - Struct to map format specifier with function
 *
 * @sp: conversion specifier.
 * @fo: pointer to function corresponding the specifier.
 */
typedef struct vtype
{
	char sp;
	int (*fo)();
} vtype_t;

void _putchar(char *buffer, int *i);
void reset_putchar(char *buffer);
int _printf(const char *format, ...);
int func_sp(va_list arg, char *buffer, const char *format, int n, int *i);

int format_str(va_list arg, char *buffer, int *i);
int format_c(va_list arg, char *buffer, int *i);
int format_pers(__attribute__((unused))va_list arg, char *buffer, int *i);
int format_d(va_list arg, char *buffer, int *i);
int format_u(va_list arg, char *buffer, int *i);
int format_p(va_list arg, char *buffer, int *i);
int format_o(va_list arg, char *buffer, int *i);
int format_x(va_list arg, char *buffer, int *i);
int format_X(va_list arg, char *buffer, int *i);
int format_r(va_list arg, char *buffer, int *i);
int format_R(va_list arg, char *buffer, int *i);
int format_S(va_list arg, char *buffer, int *i);
int format_b(va_list arg, char *buffer, int *i);

int flag_plus(va_list arg, char *buffer, int *i);
int flag_spc(va_list arg, char *buffer, const char *format, int n, int *i);
int flag_hash(va_list arg, char *buffer, const char *format, int n, int *i);
int flag_0(va_list arg, char *buffer, const char *format, int n, int *i);
int flag_left(va_list arg, char *buffer, const char *format, int n, int *i);
int flag_right(va_list arg, char *buffer, const char *format, int n, int *i);

int precision(va_list arg, char *buffer, const char *format, int n, int *i);

char *itos(char str[], long int n);
char *utos(char str[], unsigned int num);
int num_len(unsigned int num);
int _strlen(char *s);

#endif
