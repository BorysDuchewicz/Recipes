#pragma once
#include "libs.h"

//szablon do validacji wylapuje bledy i przechowuje je w mapie
//jest to szablon z ktorego beda dzieciczyc inne klasy takie jak uservalidator
template<class T>
class Validator
{
protected:
	std::unordered_map < std::string, std::string > errors;
public:
	virtual std::unordered_map<std::string, std::string>validator(const T& t) = 0;


	Validator() = default;
	virtual ~Validator() = default;
};

