#include "Attack.h"

Attack::Attack()
{
	printf("WARNING: Ability init without id\n");
}

Attack::Attack(std::string name)
{
	int flag = 0;
	for (size_t i = 0; i < AttackDatabase.size(); i++)
	{
		if (AttackDatabase[i].Name == name)
		{
			mID = AttackDatabase[i].ID;
			mTargetMode = AttackDatabase[i].TargetMode;
			mDescription = AttackDatabase[i].Description;
			mType = AttackDatabase[i].Type;
			mName = name;
		}
	}
	if (flag == 0)
	{
		printf("ERROR: Cant find attack name: %s\n", name.c_str());
	}
}

Attack::~Attack()
{
}

void Attack::use()
{
}
