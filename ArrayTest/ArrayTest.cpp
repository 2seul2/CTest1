#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>

const int students = 20;
int score()
{
	int i, j, k;
	double average, total;
	double kor[students], eng[students], mat[students];  // 국어, 영어, 수학 점수

	srand(time(NULL));
	for (i = 0; i < students; i++)
	{
		kor[i] = (double)((rand() % 1000) + 1) / 10.0; // rand : 난수 발생기 (정수)  0 ~ 100.0   1 ~ 1000 0.1 ~ 100.0
		eng[i] = (double)((rand() % 1000) + 1) / 10.0; // rand : 난수 발생기 (정수)  0 ~ 100.0   1 ~ 1000 0.1 ~ 100.0
		mat[i] = (double)((rand() % 1000) + 1) / 10.0; // rand : 난수 발생기 (정수)  0 ~ 100.0   1 ~ 1000 0.1 ~ 100.0
	}
	//for (i = 0; i < students; i++)
	//{
	//	printf("%.1f  %.1f   %.1f\n", kor[i], eng[i], mat[i]);
	//}
	printf("코스타 IoT 국어 점수 현황\n==============================\n\n개인점수 리스트:\n");
	total = 0.;
	for (i = 0; i < students; i++)
	{
		printf("%7.1f\n", kor[i]); // %7.1f  :  실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += kor[i];
	}
	average = total / students;

	printf("총점 : %7.1f\n", total);
	printf("평균 : %7.1f\n", average);

	return 0;
}

int Good()
{
	int i, j, k;
	char good[5] = "Good";
	char mon[] = "morning";
	char noon[] = "afternoon";
	char even[] = "evening";

	while (1)
	{
		printf("지금 몇시죠? "); scanf("%d", &k);
		if (k > 7 && k < 12)
		{
			printf("%s %s \n ", good, mon);
		}
		else if (k < 18)
		{
			printf("%s %s \n ", good, noon);
		}
		else if (k < 23)
		{
			printf("%s %s \n ", good, even);
		}
		else
		{
			printf("Hi!\n ");
		}
	}

	return 0;
}

int PointerTest()
{
	int a[3][2] = { 1, 2, 3, 4, 5, 6 };

	printf("a[0] : %x \n", a[0]);
	printf("a[1] : %x \n", a[1]);
	printf("a[2] : %x \n", a[2]);
	printf("a    : %x \n\n\n\n", a);

	printf("a   : %x \n", a);
	printf("a+1 : %x \n", a + 1);
	printf("a+2 : %x \n", a + 2);

	return 0;
}

// function define 
//     Prototype  :  int str_len(char *str)
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌.

int str_len(char* str)  // 배열이 아닌 포인터로 받음  [] == *
{
	//	return strlen(str);
	int ret = 0;
	//	while (*(str + ret++)); return ret;
	while (1)
	{
		if (str[ret] != 0) ret++;
		else break;
	}
	return ret;
}

int solution1()
{
	// 문1) scanf 함수를 이용하여 문자열을 입력후
	//    해당 문자열을 한 글자씩 공백(_)을 삽입하여
	//	  출력하시오.
	//    > 12345   ==>  1_2_3_4_5
	// 문2) scanf 함수를 이용하여 문자열을 입력후
	//     getch() 함수를 이용하여 숫자 키를 누르면
	//	   해당 위치의 문자를 출력하시오

	char buf[100];  //	buffer : 버퍼 : 배열 == 포인터
	int i, j, k;

	printf("문자열을 입력하세요 : "); scanf("%s", buf);

	j = str_len(buf);
	printf("입력문자열 [%s] 의 길이는 %d 입니다 \n", buf, j);
	for (i = 0; i < j; i++)
	{
		printf("%c_", buf[i]);
	}

	while (1)
	{
		k = getch() - 0x30;   // 0 ~ 9 숫자키 (    ) 입력
		if (k >= 0 && k <= 9)
		{
			printf("%c", buf[k]);
			continue;
		}
		break;
	}

	return 0;
}

// function define 
//     Prototype  :  void swap(int a, int b)
// 정수 변수 a와 b의 값을 교환.

void swap(int* a, int* b)	// a,b를 포인터로 선언하고 전달된 매개변수 값으로 설정 (초기화)
{							// 포인터 사용방법 : 포인터가 가리키는 주소의 값 : *p
							//					 주소 자체 : p
	int c = *a;
	//	printf("	Input  > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
	*a = *b;
	*b = c;
	//	printf("	Result > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
}

int SwapTest()
{
	int a = 50, b = 60;
	//	printf("Original> a(%08x) : %d,  b(%08x) : %d\n", &a, a, &b, b);

	swap(&a, &b);

	//	printf("After swap> a(%08x) : %d,  b(%08x) : %d\n", &a, a, &b, b);

	return 0;
}

void  sort(int* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j]) swap(a + i, a + j); // = swap(&a[i], &a[j]); 
		}
	}
}

void swapEx(double* a, double* b)
{
	double c = *a;
	*a = *b;
	*b = c;
}

void swapEx1(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void swapEx2(const char** a, const char** b)
{
	const char* c = *a;
	*a = *b;
	*b = c;
}

//struct student {
//	int kor;
//	int eng;
//	char name[10];
//};
//typedef struct student STU;
typedef struct {
	char name[10];
	int kor;
	int eng;
	double tot;
	double avg;
} STU;

void SWAP(void* a, void* b, int op)
{
	if (op == 1)	// char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	if (op == 4)	// int, float
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	if (op == 8)	// double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
	if (op == sizeof(STU))	// STU
	{
		STU c = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = c;
	}
}

// 전역변수 : 이하의 함수에서 사용 가능
const int nArr = 10;
int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
char nam[] = "ABCDEFGHIJK"; //문자열 포인터로 변경 : "홍길동" "홍길이" "홍길삼" "홍길사" "홍길오" "길육" 길칠 길팔 길구 
const char* name[] = { "홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", "맹일", "맹이", "맹삼", "맹사", "맹오" };
STU student[nArr];

void  sortEx(double* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j])
			{
				//swapEx(a + i, a + j); // =swap(&a[i], &a[j]);  // tot : double
				//swap(kor + i, kor + j);
				//swap(eng + i, eng + j);
				//swapEx2(name + i, name + j);
				SWAP(a + i, a + j, 8);
				SWAP(student + i, student + j, 18);
				//SWAP(kor + i, kor + j, 4);
				//SWAP(eng + i, eng + j, 4);
				//SWAP(name + i, name + j, 4);
			}
		}
	}
}

void  sortSTU(STU* a, int n)   // a: 구조체의 포인터
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((a+i)->avg < (a+j)->avg)   // 구조체 포인터의 값 ===> a[i].avg < a[j].avg  // a+i: i번째 구조체의 avg  // a+j : j번째 구조체의 avg
			{
				SWAP(a + i, a + j, sizeof(STU));
			}
		}
	}
}


void sortTest()        // 배열을 이용한 성적처리
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
	}
	printf("Original :\n\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

void sortTestNew()        // 구조체를 이용한 성적처리
{
	double f_kor = 0.3, f_eng = 0.7;
	double tot[nArr];
	int i, j, k;

	for (i = 0; i < nArr; i++)
	{
		student[i].kor = kor[i];
		student[i].eng = eng[i];
		strcpy(student[i].name, name[i]);

		tot[i] = student[i].kor * f_kor + student[i].eng * f_eng;
	}
	printf("Original :\n\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sortEx(tot, nArr);

	printf("Sorted :\n\n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
}

// 문제) 성적표 파일을 fscanf 를 통해서 구조체로 읽어 들이기
//       sorting 한 다음에 출력 방향을 fout을 이용해
//       가로 스타일이 아닌 세로로 출력
//       이름 국어 영어 총점 순으로(메모장처럼)
void sortTestEX()        // 구조체를 이용한 성적처리 - 파일 입출력
{
	double f_kor = 0.3, f_eng = 0.7;
	//double tot[nArr], avg[nArr];
	int i, j, k;

	FILE* fin = fopen("C:\\Users\\si129\\table1.txt", "r");
	FILE* fout = fopen("C:\\Users\\si129\\table1.rpt", "w+b");
	for (i = 0; i < nArr; i++) fscanf(fin, "%s", student[i].name);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].kor);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].eng);
	for (i = 0; i < nArr; i++)
	{
		student[i].tot = student[i].kor + student[i].eng;
		student[i].avg = student[i].tot / 2;
	}

	fprintf(fout, "Original :\n\n");
	fprintf(fout, "%-7s %-7s %-7s %-7s %-7s\n","  이름","  국어", "  영어", "  총점", "  평균");
	for (int i = 0; i < nArr; i++)
	{
		fprintf(fout, "%7s %7d %7d %7.2f %7.2f\n",
			student[i].name, student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}

	sortSTU(student, nArr);

	fprintf(fout, "\n\nSorted :\n\n");
	for (int i = 0; i < nArr; i++)
	{
		fprintf(fout, "%7s %7d %7d %7.2f %7.2f\n",
			student[i].name, student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}
}

void VoidPrint(void* p, int i)
{
	if (i == 1)
	{
		char* cp = (char*)p;
		printf("%c\n", *cp);
	}
	if (i == 2)	printf("%d\n", *(int*)p);
	if (i == 3)	printf("%f\n", *(double*)p);
}

void VoidTest()
{
	char c = 'z';
	int  n = 10;
	double a = 1.414;

	void* vp;
	VoidPrint(&c, 1);
	VoidPrint(&n, 2);
	VoidPrint(&a, 3);
}

void StreamTest()
{
	int m;
	float d;
	char buf[1024];

	FILE* fin = fopen("C:\\Users\\si129\\aa.txt", "r");  // 만약 파일이 존재하지 않으면 NULL 반환 (오류)  // r : read
	//FILE* fout0 = fopen("C:\\users\\si129\\aa.o0", "w");  // o : out  //write
	//FILE* fout1 = fopen("C:\\users\\si129\\aa.o1", "a");  // a : append  // arr[10] -> 이렇게 하면 안됨
	FILE* fout = fopen("C:\\Users\\si129\\aa.txt.o", "w+b");

	if (fin != NULL)
	{
		//scanf("%d %f %s", &m, &d, buf);  // buf : 문자열 입력
		fscanf(fin, "%d %f %s", &m, &d, buf);                       // scanf 와 fscanf 똑같음, 차이는 in, out
		fprintf(fout, "정수 : %d\n실수 : %f\n문자열 : %s\n", m, d, buf);
		printf("정수 : %d\n실수 : %f\n문자열 : %s\n", m, d, buf);

		//while (1)
		//{
		//	if (fgets(buf, 1024, f) == NULL) break;
		//	fputs(buf, stdout);
		//	fputs(buf, fout0);
		//	fputs(buf, fout1);
		//	fputs(buf, fout2);
		//}
	}
	else printf("입력 파일이 존재하지 않습니다.\n");
}

int main()
{
	//score();
	//Good();
	//PointerTest();
	//solution1();
	//SwapTest();
	//sortTest();
	sortTestNew();
	//VoidTest();
	//StreamTest();
	sortTestEX();
}