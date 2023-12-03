/*
** EPITECH PROJECT, 2023
** tests_strchr.c
** File description:
** tests_strchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef char *(*my_strchr)(const char *, int);
my_strchr strchr_asm;

Test(strchr_test, NullString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strchr_asm = (my_strchr)dlsym(handle, "strchr");
    const char *str = "ffffffiiiiiizzzzzz bbbbbbuuuuzzzz baaaaaaaz";
    char c = 'a';
    cr_assert(strchr_asm(str, c) == strchr(str, c));
}

Test(strchr_test, EmptyString)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strchr_asm = (my_strchr)dlsym(handle, "strchr");
    const char *str = "";
    char c = 'a';

    cr_assert(strchr_asm(str, c) == strchr(str, c));
}

Test(strchr_test, FoundInMiddle)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strchr_asm = (my_strchr)dlsym(handle, "strchr");
    const char *str = "abc";
    char c = 'b';

    cr_assert(strchr_asm(str, c) == strchr(str, c));
}

Test(strchr_asm, null_terminator)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strchr_asm = (my_strchr)dlsym(handle, "strchr");
    char string[] = "hello\0world";
    char search = '\0';

    char *result_libc = strchr(string, search);
    char *result_asm = strchr_asm(string, search);

    cr_assert_str_eq(result_libc, result_asm, "Expected equal result from both implementations.");
}

Test(strchr_asm, multiple_occurences)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strchr_asm = (my_strchr)dlsym(handle, "strchr");
    char string[] = "hello world";
    char search = 'l';
    char *result_libc = strchr(string, search);
    char *result_asm = strchr_asm(string, search);

    cr_assert_str_eq(result_libc, result_asm, "Expected equal result from both implementations.");
}
