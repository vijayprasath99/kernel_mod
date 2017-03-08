#include<linux/kernel.h>
#include <linux/module.h>
#include<linux/init.h>
#include<linux/stat.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GLP");
MODULE_AUTHOR("Vijay");

static char *name = "VijayPM";
static char *addr = "123";
static char *city = "Newark1";
static int zipcode = 000;

module_param(name, charp, 0000);
MODULE_PARM_DESC(name, "You name");
module_param(addr, charp, 0000);
MODULE_PARM_DESC(addr, "Your Address");
module_param(city, charp, 0000);
MODULE_PARM_DESC(city, "Your City");
module_param(zipcode, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(zipcode, "Your Zipcode");

static int __init hello3_init(void){
printk(KERN_INFO "Loading Hello 3: Hello World 3\n");
printk(KERN_INFO "==============================\n");
printk(KERN_INFO "Name : %s\n", name);
printk(KERN_INFO "Street : %s\n", addr);
printk(KERN_INFO "City : %s\n", city);
printk(KERN_INFO "ZIP code : %d\n", zipcode);

return 0;
}
static void __exit hello3_exit(void)
{
	printk(KERN_INFO "Exiting Module 3..\n");
}

module_init(hello3_init);
module_exit(hello3_exit);
