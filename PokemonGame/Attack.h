#pragma once

#include "StatusEffect.h"

class Attack
{
public:
	std::string mName;
	int mID;
	int mType;

	int mTargetCount;
	std::string mDescription;

	Attack();
	Attack(std::string name);
	~Attack();

	void onUse();
	bool checkTarget();
};