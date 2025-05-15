#pragma once

#include <string>
#include <vector>
#include <optional>

using string = std::string;
template<typename T> using vector = std::vector<T>;
template<typename T> using opt = std::optional<T>;

class StringUI {
public:
    string raw = "";
    string visible = "";
    size_t width = 0;
    size_t height = 1;

    // --- CONSTRUCTORS ---

    StringUI() = default;
    StringUI(const string &input);

    // --- METHODS ---

    static size_t count(const string& value, const string& str);
    static string repeat(const size_t count, const string &str, const string &separator = "");
    static string join(const vector<string> &strings, const string &separator = "");
    static string join(const vector<StringUI> &texts, const string &separator = "");
    static vector<string> split(const string &str, const string &separator);
};

