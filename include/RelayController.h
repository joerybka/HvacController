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
  /**
   * Create a controller that uses the identified pin to control a relay
   * circuit.
   * @param pinNumber The number of the IO pin to use when controlling the relay
   * @param isNormallyClosed  True if the relay is wired normally closed, defaults to false
   */
  RelayController(uint8_t pinNumber, bool isNormallyClosed = false);

  /**
   * Run all initialization code, call this in setup()
   */
  void Initialize();

  /**
   * Close the relay, controls the pin to properly set it to closed
   */
  void Close();

  /**
   * Open the relay, controls the pin to properly set it to open
   */
  void Open();

  /**
   * Toggle the relay to the opposite state, under the covers it toggles
   * the pin from its current state to the opposite state.  Unless you have
   * a fast relay, be careful calling this too much or too quickly.
   */
  void Toggle();

  /**
   * Check if the relay is currently closed.
   * @return True if the relay is closed, otherwise false
   */
  bool IsClosed();

  /**
   * Check if the relay is currently open.
   * @return True if the relay is open, otherwise false
   */
  bool IsOpen();
};

#endif //HVACCONTROLLER_RELAYCONTROLLER_H
