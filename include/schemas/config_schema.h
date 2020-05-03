#ifndef CONFIG_SCHEMA_H
#define CONFIG_SCHEMA_H

#include <nlohmann/json.hpp>

using namespace nlohmann;

static const json CONFIG_SCHEMA = 
{
	{"$schema", "http://json-schema.org/draft-07/schema#"},
	{"title", "Game config"},
	{"properties", {
		{"game_name", {
			{"description", "Name of the game"},
			{"type", "string"}
		}},
		{"window_width", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 100}
		}},
		{"window_height", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 100}
		}},
		{"game_width", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 100}
		}},
		{"game_height", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 100}
		}}
	}},
	{"required", {
		"game_name",
		"window_width",
		"window_height",
		"game_width",
		"game_height"
	}},
	{"type", "object"}
};

#endif