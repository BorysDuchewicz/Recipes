#include "user_data_service.h"

int UserDataService::get_int(const std::string& message)
{
	std::cout << message << std::endl;
	std::string text;
	std::getline(std::cin, text);

	if (!std::regex_match(text, std::regex("\\d+")))
	{
		throw AppException("incorrect int value");
	}

	return std::stoi(text);
}

std::string UserDataService::get_string(const std::string& message)
{
	std::cout << message << std::endl;
	std::string text;
	std::getline(std::cin, text);

	return text;
}

double UserDataService::get_double(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	if (!std::regex_match(txt, std::regex("\\d+")) && !std::regex_match(txt, std::regex("[0-9]+(\\.)[0-9]{0,2}")))
	{
		throw AppException("incorrect double value");
	}
	return stod(txt);
}

Sex UserDataService::get_sex(const std::string& message)
{
	std::cout << message << std::endl;
	std::string txt;
	std::getline(std::cin, txt);
	return str_to_sex(txt);
}
