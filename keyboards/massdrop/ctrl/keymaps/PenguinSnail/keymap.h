#ifndef __INTELLISENSE__
    #include QMK_KEYBOARD_H
#endif

#include <stdbool.h>
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

// flag to enable or disable rgb
bool rgb_enabled_flag;

enum layers {
    LYR_MAIN = 0,
    LYR_FUNC,
    LYR_GIT
};

enum ctrl_keycodes {
//    U_T_AUTO = SAFE_RANGE,     //USB Extra Port Toggle Auto Detect / Always Active
//    U_T_AGCR,                  //USB Toggle Automatic GCR control
//    DBG_TOG,                   //DEBUG Toggle On / Off
//    DBG_MTRX,                  //DEBUG Toggle Matrix Prints
//    DBG_KBD,                   //DEBUG Toggle Keyboard Prints
//    DBG_MOU,                   //DEBUG Toggle Mouse Prints
//    MD_BOOT,                   //Restart into bootloader after hold timeout
    MD_BOOT = SAFE_RANGE,      //Restart into bootloader after hold timeout
};

enum git_keycodes {
    G_INIT = MD_BOOT + 1,
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
