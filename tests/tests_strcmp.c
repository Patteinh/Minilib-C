/*
** EPITECH PROJECT, 2023
** tests_strcmp.c
** File description:
** tests_strcmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef int (*my_strcmp)(const char *, const char *);
my_strcmp strcmp_asm;

Test(strcmp_test, NullInput)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcmp_asm = (my_strcmp)dlsym(handle, "strcmp");
    cr_assert_eq(strcmp_asm("", ""), strcmp("", ""));
}

Test(strcmp_test, EqualStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcmp_asm = (my_strcmp)dlsym(handle, "strcmp");
    char *a = "hello";
    char *b = "hello";
    cr_assert_eq(strcmp_asm(a, b), strcmp(a, b));
    cr_assert_eq(strcmp_asm(a, b), 0, "Expected equal result from both implementations.");
}

Test(strcmp_test, UnequalStrings)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcmp_asm = (my_strcmp)dlsym(handle, "strcmp");
    char *a = "hello";
    char *b = "hel";
    cr_assert_eq(strcmp_asm(a, b), strcmp(a, b));
}

Test(strcmp_test, FirstStringGreater)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcmp_asm = (my_strcmp)dlsym(handle, "strcmp");
    char *a = "hello";
    char *b = "hel";
    cr_assert_gt(strcmp_asm(a, b), 0, "Expected result from both implementations to be greater than 0.");
    cr_assert_eq(strcmp_asm(a, b), strcmp(a, b));
}

Test(strcmp_test, SecondStringGreater)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    strcmp_asm = (my_strcmp)dlsym(handle, "strcmp");
    char *a = "hel";
    char *b = "hello";
    cr_assert_lt(strcmp_asm(a, b), 0, "Expected result from both implementations to be less than 0.");
    cr_assert_eq(strcmp_asm(a, b), strcmp(a, b));
}
