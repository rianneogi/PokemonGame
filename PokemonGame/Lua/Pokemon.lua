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

Pokemon[1] = {
    Name = "Bulbasaur",

    Types = {TYPE_GRASS, TYPE_POISON},

    BaseHP = 60,
    BaseAtk = 50,
    BaseDef = 40,
    BaseSpAtk = 60,
    BaseSpDef = 40,
    BaseSpeed = 50,

    HPGain = 2.5,
    AtkGain = 2,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 1.5,
    SpeedGain = 2,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[2] = {
    Name = "Ivysaur",

    Types = {TYPE_GRASS, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[3] = {
    Name = "Venusaur",

    Types = {TYPE_GRASS, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[4] = {
    Name = "Charmander",

    Types = {TYPE_FIRE},

    BaseHP = 40,
    BaseAtk = 60,
    BaseDef = 50,
    BaseSpAtk = 40,
    BaseSpDef = 50,
    BaseSpeed = 60,

    HPGain = 1.5,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 1.5,
    SpDefGain = 2,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[5] = {
    Name = "Charmeleon",

    Types = {TYPE_FIRE},

    BaseHP = 60,
    BaseAtk = 80,
    BaseDef = 70,
    BaseSpAtk = 60,
    BaseSpDef = 70,
    BaseSpeed = 80,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[6] = {
    Name = "Charizard",

    Types = {TYPE_FIRE},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[7] = {
    Name = "Squirle",

    Types = {TYPE_WATER},

    BaseHP = 50,
    BaseAtk = 40,
    BaseDef = 60,
    BaseSpAtk = 50,
    BaseSpDef = 60,
    BaseSpeed = 40,

    HPGain = 2,
    AtkGain = 1.5,
    DefGain = 2.5,
    SpAtkGain = 2,
    SpDefGain = 2.5,
    SpeedGain = 1.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[8] = {
    Name = "Wartortle",

    Types = {TYPE_WATER},

    BaseHP = 70,
    BaseAtk = 60,
    BaseDef = 80,
    BaseSpAtk = 70,
    BaseSpDef = 80,
    BaseSpeed = 60,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[9] = {
    Name = "Blastoise",

    Types = {TYPE_WATER},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[10] = {
    Name = "Caterpie",

    Types = {TYPE_BUG},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[11] = {
    Name = "Metapod",

    Types = {TYPE_BUG},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[12] = {
    Name = "Butterfree",

    Types = {TYPE_BUG, TYPE_FLYING},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[13] = {
    Name = "Weedle",

    Types = {TYPE_BUG, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[14] = {
    Name = "Kakuna",

    Types = {TYPE_BUG, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[15] = {
    Name = "Beedrill",

    Types = {TYPE_BUG, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 49,
    BaseDef = 49,
    BaseSpAtk = 65,
    BaseSpDef = 65,
    BaseSpeed = 45,

    HPGain = 2.3,
    AtkGain = 1,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}