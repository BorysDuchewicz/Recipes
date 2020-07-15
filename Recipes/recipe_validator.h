#pragma once
#include "validator.h"
#include "recipe.h"
class RecipeValidator :
	public Validator<Recipe>
{
private:
	static bool is_name_validate(const Recipe& recipe);
	static bool is_day_validate(const Recipe& recipe);
	static bool is_month_validate(const Recipe& recipe);
	static bool is_year_validate(const Recipe& recipe);
public:
	std::unordered_map<std::string, std::string>validator(const Recipe& recipe)override;
	friend std::ostream& operator<<(std::ostream& out, const RecipeValidator& recipe);
	RecipeValidator() = default;
	~RecipeValidator() = default;

};




