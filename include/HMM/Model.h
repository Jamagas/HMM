
#ifndef __HMM__Model__
#define __HMM__Model__

#include "StateTransitionProbabilityDistributionMatrix.h"
#include "StateEmissionProbabilityDistributionMatrix.h"
#include "InitialStateProbabilityDistribution.h"

class Model {
    
private:
    
    StateTransitionProbabilityDistributionMatrix *transitionDistribution;
    StateEmissionProbabilityDistributionMatrix *emissionDistribution;
    InitialStateProbabilityDistribution *initialStateDistribution;
    
    Model() { }
    
public:
    
    Model(StateTransitionProbabilityDistributionMatrix *transitionDistribution,
          StateEmissionProbabilityDistributionMatrix *emissionDistribution,
          InitialStateProbabilityDistribution *initialStateDistribution);
    
    StateTransitionProbabilityDistributionMatrix * getTransitionDistribution();
    StateEmissionProbabilityDistributionMatrix * getEmissionDistribution();
    InitialStateProbabilityDistribution * getInitialStateDistribution();
    
};

#endif
