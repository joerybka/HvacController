//
// Created by joerr on 28-Apr-24.
//

#include "PinController.h"

#ifndef HVACCONTROLLER_RELAYCONTROLLER_H
#define HVACCONTROLLER_RELAYCONTROLLER_H

class RelayController {
private:
  bool _isNormallyOpen;

  PinController _pin;

public:
  RelayController(uint8_t pinNumber, bool isNormallyClosed = false);

  void Initialize();

  void Close();

  void Open();

  void Toggle();

  bool IsClosed();

  bool IsOpen();
};

#endif //HVACCONTROLLER_RELAYCONTROLLER_H
