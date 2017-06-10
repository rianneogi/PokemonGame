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

Pokemon = {}

Pokemon["1"] = {
    Name = "Bulbasaur",

    Types = {TYPE_GRASS, TYPE_POISON},

    BaseHP = 45,
    BaseAttack = 49,
    BaseDefense = 49,
    BaseSpAttack = 65,
    BaseSpDefense = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AttackGain = 1,
    DefenseGain = 1,
    SpAttackGain = 1,
    SpDefenseGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}