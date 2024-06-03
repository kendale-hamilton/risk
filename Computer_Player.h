#pragma once
#include "Player.h"
class Computer_Player :
	public Player
{
public:
	Computer_Player(int, int, int);
	const std::string& get_name() const { return "Computer " + std::to_string(computer_num); }
	std::string to_string() const;
	void claim_region(const std::vector<Region*>&);
	void proliferate();
private:
	int computer_num;
};


