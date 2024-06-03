#include "Card.h"

const std::string& Card::to_string() const {
	std::string out = region.get_name();
	if (type == Infantry) {
		out += " - Infantry";
	}
	else if (type == Calvary) {
		out += " - Calvary";
	}
	else if (type == Artillery) {
		out += " - Artillery";
	}
	out += '\n';
	return out;
}