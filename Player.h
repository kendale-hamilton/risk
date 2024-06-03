#pragma once
#include<string>
#include<vector>
#include "Card.h"
#include "Region.h"

class Player
{
public:
	Player();
	void setup_player(int, int);
	int get_troops_deployed() const { return troops_deployed; }
	int get_troops_held() const { return troops_held; }
	void place_troops(int, Region&);
	const std::vector<Card*>& get_cards() const { return cards; }
	const std::vector<std::string>& get_continents() const { return continents; }
	const std::vector<Region*>& get_regions() const { return regions; }
	std::string get_regions_string() const;
	int get_player_num() const { return player_num; }
	virtual const std::string& get_name() const = 0;
	virtual std::string to_string() const = 0;
	virtual void claim_region(const std::vector<Region*>&) = 0;
	void update_ownership(Region&);
	void take_over_region(Region&, int);
	virtual void proliferate() = 0;
private:
	int troops_deployed;
	int troops_held;
	std::vector<Card*> cards;
	std::vector<std::string> continents;
	std::vector<Region*> regions;
	int player_num;
};

