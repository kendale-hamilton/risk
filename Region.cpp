#include "Region.h"

Region::Region(std::string c, std::string n) {
	continent = c;
	owner = nullptr;
	troops = 0;
	name = n;
}

std::string Region::to_string() const {
	std::string out = name;
	out += ", " + continent;
	out += "\nActive Troops: " + std::to_string(troops) + '\n';
	return out;
}
