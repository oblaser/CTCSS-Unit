/*
\author         Oliver Blaser
\date           06.11.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_CTCSS_H
#define IG_CTCSS_H

#include "../types.h"

typedef enum CTCSS_TONE_ID
{
    CTCSS_ID_OFF = 0,
    CTCSS_ID_67_0,
    CTCSS_ID_69_3,
    CTCSS_ID_71_9,
    CTCSS_ID_74_4,
    CTCSS_ID_77_0,
    CTCSS_ID_79_7,
    CTCSS_ID_82_5,
    CTCSS_ID_85_4,
    CTCSS_ID_88_5,
    CTCSS_ID_91_5,
    CTCSS_ID_94_8,
    CTCSS_ID_97_4,
    CTCSS_ID_100_0,
    CTCSS_ID_103_5,
    CTCSS_ID_107_2,
    CTCSS_ID_110_9,
    CTCSS_ID_114_8,
    CTCSS_ID_118_8,
    CTCSS_ID_123_0,
    CTCSS_ID_127_3,
    CTCSS_ID_131_8,
    CTCSS_ID_136_5,
    CTCSS_ID_141_3,
    CTCSS_ID_146_2,
    CTCSS_ID_151_4,
    CTCSS_ID_156_7,
    CTCSS_ID_159_8,
    CTCSS_ID_162_2,
    CTCSS_ID_165_5,
    CTCSS_ID_167_9,
    CTCSS_ID_171_3,
    CTCSS_ID_173_8,
    CTCSS_ID_177_3,
    CTCSS_ID_179_9,
    CTCSS_ID_183_5,
    CTCSS_ID_186_2,
    CTCSS_ID_189_9,
    CTCSS_ID_192_8,
    CTCSS_ID_196_6,
    CTCSS_ID_199_5,
    CTCSS_ID_203_5,
    CTCSS_ID_206_5,
    CTCSS_ID_210_7,
    CTCSS_ID_218_1,
    CTCSS_ID_225_7,
    CTCSS_ID_229_1,
    CTCSS_ID_233_6,
    CTCSS_ID_241_8,
    CTCSS_ID_250_3,
    CTCSS_ID_254_1
} ctcss_id_t;

// indexes for the 38 tone standard
#define CTCSS_38T_1     CTCSS_ID_67_0
#define CTCSS_38T_2     CTCSS_ID_71_9
#define CTCSS_38T_3     CTCSS_ID_74_4
#define CTCSS_38T_4     CTCSS_ID_77_0
#define CTCSS_38T_5     CTCSS_ID_79_7
#define CTCSS_38T_6     CTCSS_ID_82_5
#define CTCSS_38T_7     CTCSS_ID_85_4
#define CTCSS_38T_8     CTCSS_ID_88_5
#define CTCSS_38T_9     CTCSS_ID_91_5
#define CTCSS_38T_10    CTCSS_ID_94_8
#define CTCSS_38T_11    CTCSS_ID_97_4
#define CTCSS_38T_12    CTCSS_ID_100_0
#define CTCSS_38T_13    CTCSS_ID_103_5
#define CTCSS_38T_14    CTCSS_ID_107_2
#define CTCSS_38T_15    CTCSS_ID_110_9
#define CTCSS_38T_16    CTCSS_ID_114_8
#define CTCSS_38T_17    CTCSS_ID_118_8
#define CTCSS_38T_18    CTCSS_ID_123_0
#define CTCSS_38T_19    CTCSS_ID_127_3
#define CTCSS_38T_20    CTCSS_ID_131_8
#define CTCSS_38T_21    CTCSS_ID_136_5
#define CTCSS_38T_22    CTCSS_ID_141_3
#define CTCSS_38T_23    CTCSS_ID_146_2
#define CTCSS_38T_24    CTCSS_ID_151_4
#define CTCSS_38T_25    CTCSS_ID_156_7
#define CTCSS_38T_26    CTCSS_ID_162_2
#define CTCSS_38T_27    CTCSS_ID_167_9
#define CTCSS_38T_28    CTCSS_ID_173_8
#define CTCSS_38T_29    CTCSS_ID_179_9
#define CTCSS_38T_30    CTCSS_ID_186_2
#define CTCSS_38T_31    CTCSS_ID_192_8
#define CTCSS_38T_32    CTCSS_ID_203_5
#define CTCSS_38T_33    CTCSS_ID_210_7
#define CTCSS_38T_34    CTCSS_ID_218_1
#define CTCSS_38T_35    CTCSS_ID_225_7
#define CTCSS_38T_36    CTCSS_ID_233_6
#define CTCSS_38T_37    CTCSS_ID_241_8
#define CTCSS_38T_38    CTCSS_ID_250_3

const uint8_t CTCSS_lut[] =
{
    127, 130, 133, 136, 139, 143, 146, 149,
    152, 155, 158, 161, 164, 167, 170, 173,
    176, 178, 181, 184, 187, 190, 192, 195,
    198, 200, 203, 205, 208, 210, 212, 215,
    217, 219, 221, 223, 225, 227, 229, 231,
    233, 234, 236, 238, 239, 240, 242, 243,
    244, 245, 247, 248, 249, 249, 250, 251,
    252, 252, 253, 253, 253, 254, 254, 254,
    254, 254, 254, 254, 253, 253, 253, 252,
    252, 251, 250, 249, 249, 248, 247, 245,
    244, 243, 242, 240, 239, 238, 236, 234,
    233, 231, 229, 227, 225, 223, 221, 219,
    217, 215, 212, 210, 208, 205, 203, 200,
    198, 195, 192, 190, 187, 184, 181, 178,
    176, 173, 170, 167, 164, 161, 158, 155,
    152, 149, 146, 143, 139, 136, 133, 130,
    127, 124, 121, 118, 115, 111, 108, 105,
    102,  99,  96,  93,  90,  87,  84,  81,
     78,  76,  73,  70,  67,  64,  62,  59,
     56,  54,  51,  49,  46,  44,  42,  39,
     37,  35,  33,  31,  29,  27,  25,  23,
     21,  20,  18,  16,  15,  14,  12,  11,
     10,   9,   7,   6,   5,   5,   4,   3,
      2,   2,   1,   1,   1,   0,   0,   0,
      0,   0,   0,   0,   1,   1,   1,   2,
      2,   3,   4,   5,   5,   6,   7,   9,
     10,  11,  12,  14,  15,  16,  18,  20,
     21,  23,  25,  27,  29,  31,  33,  35,
     37,  39,  42,  44,  46,  49,  51,  54,
     56,  59,  62,  64,  67,  70,  73,  76,
     78,  81,  84,  87,  90,  93,  96,  99,
    102, 105, 108, 111, 115, 118, 121, 124
};
// octave script to calculate the look up table:
// > x=[0:1:255];
// > lut=round(sin((2*pi/256).*x)*127+127);
// > csvwrite('lut.scite', lut)


uint16_t CTCSS_accumulator;
uint16_t CTCSS_increment;

void CTCSS_init();
void CTCSS_setTone(ctcss_id_t toneId);


#endif // IG_CTCSS_H
