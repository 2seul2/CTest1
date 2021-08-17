#include <stdio.h>
#include <conio.h>

int main()
{
	const char* name[20];  // 포인터
	int age;
	int heigh;
	float factor = 100.0;

	// int index = 0;  // while 문의 수행 횟수를 정의
	// while (index < 2)
	for (int index = 0; index < 2; index++)  // index(초기값) ; 수행조건 ; 증감
	{
		printf("당신의 이름을 입력하세요.");
		scanf("%s", name);

		printf("당신의 키를 cm 단위로 입력하세요.\n나이도 입력해 주세요.");
		scanf("%d""%d", &heigh, &age);

		printf("안녕하세요.\n %s 씨\n", name);
		printf("반갑습니다.\n");
		printf("저는     %5d     살이에요.\n", age);  // %d : 10진 정수
		printf("제 키는  %5d     cm 에요.\n", heigh / 10);
		printf("제 키는  %5.2f   m 에요.\n", (float)(heigh) / factor);  // %f : 실수 // 1.68
		// index ++;
	}
	
	getch();
	return 0;
}