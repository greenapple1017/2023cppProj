#ifndef HARDSTAGE_H
#define HARDSTAGE_H

#include "Stage.h"

class HardStage : public Stage {
public:
    HardStage(const std::vector<Question> &questions);
    bool playStage() override;
    int getScore() const override; 
    int maxScore() const override; 
};

#endif //HARDSTAGE_H 
