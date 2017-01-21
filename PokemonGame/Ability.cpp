#include "Ability.h"

Ability::Ability()
{
	printf("WARNING: Ability init without id\n");
}

Ability::Ability(unsigned int id) : mAbilityID(id)
{
}

Ability::~Ability()
{
}

void Ability::use()
{
}
