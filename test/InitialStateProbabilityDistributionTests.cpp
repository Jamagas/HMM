
#include <gtest/gtest.h>

#include <HMM/InitialStateProbabilityDistribution.h>

TEST (InitialStateProbabilityDistributionTests, InitEmpty) {
    InitialStateProbabilityDistribution distribution = InitialStateProbabilityDistribution(0, NULL);
    EXPECT_EQ(0, distribution.getNumberOfStates());
}

TEST (InitialStateProbabilityDistributionTests, InitNormal) {
    double array[] = {2, -5, 7, -1};
    InitialStateProbabilityDistribution distribution = InitialStateProbabilityDistribution(4, array);
    EXPECT_EQ(4, distribution.getNumberOfStates());
}
