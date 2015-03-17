
#include "Model.h"

Model::Model(StateTransitionProbabilityDistributionMatrix *transitionDistribution,
             StateEmissionProbabilityDistributionMatrix *emissionDistribution,
             InitialStateProbabilityDistribution *initialStateDistribution) {
    
    this->transitionDistribution = transitionDistribution;
    this->emissionDistribution = emissionDistribution;
    this->initialStateDistribution = initialStateDistribution;
}

StateTransitionProbabilityDistributionMatrix * Model::getTransitionDistribution() {
    return this->transitionDistribution;
}

StateEmissionProbabilityDistributionMatrix * Model::getEmissionDistribution() {
    return this->emissionDistribution;
}
InitialStateProbabilityDistribution * Model::getInitialStateDistribution() {
    return this->initialStateDistribution;
}
