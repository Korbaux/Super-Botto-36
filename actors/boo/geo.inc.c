#include "src/game/envfx_snow.h"

const GeoLayout boo_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS(LAYER_TRANSPARENT, 0, 0, 0),
			GEO_DISPLAY_LIST(LAYER_ALPHA, boo_001_displaylist_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
