
#include "InitialStateProbabilityDistribution.h"

#include <assert.h>

InitialStateProbabilityDistribution::InitialStateProbabilityDistribution(int numberOfStates, double *propabilityDistribution) {
    if (propabilityDistribution == NULL) {
        assert(numberOfStates == 0);
    }
    this->numberOfStates = numberOfStates;
    this->propabilityDistribution = propabilityDistribution;
}

int InitialStateProbabilityDistribution::getNumberOfStates() {
    return this->numberOfStates;
}

double InitialStateProbabilityDistribution::getPropability(int state) {
    return this->propabilityDistribution[state];
}
