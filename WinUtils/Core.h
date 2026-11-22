#pragma once
#include "framework.h"
#include "Export.h"
namespace Form {
	namespace WindowsShell {
		namespace WinUtils {
			class MYLIB_API Core {
			public:
				HANDLE out;
				HANDLE in;
				Core(HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE), 
					 HANDLE in  = GetStdHandle(STD_INPUT_HANDLE)) : 
					out(out), 
					in(in)
				{
					SetConsoleTitleW(L"Windows FormShell");
					SetConsoleOutputCP(CP_UTF8);
					SetConsoleCP(CP_UTF8);
				}
			};
		}
	}
}

