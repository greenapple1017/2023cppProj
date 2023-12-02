#include "EasyStage.h"
#include <iostream>
#include <string>

bool EasyStage::playStage() {
    for (auto &q : questions) {
        q.resetHintIndex();
        q.displayQuestion();
        std::string answer;
        std::getline(std::cin, answer);
        if (q.checkAnswer(answer)) {
            std::cout << "correct! Move to the next question.\n";
            continue;
        } else {
            std::cout << "Wrong answer. Hint: " << q.provideHint() << "\n";
        }
    }
    std::cout << "Easy stage is completed\n";
    return true;  
}
