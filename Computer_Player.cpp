#include "Computer_Player.h"
#include<iostream>

Computer_Player::Computer_Player(int player_number, int computer_number, int starting_troops) {
	setup_player(starting_troops, player_number);
	computer_num = computer_number;
}

std::string Computer_Player::to_string() const {
	std::string out = Player::to_string();
	out += "	Nickname: " + get_name() + '\n';
	return out;
}

void Computer_Player::claim_region(const std::vector<Region*>& vec) {
	int range = vec.size();
	int index = rand() % range;
	update_ownership(*vec[index]);
	place_troops(1, *vec[index]);
	std::cout << get_name() << " claimed " << vec[index]->get_name() << '\n';
	std::cout << get_name() << " has " << get_troops_held() << " left to deploy.\n";
}

void Computer_Player::proliferate() {
	while (get_troops_held() > 0) {
		int held = get_troops_held();
		std::cout << get_name() << " has " << held << " troops left.\n";
		std::vector<Region*> vec = get_regions();
		int index = rand() % vec.size();
		int troops = 1 + (rand() % 5);
		if (troops > held) {
			troops = held;
		}
		place_troops(troops, *(vec[index]));
		std::cout << get_name() << " placed " << troops << " in " << vec[index]->get_name() << '\n';
	}
}