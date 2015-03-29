
#include <gtest/gtest.h>

#include <HMM/BaumWelchAlgorithm.h>

/* http://www.cs.rochester.edu/u/james/CSC248/Lec11.pdf */
TEST (BaumWelchAlgorithmTests, ForwardAlgorithm_1) {
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
    
    std::array<std::string, 3> observations = {{ "R", "W", "B" }};
    
    Model<2, 3> model = Model<2, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 4> observationSequance = {{ "R", "W", "B", "B" }};
    
    std::array<std::array<double, 4>, 2> alpha = forwardAlgorithm(model, observationSequance);
    EXPECT_DOUBLE_EQ(0.24, alpha[0][0]);
    EXPECT_DOUBLE_EQ(0.08, alpha[1][0]);
    
    EXPECT_DOUBLE_EQ(0.0672, alpha[0][1]);
    EXPECT_DOUBLE_EQ(0.0456, alpha[1][1]);
    
    EXPECT_DOUBLE_EQ(0.0162, alpha[0][2]);
    EXPECT_DOUBLE_EQ(0.01764, alpha[1][2]);
    
    EXPECT_DOUBLE_EQ(0.0045036, alpha[0][3]);
    EXPECT_DOUBLE_EQ(0.0056484, alpha[1][3]);
}

/* http://www2.nkfust.edu.tw/~wenh/2008/multimedia/HMMPack/HMMIntro.ppt */
TEST (BaumWelchAlgorithmTests, ForwardAlgorithm_2) {
    std::array<double, 3> ispDistribution = {{ 0.5, 0.25, 0.25 }};
    InitialStateProbabilityDistribution<3> initialDistribution = InitialStateProbabilityDistribution<3>(ispDistribution);
    
    std::array<std::array<double, 3>, 3> stpDistribution = {{
        {{ 0.2,  0.6,  0.2  }},
        {{ 0.25, 0.5,  0.25 }},
        {{ 0.35, 0.15, 0.5  }}
    }};
    StateTransitionProbabilityDistributionMatrix<3> transitionDistribution = StateTransitionProbabilityDistributionMatrix<3>(stpDistribution);
    
    std::array<std::array<double, 3>, 3> sepDistribution = {{
        {{ 0.25, 0.25, 0.5  }},
        {{ 0.2,  0.3,  0.5  }},
        {{ 0.45, 0.05, 0.5  }}
    }};
    StateEmissionProbabilityDistributionMatrix<3, 3> emissionDistribution = StateEmissionProbabilityDistributionMatrix<3, 3>(sepDistribution);
    
    std::array<std::string, 3> observations = {{ "R", "G", "B" }};
    
    Model<3, 3> model = Model<3, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 3> observationSequance = {{ "R", "G", "B" }};
    
    std::array<std::array<double, 3>, 3> alpha = forwardAlgorithm(model, observationSequance);
    EXPECT_NEAR(0.125, alpha[0][0], 0.00005);
    EXPECT_NEAR(0.05, alpha[1][0], 0.00005);
    EXPECT_NEAR(0.1125, alpha[2][0], 0.00005);
    
    EXPECT_NEAR(0.0192, alpha[0][1], 0.00005);
    EXPECT_NEAR(0.0351, alpha[1][1], 0.00005);
    EXPECT_NEAR(0.0047, alpha[2][1], 0.00005);
    
    EXPECT_NEAR(0.0071, alpha[0][2], 0.00005);
    EXPECT_NEAR(0.0149, alpha[1][2], 0.00005);
    EXPECT_NEAR(0.0075, alpha[2][2], 0.00005);
}

/* http://www.cs.rochester.edu/u/james/CSC248/Lec11.pdf */
TEST (BaumWelchAlgorithmTests, BackwardAlgorithm_1) {
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
    
    std::array<std::string, 3> observations = {{ "R", "W", "B" }};
    
    Model<2, 3> model = Model<2, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 4> observationSequance = {{ "R", "W", "B", "B" }};
    
    std::array<std::array<double, 4>, 2> beta = backwardAlgorithm(model, observationSequance);
    EXPECT_DOUBLE_EQ(0.0324, beta[0][0]);
    EXPECT_DOUBLE_EQ(0.0297, beta[1][0]);
    
    EXPECT_DOUBLE_EQ(0.09, beta[0][1]);
    EXPECT_DOUBLE_EQ(0.09, beta[1][1]);
    
    EXPECT_DOUBLE_EQ(0.3, beta[0][2]);
    EXPECT_DOUBLE_EQ(0.3, beta[1][2]);
    
    EXPECT_DOUBLE_EQ(1.0, beta[0][3]);
    EXPECT_DOUBLE_EQ(1.0, beta[1][3]);
}

/* http://www2.nkfust.edu.tw/~wenh/2008/multimedia/HMMPack/HMMIntro.ppt */
TEST (BaumWelchAlgorithmTests, BackwardAlgorithm_2) {
    std::array<double, 3> ispDistribution = {{ 0.5, 0.25, 0.25 }};
    InitialStateProbabilityDistribution<3> initialDistribution = InitialStateProbabilityDistribution<3>(ispDistribution);
    
    std::array<std::array<double, 3>, 3> stpDistribution = {{
        {{ 0.2,  0.6,  0.2  }},
        {{ 0.25, 0.5,  0.25 }},
        {{ 0.35, 0.15, 0.5  }}
    }};
    StateTransitionProbabilityDistributionMatrix<3> transitionDistribution = StateTransitionProbabilityDistributionMatrix<3>(stpDistribution);
    
    std::array<std::array<double, 3>, 3> sepDistribution = {{
        {{ 0.25, 0.25, 0.5  }},
        {{ 0.2,  0.3,  0.5  }},
        {{ 0.45, 0.05, 0.5  }}
    }};
    StateEmissionProbabilityDistributionMatrix<3, 3> emissionDistribution = StateEmissionProbabilityDistributionMatrix<3, 3>(sepDistribution);
    
    std::array<std::string, 3> observations = {{ "R", "G", "B" }};
    
    Model<3, 3> model = Model<3, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 3> observationSequance = {{ "R", "G", "B" }};
    
    std::array<std::array<double, 3>, 3> beta = backwardAlgorithm(model, observationSequance);
    EXPECT_NEAR(0.12, beta[0][0], 0.00005);
    EXPECT_NEAR(0.1125, beta[1][0], 0.00005);
    EXPECT_NEAR(0.0788, beta[2][0], 0.00005);
    
    EXPECT_NEAR(0.5, beta[0][1], 0.00005);
    EXPECT_NEAR(0.5, beta[1][1], 0.00005);
    EXPECT_NEAR(0.5, beta[2][1], 0.00005);
    
    EXPECT_NEAR(1.0, beta[0][2], 0.00005);
    EXPECT_NEAR(1.0, beta[1][2], 0.00005);
    EXPECT_NEAR(1.0, beta[2][2], 0.00005);
}

TEST(BaumWelchAlgorithmTests, ForwardBackwardArriveAtSameValue_1) {
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
    
    std::array<std::string, 3> observations = {{ "R", "W", "B" }};
    
    Model<2, 3> model = Model<2, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 4> observationSequance = {{ "R", "W", "B", "B" }};
    
    std::array<std::array<double, 4>, 2> alpha = forwardAlgorithm(model, observationSequance);
    std::array<std::array<double, 4>, 2> beta = backwardAlgorithm(model, observationSequance);
    
    EXPECT_TRUE(forwardAlgorithmTermination(model, alpha) > 0);
    EXPECT_TRUE(backwardAlgorithmTermination(model, beta) > 0);
    EXPECT_DOUBLE_EQ(forwardAlgorithmTermination(model, alpha), backwardAlgorithmTermination(model, beta));
}

TEST(BaumWelchAlgorithmTests, ForwardBackwardArriveAtSameValue_2) {
    std::array<double, 3> ispDistribution = {{ 0.5, 0.25, 0.25 }};
    InitialStateProbabilityDistribution<3> initialDistribution = InitialStateProbabilityDistribution<3>(ispDistribution);
    
    std::array<std::array<double, 3>, 3> stpDistribution = {{
        {{ 0.2,  0.6,  0.2  }},
        {{ 0.25, 0.5,  0.25 }},
        {{ 0.35, 0.15, 0.5  }}
    }};
    StateTransitionProbabilityDistributionMatrix<3> transitionDistribution = StateTransitionProbabilityDistributionMatrix<3>(stpDistribution);
    
    std::array<std::array<double, 3>, 3> sepDistribution = {{
        {{ 0.25, 0.25, 0.5  }},
        {{ 0.2,  0.3,  0.5  }},
        {{ 0.45, 0.05, 0.5  }}
    }};
    StateEmissionProbabilityDistributionMatrix<3, 3> emissionDistribution = StateEmissionProbabilityDistributionMatrix<3, 3>(sepDistribution);
    
    std::array<std::string, 3> observations = {{ "R", "G", "B" }};
    
    Model<3, 3> model = Model<3, 3>(transitionDistribution, emissionDistribution, initialDistribution, observations);
    std::array<std::string, 3> observationSequance = {{ "R", "G", "B" }};
    
    std::array<std::array<double, 3>, 3> alpha = forwardAlgorithm(model, observationSequance);
    std::array<std::array<double, 3>, 3> beta = backwardAlgorithm(model, observationSequance);
    
    EXPECT_TRUE(forwardAlgorithmTermination(model, alpha) > 0);
    EXPECT_TRUE(backwardAlgorithmTermination(model, beta) > 0);
    EXPECT_DOUBLE_EQ(forwardAlgorithmTermination(model, alpha), backwardAlgorithmTermination(model, beta));
}
