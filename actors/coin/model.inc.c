#include "config.h"
#include "fuck.h"
// Coin
#define IA8_30FPS_COINS
#ifdef IA8_30FPS_COINS

// YELLOW
// 0x030056C0
static const Vtx coin_seg3_vertex_yellow[] = {
    {{{   -32,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0x00, 0xff}}},
};

// BLUE
// 0x03005700
static const Vtx coin_seg3_vertex_blue[] = {
    {{{   -48,      0,      0}, 0, {   -16,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,      0,      0}, 0, {  4080,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,     96,      0}, 0, {  4080,    -16}, {0x80, 0x80, 0xff, 0xff}}},
    {{{   -48,     96,      0}, 0, {   -16,    -16}, {0x80, 0x80, 0xff, 0xff}}},
};

// RED
// 0x03005740
static const Vtx coin_seg3_vertex_red[] = {
    {{{   -36,      0,      0}, 0, {   -16,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,      0,      0}, 0, {  4080,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,     72,      0}, 0, {  4080,    -16}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -36,     72,      0}, 0, {   -16,    -16}, {0xff, 0x00, 0x00, 0xff}}},
};

// SECRET
// 0x03005780
static const Vtx coin_seg3_vertex_secret[] = {
    {{{   -36,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,     72,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -36,     72,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0xff, 0xff}}},
};

// YELLOW REV
// 0x030056C0
static const Vtx coin_seg3_vertex_yellow_r[] = {
    {{{   -32,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0x00, 0xff}}},
};

// BLUE REV
// 0x03005700
static const Vtx coin_seg3_vertex_blue_r[] = {
    {{{   -48,      0,      0}, 0, {  4080,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,      0,      0}, 0, {   -16,   4080}, {0x80, 0x80, 0xff, 0xff}}},
    {{{    48,     96,      0}, 0, {   -16,    -16}, {0x80, 0x80, 0xff, 0xff}}},
    {{{   -48,     96,      0}, 0, {  4080,    -16}, {0x80, 0x80, 0xff, 0xff}}},
};

// RED REV
// 0x03005740
static const Vtx coin_seg3_vertex_red_r[] = {
    {{{   -36,      0,      0}, 0, {  4080,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,      0,      0}, 0, {   -16,   4080}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    36,     72,      0}, 0, {   -16,    -16}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -36,     72,      0}, 0, {  4080,    -16}, {0xff, 0x00, 0x00, 0xff}}},
};

// SECRET REV
// 0x03005780
static const Vtx coin_seg3_vertex_secret_r[] = {
    {{{   -36,      0,      0}, 0, {  4080,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,      0,      0}, 0, {   -16,   4080}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    36,     72,      0}, 0, {   -16,    -16}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -36,     72,      0}, 0, {  4080,    -16}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x03005780


// set geo
// 0x03007780 - 0x030077D0
const Gfx coin_seg3_dl_start[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsSPTexture(32767, 32767, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_LOADTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 252, 252),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_RENDERTILE, 0, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD, (G_TX_CLAMP | G_TX_NOMIRROR), 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, 252, 252),
    gsSPEndDisplayList(),
};

// clear geo
// 0x030077D0 - 0x03007800
const Gfx coin_seg3_dl_end[] = {
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

// YELLOW
const Gfx coin_seg3_dl_yellow_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_1_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_2_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_3_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_4_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_6_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_yellow_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_7_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

// BLUE
const Gfx coin_seg3_dl_blue_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_1_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_2_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_3_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_4_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_6_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_blue_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_7_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

// RED
const Gfx coin_seg3_dl_red_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_1_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_2_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_3_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_4_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_6_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_red_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_7_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};
// SECRET
const Gfx coin_seg3_dl_secret_0[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_0_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_1[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_1_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_2[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_2_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_3[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_3_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_4[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_4_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_5[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_5_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_6[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_6_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

const Gfx coin_seg3_dl_secret_7[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 64, coin_seg3_texture_7_ia8),
    gsSPDisplayList(coin_seg3_dl_start),
    gsSPVertex(coin_seg3_vertex_secret, 4, 0),
    gsSPBranchList(coin_seg3_dl_end),
};

#else
#ifdef IA8_COINS
// 0x030056C0
static const Vtx coin_seg3_vertex_yellow[] = {
    {{{   -32,      0,      0}, 0, {     0,   4032}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {  4032,   4032}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {  4032,      0}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0xff, 0xff, 0x00, 0xff}}},
};

// 0x03005700
static const Vtx coin_seg3_vertex_blue[] = {
    {{{   -50,      0,      0}, 0, {     0,   4032}, {0x78, 0x78, 0xff, 0xff}}},
    {{{    50,      0,      0}, 0, {  4032,   4032}, {0x78, 0x78, 0xff, 0xff}}},
    {{{    50,    100,      0}, 0, {  4032,      0}, {0x78, 0x78, 0xff, 0xff}}},
    {{{   -50,    100,      0}, 0, {     0,      0}, {0x78, 0x78, 0xff, 0xff}}},
};

// 0x03005740
static const Vtx coin_seg3_vertex_red[] = {
    {{{   -35,      0,      0}, 0, {     0,   4032}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    35,      0,      0}, 0, {  4032,   4032}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    35,     70,      0}, 0, {  4032,      0}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -35,     70,      0}, 0, {     0,      0}, {0xff, 0x00, 0x00, 0xff}}},
};
#else
static const Vtx coin_seg3_vertex_yellow[] = {
    {{{   -32,      0,      0}, 0, {     0,   1984}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,      0,      0}, 0, {  1984,   1984}, {0xff, 0xff, 0x00, 0xff}}},
    {{{    32,     64,      0}, 0, {  1984,      0}, {0xff, 0xff, 0x00, 0xff}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0xff, 0xff, 0x00, 0xff}}},
};

// 0x03005700
static const Vtx coin_seg3_vertex_blue[] = {
    {{{   -50,      0,      0}, 0, {     0,   1984}, {0x78, 0x78, 0xff, 0xff}}},
    {{{    50,      0,      0}, 0, {  1984,   1984}, {0x78, 0x78, 0xff, 0xff}}},
    {{{    50,    100,      0}, 0, {  1984,      0}, {0x78, 0x78, 0xff, 0xff}}},
    {{{   -50,    100,      0}, 0, {     0,      0}, {0x78, 0x78, 0xff, 0xff}}},
};

// 0x03005740
static const Vtx coin_seg3_vertex_red[] = {
    {{{   -35,      0,      0}, 0, {     0,   1984}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    35,      0,      0}, 0, {  1984,   1984}, {0xff, 0x00, 0x00, 0xff}}},
    {{{    35,     70,      0}, 0, {  1984,      0}, {0xff, 0x00, 0x00, 0xff}}},
    {{{   -35,     70,      0}, 0, {     0,      0}, {0xff, 0x00, 0x00, 0xff}}},
};
#endif

// 0x03005780
#ifdef IA8_COINS
ALIGNED8 static const Texture coin_seg3_texture_front[] = {
#include "actors/coin/coin_front.ia8.inc.c"
};

// 0x03005F80
ALIGNED8 static const Texture coin_seg3_texture_tilt_right[] = {
#include "actors/coin/coin_tilt_right.ia8.inc.c"
};

// 0x03006780
ALIGNED8 static const Texture coin_seg3_texture_side[] = {
#include "actors/coin/coin_side.ia8.inc.c"
};

// 0x03006F80
ALIGNED8 static const Texture coin_seg3_texture_tilt_left[] = {
#include "actors/coin/coin_tilt_left.ia8.inc.c"
};
#else
ALIGNED8 static const Texture coin_seg3_texture_front[] = {
#include "actors/coin/coin_front.ia16.inc.c"
};

ALIGNED8 static const Texture coin_seg3_texture_tilt_right[] = {
#include "actors/coin/coin_tilt_right.ia16.inc.c"
};

ALIGNED8 static const Texture coin_seg3_texture_side[] = {
#include "actors/coin/coin_side.ia16.inc.c"
};

ALIGNED8 static const Texture coin_seg3_texture_tilt_left[] = {
#include "actors/coin/coin_tilt_left.ia16.inc.c"
};
#endif

// 0x03007780 - 0x030077D0
const Gfx coin_seg3_sub_dl_begin[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
#ifdef IA8_COINS
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 6, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64/2 * 64 - 1, CALC_DXT(64/2, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
#else
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
#endif
    gsSPEndDisplayList(),
};

// 0x030077D0 - 0x03007800
const Gfx coin_seg3_sub_dl_end[] = {
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

// 0x03007800 - 0x03007828
const Gfx coin_seg3_dl_yellow_front[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_front),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007828 - 0x03007850
const Gfx coin_seg3_dl_yellow_tilt_right[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_right),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007850 - 0x03007878
const Gfx coin_seg3_dl_yellow_side[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_side),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007878 - 0x030078A0
const Gfx coin_seg3_dl_yellow_tilt_left[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_left),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_yellow, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x030078A0 - 0x030078C8
const Gfx coin_seg3_dl_blue_front[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_front),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x030078C8 - 0x030078F0
const Gfx coin_seg3_dl_blue_tilt_right[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_right),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x030078F0 - 0x03007918
const Gfx coin_seg3_dl_blue_side[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_side),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007918 - 0x03007940
const Gfx coin_seg3_dl_blue_tilt_left[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_left),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_blue, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007940 - 0x03007968
const Gfx coin_seg3_dl_red_front[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_front),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007968 - 0x03007990
const Gfx coin_seg3_dl_red_tilt_right[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_right),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x03007990 - 0x030079B8
const Gfx coin_seg3_dl_red_side[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_side),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

// 0x030079B8 - 0x030079E0
const Gfx coin_seg3_dl_red_tilt_left[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, coin_seg3_texture_tilt_left),
    gsSPDisplayList(coin_seg3_sub_dl_begin),
    gsSPVertex(coin_seg3_vertex_red, 4, 0),
    gsSPBranchList(coin_seg3_sub_dl_end),
};

#endif
