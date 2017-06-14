Attacks = {}

Attacks[1] = {
	Name = "Tackle",
	Description = "Tackles enemy",

	Type = TYPE_NORMAL,
	TargetCount = 1,

	CheckTarget = function()
		return 1
	end,

	OnUse = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
	end
}

Attacks[2] = {
	Name = "Leech Seed",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CheckTarget = function()
		return 1
	end,

	OnUse = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
		heal(getSelf(), 3)
	end
}

Attacks[3] = {
	Name = "Razor Leaf",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CanCast = function()
		return 1
	end,

	CheckTarget = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}

Attacks[4] = {
	Name = "Vine Whip",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CheckTarget = function()
		return 1
	end,

	OnUse = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}