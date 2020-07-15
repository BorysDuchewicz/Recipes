#pragma once
#include "app_exception.h"

//plik przechowuj¹cy enumy i posiadajacy funkcje umozliwiajace ³atwe operowanie na nich
enum class Category{Breakfast,Dinner,Supper};
static const std::vector<std::string> CategoryValues = { "Breakfast","Dinner","Supper" };

inline Category str_to_category(const std::string& txt)
{
	if(txt=="Breakfast")
	{
		return Category::Breakfast;
	}
	else if(txt=="Dinner")
	{
		return Category::Dinner;
	}
	else if(txt=="Supper")
	{
		return Category::Supper;
	}
	throw AppException("no category for value");
}
inline std::string category_to_str(const Category& category)
{
	return CategoryValues[static_cast<int>(category)];
}

enum class Sex{Man,Women};
static const std::vector<std::string>SexValues = { "Man","Women" };

inline Sex str_to_sex(const std::string& txt)
{
	if(txt=="Man")
	{
		return Sex::Man;
	}
	else if(txt=="Women")
	{
		return Sex::Women;
	}
	throw AppException("wrong sex");
	
}
inline std::string sex_to_str(const Sex& sex)
{
	return SexValues[static_cast<int>(sex)];
}