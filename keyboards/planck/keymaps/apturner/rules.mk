# Build Options
#   comment out to disable the options.
#

MOUSEKEY_ENABLE  = yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE  = no	# Audio control and System control(+450)
CONSOLE_ENABLE   = no	# Console for debug(+400)
NKRO_ENABLE      = yes	# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MIDI_ENABLE      = no   # MIDI controls
STENO_ENABLE     = yes	# Stenotype

BOOTMAGIC_ENABLE = no	# Virtual DIP switch configuration(+1000)
COMMAND_ENABLE   = no	# Commands for debug and configuration
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
AUDIO_ENABLE     = yes  # Audio output on port C6
UNICODE_ENABLE   = no	# Unicode
BLUETOOTH_ENABLE = no 	# Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE  = no   # Enable WS2812 RGB underlight (+4870)
TAP_DANCE_ENABLE = no	# Enable tap dancing (+~1000)
API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend