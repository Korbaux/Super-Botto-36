#include "src/game/envfx_snow.h"

const GeoLayout thwomp_000_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_000_displaylist_mesh_layer_1_mat_override_f3dlite_material_002_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout thwomp_000_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_000_displaylist_mesh_layer_1_mat_override_f3dlite_material_003_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout thwomp_000_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_000_displaylist_mesh_layer_1_mat_override_f3dlite_material_004_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout thwomp_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(0, changeFace),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_000_displaylist_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, thwomp_000_switch_opt1),
			GEO_BRANCH(1, thwomp_000_switch_opt2),
			GEO_BRANCH(1, thwomp_000_switch_opt3),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, thwomp_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
