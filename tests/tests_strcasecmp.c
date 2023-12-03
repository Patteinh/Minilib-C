/*
** EPITECH PROJECT, 2023
** tests_strcasecmp.c
** File description:
** tests_strcasecmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

typedef int (*my_strcasecmp)(const char *, const char *);
my_strcasecmp strcasecmp_asm;

Test(strcasecmp, NullStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcasecmp_asm = (my_strcasecmp)dlsym(handle, "strcasecmp");
    cr_assert_eq(strcasecmp_asm("", ""), strcasecmp("", ""));
}

Test(strcasecmp, EqualStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcasecmp_asm = (my_strcasecmp)dlsym(handle, "strcasecmp");
    char *str1 = "Hello World";
    char *str2 = "Hello World";

    cr_assert_eq(strcasecmp_asm(str1, str2), strcasecmp(str1, str2));
}

Test(strcasecmp, DifferentStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcasecmp_asm = (my_strcasecmp)dlsym(handle, "strcasecmp");
    char *str1 = "Hello World from asm";
    char *str2 = "Hello World";
    cr_assert_eq(strcasecmp_asm(str1, str2), strcasecmp(str1, str2));
}

Test(strcasecmp, CaseInsensitive)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcasecmp_asm = (my_strcasecmp)dlsym(handle, "strcasecmp");
    char *str1 = "Hello World";
    char *str2 = "hello world";
    cr_assert_eq(strcasecmp_asm(str1, str2), strcasecmp(str1, str2));
}

Test(strcasecmp, DifferentLengths)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcasecmp_asm = (my_strcasecmp)dlsym(handle, "strcasecmp");
    char *str1 = "000";
    char *str2 = "0000";
    cr_assert_eq(strcasecmp_asm(str1, str2), strcasecmp(str1, str2));
}
