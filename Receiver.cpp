#include "Receiver.h"

Receiver::Receiver(int pinNumber, int nSignal)
  : ir(pinNumber), result(), signals(new unsigned long[nSignal]), nSignal(nSignal) {
}

Receiver::~Receiver() {
  delete[] signals;
}

inline unsigned long Receiver::resultValue() {
  return reinterpret_cast<unsigned long>(result.value);
}

void Receiver::init() {
  ir.enableIRIn();
}

bool Receiver::registerSignal(int index, unsigned long signal) {
  if (index >= nSignal) {
    return false;
  }
  
  signals[index] = signal;
  return true;
}

bool Receiver::isReceived() {
  return ir.decode(&result) == 1;
}

int Receiver::receivedIndex() {
  for (int i = 0; i < nSignal; i++) {
    if (resultValue() == signals[i]) {
      return i;
    }
  }

  return -1;
}

unsigned long Receiver::lastReceivedValue() {
  return resultValue();
}

void Receiver::resume() {
  ir.resume();
}
