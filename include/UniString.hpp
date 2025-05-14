#pragma once

#include "types.hpp"

class UniString {
public:
    string raw = "";
    string visible = "";
    size_t width = 0;
    size_t height = 1;

    // --- CONSTRUCTORS ---

    UniString() = default;
    UniString(const string &input);

    // --- METHODS ---

    static size_t count(const string& value, const string& str);
    static string repeat(const size_t count, const string &str, const string &separator = "");
    static string join(const vector<string> &strings, const string &separator = "");
    static string join(const vector<UniString> &texts, const string &separator = "");
    static vector<string> split(const string &str, const string &separator);
};

