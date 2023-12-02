#include "EasyStage.h"
#include <iostream>
#include <string>

bool EasyStage::playStage() {
    std::cout << "This is an Easy Stage. You have 5 hints for each question. Also, You will fail this stage when you got a score below than 25 percent.\n";
     for (auto &q : questions) {
         q.resetHintIndex();  //Reset hints for the new question
         bool questionAnsweredCorrectly = false;
         while (!questionAnsweredCorrectly) {  // Loop until the answer is correct
             q.displayQuestion();
             std::string answer;
             std::getline(std::cin, answer);
 
             if (q.checkAnswer(answer)) {
                 std::cout << "Answer is correct! Move to the next question.\n";
                 score += 1;
                 questionAnsweredCorrectly = true; // Exit the loop and go to next question
             } else {
                 std::string detailedHint = q.getDetailedHint();
                 std::cout << "Wrong answer. Hint: " << detailedHint << "\n";
             }
         }
     }


    if (score >= static_cast<int>(questions.size() / 4)) {
        std::cout << "You pass the basic C review course.\nYour score is " << (score*100)/questions.size() << "\n";
        return true;
    } else {
        std::cout << "************F************\n";
        return false;
    }
}
