#pragma once

#include <fstream>
#include <map>
#include <codecvt>
#include "../../json/nlohmann/single_include/nlohmann/json.hpp"

class Assets {
private:
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	nlohmann::json _json;
	std::ifstream _file;
	
	Assets();
	std::vector<std::wstring> Assets::ReadAsset(std::string name);


public:
	enum class AssetsName {
		Test = 0,
		Zombie_Waek,
		Zombie_Common, 
		ZombieMutant,
		Player1, Player2, Player3,
		Medkit, shop
	};

	static Assets* GetInstance();

	std::vector<std::wstring> Assets::GetAsset(AssetsName name);

private:
	std::map<AssetsName, std::vector<std::wstring>> _assets;
};