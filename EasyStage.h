#ifndef EASYSTAGE_H
#define EASYSTAGE_H

#include "Stage.h"

class EasyStage : public Stage {
public:
    EasyStage(const std::vector<Question> &questions);

    // In this EasyStage, this method plays a quiz game which reviews our C class(week1 ~ week7)
    // For each question, there are total five hints
    // You never lose your point in this stage 
    bool playStage() override;

    // Give a 3x weighted point to this stage
    int getScore() const override; 
    int maxScore() const override;
};

#endif // EASYSTAGE_H
