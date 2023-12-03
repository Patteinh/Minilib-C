/*
** EPITECH PROJECT, 2023
** tests_memmove.c
** File description:
** tests_memmove
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef void *(*my_memmove)(void *, const void *, size_t);
my_memmove memmove_asm;

Test(memmove_test, Simple)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memmove_asm = (my_memmove)dlsym(handle, "memmove");
    char dst[10];
    char *c = "111";
    size_t n = 0;
    cr_assert_eq(memmove_asm(dst, c, n), memmove(dst, c, n));
}

Test(memmove_test, NullSource)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memmove_asm = (my_memmove)dlsym(handle, "memmove");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memmove_asm(dst, "testmemmove", n), memmove(dst, "testmemmove", n));
}

Test(memmove_test, ZeroByteCount)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memmove_asm = (my_memmove)dlsym(handle, "memmove");
    char dst[10];
    char src[] = "hello";
    size_t n = 0;
    cr_assert_eq(memmove_asm(dst, src, n), memmove(dst, src, n));
}

Test(memove_test, OverlappingRegions)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memmove_asm = (my_memmove)dlsym(handle, "memmove");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memmove_asm(dst + 2, dst, n), memmove(dst + 2, dst, n));
}

Test(memmove_test, NonOverlappingRegions)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memmove_asm = (my_memmove)dlsym(handle, "memmove");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memmove_asm(dst, src, n), memmove(dst, src, n));
    cr_assert_str_eq(dst, src, "Expected equal result from both implementations.");
}
