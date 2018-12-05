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

#define DATA_POINTS 1024
#define SAMPLING_PERIOD 1e-3
#define N_USED_SENSORS 4 // len([ADC0..ADC3])

// Sensors attached to A0-A3 in the Galileo shield
typedef struct sensors {
    uint16_t adc0;     // big-endian:   u12/16>>0
    uint16_t adc1;     // big-endian:   u12/16>>0
    uint16_t adc2;     // big-endian:   u12/16>>0
    uint16_t adc3;     // big-endian:   u12/16>>0
    int64_t timestamp; // little-endian:s64/64>>0
} SENSORS_DATA;

// Data got in the sensors attached to A0-A3 in the Galileo shield
typedef struct adc_data {
    double adc0_data;
    double adc1_data;
    double adc2_data;
    double adc3_data;
    double elapsed_time;
} ADC_DATA;

/** Init needed triggers for using the continuous mode of the Galileo's ADC.
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int initAdcContinuous();

/** Get data from the ADC pins into the data structures.
  * @param:  {SENSORS_DATA*} sensors line data.
             {ADC_DATA*} obtained scaled data.
  * @return: {int} status of the operation.
  */
int captureAdcContinuous(SENSORS_DATA* rawData, ADC_DATA* finalData);

/** End connection with the ADC.
  * @param:  {void}.
  * @return: {int} status of the operation.
  */
int endAdc();

#endif
