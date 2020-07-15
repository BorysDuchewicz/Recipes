#include "user_validator.h"


bool UserValidator::is_name_validate(const User& user)
{
	return std::regex_match(user.get_name(), std::regex("[A-Za-z]+"));
}

bool UserValidator::is_age_validate(const User& user)
{
	return user.get_age() > 0 && user.get_age()<120;
}

bool UserValidator::is_weight_validate(const User& user)
{
	return user.get_weight() > 0;
}

bool UserValidator::is_height_validate(const User& user)
{
	return user.get_weight() > 0 && user.get_weight() < 300;
}

std::unordered_map<std::string, std::string> UserValidator::validator(const User& user)
{
	errors.clear();
	if(!is_name_validate(user))
	{
		errors.emplace(std::make_pair("name is not valid: ", user.get_name()));
	}
	if (!is_age_validate(user))
	{
		errors.emplace(std::make_pair("age is not valid: ",std::to_string(user.get_age())));
	}
	if (!is_weight_validate(user))
	{
		errors.emplace(std::make_pair("weight is not valid: ",std::to_string(user.get_weight())));
	}
	if (!is_height_validate(user))
	{
		errors.emplace(std::make_pair("height is not valid: ",std::to_string(user.get_height())));
	}
	return errors;
}

std::ostream& operator<<(std::ostream& out, const UserValidator& user)
{
	for(const auto& error:user.errors)
	{
		out << error.first << " " << error.second << std::endl;
	}
	return out;
}
