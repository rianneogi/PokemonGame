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

    HPGain = 3,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 2,
    SpeedGain = 2.5,

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

    BaseHP = 80,
    BaseAtk = 70,
    BaseDef = 60,
    BaseSpAtk = 80,
    BaseSpDef = 60,
    BaseSpeed = 70,

    HPGain = 3,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 2,
    SpeedGain = 2.5,

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

    BaseHP = 100,
    BaseAtk = 90,
    BaseDef = 80,
    BaseSpAtk = 100,
    BaseSpDef = 80,
    BaseSpeed = 90,

    HPGain = 3,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 2,
    SpeedGain = 2.5,

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

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2.5,
    SpAtkGain = 2,
    SpDefGain = 2.5,
    SpeedGain = 3,

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

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2.5,
    SpAtkGain = 2,
    SpDefGain = 2.5,
    SpeedGain = 3,

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

    BaseHP = 80,
    BaseAtk = 100,
    BaseDef = 90,
    BaseSpAtk = 80,
    BaseSpDef = 90,
    BaseSpeed = 100,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2.5,
    SpAtkGain = 2,
    SpDefGain = 2.5,
    SpeedGain = 3,

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

    HPGain = 2.5,
    AtkGain = 2,
    DefGain = 3,
    SpAtkGain = 2.5,
    SpDefGain = 3,
    SpeedGain = 2,

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

    HPGain = 2.5,
    AtkGain = 2,
    DefGain = 3,
    SpAtkGain = 2.5,
    SpDefGain = 3,
    SpeedGain = 2,

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

    BaseHP = 90,
    BaseAtk = 80,
    BaseDef = 100,
    BaseSpAtk = 90,
    BaseSpDef = 100,
    BaseSpeed = 80,

    HPGain = 2.5,
    AtkGain = 2,
    DefGain = 3,
    SpAtkGain = 2.5,
    SpDefGain = 3,
    SpeedGain = 2,

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

    BaseHP = 35,
    BaseAtk = 50,
    BaseDef = 35,
    BaseSpAtk = 50,
    BaseSpDef = 50,
    BaseSpeed = 35,

    HPGain = 2,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1.5,

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
    BaseAtk = 50,
    BaseDef = 60,
    BaseSpAtk = 50,
    BaseSpDef = 60,
    BaseSpeed = 35,

    HPGain = 2,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1.5,

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

    BaseHP = 50,
    BaseAtk = 50,
    BaseDef = 60,
    BaseSpAtk = 70,
    BaseSpDef = 60,
    BaseSpeed = 50,

    HPGain = 2,
    AtkGain = 2.5,
    DefGain = 2,
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1.5,

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

    BaseHP = 40,
    BaseAtk = 65,
    BaseDef = 35,
    BaseSpAtk = 50,
    BaseSpDef = 35,
    BaseSpeed = 35,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 2,
    SpeedGain = 3,

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

    BaseHP = 50,
    BaseAtk = 65,
    BaseDef = 50,
    BaseSpAtk = 50,
    BaseSpDef = 55,
    BaseSpeed = 35,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 2,
    SpeedGain = 3,

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

    BaseHP = 50,
    BaseAtk = 80,
    BaseDef = 50,
    BaseSpAtk = 50,
    BaseSpDef = 55,
    BaseSpeed = 60,

    HPGain = 2,
    AtkGain = 3.25,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 2,
    SpeedGain = 3.25,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[16] = {
    Name = "Pidgey",

    Types = {TYPE_NORMAL, TYPE_FLYING},

    BaseHP = 45,
    BaseAtk = 50,
    BaseDef = 50,
    BaseSpAtk = 40,
    BaseSpDef = 35,
    BaseSpeed = 50,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2,
    SpAtkGain = 1.5,
    SpDefGain = 1,
    SpeedGain = 3,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[17] = {
    Name = "Pidgeotto",

    Types = {TYPE_NORMAL, TYPE_FLYING},

    BaseHP = 60,
    BaseAtk = 70,
    BaseDef = 50,
    BaseSpAtk = 40,
    BaseSpDef = 40,
    BaseSpeed = 70,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2,
    SpAtkGain = 1.5,
    SpDefGain = 1,
    SpeedGain = 3,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[18] = {
    Name = "Pidgeot",

    Types = {TYPE_NORMAL, TYPE_FLYING},

    BaseHP = 75,
    BaseAtk = 90,
    BaseDef = 50,
    BaseSpAtk = 40,
    BaseSpDef = 45,
    BaseSpeed = 90,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2,
    SpAtkGain = 1.5,
    SpDefGain = 1,
    SpeedGain = 3.25,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[19] = {
    Name = "Ratata",

    Types = {TYPE_NORMAL},

    BaseHP = 40,
    BaseAtk = 70,
    BaseDef = 40,
    BaseSpAtk = 50,
    BaseSpDef = 40,
    BaseSpeed = 50,

    HPGain = 2,
    AtkGain = 4,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[20] = {
    Name = "Raticate",

    Types = {TYPE_NORMAL},

    BaseHP = 60,
    BaseAtk = 85,
    BaseDef = 50,
    BaseSpAtk = 50,
    BaseSpDef = 45,
    BaseSpeed = 60,

    HPGain = 2,
    AtkGain = 4,
    DefGain = 1,
    SpAtkGain = 1,
    SpDefGain = 1,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[21] = {
    Name = "Spearow",

    Types = {TYPE_NORMAL, TYPE_FLYING},

    BaseHP = 45,
    BaseAtk = 50,
    BaseDef = 50,
    BaseSpAtk = 40,
    BaseSpDef = 35,
    BaseSpeed = 50,

    HPGain = 1.5,
    AtkGain = 3.75,
    DefGain = 1,
    SpAtkGain = 1.5,
    SpDefGain = 1,
    SpeedGain = 3.75,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[22] = {
    Name = "Fearow",

    Types = {TYPE_NORMAL, TYPE_FLYING},

    BaseHP = 70,
    BaseAtk = 100,
    BaseDef = 55,
    BaseSpAtk = 50,
    BaseSpDef = 40,
    BaseSpeed = 100,

    HPGain = 1.5,
    AtkGain = 3.75,
    DefGain = 1,
    SpAtkGain = 1.5,
    SpDefGain = 1,
    SpeedGain = 3.75,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[23] = {
    Name = "Ekans",

    Types = {TYPE_POISON},

    BaseHP = 50,
    BaseAtk = 40,
    BaseDef = 40,
    BaseSpAtk = 60,
    BaseSpDef = 60,
    BaseSpeed = 50,

    HPGain = 2,
    AtkGain = 1.5,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 1.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[24] = {
    Name = "Arbok",

    Types = {TYPE_POISON},

    BaseHP = 80,
    BaseAtk = 45,
    BaseDef = 45,
    BaseSpAtk = 70,
    BaseSpDef = 70,
    BaseSpeed = 50,

    HPGain = 2,
    AtkGain = 1.5,
    DefGain = 1.5,
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 1.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[25] = {
    Name = "Pikachu",

    Types = {TYPE_ELECTRIC},

    BaseHP = 45,
    BaseAtk = 55,
    BaseDef = 40,
    BaseSpAtk = 45,
    BaseSpDef = 50,
    BaseSpeed = 60,

    HPGain = 2,
    AtkGain = 2.5,
    DefGain = 1.5,
    SpAtkGain = 2,
    SpDefGain = 2.25,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[26] = {
    Name = "Raichu",

    Types = {TYPE_ELECTRIC},

    BaseHP = 60,
    BaseAtk = 70,
    BaseDef = 50,
    BaseSpAtk = 45,
    BaseSpDef = 60,
    BaseSpeed = 65,

    HPGain = 2,
    AtkGain = 2.5,
    DefGain = 1.5,
    SpAtkGain = 2,
    SpDefGain = 2.25,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[27] = {
    Name = "Sandshrew",

    Types = {TYPE_GROUND},

    BaseHP = 50,
    BaseAtk = 55,
    BaseDef = 60,
    BaseSpAtk = 30,
    BaseSpDef = 70,
    BaseSpeed = 40,

    HPGain = 2.2,
    AtkGain = 2.5,
    DefGain = 2.75,
    SpAtkGain = 1,
    SpDefGain = 3,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[28] = {
    Name = "Sandslash",

    Types = {TYPE_GROUND},

    BaseHP = 70,
    BaseAtk = 75,
    BaseDef = 65,
    BaseSpAtk = 30,
    BaseSpDef = 75,
    BaseSpeed = 45,

    HPGain = 2.2,
    AtkGain = 2.5,
    DefGain = 2.75,
    SpAtkGain = 1,
    SpDefGain = 3,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[29] = {
    Name = "Nidoran-F",

    Types = {TYPE_POISON},

    BaseHP = 40,
    BaseAtk = 40,
    BaseDef = 40,
    BaseSpAtk = 40,
    BaseSpDef = 40,
    BaseSpeed = 40,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[30] = {
    Name = "Nidorina",

    Types = {TYPE_POISON},

    BaseHP = 60,
    BaseAtk = 50,
    BaseDef = 60,
    BaseSpAtk = 60,
    BaseSpDef = 50,
    BaseSpeed = 50,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[31] = {
    Name = "Nidoqueen",

    Types = {TYPE_POISON, TYPE_GROUND},

    BaseHP = 100,
    BaseAtk = 70,
    BaseDef = 90,
    BaseSpAtk = 90,
    BaseSpDef = 70,
    BaseSpeed = 60,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[32] = {
    Name = "Nidoran-M",

    Types = {TYPE_POISON},

    BaseHP = 40,
    BaseAtk = 40,
    BaseDef = 40,
    BaseSpAtk = 40,
    BaseSpDef = 40,
    BaseSpeed = 40,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[33] = {
    Name = "Nidorino",

    Types = {TYPE_POISON},

    BaseHP = 60,
    BaseAtk = 60,
    BaseDef = 50,
    BaseSpAtk = 50,
    BaseSpDef = 60,
    BaseSpeed = 50,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[34] = {
    Name = "Nidoking",

    Types = {TYPE_POISON, TYPE_GROUND},

    BaseHP = 100,
    BaseAtk = 90,
    BaseDef = 70,
    BaseSpAtk = 70,
    BaseSpDef = 90,
    BaseSpeed = 60,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 2.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[35] = {
    Name = "Clefairy",

    Types = {TYPE_FAIRY},

    BaseHP = 70,
    BaseAtk = 30,
    BaseDef = 50,
    BaseSpAtk = 30,
    BaseSpDef = 40,
    BaseSpeed = 40,

    HPGain = 3,
    AtkGain = 1,
    DefGain = 3;
    SpAtkGain = 2.25,
    SpDefGain = 2.5,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[36] = {
    Name = "Clefable",

    Types = {TYPE_FAIRY},

    BaseHP = 110,
    BaseAtk = 40,
    BaseDef = 60,
    BaseSpAtk = 40,
    BaseSpDef = 60,
    BaseSpeed = 40,

    HPGain = 3,
    AtkGain = 1,
    DefGain = 3;
    SpAtkGain = 2.25,
    SpDefGain = 2.5,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[37] = {
    Name = "Vulpix",

    Types = {TYPE_FIRE},

    BaseHP = 45,
    BaseAtk = 55,
    BaseDef = 45,
    BaseSpAtk = 55,
    BaseSpDef = 45,
    BaseSpeed = 50,

    HPGain = 2.3,
    AtkGain = 2.5,
    DefGain = 2;
    SpAtkGain = 3,
    SpDefGain = 2.5,
    SpeedGain = 2.75,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[38] = {
    Name = "Ninetales",

    Types = {TYPE_FIRE},

    BaseHP = 75,
    BaseAtk = 85,
    BaseDef = 45,
    BaseSpAtk = 95,
    BaseSpDef = 55,
    BaseSpeed = 70,

    HPGain = 2.3,
    AtkGain = 2.5,
    DefGain = 2;
    SpAtkGain = 3,
    SpDefGain = 2.5,
    SpeedGain = 2.75,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[39] = {
    Name = "Jigglypuff",

    Types = {TYPE_NORMAL, TYPE_FAIRY},

    BaseHP = 100,
    BaseAtk = 30,
    BaseDef = 30,
    BaseSpAtk = 30,
    BaseSpDef = 30,
    BaseSpeed = 30,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 1.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[40] = {
    Name = "Wigglytuff",

    Types = {TYPE_NORMAL, TYPE_FAIRY},

    BaseHP = 140,
    BaseAtk = 40,
    BaseDef = 40,
    BaseSpAtk = 50,
    BaseSpDef = 50,
    BaseSpeed = 30,

    HPGain = 2.75,
    AtkGain = 2.5,
    DefGain = 2.5;
    SpAtkGain = 2.5,
    SpDefGain = 2.5,
    SpeedGain = 1.5,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[41] = {
    Name = "Zubat",

    Types = {TYPE_POISON, TYPE_FLYING},

    BaseHP = 40,
    BaseAtk = 40,
    BaseDef = 30,
    BaseSpAtk = 55,
    BaseSpDef = 45,
    BaseSpeed = 40,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2;
    SpAtkGain = 3.3,
    SpDefGain = 3,
    SpeedGain = 2,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[42] = {
    Name = "Golbat",

    Types = {TYPE_POISON, TYPE_FLYING},

    BaseHP = 60,
    BaseAtk = 50,
    BaseDef = 40,
    BaseSpAtk = 65,
    BaseSpDef = 55,
    BaseSpeed = 45,

    HPGain = 2,
    AtkGain = 3,
    DefGain = 2;
    SpAtkGain = 3.3,
    SpDefGain = 3,
    SpeedGain = 2,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[43] = {
    Name = "Oddish",

    Types = {TYPE_GRASS},

    BaseHP = 30,
    BaseAtk = 30,
    BaseDef = 35,
    BaseSpAtk = 50,
    BaseSpDef = 55,
    BaseSpeed = 30,

    HPGain = 2.75,
    AtkGain = 2,
    DefGain = 3;
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[44] = {
    Name = "Gloom",

    Types = {TYPE_GRASS},

    BaseHP = 70,
    BaseAtk = 40,
    BaseDef = 45,
    BaseSpAtk = 65,
    BaseSpDef = 70,
    BaseSpeed = 35,

    HPGain = 2.75,
    AtkGain = 2,
    DefGain = 3;
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[45] = {
    Name = "Vileplume",

    Types = {TYPE_GRASS},

    BaseHP = 90,
    BaseAtk = 50,
    BaseDef = 50,
    BaseSpAtk = 80,
    BaseSpDef = 85,
    BaseSpeed = 40,

    HPGain = 2.75,
    AtkGain = 2,
    DefGain = 3;
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 1,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[46] = {
    Name = "Paras",

    Types = {TYPE_BUG, TYPE_GRASS},

    BaseHP = 40,
    BaseAtk = 30,
    BaseDef = 50,
    BaseSpAtk = 50,
    BaseSpDef = 50,
    BaseSpeed = 40,

    HPGain = 2.5,
    AtkGain = 1.5,
    DefGain = 3;
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 2,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[47] = {
    Name = "Parasect",

    Types = {TYPE_BUG, TYPE_GRASS},

    BaseHP = 50,
    BaseAtk = 40,
    BaseDef = 70,
    BaseSpAtk = 65,
    BaseSpDef = 75,
    BaseSpeed = 45,

    HPGain = 2.5,
    AtkGain = 1.5,
    DefGain = 3;
    SpAtkGain = 3,
    SpDefGain = 3,
    SpeedGain = 2,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[48] = {
    Name = "Venonat",

    Types = {TYPE_BUG, TYPE_POISON},

    BaseHP = 45,
    BaseAtk = 40,
    BaseDef = 35,
    BaseSpAtk = 45,
    BaseSpDef = 35,
    BaseSpeed = 40,

    HPGain = 2.25,
    AtkGain = 2.5,
    DefGain = 2.25;
    SpAtkGain = 2.5,
    SpDefGain = 2.75,
    SpeedGain = 2.25,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}

Pokemon[49] = {
    Name = "Venomoth",

    Types = {TYPE_BUG, TYPE_POISON},

    BaseHP = 85,
    BaseAtk = 60,
    BaseDef = 45,
    BaseSpAtk = 55,
    BaseSpDef = 45,
    BaseSpeed = 45,

    HPGain = 2.25,
    AtkGain = 2.5,
    DefGain = 2.25;
    SpAtkGain = 2.5,
    SpDefGain = 2.75,
    SpeedGain = 2.25,

    Abilities = {
        {"Tackle", 1},
        {"Razor Leaf", 1},
		{"Vine Whip", 1},
		{"Leech Seed", 1}
    }
}