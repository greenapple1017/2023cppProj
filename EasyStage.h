#ifndef EASYSTAGE_H
#define EASYSTAGE_H

#include "Stage.h"

class EasyStage : public Stage {
public:
    using Stage::Stage;
    bool playStage() override;
    int getScore() const override { return score * 3; } 
    int maxScore() const override { return questions.size() * 3; }
};

#endif // EASYSTAGE_H
