#include <iostream>
using namespace std;


//Đọc tên các file có trong tập tin ZIP

void readZip(const char* zipPath, char**& Name, int &N) {

	N = 0;
	if (!zipPath) return;
	FILE* fp = NULL;
	int er = fopen_s(&fp, zipPath, "rb");

	if (!fp || er) return;

	fseek(fp, -22, SEEK_END);
	int startEndBlock = ftell(fp);

	fseek(fp, startEndBlock + 10, SEEK_SET);
	fread(&N, 2, 1, fp);
	int start = 0;
	fseek(fp, startEndBlock + 16, SEEK_SET);
	fread(&start, 4, 1, fp);
	fseek(fp, start, SEEK_SET);
	Name = new char* [N];

	for (int i = 0; i < N; i++) {

		start = ftell(fp);

		fseek(fp, start + 28, SEEK_SET);
		int nameLength = 0;
		fread(&nameLength, 2, 1, fp);

		fseek(fp, start + 30, SEEK_SET);
		int fieldLength = 0;
		fread(&fieldLength, 2, 1, fp);

		fseek(fp, start + 32, SEEK_SET);
		int commentLength = 0;
		fread(&commentLength, 2, 1, fp);

		Name[i] = new char[nameLength + 1];
		Name[i][nameLength] = '\0';

		fseek(fp, start + 46, SEEK_SET);
		fread(Name[i], 1, nameLength, fp);

		fseek(fp, start + 46 + nameLength + fieldLength + commentLength, SEEK_SET);

	}

}



int main() {

	const char* zipPath = "test.zip";
	int N = 0;
	char** Name = NULL;
	readZip(zipPath, Name, N);
	for (int i = 0; i < N; i++) {

		cout << Name[i] << endl;
	}

	return 0;
}