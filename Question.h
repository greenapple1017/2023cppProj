#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
    std::string questionText;
    std::string correctAnswer;
    std::vector<std::string> hints;
    int hintIndex;

public:
    Question(const std::string &question, const std::string &answer, const std::vector<std::string> &hints);

    void displayQuestion() const;
    bool checkAnswer(const std::string &userAnswer) const;
    std::string provideHint();
    std::string getDetailedHint();
    void resetHintIndex();
};

#endif // QUESTION_H
