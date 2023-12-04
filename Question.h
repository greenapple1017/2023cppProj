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

    // Display content of the question
    void displayQuestion() const;

    // Check if the answer is correct
    bool checkAnswer(const std::string &userAnswer) const;

    // Provide only a hint word
    std::string provideHint();

    // Provide a detailed hint sentence using OPENAI_API
    std::string getDetailedHint();

    // Reset HintIndex to provide new hint list to the next question 
    void resetHintIndex();

    // Check if there are more hints
    bool hasMoreHints() const;
};

#endif // QUESTION_H
