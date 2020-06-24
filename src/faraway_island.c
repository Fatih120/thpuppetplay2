#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"

static u8 sub_81D4890(u8);
static bool8 sub_81D4C14(struct ObjectEvent*, u8);
static u8 sub_81D4C9C(struct ObjectEvent*, u8);
static u8 sub_81D4C58(struct ObjectEvent*, u8);
static u8 sub_81D4CE0(struct ObjectEvent*, u8);
static u8 sub_81D4D24(u8);
static bool8 CanAkyuuWalkToCoords(s16, s16);

static EWRAM_DATA u8 sUnknown_0203CF50 = 0;

static s16 sPlayerToAkyuuDeltaX;
static s16 sPlayerToAkyuuDeltaY;
static u8 sAkyuuDirectionCandidates[4];

extern const struct SpritePalette gFieldEffectObjectPaletteInfo1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const s16 sFarawayIslandRockCoords[4][2] =
{
    {21, 16},
    {25, 16},
    {16, 17},
    {20, 20},
};

static u8 GetAkyuuObjectEventId(void)
{
    u8 objectEventId;
    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    return objectEventId;
}

u32 GetAkyuuMoveDirection(void)
{
    u8 i;
    int skip;
    struct ObjectEvent *akyuu = &gObjectEvents[GetAkyuuObjectEventId()];

    sPlayerToAkyuuDeltaX = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x - akyuu->currentCoords.x;
    sPlayerToAkyuuDeltaY = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y - akyuu->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(sAkyuuDirectionCandidates); i++)
        sAkyuuDirectionCandidates[i] = DIR_NONE;

    if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x
     && gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y)
    {
        return DIR_NONE;
    }

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 8 == 0)
        akyuu->invisible = 0;
    else
        akyuu->invisible = 1;

    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 9 == 0)
        return DIR_NONE;

    for (i = 0; i < ARRAY_COUNT(sFarawayIslandRockCoords); i++)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == sFarawayIslandRockCoords[i][0])
        {
            skip = 0;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y < sFarawayIslandRockCoords[i][1])
            {
                if (akyuu->currentCoords.y <= sFarawayIslandRockCoords[i][1])
                    skip = 1;
            }
            else
            {
                if (akyuu->currentCoords.y >= sFarawayIslandRockCoords[i][1])
                    skip = 1;
            }

            if (!skip)
            {
                if (sPlayerToAkyuuDeltaX > 0)
                {
                    if (akyuu->currentCoords.x + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
                            return DIR_EAST;
                    }
                }
                else if (sPlayerToAkyuuDeltaX < 0)
                {
                    if (akyuu->currentCoords.x - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
                            return DIR_WEST;
                    }
                }

                if (akyuu->currentCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x)
                {
                    if (sPlayerToAkyuuDeltaY > 0)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                    else
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
            }
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == sFarawayIslandRockCoords[i][1])
        {
            skip = 0;
            if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x < sFarawayIslandRockCoords[i][0])
            {
                if (akyuu->currentCoords.x <= sFarawayIslandRockCoords[i][0])
                    skip = 1;
            }
            else
            {
                if (akyuu->currentCoords.x >= sFarawayIslandRockCoords[i][0])
                    skip = 1;
            }

            if (!skip)
            {
                if (sPlayerToAkyuuDeltaY > 0)
                {
                    if (akyuu->currentCoords.y + 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
                            return DIR_SOUTH;
                    }
                }
                else if (sPlayerToAkyuuDeltaY < 0)
                {
                    if (akyuu->currentCoords.y - 1 == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
                            return DIR_NORTH;
                    }
                }

                if (akyuu->currentCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y)
                {
                    if (sPlayerToAkyuuDeltaX > 0)
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
                            return DIR_WEST;
                    }
                    else
                    {
                        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
                            return DIR_EAST;
                    }
                }
            }
        }
    }

    if (sub_81D4C14(akyuu, 0))
    {
        if (sub_81D4C58(akyuu, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(akyuu, 1))
            return sub_81D4D24(2);
        else
            return DIR_NORTH;
    }

    if (sub_81D4C9C(akyuu, 0))
    {
        if (sub_81D4C58(akyuu, 1))
            return sub_81D4D24(2);
        else if (sub_81D4CE0(akyuu, 1))
            return sub_81D4D24(2);
        else
            return DIR_SOUTH;
    }

    if (sub_81D4C58(akyuu, 0))
    {
        if (sub_81D4C14(akyuu, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(akyuu, 1))
            return sub_81D4D24(2);
        else
            return DIR_EAST;
    }

    if (sub_81D4CE0(akyuu, 0))
    {
        if (sub_81D4C14(akyuu, 1))
            return sub_81D4D24(2);
        else if (sub_81D4C9C(akyuu, 1))
            return sub_81D4D24(2);
        else
            return DIR_WEST;
    }

    if (sPlayerToAkyuuDeltaY == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y > akyuu->currentCoords.y)
        {
            if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
                return DIR_NORTH;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y < akyuu->currentCoords.y)
        {
            if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
                return DIR_SOUTH;
        }

        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
            return DIR_NORTH;

        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
            return DIR_SOUTH;
    }

    if (sPlayerToAkyuuDeltaX == 0)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x > akyuu->currentCoords.x)
        {
            if (CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
                return DIR_WEST;
        }

        if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x < akyuu->currentCoords.x)
        {
            if (CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
                return DIR_EAST;
        }

        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
            return DIR_EAST;

        if (CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
            return DIR_WEST;
    }

    return sub_81D4890(DIR_NONE);
}

static bool8 CanAkyuuWalkToCoords(s16 x, s16 y)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x == x
     && gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y == y)
    {
        return FALSE;
    }

    return MetatileBehavior_IsPokeGrass(MapGridGetMetatileBehaviorAt(x, y));
}

static u8 sub_81D4890(u8 ignoredDir)
{
    u8 i;
    u8 count = 0;
    struct ObjectEvent *akyuu = &gObjectEvents[GetAkyuuObjectEventId()];

    for (i = 0; i < ARRAY_COUNT(sAkyuuDirectionCandidates); i++)
        sAkyuuDirectionCandidates[i] = DIR_NONE;

    if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1) == TRUE && ignoredDir != DIR_NORTH)
    {
        sAkyuuDirectionCandidates[count] = DIR_NORTH;
        count++;
    }

    if (CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y) == TRUE && ignoredDir != DIR_EAST)
    {
        sAkyuuDirectionCandidates[count] = DIR_EAST;
        count++;
    }

    if (CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1) == TRUE && ignoredDir != DIR_SOUTH)
    {
        sAkyuuDirectionCandidates[count] = DIR_SOUTH;
        count++;
    }

    if (CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y) == TRUE && ignoredDir != DIR_WEST)
    {
        sAkyuuDirectionCandidates[count] = DIR_WEST;
        count++;
    }

    if (count > 1)
        return sAkyuuDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % count];
    else
        return sAkyuuDirectionCandidates[0];
}

void UpdateFarawayIslandStepCounter(void)
{
    u16 steps = VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        steps++;
        if (steps >= 9999)
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0);
        else
            VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, steps);
    }
}

bool8 ObjectEventIsFarawayIslandAkyuu(struct ObjectEvent *objectEvent)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (objectEvent->graphicsId == OBJ_EVENT_GFX_AKYUU)
            return TRUE;
    }

    return FALSE;
}

bool8 IsAkyuuPlayingHideAndSeek(void)
{
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(FARAWAY_ISLAND_INTERIOR)
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(FARAWAY_ISLAND_INTERIOR))
    {
        if (FlagGet(FLAG_CAUGHT_AKYUU) != TRUE && FlagGet(FLAG_HIDE_AKYUU) != TRUE)
            return TRUE;
    }

    return FALSE;
}

bool8 sub_81D4A58(struct ObjectEvent *objectEvent)
{
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) != 0xFFFF
     && VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 4 == 0)
        return TRUE;

    return FALSE;
}

void sub_81D4A90(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct ObjectEvent *akyuu = &gObjectEvents[GetAkyuuObjectEventId()];

    akyuu->invisible = 0;
    if (gSpecialVar_0x8004 == 1)
    {
        akyuu->fixedPriority = 1;
        gSprites[akyuu->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[akyuu->spriteId].subpriority = 1;
    }
    else
    {
        VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0xFFFF);
        akyuu->fixedPriority = 1;
        gSprites[akyuu->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        if (gSpecialVar_Facing != DIR_NORTH)
            gSprites[akyuu->spriteId].subpriority = 1;

        LoadSpritePalette(&gFieldEffectObjectPaletteInfo1);
        UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(gFieldEffectObjectPaletteInfo1.tag));

        x = akyuu->currentCoords.x;
        y = akyuu->currentCoords.y;
        SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
        sUnknown_0203CF50 = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[15], x, y, gSprites[akyuu->spriteId].subpriority - 1);
        if (sUnknown_0203CF50 != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sUnknown_0203CF50];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_81D4BEC(void)
{
    if (sUnknown_0203CF50 != MAX_SPRITES)
        DestroySprite(&gSprites[sUnknown_0203CF50]);
}

static bool8 sub_81D4C14(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaY > 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
    {
        sAkyuuDirectionCandidates[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C58(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaX < 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
    {
        sAkyuuDirectionCandidates[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4C9C(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaY < 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
    {
        sAkyuuDirectionCandidates[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4CE0(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaX > 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
    {
        sAkyuuDirectionCandidates[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 sub_81D4D24(u8 mod)
{
    return sAkyuuDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % mod];
}
