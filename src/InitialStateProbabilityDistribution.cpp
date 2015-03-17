
#include "InitialStateProbabilityDistribution.h"

InitialStateProbabilityDistribution::InitialStateProbabilityDistribution(int numberOfStates, double *propabilityDistribution) {
    this->numberOfStates = numberOfStates;
    this->propabilityDistribution = propabilityDistribution;
}

double InitialStateProbabilityDistribution::getPropability(int state) {
    return this->propabilityDistribution[state];
}
