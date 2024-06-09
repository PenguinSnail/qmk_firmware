#ifndef __INTELLISENSE__
    #include QMK_KEYBOARD_H
#endif

#include <print.h>
#include <string.h>

// these ifdef includes are used to get rid of intellisense errors
// they are not required to properly compile

#ifndef KEYCODE_H
    #include "tmk_core/common/keycode.h"
#endif
#ifndef QUANTUM_KEYCODES_H
    #include "quantum/quantum_keycodes.h"
#endif
#ifndef LAYOUT
    #include "keyboards/massdrop/ctrl/ctrl.h"
#endif
#ifndef MATRIX_ROWS
    #include "keyboards/massdrop/ctrl/config.h"
#endif
#ifndef RGBLIGHT_H
    #include "quantum/rgblight.h"
#endif
#ifndef LED_FLAG_ALL
    #include "quantum/rgb_matrix_types.h"
#endif
#ifndef RGB_MATRIX_H
    #include "quantum/rgb_matrix.h"
#endif
#ifndef PROCESS_TAP_DANCE_H
    #ifndef TAP_DANCE_ENABLE
        #define TAP_DANCE_ENABLE
    #endif
    #include "quantum/process_keycode/process_tap_dance.h"
#endif

#include "raw_hid.h"

extern rgb_config_t rgb_matrix_config;

#define RGB_DEFAULT_TIME_OUT 300
#define RGB_TIME_OUT_STEP 10
#define RGB_TIME_OUT_MIN 10
#define RGB_TIME_OUT_MAX 600

bool rgb_enabled_flag;                  // Current LED state flag. If false then LED is off.
bool rgb_time_out_enable;               // Idle LED toggle enable. If false then LED will not turn off after idle timeout.
bool rgb_time_out_user_value;           // This holds the toggle value set by user with ROUT_TG. It's necessary as RGB_TOG changes timeout enable.

// timeout timer and counters
uint16_t idle_timer;
uint16_t idle_second_counter;
uint8_t key_event_counter;

uint16_t rgb_time_out_seconds;          // Idle LED timeout value, in seconds not milliseconds
uint16_t rgb_time_out_saved_seconds;    // The saved user config for RGB timeout period
led_flags_t rgb_time_out_saved_flag;    // Store LED flag before timeout so it can be restored when LED is turned on again.

// for game colors
bool game_color;
uint16_t selected_game_color;

#define MATRIX_CAPS_LOCK_KEY 50
#define MATRIX_SCROLL_LOCK_KEY 14

// lock states
bool caps_lock;
bool scroll_lock;

// layers
enum layers {
    LYR_MAIN = 0,
    LYR_FUNC,
    LYR_GIT,
    LYR_COL
};
enum game_color_layers {
    LYR_OSU = LYR_COL + 1,
    LYR_TF2,
    LYR_CIV,
    LYR_LFD
};

// keycodes
enum ctrl_keycodes {
    MD_BOOT = SAFE_RANGE,        //Restart into bootloader after hold timeout
    ROUT_TO,                     // RGB Timeout toggle
    ROUT_VI,
    ROUT_VD
};
enum git_keycodes {
    G_INIT = ROUT_VD + 1,
    G_COMMI,
    G_CLONE,
    G_PUSH,
    G_PULL,
    G_CHECK,
    G_BRANC,
    G_ADD,
    G_STAT,
    G_DIFF,
    G_FETCH,
    G_MERGE,
    G_LOG
};
enum game_color_keycodes {
    C_RESET = G_LOG + 1,
    C_OSU,
    C_TF2,
    C_CIV,
    C_LFD
};

// from `endgame` layout
// These are just to make it neater to use builtin HSV values in the keymap
#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}
#define WHITE {0, 0, 255}
