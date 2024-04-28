//
// Created by joerr on 28-Apr-24.
//

#include "RelayController.h"

RelayController::RelayController(uint8_t pinNumber, bool isNormallyClosed) : _isNormallyOpen(!isNormallyClosed), _pin(pinNumber, OUTPUT) {}

void RelayController::Initialize() {
  _pin.Initialize();
}

void RelayController::Close() {
  if(_isNormallyOpen)
    _pin.SetPinOn();
  else
    _pin.SetPinOff();
}

void RelayController::Open() {
  if(_isNormallyOpen)
    _pin.SetPinOff();
  else
    _pin.SetPinOn();
}

void RelayController::Toggle() {
  if(_pin.IsOn())
    _pin.SetPinOff();
  else
    _pin.SetPinOn();
}

bool RelayController::IsClosed() {
  return _isNormallyOpen ? _pin.IsOn() : _pin.IsOff();
}

bool RelayController::IsOpen() {
  return _isNormallyOpen ? _pin.IsOff() : _pin.IsOn();
}