#include "keymap.h"

// leave this here even though we don't use tapdance (yet),
// compile will fail without this unless we disable all the tapdance flags
qk_tap_dance_action_t tap_dance_actions[] = {
};

static const char * git_commands[] = {
    "git init ",
    "git commit ",
    "git clone ",
    "git push ",
    "git pull ",
    "git checkout ",
    "git branch -b \"",
    "git add ",
    "git status ",
    "git diff ",
    "git fetch ",
    "git merge ",
    "git log ",
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LYR_MAIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPACE,                           KC_RALT, MO(LYR_FUNC), KC_APP,  KC_RCTL,       KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [LYR_FUNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, XXXXXXX, RGB_VAD, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MD_BOOT, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, MO(LYR_GIT), _______,                          _______,
        _______, _______, _______,                   XXXXXXX,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    [LYR_GIT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                              _______,
        _______, _______, _______,                   XXXXXXX,                            _______, _______, _______, _______,            _______, _______, _______
    ),
};

#ifdef _______
    // redefine _______ temporarily to represent black/off
    #undef _______
    #define _______ {0, 0, 0}

// define our LED maps
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [LYR_MAIN] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             CYAN,    CYAN,    CYAN,
        WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   CYAN,      CYAN,    CYAN,    CYAN,
        CYAN,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,     CYAN,    CYAN,    CYAN,
        CYAN,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   CYAN,
        CYAN,    WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   WHITE,   CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                      WHITE,                              CYAN,    CYAN,    CYAN,    CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
        TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL
    },
    [LYR_FUNC] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             RED,     _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,      GOLD,    GOLD,    GREEN,
        _______, _______, GREEN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   AZURE,   AZURE,   RED,
        CYAN,    _______, RED,     WHITE,   _______, _______, _______, _______, _______, _______, _______, _______, CYAN,
        CYAN,    _______, _______, _______, _______, RED,     WHITE,   _______, _______, _______, GREEN,   CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                     _______,                             CYAN,    BLUE,    CYAN,    CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE,
        BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE
    },
    [LYR_GIT] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,      _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        CYAN,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,
        CYAN,    _______, _______, _______, _______, _______, _______, _______, _______, _______, GREEN,   CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                      _______,                            CYAN,    BLUE,    CYAN,    CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN
    },
};

    // reset the definition
    #undef _______
    #define _______ KC_TRNS
#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_enabled_flag = true;
};

// runs once after boot
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgblight_mode(RGB_MATRIX_SOLID_COLOR);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// define mod keys so that both left and right mods work
#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

// used to determine what to do on a key action
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    // switch through to determine keycode
    switch (keycode) {
        // if the MD_BOOT keycode
        // used to reset the board
        case MD_BOOT:
            // if this is the keypress event
            if (record->event.pressed) {
                // get the timer value (start value)
                key_timer = timer_read32();
            // if this is the release event
            } else {
                // if it's been more than 500ms since the press
                if (timer_elapsed32(key_timer) >= 500) {
                    // reset the board
                    reset_keyboard();
                }
            }
            // return false to not send the keycode to the host
            return false;
        /*
        case RGB_TOG:
            // if we press the rgb toggle button
            if (record->event.pressed) {
                // get the current RGB flags
                switch (rgb_matrix_get_flags()) {
                    // if the current flag is all
                    // (all lights lit)
                    case LED_FLAG_ALL: {
                        // set flags to keylight and modifier
                        // (keys only, no underglow)
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                        // disable these leds
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;
                    case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                    break;
                    case LED_FLAG_UNDERGLOW: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    }
                    break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                    break;
                }
            }
            return false;
        */
        // git macros
        case G_INIT ... G_LOG:
                send_string_with_delay(git_commands[keycode - G_INIT], 5);

                return false;
        // default for any normal keycodes
        default:
            // return true to just send the keycode to the host
            return true;
    }
}

void set_layer_color(int layer) {
    // iterate through all LEDs on the board
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        // read in our HSV value from the LED map for the current layer and LED
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        // if any of the three values are defined
        if (hsv.h || hsv.s || hsv.v) {
            // convert our HSV values to RGB values
            RGB rgb = hsv_to_rgb(hsv);
            // calculate a multiplier from the HSV `value` value
            // should be a float between 0 and 1
            // not entirely sure why this is necessary?
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        // else if all values are 0
        } else {
            // turn off the LED
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_layer_color(get_highest_layer(state));
    /*
    switch (get_highest_layer(state)) {
        case LYR_MAIN:
            rgblight_setrgb(0x00,  0x00, 0xFF);
            break;
        case LYR_FUNC:
            rgblight_setrgb(0xFF,  0x00, 0x00);
            break;
        case LYR_GIT:
            rgblight_setrgb(0x00,  0xFF, 0x00);
            break;
        default: //  for any other layers, or the default layer
            rgblight_setrgb(0x00,  0xFF, 0xFF);
            break;
    }
    */
    return state;
}
