#include "Header.h"

typedef struct _Friends {
	string Name;
	string phoneNum;	// 010-1234-5678 -> 0���� �����ϱ⵵ �ϰ� - ¦��� �����ϱ�
	struct _Friends* link = NULL;
} Friends;

int main()
{
	int choice = 10;
	while (choice != 0)
	{
		choice = 10;
		ShowTable();
		println("������ �۾��� �������ּ���");
		print("1:���� / 2:���� / 3:���� / 4:�˻� / 0:���� : ");
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
			println("�ùٸ� ���� �Է��� �ּ���.");
			break;
		}
	}

	return 0;
}