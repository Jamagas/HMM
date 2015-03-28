
#ifndef __HMM__Model__
#define __HMM__Model__

#include <string>

#include "StateTransitionProbabilityDistributionMatrix.h"
#include "StateEmissionProbabilityDistributionMatrix.h"
#include "InitialStateProbabilityDistribution.h"

template<std::size_t numberOfStates, std::size_t numberOfObservationSymbols>
class Model {
    
private:
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> transitionDistribution;
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservationSymbols> emissionDistribution;
    InitialStateProbabilityDistribution<numberOfStates> initialStateDistribution;
    std::array<std::string, numberOfObservationSymbols> observationSymbols;
    
    Model() { }
    
public:
    
    Model(const StateTransitionProbabilityDistributionMatrix<numberOfStates> &transitionDistribution,
          const StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservationSymbols> &emissionDistribution,
          const InitialStateProbabilityDistribution<numberOfStates> &initialStateDistribution,
          const std::array<std::string, numberOfObservationSymbols> &observationSymbols) :
    
    transitionDistribution(transitionDistribution),
    emissionDistribution(emissionDistribution),
    initialStateDistribution(initialStateDistribution) {
        this->transitionDistribution = transitionDistribution;
        this->emissionDistribution = emissionDistribution;
        this->initialStateDistribution = initialStateDistribution;
        this->observationSymbols = observationSymbols;
    }
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> getTransitionDistribution() {
        return this->transitionDistribution;
    }
    
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservationSymbols> getEmissionDistribution() {
        return this->emissionDistribution;
    }
    
    InitialStateProbabilityDistribution<numberOfStates> getInitialStateDistribution() {
        return this->initialStateDistribution;
    }
    
    std::array<std::string, numberOfObservationSymbols> getObservationSymbols() {
        return this->observationSymbols;
    }
    
    template<std::size_t numberOfObservationSymbolsInSequence>
    std::array<int, numberOfObservationSymbolsInSequence> getObservationSymbolsIndexes(std::array<std::string, numberOfObservationSymbolsInSequence> observationSymbolsSequence) {
        std::array<int, numberOfObservationSymbolsInSequence> observationSymbolsIndexesArray = {};
        observationSymbolsIndexesArray.fill(-1);
        for (int observationSymbolIndexInSequence = 0; observationSymbolIndexInSequence < numberOfObservationSymbolsInSequence; observationSymbolIndexInSequence++) {
            for (int observationSymbolIndex = 0; observationSymbolIndex < numberOfObservationSymbols; observationSymbolIndex++) {
                if (observationSymbols[observationSymbolIndex].compare(observationSymbolsSequence[observationSymbolIndexInSequence]) == 0) {
                    observationSymbolsIndexesArray[observationSymbolIndexInSequence] = observationSymbolIndex;
                    break;
                }
            }
        }
        return observationSymbolsIndexesArray;
    }
};

#endif
