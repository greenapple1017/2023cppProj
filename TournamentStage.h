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
    bool playStage();
    void presentChoices(const std::vector<std::string> &choices, std::string &picked);
};

#endif // TOURNAMENTSTAGE_H