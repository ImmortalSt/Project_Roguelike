#ifndef MAP_H
#define MAP_H
#include "Field.h"
#include "utils.h"
#include "Player.h"
//#include "enemies/enemies.h"
class Map {
private:
	Field* field;
	Player* player_;
	std::vector<int>* enemies;
	CellState playerscell;
public:
	Map(Field *_field, Player *_player, std::vector<int> *_enemies) {
		field = _field;
		player_ = _player;
		enemies = _enemies;
		playerscell = field->GetCellState(player_->GetY(), player_->GetX());
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}
	void MovePlayer(char side) {
		if (side == 'l') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() - 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), playerscell);
				playerscell = field->GetCellState(player_->GetY(), player_->GetX() - 1);
				field->SetCell(player_->GetY(), player_->GetX() - 1, player);
				player_->SetX(player_->GetX() - 1);
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() + 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), playerscell);
				playerscell = field->GetCellState(player_->GetY(), player_->GetX() + 1);
				field->SetCell(player_->GetY(), player_->GetX() + 1, player);
				player_->SetX(player_->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(player_->GetY() - 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), playerscell);
				playerscell = field->GetCellState(player_->GetY() - 1, player_->GetX());
				field->SetCell(player_->GetY() - 1, player_->GetX(), player);
				player_->SetY(player_->GetY() - 1);
			}
		}
		else if (side == 'd') {
			
			if ((field->GetCellState(player_->GetY() + 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), playerscell);
				playerscell = field->GetCellState(player_->GetY() + 1, player_->GetX());
				field->SetCell(player_->GetY() + 1, player_->GetX(), player);
				player_->SetY(player_->GetY() + 1);
			}
		}
	}
};





;
#endif