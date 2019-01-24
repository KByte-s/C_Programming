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

Stu *CreateList(int n);											//创建链表
void PrintList(Stu *h);											//输出链表
void InsertList(Stu *h, int i, char name[], int e, int n);		//插入节点
void DeleteList(Stu *h, int i, int n);							//删除节点
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
	printf("保存成功\n");
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
		printf("检测到当前文件夹中无数据文件\n");
		printf("已自动创建\n");
	}
	if(fgetc(fpRead) == EOF){
		printf("数据文件为空请建立新链表\n");
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
	printf("导入成功\n");
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
		printf("请输入第 %d 位学生的名字:", i);
		p = (Stu *)malloc(sizeof(Stu));
		scanf("%s", p -> name);
		printf("请输入第 %d 位学生的成绩:", i);
		scanf("%d", &p -> score);
		pre -> next = p;
		pre = p;
	}
	p -> next = NULL;
	return head;
}

void PrintList(Stu *h)
{
	printf("当前链表中的数据为：\n");
	Stu *p;
	p = h -> next;
	printf("姓名\t成绩\n");
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
		printf("请选择正确的插入位置\n");
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
		printf("请选择正确的删除位置\n");
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
	printf("1.导入数据文件\n");
	printf("2.建立新的链表\n");
	printf("3.添加元素\n");
	printf("4.删除元素\n");
	printf("5.输出当前表中的元素\n");
	printf("0.保存\n");
	printf("-1.退出\n");
	printf("---------------------------------\n");
	while(1){
		printf("请选择：");
		scanf("%d", &i);
		switch(i){
			case 1:
				h = ReadList();
				if(h != 0)
					PrintList(h);
				break;
			case 2:
				printf("总人数为：");
				scanf("%d", &n);
				h = CreateList(n);
				PrintList(h);
				break;
			case 3:
				printf("请输入插入位置:");
				scanf("%d", &i);
				printf("请输入姓名:");
				scanf("%s", name);
				printf("请输入成绩:");
				scanf("%d", &score);
				n = length(h);
				InsertList(h, i, name, score, n);
				PrintList(h);
				break;
			case 4:
				printf("请输入删除位置:");
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
				printf("请输入正确选项\n");
		}
	}
}
