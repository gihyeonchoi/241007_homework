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
	print("�̸��� �Է����ּ��� :");
	cin.getline(name, 8);
	print("��ȣ�� �Է����ּ��� :");
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
	println("� �������� �����Ͻðڽ��ϱ� ?");
	print("1:���� / 2:�̸� / 3:��ȭ��ȣ : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		int index;
		print("������ ����� ���� ��ȣ�� �Է����ּ��� (��� 0) : ");
		scanf("%d", &index);
		while (getchar() != '\n');
		if (count == 0 || count < index || index < 0) {		// ����ó��
			print("�����Ͱ� ���ų� �ùٸ��� ���� ���� �Է��߽��ϴ�.");
			return;
		}
		if (count2 == index)		// ù��° �� �����ϰ� ������
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
		println("�ùٸ� ���� �Է��� �ּ���.");
		break;
	}
}


int CountLinkedList(Friends** head)		// ���̼���
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