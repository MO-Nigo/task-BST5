// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../my_tree.h"
#include <vector>

TEST_CASE("Constructor", "[multi-file:2]")
{
    MyTree<char> my_tree = MyTree<char>();
    REQUIRE(my_tree.get_size() == 0);
}

TEST_CASE("Constructor with elements", "[multi-file:2]")
{
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    MyTree<int> my_tree = MyTree<int>(input);
    REQUIRE(my_tree.get_size() == 7);
    REQUIRE(my_tree.get_height() == 2);
}

TEST_CASE("Constructor with elements 2", "[multi-file:2]")
{
    std::vector<char> input = {'A', 'B', 'C', 'D', 'E'};
    MyTree<char> my_tree = MyTree<char>(input);
    REQUIRE(my_tree.get_size() == 5);
    REQUIRE(my_tree.get_height() == 2);
}

TEST_CASE("isBST", "[multi-file:2]")
{
    std::vector<char> input = {'A', 'B', 'C', 'D', 'E'};
    MyTree<char> my_tree = MyTree<char>(input);
    REQUIRE(my_tree.inorder_it() == input);
    REQUIRE(my_tree.isBST() == true);
}

TEST_CASE("insert", "[multi-file:2]")
{
    std::vector<char> input = {'A', 'B', 'C', 'F', 'G'};
    std::vector<char> result = {'A', 'B', 'C', 'E', 'F', 'G'};

    MyTree<char> my_tree = MyTree<char>(input);
    my_tree.insert('E');

    REQUIRE(my_tree.get_size() == 6);
    REQUIRE(my_tree.get_height() == 3);
    REQUIRE(my_tree.isBST() == true);
    REQUIRE(my_tree.inorder_rec() == result);
}

TEST_CASE("search", "[multi-file:2]")
{
    std::vector<char> input = {'A', 'B', 'C', 'F', 'G'};
    MyTree<char> my_tree = MyTree<char>(input);
    const Node<char> *search_a = my_tree.search('A');
    const Node<char> *search_z = my_tree.search('Z');

    REQUIRE(search_a->data == 'A');
    REQUIRE(search_z == nullptr);
    REQUIRE(my_tree.get_height() == 2);
}

TEST_CASE("delete", "[multi-file:2]")
{
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MyTree<int> my_tree = MyTree<int>(input);
    my_tree.delete_node(4);
    my_tree.delete_node(9);
    my_tree.delete_node(7);
    REQUIRE(my_tree.get_size() == 7);
    REQUIRE(my_tree.get_height() == 3);
    REQUIRE(my_tree.isBST() == true);
}

TEST_CASE("InOrder", "[multi-file:2]")
{
    std::vector<int> input = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
    // std::vector<int> inOrder(input.size());
     //std::partial_sort_copy(begin(input), end(input), begin(inOrder), end(inOrder));
    MyTree<int> my_tree = MyTree<int>();
    for (int i : input)
    {
        my_tree.insert(i);
    }
    std::vector<int> inOrder = {6, 8, 14, 19, 20, 39, 44, 47, 64, 65, 71, 72, 76, 99};
    REQUIRE(my_tree.inorder_it() == inOrder);
    REQUIRE(my_tree.inorder_rec() == inOrder);
}

TEST_CASE("PreOrder", "[multi-file:2]")
{
    std::vector<int> input = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
    MyTree<int> my_tree = MyTree<int>();
    for (int i : input)
    {
        my_tree.insert(i);
    }
    std::vector<int> preOrder = {20, 14, 6, 8, 19, 99, 64, 39, 44, 47, 71, 65, 76, 72};
    REQUIRE(my_tree.preorder_it() == preOrder);
    REQUIRE(my_tree.preorder_rec() == preOrder);
}

TEST_CASE("PostOrder", "[multi-file:2]")
{
    std::vector<int> input = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
    MyTree<int> my_tree = MyTree<int>();
    for (int i : input)
    {
        my_tree.insert(i);
    }
    std::vector<int> postOrder = {8, 6, 19, 14, 47, 44, 39, 65, 72, 76, 71, 64, 99, 20};
    REQUIRE(my_tree.postorder_it() == postOrder);
    REQUIRE(my_tree.postorder_rec() == postOrder);
}

TEST_CASE("Breadth", "[multi-file:2]")
{
    std::vector<int> input = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
    MyTree<int> my_tree = MyTree<int>();
    for (int i : input)
    {
        my_tree.insert(i);
    }

    std::vector<int> breadth = {20, 14, 99, 6, 19, 64, 8, 39, 71, 44, 65, 76, 47, 72};
    REQUIRE(my_tree.breadth_traversal() == breadth);
    REQUIRE(my_tree.get_height() == 5);
    REQUIRE(my_tree.get_size() == input.size());
}

TEST_CASE("clear", "[multi-file:2]")
{
    std::vector<char> input = {'A', 'B', 'C', 'D', 'E'};
    MyTree<char> my_tree = MyTree<char>(input);
    REQUIRE(my_tree.inorder_it() == input);
    REQUIRE(my_tree.isBST() == true);
    my_tree.clear();
    my_tree.insert('C');
    my_tree.insert('B');
    my_tree.insert('A');
    my_tree.insert('D');
    my_tree.insert('E');
    REQUIRE(my_tree.inorder_it() == input);
    REQUIRE(my_tree.isBST() == true);
}
