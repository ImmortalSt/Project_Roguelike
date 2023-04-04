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
public:

	Field* GetField() {
		return field;
	}

	Map(Field* _field, Player* _player, std::vector<Enemy>* _enemies) {
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
			if ((field->GetCellState(player_->GetY(), player_->GetX() - 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != emptyC) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() - 1);
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() + 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != emptyC) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(player_->GetY() - 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != emptyC) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() - 1);
			}
		}
		else if (side == 'd') {

			if ((field->GetCellState(player_->GetY() + 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != emptyC) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() + 1);
			}
		}
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}

	void MoveEnemy(int id, char side) {

		Enemy* e = &enemies->at(id);

		if (side == 'l') {
			if ((field->GetCellState(e->GetY(), e->GetX() - 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() - 1) != emptyC) && (field->GetCellState(e->GetY(), e->GetX() - 1) != player) && (field->GetCellState(e->GetY(), e->GetX() - 1) != enemy)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() - 1);
				std::cout << e->GetX();
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(e->GetY(), e->GetX() + 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() + 1) != emptyC) && (field->GetCellState(e->GetY(), e->GetX() + 1) != player) && (field->GetCellState(e->GetY(), e->GetX() + 1) != enemy)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(e->GetY() - 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() - 1, e->GetX()) != emptyC) && (field->GetCellState(e->GetY() - 1, e->GetX()) != player) && (field->GetCellState(e->GetY() - 1, e->GetX()) != enemy)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() - 1);
			}
		}
		else if (side == 'd') {
			if ((field->GetCellState(e->GetY() + 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() + 1, e->GetX()) != emptyC) && (field->GetCellState(e->GetY() + 1, e->GetX()) != player) && (field->GetCellState(e->GetY() + 1, e->GetX()) != enemy)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() + 1);
			}
		}
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);

	}

	int GetCatchByEnemy() {
		int enemy_id = 0;
		int check = 0;
		for (auto en : *enemies) {
			int x = en.GetX();
			int y = en.GetY();
			if ((field->GetCellState(y, x - 1) == player) || (field->GetCellState(y, x + 1) == player) || (field->GetCellState(y + 1, x - 1) == player) || (field->GetCellState(y + 1, x) == player) || (field->GetCellState(y + 1, x + 1) == player) || (field->GetCellState(y - 1, x - 1) == player) || (field->GetCellState(y - 1, x) == player) || (field->GetCellState(y - 1, x + 1) == player)) {
				check = 1;
				break;
			}
			enemy_id++;
		}
		if (check == 0) {
			return -1;
		}
		else {
			return enemy_id;
		}

	}

	Field RebuildFieldWithFOV() {
		int x = player_->GetX();
		int y = player_->GetY();
		Field pole = Field(field->GetHeight(), field->GetWidth());
		for (int i = 0; i <= 7; i++) {
			int n;
			switch (i) {
			case 0:
				n = 7;
				break;
			case 1:
				n = 7;
				break;
			case 2:
				n = 6;
				break;
			case 3:
				n = 5;
				break;
			case 4:
				n = 4;
				break;
			case 5:
				n = 3;
				break;
			case 6:
				n = 2;
				break;
			case 7:
				n = 1;
				break;
			}
			if ((y + i) <= field->GetHeight()) {
				int l, r;
				for (int j = 1; j <= n; j++) {
					if (x - j >= 0) {
						l = x - j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (x + j <= field->GetWidth()) {
						r = x + j;
					}
				}
				for (int k = l; k <= r; k++) {
					pole.SetCell(y + i, k, field->GetCellState(y + i, k));
				}
			}

			if (y - i >= 0) {
				int l, r;
				for (int j = 1; j <= n; j++) {
					if (x - j >= 0) {
						l = x - j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (x + j <= field->GetWidth()) {
						r = x + j;
					}
				}
				for (int k = l; k <= r; k++) {
					pole.SetCell(y - i, k, field->GetCellState(y - i, k));
				}
			}
		}
		return pole;


	}

};






#endif