/* Including files*/
#include "layer.h"
#include "comp_algo.h"
#include "benchmark.h"

/* Main function*/
int main() {

    /* Paramater for a layer */
    uint8_t nb_filter = 32;
    uint8_t kern_width = 5;
    uint8_t nb_channel = 3;

    /* Creation of the layer */
    Layer L1(computeLayerSize(nb_filter, nb_channel, kern_width));

    /* Benchmarking the RLE algorithm */
    benchmark(RLE_ENCODING, L1);

    return 0;
}