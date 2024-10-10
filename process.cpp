#include "Header.h"
#include "Process.h"

void ShowTable(Friends** head, string search)
{
	int count = 1;
	Friends* tmp = *head;
	cout << "\n\n\n\n\n\n\n" << endl;
	cout << "+--No.--+--------Name--------+---------PhoneNumber------+" << endl;	// 간지
	if (search.empty())	// 매개변수 없이 모든 테이블 데이터 출력
	{
		
		while (tmp != NULL)
		{
			cout << "| " << count << "\t\t" << tmp->Name << "\t\t\t" << tmp->phoneNum << "\t|" << endl;
			tmp = tmp->link;
			count++;
		}
		
	}
	else
	{
		if (CheckData(tmp->Name, tmp->phoneNum, search) == 1)	// 검색했는데 처음 나온경우
		{
			cout << "| " << count << "\t\t" << tmp->Name << "\t\t\t" << tmp->phoneNum << "\t|" << endl;
		}
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
			count++;
			if (CheckData(tmp->Name, tmp->phoneNum, search) == 1)
			{
				cout << "| " << count << "\t\t" << tmp->Name << "\t\t\t" << tmp->phoneNum << "\t|" << endl;
			}
		}
	}
	cout << "+-------+--------------------+--------------------------+" << endl;
	cout << "\n\n\n\n\n\n\n" << endl;
}

int CheckData(string name, string phonenum, string search)
{
	if (name.compare(search) == 0 || phonenum.compare(search) == 0)
		return 1;
	else
		return 0;
}

void AddFriend(Friends** head)
{
	//char name[8], phone[12];
	string name, phone;
	string a = "0";
	print("[추가]이름을 입력해주세요 :");
	getline(cin, name);
	print("[추가]번호를 입력해주세요 :");
	getline(cin, phone);
	Friends* tmp = *head;
	if (name.compare(a) == 0) {
		println("해당 이름은 사용할 수 없습니다.");
		return;
	}

	if ((*head != NULL && name.compare(tmp->Name) == 0 && phone.compare(tmp->phoneNum) == 0) || (*head != NULL && phone==tmp->phoneNum))	// 처음부터 같을경우
	{
		println ("이미 등록되어있는 사람입니다.");
		return;
	}

	while (*head != NULL && tmp->link != NULL)		// 그 이후부터 같을 경우
	{
		Friends* pre = tmp;
		tmp = tmp->link;
		if ((name.compare(tmp->Name) == 0 && phone.compare(tmp->phoneNum) == 0) || phone.compare(tmp->phoneNum) == 0)
		{
			println("이미 등록되어있는 사람입니다.");
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
	println("어떤 기준으로 삭제하시겠습니까 ?");
	print("1:순서 / 2:이름 / 3:전화번호 / 0:취소 : ");
	scanf("%d", &choice);
	while (getchar() != '\n');
	switch (choice)
	{
	case 0:
		return;
	case 1:
		int index;
		print("삭제할 대상의 순서 번호를 입력해주세요 (취소 0) : ");
		scanf("%d", &index);
		while (getchar() != '\n');
		if (count == 0 || count < index || index < 0) {		// 예외처리
			println("데이터가 없거나 올바르지 않은 값을 입력했습니다.");
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
	{
		string delname;
		print("삭제할 대상의 이름을 입력해주세요 (취소 0) : ");
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
		println("취소하였거나 찾을 수 없는 이름입니다.");
		return;
	}
	case 3:
	{
		string delPhonenum;
		print("삭제할 대상의 번호를 입력해주세요 (취소 0) : ");
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
		println("취소하였거나 찾을 수 없는 번호입니다.");
		return;
	}
	default:
		println("올바른 값을 입력해 주세요.");
		break;
	}
}

void AlterData(Friends** head)
{
	int choice;
	string deldata, alterdata;
	Friends* tmp = *head;
	println("수정할 데이터 종류를 선택해주세요.");
	print("1:이름 / 2:전화번호 / 0:취소 : ");
	scanf("%d", &choice);
	while (getchar() != '\n');
	switch (choice)
	{
	case 0:
		return;
	case 1:
		print("변경할 대상의 이름을 입력해주세요 (취소 0) : ");
		getline(cin, deldata);

		if (tmp->Name.compare(deldata) == 0)
		{
			cout << "\n변경할 이름을 적어주세요 (현재 " << tmp->Name << ") : ";
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
				cout << "\n변경할 이름을 적어주세요 (현재 " << tmp->Name << ") : ";
				getline(cin, alterdata);
				tmp->Name = alterdata;
				return;
			}
		}

		println("취소하였거나 찾을 수 없는 이름입니다.");
		return;
	case 2:
		print("수정할 대상의 번호를 입력해주세요 (취소 0) : ");
		getline(cin, deldata);
		
		if (tmp->phoneNum.compare(deldata) == 0)
		{
			cout << "\n변경할 번호를 적어주세요 (현재 " << tmp->phoneNum << ") : ";
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
				cout << "\n변경할 번호를 적어주세요 (현재 " << tmp->phoneNum << ") : ";
				getline(cin, alterdata);
				tmp->phoneNum = alterdata;
				return;
			}
		}

		println("취소하였거나 찾을 수 없는 번호입니다.");
		return;
	}
}

void SearchData(Friends** head)
{
	if (*head != NULL)
	{
		Friends* tmp = *head;
		string searchdata;
		print("검색할 대상의 이름 혹은 번호를 입력해 주세요 : ");
		getline(cin, searchdata);
		ShowTable(&tmp, searchdata);
		return;
	}
	println("현재 데이터가 없습니다.");
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