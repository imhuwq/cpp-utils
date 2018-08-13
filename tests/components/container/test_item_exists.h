#ifndef CPP_UTILS_TEST_CONTAINER_ITEM_EXISTS_H
#define CPP_UTILS_TEST_CONTAINER_ITEM_EXISTS_H

#include <set>
#include <map>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <string>
#include <gtest/gtest.h>

#include "utils.h"
#include "../../models.h"

class Container_ItemsExists : public ::testing::Test {
 protected:
//    virtual void SetUp() {}
//
//    virtual void TearDown() {}

  set<int> mSet = {0, 1, 2};
  set<int> mSetEmpty;

  map<int, string> mMap = {{0, "0"},
                           {1, "1"},
                           {2, "2"}};
  map<int, string> mMapEmpty;

  list<int> mList = {0, 1, 2};
  list<int> mListEmpty;

  deque<int> mDeque = {0, 1, 2};
  deque<int> mDequeEmpty;

  vector<int> mVector = {0, 1, 2};
  vector<int> mVectorEmpty;

  forward_list<int> mFList = {0, 1, 2};
  forward_list<int> mFListEmpty;

  vector<KeyValue> mVectorKV = {KeyValue("0", 0), KeyValue("1", 1), KeyValue("2", 2)};
  vector<KeyValue> mVectorKVEmpty;
};

TEST_F(Container_ItemsExists, NativeDataType) {
  EXPECT_TRUE(cpp_utils::item_exists(1, mSet));
  EXPECT_FALSE(cpp_utils::item_exists(3, mSet));
  EXPECT_FALSE(cpp_utils::item_exists(1, mSetEmpty));

  EXPECT_TRUE(cpp_utils::item_exists({1, "1"}, mMap));
  EXPECT_FALSE(cpp_utils::item_exists({3, "3"}, mMap));
  EXPECT_FALSE(cpp_utils::item_exists({1, "1"}, mMapEmpty));

  EXPECT_TRUE(cpp_utils::item_exists(1, mList));
  EXPECT_FALSE(cpp_utils::item_exists(3, mList));
  EXPECT_FALSE(cpp_utils::item_exists(1, mListEmpty));

  EXPECT_TRUE(cpp_utils::item_exists(1, mDeque));
  EXPECT_FALSE(cpp_utils::item_exists(3, mDeque));
  EXPECT_FALSE(cpp_utils::item_exists(1, mDequeEmpty));

  EXPECT_TRUE(cpp_utils::item_exists(1, mVector));
  EXPECT_FALSE(cpp_utils::item_exists(3, mVector));
  EXPECT_FALSE(cpp_utils::item_exists(1, mVectorEmpty));

  EXPECT_TRUE(cpp_utils::item_exists(1, mFList));
  EXPECT_FALSE(cpp_utils::item_exists(3, mFList));
  EXPECT_FALSE(cpp_utils::item_exists(1, mFListEmpty));
}

TEST_F(Container_ItemsExists, CustomDataType) {
  KeyValue data0 = KeyValue("0", 0);
  KeyValue data3 = KeyValue("3", 3);

  EXPECT_TRUE(cpp_utils::item_exists(data0, mVectorKV));
  EXPECT_FALSE(cpp_utils::item_exists(data3, mVectorKV));
  EXPECT_FALSE(cpp_utils::item_exists(data0, mVectorKVEmpty));
}

#endif //CPP_UTILS_TEST_CONTAINER_ITEM_EXISTS_H
