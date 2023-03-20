<h1 align="center">
    <span>C section playground<span>
</h1>

<h3 align="center">
A playground using to have fun with c section<br>
YEEEEEEEEE!
</h3>

Directories
-------------------
```shell
initcall/ -> initcalls using section

kernel_initcall/ -> the kernel initcall system

tests/    -> store temporary testing files

```

Build
-------------------
```shell
cd kernel_initcall
make
# or
make dump

./test.out

early, 0xe01420
        fn addr : 0xe01420 + (-920) = 0xe01088
        0xe01088, test_early_init, i'm calling ...


0, pure, 0xe01424
        fn addr : 0xe01424 + (-882) = 0xe010b2
        0xe010b2, test_pure_init, i'm calling ...


1, core, 0xe01428
        fn addr : 0xe01428 + (-844) = 0xe010dc
        0xe010dc, test_core_init, i'm calling ...


2, postcore, 0xe0142c
        fn addr : 0xe0142c + (-806) = 0xe01106
        0xe01106, test_postcore_init, i'm calling ...


3, arch, 0xe01430
        fn addr : 0xe01430 + (-768) = 0xe01130
        0xe01130, test_arch_init,  i'm calling ...


4, subsys, 0xe01434
        fn addr : 0xe01434 + (-730) = 0xe0115a
        0xe0115a, test_subsys_init,  i'm calling ...


5, fs, 0xe01438
        fn addr : 0xe01438 + (-692) = 0xe01184
        0xe01184, test_fs_init,  i'm calling ...


6, device, 0xe0143c
        fn addr : 0xe0143c + (-654) = 0xe011ae
        0xe011ae, test_device_init,  i'm calling ...

        fn addr : 0xe01440 + (-616) = 0xe011d8
        0xe011d8, test_module_init, i'm calling ...


7, late, 0xe01444
        fn addr : 0xe01444 + (-578) = 0xe01202
        0xe01202, test_late_init, i'm calling ...

```