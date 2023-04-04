#include "Assets.h"

static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

std::vector<std::wstring> Assets::ReadAsset(std::string name)
{
    if (_json == 0) Init();

    auto asset = _json[name];
    std::vector<std::wstring> result;

    for (auto line: asset)
    {
        result.push_back(converter.from_bytes(line.get<std::string>().c_str()));
    }
    
    return result;
}

void Assets::Init()
{
    _file.open("src\\components\\Screen\\Assets\\Assets.json");
    _file >> _json;

    _assets[AssetsName::Test] = ReadAsset("Test");
    _assets[AssetsName::Zombie_Waek] = ReadAsset("Zombie_Waek");
    _assets[AssetsName::Zombie_Common] = ReadAsset("Zombie_Common");
    _assets[AssetsName::ZombieMutant] = ReadAsset("ZombieMutant");
    _assets[AssetsName::Player1] = ReadAsset("Player1");
    _assets[AssetsName::Player2] = ReadAsset("Player2");
    _assets[AssetsName::Player3] = ReadAsset("Player3");
    _assets[AssetsName::Medkit] = ReadAsset("Medkit");
}

std::vector<std::wstring> Assets::GetAsset(AssetsName name)
{
	return _assets[name];
}