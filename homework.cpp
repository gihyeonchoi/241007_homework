#include "Header.h"

typedef struct _Friends {
	string Name;
	string phoneNum;	// 010-1234-5678 -> 0으로 시작하기도 하고 - 짝대기 붙으니깐
	struct _Friends* link = NULL;
} Friends;

int main()
{
	int choice = 10;
	while (choice != 0)
	{
		choice = 10;
		ShowTable();
		println("수행할 작업을 선택해주세요");
		print("1:삽입 / 2:삭제 / 3:수정 / 4:검색 / 0:종료 : ");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			println("올바른 값을 입력해 주세요.");
			break;
		}
	}

	return 0;
}