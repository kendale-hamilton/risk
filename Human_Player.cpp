#include "Human_Player.h"
#include<iostream>

Human_Player::Human_Player(const std::string& name, int player_number, int starting_troops) {
	setup_player(starting_troops, player_number);
	this->name = name;
}

std::string Human_Player::to_string() const {
	std::string out = Player::to_string();
	out += "	Nickname: " + name + '\n';
	return out;
}

void Human_Player::claim_region(const std::vector<Region*>& vec) {
	std::cout << "You currently control the following regions:\n" << get_regions_string();
	std::cout << "The following regions are still available to be claimed:\n";
	std::string unclaimed;
	for (int i = 0; i < vec.size(); i++) {
		unclaimed += std::to_string(i) + ": " + vec[i]->get_name() + '\n';
	}
	std::cout << unclaimed;
	std::cout << "Please enter the index of the reigon you would like to claim: ";
	std::string selection;
	std::cin >> selection;
	int index = std::stoi(selection);
	update_ownership(*vec[index]);
	place_troops(1, *vec[index]);
	std::cout << "You have claimed " << vec[index]->get_name() << '\n';
	std::cout << "You have " << get_troops_held() << " troops left to deploy.\n";
}

void Human_Player::proliferate() {
	while (get_troops_held() != 0) {
		std::cout << "You control the following regions:\n";
		std::string regions_info;
		std::vector<Region*> vec = get_regions();
		for (int i = 0; i < vec.size(); i++) {
			regions_info += std::to_string(i) + ": " + vec[i]->get_name();
			regions_info += " - " + std::to_string(vec[i]->get_troops()) + '\n';
		}
		std::cout << regions_info;
		int held = get_troops_held();
		std::cout << "You have " << held << " troops to place.\n";
		std::string selection;
		std::cout << "Please enter the index of the region you would like to place troops in: ";
		std::cin >> selection;
		int index = std::stoi(selection);
		std::cout << "How many troops would you like to place in " << vec[index]->get_name() << "? ";
		bool invalid = true;
		int troops;
		while (invalid) {
			std::string input;
			std::cin >> input;
			int to_place = std::stoi(input);
			if (0 < to_place && to_place <= held) {
				invalid = false;
				troops = to_place;
			}
			else if (to_place < 1) {
				std::cout << "Not enough troops! ";
			}
			else if (to_place > held) {
				std::cout << "Too many troops! You only have " << get_troops_held() << " troops! ";
			}
		}
		place_troops(troops, *vec[index]);
		std::cout << "Placed " << troops << " troops in " << vec[index]->get_name() << '\n';
	}
}