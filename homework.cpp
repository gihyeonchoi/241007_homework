#include "Header.h"
#include "Process.h"

int main()
{
	Friends* head = NULL;
	int choice = 10;
	while (choice != 0)
	{
		choice = 10;	// 선택 초기화
		ShowTable(&head);	// &head를 보내는 이유 -> 초기위치 알려주기
		println("수행할 작업을 선택해주세요");
		print("1:삽입 / 2:삭제 / 3:수정 / 4:검색 / 0:종료 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
		
		switch (choice)
		{
		case 1:
			AddFriend(&head);
			break;
		case 2:
			DeleteFriend(&head);
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