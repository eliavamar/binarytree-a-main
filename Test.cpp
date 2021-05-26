#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("test"){
    BinaryTree<int> BT;
    CHECK_NOTHROW(BT.add_root(3));
    CHECK_NOTHROW(BT.add_left(3,2));
    CHECK_NOTHROW(BT.add_right(3,1));
    CHECK_NOTHROW(BT.add_left(1,50));
    CHECK_NOTHROW(BT.add_left(2,4));
    CHECK_NOTHROW(BT.add_right(2,5));
    CHECK_NOTHROW(BT.add_right(5,30));
    CHECK_NOTHROW(BT.add_right(30,22));
    CHECK_NOTHROW(BT.add_left(4,21)); 
    CHECK_NOTHROW(BT.add_right(4,31));
    CHECK_THROWS(BT.add_right(100,31));
    CHECK_THROWS(BT.add_right(39,11));
    CHECK_THROWS(BT.add_right(77,8));
    CHECK_THROWS(BT.add_right(105,58));
    CHECK_THROWS(BT.add_right(55,3));
    CHECK_THROWS(BT.add_right(97,38));
    CHECK_NOTHROW(BT.add_root(100)); 
    CHECK_NOTHROW(BT.add_right(100,40));
    CHECK_NOTHROW(BT.add_right(100,41));
    CHECK_NOTHROW(BT.add_left(100,300));
    int i = 0;
    int pos[] = {31,4,22,30,5,300,50,41,100};
    int pre[] = {100,300,4,31,5,30,22,41,50};
    int in[] = {31,4,300,5,30,22,100,50,41};
    

    for (auto it=BT.begin_preorder(); it!=BT.end_preorder(); ++it)
    {
        CHECK_EQ(*it,pre[i++]);
       
    }  
    i=0;
    for (auto it=BT.begin_inorder(); it!=BT.end_inorder(); ++it)
    {
        CHECK_EQ(*it,in[i++]);
       
    }  
    i=0;
    for (auto it=BT.begin_postorder(); it!=BT.end_postorder(); ++it)
    {
        CHECK_EQ(*it,pos[i++]);
        
    }
    

}

