#ifndef HARDSTAGE_H
#define HARDSTAGE_H

#include "Stage.h"

class HardStage : public Stage {
public:
    HardStage(const std::vector<Question> &questions);

    // In this HardStage, this method plays a quiz game which reviews our advanced C++ class(week8 ~ week14)
    // For each question, there are total three hints
    // Unlike from EasyStage, you'll lose your point if you miss three hints
    bool playStage() override;

    // 5x weighted point to this HardStage 
    int getScore() const override; 
    int maxScore() const override; 
};

#endif //HARDSTAGE_H 
