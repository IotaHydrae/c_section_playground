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

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr)[0])

#define __used  __attribute__((used))
#define __section(name)     __attribute__((section(name)))

/* These are for everybody (although not all archs will actually
   discard it in modules) */
#define __init		__section(".init.text") //__cold  __latent_entropy __noinitretpoline
#define __initdata	__section(".init.data")
#define __initconst	__section(".init.rodata")
#define __exitdata	__section(".exit.data")
#define __exit_call	__used __section(".exitcall.exit")


#define __stringify_1(x...) #x
#define __stringify(x...)   __stringify_1(x)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

// #define UNIQUE_NAME(__name) __PASTE(__UNIQUE_ID_, __name)

// #define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)
#define __UNIQUE_ID(prefix) __PASTE(prefix, __COUNTER__)

#define ___ADDRESSABLE(sym, __attrs) \
	static void * __used __attrs \
		__UNIQUE_ID(__PASTE(__addressable_,sym)) = (void *)&sym;
#define __ADDRESSABLE(sym) \
	___ADDRESSABLE(sym, __section(".discard.addressable"))

/*
 * Used for initialization calls..
 */
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);
typedef int initcall_entry_t;
typedef long addressable_entry_t;

#ifndef __KBUILD_MODNAME
    #define __KBUILD_MODNAME    kmod
#endif
/* Format: <modname>__<counter>_<line>_<fn> */
#define __initcall_id(fn)					\
	__PASTE(__KBUILD_MODNAME,				\
	__PASTE(__,						\
	__PASTE(__COUNTER__,					\
	__PASTE(_,						\
	__PASTE(__LINE__,					\
	__PASTE(_, fn))))))

/* Format: __<prefix>__<iid><id> */
#define __initcall_name(prefix, __iid, id)			\
	__PASTE(__,						\
	__PASTE(prefix,						\
	__PASTE(__,						\
	__PASTE(__iid, id))))


#define __initcall_section(__sec, __iid)			\
	#__sec ".init"

#define __initcall_stub(fn, __iid, id)	fn

#define __define_initcall_stub(__stub, fn)			\
	__ADDRESSABLE(fn)

#define ____define_initcall(fn, __stub, __name, __sec)		\
	__define_initcall_stub(__stub, fn)  \
	asm(".section	\"" __sec "\", \"a\"		\n"	\
	    __stringify(__name) ":			\n"	\
	    ".long	" __stringify(__stub) " - .	\n"	\
	    ".previous					\n");

#define __unique_initcall(fn, id, __sec, __iid)			\
	____define_initcall(fn,					\
		__initcall_stub(fn, __iid, id),			\
		__initcall_name(initcall, __iid, id),		\
		__initcall_section(__sec, __iid))

#define ___define_initcall(fn, id, __sec)			\
	__unique_initcall(fn, id, __sec, __initcall_id(fn))
 
#define __define_initcall(fn, id) ___define_initcall(fn, id, .initcall##id)

/*
 * Early initcalls run before initializing SMP.
 *
 * Only for built-in code, not modules.
 */
#define early_initcall(fn)		__define_initcall(fn, early)

/*
 * A "pure" initcall has no dependencies on anything else, and purely
 * initializes variables that couldn't be statically initialized.
 *
 * This only exists for built-in code, not for modules.
 * Keep main.c:initcall_level_names[] in sync.
 */
#define pure_initcall(fn)		__define_initcall(fn, 0)

#define core_initcall(fn)		__define_initcall(fn, 1)
#define core_initcall_sync(fn)		__define_initcall(fn, 1s)
#define postcore_initcall(fn)		__define_initcall(fn, 2)
#define postcore_initcall_sync(fn)	__define_initcall(fn, 2s)
#define arch_initcall(fn)		__define_initcall(fn, 3)
#define arch_initcall_sync(fn)		__define_initcall(fn, 3s)
#define subsys_initcall(fn)		__define_initcall(fn, 4)
#define subsys_initcall_sync(fn)	__define_initcall(fn, 4s)
#define fs_initcall(fn)			__define_initcall(fn, 5)
#define fs_initcall_sync(fn)		__define_initcall(fn, 5s)
#define rootfs_initcall(fn)		__define_initcall(fn, rootfs)
#define device_initcall(fn)		__define_initcall(fn, 6)
#define device_initcall_sync(fn)	__define_initcall(fn, 6s)
#define late_initcall(fn)		__define_initcall(fn, 7)
#define late_initcall_sync(fn)		__define_initcall(fn, 7s)

#define __initcall(fn) device_initcall(fn)

#define module_init(x)	__initcall(x);

extern addressable_entry_t __discard_addressable_start[];
extern addressable_entry_t __discard_addressable_end[];

extern initcall_entry_t __initcall_start[];
extern initcall_entry_t __initcall0_start[];
extern initcall_entry_t __initcall1_start[];
extern initcall_entry_t __initcall2_start[];
extern initcall_entry_t __initcall3_start[];
extern initcall_entry_t __initcall4_start[];
extern initcall_entry_t __initcall5_start[];
extern initcall_entry_t __initcall6_start[];
extern initcall_entry_t __initcall7_start[];
extern initcall_entry_t __initcall_end[];

static initcall_entry_t *initcall_levels[] __initdata = {
    __initcall0_start,
    __initcall1_start,
    __initcall2_start,
    __initcall3_start,
    __initcall4_start,
    __initcall5_start,
    __initcall6_start,
    __initcall7_start,
    __initcall_end,
};

static const char *initcall_level_names[] __initdata = {
    "pure",
    "core",
    "postcore",
    "arch",
    "subsys",
    "fs",
    "device",
    "late",
};

static int __init test_early_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_early_init, __func__);
    return 0;
}
early_initcall(test_early_init);

static int __init test_pure_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_pure_init, __func__);
    return 0;
}
pure_initcall(test_pure_init);

static int __init test_core_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_core_init, __func__);
    return 0;
}
core_initcall(test_core_init);

static int __init test_postcore_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_postcore_init, __func__);
    return 0;
}
postcore_initcall(test_postcore_init);

static int __init test_arch_init(void)
{
    printf("\t%p, %s,  i'm calling ...\n\n", test_arch_init, __func__);
    return 0;
}
arch_initcall(test_arch_init);

static int __init test_subsys_init(void)
{
    printf("\t%p, %s,  i'm calling ...\n\n", test_subsys_init, __func__);
    return 0;
}
subsys_initcall(test_subsys_init);

static int __init test_fs_init(void)
{
    printf("\t%p, %s,  i'm calling ...\n\n", test_fs_init, __func__);
    return 0;
}
fs_initcall(test_fs_init);

static int __init test_device_init(void)
{
    printf("\t%p, %s,  i'm calling ...\n\n", test_device_init, __func__);
    return 0;
}
device_initcall(test_device_init);

static int __init test_module_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_module_init, __func__);
    return 0;
}
module_init(test_module_init);

static int __init test_late_init(void)
{
    printf("\t%p, %s, i'm calling ...\n\n", test_late_init, __func__);
    return 0;
}
late_initcall(test_late_init);

static inline void *offset_to_ptr(const int *off)
{
    printf("\tfn addr : %p + (%d) = %p\n", (void *)((unsigned long)off),
                                    *off,
                                    (void *)((unsigned long)off + *off));

    return (void *)((unsigned long)off + *off);
}

static inline initcall_t initcall_from_entry(initcall_entry_t *entry)
{
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

static void do_initcall_level(int level)
{
    initcall_entry_t *fn;

	for (fn = initcall_levels[level]; fn < initcall_levels[level+1]; fn++)
		do_one_initcall(initcall_from_entry(fn));
}

// 99: 0000000000e01140     0 NOTYPE  GLOBAL DEFAULT   28 __initcall6_start
static void __init do_initcalls(void)
{
    int level;
    
    for (level = 0; level < ARRAY_SIZE(initcall_levels) - 1; level++) {
        printf("\n%d, %s, %p\n", level, initcall_level_names[level], initcall_levels[level]);
        do_initcall_level(level);
    }
}

static void __init do_pre_smp_initcalls(void)
{
    initcall_entry_t *fn;

    printf("early, %p\n", __initcall_start);

    for (fn = __initcall_start; fn < __initcall0_start; fn++)
        do_one_initcall(initcall_from_entry(fn));
}

static void __init do_list_addressable_things(void)
{
    addressable_entry_t *fn;

    printf(".discard.addressable start : %p\n", __discard_addressable_start);
    for (fn = __discard_addressable_start; fn < __discard_addressable_end; fn++) {
        printf("pointer addr : %p\n", fn);
        printf("\tfn addr : %p\n", (void *)*fn);
    }
    printf(".discard.addressable   end : %p\n", __discard_addressable_end);
}

int main(int argc, char **argv)
{
    do_list_addressable_things();

    do_pre_smp_initcalls();

    do_initcalls();

    return 0;
}

// static void *__attribute__((used)) __attribute__((section(".discard.addressable"))) test = (void *) &test_init;
// static void *__attribute__((used)) __attribute__((section(".discard.addressable"))) test1 = (void *) &test_init1;
// asm(".section \".initcall\", \"a\"      \n" \
//     "name_test_init :     \n" \
//     ".long  test_init - .\n"   \
//     ".previous      \n");

// asm(".section \".initcall\", \"a\"      \n" \
//     "name_test_init1 :     \n" \
//     ".long  test_init1 - .\n"   \
//     ".previous      \n");
