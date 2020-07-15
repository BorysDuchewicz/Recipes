#pragma once
#include"recipe.h"
#include "component_validator.h"
#include "recipe_validator.h"

//klasa sluzaca tylko do odczytu informacji z pliku
class RecipeLoader final
{
public:
	static std::vector<std::unique_ptr<Recipe>> read_recipe_from_file(const std::string& file_name);
	RecipeLoader() = delete;
	~RecipeLoader() = delete;
};