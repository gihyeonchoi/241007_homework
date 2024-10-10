#include "Header.h"
#include "Process.h"

int main()
{
	Friends* head = NULL;
	int choice = 10;
	while (choice != 0)
	{
		if(choice != 4)
			ShowTable(&head);	// &head�� ������ ���� -> �ʱ���ġ �˷��ֱ�
		choice = 10;	// ���� �ʱ�ȭ
		println("������ �۾��� �������ּ���");
		print("1:���� / 2:���� / 3:���� / 4:�˻� / 5:��ü���̺�Ȯ�� / 0:���� : ");
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
			AlterData(&head);
			break;
		case 4:
			SearchData(&head);
			break;
		case 5:
			break;
		default:
			println("�ùٸ� ���� �Է��� �ּ���.");
			break;
		}
	}

	return 0;
}
