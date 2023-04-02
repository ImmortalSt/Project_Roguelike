#ifndef MAP_H
#define MAP_H
#include "../Field/Field.h"
#include "../utills/utils.h"
#include "../Player/Player.h"
#include "../enemies/enemies.h"
class Map {
private:
	Field* field;
	Field field_copy;
	Player* player_;
	std::vector<Enemy>* enemies;
	CellState playerscell;
	std::vector<CellState> enemiescell;
public:
	Map(Field *_field, Player *_player, std::vector<Enemy> *_enemies) {
		field = _field;
		player_ = _player;
		field_copy = *_field;
		enemies = _enemies;
		field->SetCell(player_->GetY(), player_->GetX(), player);
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
	}
	void MovePlayer(char side) {
		if (side == 'l') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() - 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() - 1);
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() + 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(player_->GetY() - 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() - 1);
			}
		}
		else if (side == 'd') {
			
			if ((field->GetCellState(player_->GetY() + 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != empt)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() + 1);
			}
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}

	void MoveEnemy(int id, char side) {
		Enemy* e = &enemies->at(id);

		if (side == 'l') {
			if ((field->GetCellState(e->GetY(), e->GetX() - 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() - 1) != empt)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() - 1);
				std::cout << e->GetX();
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(e->GetY(), e->GetX() + 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() + 1) != empt)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(e->GetY() - 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() - 1, e->GetX()) != empt)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() - 1);
			}
		}
		else if (side == 'd') {
			if ((field->GetCellState(e->GetY() + 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() + 1, e->GetX()) != empt)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() + 1);
			}
		}
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}
};






#endif