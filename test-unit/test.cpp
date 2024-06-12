#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/tree.h"
#include<sstream>
#include<map>
#include <random>


/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/



TEST_CASE("AVL Tree Incorrect Insert", "[flag]")
{
    AVLTree mytree;
    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());

    mytree.insert("Nathan King", "122dt603");
    mytree.insert("James22", "22567800");
    mytree.insert("Jim", "122000678");
    mytree.insert("nate", "126483");
    mytree.insert("nate**/12][]", "@@3tt+=..,");

    std::cout.rdbuf(output);

    REQUIRE(ss.str() == "unsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\n");

}


TEST_CASE("AVL Tree Edge Cases", "[flag]")
{
    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());
    AVLTree mytree;
    mytree.insert("Nate", "72180427");
    mytree.remove("11111111");
    mytree.removeInorder(4);
    mytree.name_from_id("12345678");
    std::cout.rdbuf(output);

    REQUIRE(ss.str() == "successful\nunsuccessful\nunsuccessful\nunsuccessful\n");


}

TEST_CASE("Left Left imbalance case", "[flag]")
{
    AVLTree mytree;

    mytree.insert("hannah", "55555555");
    mytree.insert("nate", "11111111");
    mytree.insert("jacob", "10000000");

    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());

    mytree.printPreorder(); // if balanced, 11111111 should print first

    std::cout.rdbuf(output);
    REQUIRE(ss.str() == "nate, jacob, hannah\n");

}


TEST_CASE("Left right imbalance case", "[flag]")
{
    AVLTree mytree;

    mytree.insert("hannah", "55555555");
    mytree.insert("nate", "11111111");
    mytree.insert("jacob", "12000000");

    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());

    mytree.printPreorder();

    std::cout.rdbuf(output);
    REQUIRE(ss.str() == "jacob, nate, hannah\n");

}

TEST_CASE("right right imbalance case", "[flag]")
{
    AVLTree mytree;

    mytree.insert("hannah", "00000001");
    mytree.insert("nate", "11111111");
    mytree.insert("jacob", "12000000");

    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());

    mytree.printPreorder();

    std::cout.rdbuf(output);
    REQUIRE(ss.str() == "nate, hannah, jacob\n");

}

TEST_CASE("right left imbalance case", "[flag]")
{
    AVLTree mytree;

    mytree.insert("hannah", "00000001");
    mytree.insert("nate", "11111111");
    mytree.insert("jacob", "11000000");

    std::stringstream ss;
    auto output = std::cout.rdbuf(ss.rdbuf());

    mytree.printPreorder();

    std::cout.rdbuf(output);
    REQUIRE(ss.str() == "jacob, hannah, nate\n");

}

TEST_CASE("Delete(0 children)", "[flag]")
{
    AVLTree mytree;
    mytree.insert("tim", "65477298");
    mytree.insert("tom", "66477298");
    mytree.remove("66477298");

    std::vector<std::string> s = mytree.inorder_unit_test(mytree.getRoot());
    REQUIRE(s[0] == "tim");


}

TEST_CASE("Delete(1 child)", "[flag]")
{
    AVLTree mytree;
    mytree.insert("tim", "65477298");
    mytree.insert("tom", "66477298");
    mytree.remove("65477298");
    std::vector<std::string> s = mytree.inorder_unit_test(mytree.getRoot());
    REQUIRE(s[0] == "tom");

}

TEST_CASE("Delete(2 children)", "[flag]")
{
    AVLTree mytree;
    mytree.insert("tim", "65477298");
    mytree.insert("tom", "66477298");
    mytree.insert("jane", "64477298");
    mytree.insert("sam", "65577298");
    mytree.remove("65477298");
    std::vector<std::string> s = mytree.inorder_unit_test(mytree.getRoot());
    REQUIRE(s[0] == "jane");
    REQUIRE(s[1] == "sam");
    REQUIRE(s[2] == "tom");




}

TEST_CASE("100 insertions, 10 deletions", "[flag]")
{
    std::srand(std::time(0));
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distrib(10000000, 99999999);
    int random_num;
    std::string num;


    AVLTree mytree;
    std::map<std::string, std::string > people;
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<> str_dist(0,25);

    for(int i = 0; i < 100; i++)
    {
        std::string random_string = "";
        for(int j = 0; j < 7; j++)
        {
            random_string += alph[str_dist(gen)];
        }
        random_num = distrib(gen);

        num = std::to_string(random_num);
        mytree.insert(random_string, num);
        people[num] = random_string;




    }
}