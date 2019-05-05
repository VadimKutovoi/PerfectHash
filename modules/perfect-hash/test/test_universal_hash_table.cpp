// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include <string>

#include "include/universal_hash_table.h"

TEST(StudentDataBaseTest,
    Can_Create_Table_With_Default_Constructor) {
    unihash uh_table();

    ASSERT_NO_THROW();
}
