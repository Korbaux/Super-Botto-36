#define fuck.h
#ifdef IA8_30FPS_COINS
// 0x1600013C
const GeoLayout yellow_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 50),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160001A0
const GeoLayout yellow_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000200
const GeoLayout blue_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000264
const GeoLayout blue_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160002C4
const GeoLayout red_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000328
const GeoLayout red_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160002C4
const GeoLayout silver_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000328
const GeoLayout silver_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_0),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_1),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_2),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_3),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_4),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_5),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_6),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_secret_7),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

#else
// 0x1600013C
const GeoLayout yellow_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 50),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160001A0
const GeoLayout yellow_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_yellow_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000200
const GeoLayout blue_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000264
const GeoLayout blue_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_blue_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x160002C4
const GeoLayout red_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000328
const GeoLayout red_coin_no_shadow_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(8, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_front),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_right),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_side),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_left),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, coin_seg3_dl_red_tilt_left),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
#endif
