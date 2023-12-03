/*
** EPITECH PROJECT, 2023
** tests_memset.c
** File description:
** tests_memset
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>

typedef void *(*my_memset)(void *, int, size_t);
my_memset memset_asm;

Test(memset_test, Simple)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memset_asm = (my_memset)dlsym(handle, "memset");
    char dst[10];
    int c = 'z';
    size_t n = 0;
    cr_assert_eq(memset_asm(dst, c, n), memset(dst, c, n));
}

Test(memset_test, ZeroByteCount)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memset_asm = (my_memset)dlsym(handle, "memset");
    char dst[10];
    int c = 'a';
    size_t n = 0;
    cr_assert_eq(memset_asm(dst, c, n), memset(dst, c, n));
}

Test(memset_test, OverwritingExistingData)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memset_asm = (my_memset)dlsym(handle, "memset");
    char dst[10];
    int c = 'a';
    size_t n = 10;
    strcpy(dst, "hello");
    cr_assert_eq(memset_asm(dst, c, n), memset(dst, c, n));
    cr_assert_eq(dst[0], 'a', "Expected all elements to be overwritten.");
}

Test(memset_test, OneByte)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memset_asm = (my_memset)dlsym(handle, "memset");
    char dst[10];
    int c = 'a';
    size_t n = 1;
    cr_assert_eq(memset_asm(dst, c, n), memset(dst, c, n));
    cr_assert_eq(dst[0], 'a', "Expected first element to be set to the specified value.");
}

Test(memset_test, FullArray)
{
    void *handle = dlopen("../libasm.so", RTLD_LAZY);
    memset_asm = (my_memset)dlsym(handle, "memset");
    char dst[10];
    int c = 'a';
    size_t n = 10;
    cr_assert_eq(memset_asm(dst, c, n), memset(dst, c, n));
    cr_assert_eq(dst[0], 'a', "Expected all elements to be set to the specified value.");
}
