#include "HardStage.h"
#include <iostream>
#include <string>


HardStage::HardStage(const std::vector<Question> &questions) : Stage(questions) {}

int HardStage::getScore() const {
    return score * 2;
}

int HardStage::maxScore() const {
    return questions.size() * 2 * 5;
}


bool HardStage::playStage() {
    std::cout << "This is a Hard Stage. This stage will ask you about advanced features of C++, what we have learned after the midterm exam. You have three hints for each question and when you spend all your hint, you'll get a zero point to that question\n";
    for (auto &q : questions) {
        q.resetHintIndex();  //Reset hints for the new question
        bool questionAnsweredCorrectly = false;
        while (!questionAnsweredCorrectly) {  // Loop until the answer is correct
            q.displayQuestion();
            std::string answer;
            std::getline(std::cin, answer);

            if (q.checkAnswer(answer)) {
                std::cout << "Answer is correct! Move to the next question.\n";
                score += 2;
                questionAnsweredCorrectly = true; 
            } else {
                if (q.hasMoreHints()) { 
                    std::string detailedHint = q.getDetailedHint();
                    std::cout << "Wrong answer. Hint: " << detailedHint << "\n";
                } else {
                    std::cout << "No more hints available. Moving to the next question.\n";
                    break; // Exit the loop and move to the next question
                }
            }

        }
    }

   if (score >= static_cast<int>(questions.size()) * 2 / 2) {
       std::cout << "You pass the advanced C++ OOP course.\nYour score is " << (score*100)/(questions.size() * 2) << "\n";
       return true;
   } else {
       std::cout << "************F************\n";
       return false;
   }

}
