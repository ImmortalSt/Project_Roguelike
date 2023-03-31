#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>


class Player {
private:
	std::string name;
	int hp;
	int shield;
	int x;
	int y;

public:
	Player() {

	}
	Player(std::string _name, int _hp, int _shield, int _x, int _y) {
		name = _name;
		hp = _hp;
		shield = _shield;
		x = _x;
		y = _y;
	}

	Player(std::string _name) {
		name = _name;
	}

	int GetHP() {
		return hp;
	}

	void TakeDamage(int damage) {
		hp -= damage;
	}

	void AddHP(int _hp) {
		hp += _hp;
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

	void GetSprite() {
		throw std::exception("It is not realized yet");
	}

	void SetX(int _x) {
		x = _x;
	}

	int GetX() {
		return x;
	}

	void SetY(int _y) {
		y = _y;
	}

	int GetY() {
		return y;
	}

	void SetXY(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

#endif

