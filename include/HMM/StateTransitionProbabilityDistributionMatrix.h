
#ifndef __HMM__StateTransitionProbabilityDistributionMatrix__
#define __HMM__StateTransitionProbabilityDistributionMatrix__

#include <array>
#include <assert.h>

template<std::size_t numberOfStates>
class StateTransitionProbabilityDistributionMatrix {

private:
    
    std::array<std::array<double, numberOfStates>, numberOfStates> propabilityDistributionMatrix;
    
    StateTransitionProbabilityDistributionMatrix() { }
    
public:
    
    StateTransitionProbabilityDistributionMatrix(std::array<std::array<double, numberOfStates>, numberOfStates> propabilityDistributionMatrix) {
        this->propabilityDistributionMatrix = propabilityDistributionMatrix;
    }
    
    std::size_t getNumberOfStates() {
        return this->propabilityDistributionMatrix.size();
    }
    
    double getPropability(int startState, int endState) {
        assert(startState >= 0 && startState < getNumberOfStates() &&
               endState >= 0 && endState < getNumberOfStates());
        return this->propabilityDistributionMatrix[startState][endState];
    }
    
};

#endif
