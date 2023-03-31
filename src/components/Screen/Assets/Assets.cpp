#include "Assets.h"

std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

std::vector<std::wstring> Assets::ReadAsset(std::string name)
{
    auto asset = _json[name];
    std::vector<std::wstring> result;

    for (auto line: asset)
    {
        result.push_back(converter.from_bytes(line.get<std::string>().c_str()));
    }

    return result;
}

Assets::Assets()
{
    _file.open("src\\components\\Screen\\Assets\\Assets.json");
    _file >> _json;

    _assets[AssetsName::Test] = ReadAsset("Test");

}

std::vector<std::wstring> Assets::GetAsset(AssetsName name)
{
	return _assets[name];
}