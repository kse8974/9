#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//�����̸� �Է¹޾Ƽ� fopen�ض�
	FILE *fp;
	char name[100];
	
	//printf, scanf
	printf("���� �̸��� �Է����ֽʽÿ�:  ");
	scanf("%s", name);				//�����ʹ� &���̸� �ȵ�. 
	//fopen
	fp = fopen(name,"r");
	//error handling
	if(fp == NULL)
	{
		printf("Error! check the file name: %s \n", name);
		return -1;			// ���������� ���� �����������ν� Ʋ�ȴٴ� ���� �˷���. 
	}
	
	printf("%c \n", fgetc(fp));
	//fclose
	fclose(fp);
	
	return 0;
}
