#pragma once
#include <string>

typedef struct _Friends {
	string Name;
	string phoneNum;	// 010-1234-5678 -> 0으로 시작하기도 하고 - 짝대기 붙으니깐
	struct _Friends* link = NULL;
} Friends;

void ShowTable(Friends**);
void AddFriend(Friends**);
void DeleteFriend(Friends**);
int CountLinkedList(Friends**);