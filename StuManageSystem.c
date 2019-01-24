#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char name[10];
	int score;
	struct student *next;
};
typedef struct student Stu;

Stu *CreateList(int n);											//��������
void PrintList(Stu *h);											//�������
void InsertList(Stu *h, int i, char name[], int e, int n);		//����ڵ�
void DeleteList(Stu *h, int i, int n);							//ɾ���ڵ�
void save(Stu *h);

void save(Stu *h)
{
	FILE *fpWrite;
	fpWrite=fopen("data.txt", "w");
	Stu *p;
	p = h -> next;
	while(p){
		fprintf(fpWrite,"%s %d ", p -> name, p -> score);
		p = p -> next;
		printf("\n");
	}
	printf("����ɹ�\n");
	fclose(fpWrite);
}

int length(Stu *h)
{
	Stu *p = h; int n = -1;
	while(p != NULL){
		n++;
		p = p -> next;
	}
	return n;
}

Stu *ReadList()
{
	FILE *fpRead=fopen("data.txt","r");
	if(fpRead==NULL){
		fclose(fpRead);
		fpRead=fopen("data.txt","w");
		printf("��⵽��ǰ�ļ������������ļ�\n");
		printf("���Զ�����\n");
	}
	if(fgetc(fpRead) == EOF){
		printf("�����ļ�Ϊ���뽨��������\n");
		return 0;
	}
	Stu *head, *p, *pre;
	int i;
	head = (Stu *)malloc(sizeof(Stu));
	head -> next = NULL;
	pre = head;
	rewind(fpRead);			
	while (!feof(fpRead)){
		p = (Stu *)malloc(sizeof(Stu));
		fscanf(fpRead,"%s %d\n",p -> name, &p -> score);
		pre -> next = p;
		pre = p;
	}
	p -> next = NULL;
	fclose(fpRead);
	printf("����ɹ�\n");
	return head;
}

Stu *CreateList(int n)
{
	Stu *head, *p, *pre;
	int i;
	head = (Stu *)malloc(sizeof(Stu));
	head -> next = NULL;
	pre = head;
	for(i = 1; i <= n; i++){
		printf("������� %d λѧ��������:", i);
		p = (Stu *)malloc(sizeof(Stu));
		scanf("%s", p -> name);
		printf("������� %d λѧ���ĳɼ�:", i);
		scanf("%d", &p -> score);
		pre -> next = p;
		pre = p;
	}
	p -> next = NULL;
	return head;
}

void PrintList(Stu *h)
{
	printf("��ǰ�����е�����Ϊ��\n");
	Stu *p;
	p = h -> next;
	printf("����\t�ɼ�\n");
	while(p){
		printf("%s\t%d", p -> name, p -> score);
		p = p -> next;
		printf("\n");
	}
}

void InsertList(Stu *h, int i, char name[], int e, int n)
{
	Stu *q, *p;
	int j;
	if(i < 1 || i > n + 1)
		printf("��ѡ����ȷ�Ĳ���λ��\n");
	else{
		j = 0;
		p = h;
		while(j < i - 1){
			p = p -> next;
			j++;
		}
		q = (Stu *)malloc(sizeof(Stu));
		strcpy(q -> name, name);
		q -> score = e;
		q -> next = p -> next;
		p -> next = q;
	}
}

void DeleteList(Stu *h, int i, int n)
{
	Stu *p,*q;
	int j;
	char name[10];
	int score;
	if(i < 1 || i > n)
		printf("��ѡ����ȷ��ɾ��λ��\n");
	else{
		j = 0;
		p = h;
		while(j < i - 1){
			p = p -> next;
			j++;
		}
		q = p -> next;
		p -> next = q -> next;
		strcpy(name, q->name);
		score = q -> score;
		free(q);
		printf("name=%s,score=%d\n", name, score);
	}
}

int main()
{
	Stu *h = NULL;
	int i = 1, n = 0, score;
	char name [10];
	printf("---------------------------------\n");
	printf("1.���������ļ�\n");
	printf("2.�����µ�����\n");
	printf("3.���Ԫ��\n");
	printf("4.ɾ��Ԫ��\n");
	printf("5.�����ǰ���е�Ԫ��\n");
	printf("0.����\n");
	printf("-1.�˳�\n");
	printf("---------------------------------\n");
	while(1){
		printf("��ѡ��");
		scanf("%d", &i);
		switch(i){
			case 1:
				h = ReadList();
				if(h != 0)
					PrintList(h);
				break;
			case 2:
				printf("������Ϊ��");
				scanf("%d", &n);
				h = CreateList(n);
				PrintList(h);
				break;
			case 3:
				printf("���������λ��:");
				scanf("%d", &i);
				printf("����������:");
				scanf("%s", name);
				printf("������ɼ�:");
				scanf("%d", &score);
				n = length(h);
				InsertList(h, i, name, score, n);
				PrintList(h);
				break;
			case 4:
				printf("������ɾ��λ��:");
				scanf("%d", &score);
				n = length(h);
				DeleteList(h, score, n);
				PrintList(h);
				break;
			case 5:
				PrintList(h);
				break;
			case 0:
				save(h);
				break;
			case -1:
				return 0;
			default:
				printf("��������ȷѡ��\n");
		}
	}
}
