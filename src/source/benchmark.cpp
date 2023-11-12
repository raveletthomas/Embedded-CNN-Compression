#include "benchmark.h"

void benchmark(enum EncodingAlorithm E, Layer& L) {

    /* Declaration of functions pointers */
    void (*compression_func)(Layer&);
    void (*decompression_func)(Layer&);

    /* Switch to select the good functions for the algorithm*/
    switch (E) {

    case RLE_ENCODING:
        compression_func = compressionRLE;
        decompression_func = decompressionRLE;
        break;
    
    default:
        break;

    }

    /* Getting the initial size of L*/
    int N1 = (int) L.getSize();

    /*** Start of the compression benchmark ***/
    auto start_compression = HRC::now();

    compression_func(L);

    auto end_compression = HRC::now();
    int N2 = (int) L.getSize();
    /*** End of the compression benchmark ***/

    /*** Start of the decompression benchmark ***/
    auto start_decompression = HRC::now();

    decompression_func(L);

    auto end_decompression = HRC::now();
    /*** End of the decompression benchmark ***/

    /* Computation of the algorithm performance */
    auto exec_comp_time = std::chrono::duration_cast<mSEC>(end_compression - start_compression);
    auto exec_decomp_time = std::chrono::duration_cast<uSEC>(end_decompression - start_decompression);
    auto total = exec_comp_time.count() + (double) exec_decomp_time.count() / 1000;
    float gain = ( ((float)N1 - (float)N2) / (float) N1 ) * 100;

    /* Printing results */
    std::cout << "\n----------------------- Time Performance -----------------------" << std::endl;
    std::cout << "Compression time: ~~~~~ " << exec_comp_time.count() << " ms" << std::endl;
    std::cout << "Decompression time: ~~~ " << (double) exec_decomp_time.count() / 1000 << " ms" << std::endl;
    std::cout << "Total execution time: ~ " << total << " ms" << std::endl;
    std::cout << "\n---------------------- Memory Performance ----------------------" << std::endl;
    std::cout << "Initial size: ~~~~~~~~~ " << (double) N1 * 8 / 1000 << " ko" << std::endl;
    std::cout << "Compressed size: ~~~~~~ " << (double) N2 * 8 / 1000 << " ko" << std::endl;
    std::cout << "Compression gain : ~~~~ " << gain << "%\n" << std::endl;
}