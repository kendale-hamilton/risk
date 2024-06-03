#pragma once
#include<string>
#include<vector>
#include "Region.h"
#include "Card.h"
#include "Player.h"
#include "Human_Player.h"
#include "Computer_Player.h"

class Game
{
public:
	Game();
	const std::vector<Card*>& get_deck() const { return deck; }
	const std::vector<Player*>& get_players() const { return players; }
	const std::vector<Region*>& get_board() const { return board; }
	int get_starting_troops() const { return starting_troops; }
	std::vector<Region*> get_unclaimed_vec() const;
	std::string get_unclaimed_strings(const std::vector<Region*>&) const;
	void populate_players();
	void print_players() const;
	void populate_board();
	void print_board() const;
	void populate_deck();
	void print_deck() const;
	void claiming_phase();
	void proliferate_phase();
private:
	int player_count;
	std::vector<Card*> deck;
	std::vector<Player*> players;
	std::vector<Region*> board;
	// borders, not sure on implementation yet
	int starting_troops;
};
