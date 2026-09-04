#include "I18n.h"
#include "logger.hpp"

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

namespace Relight::I18n
{
	namespace
	{
		// English source string -> translated string.
		std::unordered_map<std::string, std::string> g_map;
	}

	void Load()
	{
		const std::filesystem::path kJsonPath = L"Data/SKSE/Plugins/Relight.json";

		std::error_code ec;
		if (!std::filesystem::is_regular_file(kJsonPath, ec)) {
			logger::info("Relight.json not found; using English UI text.");
			return;
		}

		try {
			std::ifstream f(kJsonPath);
			nlohmann::json root;
			f >> root;
			// Translation strings live under the "strings" object.
			const auto& strings = root.contains("strings") ? root.at("strings") : root;
			for (auto it = strings.begin(); it != strings.end(); ++it) {
				if (it.value().is_string()) {
					g_map[it.key()] = it.value().get<std::string>();
				}
			}
			logger::info("Loaded {} translation(s) from Relight.json.", g_map.size());
		} catch (const std::exception& e) {
			logger::warn("Failed to parse Relight.json: {} — using English UI text.", e.what());
			g_map.clear();
		}
	}

	const char* Get(std::string_view a_str)
	{
		if (a_str.empty()) {
			return a_str.data();
		}
		if (auto it = g_map.find(std::string{ a_str }); it != g_map.end() && !it->second.empty()) {
			return it->second.c_str();
		}
		return a_str.data();
	}
}
