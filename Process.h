#pragma once
#include <string>

typedef struct _Friends {
	string Name;
	string phoneNum;	// 010-1234-5678 -> 0���� �����ϱ⵵ �ϰ� - ¦��� �����ϱ�
	struct _Friends* link = NULL;
} Friends;

void ShowTable(Friends**);
void AddFriend(Friends**);
void DeleteFriend(Friends**);
int CountLinkedList(Friends**);