#include<linux/module.h>
#include<linux/kernel.h>

int init_module(void){
printk(KERN_INFO "Vijay Prasath Pattur Mohankumar: Loading Hello2 module - Hello World.\n");
return 0;
}

void cleanup_module(void){
printk(KERN_INFO "Vijay Prasath Pattur Mohankumar: Exiting Hello2 module - Goodbye World.\n");
}
