#define _CRT_SECURE_NO_WARNINGS
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>

void f()
{
	setlocale(LC_ALL, "Russian");
	std::ifstream fin("text.txt");
	std::wofstream fout("OutText.txt");
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	fout.imbue(loc);

	int len = 0;
	int count = 0;
	wchar_t* outstr = nullptr;
	std::string temp;

	if (!fin.is_open())
	{
		std::cout << "File is not found" << std::endl;
		return;
	}

	while (std::getline(fin, temp))
	{
		len = mbstowcs(NULL, temp.c_str(), 0) + 1;
		outstr = new wchar_t[len];
		count = mbstowcs(outstr, temp.c_str(), len);
		fout << outstr << std::endl;
		delete[] outstr;
	}

	fout.close();
	fin.close();
}

int main()
{
	f();

	return 0;
}