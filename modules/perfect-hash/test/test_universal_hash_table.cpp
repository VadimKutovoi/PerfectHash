// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include <string>
#include <iostream>

#include "include/universal_hash_table.h"

TEST(UniversalHashTest,
    Can_Create_Table_With_Default_Constructor) {
    unihash table();

    ASSERT_NO_THROW();
}

TEST(UniversalHashTest,
    Can_Create_Table_With_Int) {
    unihash table(10);

    ASSERT_NO_THROW();
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
