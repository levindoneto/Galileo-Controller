#include  "../../../include/components/potentiometer/potentiometer.h"

int getDatePotentiometer() {

}

int read_pot()
{
    // char data_str[80];
    // struct sensors data[100];
    // float scale;
    // int samples;
    // int fd;
    // float pot;
    // int i;
    //
    // pputs("/sys/bus/iio/devices/iio:device0/buffer/enable","0");
    // pgets(data_str, sizeof data_str, "/sys/bus/iio/devices/iio:device0/in_voltage0_scale");
    // scale = atof(data_str)/1000.0;
    //
    // pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_voltage0_en", "1");
    //
    // pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_timestamp_en", "1");
    // snprintf(data_str,sizeof data_str,"%d", 100);
    // pputs("/sys/bus/iio/devices/iio:device0/buffer/length", data_str);
    //
    //
    // pgets(data_str, sizeof data_str, "/sys/bus/iio/devices/trigger0/name");
    // pputs("/sys/bus/iio/devices/iio:device0/trigger/current_trigger",data_str);
    //
    // snprintf(data_str,sizeof data_str,"%d", 1000);
    // pputs("/sys/bus/iio/devices/trigger0/frequency", data_str);
    //
    // pputs("/sys/bus/iio/devices/iio:device0/buffer/enable","1");
    //
    // //usleep(100000);
    // sleep(ceil(DATA_POINTS * SAMPLING_PERIOD));
    //
    // pputs("/sys/bus/iio/devices/iio:device0/buffer/enable","0");
    //
    // pputs("/sys/bus/iio/devices/iio:device0/trigger/current_trigger","\n");
    //
    //
    // if((fd = open("/dev/iio:device0",O_RDONLY)) < 0)
    // {
    // perror("Opening /dev/iio:device0:");
    // return -1;
    // }
    //
    //
    // samples = read(fd,data,sizeof data)/sizeof(struct sensors);
    // close(fd);
    // printf("SAMPLES READ: %d\n", samples);
    //
    // pputs("/sys/bus/iio/devices/iio:device0/buffer/length","2");
    //
    // pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_voltage0_en","0");
    // pputs("/sys/bus/iio/devices/iio:device0/scan_elements/in_timestamp_en","0");
    //
    //
    // //printf("scale: %f\n", scale);
    // avg = 0;
    // for(i=0;i < samples; i++) {
    // pot = bswap_16(data[0].pot) * scale;
    // avg += pot;
    // //printf("Pot: %f\n", pot);
    // }
    // avg = avg/samples;
    //
    //
    // std = 0;
    // for(i=0;i < samples;i++) {
    // pot = bswap_16(data[0].pot) * scale;
    // std += (pot - avg) * (pot - avg);
    // }
    // std = std/samples;


    return 0;
}
