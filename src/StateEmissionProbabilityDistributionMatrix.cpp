
#include "StateEmissionProbabilityDistributionMatrix.h"

StateEmissionProbabilityDistributionMatrix::StateEmissionProbabilityDistributionMatrix(int numberOfStates, double **propabilityDistributionMatrix) {
    this->numberOfStates = numberOfStates;
    this->propabilityDistributionMatrix = propabilityDistributionMatrix;
}

double StateEmissionProbabilityDistributionMatrix::getPropability(int state, int observation) {
    return this->propabilityDistributionMatrix[state][observation];
}
