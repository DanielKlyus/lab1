#include "gtest/gtest.h"
#include "header.h"
#include <sstream>

TEST (test, Constructor)
{
    TritSet set(1000);
    size_t allocLength = set.capacity();
    ASSERT_TRUE(allocLength >= 1000 * 2 / 8 / sizeof(uint));
}

TEST (test, Overloaded_operators)
{
    TritSet set(20);
    set[10] = Trit::True;
    set[5] = Trit::False;
    set[2] = Trit::Unknown;
    ASSERT_TRUE(set[10] == Trit::True);
    ASSERT_TRUE(set[5] == Trit::False);
    ASSERT_TRUE(set[2] == Trit::Unknown);
	
    set[10] = Trit::False;
    set[5] = Trit::Unknown;
    set[2] = Trit::True;
    ASSERT_TRUE(set[2] == Trit::True);
    ASSERT_TRUE(set[10] == Trit::False);
    ASSERT_TRUE(set[5] == Trit::Unknown);
}

TEST (test, Memory_allocation)
{
    TritSet set(1000);
    size_t allocLength = set.capacity();
    set[10000000] = Trit::Unknown;
    ASSERT_TRUE(allocLength == set.capacity());
    if (set[20000000] == Trit::True) {}
    ASSERT_TRUE(allocLength == set.capacity());
    set[1000000] = Trit::True;
    ASSERT_TRUE(allocLength < set.capacity());
    allocLength = set.capacity();
    set[10000000] = Trit::Unknown;
    set[100000] = Trit::False;
    ASSERT_TRUE(allocLength == set.capacity());
}

TEST (test, Logical_operations)
{
    TritSet setA(20);
    for (int i = 0; i < 20; i++)
    	setA[i] = Trit::True;
    TritSet setB(20);
    for (int i = 0; i < 20; i++)
    	setB[i] = Trit::False;
    TritSet setC = setA & setB;
    TritSet setD = setA | setB;
    TritSet setE = !setA;
    cout<< setA<<endl<< setB<<endl<< setC<<endl;
    EXPECT_TRUE(setC.capacity() == setB.capacity());
    EXPECT_TRUE(setD.capacity() == setB.capacity());
    EXPECT_TRUE(setE.capacity() == setA.capacity());
    EXPECT_TRUE(setC.cardinality(Trit::False) == 20);
    EXPECT_TRUE(setD.cardinality(Trit::True) == 10);
    EXPECT_TRUE(setE.cardinality(Trit::False) == 10);
};

TEST (test, Shrinking)
{
    TritSet set(1000);
    size_t allocLength = set.capacity();
    set.shrink();
    ASSERT_TRUE(allocLength > set.capacity());
}

TEST (test, Cardinality)
{
    TritSet setA(33);
    for (int i = 0; i < 33; i++)
    {
    	if (i % 3 == 0)
    	    setA[i] = Trit::True;
    	else if (i % 3 == 1)
    	    setA[i] = Trit::False;
    	else
    	    setA[i] = Trit::Unknown;
    }
    ASSERT_TRUE(setA.cardinality(Trit::True) == 11);
    ASSERT_TRUE(setA.cardinality(Trit::False) == 11);
    ASSERT_TRUE(setA.cardinality(Trit::Unknown) == 10);

}

TEST (test, Initializer_list)
{
    TritSet ts{Trit::True, Trit::True, Trit::False, Trit::Unknown};
    ASSERT_TRUE(ts[0] == Trit::True);
    ASSERT_TRUE(ts[1] == Trit::True);
    ASSERT_TRUE(ts[2] == Trit::False);
    ASSERT_TRUE(ts[3] == Trit::Unknown);
    ASSERT_TRUE(ts.length() == 3);
}

TEST (test, Single_trit)
{
    TritSet ts(1000);
    ts[0] = Trit::True;
    Trit t = ts[0];
    ASSERT_TRUE(t == ts[0]);
}

TEST (test, Range_based_for_loop)
{
    TritSet set (10);
    for (uint i = 0; i < 10; i++)
    {
    	set[i] = Trit::True;
    }
    uint check = 0;
    for (auto a : set)
    {
    	if (a == Trit::True) check++;
    }
    ASSERT_TRUE(check == 10);
}

TEST (test, Trimming_and_length)
{
    TritSet setA(50);
    for (int i = 0; i < 32; i++)
    	setA[i] = Trit::True;
    ASSERT_TRUE(setA.length() == 32);
    setA.trim(25);
    ASSERT_TRUE(setA.length() == 25);
}

TEST (test, Output)
{
    TritSet set{Trit::True, Trit::False, Trit::Unknown, Trit::True};
    stringstream f;
    f << set << endl;
    ASSERT_TRUE(f.str() == "10?1\n");
}

int testes()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
