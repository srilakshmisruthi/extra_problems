#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL;
void create();
void median();
void traverse();
int flag = 0, size = 0, median1 = -1, median2 = -1;
void main()
{
	clrscr();
	create();
	if (size % 2 == 1)
		median1 = (size + 1) / 2;
	else
	{
		median1 = size / 2;
		median2 = (size / 2) + 1;
	}
	traverse();
	median();
}
void create()
{
	int val;
	char ans;
	do
	{
		printf("enter the data");
		scanf("%d", &val);
		temp = (struct node *)malloc(sizeof(struct node));
		if (temp == NULL)
			printf("unable to allocate memory");
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			size++;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			size++;
		}
		printf("do u want to insert more nodes(y/n):");
		ans = getch();
	} while (ans == 'y' || ans == 'Y');
}
void traverse()
{
	temp = head;
	if (temp == NULL)
		printf("list is empty ");
	else
	{
		while (temp != NULL)
		{
			printf("%d   ", temp->data);
			temp = temp->next;
		}
	}
}
void median()
{
	if (median2 == -1)
	{
		temp = head;
		flag = 1;
		while (flag < median1)
		{
			temp = temp->next;
			flag++;
		}
		printf("\n median is %d at %d postion ", temp->data, median1);
	}
	else
	{
		temp = head;
		flag = 1;
		while (flag < median1)
		{
			temp = temp->next;
			flag++;
		}
		printf("\n median is %d,%d at %d,%d postions ", temp->data,(temp->next)->data,median1,median2);
	}
}