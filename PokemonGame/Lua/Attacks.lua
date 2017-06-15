TYPE_NORMAL = 0
TYPE_FIGHTING = 1
TYPE_FLYING = 2
TYPE_POISON = 3
TYPE_GROUND = 4
TYPE_ROCK = 5
TYPE_BUG = 6
TYPE_GHOST = 7
TYPE_STEEL = 8
TYPE_FIRE = 9
TYPE_WATER = 10
TYPE_GRASS = 11
TYPE_ELECTRIC = 12
TYPE_PSYCHIC = 13
TYPE_ICE = 14
TYPE_DRAGON = 15
TYPE_DARK = 16
TYPE_FAIRY = 17

Attacks = {}

getDistance = function(x1,y1,x2,y2)
	return math.max(math.abs(x1-x2), math.abs(y1-y2))
end

Attacks[1] = {
	Name = "Tackle",
	Description = "Tackles enemy",

	Type = TYPE_NORMAL,
	TargetCount = 1,

	CheckTarget = function()
		tx,ty = getAttackTarget()
		ax,ay = getPokemonPos(getAttacker())
		if(getDistance(tx,ty,ax,ay)<=2) then
			return 1
		else
			return 0
		end
	end,

	OnUse = function()
		x,y = getAttackTarget()
		if(isTileOccupied(x,y)==1) then
			dealDamage(getAttacker(), getPokemonAt(x,y), 10, TYPE_NORMAL)
		end
	end
}

Attacks[2] = {
	Name = "Leech Seed",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CheckTarget = function()
		tx,ty = getAttackTarget()
		ax,ay = getPokemonPos(getAttacker())
		if(getDistance(tx,ty,ax,ay)<=2) then
			return 1
		else
			return 0
		end
	end,

	OnUse = function()
		x,y = getAttackTarget()
		if(isTileOccupied(x,y)==1) then
			dealDamage(getAttacker(), getPokemonAt(x,y), 30, TYPE_GRASS)
		end
	end
}

Attacks[3] = {
	Name = "Razor Leaf",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CheckTarget = function()
		tx,ty = getAttackTarget()
		ax,ay = getPokemonPos(getAttacker())
		if(getDistance(tx,ty,ax,ay)<=3) then
			return 1
		else
			return 0
		end
	end,

	OnUse = function()
		x,y = getAttackTarget()
		if(isTileOccupied(x,y)==1) then
			dealDamage(getAttacker(), getPokemonAt(x,y), 30, TYPE_GRASS)
		end
	end
}

Attacks[4] = {
	Name = "Vine Whip",
	Description = "Tackles enemy",

	Type = TYPE_GRASS,
	TargetCount = 1,

	CheckTarget = function()
		tx,ty = getAttackTarget()
		ax,ay = getPokemonPos(getAttacker())
		if(getDistance(tx,ty,ax,ay)<=4) then
			return 1
		else
			return 0
		end
	end,

	OnUse = function()
		x,y = getAttackTarget()
		if(isTileOccupied(x,y)==1) then
			dealDamage(getAttacker(), getPokemonAt(x,y), 60, TYPE_GRASS)
		end
	end
}