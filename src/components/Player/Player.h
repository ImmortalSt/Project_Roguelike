#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>


class Player {
private:
	std::string name;
	int hp;
	int shield;
	

public:

	Player(std::string _name, int _hp, int _shield) {
		name = _name;
		hp = _hp;
		shield = _shield;
	}

	Player(std::string _name) {
		name = _name;
	}

	int GetHP() {
		return hp;
	}

	void SetHP(int _hp) {
		hp = _hp;
	}

	int GetShield() {
		return shield;
	}

	void SetShield(int _shield) {
		shield = _shield;
	}

	std::string GetName() {
		return name;
	}

	void SetName(std::string _name) {
		name = _name;
	}



};

#endif
