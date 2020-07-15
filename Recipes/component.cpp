#include "component.h"

Component::Component(const std::string& name, const int& calories, const double& weight, const double& price)
: name{name}, calories{calories}, weight{weight}, price{price}{}

double Component::kcal() const
{
	return this->weight * this->calories * 10;
}

double Component::final_price() const
{
	return this->price*this->weight;
}

std::string Component::get_name() const
{
	return this->name;
}

int Component::get_calories() const
{
	return this->calories;
}

double Component::get_weight() const
{
	return this->weight;
}

double Component::get_price() const
{
	return this->price;
}

std::ostream& operator<<(std::ostream& out, const Component& comp)
{
	return out << comp.name << ": " << comp.calories << "/100g " << comp.weight << "kg " << comp.price << "zl/kg " << std::endl;
}

json comp_to_json(const Component& comp)
{
	json j;
	j["Nazwa"] = comp.name;
	j["Kalorie"] = comp.calories;
	j["Waga"] = comp.weight;
	j["Cena"] = comp.price;
	return j;

}
