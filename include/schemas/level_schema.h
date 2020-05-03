#ifndef LEVEL_SCHEMA_H
#define LEVEL_SCHEMA_H

#include <nlohmann/json.hpp>

using namespace nlohmann;

static const json LEVEL_SCHEMA = 
{
	{"$schema", "http://json-schema.org/draft-07/schema#"},
	{"title", "Game level schema"},
    {"type", "object"},
	{"properties", {
		{"level_name", {
			{"description", "Name of the level"},
			{"type", "string"}
		}},
        {"level_order",{
            {"type", "integer"},
            {"minimum", 1}
        }},
        {"init_lifepoints",{
            {"description", "Lifepoints to add on this level"},
            {"type", "integer"},
            {"minimum", 0}
        }},
		{"asteroids_props", {
			{"description", "Properties of asteroids"},
			{"type", "object"},
            {"properties", {
                {"BIG",{{"$ref","#/definitions/asteroidProps"}}},
                {"MEDIUM",{{ "$ref","#/definitions/asteroidProps"}}},
                {"SMALL",{{"$ref","#/definitions/asteroidProps"}}}
            }},
            {"required",{
                "BIG", "MEDIUM", "SMALL"
            }}
		}},
        {"ship_config",{
            {"description", "Initial configuration of the ship"},
            {"type","object"},
            {"properties",{
                {"init_position",{{"$ref", "#/definitions/position"}}},
                {"color",{{"$ref","#/definitions/color"}}},
                {"init_velocity",{{"$ref", "#/definitions/vector"}}},
                {"vertices",{
                    {"description", "List of vertices to create a ship"},
                    {"type","array"},
                    {"items",{{"$ref","#/definitions/vector"}}}
                }},
                {"angle_acc",{
                    {"type","number"},
                    {"minimum",0}
                }},
                {"collider_radius",{
                    {"type","number"},
                    {"minimum",0}
                }},
                {"init_angle",{
                    {"type","number"},
                    {"minimum", 0}
                }},
                {"acc",{
                    {"type","number"},
                    {"minimum",0}
                }},
                {"gun_config",{{"$ref","#/definitions/gun_config"}}}
            }}
        }},
        {"env_resistance",{
            {"description", "Resistance coefficient of the environment"},
            {"type","number"},
            {"minimum",0}
        }}
	}},
	{"required", {
		"level_name",
        "level_order",
        "init_lifepoints",
		"asteroids_props",
		"ship_config",
		"env_resistance"
	}},
    {"definitions",{
        {"asteroidProps",{
            {"type", "object"},
            {"properties",{
                {"amount",{
                   {"type", "integer"},
                   {"minimum", 0}
                }},
                {"min_radius",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"max_radius",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"granularity",{
                   {"type", "integer"},
                   {"minimum", 0}
                }},
                {"min_angle_vary",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"max_angle_vary",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"max_velocity",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"max_angle_velocity",{
                   {"type", "number"},
                   {"minimum", 0}
                }},
                {"min_nb_split",{
                   {"type", "integer"},
                   {"minimum", 0}
                }},
                {"max_nb_split",{
                   {"type", "integer"},
                   {"minimum", 0}
                }},
                {"color",{{"$ref","#/definitions/color"}}}
            }},
            {"required", {
                "min_radius",
                "max_radius",
                "granularity",
                "min_angle_vary",
                "max_angle_vary",
                "max_velocity",
                "max_angle_velocity",
                "min_nb_split",
                "max_nb_split",
                "color"
            }}
        }},
        {"color",{
            {"type","array"},
            {"minItems", 3},
            {"maxItems", 3},
            {"items",{
                {"type","integer"},
                {"minimum", 0},
                {"maximum", 255}
            }}
        }},
        {"vector",{
            {"type", "object"},
            {"properties",{
                {"x",{
                    {"type", "number"}
                }},
                {"y",{
                    {"type", "number"}
                }}
            }}
        }},
        {"position",{
            {"type", "object"},
            {"properties",{
                {"x",{
                    {"type", "number"},
                    {"minimum", 0}
                }},
                {"y",{
                    {"type", "number"},
                    {"minimum", 0}
                }}
            }}
        }},
        {"gun_config",{
            {"type", "object"},
            {"properties",{
                {"bullets_radius",{
                    {"type", "number"},
                    {"minimum", 0}
                }},
                {"bullets_vel",{
                    {"type", "number"},
                    {"minimum", 0}
                }},
                {"bullets_ttl",{
                    {"type", "number"},
                    {"minimum", 0}
                }},
                {"cooldown",{
                    {"type", "number"},
                    {"minimum", 0}
                }},
                {"bullets_color",{{"$ref", "#/definitions/color"}}}
            }}
        }}
    }}
};

#endif