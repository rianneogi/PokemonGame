Abilities["Tackle"] = {
	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
	end
}

Abilities["Leech Seed"] = {
	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_NORMAL)
		heal(getSelf(), 3)
	end
}

Abilities["Razor Leaf"] = {
	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}

Abilities["Vine Whip"] = {
	Execute = function()
		dealDamage(getOpponent(), 3, TYPE_GRASS)
	end
}