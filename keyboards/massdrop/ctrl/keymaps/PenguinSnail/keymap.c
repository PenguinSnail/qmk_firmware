#include "keymap.h"

// leave this here even though we don't use tapdance (yet),
// compile will fail without this unless we disable all the tapdance flags
qk_tap_dance_action_t tap_dance_actions[] = {
};

// get the difference between the keycode and layer number for game layouts
static uint16_t game_layer_offset = C_OSU - LYR_OSU;

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
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPACE,                           KC_RALT, MO(LYR_FUNC), KC_APP,  KC_RCTL,       KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [LYR_FUNC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   KC_MPLY, KC_MSTP, KC_VOLU,
        XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, ROUT_TO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MNXT, KC_VOLD,
        _______, XXXXXXX, RGB_VAD, RGB_TOG, ROUT_VI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, ROUT_VD, MD_BOOT, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, OSL(LYR_GIT), _______,                         _______,
        _______, _______, _______,                   XXXXXXX,                            _______, _______, OSL(LYR_COL), _______,       _______, _______, _______
    ),
    [LYR_GIT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G_INIT,  XXXXXXX, G_PULL,  G_PUSH,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, G_ADD,   G_STAT,  G_DIFF,  G_FETCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G_LOG,   XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, G_CHECK, G_CLONE, G_COMMI, G_BRANC, XXXXXXX, G_MERGE, XXXXXXX, XXXXXXX, XXXXXXX, _______,                              _______,
        _______, _______, _______,                   XXXXXXX,                            _______, _______, _______, _______,            _______, _______, _______
    ),
    [LYR_COL] = LAYOUT(
        C_RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C_TF2,   XXXXXXX, XXXXXXX, XXXXXXX, C_OSU,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C_LFD,   XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, C_CIV,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                              _______,
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
        TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL,
        TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL, TEAL
    },
    [LYR_FUNC] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             RED,     _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,      GOLD,    GOLD,    GREEN,
        _______, _______, GREEN,   _______, _______, ORANGE,  _______, _______, _______, _______, _______, _______, _______, _______,   AZURE,   AZURE,   RED,
        CYAN,    _______, RED,     WHITE,   GREEN,   _______, _______, _______, _______, _______, _______, _______, CYAN,
        CYAN,    _______, _______, _______, RED,     RED,     WHITE,   _______, _______, _______, GREEN,   CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                     _______,                             CYAN,    GOLD,    RED,     CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD,
        GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, GOLD
    },
    [LYR_GIT] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,      _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, GREEN,   _______, CORAL,   PURPLE,  _______, _______,   _______, _______, _______,
        CYAN,    AZURE,   GREEN,   MAGENT,  GREEN,   _______, _______, _______, _______, GREEN,   _______, _______, CYAN,
        CYAN,    _______, CHART,   CORAL,   SPRING,  ORANGE,  _______, CHART,   _______, _______, GREEN,   CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                      _______,                            CYAN,    GOLD,    CYAN,    CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN
    },
    [LYR_COL] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CYAN,      _______, _______, _______,
        _______, _______, _______, _______, _______, ORANGE,  _______, _______, _______, PURPLE,  _______, _______, _______, _______,   _______, _______, _______,
        CYAN,    _______, _______, _______, _______, _______, _______, _______, _______, RED,     _______, _______, CYAN,
        CYAN,    _______, _______, CHART,   _______, _______, _______, _______, _______, _______, _______, CYAN,                                 SPRING,
        CYAN,    CYAN,    CYAN,                      _______,                            CYAN,    GOLD,    RED,     CYAN,               SPRING,  SPRING,  SPRING,

        // light bar/underglow LEDs
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED
    },

    [LYR_OSU] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, GOLD,    GOLD,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
        CYAN,    BLUE,    RED,     RED,     BLUE,    _______, _______, _______, _______, _______, _______, _______,                              _______,
        _______, _______, _______,                   GREEN,                              _______, CYAN,    CYAN,    _______,            SPRING,  _______, SPRING,

        // light bar/underglow LEDs
        PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,
        PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE
    },
    [LYR_TF2] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, GREEN,   GREEN,   GREEN,   YELLOW,  YELLOW,  _______, _______, _______, _______, _______, _______, _______, CYAN,      _______, _______, _______,
        AZURE,   _______, SPRING,  MAGENT,  RED,     _______, RED,     BLUE,    _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, SPRING,  SPRING,  SPRING,  _______, _______, WHITE,   _______, _______, _______, _______, _______, CYAN,
        CYAN,    GOLD,    GOLD,    GOLD,    _______, _______, _______, WHITE,   ORANGE,  ORANGE,  _______, _______,                              _______,
        _______, _______, _______,                   GREEN,                              _______, CYAN,    CYAN,    _______,            _______, _______, _______,

        // light bar/underglow LEDs
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE
    },
    [LYR_CIV] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, GOLD,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RED,     _______, _______,
        _______, RED,     _______, _______, MAGENT,  WHITE,   _______, _______, _______, _______, _______, _______, GREEN,
        _______, _______, _______, _______, _______, _______, _______, GREEN,   ORANGE,  ORANGE,  _______, _______,                              _______,
        _______, _______, _______,                   WHITE,                              _______, CYAN,    CYAN,    _______,            _______, _______, _______,

        // light bar/underglow LEDs
        CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART,
        CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART, CHART
    },
    [LYR_LFD] = {
        RED,     PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,  PURPLE,             _______, _______, _______,
        _______, GREEN,   GREEN,   RED,     MAGENT,  PINK,    _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        AZURE,   _______, RED,     WHITE,   RED,     BLUE,    RED,     _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______, RED,     RED,     RED,     YELLOW,  _______, _______, _______, _______, _______, _______, _______, _______,
        CYAN,    GOLD,    GOLD,    _______, _______, _______, _______, ORANGE,  _______, _______, _______, _______,                              _______,
        CYAN,    _______, _______,                   GREEN,                              _______, CYAN,    CYAN,    _______,            _______, _______, _______,

        // light bar/underglow LEDs
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED,
        RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED
    },
};

    // reset the definition
    #undef _______
    #define _______ KC_TRNS
#endif

// Runs just one time when the keyboard initializes.
// we'll initialize most of our counters and states here
void matrix_init_user(void) {
    // couters for timeout
    idle_second_counter = 0;
    key_event_counter = 0;

    rgb_enabled_flag = true;

    // timeout settings
    rgb_time_out_enable = true;
    rgb_time_out_user_value = rgb_time_out_enable;
    rgb_time_out_seconds = RGB_DEFAULT_TIME_OUT;

    // matrix state for resuming from led timeout
    rgb_time_out_saved_flag = rgb_matrix_get_flags();

    // custom game colors
    game_color = false;
    selected_game_color = 0;

    // lock key state
    caps_lock = false;
    scroll_lock = false;
};

// runs once after boot
void keyboard_post_init_user(void) {
    // enable lighting
    rgb_matrix_enable();
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if(rgb_time_out_user_value && rgb_time_out_enable && rgb_enabled_flag) {
        // If the key event counter is not zero then some key was pressed down but not released, thus reset the timeout counter.
        if (key_event_counter) {
            idle_second_counter = 0;
        } else if (timer_elapsed(idle_timer) > 1000) {
            idle_second_counter++;
            idle_timer = timer_read();
        }

        if (idle_second_counter >= rgb_time_out_seconds) {
            rgb_time_out_saved_flag = rgb_matrix_get_flags();
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            rgb_enabled_flag = false;
            idle_second_counter = 0;
        }
    }
};

// define mod keys so that both left and right mods work
#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

// used to determine what to do on a key action
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    // Increment key event counter for every press and decrement for every release.
    if (record->event.pressed) {
        key_event_counter++;
    } else {
        key_event_counter--;
    }

    if (rgb_time_out_enable) {
        idle_timer = timer_read();
        // Reset the seconds counter. Without this, something like press> leave x seconds> press, would be x seconds on the effective counter not 0 as it should.
        idle_second_counter = 0;
        if (!rgb_enabled_flag) {
            rgb_matrix_enable_noeeprom();
            rgb_matrix_set_flags(rgb_time_out_saved_flag);
            rgb_enabled_flag = true;
        }
    }

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
    }
    if (record->event.pressed) {
        switch (keycode) {
            case RGB_TOG:
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_time_out_enable = false;
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    }
                    break;
                    default: {
                        rgb_time_out_enable = true;
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                    break;
                }
                return false;
            case ROUT_TO: {
                rgb_time_out_user_value = !rgb_time_out_user_value;
                return false;
            }
            case ROUT_VI:
                if (rgb_time_out_seconds <= RGB_TIME_OUT_MAX) {
                    rgb_time_out_seconds += RGB_TIME_OUT_STEP;
                }
                return false;
            case ROUT_VD:
                if (rgb_time_out_seconds > RGB_TIME_OUT_MIN) {
                    rgb_time_out_seconds -= RGB_TIME_OUT_STEP;
                }
                return false;
            // git macros
            case G_INIT ... G_LOG: {
                send_string_with_delay(git_commands[keycode - G_INIT], 5);
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                return false;
            }
            case C_RESET: {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                game_color = false;
                return false;
            }
            case C_OSU ... C_LFD: {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                game_color = true;
                selected_game_color = keycode - game_layer_offset;
                return false;
            }
        }
    }
    return true;
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
        if ((caps_lock && i == MATRIX_CAPS_LOCK_KEY) ||
        (scroll_lock && i == MATRIX_SCROLL_LOCK_KEY)) {
            hsv.h = 0;
            hsv.s = 0;
            hsv.v = 255;
        }
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

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || rgb_matrix_get_flags() == LED_FLAG_NONE) {
        return;
    }
    if (game_color && get_highest_layer(layer_state) == LYR_MAIN) {
        set_layer_color(selected_game_color);
    } else {
        set_layer_color(get_highest_layer(layer_state));
    }
}

bool led_update_user(led_t led_state) {
    if (caps_lock != led_state.caps_lock) {
        caps_lock = led_state.caps_lock;
    }
    if (scroll_lock != led_state.scroll_lock) {
        scroll_lock = led_state.scroll_lock;
    }
    return true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your code goes here. data is the packet received from host.
}
