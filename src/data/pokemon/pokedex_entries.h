const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
        .categoryName = _("UNKNOWN"),
        .height = 0,
        .weight = 0,
        .description = gDummyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSANAE] =
    {
        .categoryName = _("SEED"),
        .height = 7,
        .weight = 69,
        .description = gCSanaePokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANAE] =
    {
        .categoryName = _("SEED"),
        .height = 10,
        .weight = 130,
        .description = gSanaePokedexText,
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CALICE] =
    {
        .categoryName = _("SEED"),
        .height = 20,
        .weight = 1000,
        .description = gCAlicePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_ALICE] =
    {
        .categoryName = _("LIZARD"),
        .height = 6,
        .weight = 85,
        .description = gAlicePokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CREISEN] =
    {
        .categoryName = _("FLAME"),
        .height = 11,
        .weight = 190,
        .description = gCReisenPokedexText,
        .pokemonScale = 302,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REISEN] =
    {
        .categoryName = _("FLAME"),
        .height = 17,
        .weight = 905,
        .description = gReisenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CLILYWHITE] =
    {
        .categoryName = _("TINY TURTLE"),
        .height = 5,
        .weight = 90,
        .description = gCLilyWhitePokedexText,
        .pokemonScale = 412,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LILYWHITE] =
    {
        .categoryName = _("TURTLE"),
        .height = 10,
        .weight = 225,
        .description = gLilyWhitePokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLILYBLACK] =
    {
        .categoryName = _("SHELLFISH"),
        .height = 16,
        .weight = 855,
        .description = gCLilyBlackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_LILYBLACK] =
    {
        .categoryName = _("WORM"),
        .height = 3,
        .weight = 29,
        .description = gLilyBlackPokedexText,
        .pokemonScale = 549,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMOMIJI] =
    {
        .categoryName = _("COCOON"),
        .height = 7,
        .weight = 99,
        .description = gCMomijiPokedexText,
        .pokemonScale = 350,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MOMIJI] =
    {
        .categoryName = _("BUTTERFLY"),
        .height = 11,
        .weight = 320,
        .description = gMomijiPokedexText,
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSHIZUHA] =
    {
        .categoryName = _("HAIRY BUG"),
        .height = 3,
        .weight = 32,
        .description = gCShizuhaPokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHIZUHA] =
    {
        .categoryName = _("COCOON"),
        .height = 6,
        .weight = 100,
        .description = gShizuhaPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMEDICINE] =
    {
        .categoryName = _("POISON BEE"),
        .height = 10,
        .weight = 295,
        .description = gCMedicinePokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEDICINE] =
    {
        .categoryName = _("TINY BIRD"),
        .height = 3,
        .weight = 18,
        .description = gMedicinePokedexText,
        .pokemonScale = 508,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKOAKUMA] =
    {
        .categoryName = _("BIRD"),
        .height = 11,
        .weight = 300,
        .description = gCKoakumaPokedexText,
        .pokemonScale = 331,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOAKUMA] =
    {
        .categoryName = _("BIRD"),
        .height = 15,
        .weight = 395,
        .description = gKoakumaPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CNAZRIN] =
    {
        .categoryName = _("MOUSE"),
        .height = 3,
        .weight = 35,
        .description = gCNazrinPokedexText,
        .pokemonScale = 481,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NAZRIN] =
    {
        .categoryName = _("MOUSE"),
        .height = 7,
        .weight = 185,
        .description = gNazrinPokedexText,
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CTOKIKO] =
    {
        .categoryName = _("TINY BIRD"),
        .height = 3,
        .weight = 20,
        .description = gCTokikoPokedexText,
        .pokemonScale = 571,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOKIKO] =
    {
        .categoryName = _("BEAK"),
        .height = 12,
        .weight = 380,
        .description = gTokikoPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CREMILIA] =
    {
        .categoryName = _("SNAKE"),
        .height = 20,
        .weight = 69,
        .description = gCRemiliaPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REMILIA] =
    {
        .categoryName = _("COBRA"),
        .height = 35,
        .weight = 650,
        .description = gRemiliaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CCIRNO] =
    {
        .categoryName = _("MOUSE"),
        .height = 4,
        .weight = 60,
        .description = gCCirnoPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CIRNO] =
    {
        .categoryName = _("MOUSE"),
        .height = 8,
        .weight = 300,
        .description = gCirnoPokedexText,
        .pokemonScale = 426,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRUMIA] =
    {
        .categoryName = _("MOUSE"),
        .height = 6,
        .weight = 120,
        .description = gCRumiaPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RUMIA] =
    {
        .categoryName = _("MOUSE"),
        .height = 10,
        .weight = 295,
        .description = gRumiaPokedexText,
        .pokemonScale = 341,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHANGHAI] =
    {
        .categoryName = _("POISON PIN"),
        .height = 4,
        .weight = 70,
        .description = gShanghaiPokedexText,
        .pokemonScale = 488,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CFLANDRE] =
    {
        .categoryName = _("POISON PIN"),
        .height = 8,
        .weight = 200,
        .description = gCFlandrePokedexText,
        .pokemonScale = 381,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLANDRE] =
    {
        .categoryName = _("DRILL"),
        .height = 13,
        .weight = 600,
        .description = gFlandrePokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOURAI] =
    {
        .categoryName = _("POISON PIN"),
        .height = 5,
        .weight = 90,
        .description = gHouraiPokedexText,
        .pokemonScale = 511,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYOUMU] =
    {
        .categoryName = _("POISON PIN"),
        .height = 9,
        .weight = 195,
        .description = gCYoumuPokedexText,
        .pokemonScale = 408,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YOUMU] =
    {
        .categoryName = _("DRILL"),
        .height = 14,
        .weight = 620,
        .description = gYoumuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUKARI] =
    {
        .categoryName = _("FAIRY"),
        .height = 6,
        .weight = 75,
        .description = gCYukariPokedexText,
        .pokemonScale = 441,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUKARI] =
    {
        .categoryName = _("FAIRY"),
        .height = 13,
        .weight = 400,
        .description = gYukariPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSUIKA] =
    {
        .categoryName = _("FOX"),
        .height = 6,
        .weight = 99,
        .description = gCSuikaPokedexText,
        .pokemonScale = 542,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUIKA] =
    {
        .categoryName = _("FOX"),
        .height = 11,
        .weight = 199,
        .description = gSuikaPokedexText,
        .pokemonScale = 339,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMYSTIA] =
    {
        .categoryName = _("BALLOON"),
        .height = 5,
        .weight = 55,
        .description = gCMystiaPokedexText,
        .pokemonScale = 433,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MYSTIA] =
    {
        .categoryName = _("BALLOON"),
        .height = 10,
        .weight = 120,
        .description = gMystiaPokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMINORIKO] =
    {
        .categoryName = _("BAT"),
        .height = 8,
        .weight = 75,
        .description = gCMinorikoPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MINORIKO] =
    {
        .categoryName = _("BAT"),
        .height = 16,
        .weight = 550,
        .description = gMinorikoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKEINE] =
    {
        .categoryName = _("WEED"),
        .height = 5,
        .weight = 54,
        .description = gCKeinePokedexText,
        .pokemonScale = 423,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KEINE] =
    {
        .categoryName = _("WEED"),
        .height = 8,
        .weight = 86,
        .description = gKeinePokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKEINE] =
    {
        .categoryName = _("FLOWER"),
        .height = 12,
        .weight = 186,
        .description = gAKeinePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CIKU] =
    {
        .categoryName = _("MUSHROOM"),
        .height = 3,
        .weight = 54,
        .description = gCIkuPokedexText,
        .pokemonScale = 593,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_IKU] =
    {
        .categoryName = _("MUSHROOM"),
        .height = 10,
        .weight = 295,
        .description = gIkuPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKOISHI] =
    {
        .categoryName = _("INSECT"),
        .height = 10,
        .weight = 300,
        .description = gCKoishiPokedexText,
        .pokemonScale = 360,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_KOISHI] =
    {
        .categoryName = _("POISON MOTH"),
        .height = 15,
        .weight = 125,
        .description = gKoishiPokedexText,
        .pokemonScale = 285,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CYAMAME] =
    {
        .categoryName = _("MOLE"),
        .height = 2,
        .weight = 8,
        .description = gCYamamePokedexText,
        .pokemonScale = 833,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YAMAME] =
    {
        .categoryName = _("MOLE"),
        .height = 7,
        .weight = 333,
        .description = gYamamePokedexText,
        .pokemonScale = 406,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CCHEN] =
    {
        .categoryName = _("SCRATCH CAT"),
        .height = 4,
        .weight = 42,
        .description = gCChenPokedexText,
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHEN] =
    {
        .categoryName = _("CLASSY CAT"),
        .height = 10,
        .weight = 320,
        .description = gChenPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYORIHIME] =
    {
        .categoryName = _("DUCK"),
        .height = 8,
        .weight = 196,
        .description = gCYorihimePokedexText,
        .pokemonScale = 369,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YORIHIME] =
    {
        .categoryName = _("DUCK"),
        .height = 17,
        .weight = 766,
        .description = gYorihimePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 273,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CKAGUYA] =
    {
        .categoryName = _("PIG MONKEY"),
        .height = 5,
        .weight = 280,
        .description = gCKaguyaPokedexText,
        .pokemonScale = 404,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KAGUYA] =
    {
        .categoryName = _("PIG MONKEY"),
        .height = 10,
        .weight = 320,
        .description = gKaguyaPokedexText,
        .pokemonScale = 326,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMOKOU] =
    {
        .categoryName = _("PUPPY"),
        .height = 7,
        .weight = 190,
        .description = gCMokouPokedexText,
        .pokemonScale = 346,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MOKOU] =
    {
        .categoryName = _("LEGENDARY"),
        .height = 19,
        .weight = 1550,
        .description = gMokouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_CHATATE] =
    {
        .categoryName = _("TADPOLE"),
        .height = 6,
        .weight = 124,
        .description = gCHatatePokedexText,
        .pokemonScale = 369,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HATATE] =
    {
        .categoryName = _("TADPOLE"),
        .height = 10,
        .weight = 200,
        .description = gHatatePokedexText,
        .pokemonScale = 288,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLETTY] =
    {
        .categoryName = _("TADPOLE"),
        .height = 13,
        .weight = 540,
        .description = gCLettyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LETTY] =
    {
        .categoryName = _("PSI"),
        .height = 9,
        .weight = 195,
        .description = gLettyPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CPATCHOULI] =
    {
        .categoryName = _("PSI"),
        .height = 13,
        .weight = 565,
        .description = gCPatchouliPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PATCHOULI] =
    {
        .categoryName = _("PSI"),
        .height = 15,
        .weight = 480,
        .description = gPatchouliPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUUGI] =
    {
        .categoryName = _("SUPERPOWER"),
        .height = 8,
        .weight = 195,
        .description = gCYuugiPokedexText,
        .pokemonScale = 342,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUUGI] =
    {
        .categoryName = _("SUPERPOWER"),
        .height = 15,
        .weight = 705,
        .description = gYuugiPokedexText,
        .pokemonScale = 323,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CTENSHI] =
    {
        .categoryName = _("SUPERPOWER"),
        .height = 16,
        .weight = 1300,
        .description = gCTenshiPokedexText,
        .pokemonScale = 280,
        .pokemonOffset = 1,
        .trainerScale = 269,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_TENSHI] =
    {
        .categoryName = _("FLOWER"),
        .height = 7,
        .weight = 40,
        .description = gTenshiPokedexText,
        .pokemonScale = 354,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CPARSEE] =
    {
        .categoryName = _("FLYCATCHER"),
        .height = 10,
        .weight = 64,
        .description = gCParseePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PARSEE] =
    {
        .categoryName = _("FLYCATCHER"),
        .height = 17,
        .weight = 155,
        .description = gParseePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CMURASA] =
    {
        .categoryName = _("JELLYFISH"),
        .height = 9,
        .weight = 455,
        .description = gCMurasaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MURASA] =
    {
        .categoryName = _("JELLYFISH"),
        .height = 16,
        .weight = 550,
        .description = gMurasaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 312,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CKISUME] =
    {
        .categoryName = _("ROCK"),
        .height = 4,
        .weight = 200,
        .description = gCKisumePokedexText,
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KISUME] =
    {
        .categoryName = _("ROCK"),
        .height = 10,
        .weight = 1050,
        .description = gKisumePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKOGASA] =
    {
        .categoryName = _("MEGATON"),
        .height = 14,
        .weight = 3000,
        .description = gCKogasaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_KOGASA] =
    {
        .categoryName = _("FIRE HORSE"),
        .height = 10,
        .weight = 300,
        .description = gKogasaPokedexText,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSATORI] =
    {
        .categoryName = _("FIRE HORSE"),
        .height = 17,
        .weight = 950,
        .description = gCSatoriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 289,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SATORI] =
    {
        .categoryName = _("DOPEY"),
        .height = 12,
        .weight = 360,
        .description = gSatoriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CEIRIN] =
    {
        .categoryName = _("HERMIT CRAB"),
        .height = 16,
        .weight = 785,
        .description = gCEirinPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_EIRIN] =
    {
        .categoryName = _("MAGNET"),
        .height = 3,
        .weight = 60,
        .description = gEirinPokedexText,
        .pokemonScale = 288,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRAN] =
    {
        .categoryName = _("MAGNET"),
        .height = 10,
        .weight = 600,
        .description = gCRanPokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAN] =
    {
        .categoryName = _("WILD DUCK"),
        .height = 8,
        .weight = 150,
        .description = gRanPokedexText,
        .pokemonScale = 330,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CDAIYOUSEI] =
    {
        .categoryName = _("TWIN BIRD"),
        .height = 14,
        .weight = 392,
        .description = gCDaiyouseiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_DAIYOUSEI] =
    {
        .categoryName = _("TRIPLE BIRD"),
        .height = 18,
        .weight = 852,
        .description = gDaiyouseiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CNITORI] =
    {
        .categoryName = _("SEA LION"),
        .height = 11,
        .weight = 900,
        .description = gCNitoriPokedexText,
        .pokemonScale = 297,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NITORI] =
    {
        .categoryName = _("SEA LION"),
        .height = 17,
        .weight = 1200,
        .description = gNitoriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 275,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHINA] =
    {
        .categoryName = _("SLUDGE"),
        .height = 9,
        .weight = 300,
        .description = gCHinaPokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HINA] =
    {
        .categoryName = _("SLUDGE"),
        .height = 12,
        .weight = 300,
        .description = gHinaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKOMACHI] =
    {
        .categoryName = _("BIVALVE"),
        .height = 3,
        .weight = 40,
        .description = gCKomachiPokedexText,
        .pokemonScale = 675,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOMACHI] =
    {
        .categoryName = _("BIVALVE"),
        .height = 15,
        .weight = 1325,
        .description = gKomachiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 269,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CYUYUKO] =
    {
        .categoryName = _("GAS"),
        .height = 13,
        .weight = 1,
        .description = gCYuyukoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUYUKO] =
    {
        .categoryName = _("GAS"),
        .height = 16,
        .weight = 1,
        .description = gYuyukoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CMEILING] =
    {
        .categoryName = _("SHADOW"),
        .height = 15,
        .weight = 405,
        .description = gCMeilingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_MEILING] =
    {
        .categoryName = _("ROCK SNAKE"),
        .height = 88,
        .weight = 2100,
        .description = gMeilingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 515,
        .trainerOffset = 14,
    },

    [NATIONAL_DEX_CSAKUYA] =
    {
        .categoryName = _("HYPNOSIS"),
        .height = 10,
        .weight = 324,
        .description = gCSakuyaPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SAKUYA] =
    {
        .categoryName = _("HYPNOSIS"),
        .height = 16,
        .weight = 756,
        .description = gSakuyaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLUNASA] =
    {
        .categoryName = _("RIVER CRAB"),
        .height = 4,
        .weight = 65,
        .description = gCLunasaPokedexText,
        .pokemonScale = 469,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUNASA] =
    {
        .categoryName = _("PINCER"),
        .height = 13,
        .weight = 600,
        .description = gLunasaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMERLIN] =
    {
        .categoryName = _("BALL"),
        .height = 5,
        .weight = 104,
        .description = gCMerlinPokedexText,
        .pokemonScale = 364,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MERLIN] =
    {
        .categoryName = _("BALL"),
        .height = 12,
        .weight = 666,
        .description = gMerlinPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLYRICA] =
    {
        .categoryName = _("EGG"),
        .height = 4,
        .weight = 25,
        .description = gCLyricaPokedexText,
        .pokemonScale = 489,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LYRICA] =
    {
        .categoryName = _("COCONUT"),
        .height = 20,
        .weight = 1200,
        .description = gLyricaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_CLAYLA] =
    {
        .categoryName = _("LONELY"),
        .height = 4,
        .weight = 65,
        .description = gCLaylaPokedexText,
        .pokemonScale = 545,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LAYLA] =
    {
        .categoryName = _("BONE KEEPER"),
        .height = 10,
        .weight = 450,
        .description = gLaylaPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKANAKO] =
    {
        .categoryName = _("KICKING"),
        .height = 15,
        .weight = 498,
        .description = gCKanakoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 259,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_KANAKO] =
    {
        .categoryName = _("PUNCHING"),
        .height = 14,
        .weight = 502,
        .description = gKanakoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 277,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CRIN] =
    {
        .categoryName = _("LICKING"),
        .height = 12,
        .weight = 655,
        .description = gCRinPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RIN] =
    {
        .categoryName = _("POISON GAS"),
        .height = 6,
        .weight = 10,
        .description = gRinPokedexText,
        .pokemonScale = 369,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CUTSUHO] =
    {
        .categoryName = _("POISON GAS"),
        .height = 12,
        .weight = 95,
        .description = gCUtsuhoPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UTSUHO] =
    {
        .categoryName = _("SPIKES"),
        .height = 10,
        .weight = 1150,
        .description = gUtsuhoPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CICHIRIN] =
    {
        .categoryName = _("DRILL"),
        .height = 19,
        .weight = 1200,
        .description = gCIchirinPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 299,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_ICHIRIN] =
    {
        .categoryName = _("EGG"),
        .height = 11,
        .weight = 346,
        .description = gIchirinPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSUNNYMILK] =
    {
        .categoryName = _("VINE"),
        .height = 10,
        .weight = 350,
        .description = gCSunnyMilkPokedexText,
        .pokemonScale = 304,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUNNYMILK] =
    {
        .categoryName = _("PARENT"),
        .height = 22,
        .weight = 800,
        .description = gSunnyMilkPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_CLUNACHILD] =
    {
        .categoryName = _("DRAGON"),
        .height = 4,
        .weight = 80,
        .description = gCLunaChildPokedexText,
        .pokemonScale = 399,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUNACHILD] =
    {
        .categoryName = _("DRAGON"),
        .height = 12,
        .weight = 250,
        .description = gLunaChildPokedexText,
        .pokemonScale = 299,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSTARSAPPHIRE] =
    {
        .categoryName = _("GOLDFISH"),
        .height = 6,
        .weight = 150,
        .description = gCStarSapphirePokedexText,
        .pokemonScale = 379,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STARSAPPHIRE] =
    {
        .categoryName = _("GOLDFISH"),
        .height = 13,
        .weight = 390,
        .description = gStarSapphirePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUUKA] =
    {
        .categoryName = _("STAR SHAPE"),
        .height = 8,
        .weight = 345,
        .description = gCYuukaPokedexText,
        .pokemonScale = 326,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUUKA] =
    {
        .categoryName = _("MYSTERIOUS"),
        .height = 11,
        .weight = 800,
        .description = gYuukaPokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CAYA] =
    {
        .categoryName = _("BARRIER"),
        .height = 13,
        .weight = 545,
        .description = gCAyaPokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AYA] =
    {
        .categoryName = _("MANTIS"),
        .height = 15,
        .weight = 560,
        .description = gAyaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CSHIKIEIKI] =
    {
        .categoryName = _("HUMAN SHAPE"),
        .height = 14,
        .weight = 406,
        .description = gCShikieikiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SHIKIEIKI] =
    {
        .categoryName = _("ELECTRIC"),
        .height = 11,
        .weight = 300,
        .description = gShikieikiPokedexText,
        .pokemonScale = 351,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSHOU] =
    {
        .categoryName = _("SPITFIRE"),
        .height = 13,
        .weight = 445,
        .description = gCShouPokedexText,
        .pokemonScale = 277,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHOU] =
    {
        .categoryName = _("STAG BEETLE"),
        .height = 15,
        .weight = 550,
        .description = gShouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CWRIGGLE] =
    {
        .categoryName = _("WILD BULL"),
        .height = 14,
        .weight = 884,
        .description = gCWrigglePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WRIGGLE] =
    {
        .categoryName = _("FISH"),
        .height = 9,
        .weight = 100,
        .description = gWrigglePokedexText,
        .pokemonScale = 310,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CTEWI] =
    {
        .categoryName = _("ATROCIOUS"),
        .height = 65,
        .weight = 2350,
        .description = gCTewiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 481,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_TEWI] =
    {
        .categoryName = _("TRANSPORT"),
        .height = 25,
        .weight = 2200,
        .description = gTewiPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_KEDAMA] =
    {
        .categoryName = _("TRANSFORM"),
        .height = 3,
        .weight = 40,
        .description = gKedamaPokedexText,
        .pokemonScale = 633,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CNUE] =
    {
        .categoryName = _("EVOLUTION"),
        .height = 3,
        .weight = 65,
        .description = gCNuePokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NUE] =
    {
        .categoryName = _("BUBBLE JET"),
        .height = 10,
        .weight = 290,
        .description = gNuePokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSUWAKO] =
    {
        .categoryName = _("LIGHTNING"),
        .height = 8,
        .weight = 245,
        .description = gCSuwakoPokedexText,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUWAKO] =
    {
        .categoryName = _("FLAME"),
        .height = 9,
        .weight = 250,
        .description = gSuwakoPokedexText,
        .pokemonScale = 306,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REISENII] =
    {
        .categoryName = _("VIRTUAL"),
        .height = 8,
        .weight = 365,
        .description = gReisenIIPokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMARISA] =
    {
        .categoryName = _("SPIRAL"),
        .height = 4,
        .weight = 75,
        .description = gCMarisaPokedexText,
        .pokemonScale = 521,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARISA] =
    {
        .categoryName = _("SPIRAL"),
        .height = 10,
        .weight = 350,
        .description = gMarisaPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CREIMU] =
    {
        .categoryName = _("SHELLFISH"),
        .height = 5,
        .weight = 115,
        .description = gCReimuPokedexText,
        .pokemonScale = 454,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REIMU] =
    {
        .categoryName = _("SHELLFISH"),
        .height = 13,
        .weight = 405,
        .description = gReimuPokedexText,
        .pokemonScale = 271,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CBYAKUREN] =
    {
        .categoryName = _("FOSSIL"),
        .height = 18,
        .weight = 590,
        .description = gCByakurenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 302,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_BYAKUREN] =
    {
        .categoryName = _("SLEEPING"),
        .height = 21,
        .weight = 4600,
        .description = gByakurenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 423,
        .trainerOffset = 11,
    },

    [NATIONAL_DEX_KONNGARA] =
    {
        .categoryName = _("FREEZE"),
        .height = 17,
        .weight = 554,
        .description = gKonngaraPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_KIKURI] =
    {
        .categoryName = _("ELECTRIC"),
        .height = 16,
        .weight = 526,
        .description = gKikuriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 318,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_YUUGENMAGAN] =
    {
        .categoryName = _("FLAME"),
        .height = 20,
        .weight = 600,
        .description = gYuugenMaganPokedexText,
        .pokemonScale = 270,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_CTOYOHIME] =
    {
        .categoryName = _("DRAGON"),
        .height = 18,
        .weight = 33,
        .description = gCToyohimePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 8,
        .trainerScale = 386,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_TOYOHIME] =
    {
        .categoryName = _("DRAGON"),
        .height = 40,
        .weight = 165,
        .description = gToyohimePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_GOLIATH] =
    {
        .categoryName = _("DRAGON"),
        .height = 22,
        .weight = 2100,
        .description = gGoliathPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_SARIEL] =
    {
        .categoryName = _("GENETIC"),
        .height = 20,
        .weight = 1220,
        .description = gSarielPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_AKYUU] =
    {
        .categoryName = _("NEW SPECIES"),
        .height = 4,
        .weight = 40,
        .description = gAkyuuPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GENJII] =
    {
        .categoryName = _("LEAF"),
        .height = 9,
        .weight = 64,
        .description = gGenjiiPokedexText,
        .pokemonScale = 512,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TORI] =
    {
        .categoryName = _("LEAF"),
        .height = 12,
        .weight = 158,
        .description = gToriPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NAMAZU] =
    {
        .categoryName = _("HERB"),
        .height = 18,
        .weight = 1005,
        .description = gNamazuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 277,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CELLY] =
    {
        .categoryName = _("FIRE MOUSE"),
        .height = 5,
        .weight = 79,
        .description = gCEllyPokedexText,
        .pokemonScale = 539,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELLY] =
    {
        .categoryName = _("VOLCANO"),
        .height = 9,
        .weight = 190,
        .description = gEllyPokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CORANGE] =
    {
        .categoryName = _("VOLCANO"),
        .height = 17,
        .weight = 795,
        .description = gCOrangePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ORANGE] =
    {
        .categoryName = _("BIG JAW"),
        .height = 6,
        .weight = 95,
        .description = gOrangePokedexText,
        .pokemonScale = 487,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YOUKI] =
    {
        .categoryName = _("BIG JAW"),
        .height = 11,
        .weight = 250,
        .description = gYoukiPokedexText,
        .pokemonScale = 378,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CCHIYURI] =
    {
        .categoryName = _("BIG JAW"),
        .height = 23,
        .weight = 888,
        .description = gCChiyuriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CHIYURI] =
    {
        .categoryName = _("SCOUT"),
        .height = 8,
        .weight = 60,
        .description = gChiyuriPokedexText,
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUMEMI] =
    {
        .categoryName = _("LONG BODY"),
        .height = 18,
        .weight = 325,
        .description = gCYumemiPokedexText,
        .pokemonScale = 346,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUMEMI] =
    {
        .categoryName = _("OWL"),
        .height = 7,
        .weight = 212,
        .description = gYumemiPokedexText,
        .pokemonScale = 380,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CELLEN] =
    {
        .categoryName = _("OWL"),
        .height = 16,
        .weight = 408,
        .description = gCEllenPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELLEN] =
    {
        .categoryName = _("FIVE STAR"),
        .height = 10,
        .weight = 108,
        .description = gEllenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKAZAMI] =
    {
        .categoryName = _("FIVE STAR"),
        .height = 14,
        .weight = 356,
        .description = gCKazamiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KAZAMI] =
    {
        .categoryName = _("STRING SPIT"),
        .height = 5,
        .weight = 85,
        .description = gKazamiPokedexText,
        .pokemonScale = 414,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMEIRA] =
    {
        .categoryName = _("LONG LEG"),
        .height = 11,
        .weight = 335,
        .description = gCMeiraPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEIRA] =
    {
        .categoryName = _("BAT"),
        .height = 18,
        .weight = 750,
        .description = gMeiraPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 281,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CSARA] =
    {
        .categoryName = _("ANGLER"),
        .height = 5,
        .weight = 120,
        .description = gCSaraPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SARA] =
    {
        .categoryName = _("LIGHT"),
        .height = 12,
        .weight = 225,
        .description = gSaraPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLUIZE] =
    {
        .categoryName = _("TINY MOUSE"),
        .height = 3,
        .weight = 20,
        .description = gCLuizePokedexText,
        .pokemonScale = 508,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUIZE] =
    {
        .categoryName = _("STAR SHAPE"),
        .height = 3,
        .weight = 30,
        .description = gLuizePokedexText,
        .pokemonScale = 462,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMARGATROID] =
    {
        .categoryName = _("BALLOON"),
        .height = 3,
        .weight = 10,
        .description = gCMargatroidPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARGATROID] =
    {
        .categoryName = _("SPIKE BALL"),
        .height = 3,
        .weight = 15,
        .description = gMargatroidPokedexText,
        .pokemonScale = 507,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKANA] =
    {
        .categoryName = _("HAPPINESS"),
        .height = 6,
        .weight = 32,
        .description = gCKanaPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KANA] =
    {
        .categoryName = _("TINY BIRD"),
        .height = 2,
        .weight = 20,
        .description = gKanaPokedexText,
        .pokemonScale = 610,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHAKUREI] =
    {
        .categoryName = _("MYSTIC"),
        .height = 15,
        .weight = 150,
        .description = gCHakureiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 318,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_HAKUREI] =
    {
        .categoryName = _("WOOL"),
        .height = 6,
        .weight = 78,
        .description = gHakureiPokedexText,
        .pokemonScale = 379,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKIRISAME] =
    {
        .categoryName = _("WOOL"),
        .height = 8,
        .weight = 133,
        .description = gCKirisamePokedexText,
        .pokemonScale = 372,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KIRISAME] =
    {
        .categoryName = _("LIGHT"),
        .height = 14,
        .weight = 615,
        .description = gKirisamePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKOTOHIME] =
    {
        .categoryName = _("FLOWER"),
        .height = 4,
        .weight = 58,
        .description = gCKotohimePokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOTOHIME] =
    {
        .categoryName = _("AQUA MOUSE"),
        .height = 4,
        .weight = 85,
        .description = gKotohimePokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUMEKO] =
    {
        .categoryName = _("AQUA RABBIT"),
        .height = 8,
        .weight = 285,
        .description = gCYumekoPokedexText,
        .pokemonScale = 448,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUMEKO] =
    {
        .categoryName = _("IMITATION"),
        .height = 12,
        .weight = 380,
        .description = gYumekoPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSHINKI] =
    {
        .categoryName = _("FROG"),
        .height = 11,
        .weight = 339,
        .description = gCShinkiPokedexText,
        .pokemonScale = 289,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHINKI] =
    {
        .categoryName = _("COTTONWEED"),
        .height = 4,
        .weight = 5,
        .description = gShinkiPokedexText,
        .pokemonScale = 562,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MIMICHAN] =
    {
        .categoryName = _("COTTONWEED"),
        .height = 6,
        .weight = 10,
        .description = gMimichanPokedexText,
        .pokemonScale = 387,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RUUKOTO] =
    {
        .categoryName = _("COTTONWEED"),
        .height = 8,
        .weight = 30,
        .description = gRuukotoPokedexText,
        .pokemonScale = 418,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRIKA] =
    {
        .categoryName = _("LONG TAIL"),
        .height = 8,
        .weight = 115,
        .description = gCRikaPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RIKA] =
    {
        .categoryName = _("SEED"),
        .height = 3,
        .weight = 18,
        .description = gRikaPokedexText,
        .pokemonScale = 541,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMUGETSU] =
    {
        .categoryName = _("SUN"),
        .height = 8,
        .weight = 85,
        .description = gCMugetsuPokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MUGETSU] =
    {
        .categoryName = _("CLEAR WING"),
        .height = 12,
        .weight = 380,
        .description = gMugetsuPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CGENGETSU] =
    {
        .categoryName = _("WATER FISH"),
        .height = 4,
        .weight = 85,
        .description = gCGengetsuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GENGETSU] =
    {
        .categoryName = _("WATER FISH"),
        .height = 14,
        .weight = 750,
        .description = gGengetsuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKURUMI] =
    {
        .categoryName = _("SUN"),
        .height = 9,
        .weight = 265,
        .description = gCKurumiPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KURUMI] =
    {
        .categoryName = _("MOONLIGHT"),
        .height = 10,
        .weight = 270,
        .description = gKurumiPokedexText,
        .pokemonScale = 317,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRIKAKO] =
    {
        .categoryName = _("DARKNESS"),
        .height = 5,
        .weight = 21,
        .description = gCRikakoPokedexText,
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_RIKAKO] =
    {
        .categoryName = _("ROYAL"),
        .height = 20,
        .weight = 795,
        .description = gRikakoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_CYUKI] =
    {
        .categoryName = _("SCREECH"),
        .height = 7,
        .weight = 10,
        .description = gCYukiPokedexText,
        .pokemonScale = 407,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UNOWN] =
    {
        .categoryName = _("SYMBOL"),
        .height = 5,
        .weight = 50,
        .description = gUnownPokedexText,
        .pokemonScale = 411,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMAI] =
    {
        .categoryName = _("PATIENT"),
        .height = 13,
        .weight = 285,
        .description = gCMaiPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAI] =
    {
        .categoryName = _("LONG NECK"),
        .height = 15,
        .weight = 415,
        .description = gMaiPokedexText,
        .pokemonScale = 281,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DSUNNYMILK] =
    {
        .categoryName = _("BAGWORM"),
        .height = 6,
        .weight = 72,
        .description = gDSunnyMilkPokedexText,
        .pokemonScale = 445,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TLUNACHILD] =
    {
        .categoryName = _("BAGWORM"),
        .height = 12,
        .weight = 1258,
        .description = gTLunaChildPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HSTARSAPPHIRE] =
    {
        .categoryName = _("LAND SNAKE"),
        .height = 15,
        .weight = 140,
        .description = gHStarSapphirePokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ANITORI] =
    {
        .categoryName = _("FLYSCORPION"),
        .height = 11,
        .weight = 648,
        .description = gANitoriPokedexText,
        .pokemonScale = 350,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TNITORI] =
    {
        .categoryName = _("IRON SNAKE"),
        .height = 92,
        .weight = 4000,
        .description = gTNitoriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_AMOKOU] =
    {
        .categoryName = _("FAIRY"),
        .height = 6,
        .weight = 78,
        .description = gAMokouPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DMOKOU] =
    {
        .categoryName = _("FAIRY"),
        .height = 14,
        .weight = 487,
        .description = gDMokouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DREISEN] =
    {
        .categoryName = _("BALLOON"),
        .height = 5,
        .weight = 39,
        .description = gDReisenPokedexText,
        .pokemonScale = 430,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TREISEN] =
    {
        .categoryName = _("PINCER"),
        .height = 18,
        .weight = 1180,
        .description = gTReisenPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TSAKUYA] =
    {
        .categoryName = _("MOLD"),
        .height = 6,
        .weight = 205,
        .description = gTSakuyaPokedexText,
        .pokemonScale = 485,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HSAKUYA] =
    {
        .categoryName = _("SINGLE HORN"),
        .height = 15,
        .weight = 540,
        .description = gHSakuyaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARUMIA] =
    {
        .categoryName = _("SHARP CLAW"),
        .height = 9,
        .weight = 280,
        .description = gARumiaPokedexText,
        .pokemonScale = 413,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SRUMIA] =
    {
        .categoryName = _("LITTLE BEAR"),
        .height = 6,
        .weight = 88,
        .description = gSRumiaPokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HMYSTIA] =
    {
        .categoryName = _("HIBERNATOR"),
        .height = 18,
        .weight = 1258,
        .description = gHMystiaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMYSTIA] =
    {
        .categoryName = _("LAVA"),
        .height = 7,
        .weight = 350,
        .description = gAMystiaPokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ACHEN] =
    {
        .categoryName = _("LAVA"),
        .height = 8,
        .weight = 550,
        .description = gAChenPokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TCHEN] =
    {
        .categoryName = _("PIG"),
        .height = 4,
        .weight = 65,
        .description = gTChenPokedexText,
        .pokemonScale = 324,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DYOUMU] =
    {
        .categoryName = _("SWINE"),
        .height = 11,
        .weight = 558,
        .description = gDYoumuPokedexText,
        .pokemonScale = 306,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SYOUMU] =
    {
        .categoryName = _("CORAL"),
        .height = 6,
        .weight = 50,
        .description = gSYoumuPokedexText,
        .pokemonScale = 410,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AYUUKA] =
    {
        .categoryName = _("JET"),
        .height = 6,
        .weight = 120,
        .description = gAYuukaPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYUUKA] =
    {
        .categoryName = _("JET"),
        .height = 9,
        .weight = 285,
        .description = gTYuukaPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SAYA] =
    {
        .categoryName = _("DELIVERY"),
        .height = 9,
        .weight = 160,
        .description = gSAyaPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TAYA] =
    {
        .categoryName = _("KITE"),
        .height = 21,
        .weight = 2200,
        .description = gTAyaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_ATENSHI] =
    {
        .categoryName = _("ARMOR BIRD"),
        .height = 17,
        .weight = 505,
        .description = gATenshiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 271,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_DTENSHI] =
    {
        .categoryName = _("DARK"),
        .height = 6,
        .weight = 108,
        .description = gDTenshiPokedexText,
        .pokemonScale = 393,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DPARSEE] =
    {
        .categoryName = _("DARK"),
        .height = 14,
        .weight = 350,
        .description = gDParseePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TPARSEE] =
    {
        .categoryName = _("DRAGON"),
        .height = 18,
        .weight = 1520,
        .description = gTParseePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 287,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKOISHI] =
    {
        .categoryName = _("LONG NOSE"),
        .height = 5,
        .weight = 335,
        .description = gAKoishiPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SKOISHI] =
    {
        .categoryName = _("ARMOR"),
        .height = 11,
        .weight = 1200,
        .description = gSKoishiPokedexText,
        .pokemonScale = 313,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DBYAKUREN] =
    {
        .categoryName = _("VIRTUAL"),
        .height = 6,
        .weight = 325,
        .description = gDByakurenPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TBYAKUREN] =
    {
        .categoryName = _("BIG HORN"),
        .height = 14,
        .weight = 712,
        .description = gTByakurenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DICHIRIN] =
    {
        .categoryName = _("PAINTER"),
        .height = 12,
        .weight = 580,
        .description = gDIchirinPokedexText,
        .pokemonScale = 287,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TICHIRIN] =
    {
        .categoryName = _("SCUFFLE"),
        .height = 7,
        .weight = 210,
        .description = gTIchirinPokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKANAKO] =
    {
        .categoryName = _("HANDSTAND"),
        .height = 14,
        .weight = 480,
        .description = gAKanakoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DKANAKO] =
    {
        .categoryName = _("KISS"),
        .height = 4,
        .weight = 60,
        .description = gDKanakoPokedexText,
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKAGUYA] =
    {
        .categoryName = _("ELECTRIC"),
        .height = 6,
        .weight = 235,
        .description = gAKaguyaPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DKAGUYA] =
    {
        .categoryName = _("LIVE COAL"),
        .height = 7,
        .weight = 214,
        .description = gDKaguyaPokedexText,
        .pokemonScale = 284,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHINGYOKUO] =
    {
        .categoryName = _("MILK COW"),
        .height = 12,
        .weight = 755,
        .description = gShinGyokuOPokedexText,
        .pokemonScale = 280,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHINGYOKUM] =
    {
        .categoryName = _("HAPPINESS"),
        .height = 15,
        .weight = 468,
        .description = gShinGyokuMPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 310,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_SHINGYOKUF] =
    {
        .categoryName = _("THUNDER"),
        .height = 19,
        .weight = 1780,
        .description = gShinGyokuFPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_AUTSUHO] =
    {
        .categoryName = _("VOLCANO"),
        .height = 21,
        .weight = 1980,
        .description = gAUtsuhoPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SUTSUHO] =
    {
        .categoryName = _("AURORA"),
        .height = 20,
        .weight = 1870,
        .description = gSUtsuhoPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_DMOMIJI] =
    {
        .categoryName = _("ROCK SKIN"),
        .height = 6,
        .weight = 720,
        .description = gDMomijiPokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELIS] =
    {
        .categoryName = _("HARD SHELL"),
        .height = 12,
        .weight = 1520,
        .description = gElisPokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MIMA] =
    {
        .categoryName = _("ARMOR"),
        .height = 20,
        .weight = 2020,
        .description = gMimaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SKOMACHI] =
    {
        .categoryName = _("DIVING"),
        .height = 52,
        .weight = 2160,
        .description = gSKomachiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_AKOMACHI] =
    {
        .categoryName = _("RAINBOW"),
        .height = 38,
        .weight = 1990,
        .description = gAKomachiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
    },

    [NATIONAL_DEX_AEIRIN] =
    {
        .categoryName = _("TIME TRAVEL"),
        .height = 6,
        .weight = 50,
        .description = gAEirinPokedexText,
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HEIRIN] =
    {
        .categoryName = _("WOOD GECKO"),
        .height = 5,
        .weight = 50,
        .description = gHEirinPokedexText,
        .pokemonScale = 541,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DYUKARI] =
    {
        .categoryName = _("WOOD GECKO"),
        .height = 9,
        .weight = 216,
        .description = gDYukariPokedexText,
        .pokemonScale = 360,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYUKARI] =
    {
        .categoryName = _("FOREST"),
        .height = 17,
        .weight = 522,
        .description = gTYukariPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 275,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_AALICE] =
    {
        .categoryName = _("CHICK"),
        .height = 4,
        .weight = 25,
        .description = gAAlicePokedexText,
        .pokemonScale = 566,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TALICE] =
    {
        .categoryName = _("YOUNG FOWL"),
        .height = 9,
        .weight = 195,
        .description = gTAlicePokedexText,
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AREIMU] =
    {
        .categoryName = _("BLAZE"),
        .height = 19,
        .weight = 520,
        .description = gAReimuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_DREIMU] =
    {
        .categoryName = _("MUD FISH"),
        .height = 4,
        .weight = 76,
        .description = gDReimuPokedexText,
        .pokemonScale = 535,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCIRNO] =
    {
        .categoryName = _("MUD FISH"),
        .height = 7,
        .weight = 280,
        .description = gSCirnoPokedexText,
        .pokemonScale = 340,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TCIRNO] =
    {
        .categoryName = _("MUD FISH"),
        .height = 15,
        .weight = 819,
        .description = gTCirnoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DYUYUKO] =
    {
        .categoryName = _("BITE"),
        .height = 5,
        .weight = 136,
        .description = gDYuyukoPokedexText,
        .pokemonScale = 481,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AYUYUKO] =
    {
        .categoryName = _("BITE"),
        .height = 10,
        .weight = 370,
        .description = gAYuyukoPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HLUNASA] =
    {
        .categoryName = _("TINYRACCOON"),
        .height = 4,
        .weight = 175,
        .description = gHLunasaPokedexText,
        .pokemonScale = 560,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HMERLIN] =
    {
        .categoryName = _("RUSHING"),
        .height = 5,
        .weight = 325,
        .description = gHMerlinPokedexText,
        .pokemonScale = 321,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HLYRICA] =
    {
        .categoryName = _("WORM"),
        .height = 3,
        .weight = 36,
        .description = gHLyricaPokedexText,
        .pokemonScale = 711,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARAN] =
    {
        .categoryName = _("COCOON"),
        .height = 6,
        .weight = 100,
        .description = gARanPokedexText,
        .pokemonScale = 431,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HRAN] =
    {
        .categoryName = _("BUTTERFLY"),
        .height = 10,
        .weight = 284,
        .description = gHRanPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMEDICINE] =
    {
        .categoryName = _("COCOON"),
        .height = 7,
        .weight = 115,
        .description = gAMedicinePokedexText,
        .pokemonScale = 391,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TMEDICINE] =
    {
        .categoryName = _("POISON MOTH"),
        .height = 12,
        .weight = 316,
        .description = gTMedicinePokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AHINA] =
    {
        .categoryName = _("WATER WEED"),
        .height = 5,
        .weight = 26,
        .description = gAHinaPokedexText,
        .pokemonScale = 406,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DHINA] =
    {
        .categoryName = _("JOLLY"),
        .height = 12,
        .weight = 325,
        .description = gDHinaPokedexText,
        .pokemonScale = 277,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SSHIZUHA] =
    {
        .categoryName = _("CAREFREE"),
        .height = 15,
        .weight = 550,
        .description = gSShizuhaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_SRIN] =
    {
        .categoryName = _("ACORN"),
        .height = 5,
        .weight = 40,
        .description = gSRinPokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARIN] =
    {
        .categoryName = _("WILY"),
        .height = 10,
        .weight = 280,
        .description = gARinPokedexText,
        .pokemonScale = 299,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZOMBIEFAIRY] =
    {
        .categoryName = _("WICKED"),
        .height = 13,
        .weight = 596,
        .description = gZombieFairyPokedexText,
        .pokemonScale = 290,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TSHOU] =
    {
        .categoryName = _("TINYSWALLOW"),
        .height = 3,
        .weight = 23,
        .description = gTShouPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ATOKIKO] =
    {
        .categoryName = _("SWALLOW"),
        .height = 7,
        .weight = 198,
        .description = gATokikoPokedexText,
        .pokemonScale = 428,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TKOGASA] =
    {
        .categoryName = _("SEAGULL"),
        .height = 6,
        .weight = 95,
        .description = gTKogasaPokedexText,
        .pokemonScale = 295,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DREMILIA] =
    {
        .categoryName = _("WATER BIRD"),
        .height = 12,
        .weight = 280,
        .description = gDRemiliaPokedexText,
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TENMA] =
    {
        .categoryName = _("FEELING"),
        .height = 4,
        .weight = 66,
        .description = gTenmaPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SENDAI] =
    {
        .categoryName = _("EMOTION"),
        .height = 8,
        .weight = 202,
        .description = gSendaiPokedexText,
        .pokemonScale = 354,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKYOUKO] =
    {
        .categoryName = _("EMBRACE"),
        .height = 16,
        .weight = 484,
        .description = gCKyoukoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SFLANDRE] =
    {
        .categoryName = _("POND SKATER"),
        .height = 5,
        .weight = 17,
        .description = gSFlandrePokedexText,
        .pokemonScale = 375,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DWRIGGLE] =
    {
        .categoryName = _("EYEBALL"),
        .height = 8,
        .weight = 36,
        .description = gDWrigglePokedexText,
        .pokemonScale = 378,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DSUWAKO] =
    {
        .categoryName = _("MUSHROOM"),
        .height = 4,
        .weight = 45,
        .description = gDSuwakoPokedexText,
        .pokemonScale = 513,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SYAMAME] =
    {
        .categoryName = _("MUSHROOM"),
        .height = 12,
        .weight = 392,
        .description = gSYamamePokedexText,
        .pokemonScale = 324,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SSARIEL] =
    {
        .categoryName = _("SLACKER"),
        .height = 8,
        .weight = 240,
        .description = gSSarielPokedexText,
        .pokemonScale = 291,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALILYWHITE] =
    {
        .categoryName = _("WILD MONKEY"),
        .height = 14,
        .weight = 465,
        .description = gALilyWhitePokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CMIMA] =
    {
        .categoryName = _("LAZY"),
        .height = 20,
        .weight = 1305,
        .description = gCMimaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 300,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_HSHIZUHA] =
    {
        .categoryName = _("TRAINEE"),
        .height = 5,
        .weight = 55,
        .description = gHShizuhaPokedexText,
        .pokemonScale = 405,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASUWAKO] =
    {
        .categoryName = _("NINJA"),
        .height = 8,
        .weight = 120,
        .description = gASuwakoPokedexText,
        .pokemonScale = 383,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASHOU] =
    {
        .categoryName = _("SHED"),
        .height = 8,
        .weight = 12,
        .description = gAShouPokedexText,
        .pokemonScale = 372,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMARISA] =
    {
        .categoryName = _("WHISPER"),
        .height = 6,
        .weight = 163,
        .description = gSMarisaPokedexText,
        .pokemonScale = 373,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMARISA] =
    {
        .categoryName = _("BIG VOICE"),
        .height = 10,
        .weight = 405,
        .description = gAMarisaPokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DMURASA] =
    {
        .categoryName = _("LOUD NOISE"),
        .height = 15,
        .weight = 840,
        .description = gDMurasaPokedexText,
        .pokemonScale = 284,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AFLANDRE] =
    {
        .categoryName = _("GUTS"),
        .height = 10,
        .weight = 864,
        .description = gAFlandrePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADAIYOUSEI] =
    {
        .categoryName = _("ARM THRUST"),
        .height = 23,
        .weight = 2538,
        .description = gADaiyouseiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 343,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CSHINGYOKU] =
    {
        .categoryName = _("POLKA DOT"),
        .height = 2,
        .weight = 20,
        .description = gCShinGyokuPokedexText,
        .pokemonScale = 603,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CELIS] =
    {
        .categoryName = _("COMPASS"),
        .height = 10,
        .weight = 970,
        .description = gCElisPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 9,
        .trainerScale = 289,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_ASUNNYMILK] =
    {
        .categoryName = _("KITTEN"),
        .height = 6,
        .weight = 110,
        .description = gASunnyMilkPokedexText,
        .pokemonScale = 492,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALUNACHILD] =
    {
        .categoryName = _("PRIM"),
        .height = 11,
        .weight = 326,
        .description = gALunaChildPokedexText,
        .pokemonScale = 322,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADMYSTIA] =
    {
        .categoryName = _("DARKNESS"),
        .height = 5,
        .weight = 110,
        .description = gAdMystiaPokedexText,
        .pokemonScale = 451,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TKISUME] =
    {
        .categoryName = _("DECEIVER"),
        .height = 6,
        .weight = 115,
        .description = gTKisumePokedexText,
        .pokemonScale = 466,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADTEWI] =
    {
        .categoryName = _("IRON ARMOR"),
        .height = 4,
        .weight = 600,
        .description = gAdTewiPokedexText,
        .pokemonScale = 419,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADMARISA] =
    {
        .categoryName = _("IRON ARMOR"),
        .height = 9,
        .weight = 1200,
        .description = gAdMarisaPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADALICE] =
    {
        .categoryName = _("IRON ARMOR"),
        .height = 21,
        .weight = 3600,
        .description = gAdAlicePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 350,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_AYUUGI] =
    {
        .categoryName = _("MEDITATE"),
        .height = 6,
        .weight = 112,
        .description = gAYuugiPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HKEINE] =
    {
        .categoryName = _("MEDITATE"),
        .height = 13,
        .weight = 315,
        .description = gHKeinePokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASHIKIEIKI] =
    {
        .categoryName = _("LIGHTNING"),
        .height = 6,
        .weight = 152,
        .description = gAShikieikiPokedexText,
        .pokemonScale = 290,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TTOYOHIME] =
    {
        .categoryName = _("DISCHARGE"),
        .height = 15,
        .weight = 402,
        .description = gTToyohimePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TNAZRIN] =
    {
        .categoryName = _("CHEERING"),
        .height = 4,
        .weight = 42,
        .description = gTNazrinPokedexText,
        .pokemonScale = 515,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HNAZRIN] =
    {
        .categoryName = _("CHEERING"),
        .height = 4,
        .weight = 42,
        .description = gHNazrinPokedexText,
        .pokemonScale = 512,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YUKI] =
    {
        .categoryName = _("FIREFLY"),
        .height = 7,
        .weight = 177,
        .description = gYukiPokedexText,
        .pokemonScale = 442,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADMOKOU] =
    {
        .categoryName = _("FIREFLY"),
        .height = 6,
        .weight = 177,
        .description = gAdMokouPokedexText,
        .pokemonScale = 572,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADREISEN] =
    {
        .categoryName = _("THORN"),
        .height = 3,
        .weight = 20,
        .description = gAdReisenPokedexText,
        .pokemonScale = 677,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKIKURI] =
    {
        .categoryName = _("STOMACH"),
        .height = 4,
        .weight = 103,
        .description = gCKikuriPokedexText,
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADMEILING] =
    {
        .categoryName = _("POISON BAG"),
        .height = 17,
        .weight = 800,
        .description = gAdMeilingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_ATEWI] =
    {
        .categoryName = _("SAVAGE"),
        .height = 8,
        .weight = 208,
        .description = gATewiPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DSHIKIEIKI] =
    {
        .categoryName = _("BRUTAL"),
        .height = 18,
        .weight = 888,
        .description = gDShikieikiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_DMEILING] =
    {
        .categoryName = _("BALL WHALE"),
        .height = 20,
        .weight = 1300,
        .description = gDMeilingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 493,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TENSOKU] =
    {
        .categoryName = _("FLOAT WHALE"),
        .height = 145,
        .weight = 3980,
        .description = gTensokuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 1352,
        .trainerOffset = 18,
    },

    [NATIONAL_DEX_CKONNGARA] =
    {
        .categoryName = _("NUMB"),
        .height = 7,
        .weight = 240,
        .description = gCKonngaraPokedexText,
        .pokemonScale = 342,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYUUGENMAGAN] =
    {
        .categoryName = _("ERUPTION"),
        .height = 19,
        .weight = 2200,
        .description = gCYuugenMaganPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 7,
        .trainerScale = 345,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_CSARIEL] =
    {
        .categoryName = _("COAL"),
        .height = 5,
        .weight = 804,
        .description = gCSarielPokedexText,
        .pokemonScale = 390,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALILYBLACK] =
    {
        .categoryName = _("BOUNCE"),
        .height = 7,
        .weight = 306,
        .description = gALilyBlackPokedexText,
        .pokemonScale = 423,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DYUUGI] =
    {
        .categoryName = _("MANIPULATE"),
        .height = 9,
        .weight = 715,
        .description = gDYuugiPokedexText,
        .pokemonScale = 358,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SKOGASA] =
    {
        .categoryName = _("SPOT PANDA"),
        .height = 11,
        .weight = 50,
        .description = gSKogasaPokedexText,
        .pokemonScale = 321,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DMINORIKO] =
    {
        .categoryName = _("ANT PIT"),
        .height = 7,
        .weight = 150,
        .description = gDMinorikoPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TSUIKA] =
    {
        .categoryName = _("VIBRATION"),
        .height = 11,
        .weight = 153,
        .description = gTSuikaPokedexText,
        .pokemonScale = 370,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASANAE] =
    {
        .categoryName = _("MYSTIC"),
        .height = 20,
        .weight = 820,
        .description = gASanaePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ANUE] =
    {
        .categoryName = _("CACTUS"),
        .height = 4,
        .weight = 513,
        .description = gANuePokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TNUE] =
    {
        .categoryName = _("SCARECROW"),
        .height = 13,
        .weight = 774,
        .description = gTNuePokedexText,
        .pokemonScale = 327,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DIKU] =
    {
        .categoryName = _("COTTON BIRD"),
        .height = 4,
        .weight = 12,
        .description = gDIkuPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TIKU] =
    {
        .categoryName = _("HUMMING"),
        .height = 11,
        .weight = 206,
        .description = gTIkuPokedexText,
        .pokemonScale = 327,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DSATORI] =
    {
        .categoryName = _("CAT FERRET"),
        .height = 13,
        .weight = 403,
        .description = gDSatoriPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TSATORI] =
    {
        .categoryName = _("FANG SNAKE"),
        .height = 27,
        .weight = 525,
        .description = gTSatoriPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HLETTY] =
    {
        .categoryName = _("METEORITE"),
        .height = 10,
        .weight = 1680,
        .description = gHLettyPokedexText,
        .pokemonScale = 300,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SYORIHIME] =
    {
        .categoryName = _("METEORITE"),
        .height = 12,
        .weight = 1540,
        .description = gSYorihimePokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_THATATE] =
    {
        .categoryName = _("WHISKERS"),
        .height = 4,
        .weight = 19,
        .description = gTHatatePokedexText,
        .pokemonScale = 581,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DHATATE] =
    {
        .categoryName = _("WHISKERS"),
        .height = 9,
        .weight = 236,
        .description = gDHatatePokedexText,
        .pokemonScale = 317,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DLAYLA] =
    {
        .categoryName = _("RUFFIAN"),
        .height = 6,
        .weight = 115,
        .description = gDLaylaPokedexText,
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DKEINE] =
    {
        .categoryName = _("ROGUE"),
        .height = 11,
        .weight = 328,
        .description = gDKeinePokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HKOAKUMA] =
    {
        .categoryName = _("CLAY DOLL"),
        .height = 5,
        .weight = 215,
        .description = gHKoakumaPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMEILING] =
    {
        .categoryName = _("CLAY DOLL"),
        .height = 15,
        .weight = 1080,
        .description = gSMeilingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 280,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ADYUKARI] =
    {
        .categoryName = _("SEA LILY"),
        .height = 10,
        .weight = 238,
        .description = gAdYukariPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADRAN] =
    {
        .categoryName = _("BARNACLE"),
        .height = 15,
        .weight = 604,
        .description = gAdRanPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADCHEN] =
    {
        .categoryName = _("OLD SHRIMP"),
        .height = 7,
        .weight = 125,
        .description = gAdChenPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DARKALICE] =
    {
        .categoryName = _("PLATE"),
        .height = 15,
        .weight = 682,
        .description = gDarkAlicePokedexText,
        .pokemonScale = 312,
        .pokemonOffset = 3,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AREMILIA] =
    {
        .categoryName = _("FISH"),
        .height = 6,
        .weight = 74,
        .description = gARemiliaPokedexText,
        .pokemonScale = 423,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DTEWI] =
    {
        .categoryName = _("TENDER"),
        .height = 62,
        .weight = 1620,
        .description = gDTewiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_TSANAE] =
    {
        .categoryName = _("WEATHER"),
        .height = 3,
        .weight = 8,
        .description = gTSanaePokedexText,
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWRIGGLE] =
    {
        .categoryName = _("COLOR SWAP"),
        .height = 10,
        .weight = 220,
        .description = gSWrigglePokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DDAIYOUSEI] =
    {
        .categoryName = _("PUPPET"),
        .height = 6,
        .weight = 23,
        .description = gDDaiyouseiPokedexText,
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYAMAME] =
    {
        .categoryName = _("MARIONETTE"),
        .height = 11,
        .weight = 125,
        .description = gTYamamePokedexText,
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RINNOSUKE] =
    {
        .categoryName = _("REQUIEM"),
        .height = 8,
        .weight = 150,
        .description = gRinnosukePokedexText,
        .pokemonScale = 406,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADCIRNO] =
    {
        .categoryName = _("BECKON"),
        .height = 16,
        .weight = 306,
        .description = gAdCirnoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 299,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_APATCHOULI] =
    {
        .categoryName = _("FRUIT"),
        .height = 20,
        .weight = 1000,
        .description = gAPatchouliPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 344,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CWAKASAGI] =
    {
        .categoryName = _("WIND CHIME"),
        .height = 6,
        .weight = 10,
        .description = gCWakasagiPokedexText,
        .pokemonScale = 505,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMEDICINE] =
    {
        .categoryName = _("DISASTER"),
        .height = 12,
        .weight = 470,
        .description = gSMedicinePokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMINORIKO] =
    {
        .categoryName = _("BRIGHT"),
        .height = 6,
        .weight = 140,
        .description = gAMinorikoPokedexText,
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DPATCHOULI] =
    {
        .categoryName = _("SNOW HAT"),
        .height = 7,
        .weight = 168,
        .description = gDPatchouliPokedexText,
        .pokemonScale = 380,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DLETTY] =
    {
        .categoryName = _("FACE"),
        .height = 15,
        .weight = 2565,
        .description = gDLettyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 344,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASUIKA] =
    {
        .categoryName = _("CLAP"),
        .height = 8,
        .weight = 395,
        .description = gASuikaPokedexText,
        .pokemonScale = 315,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HLILYWHITE] =
    {
        .categoryName = _("BALL ROLL"),
        .height = 11,
        .weight = 876,
        .description = gHLilyWhitePokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLILYBLACK] =
    {
        .categoryName = _("ICE BREAK"),
        .height = 14,
        .weight = 1506,
        .description = gSLilyBlackPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMURASA] =
    {
        .categoryName = _("BIVALVE"),
        .height = 4,
        .weight = 525,
        .description = gAMurasaPokedexText,
        .pokemonScale = 691,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ASTARSAPPHIRE] =
    {
        .categoryName = _("DEEP SEA"),
        .height = 17,
        .weight = 270,
        .description = gAStarSapphirePokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKAZAMI] =
    {
        .categoryName = _("SOUTH SEA"),
        .height = 18,
        .weight = 226,
        .description = gAKazamiPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ADLETTY] =
    {
        .categoryName = _("LONGEVITY"),
        .height = 10,
        .weight = 234,
        .description = gAdLettyPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AKISISTERS] =
    {
        .categoryName = _("RENDEZVOUS"),
        .height = 6,
        .weight = 87,
        .description = gAkiSistersPokedexText,
        .pokemonScale = 371,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KYOUKO] =
    {
        .categoryName = _("ROCK HEAD"),
        .height = 6,
        .weight = 421,
        .description = gKyoukoPokedexText,
        .pokemonScale = 448,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CYOSHIKA] =
    {
        .categoryName = _("ENDURANCE"),
        .height = 11,
        .weight = 1105,
        .description = gCYoshikaPokedexText,
        .pokemonScale = 311,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YOSHIKA] =
    {
        .categoryName = _("DRAGON"),
        .height = 15,
        .weight = 1026,
        .description = gYoshikaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CSEIGA] =
    {
        .categoryName = _("IRON BALL"),
        .height = 6,
        .weight = 952,
        .description = gCSeigaPokedexText,
        .pokemonScale = 414,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEIGA] =
    {
        .categoryName = _("IRON CLAW"),
        .height = 12,
        .weight = 2025,
        .description = gSeigaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CTOJIKO] =
    {
        .categoryName = _("IRON LEG"),
        .height = 16,
        .weight = 5500,
        .description = gCTojikoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 447,
        .trainerOffset = 9,
    },

    [NATIONAL_DEX_TOJIKO] =
    {
        .categoryName = _("ROCK PEAK"),
        .height = 17,
        .weight = 2300,
        .description = gTojikoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 309,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CFUTO] =
    {
        .categoryName = _("ICEBERG"),
        .height = 18,
        .weight = 1750,
        .description = gCFutoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_FUTO] =
    {
        .categoryName = _("IRON"),
        .height = 19,
        .weight = 2050,
        .description = gFutoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_MAMIZOU] =
    {
        .categoryName = _("EON"),
        .height = 14,
        .weight = 400,
        .description = gMamizouPokedexText,
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CKASEN] =
    {
        .categoryName = _("EON"),
        .height = 20,
        .weight = 600,
        .description = gCKasenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 294,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CMIKO] =
    {
        .categoryName = _("SEA BASIN"),
        .height = 45,
        .weight = 3520,
        .description = gCMikoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_MIKO] =
    {
        .categoryName = _("CONTINENT"),
        .height = 35,
        .weight = 9500,
        .description = gMikoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
    },

    [NATIONAL_DEX_CMAMIZOU] =
    {
        .categoryName = _("SKY HIGH"),
        .height = 70,
        .weight = 2065,
        .description = gCMamizouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
    },

    [NATIONAL_DEX_KASEN] =
    {
        .categoryName = _("WISH"),
        .height = 3,
        .weight = 11,
        .description = gKasenPokedexText,
        .pokemonScale = 608,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOMASEKI] =
    {
        .categoryName = _("DNA"),
        .height = 17,
        .weight = 608,
        .description = gGomasekiPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },
};
