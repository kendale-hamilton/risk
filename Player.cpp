#include "Player.h"

Player::Player() {
	troops_deployed = 0;
	troops_held = 0;
	cards = {};
	continents = {};
	regions = {};
	player_num = 0;
}

void Player::setup_player(int held, int player_number) {
	troops_held = held;
	player_num = player_number;
}

void Player::place_troops(int troops, Region& r) {
	troops_deployed += troops;
	troops_held -= troops;
	r.add_troops(troops);
}

std::string Player::get_regions_string() const {
	std::string out;
	for (Region* r : regions) {
		out += r->get_name() + '\n';
	}
	return out;
}

std::string Player::to_string() const {
	std::string out = "Player " + std::to_string(player_num) + ":\n";
	out += "	Troops Deployed: " + std::to_string(troops_deployed) + '\n';
	out += "	Troops Held: " + std::to_string(troops_held) + '\n';
	out += "	Cards in Hand: " + std::to_string(cards.size()) + '\n';
	out += "	Continents Controlled: " + std::to_string(continents.size()) + '\n';
	out += "	Regions Controlled: " + std::to_string(regions.size()) + '\n';
	return out;
}

void Player::take_over_region(Region& r, int troops) {
	r.set_owner(this);
	r.set_troops(troops);
}

void Player::update_ownership(Region& r) {
	r.set_owner(this);
	regions.push_back(&r);
}