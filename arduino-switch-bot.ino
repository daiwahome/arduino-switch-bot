#include "Receiver.h"
#include "Switch.h"

#define _DEBUG 0

#define PIN_IR    2
#define PIN_SERVO 5

#define SERVO_ANGLE 20

enum IRSignal : unsigned long {
  SIGNAL_BEDROOM_ON  = 0x51E43D1B,
  SIGNAL_BEDROOM_OFF = 0xC4DA2201,
};

enum IRSignalIndex : int {
  BEDROOM_ON = 0,
  BEDROOM_OFF,
  N_SIGNAL,
};

Receiver receiver = Receiver(PIN_IR, N_SIGNAL);
Switch bedroomSwitch = Switch(PIN_SERVO, SERVO_ANGLE);

void setup() {
#if _DEBUG == 1
  Serial.begin(9600);
#endif
  
  receiver.init();
  receiver.registerSignal(BEDROOM_ON, SIGNAL_BEDROOM_ON);
  receiver.registerSignal(BEDROOM_OFF, SIGNAL_BEDROOM_OFF);
  
  bedroomSwitch.init();
}

void loop() {
  if (!receiver.isReceived()) {
    delay(100);
    return;
  }
  
#if _DEBUG == 1
  Serial.println(receiver.lastReceivedValue(), HEX);
#endif

  switch (receiver.receivedIndex()) {
  case BEDROOM_ON:
    bedroomSwitch.on();
    break;
  case BEDROOM_OFF:
    bedroomSwitch.off();
    break;
  }

  receiver.resume();
}
