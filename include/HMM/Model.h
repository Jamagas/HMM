
#ifndef __HMM__Model__
#define __HMM__Model__

#include "StateTransitionProbabilityDistributionMatrix.h"
#include "StateEmissionProbabilityDistributionMatrix.h"
#include "InitialStateProbabilityDistribution.h"

template<std::size_t numberOfStates, std::size_t numberOfObservations>
class Model {
    
private:
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> transitionDistribution;
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> emissionDistribution;
    InitialStateProbabilityDistribution<numberOfObservations> initialStateDistribution;
    
    Model() { }
    
public:
    
    Model<numberOfStates>(StateTransitionProbabilityDistributionMatrix<numberOfStates> transitionDistribution,
                          StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> emissionDistribution,
                          InitialStateProbabilityDistribution<numberOfObservations> initialStateDistribution) {
        this->transitionDistribution = transitionDistribution;
        this->emissionDistribution = emissionDistribution;
        this->initialStateDistribution = initialStateDistribution;
    }
    
    StateTransitionProbabilityDistributionMatrix<numberOfStates> getTransitionDistribution() {
        return this->transitionDistribution;
    }
    
    StateEmissionProbabilityDistributionMatrix<numberOfStates, numberOfObservations> getEmissionDistribution() {
        return this->emissionDistribution;
    }
    
    InitialStateProbabilityDistribution<numberOfStates> getInitialStateDistribution() {
        this->initialStateDistribution;
    }
    
};

#endif
