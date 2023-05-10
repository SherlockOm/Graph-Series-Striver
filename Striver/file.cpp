#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <regex>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Failed to open input file: " << argv[1] << "\n";
        return 1;
    }

    std::unordered_set<std::string> keywords = {
        "if", "else", "while", "do", "for", "int", "float", "char", "double"
    };
    std::unordered_set<char> operators = {
        '+', '-', '*', '/', '%', '=', '>', '<', '&', '|', '!', '?', ':', ';', ',', '.', '(', ')', '[', ']'
    };

    std::regex constant_regex(R"((\d+(\.\d*)?|\.\d+)([eE][-+]?\d+)?)");

    std::string line;
    while (std::getline(input, line)) {
        std::string token;
        for (const char c : line) {
            if (std::isspace(c) || operators.count(c) > 0) {
                if (!token.empty()) {
                    if (keywords.count(token) > 0) {
                        std::cout << "Keyword: " << token << "\n";
                    } else if (std::regex_match(token, constant_regex)) {
                        std::cout << "Constant: " << token << "\n";
                    } else {
                        std::cout << "Identifier: " << token << "\n";
                    }
                    token.clear();
                }
                if (operators.count(c) > 0) {
                    std::cout << "Operator: " << c << "\n";
                }
            } else {
                token += c;
            }
        }
        if (!token.empty()) {
            if (keywords.count(token) > 0) {
                std::cout << "Keyword: " << token << "\n";
            } else if (std::regex_match(token, constant_regex)) {
                std::cout << "Constant: " << token << "\n";
            } else {
                std::cout << "Identifier: " << token << "\n";
            }
        }
    }

    return 0;
}
