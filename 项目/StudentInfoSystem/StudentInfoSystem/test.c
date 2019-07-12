#include "..//DataSystem/OptCourse.h"
#include "../DataSystem/Student.h"
#include "..//DataSystem/Course.h"
#include "..//UI/SortAssistance.h"
#include "..//DataSystem/DataSystem.h"
#include "..//UI/SortAssistance.h"
#include "..//UI/SearchAssistance.h"
#include "..//UI/StudentAssistance.h"
#include "..//UI/CourseAssistance.h"
#include "..//Lib/String/__string.h"
extern DataSystem dataSystem;
extern DataSystem searchResult;
static void show(DataSystem* data)
{
	Student_list_iterator sit = data->m_studentTable.begin(&data->m_studentTable);
	Course_list_iterator cit = data->m_courseTable.begin(&data->m_courseTable);
	OptCourse_list_iterator oit = data->m_optCourseTable.begin(&data->m_optCourseTable);
	while (sit != data->m_studentTable.end(&data->m_studentTable))
	{
		printf("%u %u %s %s %c\n", sit->m_class, sit->m_id, sit->m_major, sit->m_name, sit->m_sex);
		sit = data->m_studentTable.next(&data->m_studentTable, sit);
	}
	while (cit != data->m_courseTable.end(&data->m_courseTable))
	{
		printf("%s %s %s\n", cit->m_cId, cit->m_cName, cit->m_teacher);
		cit = data->m_courseTable.next(&data->m_courseTable, cit);
	}
	while (oit != data->m_optCourseTable.end(&data->m_optCourseTable))
	{
		printf("%s %lf %u\n", oit->m_cId, oit->m_score, oit->m_sId);
		oit = data->m_optCourseTable.next(&data->m_optCourseTable, oit);
	}
}
void test()
{
/*
	Student_list list1;
	Student temp;
	Course_list list2;
	Course temp1;
	OptCourse_list list3;
	OptCourse temp3;
	unsigned tempf = 4;
	Student fff = {305181, "小", 5748963, "软件", 'M' };
	initDataSystem(&dataSystem);
//	Student_list_init(&list1);
//	list1.set_copyer(copyStu);
	temp.m_name = malloc(1024);
	temp.m_major = malloc(1024);
	temp.m_class = 172230016;
	temp.m_id = 344114943;
	strcpy(temp.m_major,"软件工程");
	strcpy(temp.m_name,"小王");
	temp.m_sex = 'M';
	dataSystem.studentTable.push_back(&dataSystem.studentTable, &temp);
	dataSystem.studentTable.push_back(&dataSystem.studentTable, &temp);
	writeFileFromStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.studentTable, "at");
	readFileToStuList("../DataSystem/Data/StudentTable.txt", &dataSystem.studentTable);
	

	//Course_list_init(&list2);
	//list2.set_copyer(copyCourse);
	temp1.m_cId = malloc(1024);
	temp1.m_cName = malloc(1024);
	temp1.m_teacher = malloc(1024);
	strcpy(temp1.m_cId, "GaiLv");
	strcpy(temp1.m_cName, "概率论");
	strcpy(temp1.m_teacher, "刘分");
	dataSystem.courseTable.push_back(&dataSystem.courseTable, &temp1);
	dataSystem.courseTable.push_back(&dataSystem.courseTable, &temp1);
	writeFileFromCouList("../DataSystem/Data/CourseTable.txt", &dataSystem.courseTable, "w");
	readFileToCouList("../DataSystem/Data/CourseTable.txt", &dataSystem.courseTable);
	
//	OptCourse_list_init(&list3);
//	list3.set_copyer(copyOpt);
	//list3.set_destructor(destructOpt);
	temp3.m_cId = malloc(1024);
	temp3.m_score = 377;
	temp3.m_sId = 201008;
	strcpy(temp3.m_cId, "GaiLv");
	dataSystem.optCourseTable.push_back(&dataSystem.optCourseTable, &temp3);
	dataSystem.optCourseTable.push_back(&dataSystem.optCourseTable, &temp3);
	writeFileFromOptCourseList("../DataSystem/Data/OptCourseTable.txt", &dataSystem.optCourseTable, "at");
	readFileToOptCourseList("../DataSystem/Data/OptCourseTable.txt", &dataSystem.optCourseTable);
	collectData();
	show(&dataSystem);
	printf("开始排序\n");
	sort(compareBySId, student);
	show(&dataSystem);

	findAndSave(searchConditionStuByClass, student, &fff.m_class);
	printf("查询结果\n");
	show(&searchResult);

	findAndSave(searchConditionStuById, student, &fff.m_id);
	printf("查询结果\n");
	show(&searchResult);

	findAndSave(searchConditionStuByMaj, student, fff.m_major);
	printf("查询结果\n");
	show(&searchResult);

	findAndSave(searchConditionStuByName, student, fff.m_name);
	printf("查询结果\n");
	show(&searchResult);
	/*
	const char* path = "../DataSystem/Data/StudentTable.txt";
	mystring temp;
	mystring temp2;
	mystring_init(&temp);
	mystring_init(&temp2);
	readToTemp(&temp, path);
	printf("%s", temp.c_str(&temp));
	saveFromTemp(&temp, "C:\\Users\\12409\\Desktop\\linklist\\test.txt");
	*/

	//Student temp = { 234534, "宋", 345, "软件工程", 'f'};
	//Student data = { 1, "f", 35, "ggew", 'q' };
	//char* num = "宋";
	//unsigned id = 234534;
	//initDataSystem(&dataSystem);
	//addStuRec(&temp);
	//addStuRec(&temp);
	//show(&dataSystem);
	//printf("删除后\n");
	//show(&dataSystem);
	//printf("修改后\n");
	//changeStuRec(mvConditionStuById, &id, &data);
	//show(&dataSystem);
	//addOptCourseRec(234534,"ge", 55.8);
	//show(&dataSystem);

	//
	//Course temp = { "ke", "ming", "laosho" };
	//OptCourse opt = { 4453, "feewgwegwg", 30 };
	//OptCourse temp1 = { 53, "fewg", 34 };
	//char* cid = "ke";
	//char* t = "laosho";
	//initDataSystem(&dataSystem);
	//addOptCourseRec(53, "fewg", 34);
	//addCouRec(&temp);
	//show(&dataSystem);

	//setScore(mvConditionOpt, &temp1, &opt);
	//show(&dataSystem);

	//printf("删除\n");
	//rmCouRec(rmConditionCouByTea, t);
	//show(&dataSystem);

	
//	void changeCouRec(ConditionCou condition, void* con, Course * data);
/*
	bool rmConditionCouByCId(void* data1, void* data2);
	bool rmConditionCouByTea(void* data1, void* data2);
	bool rmConditionCouByName(void* data1, void* data2);
	bool mvConditionCouById(void* data1, void* data2);
	bool mvConditionOpt(void* data1, void* data2);
	/*
	bool searchConditionStuByName(void* data, void* con);
	bool searchConditionStuById(void* data, void* con);
	bool searchConditionStuByClass(void* data, void* con);
	bool searchConditionStuByMaj(void* data, void* con);

	bool searchConditionCouById(void* data, void* con);
	bool searchConditionCouByName(void* data, void* con);
	bool searchConditionCouByTea(void* data, void* con);

	bool searchConditionOptBySId(void* data, void* con);
	bool searchConditionOptByCId(void* data, void* con);
	bool searchConditionOptBySco(void* data, void* con);
	//判断函数 数据类型 判断函数中的判断值
	void findAndSave(ConditionSearch condition, DataType dataType, void* con);
	void collectData();
	bool fuzzySearch(const char* des, const char* src);


	void sort(Compare compare, DataType dataTpe);
	void saveResult(DataType dataTpe);
	void outputResult(const char* filePath, DataType dataTpe);
	bool compareBySId(void* data1, void* data2);
	bool compareBySName(void* data1, void* data2);
	bool compareBYScore(void* data1, void* data2);
	*/
}