#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace Relight::I18n
{
	// Load Data/SKSE/Plugins/Relight.json (if present).
	// Falls back gracefully: all Get() calls return the English string itself
	// when the file is missing or a key is absent.
	void Load();

	// Get translated string by English source string.
	// Returns a_str itself when no translation exists (identity).
	const char* Get(std::string_view a_str);
}

// Macro: wraps a UI string literal so it passes through the translation table.
// Named QLT (Relight) to avoid clashing with single-letter template params
// (e.g. nlohmann json's `T`) that are common in the codebase.
#define QLT(str) (::Relight::I18n::Get(str))
