
#include <gtest/gtest.h>

#include <HMM/StateTransitionProbabilityDistributionMatrix.h>

TEST (StateTransitionProbabilityDistributionMatrixTests, InitEmpty) {
    std::array<std::array<double, 0>, 0> matrix;
    StateTransitionProbabilityDistributionMatrix<0> distributionMatrix = StateTransitionProbabilityDistributionMatrix<0>(matrix);
    EXPECT_EQ(0, distributionMatrix.getNumberOfStates());
}

TEST (StateTransitionProbabilityDistributionMatrixTests, InitNormal) {
    std::array<std::array<double, 4>, 4> matrix = {{
        {{ 1,       2,      3,      4 }},
        {{ 10,      20,     30,     40 }},
        {{ 100,     200,    300,    400 }},
        {{ -1,      -2,     -3,     -4 }}
    }};
    StateTransitionProbabilityDistributionMatrix<4> distributionMatrix = StateTransitionProbabilityDistributionMatrix<4>(matrix);
    EXPECT_EQ(4, distributionMatrix.getNumberOfStates());
    
    EXPECT_EQ(1, distributionMatrix.getPropability(0, 0));
    EXPECT_EQ(2, distributionMatrix.getPropability(0, 1));
    EXPECT_EQ(3, distributionMatrix.getPropability(0, 2));
    EXPECT_EQ(4, distributionMatrix.getPropability(0, 3));
    
    EXPECT_EQ(10, distributionMatrix.getPropability(1, 0));
    EXPECT_EQ(20, distributionMatrix.getPropability(1, 1));
    EXPECT_EQ(30, distributionMatrix.getPropability(1, 2));
    EXPECT_EQ(40, distributionMatrix.getPropability(1, 3));
    
    EXPECT_EQ(100, distributionMatrix.getPropability(2, 0));
    EXPECT_EQ(200, distributionMatrix.getPropability(2, 1));
    EXPECT_EQ(300, distributionMatrix.getPropability(2, 2));
    EXPECT_EQ(400, distributionMatrix.getPropability(2, 3));
    
    EXPECT_EQ(-1, distributionMatrix.getPropability(3, 0));
    EXPECT_EQ(-2, distributionMatrix.getPropability(3, 1));
    EXPECT_EQ(-3, distributionMatrix.getPropability(3, 2));
    EXPECT_EQ(-4, distributionMatrix.getPropability(3, 3));
}

TEST(StateTransitionProbabilityDistributionMatrixTests, GetPropabilityForZeroLengthDistributionMatrix) {
    std::array<std::array<double, 0>, 0> array;
    StateTransitionProbabilityDistributionMatrix<0> distribution = StateTransitionProbabilityDistributionMatrix<0>(array);
    EXPECT_EQ(0, distribution.getNumberOfStates());
    
    EXPECT_DEATH(distribution.getPropability(0, 0), "");
}

TEST(StateTransitionProbabilityDistributionMatrixTests, GetPropabilityForOutOfBoundsState) {
    std::array<std::array<double, 2>, 2> array = {{
        {{ 1, 2 }},
        {{ 3, 9 }}
    }};
    StateTransitionProbabilityDistributionMatrix<2> distribution = StateTransitionProbabilityDistributionMatrix<2>(array);
    EXPECT_EQ(2, distribution.getNumberOfStates());
    
    EXPECT_EQ(1, distribution.getPropability(0, 0));
    EXPECT_EQ(2, distribution.getPropability(0, 1));
    EXPECT_EQ(3, distribution.getPropability(1, 0));
    EXPECT_EQ(9, distribution.getPropability(1, 1));
    
    EXPECT_DEATH(distribution.getPropability(0, -1), "");
    EXPECT_DEATH(distribution.getPropability(0, -10), "");
    EXPECT_DEATH(distribution.getPropability(0, 2), "");
    EXPECT_DEATH(distribution.getPropability(0, 10), "");
    
    EXPECT_DEATH(distribution.getPropability(1, -1), "");
    EXPECT_DEATH(distribution.getPropability(1, -10), "");
    EXPECT_DEATH(distribution.getPropability(1, 2), "");
    EXPECT_DEATH(distribution.getPropability(1, 10), "");
    
    EXPECT_DEATH(distribution.getPropability(-1, 0), "");
    EXPECT_DEATH(distribution.getPropability(-10, 0), "");
    EXPECT_DEATH(distribution.getPropability(2, 0), "");
    EXPECT_DEATH(distribution.getPropability(10, 0), "");
    
    EXPECT_DEATH(distribution.getPropability(-1, 1), "");
    EXPECT_DEATH(distribution.getPropability(-10, 1), "");
    EXPECT_DEATH(distribution.getPropability(2, 1), "");
    EXPECT_DEATH(distribution.getPropability(10, 1), "");
}
