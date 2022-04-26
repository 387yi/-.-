#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void zhanbian1(char* arr, int k)
{
	int sz = strlen(arr);
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int a = *arr;
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + sz - 1) = a;
	}
}
void resesr(char* arr1, char* arr2)
{
	while (arr1 < arr2)
	{
		char  map = *arr1;
		*arr1 = *arr2;
		*arr2 = map;
		arr1++;
		arr2--;
	}
}
//三步法
void zhanbian(char* arr, int k)
{
	int sz = strlen(arr);
	resesr(arr, arr + k - 1);
	resesr(arr + k, arr + sz - 1);
	resesr(arr, arr + sz - 1);
}
int xuanzhuan(char* arr1, char* arr2)
{
	int sz = strlen(arr1);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		zhanbian(arr1, 1);
		int ret = strcmp(arr1, arr2);
		if (ret==0)
			return 1;
	}
	return 0;
}
int xuanzhuan1(char* arr1, char* arr2)
{
	int sz1 = strlen(arr1);
	int sz2 = strlen(arr1);
	if (sz1 != sz2)
		return 0;
	//strcat：字符串追加
	//strncat：字符串追加，相加几个字符串
	strncat(arr1, arr1, 6);
	//strstr 找子集，NULL为不为子集
	char *ret=strstr(arr1, arr2);
	if (ret == NULL)
		return 0;
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	//int ret=xuanzhuan(arr1, arr2);
	int ret = xuanzhuan1(arr1, arr2);

	if (ret = 1)
		printf("yes");
	else
		printf("no");
	return 0;
}