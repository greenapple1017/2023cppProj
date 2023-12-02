#include "Game.h"
#include <iostream>

void Game::addStage(const std::shared_ptr<Stage> &stage) {
    stages.push_back(stage);
}

void Game::play() {
    for (auto &stage : stages) {
        std::cout << "*****Starting a new stage...**********\n";
        if (!stage->playStage()) {
            std::cout << "F!!!!!!!!!!!!!!\n";
            return;
        }
    }
    std::cout << "Your Grade in this C++ Prograing Course is.....\n";
}
