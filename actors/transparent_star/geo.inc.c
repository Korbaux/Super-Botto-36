#include "src/game/envfx_snow.h"

const GeoLayout transparent_star_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 255, 100),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, transparent_star_Lemon_01_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, transparent_star_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
