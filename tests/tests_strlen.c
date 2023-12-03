/*
** EPITECH PROJECT, 2023
** tests_strlen.c
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef size_t (*my_strlen)(const char *);
my_strlen strlen_asm;

Test(strlen_test, EmptyString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strlen_asm = (my_strlen)dlsym(handle, "strlen");
    char str[] = "";
    cr_assert_eq(strlen_asm(str), strlen(str), "Expected the same length for both implementations.");
}

Test(strlen_test, NullTerminatedString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strlen_asm = (my_strlen)dlsym(handle, "strlen");
    char str[] = "hello";
    size_t len = strlen(str);
    cr_assert_eq(strlen_asm(str), len, "Expected the same length for both implementations.");
}

Test(strlen_test, NotNullTerminatedString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strlen_asm = (my_strlen)dlsym(handle, "strlen");
    char str[] = {'h', 'e', 'l', 'l', 'o', 0};
    size_t len = strlen(str);
    cr_assert_eq(strlen_asm(str), len, "Expected the same length for both implementations.");
}

Test(strlen_test, LongString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strlen_asm = (my_strlen)dlsym(handle, "strlen");
    char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    size_t len = strlen(str);
    cr_assert_eq(strlen_asm(str), len, "Expected the same length for both implementations.");
}

Test(strlen_test, StringWithNewline)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strlen_asm = (my_strlen)dlsym(handle, "strlen");
    char str[] = "hello\n";
    size_t len = strlen(str);
    cr_assert_eq(strlen_asm(str), len, "Expected the same length for both implementations.");
}
