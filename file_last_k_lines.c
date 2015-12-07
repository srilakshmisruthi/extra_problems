#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *p1;
	int k,n,count=0;
	char ch;
	printf("enter k value:");
	scanf("%d", &k);
	p1 = fopen("abc.txt", "r");
	if (p1 == NULL)
	{
		printf("unable to open the file");
		exit(0);
	}
	while (!(feof(p1)))
	{
		ch = getc(p1);
		if (ch == '\n')
			count++;
	}
	rewind(p1);
	n = count;
	count = 0;
	while (!feof(p1))
	{
		ch = getc(p1);
		if (ch == '\n')
		{
			count++;
		}
		if (count == (n - k))
			break;
	}
	while (!feof(p1))
	{
		ch = getch(p1);
		putchar(ch);
	}
}