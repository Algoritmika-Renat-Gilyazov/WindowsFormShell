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
			Command(std::string cmd) {
				std::vector<std::string> parts = Utils::split(cmd, " ");

				if (!parts.empty()) {
					name = parts[0];
					args.assign(parts.begin() + 1, parts.end());
				}
			}
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
					if (cmd->name == "exit") {
						delete cmd;
						cmd = nullptr;
						return 0;
					} else {
						std::cout << "Unknown commad: " << cmd->name << std::endl;
					}
					delete cmd;
					cmd = nullptr;
				}
				return 0;
			}
			Command* input() {
				std::string cmd;
				std::getline(std::cin, cmd);
				return new Command(cmd);
			}
		};
	}
}

