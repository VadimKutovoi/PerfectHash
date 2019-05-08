// Copyright 2019 Kutovoi Vadim

#include <string>
#include <iostream>
#include <vector>

#include "../include/multiply_shift_hash_table.h"
#include "../../../3rdparty/gtest/gtest.h"

TEST(MshiftHashTest,
    Can_Create_Table_With_Default_Constructor) {
    ASSERT_NO_THROW(mshifthash table());
}

TEST(MshiftHashTest,
    Can_Create_Table_With_Int) {
    ASSERT_NO_THROW(mshifthash table(10));
}

TEST(MshiftHashTest,
    No_Throw_When_Adding_Positive_Int_Element) {
    mshifthash table(10);

    ASSERT_NO_THROW(table.add(5));
}

TEST(MshiftHashTest,
    No_Throw_When_Adding_Negative_Int_Element) {
    mshifthash table(10);

    ASSERT_NO_THROW(table.add(-5));
}

TEST(MshiftHashTest,
    Can_Find_Element) {
    mshifthash table(10);

    table.add(5);
    int item = table.find(5);

    EXPECT_EQ(5, item);
}

TEST(MshiftHashTest,
    Can_Remove_Element) {
    mshifthash table(10);
    table.add(5);
    table.remove(5);

    int item = table.find(5);

    EXPECT_EQ(-1, item);
}

TEST(MshiftHashTest,
    No_Throw_When_Build_Table_From_Vector) {
    mshifthash table(25);
    std::vector<int64_t> data = { 0, 1, 2, 4, 5 };

    ASSERT_NO_THROW(table.buildTable(data));
}
