#pragma once

#include "StatusEffect.h"

class Attack
{
public:
	std::string mName;
	int mID;
	int mType;

	int mTargetMode;
	std::string mDescription;

	Attack();
	Attack(std::string name);
	~Attack();

	void use();
};