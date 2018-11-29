#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//파일이름 입력받아서 fopen해라
	FILE *fp;
	char name[100];
	
	//printf, scanf
	printf("파일 이름을 입력해주십시오:  ");
	scanf("%s", name);				//포인터는 &붙이면 안됨. 
	//fopen
	fp = fopen(name,"r");
	//error handling
	if(fp == NULL)
	{
		printf("Error! check the file name: %s \n", name);
		return -1;			// 비정상적인 값을 리턴해줌으로써 틀렸다는 것을 알려줌. 
	}
	
	printf("%c \n", fgetc(fp));
	//fclose
	fclose(fp);
	
	return 0;
}
