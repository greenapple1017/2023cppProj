#include "Question.h"
#include <iostream>
#include "openai.hpp" 
#include "nlohmann/json.hpp"

Question::Question(const std::string &question, const std::string &answer, const std::vector<std::string> &hints)
    : questionText(question), correctAnswer(answer), hints(hints), hintIndex(0) {}

void Question::displayQuestion() const {
    std::cout << questionText << std::endl;
}

bool Question::checkAnswer(const std::string &userAnswer) const {
    return userAnswer == correctAnswer;
}

std::string Question::provideHint() {
    if (hintIndex < static_cast<int>(hints.size())) {
        return hints[hintIndex++];  // Return the current hint and increment hintIndex
    } else {
        return "No more hints available.";
    }
}

void Question::resetHintIndex() {
    hintIndex = 0;  // Reset hintIndex when a new question starts
}

bool Question::hasMoreHints() const {
    return hintIndex < static_cast<int>(hints.size());
}


std::string Question::getDetailedHint() {
    if (hintIndex >= static_cast<int>(hints.size())) {
        return "No more hints available.";
    }

    std::string hintWord = hints[hintIndex++];

    openai::start(); 

    std::string prompt = "Provide a hint about the following topic: " + hintWord;

    nlohmann::json request = {
        {"model", "text-davinci-003"},
        {"prompt", prompt},
        {"max_tokens", 100},
        {"temperature", 0.1} 
    };

    auto completion = openai::completion().create(request);
    nlohmann::json response = nlohmann::json::parse(completion.dump());
    std::string detailedHint = response["choices"][0]["text"].get<std::string>();

    return detailedHint;
}
