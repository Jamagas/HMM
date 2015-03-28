
#ifndef __HMM__StateEmissionProbabilityDistributionMatrix__
#define __HMM__StateEmissionProbabilityDistributionMatrix__

#include <array>
#include <assert.h>

template<std::size_t numberOfStates, std::size_t numberOfObservationSymbols>
class StateEmissionProbabilityDistributionMatrix {
    
private:
    
    std::array<std::array<double, numberOfObservationSymbols>, numberOfStates> propabilityDistributionMatrix;
    
    StateEmissionProbabilityDistributionMatrix() { }
    
public:
    
    StateEmissionProbabilityDistributionMatrix(const std::array<std::array<double, numberOfObservationSymbols>, numberOfStates> &propabilityDistributionMatrix) {
        this->propabilityDistributionMatrix = propabilityDistributionMatrix;
    }
    
    std::size_t getNumberOfStates() {
        return this->propabilityDistributionMatrix.size();
    }
    
    std::size_t getNumberOfObservationSymbols() {
        if (this->propabilityDistributionMatrix.empty()) {
            return 0;
        } else {
            return this->propabilityDistributionMatrix[0].size();
        }
    }
    
    double getPropability(int stateIndex, int observationSymbolIndex) {
        assert(stateIndex >= 0 && stateIndex < getNumberOfStates() &&
               observationSymbolIndex >= 0 && observationSymbolIndex < getNumberOfObservationSymbols());
        return this->propabilityDistributionMatrix[stateIndex][observationSymbolIndex];
    }
    
};

#endif
