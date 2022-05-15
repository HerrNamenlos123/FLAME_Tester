#pragma once

#include "Battery/Fonts/RobotoMedium.h"
#include "Battery/Fonts/FontAwesome6FreeSolid.h"

struct Fonts : public Battery::Fonts {

	// Here you can load any number of fonts to be used throughout the application
	inline static ImFont* robotoMedium = nullptr;
	inline static ImFont* fontAwesomeIcons = nullptr;

	static void load() {
		robotoMedium = ADD_FONT(RobotoMedium, 18);
		fontAwesomeIcons = ADD_FONT(FontAwesome6FreeSolid, 18);
	}
	
};
