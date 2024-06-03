#include "Game.h"
#include<iostream>
#include<fstream>

std::vector<Region*> Game::get_unclaimed_vec() const {
	std::vector<Region*> out;
	for (Region* r : board) {
		if (r->get_owner_ptr() == nullptr) {
			out.push_back(r);
		}
	}
	return out;
}

std::string Game::get_unclaimed_strings(const std::vector<Region*>& vec) const {
	std::string out;
	for (int i = 0; i < vec.size(); i++) {
		out += std::to_string(i) + ": ";
		out += vec[i]->get_name() + '\n';
	}
	return out;

}

void Game::print_players() const {
	std::cout << "Players:\n";
	for (Player* p : players) {
		std::cout << p->to_string();
	}
}

void Game::print_board() const {
	std::cout << "Board:\n";
	for (Region* r : board) {
		std::cout << r->to_string();
	}
}

void Game::print_deck() const {
	std::cout << "Cards:\n";
	for (Card* c : deck) {
		std::cout << c->to_string();
	}
}

Game::Game() {
	srand((unsigned)time(NULL));
	std::cout << "Welcome to risk!\n";
	bool invalid = true;
	while (invalid) {
		std::cout << "Please enter the number of players: ";
		std::string input;
		std::cin >> input;
		if (1 >= std::stoi(input)) {
			std::cout << "Not enough players! (2-6 only)\n";
		}
		else if (6 < std::stoi(input)) {
			std::cout << "Too many players! (2-6 only)\n";
		}
		else {
			invalid = false;
			player_count = std::stoi(input);
		}
	}
	deck = {};
	players = {};
	board = {};
	//borders
	if (player_count == 6) { starting_troops = 20; }
	else if (player_count == 5) { starting_troops = 25; }
	else if (player_count == 4) { starting_troops = 30; }
	else if (player_count == 3) { starting_troops = 35; }
	else if (player_count == 2) { starting_troops = 40; }

	populate_players();
	populate_board();
	populate_deck();

	claiming_phase();
	proliferate_phase();

	std::cout << "Thanks for playing risk!\n";
}

void Game::populate_players() {
	int troops = get_starting_troops();
	int computer_count = 1;
	for (int i = 0; i < player_count; i++) {
		std::string player_name;
		std::cout << "Enter player " << i + 1 << "'s name (enter c for a computer player): ";
		std::cin >> player_name;
		if (player_name != "c") {
			Human_Player* h = new Human_Player(player_name, i + 1, troops);
			//std::cout << "Adding " << player_name << " to game.\n";
			players.push_back(h);
		}
		else {
			Computer_Player* c = new Computer_Player(i + 1, computer_count, troops);
			//std::cout << "Adding Computer " << computer_count << " to game.\n";
			players.push_back(c);
			computer_count++;
		}
	}
}

void Game::populate_board() {
	std::ifstream board_data("risk_regions.txt");

	std::string region;
	while (!board_data.eof()) {
		getline(board_data, region);
		int index = region.find(',');
		std::string continent = region.substr(index + 2, region.size() - (index + 2));
		std::string region_name = region.substr(0, index);
		//std::cout << "Adding " << region_name << " to board.\n";
		Region* r = new Region(continent, region_name);
		board.push_back(r);
	}

	board_data.close();
}

void Game::populate_deck() {
	std::cout << "Populating deck...\n";
	for (int i = 0; i < board.size(); i++) {
		Troop_Type t;
		if (i % 3 == 0) {
			deck.push_back(new Card(Infantry, *board[i]));
		}
		else if (i % 3 == 1) {
			deck.push_back(new Card(Calvary, *board[i]));
		}
		else if (i % 3 == 2) {
			deck.push_back(new Card(Artillery, *board[i]));
		}
	}
}

void Game::claiming_phase() {
	std::cout << "Entering the Claiming Phase.\n";
	bool placing = true;
	while (placing) {
		for (Player* p : players) {
			std::vector<Region*> unclaimed = get_unclaimed_vec();
			if (unclaimed.size() != 0) {
				std::cout << "It is " << p->get_name() << "'s turn.\n";
				p->claim_region(unclaimed);
			}
			else {
				placing = false;
				break;
			}
		}
	}
	std::cout << "Setup Claiming complete!\n";
}

void Game::proliferate_phase() {
	std::cout << "Entering Proliferation Phase.\n";
	for (Player* p : players) {
		std::cout << "It is " << p->get_name() << "'s turn.\n";
		p->proliferate();
	}
	std::cout << "Proliferation complete!\n";
}
