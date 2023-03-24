#include "../../json/nlohmann/single_include/nlohmann/json.hpp"
#include <fstream>
#include <map>
#include <codecvt>

class Assets {
private:
	nlohmann::json _json;
	std::ifstream _file;
	std::vector<std::wstring> ReadAsset(std::string name);

public:
	enum class AssetsName {
		Test = 0
	};

	Assets();

	std::vector<std::wstring> GetAsset(AssetsName name);

private:
	std::map<AssetsName, std::vector<std::wstring>> _assets;
};