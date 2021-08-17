#include <stdio.h>
#include <conio.h>
	int dan = 1;  // 구구단의 1단 ~ 9단
	int nDan = 9;  // xx 단 : 9
	int hDan = 3;

int main()
{
	int i, j, k;

	for (; dan < 10; dan += hDan)  // hDan : 가로 방향 열 수
	{
		for (int idx = 1; idx <= nDan; idx++)  // ++은 1씩 증가    idx += 3
		{
			for (i = 0; i < hDan; i++)  // hDan : 가로 방향 열 수
			{
				printf("%2d x %2d = %3d        ", dan + i, idx, (dan + i) * idx);  // 2 x 2 = 4  dan x idx = (dan * idx)
			}
			printf("\n");
		}
		printf("\n");
	}

	while (1)
	{
		scanf("%d", &k);
		// if (k == 1)
		// {
		//	 printf(">1: One\n");
		// }
		// else if (k == 2) printf(">2: Two\n");
		// else if (k == 2) printf(">3: Three\n");
		// else if (k == 2) printf(">4: Four\n");
		// else if (k == 2) printf(">5: Five\n");
		// else if (k == 2) printf(">6: Six\n");
		// else if (k == 2) printf(">7: Seven\n");
		// else if (k == 2) printf(">8: Eight\n");
		// else if (k == 2) printf(">9: Nine\n");
		// else break;
		switch (k)
		{
		case 1:printf(">1: One\n");     break;
		case 2:printf(">2: Two\n");     break;
		case 3:printf(">3: Three\n");   break;
		case 4:printf(">4: Four\n");    break;
		case 5:printf(">5: Five\n");    break;
		case 6:printf(">6: Six\n");     break;
		case 7:printf(">7: Seven\n");   break;
		case 8:printf(">8: Eight\n");   break;
		case 9:printf(">9: Nine\n");    break;
		default: break;
		}
		if (k == 0) break;
	}
	printf("프로그램을 종료하려면 아무 키나 누르세요....");
	getch();
}