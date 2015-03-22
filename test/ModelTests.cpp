
#include <gtest/gtest.h>

#include <HMM/Model.h>

TEST (ModelTests, Init) {
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
    EXPECT_EQ(2, model.getTransitionDistribution().getNumberOfStates());
    EXPECT_EQ(2, model.getEmissionDistribution().getNumberOfStates());
    EXPECT_EQ(3, model.getEmissionDistribution().getNumberOfObservations());
    EXPECT_EQ(2, model.getInitialStateDistribution().getNumberOfStates());
}
