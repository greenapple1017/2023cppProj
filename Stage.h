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
    Stage() : score(0) {}
    Stage(const std::vector<Question> &questions);
    virtual int getScore() const = 0;
    virtual int maxScore() const = 0;
    virtual bool playStage() = 0;
    virtual ~Stage() {}
};

#endif 
