// Copyright 2019 Kutovoi Vadim

#include <string>
#include <iostream>
#include <vector>

#include "../include/universal_hash_table.h"
#include "../../../3rdparty/gtest/gtest.h"

TEST(UniversalHashTest,
    Can_Create_Table_With_Default_Constructor) {
    ASSERT_NO_THROW(unihash table());
}

TEST(UniversalHashTest,
    Can_Create_Table_With_Int) {
    ASSERT_NO_THROW(unihash table(10));
}

TEST(UniversalHashTest,
    No_Throw_When_Adding_Positive_Int_Element) {
    unihash table(10);

    ASSERT_NO_THROW(table.add(5));
}

TEST(UniversalHashTest,
    No_Throw_When_Adding_Negative_Int_Element) {
    unihash table(10);

    ASSERT_NO_THROW(table.add(-5));
}

TEST(UniversalHashTest,
    Can_Find_Element) {
    unihash table(10);

    table.add(5);
    int item = table.find(5);

    EXPECT_EQ(5, item);
}

TEST(UniversalHashTest,
    Can_Remove_Element) {
    unihash table(10);
    table.add(5);
    table.remove(5);

    int item = table.find(5);

    EXPECT_EQ(-1, item);
}

TEST(UniversalHashTest,
    No_Throw_When_Build_Table_From_Vector) {
    unihash table(25);
    std::vector<unihash::ullong> data = { 0, 1, 2, 4, 5 };

    ASSERT_NO_THROW(table.buildTable(data));
}
