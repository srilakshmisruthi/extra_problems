#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL,*temp1=NULL;
int flag=0,size=0;
void create();
void insert(int);
void traverse();
void main()
{
	int n;
	clrscr();
	create();
	printf("enter the position to insert");
	scanf("%d",&n);
	traverse();
	insert(n);
	traverse();
}
void insert(int n)
{
	int val;
	printf("enter the data");
	scanf("%d", &val);
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
		printf("unable to allocate memory");
	temp->data = val;
	temp->next = NULL;
	if(n==1)
	{
		temp->next=head;
		tail->next=temp;
		head=temp;
	}
	else if(n>size)
	{
		tail->next=temp;
		temp->next=head;
		tail=temp;
	}
	else
	{
		temp1=head;
		while(flag!=n-2)
		{
			temp1=temp1->next;
			flag++;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
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
	tail->next=head;
}
void traverse()
{
	temp = head;
	if (temp == NULL)
		printf("list is empty ");
	else
	{
		while (temp != tail)
		{
			printf("%d   ", temp->data);
			temp = temp->next;
		}
		printf("%d  ",tail->data);
	}
}