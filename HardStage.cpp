#include "HardStage.h"
#include <iostream>
#include <string>

bool HardStage::playStage() {
    for (auto &q : questions) {
        q.resetHintIndex();  //Reset hints for the new question

        bool questionAnsweredCorrectly = false;
        while (!questionAnsweredCorrectly) {  // Loop until the answer is correct
            q.displayQuestion();
            std::string answer;
            std::getline(std::cin, answer);

            if (q.checkAnswer(answer)) {
                std::cout << "Answer is correct! Move to the next question.\n";
                questionAnsweredCorrectly = true; // Exit the loop and go to next question
            } else {
                std::string detailedHint = q.getDetailedHint();
                std::cout << "Wrong answer. Hint: " << detailedHint << "\n";
            }
        }
    }
    std::cout << "Hard stage completed!!!\n";
    return true;
}
