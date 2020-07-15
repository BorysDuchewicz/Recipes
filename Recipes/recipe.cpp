#include "recipe.h"

Recipe::Recipe(const std::string& name, const int& day, const int& month, const int& year,const Category& category,
               std::vector<Component> components): name{name},day{day},month{month},year{year},category{category}
{
	for(const auto& i:components)
	{
		this->components.emplace_back(std::make_unique<Component>(i));
	}
}

Recipe::Recipe(const Recipe& recipe)
{
	this->day = recipe.day;
	this->month = recipe.month;
	this->year = recipe.year;
	this->name = recipe.name;
	this->category = recipe.category;
	for(const auto& i:recipe.components)
	{
		this->components.emplace_back(std::make_unique<Component>(*i));
	}
}

Recipe::Recipe(Recipe&& recipe) noexcept
{
	this->day = recipe.day;
	this->month = recipe.month;
	this->year = recipe.year;
	this->name = recipe.name;
	this->category = recipe.category;
	this->components = std::move(recipe.components);
}

Recipe Recipe::operator=(const Recipe& recipe)
{
	if(this!=&recipe)
	{
		this->components.clear();
		this->day = recipe.day;
		this->month = recipe.month;
		this->year = recipe.year;
		this->name = recipe.name;
		this->category = recipe.category;
		for (const auto& i : recipe.components)
		{
			this->components.emplace_back(std::make_unique<Component>(*i));
		}
	}
	return *this;
}

Recipe& Recipe::operator=(Recipe&& recipe) noexcept
{
	
	if (this != &recipe)
	{
		this->components.clear();
		this->day = recipe.day;
		this->month = recipe.month;
		this->year = recipe.year;
		this->name = recipe.name;
		this->category = recipe.category;
		this->components= std::move(recipe.components);		
	}
	return *this;
}

std::string Recipe::get_name() const
{
	return this->name;
}

int Recipe::get_day() const
{
	return this->day;
}

int Recipe::get_month() const
{
	return this->month;
}

int Recipe::get_year() const
{
	return this->year;
}

Category Recipe::get_category() const
{
	return this->category;
}

double Recipe::kcal() const
{
	double kcal =0;
	for(const auto& i:this->components)
	{
		kcal += i->kcal();
	}
	return kcal;
}

double Recipe::final_price() const
{
	double price=0;
	for (const auto& i : this->components)
	{
		price += i->final_price();
	}
	return price;
}

std::ostream& operator<<(std::ostream& out, const Recipe& recipe)
{
	out << "Data opublikowania przepisu: " << std::endl;
	out<< recipe.day << "-" << recipe.month << "-" << recipe.year << std::endl;
	out << recipe.name << std::endl;
	out << "Kalorie dania: " << recipe.kcal() << std::endl;
	out<< "Cena: " << recipe.final_price() << std::endl;
	out << "Kategoria: " << category_to_str(recipe.category) << std::endl;
	out << "Skladniki: " << std::endl;

	for(const auto& i: recipe.components)
	{
		out << *i << std::endl;
	}
	 return out;
}

json to_json(const Recipe& recipe)
{
	json j;
	json jh;
	std::string date =std::to_string(recipe.day) + "-" +std::to_string( recipe.month) + "-" + std::to_string(recipe.year);
	j["Data opublikowania przepisu"] = date;
	j["Nazwa"] = recipe.name;
	j["Kalorie"] = recipe.kcal();
	j["Cena"] = recipe.final_price();
	j["Kategoria"] = category_to_str(recipe.category);
	for (const auto& i : recipe.components)
	{	
		jh.emplace_back(comp_to_json(*i));		
	}
	j["Skladniki"] = jh;
	jh.clear();
	return j;
}
