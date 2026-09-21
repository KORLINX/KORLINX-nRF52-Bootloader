# KORLINX nRF52 Bootloader

UF2 and serial DFU bootloader for KORLINX nRF52 boards. Forked from
[Adafruit_nRF52_Bootloader](https://github.com/adafruit/Adafruit_nRF52_Bootloader).

Once installed, a board shows up as a USB drive you can drag firmware onto, and
as a serial port the Arduino IDE uploads to — no debug probe needed. Pair it with
the [KORLINX Arduino core](https://github.com/KORLINX/KORLINX-nRF52-Arduino).

## Supported boards

<!-- AUTO-GENERATED from src/boards/ -->

| Board | Target | USB ID | UF2 drive | Documentation |
|---|---|---|---|---|
| NX40 nRF52840 | `nx40_nrf52840` | `0x1209:0x4E58` | `NX40BOOT` | [NX40 Dev Kit](https://wiki.korlinx.com/docs/Network/Bluetooth/NX40_Dev_Kit/NX40_Dev_Kit_Overview) |

<!-- END AUTO-GENERATED -->

Prebuilt images ship with the Arduino core under `bootloader/<target>/`.

## Entering the bootloader

| Method | How |
|---|---|
| Double reset | Press reset twice within 500 ms |
| Button | Hold the DFU button (SW2 on NX40) while pressing reset |
| From firmware | Set `NRF_POWER->GPREGRET = 0x57` and reset |

The Arduino IDE enters it automatically with a 1200 bps touch.

## Updating firmware

Drag a `.uf2` file onto the drive. To make one from a `.hex`:

```bash
python3 lib/uf2/utils/uf2conv.py firmware.hex -c -f 0xADA52840
```

## Building

Needs an ARM GCC toolchain, and `intelhex` plus `adafruit-nrfutil` for packaging.

```bash
git clone --recursive https://github.com/KORLINX/KORLINX-nRF52-Bootloader.git
cd KORLINX-nRF52-Bootloader
python3 -m venv .venv && .venv/bin/pip install intelhex adafruit-nrfutil

PATH="$PWD/.venv/bin:$PATH" make BOARD=nx40_nrf52840 all
```

Output lands in `_build/build-nx40_nrf52840/`.

> **macOS:** the Makefile's version parsing needs GNU sed, so pass the version
> yourself: `make BOARD=nx40_nrf52840 GIT_VERSION=1.0.0 _VER_MAJ=1 _VER_MIN=0 _VER_PAT=0 all`

## Installing

A blank board needs the bootloader installed once over SWD, with
[nRF Util](https://www.nordicsemi.com/Products/Development-tools/nrf-util):

```bash
nrfutil device program \
  --firmware nx40_nrf52840_bootloader-1.0.0_s140_6.1.1.hex \
  --options chip_erase_mode=ERASE_ALL,reset=RESET_SYSTEM
```

> **Warning:** this erases the whole chip.

## License

MIT; see `LICENSE`. Images include the Nordic SoftDevice S140, covered by
`lib/softdevice/s140_nrf52_6.1.1/s140_nrf52_6.1.1_license-agreement.txt`.
