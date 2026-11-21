#pragma once
#include <vector>
#include <string>
namespace Form {
	namespace WindowsShell {
		static class Utils
		{
        public:
			static std::vector<std::string> split(const std::string& str, const std::string& delim) {
                std::vector<std::string> result;
                size_t start = 0;
                size_t end = str.find(delim);

                while (end != std::string::npos) {
                    result.push_back(str.substr(start, end - start));
                    start = end + delim.length();
                    end = str.find(delim, start);
                }
                result.push_back(str.substr(start));
                return result;
            }
		};
	}
}

