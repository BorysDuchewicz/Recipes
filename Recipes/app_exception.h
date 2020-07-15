#pragma once
#include "libs.h"

//klasa obs�ugujaca wyj�tki
class AppException: public std::exception
{
private:
	std::string message;
public:
	AppException(const std::string& message);

	std::string error_message()const;//metoda wyswietlajaca wiadomosc gdy zostanie wylapany wyjatek
};

