
#ifndef __HMM__InitialStateProbabilityDistribution__
#define __HMM__InitialStateProbabilityDistribution__

#include <array>
#include <assert.h>

template<std::size_t numberOfStates>
class InitialStateProbabilityDistribution {
    
private:
    
    std::array<double, numberOfStates> propabilityDistribution;
    
    InitialStateProbabilityDistribution() { }
    
public:
    
    InitialStateProbabilityDistribution(const std::array<double, numberOfStates> &propabilityDistribution) {
        this->propabilityDistribution = propabilityDistribution;
    }
    
    std::size_t getNumberOfStates() {
        return this->propabilityDistribution.size();
    }
    double getPropability(int state) {
        assert(state >= 0 && state < getNumberOfStates());
        return this->propabilityDistribution[state];
    }
    
};

#endif
