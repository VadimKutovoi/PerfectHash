// Copyright 2019 Kutovoi Vadim

#include <string>
#include <iostream>

#include "..\include\perfect_hash_table.h"
#include "..\..\..\3rdparty\gtest\gtest.h"

TEST(PerfectHashTest,
    No_Throw_When_Build_Table_From_Vector) {
    std::vector<int64_t> data = { 0, 1, 2, 4, 5 };
    perfhash table(data.size());

    ASSERT_NO_THROW(table.buildTable(data));
}
