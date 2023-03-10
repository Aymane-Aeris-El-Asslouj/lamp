//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB52_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void
enter_DefaultMode_from_RESET (void)
{
  // $[Config Calls]
  // Save the SFRPAGE
  uint8_t SFRPAGE_save = SFRPAGE;
  WDT_0_enter_DefaultMode_from_RESET ();
  PORTS_0_enter_DefaultMode_from_RESET ();
  PORTS_2_enter_DefaultMode_from_RESET ();
  PORTS_3_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  CLOCK_0_enter_DefaultMode_from_RESET ();
  CIP51_0_enter_DefaultMode_from_RESET ();
  TIMER01_0_enter_DefaultMode_from_RESET ();
  TIMER16_2_enter_DefaultMode_from_RESET ();
  TIMER16_3_enter_DefaultMode_from_RESET ();
  TIMER16_4_enter_DefaultMode_from_RESET ();
  TIMER_SETUP_0_enter_DefaultMode_from_RESET ();
  PWM_0_enter_DefaultMode_from_RESET ();
  SMBUS_0_enter_DefaultMode_from_RESET ();
  UART_0_enter_DefaultMode_from_RESET ();
  EXTINT_0_enter_DefaultMode_from_RESET ();
  INTERRUPT_0_enter_DefaultMode_from_RESET ();
  // Restore the SFRPAGE
  SFRPAGE = SFRPAGE_save;
  // [Config Calls]$

}

extern void
WDT_0_enter_DefaultMode_from_RESET (void)
{
  // $[Watchdog Timer Init Variable Declarations]
  uint32_t i;
  bool ea;
  // [Watchdog Timer Init Variable Declarations]$

  // $[WDTCN - Watchdog Timer Control]
  SFRPAGE = 0x00;

  // Feed WDT timer before disabling (Erratum WDT_E102)
  WDTCN = 0xA5;

  // Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
  for (i = 0; i < (2 * 3062500UL) / (80000 * 3); i++)
    {
      NOP ();
    }

  // Disable WDT
  ea = IE_EA;
  IE_EA = 0;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  IE_EA = ea;

  // [WDTCN - Watchdog Timer Control]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  /***********************************************************************
   - P0.0 output is open-drain
   - P0.1 output is open-drain
   - P0.2 output is push-pull
   - P0.3 output is push-pull
   - P0.4 output is push-pull
   - P0.5 output is open-drain
   - P0.6 output is open-drain
   - P0.7 output is open-drain
   ***********************************************************************/
  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
      | P0MDOUT_B2__PUSH_PULL | P0MDOUT_B3__PUSH_PULL | P0MDOUT_B4__PUSH_PULL
      | P0MDOUT_B5__OPEN_DRAIN | P0MDOUT_B6__OPEN_DRAIN
      | P0MDOUT_B7__OPEN_DRAIN;
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  /***********************************************************************
   - P0.0 pin is configured for digital mode
   - P0.1 pin is configured for digital mode
   - P0.2 pin is configured for digital mode
   - P0.3 pin is configured for digital mode
   - P0.4 pin is configured for digital mode
   - P0.5 pin is configured for digital mode
   - P0.6 pin is configured for digital mode
   - P0.7 pin is configured for analog mode
   ***********************************************************************/
  P0MDIN = P0MDIN_B0__DIGITAL | P0MDIN_B1__DIGITAL | P0MDIN_B2__DIGITAL
      | P0MDIN_B3__DIGITAL | P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL
      | P0MDIN_B6__DIGITAL | P0MDIN_B7__ANALOG;
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  /***********************************************************************
   - P0.0 pin is not skipped by the crossbar
   - P0.1 pin is not skipped by the crossbar
   - P0.2 pin is not skipped by the crossbar
   - P0.3 pin is not skipped by the crossbar
   - P0.4 pin is not skipped by the crossbar
   - P0.5 pin is not skipped by the crossbar
   - P0.6 pin is skipped by the crossbar
   - P0.7 pin is not skipped by the crossbar
   ***********************************************************************/
  P0SKIP = P0SKIP_B0__NOT_SKIPPED | P0SKIP_B1__NOT_SKIPPED
      | P0SKIP_B2__NOT_SKIPPED | P0SKIP_B3__NOT_SKIPPED | P0SKIP_B4__NOT_SKIPPED
      | P0SKIP_B5__NOT_SKIPPED | P0SKIP_B6__SKIPPED | P0SKIP_B7__NOT_SKIPPED;
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

}

extern void
PBCFG_0_enter_DefaultMode_from_RESET (void)
{
  // $[XBR2 - Port I/O Crossbar 2]
  /***********************************************************************
   - Weak Pullups enabled 
   - Crossbar enabled
   - PWM single ended output for all enabled channels
   - UART1 I/O unavailable at Port pin
   - UART1 RTS1 unavailable at Port pin
   - UART1 CTS1 unavailable at Port pin
   - PWM0 Ch0 and Ch1 routed to Port pin
   ***********************************************************************/
  SFRPAGE = 0x00;
  XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED
      | XBR2_PWMDE__SINGLE | XBR2_URT1E__DISABLED | XBR2_URT1RTSE__DISABLED
      | XBR2_URT1CTSE__DISABLED | XBR2_PWME__PWM0CH01;
  // [XBR2 - Port I/O Crossbar 2]$

  // $[PRTDRV - Port Drive Strength]
  // [PRTDRV - Port Drive Strength]$

  // $[XBR0 - Port I/O Crossbar 0]
  /***********************************************************************
   - UART0 TX0, RX0 routed to Port pins P0.4 and P0.5
   - SPI I/O unavailable at Port pins
   - SMBus 0 I/O routed to Port pins
   - CP0 unavailable at Port pin
   - Asynchronous CP0 unavailable at Port pin
   - CP1 unavailable at Port pin
   - Asynchronous CP1 unavailable at Port pin
   - SYSCLK unavailable at Port pin
   ***********************************************************************/
  XBR0 = XBR0_URT0E__ENABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__ENABLED
      | XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
      | XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  // [XBR1 - Port I/O Crossbar 1]$

}

extern void
CLOCK_0_enter_DefaultMode_from_RESET (void)
{
  // $[HFOSC0 49 and 49/1.5 MHz Oscillator Setup]
  // Ensure SYSCLK is > 24 MHz before switching to 49 MHz or 49/1.5 MHz Oscillator
  CLKSEL = CLKSEL_CLKSL__HFOSC0_clk24p5 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
  while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
    ;
  // [HFOSC0 49 and 49/1.5 MHz Oscillator Setup]$

  // $[CLKSEL - Clock Select]
  /***********************************************************************
   - Clock derived from the Internal High Frequency Oscillator 49 MHz
   - SYSCLK is equal to selected clock source divided by 1
   ***********************************************************************/
  CLKSEL = CLKSEL_CLKSL__HFOSC0_clk49 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
  while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
    ;
  // [CLKSEL - Clock Select]$

  // $[CLKGRP0 - Clock Group 0]
  // [CLKGRP0 - Clock Group 0]$

}

extern void
CIP51_0_enter_DefaultMode_from_RESET (void)
{
  // $[PFE0CN - Prefetch Engine Control]
  /***********************************************************************
   - Enables the Prefetch Engine when SYSCLK < 50 MHz
   ***********************************************************************/
  SFRPAGE = 0x10;
  PFE0CN = PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ;
  // [PFE0CN - Prefetch Engine Control]$

}

extern void
PWM_0_enter_DefaultMode_from_RESET (void)
{
  // $[Stop PWM]
  SFRPAGE = 0x10;
  PWMCFG1 &= ~(PWMCFG1_PWMEN__BMASK);
  // [Stop PWM]$

  // $[PWMCKDIV - PWMCKDIV]
  // [PWMCKDIV - PWMCKDIV]$

  // $[PWMCFG0 - PWM Configuration 0]
  /***********************************************************************
   - Enable clock to the PWM module
   - PWM will operate in Edge-aligned mode
   - No channels will be synchronously updated
   - PWM will continue running on breakpoints in debug mode
   - Rising edge on the enabled external trigger will start PWM counter
   - Disable Kill0 signal to halt the PWM
   - Disable Kill1 signal to halt the PWM
   ***********************************************************************/
  PWMCFG0 = PWMCFG0_PWMCLKEN__ENABLE | PWMCFG0_PWMMODE__EDGE
      | PWMCFG0_SYNCUPD__NOSYNCUPD | PWMCFG0_DBGSTLEN__DISABLE
      | PWMCFG0_TRGESEL__REDGE | PWMCFG0_KILL0EN__DISABLE
      | PWMCFG0_KILL1EN__DISABLE;
  // [PWMCFG0 - PWM Configuration 0]$

  // $[PWMCFG1 - PWM Configuration 1]
  // [PWMCFG1 - PWM Configuration 1]$

  // $[PWMCFG2 - PWM Configuration 2]
  // [PWMCFG2 - PWM Configuration 2]$

  // $[PWMCFG3 - PWMCFG3]
  // [PWMCFG3 - PWMCFG3]$

  // $[PWML - PWML]
  // [PWML - PWML]$

  // $[PWMH - PWMH]
  // [PWMH - PWMH]$

  // $[PWMLIML - PWMLIML]
  /***********************************************************************
   - PWM Counter Limit LSB = 0xFF
   ***********************************************************************/
  PWMLIML = (0xFF << PWMLIML_PWMLIML__SHIFT);
  // [PWMLIML - PWMLIML]$

  // $[PWMLIMH - PWMLIMH]
  /***********************************************************************
   - PWM Counter Limit MSB = 0xFF
   ***********************************************************************/
  PWMLIMH = (0xFF << PWMLIMH_PWMLIMH__SHIFT);
  // [PWMLIMH - PWMLIMH]$

  // $[PWMDTIPLIM - PWMDTIPLIM]
  // [PWMDTIPLIM - PWMDTIPLIM]$

  // $[PWMDTINLIM - PWMDTINLIM]
  // [PWMDTINLIM - PWMDTINLIM]$

  // $[PWMIE - PWMIE]
  // [PWMIE - PWMIE]$

  // Set the compare registers of channels 0 and 1 to sensible initial values.
  // This is done synchronously, although that's not strictly necessary at this
  // time since we haven't enabled the peripheral yet.
  // See pwm_set() for further information.
  PWMCFG0 &= ~PWMCFG0_SYNCUPD__FMASK;
  PWMCPUDL0 = DEFAULT_PWM_CHANNEL0 & 0xff;
  PWMCPUDH0 = (DEFAULT_PWM_CHANNEL0 >> 8) & 0xff;
  PWMCPUDL1 = DEFAULT_PWM_CHANNEL1 & 0xff;
  PWMCPUDH1 = (DEFAULT_PWM_CHANNEL1 >> 8) & 0xff;
  PWMCFG0 |= PWMCFG0_SYNCUPD__CH0CH1CH2;

  // Enable output on channels 0 and 1.
  PWMCFG2 |= PWMCFG2_CH0EN__BMASK;
  PWMCFG2 |= PWMCFG2_CH1EN__BMASK;

  // $[PWM On]
  PWMCFG1 |= PWMCFG1_PWMEN__ENABLE;
  // [PWM On]$

}

extern void
PORTS_3_enter_DefaultMode_from_RESET (void)
{
  // $[P3 - Port 3 Pin Latch]
  // [P3 - Port 3 Pin Latch]$

  // $[P3MDOUT - Port 3 Output Mode]
  // [P3MDOUT - Port 3 Output Mode]$

  // $[P3MDIN - Port 3 Input Mode]
  /***********************************************************************
   - P3.0 pin is configured for analog mode
   - P3.1 pin is configured for analog mode
   - P3.2 pin is configured for analog mode
   - P3.3 pin is configured for digital mode
   - P3.4 pin is configured for analog mode
   - P3.7 pin is configured for analog mode
   ***********************************************************************/
  P3MDIN = P3MDIN_B0__ANALOG | P3MDIN_B1__ANALOG | P3MDIN_B2__ANALOG
      | P3MDIN_B3__DIGITAL | P3MDIN_B4__ANALOG | P3MDIN_B7__ANALOG;
  // [P3MDIN - Port 3 Input Mode]$

}

extern void
PORTS_1_enter_DefaultMode_from_RESET (void)
{
  // $[P1 - Port 1 Pin Latch]
  // [P1 - Port 1 Pin Latch]$

  // $[P1MDOUT - Port 1 Output Mode]
  /***********************************************************************
   - P1.0 output is open-drain
   - P1.1 output is open-drain
   - P1.2 output is open-drain
   - P1.3 output is open-drain
   - P1.4 output is push-pull
   - P1.5 output is open-drain
   - P1.6 output is open-drain
   - P1.7 output is open-drain
   ***********************************************************************/
  P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
      | P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN | P1MDOUT_B4__PUSH_PULL
      | P1MDOUT_B5__OPEN_DRAIN | P1MDOUT_B6__OPEN_DRAIN
      | P1MDOUT_B7__OPEN_DRAIN;
  // [P1MDOUT - Port 1 Output Mode]$

  // $[P1MDIN - Port 1 Input Mode]
  /***********************************************************************
   - P1.0 pin is configured for analog mode
   - P1.1 pin is configured for analog mode
   - P1.2 pin is configured for analog mode
   - P1.3 pin is configured for analog mode
   - P1.4 pin is configured for digital mode
   - P1.5 pin is configured for analog mode
   - P1.6 pin is configured for analog mode
   - P1.7 pin is configured for analog mode
   ***********************************************************************/
  P1MDIN = P1MDIN_B0__ANALOG | P1MDIN_B1__ANALOG | P1MDIN_B2__ANALOG
      | P1MDIN_B3__ANALOG | P1MDIN_B4__DIGITAL | P1MDIN_B5__ANALOG
      | P1MDIN_B6__ANALOG | P1MDIN_B7__ANALOG;
  // [P1MDIN - Port 1 Input Mode]$

  // $[P1SKIP - Port 1 Skip]
  // [P1SKIP - Port 1 Skip]$

  // $[P1MASK - Port 1 Mask]
  // [P1MASK - Port 1 Mask]$

  // $[P1MAT - Port 1 Match]
  // [P1MAT - Port 1 Match]$

}

extern void
INTERRUPT_0_enter_DefaultMode_from_RESET (void)
{
  // $[EIE1 - Extended Interrupt Enable 1]
  /***********************************************************************
   - Disable ADC0 Conversion Complete interrupt
   - Disable ADC0 Window Comparison interrupt
   - Disable CP0 interrupts
   - Disable CP1 interrupts
   - Disable all Port Match interrupts
   - Disable all PCA0 interrupts
   - Enable interrupt requests generated by SMB0
   - Disable Timer 3 interrupts
   ***********************************************************************/
  EIE1 = EIE1_EADC0__DISABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
      | EIE1_ECP1__DISABLED | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
      | EIE1_ESMB0__ENABLED | EIE1_ET3__DISABLED;
  // [EIE1 - Extended Interrupt Enable 1]$

  // $[EIE2 - Extended Interrupt Enable 2]
  // [EIE2 - Extended Interrupt Enable 2]$

  // $[EIP1H - Extended Interrupt Priority 1 High]
  // [EIP1H - Extended Interrupt Priority 1 High]$

  // $[EIP1 - Extended Interrupt Priority 1 Low]
  // [EIP1 - Extended Interrupt Priority 1 Low]$

  // $[EIP2 - Extended Interrupt Priority 2]
  // [EIP2 - Extended Interrupt Priority 2]$

  // $[EIP2H - Extended Interrupt Priority 2 High]
  // [EIP2H - Extended Interrupt Priority 2 High]$

  // $[IE - Interrupt Enable]
  /***********************************************************************
   - Enable each interrupt according to its individual mask setting
   - Enable interrupt requests generated by the INT0 input
   - Disable external interrupt 1
   - Disable all SPI0 interrupts
   - Disable all Timer 0 interrupt
   - Disable all Timer 1 interrupt
   - Disable Timer 2 interrupt
   - Enable UART0 interrupt
   ***********************************************************************/
  IE = IE_EA__ENABLED | IE_EX0__ENABLED | IE_EX1__DISABLED | IE_ESPI0__DISABLED
      | IE_ET0__DISABLED | IE_ET1__DISABLED | IE_ET2__DISABLED
      | IE_ES0__ENABLED;
  // [IE - Interrupt Enable]$

  // $[IP - Interrupt Priority]
  // [IP - Interrupt Priority]$

  // $[IPH - Interrupt Priority High]
  // [IPH - Interrupt Priority High]$

}

extern void
TIMER_SETUP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CKCON0 - Clock Control 0]
  /***********************************************************************
   - System clock divided by 4
   - Counter/Timer 0 uses the clock defined by the prescale field, SCA
   - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 2 low byte uses the system clock
   - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 1 uses the system clock
   ***********************************************************************/
  SFRPAGE = 0x00;
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T0M__PRESCALE
      | CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__SYSCLK
      | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
      | CKCON0_T1M__SYSCLK;
  // [CKCON0 - Clock Control 0]$

  // $[CKCON1 - Clock Control 1]
  // [CKCON1 - Clock Control 1]$

  // $[TMOD - Timer 0/1 Mode]
  /***********************************************************************
   - Mode 2, 8-bit Counter/Timer with Auto-Reload
   - Mode 2, 8-bit Counter/Timer with Auto-Reload
   - Timer Mode
   - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
   - Timer Mode
   - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
   ***********************************************************************/
  TMOD = TMOD_T0M__MODE2 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
      | TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
  // [TMOD - Timer 0/1 Mode]$

  // $[TCON - Timer 0/1 Control]
  /***********************************************************************
   - INT0 is edge triggered
   - Start Timer 0 running
   - Start Timer 1 running
   ***********************************************************************/
  TCON |= TCON_IT0__EDGE | TCON_TR0__RUN | TCON_TR1__RUN;
  // [TCON - Timer 0/1 Control]$

}

extern void
TIMER16_2_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR2CN0_TR2_save;
  TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
  // Stop Timer
  TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
  // [Timer Initialization]$

  // $[TMR2CN1 - Timer 2 Control 1]
  // [TMR2CN1 - Timer 2 Control 1]$

  // $[TMR2CN0 - Timer 2 Control]
  // [TMR2CN0 - Timer 2 Control]$

  // $[TMR2H - Timer 2 High Byte]
  // [TMR2H - Timer 2 High Byte]$

  // $[TMR2L - Timer 2 Low Byte]
  // [TMR2L - Timer 2 Low Byte]$

  // $[TMR2RLH - Timer 2 Reload High Byte]
  /***********************************************************************
   - Timer 2 Reload High Byte = 0xFE
   ***********************************************************************/
  TMR2RLH = (0xFE << TMR2RLH_TMR2RLH__SHIFT);
  // [TMR2RLH - Timer 2 Reload High Byte]$

  // $[TMR2RLL - Timer 2 Reload Low Byte]
  /***********************************************************************
   - Timer 2 Reload Low Byte = 0x16
   ***********************************************************************/
  TMR2RLL = (0x16 << TMR2RLL_TMR2RLL__SHIFT);
  // [TMR2RLL - Timer 2 Reload Low Byte]$

  // $[TMR2CN0]
  /***********************************************************************
   - Start Timer 2 running
   ***********************************************************************/
  TMR2CN0 |= TMR2CN0_TR2__RUN;
  // [TMR2CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR2CN0 |= TMR2CN0_TR2_save;
  // [Timer Restoration]$

}

extern void
TIMER16_3_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR3CN0_TR3_save;
  TMR3CN0_TR3_save = TMR3CN0 & TMR3CN0_TR3__BMASK;
  // Stop Timer
  TMR3CN0 &= ~(TMR3CN0_TR3__BMASK);
  // [Timer Initialization]$

  // $[TMR3CN1 - Timer 3 Control 1]
  // [TMR3CN1 - Timer 3 Control 1]$

  // $[TMR3CN0 - Timer 3 Control]
  // [TMR3CN0 - Timer 3 Control]$

  // $[TMR3H - Timer 3 High Byte]
  // [TMR3H - Timer 3 High Byte]$

  // $[TMR3L - Timer 3 Low Byte]
  // [TMR3L - Timer 3 Low Byte]$

  // $[TMR3RLH - Timer 3 Reload High Byte]
  /***********************************************************************
   - Timer 3 Reload High Byte = 0xF0
   ***********************************************************************/
  TMR3RLH = (0xF0 << TMR3RLH_TMR3RLH__SHIFT);
  // [TMR3RLH - Timer 3 Reload High Byte]$

  // $[TMR3RLL - Timer 3 Reload Low Byte]
  /***********************************************************************
   - Timer 3 Reload Low Byte = 0x0D
   ***********************************************************************/
  TMR3RLL = (0x0D << TMR3RLL_TMR3RLL__SHIFT);
  // [TMR3RLL - Timer 3 Reload Low Byte]$

  // $[TMR3CN0]
  /***********************************************************************
   - Start Timer 3 running
   ***********************************************************************/
  TMR3CN0 |= TMR3CN0_TR3__RUN;
  // [TMR3CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR3CN0 |= TMR3CN0_TR3_save;
  // [Timer Restoration]$

}

extern void
TIMER16_4_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR4CN0_TR4_save;
  SFRPAGE = 0x10;
  TMR4CN0_TR4_save = TMR4CN0 & TMR4CN0_TR4__BMASK;
  // Stop Timer
  TMR4CN0 &= ~(TMR4CN0_TR4__BMASK);
  // [Timer Initialization]$

  // $[TMR4CN1 - Timer 4 Control 1]
  // [TMR4CN1 - Timer 4 Control 1]$

  // $[TMR4CN0 - Timer 4 Control]
  /***********************************************************************
   - Timer 4 is clocked by Timer 3 overflows
   ***********************************************************************/
  TMR4CN0 &= ~TMR4CN0_T4XCLK__FMASK;
  TMR4CN0 |= TMR4CN0_T4XCLK__TIMER3;
  // [TMR4CN0 - Timer 4 Control]$

  // $[TMR4H - Timer 4 High Byte]
  // [TMR4H - Timer 4 High Byte]$

  // $[TMR4L - Timer 4 Low Byte]
  // [TMR4L - Timer 4 Low Byte]$

  // $[TMR4RLH - Timer 4 Reload High Byte]
  // [TMR4RLH - Timer 4 Reload High Byte]$

  // $[TMR4RLL - Timer 4 Reload Low Byte]
  // [TMR4RLL - Timer 4 Reload Low Byte]$

  // $[TMR4CN0]
  /***********************************************************************
   - Start Timer 4 running
   ***********************************************************************/
  TMR4CN0 |= TMR4CN0_TR4__RUN;
  // [TMR4CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR4CN0 |= TMR4CN0_TR4_save;
  // [Timer Restoration]$

}

extern void
UART_0_enter_DefaultMode_from_RESET (void)
{
  // $[SCON0 - UART0 Serial Port Control]
  /***********************************************************************
   - UART0 reception enabled
   - RI is set and an interrupt is generated only when the stop bit is
   logic 1
   ***********************************************************************/
  SCON0 |= SCON0_REN__RECEIVE_ENABLED | SCON0_MCE__MULTI_ENABLED;
  // [SCON0 - UART0 Serial Port Control]$

}

extern void
TIMER01_0_enter_DefaultMode_from_RESET (void)
{

  // $[Timer Initialization]
  //Save Timer Configuration
  uint8_t TCON_save;
  SFRPAGE = 0x00;
  TCON_save = TCON;
  //Stop Timers
  TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

  // [Timer Initialization]$

  // $[TH0 - Timer 0 High Byte]
  /***********************************************************************
   - Timer 0 High Byte = 0x86
   ***********************************************************************/
  TH0 = (0x86 << TH0_TH0__SHIFT);
  // [TH0 - Timer 0 High Byte]$

  // $[TL0 - Timer 0 Low Byte]
  // [TL0 - Timer 0 Low Byte]$

  // $[TH1 - Timer 1 High Byte]
  /***********************************************************************
   - Timer 1 High Byte = 0x2B
   ***********************************************************************/
  TH1 = (0x2B << TH1_TH1__SHIFT);
  // [TH1 - Timer 1 High Byte]$

  // $[TL1 - Timer 1 Low Byte]
  // [TL1 - Timer 1 Low Byte]$

  // $[Timer Restoration]
  //Restore Timer Configuration
  TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

  // [Timer Restoration]$

}

extern void
SMBUS_0_enter_DefaultMode_from_RESET (void)
{
  // $[SMB0FCN0 - SMBus0 FIFO Control 0]
  /***********************************************************************
   - SMBus 0 interrupts will be generated if RFRQ is set
   - SMBus 0 interrupts will not be generated when TFRQ is set
   - RFRQ will be set anytime new data arrives in the RX FIFO 
   - TFRQ will be set when the TX FIFO is empty
   ***********************************************************************/
  SFRPAGE = 0x20;
  SMB0FCN0 = SMB0FCN0_RFRQE__ENABLED | SMB0FCN0_TFRQE__DISABLED
      | SMB0FCN0_RXTH__ZERO | SMB0FCN0_TXTH__ZERO;
  // [SMB0FCN0 - SMBus0 FIFO Control 0]$

  // $[SMB0RXLN - SMBus0 Receive Length Counter]
  // [SMB0RXLN - SMBus0 Receive Length Counter]$

  // $[SMB0ADR - SMBus 0 Slave Address]
  // [SMB0ADR - SMBus 0 Slave Address]$

  // $[SMB0ADM - SMBus 0 Slave Address Mask]
  // [SMB0ADM - SMBus 0 Slave Address Mask]$

  // $[SMB0TC - SMBus 0 Timing and Pin Control]
  /***********************************************************************
   - SDA setup time is 11 SYSCLKs and SDA hold time is 12 SYSCLKs
   - SCL is mapped to the lower-numbered port pin, and SDA is mapped to the
   higher-numbered port pin
   - No additional SDA falling edge recognition delay 
   ***********************************************************************/
  SFRPAGE = 0x00;
  SMB0TC = SMB0TC_DLYEXT__STANDARD | SMB0TC_SWAP__SDA_HIGH_PIN
      | SMB0TC_SDD__NONE;
  // [SMB0TC - SMBus 0 Timing and Pin Control]$

  // $[SMB0CF - SMBus 0 Configuration]
  /***********************************************************************
   - Timer 2 Low Byte Overflow
   - Slave states are inhibited
   - Enable the SMBus module
   ***********************************************************************/
  SMB0CF |= SMB0CF_SMBCS__TIMER2_LOW | SMB0CF_INH__SLAVE_DISABLED
      | SMB0CF_ENSMB__ENABLED;
  // [SMB0CF - SMBus 0 Configuration]$

}

extern void
PORTS_2_enter_DefaultMode_from_RESET (void)
{
  // $[P2 - Port 2 Pin Latch]
  /***********************************************************************
   - P2.0 is high. Set P2.0 to drive or float high
   - P2.1 is high. Set P2.1 to drive or float high
   - P2.2 is high. Set P2.2 to drive or float high
   - P2.3 is high. Set P2.3 to drive or float high
   - P2.4 is high. Set P2.4 to drive or float high
   - P2.5 is high. Set P2.5 to drive or float high
   - P2.6 is low. Set P2.6 to drive low
   ***********************************************************************/
  P2 = P2_B0__HIGH | P2_B1__HIGH | P2_B2__HIGH | P2_B3__HIGH | P2_B4__HIGH
      | P2_B5__HIGH | P2_B6__LOW;
  // [P2 - Port 2 Pin Latch]$

  // $[P2MDOUT - Port 2 Output Mode]
  /***********************************************************************
   - P2.0 output is open-drain
   - P2.1 output is open-drain
   - P2.2 output is open-drain
   - P2.3 output is open-drain
   - P2.4 output is open-drain
   - P2.5 output is open-drain
   - P2.6 output is push-pull
   ***********************************************************************/
  P2MDOUT = P2MDOUT_B0__OPEN_DRAIN | P2MDOUT_B1__OPEN_DRAIN
      | P2MDOUT_B2__OPEN_DRAIN | P2MDOUT_B3__OPEN_DRAIN | P2MDOUT_B4__OPEN_DRAIN
      | P2MDOUT_B5__OPEN_DRAIN | P2MDOUT_B6__PUSH_PULL;
  // [P2MDOUT - Port 2 Output Mode]$

  // $[P2MDIN - Port 2 Input Mode]
  /***********************************************************************
   - P2.0 pin is configured for analog mode
   - P2.1 pin is configured for analog mode
   - P2.2 pin is configured for analog mode
   - P2.3 pin is configured for analog mode
   - P2.4 pin is configured for analog mode
   - P2.5 pin is configured for analog mode
   - P2.6 pin is configured for digital mode
   ***********************************************************************/
  SFRPAGE = 0x20;
  P2MDIN = P2MDIN_B0__ANALOG | P2MDIN_B1__ANALOG | P2MDIN_B2__ANALOG
      | P2MDIN_B3__ANALOG | P2MDIN_B4__ANALOG | P2MDIN_B5__ANALOG
      | P2MDIN_B6__DIGITAL;
  // [P2MDIN - Port 2 Input Mode]$

  // $[P2SKIP - Port 2 Skip]
  /***********************************************************************
   - P2.0 pin is not skipped by the crossbar
   - P2.1 pin is not skipped by the crossbar
   - P2.2 pin is not skipped by the crossbar
   - P2.3 pin is not skipped by the crossbar
   - P2.4 pin is not skipped by the crossbar
   - P2.5 pin is not skipped by the crossbar
   - P2.6 pin is skipped by the crossbar
   ***********************************************************************/
  P2SKIP = P2SKIP_B0__NOT_SKIPPED | P2SKIP_B1__NOT_SKIPPED
      | P2SKIP_B2__NOT_SKIPPED | P2SKIP_B3__NOT_SKIPPED | P2SKIP_B4__NOT_SKIPPED
      | P2SKIP_B5__NOT_SKIPPED | P2SKIP_B6__SKIPPED;
  // [P2SKIP - Port 2 Skip]$

  // $[P2MASK - Port 2 Mask]
  // [P2MASK - Port 2 Mask]$

  // $[P2MAT - Port 2 Match]
  // [P2MAT - Port 2 Match]$

}

extern void
EXTINT_0_enter_DefaultMode_from_RESET (void)
{
  // $[IT01CF - INT0/INT1 Configuration]
  /***********************************************************************
   - INT0 input is active low
   - Select P0.6
   - INT1 input is active low
   - Select P0.0
   ***********************************************************************/
  IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_6
      | IT01CF_IN1PL__ACTIVE_LOW | IT01CF_IN1SL__P0_0;
  // [IT01CF - INT0/INT1 Configuration]$

}

