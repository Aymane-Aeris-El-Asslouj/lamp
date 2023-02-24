//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB52_Register_Enums.h>
#include "state_machine.h"
#include "command_handler.h"
#include "Interrupts.h"

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------

uint8_t previous_pressed = 0;
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
  {
    uint8_t pressed = 0;
    if ((P3 & P3_B0__BMASK) != P3_B0__BMASK)
      {
        pressed = 1;
      }

    if (pressed != previous_pressed)
      {
        previous_pressed = pressed;
        current_event = EV_BUTTON_PUSHED;
      }
  }

