#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//void InitContact(struct Contact* ps)
//{
//	//将数组中的内容初试化为0，查看CSDN中函数memset使用
//	memset(ps->data, 0, sizeof(ps->data));
//	ps->size = 0;//设置通讯录最初只有0个元素
//}

void InitContact(struct Contact* ps)
{
	ps -> data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}

void CheckCapacity(struct Contact* ps);
void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("loadcontact::%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中 ,fread函数注意返回值
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead)) 
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;

}

//void AddContact(struct Contact* ps)
//{
//	if (ps->size == MAX)
//	{
//		printf("通讯录已满了,无法增加\n");
//	}
//	else
//	{
//		printf("请输入名字:>");
//		scanf("%s", ps->data[ps->size].name);
//		printf("请输入年龄:>");
//		scanf("%d", &ps->data[ps->size].age);//注意，这里必须取地址，因为age是整型，与前面数组不同
//		printf("请输入性别:>");
//		scanf("%s", ps->data[ps->size].sex);
//		printf("请输入电话:>");
//		scanf("%s", ps->data[ps->size].tele);
//		printf("请输入地址:>");
//		scanf("%s", ps->data[ps->size].addr);
//
//		(ps->size)++;
//		printf("添加成功\n");
//	}
//}
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//增容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;//一次增加两个结构体空间
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//检测当前通讯录的容量
	//1.如果满了，就增加通讯录的空间
	//2.如果不满，啥事都不干
	CheckCapacity(ps);					//检测需不需要扩容

	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &ps->data[ps->size].age);//注意，这里必须取地址，因为age是整型，与前面数组不同
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);
	(ps->size)++;
	printf("添加成功\n");

}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
//static修饰局部变量以及局部函数

static int FindByname(struct Contact* ps, char name[NAME])
{
	int i = 0;
    for (i = 0; i < ps->size ; i++)
    {
	    if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
    }
	return -1;//找不到情况
}

void DelContact(struct Contact* ps)
{
	int pos = 0;
	char name[NAME];
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	//1.查找要删除人的所在位置
	//找到了返回所在数组元素的下标
	//找不到返回-1；
	pos=FindByname(ps, name);
	//int i = 0;
	//for (i = 0; i < ps->size ; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, name))
	//	{
	//		break;
	//	}
	//}
	//2.删除
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


void SearchContact(struct Contact* ps)
{
	int pos = 0;
	//1.查找人所在的位置
	char name[NAME];
	printf("请输入要查找人的名字：>");
	scanf("%s", name);
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, name))
	//	{
	//		break;
	//	}
	//}
	pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		//打印数据
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	int pos = 0;
	char name[NAME];
	printf("请输入要修改人的名字：>");
	scanf("%s", name);
	pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &ps->data[pos].age);//注意，这里必须取地址，因为age是整型，与前面数组不同
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");

	}
}

void DestoryContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}


void SaveContact(Contact* ps)
{
	int i = 0;
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//写通讯录中的数据到文件中
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfwrite);
	}

	//关闭文件
	fclose(pfwrite);
	pfwrite = NULL;
}