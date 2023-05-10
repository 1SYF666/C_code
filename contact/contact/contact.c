#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//void InitContact(struct Contact* ps)
//{
//	//�������е����ݳ��Ի�Ϊ0���鿴CSDN�к���memsetʹ��
//	memset(ps->data, 0, sizeof(ps->data));
//	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
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
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
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
	//��ȡ�ļ�����ŵ�ͨѶ¼�� ,fread����ע�ⷵ��ֵ
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
//		printf("ͨѶ¼������,�޷�����\n");
//	}
//	else
//	{
//		printf("����������:>");
//		scanf("%s", ps->data[ps->size].name);
//		printf("����������:>");
//		scanf("%d", &ps->data[ps->size].age);//ע�⣬�������ȡ��ַ����Ϊage�����ͣ���ǰ�����鲻ͬ
//		printf("�������Ա�:>");
//		scanf("%s", ps->data[ps->size].sex);
//		printf("������绰:>");
//		scanf("%s", ps->data[ps->size].tele);
//		printf("�������ַ:>");
//		scanf("%s", ps->data[ps->size].addr);
//
//		(ps->size)++;
//		printf("���ӳɹ�\n");
//	}
//}
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;//һ�����������ṹ��ռ�
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.������ˣ�������ͨѶ¼�Ŀռ�
	//2.���������ɶ�¶�����
	CheckCapacity(ps);					//����費��Ҫ����

	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &ps->data[ps->size].age);//ע�⣬�������ȡ��ַ����Ϊage�����ͣ���ǰ�����鲻ͬ
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->size].addr);
	(ps->size)++;
	printf("���ӳɹ�\n");

}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
//static���ξֲ������Լ��ֲ�����

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
	return -1;//�Ҳ������
}

void DelContact(struct Contact* ps)
{
	int pos = 0;
	char name[NAME];
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//1.����Ҫɾ���˵�����λ��
	//�ҵ��˷�����������Ԫ�ص��±�
	//�Ҳ�������-1��
	pos=FindByname(ps, name);
	//int i = 0;
	//for (i = 0; i < ps->size ; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, name))
	//	{
	//		break;
	//	}
	//}
	//2.ɾ��
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


void SearchContact(struct Contact* ps)
{
	int pos = 0;
	//1.���������ڵ�λ��
	char name[NAME];
	printf("������Ҫ�����˵����֣�>");
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
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		//��ӡ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &ps->data[pos].age);//ע�⣬�������ȡ��ַ����Ϊage�����ͣ���ǰ�����鲻ͬ
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸ĳɹ�\n");

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
	//дͨѶ¼�е����ݵ��ļ���
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfwrite);
	}

	//�ر��ļ�
	fclose(pfwrite);
	pfwrite = NULL;
}