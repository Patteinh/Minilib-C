/*
** EPITECH PROJECT, 2023
** tests_strncmp.c
** File description:
** tests_strncmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef int (*my_strncmp)(const char *, const char *, size_t);
my_strncmp strncmp_asm;

Test(strncmp_test, NullStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strncmp_asm = (my_strncmp)dlsym(handle, "strncmp");
    size_t n = 10;
    cr_assert_eq(strncmp_asm("", "", n), strncmp("", "", n));
}

Test(strncmp_test, NullFirstString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strncmp_asm = (my_strncmp)dlsym(handle, "strncmp");
    char *s2 = "hello";
    size_t n = strlen(s2);
    cr_assert_eq(strncmp_asm("", s2, n), strncmp("", s2, n));
}

Test(strncmp_test, NullSecondString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strncmp_asm = (my_strncmp)dlsym(handle, "strncmp");
    char *s1 = "hello";
    size_t n = strlen(s1);
    cr_assert_eq(strncmp_asm(s1, "teststrcmp", n), strncmp(s1, "teststrcmp", n));
}

Test(strncmp_test, ZeroByteCount)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strncmp_asm = (my_strncmp)dlsym(handle, "strncmp");
    char *s1 = "hello";
    char *s2 = "hello";
    size_t n = 0;
    cr_assert_eq(strncmp_asm(s1, s2, n), strncmp(s1, s2, n));
}

Test(strncmp_test, DifferentStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strncmp_asm = (my_strncmp)dlsym(handle, "strncmp");
    char *s1 = "hello";
    char *s2 = "world";
    size_t n = strlen(s1);
    cr_assert_eq(strncmp_asm(s1, s2, n), strncmp(s1, s2, n));
}
