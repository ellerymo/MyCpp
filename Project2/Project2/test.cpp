#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int Count(string filename, string dest)
{
	int Count = 0;
	char ch = 0;
	const char *file = filename.c_str();
	const char *find = dest.c_str();
	FILE* fout = fopen(file, "r");
	while (ch != EOF)
	{
		ch = fgetc(fout);
		while(ch == *find && *find != '\0')
		{
			find++;
			ch = fgetc(fout);
		}
		if (*find == '\0')
		{
			Count++;
		}
		find = dest.c_str();
	}
	fclose(fout);
	return Count;
}
int main()
{
	cout << Count("test.txt", "apple") << endl;
	getchar();
	return 0;
}