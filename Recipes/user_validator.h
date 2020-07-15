#pragma once
#include "validator.h"
#include "user.h"

//klasa ktora swoimi metodami sprawdza czy podane dane do obiektu user sa poprawne jezeli nie wyswietla ktore nie sa dziedziczy po klasie Validator
class UserValidator :
	public Validator<User>
{
private:
	static bool is_name_validate(const User& user);
	static bool is_age_validate(const User& user);
	static bool is_weight_validate(const User& user);
	static bool is_height_validate(const User& user);
public:
	std::unordered_map<std::string, std::string>validator(const User& user)override;
	friend std::ostream& operator<<(std::ostream& out, const UserValidator& user);
	UserValidator() = default;
	~UserValidator() = default;
	
};

