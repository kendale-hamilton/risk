#pragma once
#include<string>
#include "Region.h"

enum Troop_Type { Infantry, Calvary, Artillery };

class Card
{
public:
	Card(const Troop_Type& t, const Region& r) : type(t), region(r) {}
	const Troop_Type& get_type() const { return type; }
	const class Region& get_region() const { return region; }
	const std::string& to_string() const;
private:
	Troop_Type type;
	const class Region& region;
};

