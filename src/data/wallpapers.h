enum {
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
    WALLPAPER_COUNT
};
#define MAX_DEFAULT_WALLPAPER WALLPAPER_SAVANNA

static const u16 sWallpaperPalettes_Forest[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/forest/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/forest/bg.gbapal"),
};
static const u32 sWallpaperTiles_Forest[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/forest/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Forest[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/forest/tilemap.bin.lz");

static const u16 sWallpaperPalettes_City[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/city/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/city/bg.gbapal"),
};
static const u32 sWallpaperTiles_City[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/city/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_City[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/city/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Desert[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/desert/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/desert/bg.gbapal"),
};
static const u32 sWallpaperTiles_Desert[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/desert/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Desert[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/desert/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Savanna[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/savanna/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/savanna/bg.gbapal"),
};
static const u32 sWallpaperTiles_Savanna[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Savanna[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/savanna/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Crag[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/crag/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/crag/bg.gbapal"),
};
static const u32 sWallpaperTiles_Crag[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/crag/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Crag[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/crag/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Volcano[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/volcano/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/volcano/bg.gbapal"),
};
static const u32 sWallpaperTiles_Volcano[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Volcano[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/volcano/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Snow[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/snow/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/snow/bg.gbapal"),
};
static const u32 sWallpaperTiles_Snow[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/snow/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Snow[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/snow/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Cave[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/cave/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/cave/bg.gbapal"),
};
static const u32 sWallpaperTiles_Cave[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/cave/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Cave[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/cave/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Beach[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/beach/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/beach/bg.gbapal"),
};
static const u32 sWallpaperTiles_Beach[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/beach/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Beach[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/beach/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Seafloor[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/seafloor/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/seafloor/bg.gbapal"),
};
static const u32 sWallpaperTiles_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Seafloor[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/seafloor/tilemap.bin.lz");

static const u16 sWallpaperPalettes_River[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/river/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/river/bg.gbapal"),
};
static const u32 sWallpaperTiles_River[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/river/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_River[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/river/tilemap.bin.lz");
static const u16 sWallpaperPalettes_Sky[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/sky/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/sky/bg.gbapal"),
};
static const u32 sWallpaperTiles_Sky[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/sky/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Sky[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/sky/tilemap.bin.lz");

static const u16 sWallpaperPalettes_PolkaDot[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/polkadot/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/polkadot/bg.gbapal"),
};
static const u32 sWallpaperTiles_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_PolkaDot[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/polkadot/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Machine[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/machine/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/machine/bg.gbapal"),
};
static const u32 sWallpaperTiles_Machine[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/machine/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Machine[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/machine/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Plain[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/plain/frame.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/plain/bg.gbapal"),
};
static const u32 sWallpaperTiles_Plain[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/plain/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Plain[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/plain/tilemap.bin.lz");

// 12x18 tilemap
static const u32 sWallpaperTilemap_Unused[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/unused.bin");

// Shadow color, text color
static const u16 sBoxTitleColors[WALLPAPER_COUNT][2] =
{
    [WALLPAPER_FOREST]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CITY]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_DESERT]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SAVANNA]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CRAG]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_VOLCANO]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SNOW]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CAVE]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_BEACH]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SEAFLOOR]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_RIVER]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SKY]        = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POLKADOT]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POKECENTER] = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_MACHINE]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_PLAIN]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_FRIENDS]    = {RGB(7, 7, 7), RGB_WHITE}
};

#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalettes_##name[0]}
// A few wallpapers are not defined in this file
#define WALLPAPER_ENTRY_G(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct Wallpaper sWallpapers[WALLPAPER_COUNT - 1] =
{
    [WALLPAPER_FOREST]     = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY]       = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT]     = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA]    = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG]       = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO]    = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW]       = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE]       = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH]      = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR]   = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER]      = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY]        = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT]   = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE]    = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN]      = WALLPAPER_ENTRY(Plain),
};

static const u8 sArrow_Gfx[] = INCBIN_U8("graphics/pokemon_storage/arrow.4bpp");

static const u16 sWallpaperPalettes_HLunasa[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/hlunasa/bg.gbapal"),
};
static const u32 sWallpaperTiles_HLunasa[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/hlunasa/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_HLunasa[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/hlunasa/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Screen[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/screen/bg.gbapal"),
};
static const u32 sWallpaperTiles_Screen[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Screen[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/screen/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Diagonal[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/diagonal/bg.gbapal"),
};
static const u32 sWallpaperTiles_Diagonal[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Diagonal[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Block[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/block/bg.gbapal"),
};
static const u32 sWallpaperTiles_Block[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Block[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/block/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Pokecenter2[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter2[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Pokecenter2[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Frame[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/frame/bg.gbapal"),
};
static const u32 sWallpaperTiles_Frame[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Frame[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/frame/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Blank[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame1.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/hlunasa/bg.gbapal"),
};
static const u32 sWallpaperTiles_Blank[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Blank[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/blank/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Circles[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/circles/bg.gbapal"),
};
static const u32 sWallpaperTiles_Circles[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Circles[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/circles/tilemap.bin.lz");

static const u16 sWallpaperPalettes_CYumeko[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/cyumeko/bg.gbapal"),
};
static const u32 sWallpaperTiles_CYumeko[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/cyumeko/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_CYumeko[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/cyumeko/tilemap.bin.lz");

static const u16 sWallpaperPalettes_CCirno[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ccirno/bg.gbapal"),
};
static const u32 sWallpaperTiles_CCirno[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/ccirno/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_CCirno[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/ccirno/tilemap.bin.lz");

static const u16 sWallpaperPalettes_Legendary[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/legendary/bg.gbapal"),
};
static const u32 sWallpaperTiles_Legendary[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_Legendary[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/legendary/tilemap.bin.lz");

static const u16 sWallpaperPalettes_AdCirno[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/adcirno/bg.gbapal"),
};
static const u32 sWallpaperTiles_AdCirno[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/adcirno/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_AdCirno[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/adcirno/tilemap.bin.lz");

static const u16 sWallpaperPalettes_SShizuha[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/sshizuha/bg.gbapal"),
};
static const u32 sWallpaperTiles_SShizuha[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/sshizuha/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_SShizuha[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/sshizuha/tilemap.bin.lz");

static const u16 sWallpaperPalettes_DHatate[][16] =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/dhatate/bg.gbapal"),
};
static const u32 sWallpaperTiles_DHatate[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/dhatate/tiles.4bpp.lz");
static const u32 sWallpaperTilemap_DHatate[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/dhatate/tilemap.bin.lz");

static const u32 sWallpaperIcon_Aqua[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/aqua.4bpp.lz");
static const u32 sWallpaperIcon_Heart[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/heart.4bpp.lz");
static const u32 sWallpaperIcon_FiveStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/five_star.4bpp.lz");
static const u32 sWallpaperIcon_Brick[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/brick.4bpp.lz");
static const u32 sWallpaperIcon_FourStar[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_star.4bpp.lz");
static const u32 sWallpaperIcon_Asterisk[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Dot[]          = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/dot.4bpp.lz");
static const u32 sWallpaperIcon_LineCircle[]   = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/line_circle.4bpp.lz");
static const u32 sWallpaperIcon_PokeBall[]     = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/pokeball.4bpp.lz");
static const u32 sWallpaperIcon_Maze[]         = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/maze.4bpp.lz");
static const u32 sWallpaperIcon_Footprint[]    = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/footprint.4bpp.lz");
static const u32 sWallpaperIcon_BigAsterisk[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/big_asterisk.4bpp.lz");
static const u32 sWallpaperIcon_Circle[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/circle.4bpp.lz");
static const u32 sWallpaperIcon_Rin[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/rin.4bpp.lz");
static const u32 sWallpaperIcon_Ribbon[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/ribbon.4bpp.lz");
static const u32 sWallpaperIcon_FourCircles[]  = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/four_circles.4bpp.lz");
static const u32 sWallpaperIcon_AHina[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/ahina.4bpp.lz");
static const u32 sWallpaperIcon_Crystal[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/crystal.4bpp.lz");
static const u32 sWallpaperIcon_CLuize[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/cluize.4bpp.lz");
static const u32 sWallpaperIcon_CYamame[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/cyamame.4bpp.lz");
static const u32 sWallpaperIcon_AkiSisters[]      = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/akisisters.4bpp.lz");
static const u32 sWallpaperIcon_StarInCircle[] = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/star_in_circle.4bpp.lz");
static const u32 sWallpaperIcon_SKogasa[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/skogasa.4bpp.lz");
static const u32 sWallpaperIcon_Latis[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/latis.4bpp.lz");
static const u32 sWallpaperIcon_HNazrin[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/hnazrin.4bpp.lz");
static const u32 sWallpaperIcon_Margatroid[]       = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/margatroid.4bpp.lz");
static const u32 sWallpaperIcon_Magma[]        = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/magma.4bpp.lz");

static const struct Wallpaper sWaldaWallpapers[] =
{
    WALLPAPER_ENTRY(HLunasa),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY_G(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY_G(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(CYumeko),
    WALLPAPER_ENTRY(CCirno),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(AdCirno),
    WALLPAPER_ENTRY(SShizuha),
    WALLPAPER_ENTRY(DHatate),
};

static const u32 *const sWaldaWallpaperIcons[] =
{
    sWallpaperIcon_Aqua,
    sWallpaperIcon_Heart,
    sWallpaperIcon_FiveStar,
    sWallpaperIcon_Brick,
    sWallpaperIcon_FourStar,
    sWallpaperIcon_Asterisk,
    sWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    sWallpaperIcon_LineCircle,
    sWallpaperIcon_PokeBall,
    sWallpaperIcon_Maze,
    sWallpaperIcon_Footprint,
    sWallpaperIcon_BigAsterisk,
    sWallpaperIcon_Circle,
    sWallpaperIcon_Rin,
    sWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    sWallpaperIcon_FourCircles,
    sWallpaperIcon_AHina,
    sWallpaperIcon_Crystal,
    sWallpaperIcon_CLuize,
    sWallpaperIcon_CYamame,
    sWallpaperIcon_AkiSisters,
    sWallpaperIcon_StarInCircle,
    sWallpaperIcon_SKogasa,
    sWallpaperIcon_Latis,
    gWallpaperIcon_TNazrin,
    sWallpaperIcon_HNazrin,
    sWallpaperIcon_Margatroid,
    sWallpaperIcon_Magma,
};
