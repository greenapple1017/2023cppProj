#include "TournamentStage.h"
#include <iostream>
#include <cstdlib>

TournamentStage::TournamentStage(const std::vector<std::string> &professors, const std::string &finalProfessor)
    : Stage(std::vector<Question>()), professors(professors), finalProfessor(finalProfessor) {}

void TournamentStage::presentChoices(const std::vector<std::string> &choices, std::string &picked) {
    std::cout << "Choose a professor:\n";
    for (size_t i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }

    int choice;
    std::cin >> choice;
    --choice;
    if (choice >= 0 && choice < static_cast<int>(choices.size())) {
        picked = choices[choice];
    } else {
        std::cout << "You are F\n";
        std::exit(EXIT_FAILURE);
    }
}

bool TournamentStage::playStage() {
    std::string roundName = "Quarterfinals";

    while (professors.size() > 1) {
        std::cout << roundName << ":\n";
        std::vector<std::string> nextRoundProfessors;

        for (size_t i = 0; i < professors.size(); i += 2) {
            std::vector<std::string> pair = {professors[i], professors[i + 1]};
            std::string pickedProfessor;
            presentChoices(pair, pickedProfessor);
            nextRoundProfessors.push_back(pickedProfessor);
        }

        professors = nextRoundProfessors;

        if (professors.size() == 4) {
            roundName = "Semifinals";
        } else if (professors.size() == 2) {
            roundName = "Final";
        }
    }

    std::cout << "The final professor is: " << professors[0] << "\n";

    if (professors[0] == finalProfessor) {
        score += 10;  
        return true;
    }

    return false;
}




