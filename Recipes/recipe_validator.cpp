#include "recipe_validator.h"

bool RecipeValidator::is_name_validate(const Recipe& recipe)
{
	return std::regex_match(recipe.get_name(), std::regex("[A-Za-z]+[ ]*[A-Za-z]*"));
}

bool RecipeValidator::is_day_validate(const Recipe& recipe)
{
	return recipe.get_day() > 0 && recipe.get_day() <= 31;
}

bool RecipeValidator::is_month_validate(const Recipe& recipe)
{
	return recipe.get_month() > 0 && recipe.get_month() <= 12;
}

bool RecipeValidator::is_year_validate(const Recipe& recipe)
{
	return recipe.get_year() <= 2020;
}

std::unordered_map<std::string, std::string> RecipeValidator::validator(const Recipe& recipe)
{
	errors.clear();
	if (!is_name_validate(recipe))
	{
		errors.emplace("Name is not valid ", recipe.get_name());
	}
	if (!is_day_validate(recipe))
	{
		errors.emplace("Day is not valid ", std::to_string(recipe.get_day()));
	}
	if (!is_month_validate(recipe))
	{
		errors.emplace("Month is not valid ",std::to_string(recipe.get_month()));
	}
	if (!is_year_validate(recipe))
	{
		errors.emplace("Year is not valid ", std::to_string(recipe.get_year()));
	}

	return errors;
}

std::ostream& operator<<(std::ostream& out, const RecipeValidator& recipe)
{
	for (const auto& error : recipe.errors)
	{
		out << error.first << " " << error.second << std::endl;
	}
	return out;
}
