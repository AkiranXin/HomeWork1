#include<stdio.h>
#include<string.h>

void wordCount_C(char *FileName)
{
	FILE *fp;//文件指针
	char ch;
	char String[1000];
	int count = 0;
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("文件打开失败");
		return ;
	}
	while(!feof(fp))
	{
		ch = fgetc(fp);
		//printf("%c",ch);
		count++;
		printf("%c%d",ch,count);
		
	}
	count--;
	printf("字符数：%d",count);
	/*
	while(!feof(fp))
	{
		
		fscanf(fp,"%s",&String);
		printf("%s ",String);
	}
	printf("%s length:%d",String,strlen(String)); 
	*/
	fclose(fp); 
}

void wordCount_W(char *FileName)
{
	FILE *fp;
	char String[1000];
	char ch;
	int count = 0;
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("文件打开失败");
		return ;
	}
	/*while(!feof(fp))
	{
		fscanf(fp,"%s",&String);
		
		count++;
	}*/
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch==' '||ch==',')
		{
			count++;
		}
		printf("%c",ch);
		if(ch=='\n')
		{
			count++;
		}
	}
	count++;
	//printf("%s length:%d",String,strlen(String));
	printf("单词数:%d",count);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	
	int i,wordCount;//i作为循环变量，wordCount为计数 
	if(strcmp(argv[1],"-c")==0)
	{
		wordCount_C(argv[2]);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		wordCount_W(argv[2]);
	}
	else 
	{
		printf("不存在的参数!");
		return ;
	}
	return 0;
} 
