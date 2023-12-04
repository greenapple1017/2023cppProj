#ifndef STAGE_H
#define STAGE_H

#include "Question.h"
#include <vector>
#include <string>

class Stage {
protected:
    std::vector<Question> questions;
    int score;

public:
    // Default constructor
    Stage() : score(0) {}

    // This constructor is used in EasyStage and HardStage. Not TournamentStage. 
    Stage(const std::vector<Question> &questions);

    // Pure virtual function to get score for each stage
    virtual int getScore() const = 0;

    // Pure virtual function to get maximum score for each stage to calculate percentage
    virtual int maxScore() const = 0;

    // Pure virtual function to play different mode for each stage
    virtual bool playStage() = 0;

    // Destructor
    virtual ~Stage() {}
};

#endif //STAGE_H
