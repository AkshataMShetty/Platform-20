/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/current.h>
#include <asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/export.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <asm/cpufeature.h>
#include <linux/mm.h>

MODULE_LICENSE("Dual BSD/GPL");

/** contents **/
#define FIRST_MINOR 0
#define NR_DEVS 1   //Number of device numbers

//Functions Declarations for syscall definition
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = myOpen,
	.unlocked_ioctl = myIoctl,
	.release = myRelease
};

/*Global variables */
char *devname; //contains device name
int majNo;
static dev_t mydev; //encodes major number and minor number
struct cdev *my_cdev; //holds character device driver descriptor

/* To accept input from the command line */
module_param(devname, charp, 0000);

//class and device structures
static struct class *mychar_class;
static struct device *mychar_device;

/*
*myOpen:open function of the pseudo driver
*
*/
int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "open successful\n");
	return 0;
}

/*
*myRelease : class function of the pseudo driver
*
*/
int myRelease(struct inode *in,struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

long myIoctl (struct file *fd, unsigned int var1, unsigned long var2)
{
	struct task_struct *task = current;
	printk("pid : %d\n",task -> pid);
	//struct mm_struct *mem = NULL;
	int i = 0;
	int count = 1;
	/*struct vm_area_struct *vm = NULL;

	mem = task -> mm;
	vm = mem -> mmap;
	
	while(vm != NULL) {
	printk("%p - %p\n",vm -> vm_start,vm -> vm_end);
	
	vm = vm -> vm_next;
	} */

	//mem = task -> mm;	
	pgd_t *base_pgd = task -> mm -> pgd;

	printk("Base address of pgd table : %p\n",base_pgd); //Base address of pgd 

	//Page dump on pgd table
	for (i = 0;i < 1024;i++) {
		printk("contents of pgd : %p\t count = %d\n", *(base_pgd + i),count);
		count++;
	}

	pte_t *base_pt;    //Base address of page table
	unsigned long addr;	
	unsigned long addr2;
	unsigned long addr1;
	unsigned long base_page;
	unsigned long *actual_addr;

	addr = (unsigned long)base_pgd[var2 >> 22].pgd;
	base_pt = (pte_t *)kmap(&mem_map[addr >> 12]);
	printk("Virtual address of page table : %p\n",base_pt);
	
	addr2 = (unsigned long)base_pt[(var2 << 10) >> 22].pte;
	base_page = (unsigned long)kmap(&mem_map[addr2 >> 12]);
	printk("Virtual address of page frame : %p\n",base_page);
	
	actual_addr = (base_page & 0xFFFFF000) + (var2 & 0X00000FFF);
	printk("Actual Address : %p\n",actual_addr);

	*actual_addr = 89;		
	printk("Actual value : %d\n",*actual_addr);
	/*base_page = (pte_t)
	printk("
	printk("Virtual address = %p\n", base_pt);
	//printk("Contents of var2 : %p\n",var2);
	//printk("Virtual address = %p\n",kmap(var2));
	
	printk("size : %d",sizeof(struct task_struct));
	*/
}
	 

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;
	printk(KERN_INFO "Initializing Character Device\n");

	//Allocating device number
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{
		printk(KERN_NOTICE "Device numbers allocation failed: %d\n",status);
		goto err;
	}
	printk(KERN_INFO "major number allocated :%d\n",MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cdev_alloc failed");
		goto err_cdev_alloc;
	}
	cdev_init(my_cdev, &fops);
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);
	if(status)
	{
		printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}

	//create class and entry in sysfs

	mychar_class = class_create( THIS_MODULE, devname);
	if(IS_ERR(mychar_class))
	{
		printk(KERN_ERR "class_crete failed");
		goto err_class_create;
	}

	//create mychar_device in sysfs and add entry in /dev

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device))
	{
		printk(KERN_ERR "device_create failed");
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

/*
*myExit :cleanup function to the kernel module
*
*/

static void myExit(void)
{
	printk(KERN_INFO "exiting the character driver");
	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);
	return ;
}

module_init (myInit);
module_exit(myExit);
