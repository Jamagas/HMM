
#include <gtest/gtest.h>

#include <HMM/BaumWelchAlgorithm.h>

/* http://www.cs.rochester.edu/u/james/CSC248/Lec11.pdf */
TEST (BaumWelchAlgorithmTests, Test) {
    std::array<double, 2> ispDistribution = {{ 0.8, 0.2 }};
    InitialStateProbabilityDistribution<2> initialDistribution = InitialStateProbabilityDistribution<2>(ispDistribution);
    
    std::array<std::array<double, 2>, 2> stpDistribution = {{
        {{ 0.6, 0.4 }},
        {{ 0.3, 0.7 }}
    }};
    StateTransitionProbabilityDistributionMatrix<2> transitionDistribution = StateTransitionProbabilityDistributionMatrix<2>(stpDistribution);
    
    std::array<std::array<double, 3>, 2> sepDistribution = {{
        {{ 0.3, 0.4, 0.3 }},
        {{ 0.4, 0.3, 0.3 }}
    }};
    StateEmissionProbabilityDistributionMatrix<2, 3> emissionDistribution = StateEmissionProbabilityDistributionMatrix<2, 3>(sepDistribution);
    
    Model<2, 3> model = Model<2, 3>(transitionDistribution, emissionDistribution, initialDistribution);
    std::array<int, 4> observations = {{ 0, 1, 2, 2 }};
    
    std::array<std::array<double, 4>, 2> alpha = forwardAlgorithm(model, observations);
    EXPECT_DOUBLE_EQ(0.24, alpha[0][0]);
    EXPECT_DOUBLE_EQ(0.08, alpha[1][0]);
    
    EXPECT_DOUBLE_EQ(0.0672, alpha[0][1]);
    EXPECT_DOUBLE_EQ(0.0456, alpha[1][1]);
    
    EXPECT_DOUBLE_EQ(0.0162, alpha[0][2]);
    EXPECT_DOUBLE_EQ(0.01764, alpha[1][2]);
    
    EXPECT_DOUBLE_EQ(0.0045036, alpha[0][3]);
    EXPECT_DOUBLE_EQ(0.0056484, alpha[1][3]);
}
