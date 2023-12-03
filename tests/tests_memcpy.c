/*
** EPITECH PROJECT, 2023
** tests_memcpy.c
** File description:
** tests_memcpy
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef void *(*my_memcpy)(void *, const void *, size_t);
my_memcpy memcpy_asm;

Test(memcpy_test, Simple)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memcpy_asm = (my_memcpy)dlsym(handle, "memcpy");
    char dst[10];
    char *c = "111";
    size_t n = 0;
    cr_assert_eq(memcpy_asm(dst, c, n), memcpy(dst, c, n));
}

Test(memcpy_test, NullSource)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memcpy_asm = (my_memcpy)dlsym(handle, "memcpy");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memcpy_asm(dst, "testmemcpy", n), memcpy(dst, "testmemcpy", n));
}

Test(memcpy_test, ZeroByteCount)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memcpy_asm = (my_memcpy)dlsym(handle, "memcpy");
    char dst[10];
    char src[] = "hello";
    size_t n = 0;
    cr_assert_eq(memcpy_asm(dst, src, n), memcpy(dst, src, n));
}

Test(memcpy_test, OverlappingRegions)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memcpy_asm = (my_memcpy)dlsym(handle, "memcpy");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memcpy_asm(dst + 2, dst, n), memcpy(dst + 2, dst, n));
}

Test(memcpy_test, NonOverlappingRegions)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memcpy_asm = (my_memcpy)dlsym(handle, "memcpy");
    char dst[10];
    char src[] = "hello";
    size_t n = strlen(src) + 1;
    cr_assert_eq(memcpy_asm(dst, src, n), memcpy(dst, src, n));
    cr_assert_str_eq(dst, src, "Expected equal result from both implementations.");
}
