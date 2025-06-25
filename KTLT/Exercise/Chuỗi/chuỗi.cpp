#include <iostream>
using namespace std;


//Xóa chuỗi con sub trong chuỗi lớn

char * RemoveSubstring(const char* s, const char* sub) {

	int len = strlen(s);
	int lenSub = strlen(sub);
	char* result = new char[len + 1];
	strncpy_s(result, len + 1, s, len);
	result[len] = '\0';

	while (1) {

		char* pos = strstr(result, sub);
		if (!pos) break;

		int remain = strlen(pos + lenSub);
		strncpy_s(pos, remain + 1, pos + lenSub + 1, remain);

	}

	return result;
}

//Thay chuỗi còn sub thành chuỗi con khác replace

char* ReplaceSubstring(const char* s, const char* sub, const char* replace) {

	int lenS = strlen(s);
	int lenSub = strlen(sub);
	int lenReplace = strlen(replace);

	char* result = new char[lenS + 1];
	strncpy_s(result, lenS + 1, s, lenS);
	result[lenS] = '\0';

	while (1) {

		char* pos = strstr(result, sub);
		if (!pos) break;

		int remain = strlen(pos + lenSub);
		int newLen = lenS - lenSub + lenReplace;
		int beforeLen = pos - result;

		char* newResult = new char[newLen + 1];
		newResult[newLen] = '\0';

		strncpy_s(newResult, beforeLen + 1, result, beforeLen);
		strncpy_s(newResult + beforeLen, lenReplace + 1, replace, lenReplace);
		strncpy_s(newResult + beforeLen + lenReplace, remain + 1, pos + lenSub, remain);

		delete[]result;
		result = newResult;
		lenS = newLen;

	}
	return result;

}


int main() {

	const char* s = "Nguyen Nhat Duy";
	const char* sub = "Duy";
	const char* replace = "Huy";
	char* res1 = RemoveSubstring(s, sub);
	char* res2 = ReplaceSubstring(s, sub, replace);

	cout << s << endl;
	cout << "Chuoi sau khi xoa sub: " << res1 << endl;
	cout << "Chuoi sau khi thay the sub: " << res2 << endl;
	delete[]res1;
	delete[]res2;

	return 0;
}