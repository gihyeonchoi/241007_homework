#include "Header.h"
#include "Process.h"

int main()
{
	Friends* head = NULL;
	int choice = 10;
	while (choice != 0)
	{
		choice = 10;	// ���� �ʱ�ȭ
		ShowTable(&head);	// &head�� ������ ���� -> �ʱ���ġ �˷��ֱ�
		println("������ �۾��� �������ּ���");
		print("1:���� / 2:���� / 3:���� / 4:�˻� / 0:���� : ");
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
			println("�ùٸ� ���� �Է��� �ּ���.");
			break;
		}
	}

	return 0;
}