
#include "StateTransitionProbabilityDistributionMatrix.h"

StateTransitionProbabilityDistributionMatrix::StateTransitionProbabilityDistributionMatrix(int numberOfStates, double **propabilityDistributionMatrix) {
    this->numberOfStates = numberOfStates;
    this->propabilityDistributionMatrix = propabilityDistributionMatrix;
}

double StateTransitionProbabilityDistributionMatrix::getPropability(int startState, int endState) {
    return this->propabilityDistributionMatrix[startState][endState];
}
