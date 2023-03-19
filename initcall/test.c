/**
* @file test.c
* @author IotaHydrae (writeforever@foxmail.com)
* @brief
* @version 0.1
* @date 2023-03-19
*
* MIT License
*
* Copyright 2022 IotaHydrae(writeforever@foxmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*
*/

#include <stdio.h>
#include <stdbool.h>

/*
    #define pure_initcall(fn) __define_initcall(fn, 0)

    pure_initcall(test_init);

    __define_initcall(test_init, 0)

    ___define_initcall(test_init, 0, .initcall0)

    __unique_initcall(test_init, 0, .initcall0, __initcall_id(test_init))

    __unique_initcall(test_init, 0, .initcall0, kmod_main__0_157_test_init)

    ____define_initcall(test_init,
                __initcall_stub(test_init, kmod_main__0_157_test_init, 0)
                __initcall_name(initcall, kmod_main__0_157_test_init, 0)
                __initcall_section(.initcall0, kmod_main__0_157_test_init))

        {
            __initcall_stub(test_init, kmod_main__0_157_test_init, 0)
          =
            test_init

            __initcall_name(initcall, kmod_main__0_157_test_init, 0)
          =
            __initcall__kmod_main__0_157_test_init0

            __initcall_section(.initcall0, kmod_main__0_157_test_init)
          =
            .initcall0.init
        }

    ____define_initcall(test_init,
                        test_init,
                        __initcall__kmod_main__0_157_test_init0
                        .initcall0.init)

    __define_initcall_stub(test_init, test_init)
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")

    __ADDRESSABLE(test_init)
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")


    ___ADDRESSABLE(test_init, __section(".discard.addressable"))
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")

    static void * __used __section(".discard.addressable") \
            __UNIQUE_ID(__PASTE(__addressable_,test_init)) = (void *)&test_init;
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")

    static void * __used __section(".discard.addressable") \
            __UNIQUE_ID(__addressable_test_init) = (void *)&test_init;
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")

    static void * __used __section(".discard.addressable") \
            __UNIQUE_ID(__addressable_test_init) = (void *)&test_init;
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        __stringify(__initcall__kmod_main__0_157_test_init0) ":     \n" \
        ".long  " __stringify(test_init) " - . \n" \
        ".previous              \n")

    static void * __used __section(".discard.addressable") \
            unique_id__addressable_test_init_0 = (void *)&test_init;
    asm(". section  \"" .initcall0.init, \"a\"      \n" \
        "__initcall__kmod_main__0_157_test_init0" ":     \n" \
        ".long  " "test_init" " - . \n" \
        ".previous              \n")

*/

#define __stringify_1(x...) #x
#define __stringify(x...)   __stringify_1(x)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

// #define UNIQUE_NAME(__name) __PASTE(__UNIQUE_ID_, __name)
#define __UNIQUE_ID_ sdf_

#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)

/*
 * Used for initialization calls..
 */
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);
typedef int initcall_entry_t;

extern initcall_entry_t __initcall_start[];
extern initcall_entry_t __initcall0_start[];

extern initcall_entry_t __discard_addressable_start[];
extern initcall_entry_t __discard_addressable_end[];

static int test_init(void)
{
    printf("%s, i'm calling ...\n", __func__);
    return 0;
}

static int test_init1(void)
{
    printf("%s, i'm calling ...\n", __func__);
    return 0;
}

static inline void *offset_to_ptr(const int *off)
{
    // printf("%p\n", (void *)((unsigned long)off));
    // printf("%d\n", *off);
    // printf("%p\n", (void *)((unsigned long)off + *off));
    // printf("%s, %p\n", __func__, (void *)((unsigned long)off + *off));
    return (void *)((unsigned long)off + *off);
}

static inline initcall_t initcall_from_entry(initcall_entry_t *entry)
{
    // printf("%s, %p\n", __func__, entry);
    return offset_to_ptr(entry);
}

static inline bool initcall_blacklisted(initcall_t fn)
{
    return false;
}

static int do_one_initcall(initcall_t fn)
{
    int ret;
    
    /* blacklist */
    if (initcall_blacklisted(fn))
        return -1;
        
    ret = (*fn)();
    
    return ret;
}

static void do_initcalls(void)
{
    initcall_entry_t *fn;
    
    // trace_initcall_level("early");
    for (fn = __initcall_start; fn < __initcall0_start; fn++) {
        do_one_initcall(initcall_from_entry(fn));
    }
    
}

// static int __UNIQUE_ID(uni_name) = 1;

int main(int argc, char **argv)
{
    // printf("%d\n", __COUNTER__);
    
    // printf("%s\n", __stringify(FOO));
    
    printf("initcall start : %p\n", __initcall_start);
    printf("initcall0 start : %p\n", __initcall0_start);
    
    printf(".discard.addressable start : %p\n", __discard_addressable_start);
    printf(".discard.addressable   end : %p\n", __discard_addressable_end);
    
    printf("address of test_init : %p\n", test_init);
    printf("address of test_init1 : %p\n", test_init1);
    
    do_initcalls();
    
    return 0;
}

static void *__attribute__((used)) __attribute__((section(".discard.addressable"))) test = (void *) &test_init;
static void *__attribute__((used)) __attribute__((section(".discard.addressable"))) test1 = (void *) &test_init1;
asm(".section \".initcall\", \"a\"      \n" \
    "name_test_init :     \n" \
    ".long  test_init - .\n"   \
    ".previous      \n");

asm(".section \".initcall\", \"a\"      \n" \
    "name_test_init1 :     \n" \
    ".long  test_init1 - .\n"   \
    ".previous      \n");
