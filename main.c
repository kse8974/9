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
	return 1; //공백글자다
	
	return 0; // 유의미한 글자다	
}

int fget_word(FILE*fp, char*word)
{
	char c;
	while((c=fgetc(fp)) != EOF){			//1문자 받음 
		if(is_whitespace(c)==0)
		break;							//유의미한 문자이면 나감 
	}
	
	if(c == EOF)			//최초 읽은 문자가 마지막일때 
	{
	return 0;
	}
	
	//본격적으로 단어를 한글자씩 읽음
	 
	int cnt = 0;
	word[cnt++] = c; 		//아까 읽은 첫글자 입력 
	word[cnt]='\0'	;			//혹시 뒤에서 못읽을수 있으므로(한글자짜리 단어) 
	
	while((word[cnt]=fgetc(fp))!= EOF)
	{
		if(is_whitespace(word[cnt]) ==1) //공백문자면 받은거 취소 
		{
			word[cnt] = '\0' ;  	//문자열 끝 
			break;
		}
		cnt++;		
	 } 
	 return cnt; 
}



int main(int argc, char *argv[]) {
	//파일이름 입력받아서 fopen해라
	FILE *fp;
	char name[100];
	char word[100];
	
	//printf, scanf
	printf("파일 이름을 입력해주십시오:  ");
	scanf("%s", name);				//포인터는 &붙이면 안됨. 
	//fopen
	fp = fopen(name,"r");
	//error handling
	if(fp == NULL)
	{
		printf("Error! check the file name: %s \n", name);
		return -1;						// 비정상적인 값을 리턴해줌으로써 틀렸다는 것을 알려줌. 
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


