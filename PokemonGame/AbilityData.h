#pragma once

#include "Include.h"

enum TargetType { TARGET_NONE, TARGET_UNIT, TARGET_GROUND, TARGET_NUM };

class AbilityData
{
public:
	std::string Name;
	int ID;

	int TargetType;
	std::string Description;

	AbilityData();
	~AbilityData();
};

void initAbilities();

extern std::vector<AbilityData> AbilityDatabase;