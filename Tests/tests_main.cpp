/*
 * Project:    Ex3.
 * Author:  Alon Vita
 *   ID:    311233431
 *
 * tests_main Class.
 *
 * Google-Testing unit for code testing and evaluations.
 */

//----------INCLUDING----------
#include <gtest/gtest.h>

/*
 * main(int argc, char* argv[]).
 *
 * Testing-unit main.
 *
 */
int main(int argc,char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}