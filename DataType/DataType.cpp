#include <stdio.h>  // C++ 전용 헤더 파일

int main()
{
	// Char, short, int, long, float, double 변수를 선언하고
	// 해당 data type 의 byte 수를 출력하시오.

	int age = 10;
	float pi = 3.141592;
	double dr2 = 1.414;

	printf("age = %d         sizeof(age) = %d\n", age, sizeof(age));
	printf("pi = %f          sizeof(pi) = %d\n", pi, sizeof(pi));
	printf("dr2 = %f         sizeof(pi) = %d\n", dr2, sizeof(dr2));
}