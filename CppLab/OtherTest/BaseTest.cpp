#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "AAA.h"
using namespace std;

namespace BaseTest {


	void testStr(float _num) {
		char buff[12];
		sprintf_s(buff, "%0.2f", _num);
		printf("--- buff: %s\n", buff);

		string str = "asdwa";
		str = buff;
		printf("--- str: %s\n", str.c_str());
		int len = str.length();
		printf("--- len: %d\n", len);

		string listFilePath = "helloworld/aaa";
		if (listFilePath.find('/') != string::npos) {
			listFilePath = listFilePath.substr(0, listFilePath.rfind('/') + 1);
			printf("--- substr: %s\n", listFilePath.c_str());
		} else
			printf("no find /\n");

		std::string path = "aaa/vvv/bbb.c";
		int lastpos = path.find_last_of("/");
		printf("--- lastpos: %d\n", lastpos);
		path = path.substr(0, lastpos + 1);
		printf("--- destPath: %s\n", path.c_str());
	}

	void testStr2() {
		std::string s("456789");
		int len = s.length();
		for (size_t i = 0; i < len; i++) {


			int a = atoi(s.substr(i, 1).c_str());
			printf("--- num:%d\n", a);
		}
	}

	void testArrPtr() {
		// �õ���������һ���� - ʹ��ָ�������ָ�������
		printf("--- �õ���������һ������Ȥζʵ�� \n");

		const int MAXN = 8;
		int a[MAXN] = { 1, 2, 4, 8, 16, 32, 64, 128 };

		//a�ĵ�ַ����ƫ��1λ��ȡ����һ����ַ����ָ�����λ�õĶ�����ֻ�轫�����ַ��ǰƫ��1λ������ȡ����ȷ����������һλ
		int *p = (int*)(&a + 1);  //&a ��һ��ָ�룬ָ���СΪ4������ int(*)[MAXN]
		printf("--- %d\n", *((int*)p - 1)); //Ϊ128

		//a���׵�ַ����ƫ��7λ����ȡֵ
		//int num = *((int*)(&a) + 7); 
		//printf("--- num:%d\n", num);
	}

	void testArrPtr2() {
		auto func = [](int* arr, int row, int col) {
			int counter = 0;
			for (size_t i = 0; i < row; i++) {
				for (size_t j = 0; j < col; j++) {
					int num = *((int*)arr + counter++);
					printf("%d ", num);
				}
				printf("\n");
			}
		};


		int arr[5][10];
		int counter = 1;
		for (size_t i = 0; i < 5; i++) {
			for (size_t j = 0; j < 10; j++) {
				arr[i][j] = counter++;
			}
		}

		int* tmp = &(*arr)[0];
		func(tmp, 5, 10);


		int num = *((int*)(&arr) + 25);
		printf("--- num:%d\n", num);
	}

	const char* testFuncName() {
		return __FUNCTION__; //���ط�����
	}

	struct testAAA {
		testAAA() : name(__FUNCTION__) {
		}
		const char* name;
	};

	void testFunc() {
		const char* charr = testFuncName();
		printf("--- func name:%s\n", charr);

		testAAA t1;
		printf("--- test name:%s\n", t1.name);
	}

	void testlonglong() {
		auto num = 234123123ll;
		printf("--- num:%lld\n", num);
	}

	std::vector<int> GetVec() { return{ 1, 2, 3 }; }
	void testGetVec() {
		std::vector<int>&& v = GetVec();
		for (int a : v)
			printf("---a:%d\n", a);
	}

	void testR() {
		std::string tmp = " �Է���";
		std::string str = R"(hello \n \t �õ�
							world)" " ##���Ϻ�" + tmp;
		std::cout << str << std::endl;
	}

	static void parseUTF8(const std::string &str, std::vector<std::string>& ret) {
		int l = str.length();
		ret.clear();
		for (int p = 0; p < l;) {
			int size = 0;
			unsigned char c = str[p];
			if (c < 0x80) {
				size = 1;
			} else if (c < 0xc2) {
				size = 2;
			} else if (c < 0xe0) {
				size = 2;
			} else if (c < 0xf0) {
				size = 3;
			} else if (c < 0xf8) {
				size = 4;
			} else if (c < 0xfc) {
				size = 5;
			} else if (c < 0xfe) {
				size = 6;
			} else
				size = 7;
			std::string temp = "";
			temp = str.substr(p, size);
			ret.push_back(temp);
			p += size;
		}
	}

	static std::string subUTF8(const std::string &str, int from, int to) {
		if (from > to) return "";

		if (str.length() < to) return "";

		std::vector<std::string> vstr;
		parseUTF8(str, vstr);
		to = to > vstr.size() ? vstr.size() : to;

		std::vector<std::string>::iterator iter = vstr.begin();
		std::string res;
		std::string result;
		for (iter = (vstr.begin() + from); iter != (vstr.begin() + to); iter++) {
			res += *iter;
		}
		return res;
	}

	static std::string stringReplace(const std::string& input,
		const std::string& find,
		const std::string& replaceWith) {
		std::string strOut(input);
		int curPos = 0;

		int pos;
		while ((pos = strOut.find(find, curPos)) != -1) {
			strOut.replace(pos, find.size(), replaceWith);
			curPos = pos + replaceWith.size();
		}

		return strOut;
	}

	void testStr3() {
		std::string str = "asdע\n\n\n�ᰢ˹��qwe";
		str = stringReplace(str, "\n", "");
		std::string tmp = subUTF8(str.c_str(), 0, 6);
		std::string tmp2 = subUTF8(str.c_str(), 6, str.length() - 1);
		printf("--- %s\n", tmp.c_str());
		printf("--- %s\n", tmp2.c_str());
	}

	void testList() {
		std::list<std::string> ml;
		ml.push_back("aaaa");
		ml.push_back("bbb");
		ml.push_back("ccc");
		while (!ml.empty()) {
			printf("--- val:%s\n", (*ml.begin()).c_str());
			ml.pop_front();
		}
	}

	void main() {
		//testStr(56);
		//testStr2();
		//testArrPtr();
		//testArrPtr2();
		//testFunc();
		//testlonglong();
		//testGetVec();
		//testR();
		//testStringReplace();
		//testStr3();
		testList();
	}
}
