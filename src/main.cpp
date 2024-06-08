#include <iostream>
#include "tree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/
using namespace std;
int main()
{
    AVLTree students;
    students.levelcount();
    students.insert("Nathan King", "12345878");
    students.insert("Nathan Kingjames", "22222111");
    students.insert("Lebron King", "22222222");
    cout << endl;
    students.levelcount();

    students.name_from_id("12345878");
    students.id_from_name("Nathan King");
    students.printPostorder();
    students.printInorder();
    students.printPreorder();
    students.levelcount();
    students.insert("Leb King", "22222222");
    students.levelcount();
    students.insert("Leb King", "22222242");
    students.levelcount();
}
