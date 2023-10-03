#include <iostream>
#include <Windows.h>

using namespace std;

namespace console {
	void init(LPCSTR title) {
		// Console allocation
		AllocConsole();
		SetConsoleTitleA(title);

		// I/O Redirection to allocated console
		FILE* dummy{};
		freopen_s(&dummy, "CONIN$", "w", stdin);
		freopen_s(&dummy, "CONOUT$", "r", stdout);
	}

	void print(std::string text) {
		cout << "[*]: " << text << endl;
	}

	string input(std::string question) {
		string answer;
		cout << "[?]: " << question;
		cin >> answer;

		return answer;
	}

	// Window management
	void show() { ShowWindow(GetConsoleWindow(), SW_SHOW); }

	void hide() { ShowWindow(GetConsoleWindow(), SW_HIDE); }
}