#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);


__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,

	.exit = cleanup_module,

	.arch = MODULE_ARCH_INIT,
};
MODULE_INFO(retpoline, "Y");


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x2c635209, "module_layout" },
	{ 0xe8a33f46, "param_ops_ulong" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9e9fdd9d, "memunmap" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x4d924f20, "memremap" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A0438C0B4BE72A9D0CAD348");


