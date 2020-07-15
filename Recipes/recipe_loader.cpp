#include "recipe_loader.h"

std::vector<std::unique_ptr<Recipe>> RecipeLoader::read_recipe_from_file(const std::string& file_name)
{
	std::vector<std::unique_ptr<Recipe>> recipes;
	std::vector<Component> components;
	RecipeValidator recipe_validator;
	ComponentValidator component_validator;
	std::ifstream reader;
	reader.open(file_name + ".json");
	
	if(reader.is_open())
	{
		json j;
		reader >> j;
		for(const auto& el:j)
		{
			components.clear();
			std::string name = el["name"].get<std::string>();
			int day = el["day"].get<int>();
			int month= el["month"].get<int>();
			int year = el["year"].get<int>();		
			Category category = str_to_category(el["category"].get<std::string>());
			
			for (const auto comp : el["components"])
			{
				std::string comp_name = comp["name"].get<std::string>();
				int calories = comp["calories"].get<int>();
				double weight = comp["weight"].get<double>();
				double price = comp["price"].get<double>();
				Component component{ comp_name,calories,weight,price };
				if (component_validator.validator(component).empty())
				{
					components.emplace_back(component);
				}
				else
				{
					std::cout << component_validator<<std::endl;
				}
			}
			
			Recipe recipe{name,day,month,year,category,components};
			if (recipe_validator.validator(recipe).empty())
			{
				recipes.emplace_back(std::make_unique<Recipe>(recipe));
			}
			else
			{
				std::cout << recipe_validator << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Error with file"<<std::endl;
	}
	reader.close();
	return recipes;
}
