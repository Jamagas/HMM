
#include <gtest/gtest.h>

#include <HMM/StateEmissionProbabilityDistributionMatrix.h>

TEST (StateEmissionProbabilityDistributionMatrixTests, InitEmpty) {
    std::array<std::array<double, 0>, 0> matrix;
    StateEmissionProbabilityDistributionMatrix<0, 0> distributionMatrix = StateEmissionProbabilityDistributionMatrix<0, 0>(matrix);
    EXPECT_EQ(0, distributionMatrix.getNumberOfStates());
    EXPECT_EQ(0, distributionMatrix.getNumberOfObservations());
}

TEST (StateEmissionProbabilityDistributionMatrixTests, InitNormal) {
    std::array<std::array<double, 4>, 2> matrix = {{
        {{ 1,       2,      3,      4 }},
        {{ 10,      20,     30,     40 }}
    }};
    StateEmissionProbabilityDistributionMatrix<2, 4> distributionMatrix = StateEmissionProbabilityDistributionMatrix<2, 4>(matrix);
    EXPECT_EQ(2, distributionMatrix.getNumberOfStates());
    EXPECT_EQ(4, distributionMatrix.getNumberOfObservations());
    
    EXPECT_EQ(1, distributionMatrix.getPropability(0, 0));
    EXPECT_EQ(2, distributionMatrix.getPropability(0, 1));
    EXPECT_EQ(3, distributionMatrix.getPropability(0, 2));
    EXPECT_EQ(4, distributionMatrix.getPropability(0, 3));
    
    EXPECT_EQ(10, distributionMatrix.getPropability(1, 0));
    EXPECT_EQ(20, distributionMatrix.getPropability(1, 1));
    EXPECT_EQ(30, distributionMatrix.getPropability(1, 2));
    EXPECT_EQ(40, distributionMatrix.getPropability(1, 3));
}

TEST(StateEmissionProbabilityDistributionMatrixTests, GetPropabilityForZeroLengthDistributionMatrix) {
    std::array<std::array<double, 0>, 0> array;
    StateEmissionProbabilityDistributionMatrix<0, 0> distribution = StateEmissionProbabilityDistributionMatrix<0, 0>(array);
    
    EXPECT_EQ(0, distribution.getNumberOfStates());
    EXPECT_EQ(0, distribution.getNumberOfObservations());
    
    EXPECT_DEATH(distribution.getPropability(0, 0), "");
}

TEST(StateEmissionProbabilityDistributionMatrixTests, GetPropabilityForOutOfBoundsState) {
    std::array<std::array<double, 3>, 2> array = {{
        {{ 1, 2, 3 }},
        {{ 4, 8, 16 }}
    }};
    StateEmissionProbabilityDistributionMatrix<2, 3> distribution = StateEmissionProbabilityDistributionMatrix<2, 3>(array);
    
    EXPECT_EQ(2, distribution.getNumberOfStates());
    EXPECT_EQ(3, distribution.getNumberOfObservations());
    
    EXPECT_EQ(1, distribution.getPropability(0, 0));
    EXPECT_EQ(2, distribution.getPropability(0, 1));
    EXPECT_EQ(3, distribution.getPropability(0, 2));
    EXPECT_EQ(4, distribution.getPropability(1, 0));
    EXPECT_EQ(8, distribution.getPropability(1, 1));
    EXPECT_EQ(16, distribution.getPropability(1, 2));
    
    EXPECT_DEATH(distribution.getPropability(-1, 0), "");
    EXPECT_DEATH(distribution.getPropability(-10, 0), "");
    EXPECT_DEATH(distribution.getPropability(2, 0), "");
    EXPECT_DEATH(distribution.getPropability(10, 0), "");
    
    EXPECT_DEATH(distribution.getPropability(-1, 1), "");
    EXPECT_DEATH(distribution.getPropability(-10, 1), "");
    EXPECT_DEATH(distribution.getPropability(2, 1), "");
    EXPECT_DEATH(distribution.getPropability(10, 1), "");
    
    EXPECT_DEATH(distribution.getPropability(-1, 2), "");
    EXPECT_DEATH(distribution.getPropability(-10, 2), "");
    EXPECT_DEATH(distribution.getPropability(2, 2), "");
    EXPECT_DEATH(distribution.getPropability(10, 2), "");
}

TEST(StateEmissionProbabilityDistributionMatrixTests, GetPropabilityForOutOfBoundsObservation) {
    std::array<std::array<double, 3>, 2> array = {{
        {{ 1, 2, 3 }},
        {{ 4, 8, 16 }}
    }};
    StateEmissionProbabilityDistributionMatrix<2, 3> distribution = StateEmissionProbabilityDistributionMatrix<2, 3>(array);
    
    EXPECT_EQ(2, distribution.getNumberOfStates());
    EXPECT_EQ(3, distribution.getNumberOfObservations());
    
    EXPECT_EQ(1, distribution.getPropability(0, 0));
    EXPECT_EQ(2, distribution.getPropability(0, 1));
    EXPECT_EQ(3, distribution.getPropability(0, 2));
    EXPECT_EQ(4, distribution.getPropability(1, 0));
    EXPECT_EQ(8, distribution.getPropability(1, 1));
    EXPECT_EQ(16, distribution.getPropability(1, 2));
    
    EXPECT_DEATH(distribution.getPropability(0, -1), "");
    EXPECT_DEATH(distribution.getPropability(0, -10), "");
    EXPECT_DEATH(distribution.getPropability(0, 3), "");
    EXPECT_DEATH(distribution.getPropability(0, 10), "");
    
    EXPECT_DEATH(distribution.getPropability(1, -1), "");
    EXPECT_DEATH(distribution.getPropability(1, -10), "");
    EXPECT_DEATH(distribution.getPropability(1, 3), "");
    EXPECT_DEATH(distribution.getPropability(1, 10), "");
}
