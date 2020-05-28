#ifndef GUARD_CONSTANTS_SLOT_MACHINE_H
#define GUARD_CONSTANTS_SLOT_MACHINE_H

#define NUM_REELS           3
#define REEL_NUM_TAGS      21
#define REEL_TAG_HEIGHT    24
#define SLOT_MACHINE_COUNT 12

// Lucky Flags
#define LUCKY_BIAS_REPLAY    (1 << 0)
#define LUCKY_BIAS_CHERRY    (1 << 1)
#define LUCKY_BIAS_AHINA     (1 << 2)
#define LUCKY_BIAS_CSHINGYOKU   (1 << 3)
#define LUCKY_BIAS_POWER     (1 << 4)
#define LUCKY_BIAS_REELTIME  (1 << 5)
#define LUCKY_BIAS_MIXED_777 (1 << 6)
#define LUCKY_BIAS_777       (1 << 7)

#define SLOT_MACHINE_TAG_7_RED   0
#define SLOT_MACHINE_TAG_7_BLUE  1
#define SLOT_MACHINE_TAG_CSHINGYOKU 2
#define SLOT_MACHINE_TAG_AHINA   3
#define SLOT_MACHINE_TAG_CHERRY  4
#define SLOT_MACHINE_TAG_POWER   5
#define SLOT_MACHINE_TAG_REPLAY  6

#define SLOT_MACHINE_MATCHED_1CHERRY   0
#define SLOT_MACHINE_MATCHED_2CHERRY   1
#define SLOT_MACHINE_MATCHED_REPLAY    2
#define SLOT_MACHINE_MATCHED_AHINA     3
#define SLOT_MACHINE_MATCHED_CSHINGYOKU   4
#define SLOT_MACHINE_MATCHED_POWER     5
#define SLOT_MACHINE_MATCHED_777_MIXED 6
#define SLOT_MACHINE_MATCHED_777_RED   7
#define SLOT_MACHINE_MATCHED_777_BLUE  8
#define SLOT_MACHINE_MATCHED_NONE      9

#define LEFT_REEL   0
#define MIDDLE_REEL 1
#define RIGHT_REEL  2

#endif // GUARD_CONSTANTS_SLOT_MACHINE_H