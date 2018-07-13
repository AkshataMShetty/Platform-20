#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/sched.h>
#include<linux/cdev.h>
#include<asm/uaccess.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<asm/current.h>
#include<asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/export.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <asm/cpufeature.h>
#include<linux/mm.h>


MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 10
#define NR_DEVS 1 //no. of device numbers

int myopen(struct inode *inode, struct file *fileep);
int myrelease(struct inode *in, struct file *fp);
long my_ioctl(struct file *f,unsigned int addr,unsigned long add );

static int myinit(void);
static void myexit(void);

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = myopen,
	.release = myrelease,
	.unlocked_ioctl = my_ioctl
};

char *devname;

int majornum;

static dev_t mydev;
struct cdev *my_cdev;

module_param(devname, charp, 0000);

static struct class *mychar_class;
static struct device *mychar_device;

int myopen(struct inode *inode, struct file *fileep)
{
	printk(KERN_INFO"opened successfully");
	return 0;
}

int myrelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO"file released");
	return 0;
}

static int __init myinit(void)
{
	int ret = -ENODEV;
	int status;
	
	printk(KERN_INFO"Initializing character device");
	
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	
	if(status < 0) {
		printk(KERN_NOTICE"device numbers allocation failed %d", status);
		goto err;
	}

	printk(KERN_INFO "major number allocated = %d", MAJOR(mydev));

	my_cdev = cdev_alloc();  //allocate memory for cdev

	if(my_cdev == NULL) {
		printk(KERN_ERR"cdev_alloc failed");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);

	my_cdev->owner = THIS_MODULE;
	status = cdev_add(my_cdev, mydev, NR_DEVS);

	if(status) {
		printk(KERN_ERR"cdev_add failed");
		goto err_cdev_add;
	}

	mychar_class = class_create(THIS_MODULE, devname);
	
	if(IS_ERR(mychar_class)){
		printk(KERN_ERR"class_create failed");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);

	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR"device create failed");
		goto err_device_create;
	}

	return 0;
	
	err_device_create:
		class_destroy(mychar_class);
	err_class_create:
		cdev_del(my_cdev);
	err_cdev_add:
		kfree(my_cdev);
	err_cdev_alloc:
		unregister_chrdev_region(mydev, NR_DEVS);
	err:
		return ret;
}

static void myexit(void) {
	printk(KERN_INFO"Existing the character driver");
	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);
	return;
}
long my_ioctl(struct file *f,unsigned int addr,unsigned long add)
{
	//struct task_struct *task = current;
	struct vm_area_struct  *ptr;
	int *ptr1;
	#if 0
	printk("pcb (virtual) address is %p", task);
	ptr=task->mm->mmap;
	printk("vm_area struct starting address %p",ptr);
//	ptr->vm_start=0Xc300000;
//	ptr->vm_end=0xc4000000;	
#endif
	printk("the starting address of code %p\n", ptr->vm_start);
	printk("the ending address of code %p\n", ptr->vm_end);

	ptr=ptr->vm_next;
//	ptr->vm_start=0xc1000000;
//	ptr->vm_end=0xc2000000;
//	ptr1=0xc1000000;
//	printk("derefference %d",*(ptr1));
	printk("the starting address of data %p\n", ptr->vm_start);
	printk("the ending address of data %p\n", ptr->vm_end);
	return 0;
}
module_init(myinit);
module_exit(myexit);




	
		
	
