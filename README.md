# Sovol SV06 — Marlin firmware (SKR E3 V3 / STM32F103, TMC2209 UART, sensorless-capable)

What I prepared
- Configuration.h (tailored for Sovol SV06 defaults)
- Configuration_adv.h (key advanced settings for TMC2209 / sensorless homing / safety)
- platformio.ini (instructions + recommended environment selection)
- This README with build & flash steps and wiring notes

Important notes (read first)
1. MCU / board environment
   - I intended the SKR E3 V3 (STM32F103). PlatformIO/Marlin environment names can vary by Marlin release. Before building, verify the correct environment name in platformio.ini. If compilation fails with an unknown board, I will update the environment.
2. Pins / probe / UART wiring
   - Marlin pin definitions (UART TX/RX, probe pins, diag pins) are board/pinset-specific. I left explicit pin numbers commented or as placeholders in the config when board-specific pin names are required. Please confirm the SKR E3 V3 pin file in Marlin (pins_BTT_SKR_E3_V3.h) and update if needed.
3. Stock Z probe
   - I assumed a stock inductive/proximity sensor typical for SV06. If your stock probe is a BLTouch/CR-Touch, tell me and I'll switch the config to the BLTouch servo settings.
4. Sensorless homing over UART
   - You chose UART for TMC2209. Ensure the UART jumpers/wires are installed for the drivers you want Marlin to configure. If you prefer DIAG-based sensorless homing later, I included notes for that too.
5. Steps/mm and PID
   - X/Y = 100, Z = 400 are set as sensible defaults for Sovol SV06 (confirm and calibrate). Extruder steps are a starting point; do a calibration extrusion after flashing.
6. Safety
   - Thermal runaway protection is enabled. Do not power heaters without verifying thermistor types and wiring.
7. If you want, I can:
   - Push these files to the `cully4126/sovol-firmware` repo on a new branch and/or build a .bin for SD flashing.

Build & flash (short)
1. Install VSCode + PlatformIO (recommended) or PlatformIO Core (CLI).
2. Open this folder in VSCode.
3. Edit platformio.ini: set the correct `env` for SKR E3 V3 if necessary (see comments).
4. Optionally run `pio run -e <env>` to build.
5. For STM32F103 SKR boards you usually flash via SD (bootloader) by copying `firmware.bin` to the root of an SD card, or via STM32CubeProgrammer / DFU if you have the bootloader details. See section "Flashing" below for recommended steps.
6. After flashing: test endstops, stepper direction, heaters bench-test (with PID tuning), then test homing with the Z probe above the bed.

Wiring reminders
- TMC2209 UART: connect the UART TX/RX or the single-wire UART to the MCU header per the board manual. Install UART jumpers if required.
- Sleep/EN/PDN pins: ensure the driver modules are seated and jumpers set for UART.
- Probe wiring: verify whether the probe is NO or NC (common for inductive probes), and check which pin on the board is expected (usually `Z_MIN_PROBE_PIN` or `Z_MIN_PIN`).

If anything in the files looks wrong for your specific board or probe, tell me the exact pin names shown in your board's pins_BTT_SKR_E3_V3.h or a photo of the board’s silkscreen and I’ll update and (if you want) push & compile.