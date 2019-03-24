TARGETRX=rx
TARGETTX=tx
UTILS=utils/conversion/types_conversion.c utils/conversion/measurement_conversion.c utils/datetime.c utils/utils.c
COMMONS=commons/errors.c
GALILEO=galileo/pwm.c galileo/adc_continuous.c galileo/eeprom.c
CONFIGTXRX=components/pushbutton/pushbutton.c components/pushbutton/configTx.c components/pushbutton/configRx.c
DISPLAY=components/display/lcdconfig.c components/display/backlightconfig.c components/display/lcd.c
COMPONENTS=$(CONFIGTXRX) $(DISPLAY)
SRCSRX=$(COMMONS) $(UTILS) $(GALILEO) $(COMPONENTS) $(TARGETRX).c
SRCSTX=$(COMMONS) $(UTILS) $(GALILEO) $(COMPONENTS) $(TARGETTX).c

FLAGS=-MMD # -O2 cannot be used for using the Galileo's continuous mode
INCLUDE=-I. -I../include/
LIBDIR=-L../lib
LIBS=-lgalileo2

CC=$(CROSS_COMPILE)gcc
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)

all: $(TARGETRX) $(TARGETTX)

$(TARGETRX): $(SRCSRX:.c=.o)
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGETTX): $(SRCSTX:.c=.o)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.c=.d)

clean:
	rm -f *~ *.bak *.o *.d \
	components/display/*.d components/display/*.o \
	commons/*.o commons/*.d \
	components/pushbutton/*.d components/pushbutton/*.o \
	utils/*.d utils/*.o utils/conversion/*.d utils/conversion/*.o \
	galileo/*.d galileo/*.o

distclean: clean
	rm -f $(TARGETTX) $(TARGETRX)
