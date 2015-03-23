
#ifndef __HMM__BaumWelchAlgorithm__
#define __HMM__BaumWelchAlgorithm__

#include "Model.h"

template<std::size_t modelNumberOfStates, std::size_t modelNumberOfObservations, std::size_t numberOfObservations>
std::array<std::array<double, numberOfObservations>, modelNumberOfStates> forwardAlgorithm(Model<modelNumberOfStates, modelNumberOfObservations> model,
                                                                                                               std::array<int, numberOfObservations> observations) {
    std::array<std::array<double, numberOfObservations>, modelNumberOfStates> alpha = {};
    
    // Step 1
    int firtsObservationIndex = 0;
    int firstObservation = observations[firtsObservationIndex];
    for (int state = 0; state < modelNumberOfStates; state++) {
        alpha[state][firtsObservationIndex] = model.getInitialStateDistribution().getPropability(state) * model.getEmissionDistribution().getPropability(state, firstObservation);
    }
    
    // Step 2
    for (int observationIndex = 1; observationIndex < numberOfObservations; observationIndex++) {
        for (int state = 0; state < modelNumberOfStates; state++) {
            double sum = 0;
            for (int sumState = 0; sumState < modelNumberOfStates; sumState++) {
                int previousObservation = observations[observationIndex - 1];
                sum += alpha[sumState][previousObservation] * model.getTransitionDistribution().getPropability(sumState, state);
            }
            int observation = observations[observationIndex];
            alpha[state][observationIndex] = sum * model.getEmissionDistribution().getPropability(state, observation);
        }
    }
    
    // Step 3
    
    return alpha;
}

#endif
