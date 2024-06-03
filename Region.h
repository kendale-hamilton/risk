#pragma once
#include<string>

class Region
{
public:
	Region(std::string, std::string);
	std::string get_continent() const { return continent; }
	class Player* get_owner_ptr() const { return owner; }
	int get_troops() const { return troops; }
	const std::string& get_name() const { return name; }
	void set_owner(class Player* p) { owner = p; }
	void set_troops(int t) { troops = t; }
	void add_troops(int t) { troops += t; }
	std::string to_string() const;
private:
	std::string continent;
	class Player* owner;
	int troops;
	std::string name;
};


