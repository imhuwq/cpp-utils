#ifndef CPP_UTILS_TEST_STRING_TO_STRING_H
#define CPP_UTILS_TEST_STRING_TO_STRING_H

#include <string>
#include <gtest/gtest.h>

#include "utils.h"
#include "../../models.h"

class Container_ToString : public ::testing::Test {
 protected:
  set<int> mSet = {0, 1, 2, 3};
  set<int> mSetEmpty;

  list<int> mList = {0, 1, 2, 3};
  list<int> mListEmpty;

  deque<int> mDeque = {0, 1, 2, 3};
  deque<int> mDequeEmpty;

  vector<int> mVector = {0, 1, 2, 3};
  vector<int> mVectorEmpty;

  forward_list<int> mFList = {0, 1, 2, 3};
  forward_list<int> mFListEmpty;

  vector<KeyValue> mVectorKV = {KeyValue("0", 0),
                                KeyValue("1", 1),
                                KeyValue("2", 2),
                                KeyValue("3", 3)};
  vector<KeyValue> mVectorKVEmpty;
};

TEST(ToString, Item) {
  EXPECT_EQ("1", cpp_utils::to_string(1));
  EXPECT_NE("3.1315926", cpp_utils::to_string(3.1415926));  //Fixme
  EXPECT_EQ("(\"Hi\": 3.14)", cpp_utils::to_string(KeyValue("Hi", 3.14)));
}

TEST_F(Container_ToString, ContainerByRange) {
  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mSet.begin(), mSet.end(), ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mSet.begin(), mSet.end(), ","));
//    EXPECT_EQ("1, 2", cpp_utils::to_string(mList.begin() + 1, mList.end() - 1, ",")); // Set iterator 不支持 operator- 和 operator+
  EXPECT_EQ("", cpp_utils::to_string(mSetEmpty.begin(), mSetEmpty.end(), ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mSetEmpty.begin(), mSetEmpty.end(), ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mList.begin(), mList.end(), ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mList.begin(), mList.end(), ","));
//    EXPECT_EQ("1, 2", cpp_utils::to_string(mList.begin() + 1, mList.end() - 1, ","));  // List iterator 不支持 operator- 和 operator+
  EXPECT_EQ("", cpp_utils::to_string(mListEmpty.begin(), mListEmpty.end(), ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mListEmpty.begin(), mListEmpty.end(), ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mDeque.begin(), mDeque.end(), ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mDeque.begin(), mDeque.end(), ","));
  EXPECT_EQ("1, 2", cpp_utils::to_string(mDeque.begin() + 1, mDeque.end() - 1, ","));  // 不要第一个和最后一个
  EXPECT_EQ("", cpp_utils::to_string(mDequeEmpty.begin(), mDequeEmpty.end(), ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mDequeEmpty.begin(), mDequeEmpty.end(), ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mVector.begin(), mVector.end(), ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mVector.begin(), mVector.end(), ","));
  EXPECT_EQ("1, 2", cpp_utils::to_string(mVector.begin() + 1, mVector.end() - 1, ","));  // 不要第一个和最后一个
  EXPECT_EQ("", cpp_utils::to_string(mVectorEmpty.begin(), mVectorEmpty.end(), ""));
  EXPECT_NE("0, 1, 2", cpp_utils::to_string(mVectorEmpty.begin(), mVectorEmpty.end(), ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mFList.begin(), mFList.end(), ""));
//    EXPECT_EQ("1, 2", cpp_utils::to_string(mFList.begin() + 1, mFList.end() - 1, ","));  // ForWard List iterator 不支持 operator- 和 operator+
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mFList.begin(), mFList.end(), ","));
  EXPECT_EQ("", cpp_utils::to_string(mFListEmpty.begin(), mFListEmpty.end(), ""));
  EXPECT_NE("0, 1, 2", cpp_utils::to_string(mFListEmpty.begin(), mFListEmpty.end(), ","));

  EXPECT_EQ("(\"0\": 0) (\"1\": 1) (\"2\": 2) (\"3\": 3)", cpp_utils::to_string(mVectorKV.begin(), mVectorKV.end(), ""));
  EXPECT_EQ("(\"0\": 0), (\"1\": 1), (\"2\": 2), (\"3\": 3)", cpp_utils::to_string(mVectorKV.begin(), mVectorKV.end(), ","));
  EXPECT_EQ("(\"1\": 1), (\"2\": 2)", cpp_utils::to_string(mVectorKV.begin() + 1, mVectorKV.end() - 1, ","));  // 不要第一个和最后一个
  EXPECT_EQ("", cpp_utils::to_string(mVectorKVEmpty.begin(), mVectorKVEmpty.end(), ""));
  EXPECT_NE("(\"0\": 0), (\"1\": 1), (\"2\": 2), (\"3\": 3)", cpp_utils::to_string(mVectorKVEmpty.begin(), mVectorKVEmpty.end(), ","));
}

TEST_F(Container_ToString, ContainerAll) {
  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mSet, ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mSet, ","));
  EXPECT_EQ("", cpp_utils::to_string(mSetEmpty, ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mSetEmpty, ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mList, ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mList, ","));
  EXPECT_EQ("", cpp_utils::to_string(mListEmpty, ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mListEmpty, ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mDeque, ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mDeque, ","));
  EXPECT_EQ("", cpp_utils::to_string(mDequeEmpty, ""));
  EXPECT_NE("0, 1, 2, 3", cpp_utils::to_string(mDequeEmpty, ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mVector, ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mVector, ","));
  EXPECT_EQ("", cpp_utils::to_string(mVectorEmpty, ""));
  EXPECT_NE("0, 1, 2", cpp_utils::to_string(mVectorEmpty, ","));

  EXPECT_EQ("0 1 2 3", cpp_utils::to_string(mFList, ""));
  EXPECT_EQ("0, 1, 2, 3", cpp_utils::to_string(mFList, ","));
  EXPECT_EQ("", cpp_utils::to_string(mFListEmpty, ""));
  EXPECT_NE("0, 1, 2", cpp_utils::to_string(mFListEmpty, ","));

  EXPECT_EQ("(\"0\": 0) (\"1\": 1) (\"2\": 2) (\"3\": 3)", cpp_utils::to_string(mVectorKV, ""));
  EXPECT_EQ("(\"0\": 0), (\"1\": 1), (\"2\": 2), (\"3\": 3)", cpp_utils::to_string(mVectorKV, ","));
  EXPECT_EQ("", cpp_utils::to_string(mVectorKVEmpty, ""));
  EXPECT_NE("(\"0\": 0), (\"1\": 1), (\"2\": 2), (\"3\": 3)", cpp_utils::to_string(mVectorKVEmpty, ","));
}

#endif //CPP_UTILS_TEST_STRING_TO_STRING_H
