
#include <gtest/gtest.h>

#include <HMM/InitialStateProbabilityDistribution.h>

TEST (InitialStateProbabilityDistributionTests, InitEmpty) {
    std::array<double, 0> array;
    InitialStateProbabilityDistribution<0> distribution = InitialStateProbabilityDistribution<0>(array);
    EXPECT_EQ(0, distribution.getNumberOfStates());
}

TEST (InitialStateProbabilityDistributionTests, InitNormal) {
    std::array<double, 4> array = {{ 1, 2, 5, 4 }};
    InitialStateProbabilityDistribution<4> distribution = InitialStateProbabilityDistribution<4>(array);
    EXPECT_EQ(4, distribution.getNumberOfStates());
    
    EXPECT_EQ(1, distribution.getPropability(0));
    EXPECT_EQ(2, distribution.getPropability(1));
    EXPECT_EQ(5, distribution.getPropability(2));
    EXPECT_EQ(4, distribution.getPropability(3));
}

TEST(InitialStateProbabilityDistributionTests, GetPropabilityForZeroLengthDistribution) {
    std::array<double, 0> array;
    InitialStateProbabilityDistribution<0> distribution = InitialStateProbabilityDistribution<0>(array);
    EXPECT_EQ(0, distribution.getNumberOfStates());
    
    EXPECT_DEATH(distribution.getPropability(0), "");
}

TEST(InitialStateProbabilityDistributionTests, GetPropabilityForOutOfBoundsState) {
    std::array<double, 2> array = {{ 3, 9 }};
    InitialStateProbabilityDistribution<2> distribution = InitialStateProbabilityDistribution<2>(array);
    EXPECT_EQ(2, distribution.getNumberOfStates());

    EXPECT_EQ(3, distribution.getPropability(0));
    EXPECT_EQ(9, distribution.getPropability(1));
    
    EXPECT_DEATH(distribution.getPropability(-1), "");
    EXPECT_DEATH(distribution.getPropability(2), "");
    
    EXPECT_DEATH(distribution.getPropability(-10), "");
    EXPECT_DEATH(distribution.getPropability(10), "");
}
