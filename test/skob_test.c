#include "../thirdparty/ctest.h"
#include "../src/skob.h"

CTEST(proverka1, balance)
{
    ASSERT_EQUAL(1, check(fopen("data.txt", "r")));
}

CTEST(proverka2, dizbalance)
{
    ASSERT_EQUAL(0, check(fopen("datadisbalance.txt", "r")));
}

CTEST(proverka3, fileopen)
{
    ASSERT_NOT_NULL(open_file("data.txt"));
}

CTEST(proverka4, filenotopen)
{
    ASSERT_NOT_NULL(open_file("data.txt"));
}
