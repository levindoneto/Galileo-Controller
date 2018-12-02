echo ">>> Moving configuration bash files to the root of the GalileoGen2... <<<"
scp lcd_I2C root@192.168.0.13:
scp pwm1_IO3 root@192.168.0.13:
#scp pwm3_IO5 root@192.168.0.13:
#scp pushbutton_IO4 root@192.168.0.13:
scp led_IO6 root@192.168.0.13:
scp adc_IO14-IO15-IO16-IO17_continuous root@192.168.0.13:
#scp adc_IO14_oneshot root@192.168.0.13:
echo ">>> All moved, please follow the correct setup, which may be seen on this folder's README <<<"
