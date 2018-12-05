#include <byteswap.h>
#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libgalileo/galileo2io.h"
#include "galileo/adc_continuous.h"

static double scale[N_USED_SENSORS];

int initAdcContinuous() {
    char path_str[80];
    char data_str[80];
    int i;
    pputs("/sys/bus/iio/devices/iio:device0/buffer/enable","0");

    // Configure the ADC's scale
    for(i=0; i < N_USED_SENSORS; i++) {
        snprintf(path_str,sizeof path_str,"/sys/bus/iio/devices/iio:device0/in_voltage%d_scale",i);
        pgets(data_str, sizeof data_str, path_str);
        scale[i] = atof(data_str)/1000.0;
        snprintf(path_str,sizeof path_str,"/sys/bus/iio/devices/iio:device0/scan_elements/in_voltage%d_en",i);
        pputs(path_str, "1");
    }
    pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_timestamp_en","1");

    snprintf(data_str,sizeof data_str,"%d",DATA_POINTS);
    pputs("/sys/bus/iio/devices/iio:device0/buffer/length",data_str);

    #ifdef TRIG_SYSFS
    pgets(data_str,sizeof data_str,"/sys/bus/iio/devices/trigger0/name");
    pputs("/sys/bus/iio/devices/iio:device0/trigger/current_trigger",data_str);
    #else
    pgets(data_str,sizeof data_str,"/sys/bus/iio/devices/trigger1/name");
    pputs("/sys/bus/iio/devices/iio:device0/trigger/current_trigger",data_str);
    snprintf(data_str,sizeof data_str,"%d",(int)round(1.0/SAMPLING_PERIOD));
    pputs("/sys/bus/iio/devices/trigger1/frequency",data_str);
    #endif

    return SUCCESS;
}

int captureAdcContinuous(SENSORS_DATA* raw_data, ADC_DATA* final_data) {
    char path_str[80];
    int fd;
    int samples;
    int i;
    pputs("/sys/bus/iio/devices/iio:device0/buffer/enable", "1");

    #ifdef TRIG_SYSFS
    for(i=0; i < DATA_POINTS; i++) {
        pputs("/sys/bus/iio/devices/trigger0/trigger_now","1");
        usleep(ceil(SAMPLING_PERIOD*1e6));
    }
    #else
    sleep(ceil(DATA_POINTS*SAMPLING_PERIOD));
    #endif

    pputs("/sys/bus/iio/devices/iio:device0/buffer/enable", "0");
    if((fd=open("/dev/iio:device0", O_RDONLY)) < 0) {
        perror("Opening /dev/iio:device0:");
        return -1;
    }
    if(raw_data == NULL) {
        throwError("Raw data structure for ADC continuous mode is NULL.\n");
    }
    if(final_data == NULL) {
        throwError("Final data structure for ADC continuous mode is NULL.\n");
    }

    int lengthRequested = DATA_POINTS*sizeof(struct sensors);
    // Get samples from the sensors
    printf("\nsizeof: %d", DATA_POINTS*sizeof(struct sensors));
    samples = read(fd, raw_data, lengthRequested) / sizeof(struct sensors); // Read bytes
    printf("\nSamples: %d", samples);
    close(fd);

    for(i=0; i < samples; i++) { // Go through all the obtained data
        // Sensors
        raw_data[i].adc0=bswap_16(raw_data[i].adc0);
        raw_data[i].adc1=bswap_16(raw_data[i].adc1);
        raw_data[i].adc2=bswap_16(raw_data[i].adc2);
        raw_data[i].adc3=bswap_16(raw_data[i].adc3);
        // Obtained data
        final_data[i].adc0_data = raw_data[i].adc0 * scale[0];
        final_data[i].adc1_data = raw_data[i].adc1 * scale[1];
        final_data[i].adc2_data = raw_data[i].adc2 * scale[2];
        final_data[i].adc3_data = raw_data[i].adc3 * scale[3];
        printf("final_data[i].adc0_data: %lf\n", final_data[i].adc0_data);
        final_data[i].elapsed_time = (raw_data[i].timestamp - raw_data[0].timestamp) * 1e-9;
    }
    return 0;
}

int endAdc() {
    char path_str[80];
    int i;
    pputs("/sys/bus/iio/devices/iio:device0/buffer/length", "2");
    for(i=0; i < N_USED_SENSORS; i++) {
        snprintf(path_str, sizeof path_str,
                 "/sys/bus/iio/devices/iio:device0/scan_elements/in_voltage%d_en",i);
        pputs(path_str, "0");
    }
    pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_timestamp_en","0");
    return pputs("/sys/bus/iio/devices/iio:device0/trigger/current_trigger", "\n");
}
