
cmake_minimum_required(VERSION 3.0.0)

enable_testing()

if (NOT ((TARGET gtest) AND (TARGET gtest_main)))
    message(FATAL_ERROR "gtest and gtest_main targets NOT found")
endif()

set(HMM_TESTS_NAME
    HMMTests
)
set(HMM_TESTS_SOURCE
    InitialStateProbabilityDistributionTests.cpp
    StateTransitionProbabilityDistributionMatrixTests.cpp
    StateEmissionProbabilityDistributionMatrixTests.cpp

    ModelTests.cpp
)
add_executable(${HMM_TESTS_NAME} ${HMM_TESTS_SOURCE})
target_link_libraries(${HMM_TESTS_NAME} 
    gtest 
    gtest_main 
    ${HMM_LIBRARY_NAME}
)
add_test(${HMM_TESTS_NAME} ${HMM_TESTS_NAME})
