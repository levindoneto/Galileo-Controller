#ifndef CONTINUOUS_H_
#define CONTINUOUS_H_ 

#define DATA_POINTS 1000
#define SAMPLING_PERIOD 1e-3
 
/* Assumes the data format for Galileo Gen2 */
struct sensors {
        uint16_t adc0;       /* be:u12/16>>0 */
        uint16_t adc1;     /* be:u12/16>>0 */
        uint16_t adc2;     /* be:u12/16>>0 */
        uint16_t adc3;      /* be:u12/16>>0 */
        int64_t timestamp;  /* le:s64/64>>0 */
};

struct adc_data {
	double adc0_data;
	double adc1_data;
	double adc2_data;
	double adc3_data;
	double elapsed_time;
};

#endif
