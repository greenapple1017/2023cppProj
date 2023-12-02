#ifndef HARDSTAGE_H
#define HARDSTAGE_H

#include "Stage.h"

class HardStage : public Stage {
public:
    using Stage::Stage; 
    bool playStage() override;
};

#endif 
