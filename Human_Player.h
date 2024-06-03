#pragma once
#include "Player.h"
class Human_Player :
	public Player
{
public:
	Human_Player(const std::string&, int, int);
	const std::string& get_name() const { return name; }
	std::string to_string() const;
	void claim_region(const std::vector<Region*>&);
	void proliferate();
private:
	std::string name;
};

