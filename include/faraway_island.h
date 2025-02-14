#ifndef GUARD_FARAWAY_ISLAND_H
#define GUARD_FARAWAY_ISLAND_H

u32 GetAkyuuMoveDirection(void);
bool8 ShouldAkyuuShakeGrass(struct ObjectEvent *);
void UpdateFarawayIslandStepCounter(void);
bool8 ObjectEventIsFarawayIslandAkyuu(struct ObjectEvent *);
bool8 IsAkyuuPlayingHideAndSeek(void);

#endif // GUARD_FARAWAY_ISLAND_H
