#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x852348eb, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x3d570de7, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xb6513cde, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x7e573775, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x381e5db1, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x60cc9040, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x661c41b8, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x6faceca5, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x113182f8, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x1d2c3ac0, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xdc80def5, __VMLINUX_SYMBOL_STR(kmap) },
	{ 0x70628f1e, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0xd54d8477, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "0407E85253CAB4A85776F0D");
