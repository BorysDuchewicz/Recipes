#include "recipes.h"


Recipe Recipes::best_price_to_kcal()
{
	Recipe recipe;
	double ratio = DBL_MAX;
	for (const auto& r : recipes)
	{
		if (r->final_price() / r->kcal() < ratio)
		{
			recipe = *r;
			ratio = r->final_price() / r->kcal();
		}
	}
	return recipe;
}

std::vector<Recipe> Recipes::find_all_breakfasts()
{
	std::vector<Recipe> breakfasts;
	for(auto& i:this->recipes)
	{
		if(category_to_str(i->get_category())=="Breakfast")
		{
			breakfasts.emplace_back(*i);
		}
	}
	return breakfasts;
}
std::vector<Recipe> Recipes::find_all_dinners()
{
	std::vector<Recipe> dinners;
	for (auto& i : this->recipes)
	{
		if (category_to_str(i->get_category()) == "Dinner")
		{
			dinners.emplace_back(*i);
		}
	}
	return dinners;
}

std::vector<Recipe> Recipes::find_all_suppers()
{
	std::vector<Recipe> suppers;
	for (auto& i : this->recipes)
	{
		if (category_to_str(i->get_category()) == "Supper")
		{
			suppers.emplace_back(*i);
		}
	}
	return suppers;
}

Recipes::Recipes(const std::string& file_name)
{
	this->recipes = RecipeLoader::read_recipe_from_file(file_name);
}

Recipes::Recipes(const Recipes& recipes)
{
	for(auto& i:recipes.recipes)
	{
		this->recipes.emplace_back(std::make_unique<Recipe>(*i));
	}
}

Recipes::Recipes(Recipes&& recipes)noexcept
{
	this->recipes = std::move(recipes.recipes);
}

Recipes Recipes::operator=(const Recipes& recipes)
{
	if(this!=&recipes)
	{
		for (auto& i : recipes.recipes)
		{
			this->recipes.emplace_back(std::make_unique<Recipe>(*i));
		}
	}
	return *this;
}

Recipes& Recipes::operator=(Recipes&& recipes) noexcept
{
	if (this != &recipes)
	{
		this->recipes = std::move(recipes.recipes);
	}
	return *this;
}

void Recipes::write_best_price_to_kcl_txt()
{
	
	std::ofstream write;
	write.open("The best option.txt");
	if (write.is_open())
	{
		write << best_price_to_kcal();
	}
	else
	{
		std::cout << "Path error" << std::endl;
	}
	write.close();


}

void Recipes::write_best_price_to_kcl_json()
{

	std::ofstream write;
	write.open("The best option.json");

	if (write.is_open())
	{

		write << to_json(best_price_to_kcal()).dump(3);
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	write.close();
}

std::optional<std::vector<std::unique_ptr<Recipe>>> Recipes::diet(const double& kcl)
{

	std::vector<std::unique_ptr<Recipe>> diet;

	std::vector<Recipe> breakfast = find_all_breakfasts();
	std::vector<Recipe> dinner = find_all_dinners();
	std::vector<Recipe> supper = find_all_suppers();
	std::vector<Recipe> tmp_diet(3);
	double tmp_kcl = DBL_MAX;

	//algorytm na znalezienie sumy najblizej podanej liczby
	for (const auto& b : breakfast)
	{
		for (const auto& d : dinner)
		{
			for (const auto& s : supper)
			{
				if (abs(kcl - b.kcal() - d.kcal() - s.kcal()) < tmp_kcl)
				{
					tmp_kcl = kcl - b.kcal() - d.kcal() - s.kcal();
					tmp_diet[0] = b;
					tmp_diet[1] = d;
					tmp_diet[2] = s;
				}
			}
		}
	}
	if (tmp_diet.empty())
	{
		return std::nullopt;
	}	
	for (const auto& recipe : tmp_diet)
	{
		diet.emplace_back(std::make_unique<Recipe>(recipe));
	}
	
	return diet;
}

std::ostream& operator<<(std::ostream& out, const Recipes& recipes)
{
	for(auto& recipe:recipes.recipes)
	{
		out << *recipe << std::endl;
	}
	return out;
}
