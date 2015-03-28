
#ifndef __HMM__Model__
#define __HMM__Model__

#include <string>

#include "StateTransitionProbabilityDistributionMatrix.h"
#include "StateEmissionProbabilityDistributionMatrix.h"
#include "InitialStateProbabilityDistribution.h"

template<std::size_t numberOfStates, std::size_t numberOfObservations>
class Model {
    
private:
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> transitionDistribution;
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> emissionDistribution;
    InitialStateProbabilityDistribution<numberOfStates> initialStateDistribution;
    std::array<std::string, numberOfObservations> observations;
    
    Model() { }
    
public:
    
    Model(const StateTransitionProbabilityDistributionMatrix<numberOfStates> &transitionDistribution,
          const StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> &emissionDistribution,
          const InitialStateProbabilityDistribution<numberOfStates> &initialStateDistribution,
          const std::array<std::string, numberOfObservations> &observations) :
    
    transitionDistribution(transitionDistribution),
    emissionDistribution(emissionDistribution),
    initialStateDistribution(initialStateDistribution) {
        this->transitionDistribution = transitionDistribution;
        this->emissionDistribution = emissionDistribution;
        this->initialStateDistribution = initialStateDistribution;
        this->observations = observations;
    }
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> getTransitionDistribution() {
        return this->transitionDistribution;
    }
    
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> getEmissionDistribution() {
        return this->emissionDistribution;
    }
    
    InitialStateProbabilityDistribution<numberOfStates> getInitialStateDistribution() {
        return this->initialStateDistribution;
    }
    
    std::array<std::string, numberOfObservations> getObservations() {
        return this->observations;
    }
    
    template<std::size_t numberOfObservationsInSequence>
    std::array<int, numberOfObservationsInSequence> getObservationIndexesForSequence(std::array<std::string, numberOfObservationsInSequence> observationSequence) {
        std::array<int, numberOfObservationsInSequence> observationIndexesArray = {};
        observationIndexesArray.fill(-1);
        for (int i = 0; i < numberOfObservationsInSequence; i++) {
            for (int observation = 0; observation < numberOfObservations; observation++) {
                if (observations[observation].compare(observationSequence[i]) == 0) {
                    observationIndexesArray[i] = observation;
                    break;
                }
            }
        }
        return observationIndexesArray;
    }
};

#endif
