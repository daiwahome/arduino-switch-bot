#ifndef _RECEIVER_H
#define _RECEIVER_H

#include <IRremote.h>

class Receiver {
  IRrecv ir;
  decode_results result;
  unsigned long* signals;
  int nSignal;

  unsigned long resultValue();

public:
  Receiver(int pinNumber, int nSignal);
  ~Receiver();

  void init();
  bool registerSignal(int index, unsigned long signal);
  bool isReceived();
  int receivedIndex();
  unsigned long lastReceivedValue();
  void resume();
};

#endif /* _RECEIVER_H */
