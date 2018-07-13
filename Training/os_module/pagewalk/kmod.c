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
#include <linux/export.h>
#include <linux/syscalls.h>
#include <asm/cpufeature.h>



#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/path.h>
MODULE_LICENSE("Dual BSD/GPL");

/** contents **/
#define FIRST_MINOR 0
#define NR_DEVS 1   //Number of device numbers

//Functions Declarations for syscall definition
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);

long myioctl (int , unsigned int, unsigned long);


//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myioctl
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

long myioctl(int fd, unsigned int va_a, unsigned long num2)
{
	struct task_struct *my_task_struct = NULL;
	struct vm_area_struct *my_vm_area = NULL;
	struct mm_struct *my_mm = NULL;	
	pgd_t *my_pgd; 	
	unsigned long i = 0;
	
	unsigned long addr;	
	unsigned long v_add1;
	unsigned long * v_add2;
	unsigned long * addr_2;
	unsigned long * addr_3;	
	unsigned long v_add3;
	
	dev_t my_rdev = 0 ;
	
	int r,w,x,s;
	char a_r[2]={'-','r'};
	char a_w[2]={'-','w'};
	char a_x[2]={'-','x'};
	char a_s[2]={'p','s'};
	//char a_m[2]={'-','m'};

	my_task_struct = current;
	my_mm = my_task_struct -> mm;
	my_pgd = my_mm -> pgd;	

	addr = my_pgd[ va_a >> 22].pgd;

	printk("pgd base address = %p\n",my_pgd);

	printk("Physical address of PGD entry = %p\n",(void *) addr);
	
	v_add1 = ( unsigned long ) kmap ( &(mem_map[addr >> 12]));
	
	printk( "PT Base addr = %p",(void *) v_add1);	

	v_add2 = ((va_a << 10) >> 22) + v_add1;
	addr_2 = (unsigned long ) kmap ( & ( mem_map[ *v_add2 >> 12]));
	
	printk(" offset in PT = %p ",( void *)v_add2);

	printk(" content (PA) in PT = %p ", ( void *) addr_2);
	
	addr_3 = addr_2 + (( va_a << 22) >> 22);

	printk(" particular index in page frame = %p ", (void *) addr_3);

	v_add3 = (unsigned long ) kmap ( & ( mem_map[ *addr_3 >> 12]));

	printk(" kmap of addr_3 = %d ",*addr_3);	

	printk(" PID = %d\n", my_task_struct->pid);
	
	my_vm_area = my_task_struct -> mm -> mmap;

//	printk(" %d, %d, %d, %d, %d", VM_READ, VM_WRITE, VM_EXEC, VM_SHARED, VM_MAYSHARE);
	printk("struct node \t start \t\t end \t\t size \t\t permissions\t\toffset");	
/*	while( my_vm_area)
	{
        if ((my_vm_area->vm_flags) & 1)
           r = 1;
        else
           r = 0;

        if ((my_vm_area->vm_flags) & 2)
           w = 1;
        else
           w = 0;

        if ((my_vm_area->vm_flags) & 4)
           x = 1;
        else
           x = 0;

        if ((my_vm_area->vm_flags) & 8)
           s = 1;
        else
           s = 0;
	
	
//	my_rdev = my_vm_area -> vm_file -> f_inode -> i_rdev;

		printk(" %p \t %p \t %p \t %d \t\t%c%c%c%c\t\t%08x\t %d", my_vm_area , my_vm_area -> vm_start, my_vm_area -> vm_end, (my_vm_area ->vm_end - my_vm_area -> vm_start) ,a_r[r],a_w[w],a_x[x],a_s[s], my_vm_area->vm_pgoff, my_rdev );
		my_vm_area = my_vm_area -> vm_next;
	} */
  

/*	for( i = 0; i <= 1024; i++)
	{
		printk("i = %u \t %p\n",i, *(my_pgd + i));
	}*/
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
