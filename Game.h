#ifndef GAME_H
#define GAME_H

#include "Stage.h"
#include <vector>
#include <memory>

class Game {
    std::vector<std::shared_ptr<Stage>> stages;

public:
    // Add stages
    void addStage(const std::shared_ptr<Stage> &stage);
    
    // Play the game 
    void play();
};

#endif //GAME_H
