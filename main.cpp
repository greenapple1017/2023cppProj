#include "Game.h"
#include "EasyStage.h"
#include "HardStage.h"
#include "TournamentStage.h"
#include <memory>

int main() {
    Game quizGame;

    std::vector<std::string> professors = {"김소영 교수님", "신동군 교수님", "이윤명 교수님", "한태희 교수님", "황재현 교수님", "김정래 교수님", "전재욱 교수님", "홍석인 교수님"};
    std::string finalProfessor = "홍석인 교수님";
    quizGame.addStage(std::make_shared<TournamentStage>(professors, finalProfessor));



    quizGame.addStage(std::make_shared<HardStage>(std::vector<Question>{
    Question("What is the use of the 'new' keyword in C++?", "Memory Allocation", {"Dynamic", "Heap", "Pointer"}),
    Question("What is the principle of OOP that C++ supports?", "Inheritance", {"Class", "Object", "Hierarchy"}),
}));



   quizGame.addStage(std::make_shared<HardStage>(std::vector<Question>{
        Question("Who is the best professor?", "Mr.Hong", {"Hardware", "Software", "handsome"})
    }));

    
    quizGame.play();





    return 0;
}
