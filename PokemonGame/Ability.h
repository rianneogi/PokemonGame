#pragma once

#include "Attack.h"

class Ability
{
public:
	std::string mName;
	int mID;
	int mType;

	int mTargetMode;
	std::string mDescription;

	Ability();
	Ability(unsigned int id);
	~Ability();

	void use();
};

