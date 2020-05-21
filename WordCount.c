#include<stdio.h>
#include<string.h>

/*
Written by �ս��� 
*/


void wordCount_C(char *FileName)//�ж��ַ��� 
{
	FILE *fp;//�ļ�ָ��
	char ch;
	int count = 0; 
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("�ļ���ʧ��");
		return ;
	}
	/*
	���ļ�δ����ʱ��һֱ�����ļ����һ���ַ����漴EOF
	ÿ����һ���ַ������+1�������Ϊ�Ƕ��������һ���ַ������Ի�Ҫ-1 
	*/
	while(!feof(fp))
	{
		ch = fgetc(fp);
		count++;		
	}
	count--;
	printf("�ַ�����%d",count);
	fclose(fp); 
}

void wordCount_W(char *FileName)//�жϵ����� 
{
	FILE *fp;
	char ch;
	int count = 0;
	if((fp=fopen(FileName,"r"))==NULL)
	{
		printf("�ļ���ʧ��");
		return ;
	}
	/*
	���ݸ�ʽ����֪�����ʵ��ж���ʵ���Ƕ��ſո�ͻ��з�
	��ô�ڶ�����Ӧ���ַ�ʱӦ�þ�֪��ǰ������һ�����ʵ�
	���Լ���Ҫ+1�����ļ�����ĩβ��û�л��з���
	���Ի�Ҫ����+1 
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
	printf("������:%d",count);
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
		printf("�����ڵĲ���!");
		return ;
	}
	return 0;
} 
