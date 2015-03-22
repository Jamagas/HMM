
#ifndef __HMM__StateEmissionProbabilityDistributionMatrix__
#define __HMM__StateEmissionProbabilityDistributionMatrix__

#include <array>
#include <assert.h>

template<std::size_t numberOfStates, std::size_t numberOfObservations>
class StateEmissionProbabilityDistributionMatrix {
    
private:
    
    std::array<std::array<double, numberOfObservations>, numberOfStates> propabilityDistributionMatrix;
    
    StateEmissionProbabilityDistributionMatrix() { }
    
public:
    
    StateEmissionProbabilityDistributionMatrix(const std::array<std::array<double, numberOfObservations>, numberOfStates> &propabilityDistributionMatrix) {
        this->propabilityDistributionMatrix = propabilityDistributionMatrix;
    }
    
    std::size_t getNumberOfStates() {
        return this->propabilityDistributionMatrix.size();
    }
    
    std::size_t getNumberOfObservations() {
        if (this->propabilityDistributionMatrix.empty()) {
            return 0;
        } else {
            return this->propabilityDistributionMatrix[0].size();
        }
    }
    
    double getPropability(int state, int observation) {
        assert(state >= 0 && state < getNumberOfStates() &&
               observation >= 0 && observation < getNumberOfObservations());
        return this->propabilityDistributionMatrix[state][observation];
    }
    
};

#endif
