#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include "Utils.h"
namespace Form {
	namespace WindowsShell {
		struct Command {
			std::string name;
			std::vector<std::string> args;
			Command(std::string cmd) : name(Utils::split(cmd, " ")[0]), args(Utils::split(cmd, " ").begin() + 1, Utils::split(cmd, " ").end()) {}
		};
		class Shell
		{
		public:
			std::filesystem::path cwd;
			const unsigned short MAJOR = 0;
			const unsigned short MINOR = 1;
			const unsigned short PATCH = 0;
			Shell(std::filesystem::path cwd = std::filesystem::current_path()) : cwd(cwd) {}
			unsigned int run() {
				std::cout << "Windows FormShell " << MAJOR << '.' << MINOR << '.' << PATCH << "\n\n";
				Command* cmd = nullptr;
				for (;;) {
					std::cout << std::filesystem::weakly_canonical(cwd).string() << "> ";
					cmd = input();
					delete cmd;
					cmd = nullptr;
				}
			}
			Command* input() {
				std::string cmd;
				std::getline(std::cin, cmd);
				return new Command(cmd);
			}
		};
	}
}

