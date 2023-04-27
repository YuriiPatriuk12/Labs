#include "MainFunctions.h"
int main() {
    //Two-dimensional vectors
    TwoDimensionalVector two_dim_vectors[] = {
            TwoDimensionalVector(2,1),
            TwoDimensionalVector(4,2),
            TwoDimensionalVector(6,1)
    };
    sumOfParallelTwoDimensionalVectors(two_dim_vectors,3);

    //Three-dimensional vectors
    ThreeDimensionalVector three_dim_vectors[] = {
            ThreeDimensionalVector(1, 2, 0),
            ThreeDimensionalVector(2, -1, 10),
            ThreeDimensionalVector(4, -2, 3),
            ThreeDimensionalVector(2, 4, 7)
    };
    sumOfPerpendicularThreeDimensionalVectors(three_dim_vectors,4);

    return 0;
}
