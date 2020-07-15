#include "component_validator.h"

bool ComponentValidator::is_name_validate(const Component& component)
{
	return std::regex_match(component.get_name(), std::regex("[A-Za-z]+[ ]*[A-Za-z]*"));
}

bool ComponentValidator::is_calories_validate(const Component& component)
{
	return component.get_calories() > 0;
}

bool ComponentValidator::is_weight_validate(const Component& component)
{
	return component.get_weight() > 0;
}

bool ComponentValidator::is_price_validate(const Component& component)
{
	return component.get_price() > 0;
}

std::unordered_map<std::string, std::string> ComponentValidator::validator(const Component& component)
{
	errors.clear();
	if (!is_name_validate(component))
	{
		errors.emplace(std::make_pair("Name is not valid ", component.get_name()));
	}
	if (!is_calories_validate(component))
	{
		errors.emplace(std::make_pair("Calories is not valid ",std::to_string(component.get_calories())));
	}
	if (!is_weight_validate(component))
	{
		errors.emplace(std::make_pair("Weight is not valid ", std::to_string(component.get_weight())));		
	}
	if (!is_price_validate(component))
	{
		errors.emplace(std::make_pair("Price is not valid ", std::to_string(component.get_price())));
	}
	return errors;
}

std::ostream& operator<<(std::ostream& out, const ComponentValidator& component)
{
	for (const auto& error : component.errors)
	{
		out << error.first << " " << error.second << std::endl;
	}
	return out;
}
