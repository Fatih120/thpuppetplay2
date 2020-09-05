#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"

static u8 GetValidMewMoveDirection(u8);
static bool8 ShouldMewMoveNorth(struct ObjectEvent*, u8);
static bool8 ShouldMewMoveSouth(struct ObjectEvent*, u8);
static bool8 ShouldMewMoveEast(struct ObjectEvent*, u8);
static bool8 ShouldMewMoveWest(struct ObjectEvent*, u8);
static u8 GetRandomMewDirectionCandidate(u8);
static bool8 CanAkyuuWalkToCoords(s16, s16);

static EWRAM_DATA u8 sGrassSpriteId = 0;

static s16 sPlayerToAkyuuDeltaX;
static s16 sPlayerToAkyuuDeltaY;
static u8 sAkyuuDirectionCandidates[4];

extern const struct SpritePalette gSpritePalette_GeneralFieldEffect1;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

static const s16 sFarawayIslandRockCoords[4][2] =
{
    {14 + 7,  9 + 7},
    {18 + 7,  9 + 7},
    { 9 + 7, 10 + 7},
    {13 + 7, 13 + 7},
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
    bool32 skip;
    struct ObjectEvent *akyuu = &gObjectEvents[GetAkyuuObjectEventId()];

    sPlayerToAkyuuDeltaX = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x - akyuu->currentCoords.x;
    sPlayerToAkyuuDeltaY = gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y - akyuu->currentCoords.y;
    for (i = 0; i < ARRAY_COUNT(sAkyuuDirectionCandidates); i++)
        sAkyuuDirectionCandidates[i] = DIR_NONE;

    // Player hasn't moved (just facing new direction), don't move
    if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x
     && gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.y == gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y)
    {
        return DIR_NONE;
    }

    // Mew is invisible except for every 8th step
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 8 == 0)
        akyuu->invisible = 0;
    else
        akyuu->invisible = 1;

    // Mew will stay in place for 1 step after its visible
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 9 == 0)
        return DIR_NONE;

    // Below loop is for Mew to try to avoid getting trapped between the player and a rock
    for (i = 0; i < ARRAY_COUNT(sFarawayIslandRockCoords); i++)
    {
        if (gObjectEvents[gPlayerAvatar.objectEventId].previousCoords.x == sFarawayIslandRockCoords[i][0])
        {
            skip = FALSE;
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
            skip = FALSE;
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

    // Check if Mew can move in any direction without getting closer to the player
    // If so load into sMewDirectionCandidates
    // If Mew can move in two of the checked directions, choose one randomly
    if (ShouldMewMoveNorth(akyuu, 0))
    {
        if (ShouldMewMoveEast(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveWest(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        return DIR_NORTH;
    }

    if (ShouldMewMoveSouth(akyuu, 0))
    {
        if (ShouldMewMoveEast(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveWest(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
         return DIR_SOUTH;
    }

    if (ShouldMewMoveEast(akyuu, 0))
    {
        if (ShouldMewMoveNorth(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveSouth(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        return DIR_EAST;
    }

    if (ShouldMewMoveWest(akyuu, 0))
    {
        if (ShouldMewMoveNorth(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
        else if (ShouldMewMoveSouth(akyuu, 1))
            return GetRandomMewDirectionCandidate(2);
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

    // Can't avoid player on axis, move any valid direction
    return GetValidMewMoveDirection(DIR_NONE);
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

// Last ditch effort to move, clear move candidates and try all directions again
static u8 GetValidMewMoveDirection(u8 ignoredDir)
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

// Every 4th step Mew will shake the grass it steps into
// Otherwise its movement leaves grass undisturbed
bool8 ShouldMewShakeGrass(struct ObjectEvent *objectEvent)
{
    if (VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) != 0xFFFF
     && VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % 4 == 0)
        return TRUE;

    return FALSE;
}

void SetMewAboveGrass(void)
{
    s16 x;
    s16 y;
    u8 spriteId;
    struct ObjectEvent *akyuu = &gObjectEvents[GetAkyuuObjectEventId()];

    akyuu->invisible = FALSE;
    if (gSpecialVar_0x8004 == 1)
    {
        akyuu->fixedPriority = 1;
        gSprites[akyuu->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[akyuu->spriteId].subpriority = 1;
    }
    else
    {
        // Mew emerging from grass when found
        // Also do field effect for grass shaking as it emerges
        VarSet(VAR_FARAWAY_ISLAND_STEP_COUNTER, 0xFFFF);
        akyuu->fixedPriority = 1;
        gSprites[akyuu->spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        if (gSpecialVar_Facing != DIR_NORTH)
            gSprites[akyuu->spriteId].subpriority = 1;

        LoadSpritePalette(&gSpritePalette_GeneralFieldEffect1);
        UpdateSpritePaletteWithWeather(IndexOfSpritePaletteTag(gSpritePalette_GeneralFieldEffect1.tag));

        x = akyuu->currentCoords.x;
        y = akyuu->currentCoords.y;
        SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
        sGrassSpriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_LONG_GRASS], x, y, gSprites[akyuu->spriteId].subpriority - 1);
        if (sGrassSpriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[sGrassSpriteId];
            sprite->coordOffsetEnabled = 1;
            sprite->oam.priority = 2;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void DestroyMewEmergingGrassSprite(void)
{
    if (sGrassSpriteId != MAX_SPRITES)
        DestroySprite(&gSprites[sGrassSpriteId]);
}

static bool8 ShouldMewMoveNorth(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaY > 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y - 1))
    {
        sAkyuuDirectionCandidates[index] = DIR_NORTH;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveEast(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaX < 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x + 1, akyuu->currentCoords.y))
    {
        sAkyuuDirectionCandidates[index] = DIR_EAST;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveSouth(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaY < 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x, akyuu->currentCoords.y + 1))
    {
        sAkyuuDirectionCandidates[index] = DIR_SOUTH;
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldMewMoveWest(struct ObjectEvent *akyuu, u8 index)
{
    if (sPlayerToAkyuuDeltaX > 0 && CanAkyuuWalkToCoords(akyuu->currentCoords.x - 1, akyuu->currentCoords.y))
    {
        sAkyuuDirectionCandidates[index] = DIR_WEST;
        return TRUE;
    }

    return FALSE;
}

static u8 GetRandomMewDirectionCandidate(u8 numDirections)
{
    return sAkyuuDirectionCandidates[VarGet(VAR_FARAWAY_ISLAND_STEP_COUNTER) % numDirections];
}
