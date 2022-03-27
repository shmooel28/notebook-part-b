#include "Direction.hpp"
#include "doctest.h"
#include<string>
#include<iostream>
#include "Notebook.hpp"

using namespace std;
using namespace ariel;

Notebook notebook;

TEST_CASE("good input")
{
    CHECK_NOTHROW(notebook.write(0,0,0,Direction::Vertical,"str"));
    CHECK_THROWS(notebook.write(0,0,0,Direction::Vertical,"str"));
    CHECK(notebook.read(0,0,0,Direction::Vertical,3)=="str");
    CHECK_NOTHROW(notebook.erase(0,0,0,Direction::Vertical,3));
    CHECK(notebook.read(0,0,0,Direction::Vertical,3)=="~~~");
    CHECK_THROWS(notebook.write(0,0,0,Direction::Vertical,"str"));
    CHECK_NOTHROW(notebook.write(1,0,0,Direction::Vertical,"str"));

}
TEST_CASE(" input less than 0")
{
    CHECK_THROWS(notebook.write(-1,0,0,Direction::Vertical,"str"));
    CHECK_THROWS(notebook.write(0,-1,0,Direction::Vertical,"str"));
    CHECK_THROWS(notebook.write(0,0,-7,Direction::Vertical,"str"));
    CHECK_THROWS(notebook.read(0,-1,0,Direction::Vertical,3));
    CHECK_THROWS(notebook.read(-2,-10,0,Direction::Horizontal,3));
    CHECK_THROWS(notebook.read(0,-5,-10,Direction::Horizontal,3));
    CHECK_THROWS(notebook.read(-4,0,-11,Direction::Horizontal,3));
    CHECK_THROWS(notebook.read(-2,-3,-4,Direction::Vertical,3));

}

TEST_CASE("col over 100")
{
    CHECK_THROWS(notebook.write(0,0,101,Direction::Horizontal,"str"));
    CHECK_THROWS(notebook.read(0,0,102,Direction::Horizontal,3));
    CHECK_THROWS(notebook.write(0,0,99,Direction::Horizontal,"str"));
    CHECK_THROWS(notebook.read(0,0,99,Direction::Horizontal,3));
    CHECK_THROWS(notebook.erase(0,0,80,Direction::Horizontal,23));

}