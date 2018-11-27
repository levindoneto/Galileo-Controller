TARGET=controller
SRCS=commons/errors.c components/pushbutton/pushbuttonconfig.c components/pushbutton/pushbutton.c components/potentiometer.c components/servomotor.c components/display/lcdconfig.c components/display/backlightconfig.c components/display/lcd.c $(TARGET).c

FLAGS=-O2 -MMD
INCLUDE=-I. -I../include/components/display
LIBDIR=-L../lib
LIBS=-lgalileo2

CC=$(CROSS_COMPILE)gcc
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)

all: $(TARGET)

$(TARGET): $(SRCS:.c=.o)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.c=.d)

clean:
	rm -f *~ *.bak *.o *.d components/display/*.d components/display/*.o \
	commons/*.o commons/*.d  components/*.o  components/*.d components/pushbutton*.d components/pushbutton*.o\
	 components/pushbuttonconfig*.d components/pushbuttonconfig*.o

distclean: clean
	rm -f $(TARGET)
