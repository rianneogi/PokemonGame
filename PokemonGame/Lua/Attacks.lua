Attacks = {}

Attacks[1] = {
	Name = "Tackle",
	Description = "Tackles enemy",

	Type = TYPE_NORMAL,
	TargetMode = TARGET_YES,

	CanCast = function()
		return 1
	end,

	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
	end
}

Attacks[2] = {
	Name = "Leech Seed",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetMode = TARGET_YES,

	CanCast = function()
		return 1
	end,

	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
		heal(getSelf(), 3)
	end
}

Attacks[3] = {
	Name = "Razor Leaf",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetMode = TARGET_YES,

	CanCast = function()
		return 1
	end,

	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}

Attacks[4] = {
	Name = "Vine Whip",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetMode = TARGET_YES,

	CanCast = function()
		return 1
	end,

	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}