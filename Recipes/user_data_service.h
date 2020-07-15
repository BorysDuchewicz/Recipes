#pragma once
#include "libs.h"
#include "enums.h"


//klasa ktora przechowuje statyczne metody sluzoace to pobierania od uzytkownika poszczegolnych danych
class UserDataService final
{
public:
	UserDataService() = delete;
	static int get_int(const std::string& message);
	static std::string get_string(const std::string& message);
	static double get_double(const std::string& message);
	static Sex get_sex(const std::string& message);
};

