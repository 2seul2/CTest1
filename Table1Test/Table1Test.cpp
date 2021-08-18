#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>

void StraamTest()
{
	int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
	int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
	const char* name[] = { "홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", "맹일", "맹이", "맹삼", "맹사", "맹오" };
	
	FILE* fin = fopen("C:\\Users\\si129\\table1.txt", "r");
	FILE* fout = fopen("C:\\Users\\si129\\table1.txt.o", "w+b");
	if (fin != NULL)
	{
		fscanf(fin, "%d %f %s", &kor, &eng, name);
	    fprintf(fout, "국어 : %d\n영어 : %d\n이름 : %s\n", kor, eng, name);
	    printf("국어 : %d\n영어 : %d\n이름 : %s\n", kor, eng, name);
	}
	else printf("입력 파일이 존재하지 않습니다.\n");
}

int main()
{
	StraamTest();
}