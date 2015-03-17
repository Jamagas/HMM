
cmake_minimum_required(VERSION 3.0.0)

enable_testing()

set(HMM_PROJECT_NAME
    "HMM project"
)
set(HMM_LIBRARY_NAME
    HMM
)
set(HMM_HEADERS_DIR
    include/${HMM_LIBRARY_NAME}
)
set(HMM_HEADERS
    ${HMM_HEADERS_DIR}/HMM.h
    
    ${HMM_HEADERS_DIR}/Model.h
    ${HMM_HEADERS_DIR}/StateTransitionProbabilityDistributionMatrix.h
    ${HMM_HEADERS_DIR}/StateEmissionProbabilityDistributionMatrix.h
    ${HMM_HEADERS_DIR}/InitialStateProbabilityDistribution.h
    
    ${HMM_HEADERS_DIR}/BaumWelchAlgorithm.h
)
set(HMM_SOURCE_DIR
    src
)
set(HMM_SOURCE
    ${HMM_SOURCE_DIR}/HMM.cpp
    
    ${HMM_SOURCE_DIR}/Model.cpp
    ${HMM_SOURCE_DIR}/StateTransitionProbabilityDistributionMatrix.cpp
    ${HMM_SOURCE_DIR}/StateEmissionProbabilityDistributionMatrix.cpp
    ${HMM_SOURCE_DIR}/InitialStateProbabilityDistribution.cpp
    
    ${HMM_SOURCE_DIR}/BaumWelchAlgorithm.cpp
)

project(${HMM_PROJECT_NAME})

add_library(${HMM_LIBRARY_NAME} STATIC
    ${HMM_HEADERS}
    ${HMM_SOURCE}
)

target_include_directories(${HMM_LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${HMM_LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${HMM_LIBRARY_NAME}>
)

target_include_directories(${HMM_LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (NOT ((TARGET gtest) AND (TARGET gtest_main)))
    add_subdirectory(libs/gtest)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()

add_subdirectory(test)
