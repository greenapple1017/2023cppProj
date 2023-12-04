#ifndef TOURNAMENTSTAGE_H
#define TOURNAMENTSTAGE_H

#include "Stage.h"  
#include <vector>
#include <string>

class TournamentStage : public Stage { 
    std::vector<std::string> professors;
    std::string finalProfessor;

public:
    TournamentStage(const std::vector<std::string> &professors, const std::string &finalProfessor);

    // In TournamentStage, this function plays a tournament game to pick your favourite professo
    bool playStage() override;

    // Give a 2x weighted point to this tournament stage
    int getScore() const override;
    int maxScore() const override;

private:
    // Keep track of your choices to perform a tournament  
    void presentChoices(const std::vector<std::string> &choices, std::string &picked);

};

#endif // TOURNAMENTSTAGE_H
