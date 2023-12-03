/*
** EPITECH PROJECT, 2023
** tests_strrchr.c
** File description:
** tests_strrchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef char *(*my_strrchr)(const char *, int);
my_strrchr strrchr_asm;

Test(strrchr_test, NullString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strrchr_asm = (my_strrchr)dlsym(handle, "strrchr");
    const char *str = "ffffffiiiiiizzzzzz bbbbbbuuuuzzzz baaaaaaaz";
    char c = 'a';
    cr_assert(strrchr_asm(str, c) == strrchr(str, c));
}

Test(strrchr_test, EmptyString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strrchr_asm = (my_strrchr)dlsym(handle, "strrchr");
    const char *str = "";
    char c = 'a';
    cr_assert(strrchr_asm(str, c) == strrchr(str, c));
}

Test(strrchr_test, FoundAtEnd)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strrchr_asm = (my_strrchr)dlsym(handle, "strrchr");
    const char *str = "abc";
    char c = 'c';
    cr_assert(strrchr_asm(str, c) == strrchr(str, c));
}

Test(strrchr_test, not_found)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strrchr_asm = (my_strrchr)dlsym(handle, "strrchr");
    char string[] = "hello world";
    int search = 'd';
    char *result_libc = strrchr(string, search);
    char *result_asm = strrchr_asm(string, search);
    cr_assert_str_eq(result_libc, result_asm, "Expected equal result from both implementations.");
}

Test(strrchr_test, multiple_occurences)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strrchr_asm = (my_strrchr)dlsym(handle, "strrchr");
    char string[] = "hello world";
    char search = 'l';
    char *result_libc = strrchr(string, search);
    char *result_asm = strrchr_asm(string, search);
    cr_assert_str_eq(result_libc, result_asm, "Expected equal result from both implementations.");
}
