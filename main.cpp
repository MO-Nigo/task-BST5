#include <iostream>
#include"my_tree.h"
using namespace std;

int main(int argc, char** argv){

 std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     MyTree<int> my_tree = MyTree<int>(input);
    my_tree.delete_node(4);
    my_tree.delete_node(9);
    my_tree.delete_node(7);
    cout<<(my_tree.get_size() == 7);
    cout<<(my_tree.get_height() == 3);
    cout<<(my_tree.isBST() == true);
    
}