#ifndef EASYSTAGE_H
#define EASYSTAGE_H

#include "Stage.h"

class EasyStage : public Stage {
public:
    EasyStage(const std::vector<Question> &questions);
    bool playStage() override;
    int getScore() const override; 
    int maxScore() const override;
};

#endif // EASYSTAGE_H
