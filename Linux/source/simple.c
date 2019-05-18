#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
struct birthday
{
	int day;
	int month;
	int year;
	struct list_head list;
};
static LIST_HEAD(birthday_list);
/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
	//初始化
	for (int i = 0; i < 5; ++i)
	{
		struct birthday * person;
		person = kmalloc(sizeof(struct birthday), GFP_KERNEL);
		person->day = i * 2;
		person->month = i * 8;
		person->year = 1995 + i;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}	
	//遍历链表
	struct birthday * ptr;
	list_for_each_entry(ptr, &birthday_list, birthday.list);
	while (ptr)
	{	printk(KERN_INFO "day:%d month:%d year:%d", ptr->day, ptr->month, ptr->year);	
		list_for_each_entry(ptr, &birthday_list, birthday.list);
	}
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	struct birthday * ptr, * next;
	list_for_each_entry_safe(ptr, next, &birthday_list, birthday_list.list);
	while (ptr)
	{
		ptr = next;
		list_for_each_entry_safe(ptr, next, &birthday_list, birthday_list.list);
	}
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

