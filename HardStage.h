#ifndef HARDSTAGE_H
#define HARDSTAGE_H

#include "Stage.h"

class HardStage : public Stage {
public:
    using Stage::Stage; 
    bool playStage() override;
    int getScore() const override { return score * 2; }
    int maxScore() const override { return questions.size() * 2 * 5; } // 2 points per question, 5x weighting
};

#endif 
