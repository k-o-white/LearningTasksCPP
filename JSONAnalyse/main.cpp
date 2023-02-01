#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

void createJSON()
{
    nlohmann::json dict;
    std::ofstream jsonFile("movies.json");

    dict["Scarface"]["Country"] = "USA";
    dict["Scarface"]["Release Year"] = "1983";
    dict["Scarface"]["Studio"] = "Universal Pictures";
    dict["Scarface"]["Directed by"] = "Brian De Palma";
    dict["Scarface"]["Produced by"] = "Martin Bregman";
    dict["Scarface"]["Starring"]["Al Pacino"] = "Tony Montana";
    dict["Scarface"]["Starring"]["Steven Bauer"] = "Manny Ray";
    dict["Scarface"]["Starring"]["Michelle Pfeiffer"] = "Elvira";
    dict["Scarface"]["Starring"]["Mary Elizabeth Mastrantonio"] = "Gina";
    dict["Scarface"]["Starring"]["Robert Loggia"] = "Frank Lopez";

    dict["The Godfather Part II"]["Country"] = "USA";
    dict["The Godfather Part II"]["Release Year"] = "1974";
    dict["The Godfather Part II"]["Studio"] = "Paramount Pictures";
    dict["The Godfather Part II"]["Directed by"] = "Francis Ford Coppola";
    dict["The Godfather Part II"]["Produced by"] = "Francis Ford Coppola";
    dict["The Godfather Part II"]["Starring"]["Al Pacino"] = "Michael Corleone";
    dict["The Godfather Part II"]["Starring"]["Robert Duvall"] = "Tom Hagen";
    dict["The Godfather Part II"]["Starring"]["Diane Keaton"] = "Kay Adams-Corleone";
    dict["The Godfather Part II"]["Starring"]["Robert De Niro"] = "Vito Corleone";

    dict["Taxi Driver"]["Country"] = "USA";
    dict["Taxi Driver"]["Release Year"] = "1976";
    dict["Taxi Driver"]["Studio"] = "Bill/Phillips Productions";
    dict["Taxi Driver"]["Directed by"] = "Martin Scorsese";
    dict["Taxi Driver"]["Produced by"] = {"Michael Phillips", "Julia Phillips"};
    dict["Taxi Driver"]["Starring"]["Robert De Niro"] = "Travis Bickle";
    dict["Taxi Driver"]["Starring"]["Jodie Foster"] = "Iris Steensma";
    dict["Taxi Driver"]["Starring"]["Cybill Shepherd"] = "Betsy";
    dict["Taxi Driver"]["Starring"]["Harvey Keitel"] = "Matthew \"Sport\" Higgins";

    dict["The Devil's Advocate"]["Country"] = "USA";
    dict["The Devil's Advocate"]["Release Year"] = "1997";
    dict["The Devil's Advocate"]["Studio"] = "Regency Enterprises";
    dict["The Devil's Advocate"]["Directed by"] = "Taylor Hackford";
    dict["The Devil's Advocate"]["Produced by"] = {"Arnon Milchan", "Arnold Kopelson", "Anne Kopelson"};
    dict["The Devil's Advocate"]["Starring"]["Keanu Reeves"] = "Kevin Lomax";
    dict["The Devil's Advocate"]["Starring"]["Al Pacino"] = "John Milton / Satan";
    dict["The Devil's Advocate"]["Starring"]["Charlize Theron"] = "Mary Ann Lomax";
    dict["The Devil's Advocate"]["Starring"]["Jeffrey Jones"] = "Eddie Barzoon";
    dict["The Devil's Advocate"]["Starring"]["Judith Ivey"] = "Alice Lomax";


    jsonFile << dict;
    jsonFile.close();
}

int main()
{
    createJSON();
    std::ifstream jsonFile("movies.json");
    if (jsonFile.is_open())
    {
        nlohmann::json jsonDict;
        jsonFile >> jsonDict;
        jsonFile.close();
        std::string name;
        std::cout << "Input actor's name: ";
        std::getline(std::cin, name);

        bool found = false;
        for (auto it = jsonDict.begin(); it != jsonDict.end(); ++it)
        {
            auto cast = it.value().at("Starring");
            auto actor = cast.find(name);

            if (actor != cast.end())
            {
                if (!found)
                {
                    std::cout << name << " appeared in:\n";
                    found = true;
                }

                auto role = to_string(*actor);
                role = role.substr(1, role.length() - 2);
                std::cout << "\"" << it.key() << "\" as " << role << "." << std::endl;
            }
        }

        if (!found)
            std::cout << "Not found." << std::endl;
    }
    else
    {
        std::cout << "Json file not found." << std::endl;
    }
    return 0;
}


