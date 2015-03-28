
#ifndef __HMM__BaumWelchAlgorithm__
#define __HMM__BaumWelchAlgorithm__

#include "Model.h"

template<std::size_t numberOfStates, std::size_t numberOfObservationSymbols, std::size_t numberOfObservations>
std::array<std::array<double, numberOfObservations>, numberOfStates> forwardAlgorithm(Model<numberOfStates, numberOfObservationSymbols> model,
                                                                                      std::array<std::string, numberOfObservations> observationSymbolsSequence) {
    std::array<std::array<double, numberOfObservations>, numberOfStates> alpha = {};
    std::array<int, numberOfObservations> observationSymbolsIndexes = model.getObservationSymbolsIndexes(observationSymbolsSequence);
    
    // Step 1
    int firstObservationIndex = 0;
    int firstObservationSymbolIndex = observationSymbolsIndexes[firstObservationIndex];
    for (int stateIndex = 0; stateIndex < numberOfStates; stateIndex++) {
        alpha[stateIndex][firstObservationIndex] = model.getInitialStateDistribution().getPropability(stateIndex) * model.getEmissionDistribution().getPropability(stateIndex, firstObservationSymbolIndex);
    }
    
    // Step 2
    for (int observationIndex = 1; observationIndex < numberOfObservations; observationIndex++) {
        for (int stateIndex = 0; stateIndex < numberOfStates; stateIndex++) {
            double sum = 0;
            for (int sumStateIndex = 0; sumStateIndex < numberOfStates; sumStateIndex++) {
                sum += alpha[sumStateIndex][observationIndex - 1] * model.getTransitionDistribution().getPropability(sumStateIndex, stateIndex);
            }
            int observationSymbolIndex = observationSymbolsIndexes[observationIndex];
            alpha[stateIndex][observationIndex] = sum * model.getEmissionDistribution().getPropability(stateIndex, observationSymbolIndex);
        }
    }
    
    // Step 3
    
    return alpha;
}

template<std::size_t numberOfStates, std::size_t numberOfObservationSymbols, std::size_t numberOfObservations>
std::array<std::array<double, numberOfObservations>, numberOfStates> backwardAlgorithm(Model<numberOfStates, numberOfObservationSymbols> model,
                                                                                       std::array<std::string, numberOfObservations> observationSymbolsSequence) {
    std::array<std::array<double, numberOfObservations>, numberOfStates> beta = {};
    std::array<int, numberOfObservations> observationIndexes = model.getObservationSymbolsIndexes(observationSymbolsSequence);
    
    // Step 1
    int lastObservationIndex = numberOfObservations - 1;
    for (int stateIndex = 0; stateIndex < numberOfStates; stateIndex++) {
        beta[stateIndex][lastObservationIndex] = 1.0;
    }
    
    // Step 2
    for (int observationIndex = lastObservationIndex - 1; observationIndex >= 0; observationIndex--) {
        for (int stateIndex = 0; stateIndex < numberOfStates; stateIndex++) {
            double sum = 0;
            for (int sumStateIndex = 0; sumStateIndex < numberOfStates; sumStateIndex++) {
                int nextObservationSymbolIndex = observationIndexes[observationIndex + 1];
                sum += model.getTransitionDistribution().getPropability(stateIndex, sumStateIndex) *
                        model.getEmissionDistribution().getPropability(sumStateIndex, nextObservationSymbolIndex) *
                        beta[sumStateIndex][observationIndex + 1];
            }
            beta[stateIndex][observationIndex] = sum;
        }
    }
    
    return beta;
}

#endif
