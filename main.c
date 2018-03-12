#include "list.h"

#include <stddef.h>
#include <stdio.h>

struct student{
	char *name;
	int age;
	struct list_head list;
};

LIST_HEAD(stu_list);
struct student stu1, stu2, stu3;

int main(void)
{
	struct list_head *pos;
	struct student *stu;

	stu1.name = "Rick";
	stu1.age = 12;
	list_add_tail(&stu1.list, &stu_list);

	stu2.name = "Lori";
	stu2.age = 14;
	list_add_tail(&stu2.list, &stu_list);

	stu3.name = "Karl";
	stu3.age = 2;
	list_add_tail(&stu3.list, &stu_list);

	list_for_each(pos, &stu_list){
		//stu = list_entry(pos, struct student, list);
		stu = list_entry(pos, struct student, list);
		printf("%s: %d\n", stu->name, stu->age);
	}

	list_del(&stu2.list);
	list_for_each(pos, &stu_list){
		//stu = list_entry(pos, struct student, list);
		stu = list_entry(pos, struct student, list);
		printf("%s: %d\n", stu->name, stu->age);
	}

	return 0;
}