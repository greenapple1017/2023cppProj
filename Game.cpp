#include "Game.h"
#include <iostream>

void Game::addStage(const std::shared_ptr<Stage> &stage) {
    stages.push_back(stage);
}

void Game::play() {
    int totalWeightedScore = 0;
    int totalMaxWeightedScore = 0;
    for (auto &stage : stages) {
        std::cout << "**************************************\n";
        std::cout << "********Starting a new stage**********\n";
        std::cout << "**************************************\n";
        if (!stage->playStage()) {
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            std::cout << "!!!!!!!!!!!!!!!!You failed this course!!!!!!!!!!!!!!\n";
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            return;
        }
        totalWeightedScore += stage->getScore();
        totalMaxWeightedScore += stage->maxScore();
    }

    double weightedAverage = static_cast<double>(totalWeightedScore) / totalMaxWeightedScore;

    if (weightedAverage >= 0.8) {
        std::cout << "Your Grade in this C++ Programming Course is A\n";
    } else if (weightedAverage >= 0.5) {
        std::cout << "Your Grade in this C++ Programming Course is B\n";
    } else {
        std::cout << "Your Grade in this C++ Programming Course is F\n";
    }
}
