#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_
#include "Settings.h"
#include <stdint.h>
/**
 * Configuration.h
 * Define here your default pre settings for TS80(P) or TS100
 *
 */

//===========================================================================
//============================= Default Settings ============================
//===========================================================================
/**
 * Default soldering temp is 320.0 C
 * Temperature the iron sleeps at - default 150.0 C
 */

#define SLEEP_TEMP         150 // Default sleep temperature
#define BOOST_TEMP         420 // Default boost temp.
#define BOOST_MODE_ENABLED 1   // 0: Disable 1: Enable

/**
 * Blink the temperature on the cooling screen when its > 50C
 */
#define COOLING_TEMP_BLINK 0 // 0: Disable 1: Enable

/**
 * How many seconds/minutes we wait until going to sleep/shutdown.
 * Values -> SLEEP_TIME * 10; i.e. 5*10 = 50 Seconds!
 */
#define SLEEP_TIME    5  // x10 Seconds
#define SHUTDOWN_TIME 10 // Minutes

/**
 * Auto start off for safety.
 * Pissible values are:
 *  0 - none
 *  1 - Soldering Temperature
 *  2 - Sleep Temperature
 *  3 - Sleep Off Temperature
 */
#define AUTO_START_MODE 0 // Default to none

/**
 * Locking Mode
 * When in soldering mode a long press on both keys toggle the lock of the buttons
 * Possible values are:
 *  0 - Desactivated
 *  1 - Lock except boost
 *  2 - Full lock
 */
#define LOCKING_MODE 0 // Default to desactivated for safety

/**
 * OLED Orientation
 *
 */
#define ORIENTATION_MODE           2 // 0: Right 1:Left 2:Automatic - Default Automatic
#define REVERSE_BUTTON_TEMP_CHANGE 0 // 0:Default 1:Reverse - Reverse the plus and minus button assigment for temperature change

/**
 * Temp change settings
 */
#define TEMP_CHANGE_SHORT_STEP     1  // Default temp change short step +1
#define TEMP_CHANGE_LONG_STEP      10 // Default temp change long step +10
#define TEMP_CHANGE_SHORT_STEP_MAX 50 // Temp change short step MAX value
#define TEMP_CHANGE_LONG_STEP_MAX  90 // Temp change long step MAX value

/* Power pulse for keeping power banks awake*/
#define POWER_PULSE_INCREMENT    1
#define POWER_PULSE_MAX          100 // x10 max watts
#define POWER_PULSE_WAIT_MAX     9   // 9*2.5s = 22.5 seconds
#define POWER_PULSE_DURATION_MAX 9   // 9*250ms = 2.25 seconds

#ifdef MODEL_TS100
#define POWER_PULSE_DEFAULT 0
#else
#define POWER_PULSE_DEFAULT 5
#endif
#define POWER_PULSE_WAIT_DEFAULT     4 // Default rate of the power pulse: 4*2500 = 10000 ms = 10 s
#define POWER_PULSE_DURATION_DEFAULT 1 // Default duration of the power pulse: 1*250 = 250 ms

/**
 * OLED Orientation Sensitivity on Automatic mode!
 * Motion Sensitivity <0=Off 1=Least Sensitive 9=Most Sensitive>
 */
#define SENSITIVITY 7 // Default 7

/**
 * Detailed soldering screen
 * Detailed idle screen (off for first time users)
 */
#define DETAILED_SOLDERING 0 // 0: Disable 1: Enable - Default 0
#define DETAILED_IDLE      0 // 0: Disable 1: Enable - Default 0

#define THERMAL_RUNAWAY_TIME_SEC 20
#define THERMAL_RUNAWAY_TEMP_C   10

#define CUT_OUT_SETTING          0  // default to no cut-off voltage
#define RECOM_VOL_CELL           33 // Minimum voltage per cell (Recommended 3.3V (33))
#define TEMPERATURE_INF          0  // default to 0
#define DESCRIPTION_SCROLL_SPEED 0  // 0: Slow 1: Fast - default to slow
#define ANIMATION_LOOP           1  // 0: off 1: on
#define ANIMATION_SPEED          settingOffSpeed_t::MEDIUM

#define OP_AMP_Rf_TS100  750 * 1000 // 750  Kilo-ohms -> From schematic, R1
#define OP_AMP_Rin_TS100 2370       // 2.37 Kilo-ohms -> From schematic, R2

#define OP_AMP_GAIN_STAGE_TS100 (1 + (OP_AMP_Rf_TS100 / OP_AMP_Rin_TS100))

#define OP_AMP_Rf_TS80  180 * 1000 //  180  Kilo-ohms -> From schematic, R6
#define OP_AMP_Rin_TS80 2000       //  2.0  Kilo-ohms -> From schematic, R3

#define OP_AMP_GAIN_STAGE_TS80 (1 + (OP_AMP_Rf_TS80 / OP_AMP_Rin_TS80))

// Deriving the Voltage div:
// Vin_max = (3.3*(r1+r2))/(r2)
// vdiv = (32768*4)/(vin_max*10)

#if defined(MODEL_TS100) + defined(MODEL_TS80) + defined(MODEL_TS80P) > 1
#error "Multiple models defined!"
#elif defined(MODEL_TS100) + defined(MODEL_TS80) + defined(MODEL_TS80P) == 0
#error "No model defined!"
#endif

// Miniware is swapping IMU's around a bit now, so we turn them all on

#define ACCEL_MMA
#define ACCEL_LIS
#define ACCEL_SC7
#define ACCEL_MSA
#define ACCEL_BMA

#ifdef MODEL_TS100
#define SOLDERING_TEMP         320                     // Default soldering temp is 320.0 °C
#define VOLTAGE_DIV            467                     // 467 - Default divider from schematic
#define CALIBRATION_OFFSET     900                     // 900 - Default adc offset in uV
#define MIN_CALIBRATION_OFFSET 100                     // Min value for calibration
#define PID_POWER_LIMIT        70                      // Sets the max pwm power limit
#define POWER_LIMIT            0                       // 0 watts default limit
#define MAX_POWER_LIMIT        70                      //
#define POWER_LIMIT_STEPS      5                       //
#define OP_AMP_GAIN_STAGE      OP_AMP_GAIN_STAGE_TS100 //
#define TEMP_uV_LOOKUP_HAKKO                           //
#define USB_PD_VMAX            20                      // Maximum voltage for PD to negotiate
#define PID_TIM_HZ             (8)                     // Tick rate of the PID loop
#define MAX_TEMP_C             450                     // Max soldering temp selectable °C
#define MAX_TEMP_F             850                     // Max soldering temp selectable °F
#define MIN_TEMP_C             10                      // Min soldering temp selectable °C
#define MIN_TEMP_F             60                      // Min soldering temp selectable °F
#define MIN_BOOST_TEMP_C       250                     // The min settable temp for boost mode °C
#define MIN_BOOST_TEMP_F       480                     // The min settable temp for boost mode °F
#define POW_DC

#define POW_PD 0

#define TEMP_TMP36
#endif

#ifdef MODEL_TS80
#define SOLDERING_TEMP         320                    // Default soldering temp is 320.0 °C
#define VOLTAGE_DIV            780                    // Default divider from schematic
#define PID_POWER_LIMIT        24                     // Sets the max pwm power limit
#define CALIBRATION_OFFSET     900                    // the adc offset in uV
#define MIN_CALIBRATION_OFFSET 100                    // Min value for calibration
#define POWER_LIMIT            24                     // 24 watts default power limit
#define MAX_POWER_LIMIT        40                     //
#define POWER_LIMIT_STEPS      2                      //
#define OP_AMP_GAIN_STAGE      OP_AMP_GAIN_STAGE_TS80 //
#define TEMP_uV_LOOKUP_TS80                           //
#define USB_PD_VMAX            12                     // Maximum voltage for PD to negotiate
#define PID_TIM_HZ             (8)                    // Tick rate of the PID loop
#define MAX_TEMP_C             450                    // Max soldering temp selectable °C
#define MAX_TEMP_F             850                    // Max soldering temp selectable °F
#define MIN_TEMP_C             10                     // Min soldering temp selectable °C
#define MIN_TEMP_F             60                     // Min soldering temp selectable °F
#define MIN_BOOST_TEMP_C       250                    // The min settable temp for boost mode °C
#define MIN_BOOST_TEMP_F       480                    // The min settable temp for boost mode °F

#define POW_QC
#define POW_PD 0
#define TEMP_TMP36
#define LIS_ORI_FLIP
#define OLED_FLIP
#endif

#ifdef MODEL_TS80P
#define SOLDERING_TEMP         320                    // Default soldering temp is 320.0 °C
#define VOLTAGE_DIV            650                    // Default for TS80P with slightly different resistors
#define PID_POWER_LIMIT        35                     // Sets the max pwm power limit
#define CALIBRATION_OFFSET     1500                   // the adc offset in uV
#define MIN_CALIBRATION_OFFSET 100                    // Min value for calibration
#define POWER_LIMIT            30                     // 30 watts default power limit
#define MAX_POWER_LIMIT        40                     //
#define POWER_LIMIT_STEPS      2                      //
#define OP_AMP_GAIN_STAGE      OP_AMP_GAIN_STAGE_TS80 //
#define TEMP_uV_LOOKUP_TS80                           //
#define USB_PD_VMAX            12                     // Maximum voltage for PD to negotiate
#define PID_TIM_HZ             (8)                    // Tick rate of the PID loop
#define MAX_TEMP_C             450                    // Max soldering temp selectable °C
#define MAX_TEMP_F             850                    // Max soldering temp selectable °F
#define MIN_TEMP_C             10                     // Min soldering temp selectable °C
#define MIN_TEMP_F             60                     // Min soldering temp selectable °F
#define MIN_BOOST_TEMP_C       250                    // The min settable temp for boost mode °C
#define MIN_BOOST_TEMP_F       480                    // The min settable temp for boost mode °F

#define POW_PD 1
#define POW_QC 1
#define TEMP_NTC
#define I2C_SOFT
#define LIS_ORI_FLIP
#define SC7_ORI_FLIP
#define OLED_FLIP
#endif

#ifdef MODEL_TS100
#define HARDWARE_MAX_WATTAGE_X10 750
#define TIP_THERMAL_MASS         65 // X10 watts to raise 1 deg C in 1 second
#define TIP_RESISTANCE           75 // x10 ohms, 7.5 typical for ts100 tips
#endif

#ifdef MODEL_TS80
#define HARDWARE_MAX_WATTAGE_X10 180
#define TIP_THERMAL_MASS         40
#define TIP_RESISTANCE           45 // x10 ohms, 4.5 typical for ts80 tips
#endif

#ifdef MODEL_TS80P
#define HARDWARE_MAX_WATTAGE_X10 300
#define TIP_THERMAL_MASS         40
#define TIP_RESISTANCE           45 // x10 ohms, 4.5 typical for ts80 tips
#endif
#endif

#define FLASH_LOGOADDR (0x08000000 + (62 * 1024))