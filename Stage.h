#ifndef STAGE_H
#define STAGE_H

#include "Question.h"
#include <vector>
#include <string>

class Stage {
protected:
    std::vector<Question> questions;

public:
    Stage() {} 
    Stage(const std::vector<Question> &questions);
    virtual bool playStage() = 0;
    virtual ~Stage() {}
};

#endif 
