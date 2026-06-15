#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>	

MODULE_LICENSE("Moss' lincense");
MODULE_DESCRIPTION("Greatest Module Ever Created");
MODULE_VERSION("69");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello world\n");
	return 0;
}

static void __exit bye_exit(void)
{
	printk(KERN_INFO "Bye bye, love you\n");
}

module_init(hello_init);
module_exit(bye_exit);
