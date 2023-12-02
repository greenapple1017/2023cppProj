#ifndef EASYSTAGE_H
#define EASYSTAGE_H

#include "Stage.h"

class EasyStage : public Stage {
public:
    using Stage::Stage;
    bool playStage() override;
};

#endif // EASYSTAGE_H
