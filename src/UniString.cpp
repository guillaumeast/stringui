#include "UniString.hpp"

// libunistring lib → unicode-aware width
#include <unistr.h>
#include <uniwidth.h>

static string _clean(const string &input);
static size_t _get_width(const string &input);

// --- CONSTRUCTOR ---

UniString::UniString(const std::string &input)
    : raw(input),
      visible(_clean(input)),
      width(_get_width(visible)),
      height(UniString::count("\n", raw) + 1)
{}

// --- PUBLIC ---

size_t UniString::count(const string& value, const string& str)
{
    if (value.empty()) return 0;

    size_t count = 0;
    size_t position = 0;
    while ((position = str.find(value, position)) != string::npos) {
        ++count;
        position += value.length();
    }

    return count;
}

string UniString::join(const vector<string> &strings, const string &separator)
{
    if (strings.empty()) return "";

    string result = strings[0];
    for (size_t i = 1; i < strings.size(); ++i)
    {
        result += separator + strings[i];
    }

    return result;
}

string UniString::join(const vector<UniString> &unistrings, const string &separator)
{
    if (unistrings.empty()) return "";

    string result = unistrings[0].raw;
    for (size_t i = 1; i < unistrings.size(); ++i)
    {
        result += separator + unistrings[i].raw;
    }

    return result;
}

vector<string> UniString::split(const string &str, const string &separator)
{
    vector<string> result;
    size_t separator_length = separator.length();
    size_t start = 0;

    while (true) {
        size_t position = str.find(separator, start);
        if (position == string::npos) break;

        result.push_back(str.substr(start, position - start));
        start = position + separator_length;
    }

    result.push_back(str.substr(start));
    return result;
}

string UniString::repeat(const size_t count, const string &str, const string &separator)
{
    if (count == 0) return "";

    string result = str;
    for (size_t i = 1; i < count; ++i) {
        result += separator + str;
    }

    return result;
}

// --- PRIVATE ---

// Remove ANSI escape sequences
static string _clean(const string &input)
{
    string output;
    size_t i = 0;

    while (i < input.length()) {
        if (input[i] == '\033' && i + 1 < input.length() && input[i + 1] == '[') {
            i += 2;
            while (i < input.length() && !(input[i] >= '@' && input[i] <= '~')) {
                i++;
            }
            if (i < input.length()) i++;
        } else {
            output += input[i++];
        }
    }

    return output;
}

// Return display width (unicode-aware)
static size_t _get_width(const string &input)
{
    const uint8_t *utf8_cast = reinterpret_cast<const uint8_t *>(input.c_str());

    int width = u8_width(utf8_cast, input.length(), "UTF-8");

    return (width < 0) ? 0 : static_cast<size_t>(width);
}

