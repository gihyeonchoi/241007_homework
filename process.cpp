#include "Header.h"
#include "Process.h"

void ShowTable(Friends** head)
{
	int count = 1;
	Friends* tmp = *head;
	cout << "\n\n\n\n\n\n\n" << endl;
	cout << "+--No.--+--------Name--------+---------PhoneNumber------+" << endl;
	while (tmp != NULL)
	{
		cout << "| " << count << "\t\t" << tmp->Name << "\t\t\t" << tmp->phoneNum << "\t|" << endl;
		tmp = tmp->link;
		count++;
	}
	cout << "+-------+--------------------+--------------------------+" << endl;
	cout << "\n\n\n\n\n\n\n" << endl;
}

void AddFriend(Friends** head)
{
	char name[8], phone[12];
	print("이름을 입력해주세요 :");
	cin.getline(name, 8);
	print("번호를 입력해주세요 :");
	cin.getline(phone, 12);
	Friends* newfriend = new Friends;
	newfriend->Name = name;
	newfriend->phoneNum = phone;
	if (*head == NULL)
	{
		*head = newfriend;
	}
	else
	{
		Friends* tmp = *head;
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		tmp->link = newfriend;
	}
}

void DeleteFriend(Friends** head)
{
	int count = CountLinkedList(head), count2 = 1;
	int choice;
	Friends* tmp = *head;
	println("어떤 기준으로 삭제하시겠습니까 ?");
	print("1:순서 / 2:이름 / 3:전화번호 : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		int index;
		print("삭제할 대상의 순서 번호를 입력해주세요 (취소 0) : ");
		scanf("%d", &index);
		while (getchar() != '\n');
		if (count == 0 || count < index || index < 0) {		// 예외처리
			print("데이터가 없거나 올바르지 않은 값을 입력했습니다.");
			return;
		}
		if (count2 == index)		// 첫번째 값 삭제하고 싶으면
		{
			*head = tmp->link;
			delete tmp;
			return;
		}
		while (tmp->link != NULL)
		{
			Friends* pre = tmp;
			tmp = tmp->link;
			count2++;
			if (count2 == index)
			{
				pre->link = tmp->link;
				delete tmp;
				return;
			}
		}
		return;
	case 2:
		break;
	case 3:
		break;
	default:
		println("올바른 값을 입력해 주세요.");
		break;
	}
}


int CountLinkedList(Friends** head)		// 길이세기
{
	int count = 0;
	Friends* tmp = *head;
	if (*head != NULL)
	{
		count++;
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
			count++;
		}
	}
	return count;
}