#include<stdio.h>
#include<string.h>

/*
Written by 苏杰鑫 
*/


void wordCount_C(char *FileName)//判断字符数 
{
	FILE *fp;//文件指针
	char ch;
	int count = 0; 
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("文件打开失败");
		return ;
	}
	/*
	当文件未读完时，一直读到文件最后一个字符后面即EOF
	每读入一个字符则计数+1，最后因为是读过了最后一个字符，所以还要-1 
	*/
	while(!feof(fp))
	{
		ch = fgetc(fp);
		count++;		
	}
	count--;
	printf("字符数：%d",count);
	fclose(fp); 
}

void wordCount_W(char *FileName)//判断单词数 
{
	FILE *fp;
	char ch;
	int count = 0;
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("文件打开失败");
		return ;
	}
	/*
	根据格式可以知道单词的判断其实就是逗号空格和换行符
	那么在读到相应的字符时应该就知道前面是有一个单词的
	所以计数要+1，在文件流的末尾是没有换行符的
	所以还要计数+1 
	*/
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch==' '||ch==',')
		{
			count++;
		}
		if(ch=='\n')
		{
			count++;
		}
	}
	count++;
	printf("单词数:%d",count);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	
	int i;
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
