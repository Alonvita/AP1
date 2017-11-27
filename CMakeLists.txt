cmake_minimum_required(VERSION 3.8)
project(AP1_ex3)

set(CMAKE_CXX_STANDATD 98 -Wall -Wextra)
#set(CMAKE_CCX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -Wextra")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(CORE_FILES
		# Utilities
		src/core/Utilities/GameUtilities.cpp src/core/Utilities/GameUtilities.h
		# Players
		src/core/Players/AI.cpp src/core/Players/AI.h
		src/core/Players/Participant.cpp src/core/Players/Participant.h
		src/core/Players/Player.cpp src/core/Players/Player.h
		# Game Logic
		src/core/GameLogic/TurnsManager.cpp src/core/GameLogic/TurnsManager.h
		src/core/GameLogic/MovesEvaluator.cpp src/core/GameLogic/MovesEvaluator.h
		# Game Flow
		src/core/GameFlow/ReversiGame.cpp src/core/GameFlow/ReversiGame.h
		# Board
		src/core/Board/Board.cpp src/core/Board/Board.h
		src/core/Board/Cell.h)

set(TEST_FILES
        # Board Test Files
		Tests/TestBoard.cpp
		# Moves Evaluator Test Files
		Tests/TestMovesEvaluator.cpp;
		# Turns Manager Test Files
		Tests/TestTurnsManager.cpp
        # AI Test Files
        Tests/TestAI.cpp
        # Participant Test Files
        Tests/TestParticipant.cpp
        # GameUtilities Test Files
        Tests/TestGameUtilities.cpp)

set(SOURCE_FILES ${CORE_FILES})

# Adding Executables
add_executable(Run_main src/main.cpp ${SOURCE_FILES})
add_executable(Run_tests Tests/tests_main.cpp ${TEST_FILES}
                                                  ${SOURCE_FILES})

# Link Libraries
target_link_libraries(Run_tests gtest gtest_main)
