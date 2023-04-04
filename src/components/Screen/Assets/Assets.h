#pragma once

#include "../../json/nlohmann/single_include/nlohmann/json.hpp"
#include <fstream>
#include <map>
#include <codecvt>

class Assets {
private:
	static nlohmann::json _json;
	static std::ifstream _file;
	static std::vector<std::wstring> ReadAsset(std::string name);

	static void Init();

public:
	enum class AssetsName {
		Test = 0,
		Zombie_Waek,
		Zombie_Common, 
		ZombieMutant,
		Player1, Player2, Player3,
		Medkit
	};

	static std::vector<std::wstring> GetAsset(AssetsName name);

private:
	static std::map<AssetsName, std::vector<std::wstring>> _assets;
};