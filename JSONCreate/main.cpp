#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

int main()
{
    nlohmann::json dict;
    std::ofstream jsonFile("movie.json");
    dict["Name"] = "Scarface";
    dict["Country"] = "USA";
    dict["Release Year"] = "1983";
    dict["Studio"] = "Universal Pictures";
    dict["Director"] = "Brian De Palma";
    dict["Producer"] = "Martin Bregman";
    dict["Starring"] = {
            {"Al Pacino", "Tony Montana"},
            {"Steven Bauer", "Manny Ray"},
            {"Michelle Pfeiffer", "Elvira"},
            {"Mary Elizabeth Mastrantonio", "Gina"},
            {"Robert Loggia", "Frank Lopez"}
    };
    jsonFile << dict;
    jsonFile.close();
    return 0;
}
