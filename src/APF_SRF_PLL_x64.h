#ifndef APF_SRF_PLL_X64_
#define APF_SRF_PLL_X64_


// Para funções trigonométricas
#include "hls_math.h"

// biblioteca usada para ponto fixo
#include <ap_fixed.h>

//para "arbitrary precision" em C++
#include "ap_int.h" 


// Fixed-point de 32 bits, com 7 bits a esquerda do ponto.
typedef  ap_fixed<64,16, AP_TRN, AP_WRAP> data_t;

// Bit para servir de trigger da interrupção
typedef ap_uint<1> uint1_t;

//Definições
#define Ts data_t(500e-9)
#define Ts2 data_t(500e-9)
#define pi data_t(3.141592653589793)
#define pi2 data_t(6.283185307179586)
#define pi2Ts data_t(3.14159265358979e-6)


// Constantes dos PLLs
#define Kpf data_t(30.0)
#define Kif data_t(1000.0)
#define w0 data_t(300.0)
#define wc data_t(120.0)
#define K data_t(2.0)


// Cabeçalho
data_t sin_2000(data_t theta);
data_t cos_2000(data_t theta);
void APF_SRF_PLL_x64(uint1_t sinc,  data_t vin,
                                    data_t *wout,
                                    data_t *vdout,
                                    data_t *vqout,
                                    data_t *yout,
                                    data_t *thetaout,
                                    data_t *Aout,
                                    data_t *valphaout,
                                    data_t *vbetaout,
                                    data_t *vsigmaout);






#endif
