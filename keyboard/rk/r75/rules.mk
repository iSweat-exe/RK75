MCU = WB32FQ95
BOOTLOADER = wb32-dfu

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Use optimized r75.c

SRC += rgb_startup_animation.c

RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = yes
