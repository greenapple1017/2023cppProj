CXX = g++
CXXFLAGS = -Wall 
LDFLAGS = -lcurl  
TARGET = start 
SRCS = main.cpp Game.cpp EasyStage.cpp HardStage.cpp Stage.cpp Question.cpp TournamentStage.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
