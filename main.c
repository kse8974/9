#include <stdio.h>
#include <stdlib.h>
#include "keyword.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if( c ==' ' ||
		c =='\t'||
		c =='\n'||
		c =='\r'||
		c =='(') 
	return 1; //������ڴ�
	
	return 0; // ���ǹ��� ���ڴ�	
}

int fget_word(FILE*fp, char*word)
{
	char c;
	while((c=fgetc(fp)) != EOF){			//1���� ���� 
		if(is_whitespace(c)==0)
		break;							//���ǹ��� �����̸� ���� 
	}
	
	if(c == EOF)			//���� ���� ���ڰ� �������϶� 
	{
	return 0;
	}
	
	//���������� �ܾ �ѱ��ھ� ����
	 
	int cnt = 0;
	word[cnt++] = c; 		//�Ʊ� ���� ù���� �Է� 
	word[cnt]='\0'	;			//Ȥ�� �ڿ��� �������� �����Ƿ�(�ѱ���¥�� �ܾ�) 
	
	while((word[cnt]=fgetc(fp))!= EOF)
	{
		if(is_whitespace(word[cnt]) ==1) //���鹮�ڸ� ������ ��� 
		{
			word[cnt] = '\0' ;  	//���ڿ� �� 
			break;
		}
		cnt++;		
	 } 
	 return cnt; 
}



int main(int argc, char *argv[]) {
	//�����̸� �Է¹޾Ƽ� fopen�ض�
	FILE *fp;
	char name[100];
	char word[100];
	
	//printf, scanf
	printf("���� �̸��� �Է����ֽʽÿ�:  ");
	scanf("%s", name);				//�����ʹ� &���̸� �ȵ�. 
	//fopen
	fp = fopen(name,"r");
	//error handling
	if(fp == NULL)
	{
		printf("Error! check the file name: %s \n", name);
		return -1;						// ���������� ���� �����������ν� Ʋ�ȴٴ� ���� �˷���. 
	}
	
	//word reading
	while(fget_word(fp, word) != 0)
	{
		count_word(word);
	}
	print_word();
	
	//fclose
	fclose(fp);
	
	return 0;
}


