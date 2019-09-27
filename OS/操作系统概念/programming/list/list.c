#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>

typedef struct birthday
{
	int day;
	int month;
	int year;
	struct list_head list;
}birthday;

static LIST_HEAD(birthday_list); //struct list_head birthday_list = { &birthday_list, &birthday_list };

int list_init(void)
{
	int i = 0;
	birthday * person;
	birthday * each;
	for (; i < 5; ++i)
	{
		person = vmalloc(sizeof(*person));
		person->day = 2;
		person->month = 8;
		person->year = 1995;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}
	list_for_each_entry(each, &birthday_list, list)
	{
		printk(KERN_INFO "day = %d, month=%d, year=%d\n", each->day, each->month, each->year);
	}
	return 0;
}

void list_exit(void)
{
	birthday * ptr, *next;
	list_for_each_entry_safe(ptr, next, &birthday_list, list)
	{
		printk(KERN_INFO "death\n");
		list_del(&ptr->list);
		vfree(ptr);
	}
}
module_init(list_init);
module_exit(list_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MyList Module");
MODULE_AUTHOR("ABC");


