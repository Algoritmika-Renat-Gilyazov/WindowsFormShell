#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include "Utils.h"
#include <format>
#include <Core.h>

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
			const unsigned short MINOR = 2;
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
					} else if (cmd->name.empty()) {

					} else if (cmd->name == "echo") {
						for (size_t i = 0; i < cmd->args.size(); ++i) {
							std::cout << std::format("{}{}", i > 0 ? " " : "", cmd->args[i]);
						}
						std::cout << std::endl;
					} else if (cmd->name == "pwd") {
						std::cout << std::filesystem::weakly_canonical(cwd).string() << std::endl;
					} else if (cmd->name == "cd") {
						cwd = "";
						for (size_t i = 0; i < cmd->args.size(); ++i) {
							cwd += std::format("{}{}", i > 0 ? " " : "", cmd->args[i]);
						}
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

