#include <string>
#include <iostream>
#include <cstdlib>      // std::atoi
#include "StringUI.hpp"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <command> <args>\n";
        return 1;
    }

    const string command = argv[1];
    if (command == "width")
    {
        std::cout << StringUI(argv[2]).width << "\n";
    }
    else if (command == "height")
    {
        std::cout << StringUI(argv[2]).height << "\n";
    }
    else if (command == "clean")
    {
        std::cout << StringUI(argv[2]).visible << "\n";
    }
    else if (command == "split")
    {
        if (argc < 4)
        {
            std::cerr << "Usage: " << argv[0] << " split <string> <separator>\n";
            return 1;
        }

        string str = argv[2];
        string separator = argv[3];

        vector<string> parts = StringUI::split(str, separator);
        for (const auto& part : parts) {
            std::cout << part << "\n";
        }
    }
    else if (command == "repeat")
    {
        if (argc < 4)
        {
            std::cerr << "Usage: " << argv[0] << " repeat <count> <string> [separator]\n";
            return 1;
        }

        size_t count = std::atoi(argv[2]);
        string str = argv[3];
        string separator = (argc >= 5) ? argv[4] : "";

        std::cout << StringUI::repeat(count, str, separator) << "\n";
    }
    else if (command == "count")
    {
        if (argc < 5)
        {
            std::cerr << "Usage: " << argv[0] << " count <value> in <string>\n";
            return 1;
        }

        string value = argv[2];
        string str = argv[4];

        std::cout << StringUI::count(value, str) << "\n";
    }
    else
    {
        std::cerr << "Unknown command: " << command << "\n";
        return 1;
    }

    return 0;
}

