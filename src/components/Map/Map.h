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
	std::vector<Enemy*>* enemies;
public:
	Player* GetPlayer() {
		return player_;
	}


	std::vector<Enemy*>* GetEnemies() {
		return enemies;
	}


	Field* GetField() {
		return field;
	}

	Map(Field *_field, Player *_player, std::vector<Enemy*> *_enemies) {
		field = _field;
		player_ = _player;
		field_copy = *_field;
		enemies = _enemies;
		field->SetCell(player_->GetY(), player_->GetX(), player);
		for (auto en : *enemies) {
			field->SetCell(en->GetY(), en->GetX(), enemy);
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
			if (field->GetCellState(en->GetY(), en->GetX()) != enemy_dead) {
				field->SetCell(en->GetY(), en->GetX(), enemy);
			}
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}

	void MoveEnemy(int id, char side) {

		Enemy* e = enemies->at(id);
		if (field->GetCellState(e->GetY(), e->GetX()) == enemy) {
			if (side == 'l') {
				if ((field->GetCellState(e->GetY(), e->GetX() - 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() - 1) != emptyC) && (field->GetCellState(e->GetY(), e->GetX() - 1) != player)) {
					field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
					e->SetX(e->GetX() - 1);
					//std::cout << e->GetX();
				}
			}
			else if (side == 'r') {
				if ((field->GetCellState(e->GetY(), e->GetX() + 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() + 1) != emptyC) && (field->GetCellState(e->GetY(), e->GetX() + 1) != player)) {
					field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
					e->SetX(e->GetX() + 1);
				}
			}
			else if (side == 'u') {
				if ((field->GetCellState(e->GetY() - 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() - 1, e->GetX()) != emptyC) && (field->GetCellState(e->GetY() - 1, e->GetX()) != player)) {
					field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
					e->SetY(e->GetY() - 1);
				}
			}
			else if (side == 'd') {
				if ((field->GetCellState(e->GetY() + 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() + 1, e->GetX()) != emptyC) && (field->GetCellState(e->GetY() + 1, e->GetX()) != player)) {
					field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
					e->SetY(e->GetY() + 1);
				}
			}
			for (auto en : *enemies) {
				if (field->GetCellState(en->GetY(), en->GetX()) != enemy_dead) {
					field->SetCell(en->GetY(), en->GetX(), enemy);
				}
			}
			field->SetCell(player_->GetY(), player_->GetX(), player);

		}
		
	}

	int CheckEnemies() {
		int k = 0;
		for (int i = 0; i < field->GetHeight(); i++) {
			for (int j = 0; j < field->GetWidth(); j++) {
				if (field->GetCellState(i, j) == enemy) {
					k++;
				}
			}
		}
		return k;
	}

	void KillEnemy(int id) {
		Enemy* en = enemies->at(id);
		field->SetCell(en->GetY(), en->GetX(), enemy_dead);
		field_copy.SetCell(en->GetY(), en->GetX(), enemy_dead);
	}

	int GetCatchByEnemy() {
		int enemy_id = 0;
		int check = 0;
		for (auto en : *enemies) {
			int x = en->GetX();
			int y = en->GetY();
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

	Field RebuildFieldWithFOV(int radius) {
		int x = player_->GetX();
		int y = player_->GetY();
		int r = radius;
		vector<int> arr(r + 1);
		for (int i = 0; i < r + 1; i++) {
			arr[i] = r - i + 1;
			arr[0] = arr[1] = r;
		}
		Field pole = Field(field->GetHeight(), field->GetWidth());
		for (int i = 0; i <= r; i++) {
			int n = arr[i];
			if ((y + i) <= field->GetHeight() - 1) {
				int l, r;
				for (int j = 1; j <= n; j++) {
					if (x - j >= 0) {
						l = x - j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (x + j <= field->GetWidth() - 1) {
						r = x + j;
					}
				}
				for (int k = l; k <= r; k++) {
					pole.SetCell(y + i, k, field->GetCellState(y + i, k));
				}
				if (y - i >= 0) {
					for (int k = l; k <= r; k++) {
						pole.SetCell(y - i, k, field->GetCellState(y - i, k));
					}
				}
			}


		}
		return pole;
	}

};

#endif