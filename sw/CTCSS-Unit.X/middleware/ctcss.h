/*
\author         Oliver Blaser
\date           16.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_CTCSS_H
#define IG_CTCSS_H

#include "../types.h"


#define CTCSS_IDX_OFF       0
#define CTCSS_IDX_67_0      1
#define CTCSS_IDX_69_3      2
#define CTCSS_IDX_71_9      3
#define CTCSS_IDX_74_4      4
#define CTCSS_IDX_77_0      5
#define CTCSS_IDX_79_7      6
#define CTCSS_IDX_82_5      7
#define CTCSS_IDX_85_4      8
#define CTCSS_IDX_88_5      9
#define CTCSS_IDX_91_5     10
#define CTCSS_IDX_94_8     11
#define CTCSS_IDX_97_4     12
#define CTCSS_IDX_100_0    13
#define CTCSS_IDX_103_5    14
#define CTCSS_IDX_107_2    15
#define CTCSS_IDX_110_9    16
#define CTCSS_IDX_114_8    17
#define CTCSS_IDX_118_8    18
#define CTCSS_IDX_123_0    19
#define CTCSS_IDX_127_3    20
#define CTCSS_IDX_131_8    21
#define CTCSS_IDX_136_5    22
#define CTCSS_IDX_141_3    23
#define CTCSS_IDX_146_2    24
#define CTCSS_IDX_151_4    25
#define CTCSS_IDX_156_7    26
#define CTCSS_IDX_159_8    27
#define CTCSS_IDX_162_2    28
#define CTCSS_IDX_165_5    29
#define CTCSS_IDX_167_9    30
#define CTCSS_IDX_171_3    31
#define CTCSS_IDX_173_8    32
#define CTCSS_IDX_177_3    33
#define CTCSS_IDX_179_9    34
#define CTCSS_IDX_183_5    35
#define CTCSS_IDX_186_2    36
#define CTCSS_IDX_189_9    37
#define CTCSS_IDX_192_8    38
#define CTCSS_IDX_196_6    39
#define CTCSS_IDX_199_5    40
#define CTCSS_IDX_203_5    41
#define CTCSS_IDX_206_5    42
#define CTCSS_IDX_210_7    43
#define CTCSS_IDX_218_1    44
#define CTCSS_IDX_225_7    45
#define CTCSS_IDX_229_1    46
#define CTCSS_IDX_233_6    47
#define CTCSS_IDX_241_8    48
#define CTCSS_IDX_250_3    49
#define CTCSS_IDX_254_1    50

// indexes for the 38 tone standard
#define CTCSS_38T_1     CTCSS_IDX_67_0
#define CTCSS_38T_2     CTCSS_IDX_71_9
#define CTCSS_38T_3     CTCSS_IDX_74_4
#define CTCSS_38T_4     CTCSS_IDX_77_0
#define CTCSS_38T_5     CTCSS_IDX_79_7
#define CTCSS_38T_6     CTCSS_IDX_82_5
#define CTCSS_38T_7     CTCSS_IDX_85_4
#define CTCSS_38T_8     CTCSS_IDX_88_5
#define CTCSS_38T_9     CTCSS_IDX_91_5
#define CTCSS_38T_10    CTCSS_IDX_94_8
#define CTCSS_38T_11    CTCSS_IDX_97_4
#define CTCSS_38T_12    CTCSS_IDX_100_0
#define CTCSS_38T_13    CTCSS_IDX_103_5
#define CTCSS_38T_14    CTCSS_IDX_107_2
#define CTCSS_38T_15    CTCSS_IDX_110_9
#define CTCSS_38T_16    CTCSS_IDX_114_8
#define CTCSS_38T_17    CTCSS_IDX_118_8
#define CTCSS_38T_18    CTCSS_IDX_123_0
#define CTCSS_38T_19    CTCSS_IDX_127_3
#define CTCSS_38T_20    CTCSS_IDX_131_8
#define CTCSS_38T_21    CTCSS_IDX_136_5
#define CTCSS_38T_22    CTCSS_IDX_141_3
#define CTCSS_38T_23    CTCSS_IDX_146_2
#define CTCSS_38T_24    CTCSS_IDX_151_4
#define CTCSS_38T_25    CTCSS_IDX_156_7
#define CTCSS_38T_26    CTCSS_IDX_162_2
#define CTCSS_38T_27    CTCSS_IDX_167_9
#define CTCSS_38T_28    CTCSS_IDX_173_8
#define CTCSS_38T_29    CTCSS_IDX_179_9
#define CTCSS_38T_30    CTCSS_IDX_186_2
#define CTCSS_38T_31    CTCSS_IDX_192_8
#define CTCSS_38T_32    CTCSS_IDX_203_5
#define CTCSS_38T_33    CTCSS_IDX_210_7
#define CTCSS_38T_34    CTCSS_IDX_218_1
#define CTCSS_38T_35    CTCSS_IDX_225_7
#define CTCSS_38T_36    CTCSS_IDX_233_6
#define CTCSS_38T_37    CTCSS_IDX_241_8
#define CTCSS_38T_38    CTCSS_IDX_250_3


void CTCSS_setTone(uint8_t ctcssIdx);


#endif // IG_CTCSS_H
