#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(test_empty) {
    List<int> list;
    ASSERT_TRUE(list.empty());

    list.push_front(1);
    list.push_back(3);
    ASSERT_FALSE(list.empty());

    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(test_empty_size) {
    List<int> list;
    ASSERT_EQUAL(list.size(),0);
}

TEST(test_size) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    list.push_front(1);
    list.push_front(1);
    list.push_back(3);
    ASSERT_EQUAL(list.size(),3);

    list.pop_back();
    ASSERT_EQUAL(list.size(),2);
}

TEST(test_push_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    ASSERT_EQUAL(list.front(),3);
}

TEST(test_push_back) {
    List<int> list;
    list.push_front(1); // 1
    list.push_front(2); // 2, 1
    list.push_back(3); // 2, 1, 3
    ASSERT_EQUAL(list.back(),3);
    ASSERT_EQUAL(list.front(),2);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_front(1); // 1
    list.push_front(2); // 2, 1
    list.push_front(3); // 3, 2, 1
    list.push_back(4); // 3, 2, 1, 4
    list.pop_front(); // 2, 1, 4
    ASSERT_EQUAL(list.front(), 2);
}

TEST(test_pop_back) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.pop_back();
    ASSERT_EQUAL(list.back(),1);
}

TEST(test_clear) {
    List<int> list;
    list.push_front(1);
    list.push_front(4);
    list.push_front(1);
    list.push_back(4);
    list.pop_front();
    list.push_front(9);
    list.push_back(10);
    list.pop_back();
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(front_back){
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.front() == 7);
    ASSERT_TRUE(list.back() == 5);
}

TEST(test_operator_equal_not) {
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    List<int> list2(list);
    List<int>::Iterator it2 = list2.begin();
    List<int>::Iterator it = list.begin();
    ASSERT_FALSE(it == it2);
    ASSERT_EQUAL(*it2, 7);
    it2++;
    ASSERT_EQUAL(*it2, 3);
    it2++;
    ASSERT_EQUAL(*it2, 5);
    list2.push_front(4); // 4, 7, 3, 5
    it2 = list2.begin();
    ASSERT_EQUAL(*it2, 4);
    it2++;
    ASSERT_EQUAL(*it2, 7);
    it2++;
    ASSERT_EQUAL(*it2, 3);
    it2++;
    ASSERT_EQUAL(*it2, 5);
    
    ASSERT_EQUAL(*it, 7);
    it2 = list2.begin();
    ASSERT_TRUE(it != it2);
}

TEST(test_operator_minus){
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    List<int>::Iterator it = list.end();
    //ASSERT_TRUE(it == nullptr);
    it--;
    ASSERT_EQUAL(*it, 5);
    it--;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 7);
    it--;
    //ASSERT_TRUE(it == nullptr);
}

TEST(insert){
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    List<int>::Iterator it = list.begin();
    it = list.insert(it, 9); // 9, 7, 3, 5
    ASSERT_EQUAL(*it, 9);
    list.pop_back(); // 9, 7, 3
    it = list.end();
    it--; 
    ASSERT_EQUAL(*it, 3);
    list.pop_front(); // 7, 3
    it = list.begin();
    ASSERT_EQUAL(*it, 7)
    it++;
    it = list.insert(it, 8); // 7, 8, 3
    ASSERT_EQUAL(*it, 8);
}

TEST(eraser){
    List<int> list;
    List<int>::Iterator it = list.begin();
    //ASSERT_EQUAL(it, nullptr);
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    list.push_front(9); // 9, 7, 3, 5
    it = list.begin();
    ++(++it);
    list.erase(it); // 9, 7, 5
    it = list.begin();
    ++(++it);
    ASSERT_EQUAL(*it, 5);
    list.erase(it);
    //ASSERT_EQUAL(it, nullptr);
}

void checkCopyConstructor(List<char> in_List) {
    ASSERT_TRUE(in_List.front() == 'a');
    ASSERT_TRUE(in_List.back() == 'e');
    in_List.pop_front();
    in_List.pop_back();
    ASSERT_TRUE(in_List.front() == 'b');
    ASSERT_TRUE(in_List.back() == 'd');
}

TEST(copy_constructor) {
    List<char> list;
    list.push_back('a');
    list.push_back('b');
    list.push_back('c');
    list.push_back('d');
    list.push_back('e');
    checkCopyConstructor(list);

    // test assignment operator
    List<char> l2;
    l2 = list;
    checkCopyConstructor(l2);
}

TEST(test_assignment_operator) {
    List<char> list;
    list.push_back('a'); // a
    list.push_back('b'); // a, b
    list.push_back('c'); // a, b, c

    List<char> copiedList;
    copiedList = list; // a, b, c
    ASSERT_TRUE(copiedList.front() == 'a');
    ASSERT_TRUE(copiedList.back() == 'c');
    ASSERT_TRUE(copiedList.size() == list.size());

    List<char> preFilledList;
    preFilledList.push_back('x'); // x
    preFilledList = list; // a, b, c
    ASSERT_TRUE(preFilledList.front() == 'a');
    ASSERT_TRUE(preFilledList.back() == 'c');
    ASSERT_TRUE(preFilledList.size() == list.size());

    list = list;
    ASSERT_TRUE(list.front() == 'a');
    ASSERT_TRUE(list.back() == 'c');
    ASSERT_TRUE(list.size() == 3);

    list.push_back('d'); // a, b, c, d
    ASSERT_TRUE(list.back() == 'd');
    ASSERT_TRUE(copiedList.back() == 'c');
}

TEST(equal_or_not){
    List<int>::Iterator it;
    List<int>::Iterator it2;
    ASSERT_EQUAL(it, it2); // two default constructors
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    list.push_front(9); // 9, 7, 3, 5
    it = list.end();
    ASSERT_TRUE(it != it2);
    it2 = list.begin();
    ASSERT_TRUE(it != it2);
    it2 = list.end();
    ASSERT_TRUE(it == it2);
    it = list.begin();
    it++;
    list.insert(it, 5); //9, 5, 7, 3, 5
    ASSERT_TRUE(it != it2);
}


TEST(test_iterator_comparison) {
    List<double> list;
    for (double i = 0.5; i < 3; ++i) {
        list.push_back(i);
    }
    // 0.5, 1.5, 2.5
    ASSERT_TRUE(list.size() == 3);

    List<double>::Iterator it1;
    List<double>::Iterator it2;
    ASSERT_TRUE(it1 == it2); // nullptr == nullptr
    it2 = list.end(); // &2.5
    ASSERT_TRUE(it1 != it2); // nullptr != &2.5
    it2 = list.begin(); // 0.5
    ASSERT_TRUE(it1 != it2); // nullptr != &0.5

    it1 = list.begin(); // &0.5
    ASSERT_TRUE(it1 == it2); // &0.5 == &0.5

    List<double>::Iterator it3 = it1++;
    ASSERT_TRUE(it3 == it2); // &0.5 == &0.5
    ASSERT_TRUE(it1 != it2); // &1.5 != &0.5
    ++it2; // &1.5
    ASSERT_TRUE(it1 == it2); // &1.5 == &1.5

    List<double>::Iterator it4 = it2--;
    ASSERT_TRUE(it4 == it1); // &1.5 == &1.5
    ASSERT_TRUE(it1 != it2); // &1.5 != &0.5
    --it1; // &0.5
    ASSERT_TRUE(it1 == it2); // &0.5 = &0.5
    ++it2; // &1.5
    list.erase(it1); 
    ASSERT_TRUE(list.front() == 1.5);
    double insertDouble = 5.5;
    list.insert(it2, insertDouble); // 5.5, 1.5, 2.5
    ASSERT_TRUE(list.front() == 5.5);

    double insertDouble2 = 4.5;
    list.insert(it2, insertDouble2); // 5.5, 4.5, 1.5, 2.5
    list.pop_front(); // 5.5, 4.5, 1.5
    ASSERT_TRUE(list.front() == 4.5);

    list.erase(it2);
    list.pop_front();
    ASSERT_TRUE(list.front() == 2.5);
}

TEST(copy_equal){
    List<int> list;
    list.push_back(3); // 3
    list.push_back(5); // 3, 5
    list.push_front(7); // 7, 3, 5
    list.push_front(9); // 9, 7, 3, 5

    List<int> list_in;
    list_in = list;
    List<int>::Iterator it_in = list_in.begin();
    for(List<int>::Iterator it = list.begin(); it != list.end(); it++, it_in++){
        ASSERT_EQUAL(*it, *it_in);
    }
    List<int> &list_two = list;
    list_two.push_back(11);  // 9, 7, 3, 5, 11
    list = list_two;
    ASSERT_EQUAL(list.front(), list_two.front());
    ASSERT_EQUAL(list.back(), list_two.back());
    list.pop_back(); // 9, 7, 3, 5
    list.pop_front(); // 7, 3, 5
    ASSERT_EQUAL(list_two.front(), list.front());
    ASSERT_EQUAL(list_two.back(), list_two.back());
    list.pop_back(); // 7, 3
    list.pop_front(); // 3
    ASSERT_EQUAL(list_two.front(), list.front());
    ASSERT_EQUAL(list_two.back(), list_two.back());
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}

TEST_MAIN()