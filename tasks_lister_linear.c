#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

static int tasks_lister_linear_init(void)
{
    struct task_struct *task;
    printk(KERN_INFO "Loading module\n");
    for_each_process(task) {
        printk(KERN_INFO "\nPARENT PID: %d PROCESS: %s STATE: %d",task->pid, task->comm, task->__state);
    }
    return 0;
}
static void __exit tasks_lister_linear_exit(void)
{
    printk(KERN_INFO "Goodbye\n");
}
module_init(tasks_lister_linear_init);
module_exit(tasks_lister_linear_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("List tasks linearly");
MODULE_AUTHOR("Prajna R"); 
____________________________________________________________________

//Makefile

obj-m += tasks_lister_linear.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
