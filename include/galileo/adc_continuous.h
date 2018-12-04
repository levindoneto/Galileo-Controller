#ifndef CONTINUOUS_H_
#define CONTINUOUS_H_

#include <byteswap.h>
#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../libgalileo/galileo2io.h"
#include "../commons/status.h"
#include "../commons/errors.h"

#define DATA_POINTS 100
#define SAMPLING_PERIOD 1e-3
#define N_USED_SENSORS 1 // len([ADC0..ADC3])

// Sensors attached to A0-A3 in the Galileo shield
struct sensors {
    uint16_t adc0;     // big-endian:   u12/16>>0
    uint16_t adc1;     // big-endian:   u12/16>>0
    uint16_t adc2;     // big-endian:   u12/16>>0
    uint16_t adc3;     // big-endian:   u12/16>>0
    int64_t timestamp; // little-endian:s64/64>>0
};

// Data got in the sensors attached to A0-A3 in the Galileo shield
struct adc_data {
    double adc0_data;
    double adc1_data;
    double adc2_data;
    double adc3_data;
    double elapsed_time;
};

/** Init needed triggers for using the continuous mode of the Galileo's ADC.
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int initAdcContinuous();

/** Get data from the ADC pins into the data structures.
  * @param:  {struct sensors*} sensors line data.
             {struct adc_data*} obtained data.
  * @return: {float} adc[0]'s avg value within the data collection.
  */
float captureAdcContinuous();

#endif
