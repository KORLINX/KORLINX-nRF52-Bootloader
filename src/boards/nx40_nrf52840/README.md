# KORLINX NX40 nRF52840

Pairs with the `nx40_nrf52840` variant in the KORLINX Arduino BSP.

| | |
|---|---|
| DFU activity LED | P0.14, active low |
| BLE OTA LED | P0.08, active low |
| DFU button | P0.07 (SW2) |
| SoftDevice | s140 6.1.1 |
| USB | 0x1209:0x4E58 |

SW1 is wired to P0.18/RESET, so double-tap reset is the other way into DFU.

## Building on macOS

The Makefile's version `sed` is GNU-only, so pass the numbers yourself.
The Zephyr SDK toolchain works as the cross compiler.

    python3 -m venv .venv && .venv/bin/pip install intelhex adafruit-nrfutil
    PATH="$PWD/.venv/bin:$PATH" make \
        BOARD=nx40_nrf52840 \
        GIT_VERSION=1.0.0 _VER_MAJ=1 _VER_MIN=0 _VER_PAT=0 \
        CROSS_COMPILE=$HOME/zephyr-sdk-0.17.4/arm-zephyr-eabi/bin/arm-zephyr-eabi- \
        all

Copy the `.hex`, `.zip` and `update-*.uf2` from `_build/build-nx40_nrf52840/`
into the BSP at `bootloader/nx40_nrf52840/`. Keep the directory and file
prefix lower case -- `platform.txt` resolves them from `{build.variant}`.
