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
	//char name[8], phone[12];
	string name, phone;
	string a = "0";
	print("[�߰�]�̸��� �Է����ּ��� :");
	getline(cin, name);
	print("[�߰�]��ȣ�� �Է����ּ��� :");
	getline(cin, phone);
	Friends* tmp = *head;
	if (name.compare(a) == 0) {
		println("�ش� �̸��� ����� �� �����ϴ�.");
		return;
	}

	if (*head != NULL && name.compare(tmp->Name) == 0 && phone.compare(tmp->phoneNum) == 0)
	{
		println ("�̹� ��ϵǾ��ִ� ����Դϴ�.");
		return;
	}
	while (*head != NULL && tmp->link != NULL)
	{
		Friends* pre = tmp;
		tmp = tmp->link;
		if (name.compare(tmp->Name) == 0 && phone.compare(tmp->phoneNum) == 0)
		{
			println("�̹� ��ϵǾ��ִ� ����Դϴ�.");
			return;
		}
	}

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
	print("1:���� / 2:�̸� / 3:��ȭ��ȣ / 0:��� : ");
	scanf("%d", &choice);
	while (getchar() != '\n');
	switch (choice)
	{
	case 0:
		return;
	case 1:
		int index;
		print("������ ����� ���� ��ȣ�� �Է����ּ��� (��� 0) : ");
		scanf("%d", &index);
		while (getchar() != '\n');
		if (count == 0 || count < index || index < 0) {		// ����ó��
			println("�����Ͱ� ���ų� �ùٸ��� ���� ���� �Է��߽��ϴ�.");
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
	{
		string delname;
		print("������ ����� �̸��� �Է����ּ��� (��� 0) : ");
		getline(cin, delname);
		if (tmp->Name.compare(delname) == 0)
		{
			*head = tmp->link;
			delete tmp;
			return;
		}
		while (tmp->link != NULL)
		{
			Friends* pre = tmp;
			tmp = tmp->link;
			if (tmp->Name.compare(delname) == 0)
			{
				pre->link = tmp->link;
				delete tmp;
				return;
			}
		}
		println("����Ͽ��ų� ã�� �� ���� �̸��Դϴ�.");
		return;
	}
	case 3:
	{
		string delPhonenum;
		print("������ ����� ��ȣ�� �Է����ּ��� (��� 0) : ");
		getline(cin, delPhonenum);
		if (tmp->Name.compare(delPhonenum) == 0)
		{
			*head = tmp->link;
			delete tmp;
			return;
		}
		while (tmp->link != NULL)
		{
			Friends* pre = tmp;
			tmp = tmp->link;
			if (tmp->phoneNum.compare(delPhonenum) == 0)
			{
				pre->link = tmp->link;
				delete tmp;
				return;
			}
		}
		println("����Ͽ��ų� ã�� �� ���� ��ȣ�Դϴ�.");
		return;
	}
	default:
		println("�ùٸ� ���� �Է��� �ּ���.");
		break;
	}
}

void AlterData(Friends** head)
{
	int choice;
	string deldata, alterdata;
	Friends* tmp = *head;
	println("������ ������ ������ �������ּ���.");
	print("1:�̸� / 2:��ȭ��ȣ / 0:��� : ");
	scanf("%d", &choice);
	while (getchar() != '\n');
	switch (choice)
	{
	case 0:
		return;
	case 1:
		print("������ ����� �̸��� �Է����ּ��� (��� 0) : ");
		getline(cin, deldata);

		if (tmp->Name.compare(deldata) == 0)
		{
			cout << "\n������ �̸��� �����ּ��� (���� " << tmp->Name << ") : ";
			getline(cin, alterdata);
			tmp->Name = alterdata;
			return;
		}
		while (tmp->link != NULL)
		{
			Friends* pre = tmp;
			tmp = tmp->link;
			if (tmp->Name.compare(deldata) == 0)
			{
				cout << "\n������ �̸��� �����ּ��� (���� " << tmp->Name << ") : ";
				getline(cin, alterdata);
				tmp->Name = alterdata;
				return;
			}
		}

		println("����Ͽ��ų� ã�� �� ���� �̸��Դϴ�.");
		return;
	case 2:
		print("������ ����� ��ȣ�� �Է����ּ��� (��� 0) : ");
		getline(cin, deldata);
		
		if (tmp->phoneNum.compare(deldata) == 0)
		{
			cout << "\n������ ��ȣ�� �����ּ��� (���� " << tmp->phoneNum << ") : ";
			getline(cin, alterdata);
			tmp->phoneNum = alterdata;
			return;
		}
		while (tmp->link != NULL)
		{
			Friends* pre = tmp;
			tmp = tmp->link;
			if (tmp->phoneNum.compare(deldata) == 0)
			{
				cout << "\n������ ��ȣ�� �����ּ��� (���� " << tmp->phoneNum << ") : ";
				getline(cin, alterdata);
				tmp->phoneNum = alterdata;
				return;
			}
		}

		println("����Ͽ��ų� ã�� �� ���� ��ȣ�Դϴ�.");
		return;
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