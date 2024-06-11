#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/tree.h"
#include<sstream>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object 
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
	REQUIRE(1 == 1);
}

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