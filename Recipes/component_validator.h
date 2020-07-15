#pragma once
#include "validator.h"
#include "component.h"
class ComponentValidator :
	public Validator<Component>
{
private:
	static bool is_name_validate(const Component& component);
	static bool is_calories_validate(const Component& component);
	static bool is_weight_validate(const Component& component);
	static bool is_price_validate(const Component& component);
public:
	std::unordered_map<std::string, std::string>validator(const Component& component)override;
	friend std::ostream& operator<<(std::ostream& out, const ComponentValidator& component);
	ComponentValidator() = default;
	~ComponentValidator() = default;

};

