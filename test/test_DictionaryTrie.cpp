/**
 * TODO: File HEADER
 *
 * Author:
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "DictionaryTrie.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/* Empty test */
TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}

/* TODO */
TEST(DictTrieTests, INSERT_TEST) {
    DictionaryTrie dict;

    ASSERT_EQ(dict.insert("apple", 1), true);
    ASSERT_EQ(dict.insert("ape", 2), true);
    ASSERT_EQ(dict.insert("apa", 2), true);
    ASSERT_EQ(dict.insert("book", 2), true);

    // check if insert() return false if duplication exists
    ASSERT_EQ(dict.insert("apple", 1), false);
    ASSERT_EQ(dict.insert("ape", 2), false);
    ASSERT_EQ(dict.insert("apa", 2), false);
    ASSERT_EQ(dict.insert("book", 2), false);
}

TEST(DictTrieTests, FULL_TEST) {
    DictionaryTrie dict;

    ASSERT_EQ(dict.insert("pain", 1), true);
    ASSERT_EQ(dict.insert("lol", 2), true);
    ASSERT_EQ(dict.insert("pls", 2), true);
    ASSERT_EQ(dict.insert("goal", 2), true);
    ASSERT_EQ(dict.insert("rick", 2), true);
    ASSERT_EQ(dict.insert("richard", 2), true);

    ASSERT_EQ(dict.find("pain"), true);
    ASSERT_EQ(dict.find("lol"), true);
    ASSERT_EQ(dict.find("pls"), true);
    ASSERT_EQ(dict.find("goal"), true);
    ASSERT_EQ(dict.find("rick"), true);
    ASSERT_EQ(dict.find("richard"), true);

    ASSERT_EQ(dict.find("pa"), false);
}

TEST(DictTrieTests, FIND_TEST) {
    DictionaryTrie dict;

    dict.insert("apple", 1);
    dict.insert("ape", 2);
    dict.insert("apa", 2);
    dict.insert("book", 2);

    ASSERT_EQ(dict.find("apple"), true);
    ASSERT_EQ(dict.find("ape"), true);
    ASSERT_EQ(dict.find("apa"), true);
    ASSERT_EQ(dict.find("book"), true);
    ASSERT_EQ(dict.find("apb"), false);
    ASSERT_EQ(dict.find("app"), false);
}

TEST(DictTrieTests, END_OF_PREFIX_TEST) {
    DictionaryTrie dict;
    dict.insert("apple", 0);
    dict.insert("book", 0);
    dict.insert("ape", 0);

    TrieNode* apResult = dict.endOfPrefixNode("ap", 0, dict.root);
    TrieNode* bResult = dict.endOfPrefixNode("b", 0, dict.root);

    ASSERT_EQ(apResult->getData(), 'p');
    ASSERT_EQ(bResult->getData(), 'b');
}

TEST(DictTrieTests, DFS_PREDICT_COMPLETION_TEST) {
    DictionaryTrie dict;
    dict.insert("apple", 143);
    dict.insert("book", 600);
    dict.insert("ape", 13);

    // vector<string>* vec = new vector<string>();
    vector<pair<string, int>>* vec = new vector<pair<string, int>>();

    dict.dfsForPredictCompletion(dict.root, "", vec, 0, 3);

    ASSERT_NE(vec->size(), 0);
}