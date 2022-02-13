#include <fstream>
#include <iostream> //проверить правильность описания функции,  ее вызова,  правильность передаваемых параметров
#include <windows.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
int _current_line_;
std::vector<std::string> loadCodeFromFile() {
	std::string filename;
	std::vector<std::string> codeLines;
	std::cout << "Enter the name of file: ";
	std::cin >> filename;
	std::ifstream file(filename);
	if (file.is_open()) {
		while (getline(file, filename)) {
			codeLines.push_back(filename);
		}
		file.close();
	}
	system("cls");
	return codeLines;
}

bool isMain(std::string s) { //возвращает true, если найденная строка содержит в себе функцию main
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'n' && s.at(i + 1) == 't') {
			s.erase(s.begin(), s.begin() + i);
			for (int i = 0; i < s.length(); ++i) {
				if (s[i] == 'm' && s.at(i + 1) == 'a' && s.at(i + 2) == 'i' && s.at(i + 3) == 'n') {
					return true;
				}
			}
		}
	}
	return false;
}
std::string getFunctionName(std::string s) {
	std::string newStr;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ') {
			switch (s[i]) {
			case 'v':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'i' && s.at(i + 3) == 'd') {
					for (int j = i + 4; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
				break;
			case 'i':
				if (s.at(i + 1) == 'n' && s.at(i + 2) == 't') {
					for (int j = i + 3; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
				break;
			case 'f':
				if (s.at(i + 1) == 'l' && s.at(i + 2) == 'o' && s.at(i + 3) == 'a' && s.at(i + 4) == 't') {
					for (int j = i + 5; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
				break;
			case 'c':
				if (s.at(i + 1) == 'h' && s.at(i + 2) == 'a' && s.at(i + 3) == 'r') {
					for (int j = i + 4; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
				break;
			case 'd':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'u' && s.at(i + 3) == 'b' && s.at(i + 4) == 'l' && s.at(i + 5) == 'e') {
					for (int j = i + 6; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
				break;
			case 'b':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'o' && s.at(i + 3) == 'l') {
					for (int j = i + 4; j < s.length(), s[j] != '('; ++j) {
						if (s[j] != ' ')
							newStr.push_back(s[j]);
					}
				}
				return newStr;
			default:
				std::cout << "\033[31munknown identifier at line  \033[0m" << _current_line_;
				Sleep(4000);
				exit(-2);
			}
		}
	}
	return newStr;
}
std::string getFunctionType(std::string s) { // получаем тип возвращаемого значения прототипа/функции
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ') {
			switch (s[i]) {
			case 'v':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'i' && s.at(i + 3) == 'd' && s.at(i + 4) == ' ')
					return "void";
				break; //протестить и убрать
			case 'i':
				if (s.at(i + 1) == 'n' && s.at(i + 2) == 't' && s.at(i + 3) == ' ')
					return "int";
				break; //протестить и убрать
			case 'f':
				if (s.at(i + 1) == 'l' && s.at(i + 2) == 'o' && s.at(i + 3) == 'a' && s.at(i + 4) == 't' && s.at(i + 5) == ' ')
					return "float";
				break; //протестить и убрать
			case 'd':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'u' && s.at(i + 3) == 'b' && s.at(i + 4) == 'l' && s.at(i + 5) == 'e' && s.at(i + 6) == ' ')
					return "double";
				break; //протестить и убрать
			case 'c':
				if (s.at(i + 1) == 'h' && s.at(i + 2) == 'a' && s.at(i + 3) == 'r' && s.at(i + 4) == ' ')
					return "char";
				break; //протестить и убрать
			case 'b':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'o' && s.at(i + 3) == 'l' && s.at(i + 4) == ' ')
					return "bool";
			case '{':
				return "";
			case '}':
				return "";
			case ' ':
				return "";
			case '\t':
				return "";
			default:
				std::cout << "\033[31munknown identifier at line  \033[0m" << _current_line_;
				Sleep(4000);
				exit(-3);
			}
		}
	}
	return " ";
}
std::vector<std::string> getTypeOfParameters(std::string s) {
	std::vector<std::string> arr;
	bool typeFound = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {			//обрезаем строку, пока не останутся параметры
			s.erase(s.begin(), s.begin() + i + 1);
			break;
		}
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ') {
			switch (s[i]) {
			case 'i':
				if (s[i + 1] == 'n' && s[i + 2] == 't') {
					arr.push_back("int");
					typeFound = true;
					i += 4;
					break;
				}
			case 'f':
				if (s[i + 1] == 'l' && s[i + 2] == 'o' && s[i + 3] == 'a' && s[i + 4] == 't') {
					arr.push_back("float");
					typeFound = true;
					i += 6;
					break;
				}
			case 'd':
				if (s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'b' && s[i + 4] == 'l' && s[i + 5] == 'e') {
					arr.push_back("double");
					typeFound = true;
					i += 7;
					break;
				}
			case 'c':
				if (s[i + 1] == 'h' && s[i + 2] == 'a' && s[i + 3] == 'r') {
					arr.push_back("char");
					typeFound = true;
					i += 5;
					break;
				}
			case 'b':
				if (s.at(i + 1) == 'o' && s.at(i + 2) == 'o' && s.at(i + 3) == 'l') {
					arr.push_back("bool");
					typeFound = true;
					i += 5;
					int x = 1 == 1 ? true : NULL;
					break;
				}
			case ' ':
				continue;
			case ',':
				typeFound = false;
				continue;
			case ')':
				return arr;
			default:
				if (typeFound) break;
				std::cout << "\033[31minvalid parameter type at line  \033[0m" << _current_line_;
				exit(-4);
			}
		}
	}
	return arr;
}
void checkParameters(std::string s, std::string type, std::unordered_map<std::string, std::string> m, std::vector<std::string> types) {
	std::unordered_map<std::string, std::string>::iterator it;
	std::vector<std::string> parameters;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			s.erase(s.begin(), s.begin() + i + 1);
			break;
		}
	}
	std::string temp = "";
	for (int i = 0; i < s.length(); ++i) {
		switch (s[i]) {
		case ' ':
			continue;
		case ',':
			if ((it = m.find(temp)) != m.end()) {
				parameters.push_back(it->second);
				temp = "";
				continue;
			}
			else {
				std::cout << "\033[31minvalid parameter in a function call at line  \033[0m" << _current_line_ + 1;;
			}
		case ')':
			if ((it = m.find(temp)) != m.end()) {
				parameters.push_back(it->second);
				i = s.length();
				break;
			}
			else {
				std::cout << "\033[31minvalid parameter in a function call at line  \033[0m" << _current_line_ + 1;
				exit(-9);
			}
		default:
			temp.push_back(s[i]);
			break;
		}
	}
	if (parameters.size() < types.size()) {
		std::cout << "\033[31mtoo few arguments in a function call at line \033[0m" << _current_line_ + 1;
		exit(-6);
	}
	else if (parameters.size() > types.size()) {
		std::cout << "\033[31mtoo many arguments in a function call at line \033[0m" << _current_line_ + 1;
		exit(-7);
	}
	for (int i = 0; i < types.size(); ++i) {
		if (parameters[i] != types[i]) {
			std::cout << "\033[31minvalid parameter in a function call at line \033[0m" << _current_line_ + 1;
			exit(-8);
		}
	}
}
int main() {
	std::string functionName = ""; //по условию в тексте программы присутствует только одна функция
	std::string type = "";
	std::unordered_map<std::string, std::string> mapOfNames; //хэш-таблица для хранения имени переменной и её типа
	std::vector<std::string> arrOfTypes;
	auto arr = loadCodeFromFile();
	bool mainFound = false;
	int prototypeLine = -1, mainLine, functionLine;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].length(); ++j) {
			if (arr[i][j] == 'i')
				mainFound = isMain(arr[i]);
			if (mainFound) {
				mainLine = i + 1;
				i = arr.size(); //выходим из циклов, если main найден
				break;
			}
			else j = arr[i].length(); //предотвращает лишние проходы по строке
		}
	}
	if (!mainFound) {
		std::cout << "main is not found!";
		exit(-1);
	}
	_current_line_ = 1;
	for (int i = 0; i < mainLine; ++i, ++_current_line_) { //цикл, после которого мы находим имя прототипа, его наличие, количество передаваемых параметров и их типы
		std::string tempReturnType = getFunctionType(arr[i]); //чтобы не вызывать много раз
		if (tempReturnType == "void") {
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "void";
				break;
			}
		}
		if (tempReturnType == "int") {
			if (getFunctionName(arr[i]) == "main")
				continue;
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "int";
				break;
			}
		}
		if (tempReturnType == "float") {
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "float";
				break;
			}
		}
		if (tempReturnType == "char") {
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "char";
				break;
			}
		}
		if (tempReturnType == "double") {
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "double";
				break;
			}
		}
		if (tempReturnType == "bool") {
			if (!arr[i].find("{") != std::string::npos && !arr[i + 1].find("{") != std::string::npos && arr[i].find(";") != std::string::npos) {
				prototypeLine = i;
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = "bool";
				break;
			}
		}
	}
	_current_line_ = 1;
	if (functionName.empty()) { //если прототип не найден, то ищем имя функции, тип возвр. значения и передаваемые параметры
		for (int i = 0; i < arr.size(); ++i, ++_current_line_) {
			if (arr[i].find("{") != std::string::npos && !arr[i].find(";") != std::string::npos && arr[i].find("(") != std::string::npos && arr[i].find(")") != std::string::npos && getFunctionName(arr[i]) != "main") {
				functionName = getFunctionName(arr[i]);
				arrOfTypes = getTypeOfParameters(arr[i]);
				type = getFunctionType(arr[i]);
				functionLine = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i].find("{") != std::string::npos && !arr[i].find(";") != std::string::npos && arr[i].find("(") != std::string::npos && arr[i].find(")") != std::string::npos) {
				functionLine = i;
				break;
			}
		}
		functionLine = -1;
	}
	if (!functionName.empty()) { //поиск переменных и их типов
		for (int i = mainLine; i < arr.size(); ++i) {
			if (!(arr[i].find(functionName) != std::string::npos)) {
				std::string name = "", temp = "";
				for (int j = 0; j < arr[i].length(); ++j, name = "") {
					if (arr[i][j] != ' ') {
						switch (arr[i][j]) {
						case 'i':
							if (arr[i].at(j + 1) == 'n' && arr[i].at(j + 2) == 't' && arr[i].at(j + 3) == ' ') {
								temp = "int";
								j += 3;
								while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
									++j;
								while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
									name.push_back(arr[i][j]);
									++j;
								}
								mapOfNames.insert(std::pair<std::string, std::string>(name, "int"));
							}
							--j;
							break;
						case 'f':
							temp = "float";
							if (arr[i][j + 1] == 'l' && arr[i][j + 2] == 'o' && arr[i][j + 3] == 'a' && arr[i][j + 4] == 't') {
								j += 5;
								while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
									++j;
								while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
									name.push_back(arr[i][j]);
									++j;
								}
								mapOfNames.insert(std::pair<std::string, std::string>(name, "float"));
							}
							--j;
							break;
						case 'c':
							temp = "char";
							if (arr[i][j + 1] == 'h' && arr[i][j + 2] == 'a' && arr[i][j + 3] == 'r') {
								j += 4;
								while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
									++j;
								while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
									name.push_back(arr[i][j]);
									++j;
								}
								mapOfNames.insert(std::pair<std::string, std::string>(name, "char"));
							}
							--j;
							break;
						case 'd':
							temp = "double";
							if (arr[i][j + 1] == 'o' && arr[i][j + 2] == 'u' && arr[i][j + 3] == 'b' && arr[i][j + 4] == 'l' && arr[i][j + 5] == 'e') {
								j += 6;
								while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
									++j;
								while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
									name.push_back(arr[i][j]);
									++j;
								}
								mapOfNames.insert(std::pair<std::string, std::string>(name, "double"));
							}
							--j;
							break;
						case 'b':
							temp = "bool";
							if (arr[i][j + 1] == 'o' && arr[i][j + 2] == 'o' && arr[i][j + 3] == 'l') {
								j += 4;
								while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
									++j;
								while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
									name.push_back(arr[i][j]);
									++j;
								}
								mapOfNames.insert(std::pair<std::string, std::string>(name, "bool"));
							}
							--j;
							break;
						case ',':
							++j;
							while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
								++j;
							while (arr[i].at(j) != ';' && arr[i].at(j) != '=' && arr[i].at(j) != ',' && arr[i].at(j) != ' ') {
								name.push_back(arr[i][j]);
								++j;
							}
							mapOfNames.insert(std::pair<std::string, std::string>(name, temp));
							--j;
							continue;
						case '=':
							++j;
							while (arr[i].at(j) == ' ') //избавляемся от лишних пробелов
								++j;
							while (std::isdigit(arr[i][j]))
								++j;
							--j;
							continue;
						case ' ':
							continue;
						case ';':
							j = arr[i].length();
							break;
						}
					}
				}
			}
		}
	}
	_current_line_ = mainLine;
	for (int i = mainLine; i < arr.size(); ++i, ++_current_line_) {
		if (arr[i].find(functionName) != std::string::npos) {
			if (prototypeLine == -1 && i < functionLine) {
				std::cout << "\033[31mfunction is not found at line \033[0m" << _current_line_ + 1; //если вызов функции до ее описания
				exit(-5);
			}
			checkParameters(arr[i], type, mapOfNames, arrOfTypes);
			break;
		}
	}
	std::cout << "compiled successfully";
}