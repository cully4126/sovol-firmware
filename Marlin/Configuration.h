/**
 * Configuration.h - tailored for Sovol SV06 + SKR E3 V3 (STM32F103) + TMC2209 (UART)
 *
 * NOTES:
 * - Verify the MOTHERBOARD name matches your Marlin version's board list.
 * - Confirm probe pin and serial port settings in pins file for your board.
 * - After flashing, run axis calibration, PID autotune, and TMC current/stall tuning as needed.
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//===========================================================================
//============================= Board Selection =============================
//===========================================================================
// Use the BOARD define that matches SKR E3 V3 in your Marlin release.
// If your Marlin version uses a different symbol, update accordingly.
#define MOTHERBOARD BOARD_BTT_SKR_E3_V3

// Serial port (USB). If USB CDC is used on your board, SERIAL_PORT usually = 0.
// If you need another UART for host, set accordingly.
#define SERIAL_PORT 0
#define BAUDRATE 115200

//===========================================================================
//============================= Machine Geometry ============================
//===========================================================================
// Sovol SV06 common defaults
#define X_BED_SIZE 235
#define Y_BED_SIZE 235
#define Z_MAX_POS 270

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

// Steps per unit: { X, Y, Z, E }
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 100, 100, 400, 95 }  // E value is a starting point — calibrate your extruder

//===========================================================================
//============================= Endstop / Probe =============================
//===========================================================================
// Use a separate Z probe (stock inductive-style probe assumed).
// If your probe uses the Z_MIN endstop pin, use Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN as appropriate.
// By default enable a z-probe
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

// Set probe type: if BLTouch/CR-Touch replace with related settings
// If inductive probe, ensure wiring and logic (NC/NO) are verified in pins/board.
#define PROBE_MANUALLY // If you prefer manual probe use; otherwise disable and use M48/G29 mesh probing
// For automatic mesh bed leveling, enable one of the ABL options (example below commented)
// #define AUTO_BED_LEVELING_BILINEAR
// #define MESH_BED_LEVELING

// Probe offsets - set after you physically measure
#define NOZZLE_TO_PROBE_OFFSET { 0, 0, 0 } // { X, Y, Z } — must be measured and set for your probe

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================
// Most Sovol machines use EPCOS 100K thermistors
#define TEMP_SENSOR_0 1     // Hotend
#define TEMP_SENSOR_BED 1   // Bed

// Safety: thermal runaway protection
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

//===========================================================================
//============================= Extruder ===================================
//===========================================================================
// If you have a single direct extruder:
#define EXTRUDERS 1

//===========================================================================
//============================= Motors / Drivers ============================
//===========================================================================
// Configure TMC2209 drivers (UART)
// Marlin driver types
#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209

// Default motor currents (mA) — tune to your motors and drivers. Values are examples.
#define X_CURRENT 800
#define Y_CURRENT 800
#define Z_CURRENT 800
#define E0_CURRENT 800

// Enable sensorless homing support in Marlin
// Note: With UART TMC2209 you can use StallGuard but board-specific diag pins or stall tuning may be needed.
// If you plan to use DIAG wiring instead of UART, see Configuration_adv.h notes.
#define SENSORLESS_HOMING

//===========================================================================
//============================= Misc =======================================
//===========================================================================
// Mechanical homing order
#define HOMING_ORDER HOME_ORDER_XYZ

// Disable default power-on message if desired
//#define SHOW_BOOTSCREEN

#endif // CONFIGURATION_H
