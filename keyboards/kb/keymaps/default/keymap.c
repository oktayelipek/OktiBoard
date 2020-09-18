#include "kb.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
// Macro Declarations

	enum custom_keycodes {
		QMKBEST = SAFE_RANGE,
	};

    enum {
        Create_Components = 0,
        Show_Components = 1,
        Team_Library = 2,
        Detach_Instance = 3,

        All_Layers = 4,
        Bring_Forward = 5,
        Send_Backward = 6,
        Show_HideGrid = 7,

        Run_Last_Plugin = 8,
        Text_Align_Left = 9,
        Text_Align_Center = 10,
        Text_Align_Right = 11,

        Auto_Layout = 12,
        Remove_Auto_Layout = 13,
        Copy_Style = 14,
        Paste_Style = 15,
    };

	KEYMAP(
		M(Create_Components), M(Show_Components), M(Team_Library), M(Detach_Instance), 
		M(All_Layers), M(Bring_Forward), M(Send_Backward), M(Show_HideGrid), 
		M(Run_Last_Plugin), M(Text_Align_Left), M(Text_Align_Center), M(Text_Align_Right), 
		M(Auto_Layout), M(Remove_Auto_Layout), M(COPYPASTESTYLE), M(BOS)

};

bool is_copied = false; # inner variable kopyalandı mı diye

# layerde CUSTOMCODE diye bir tuş olsun..

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COPYPASTESTYLE:
      if(!is_copied) {
        register_code(KC_LGUI(KC_LALT(KC_C)));
        is_copied = true;
      } else {
        register_code(KC_LGUI(KC_LALT(KC_V)));
        is_copied = false; // state'i sıfırla
      }
      break;
  }
  return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {
		case 0: // Create Component
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(K), END );
			}
			break;
        case 1: // Show Components
			if (record->event.pressed) {
				return MACRO( T(LALT), T(2), END );
			}
            break;
		case 2: // Team Library
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(O), END );
			}
			break;
		case 3: // Detach Instance
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(B), END );
			}
			break;
        case 4: // Send Backward
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(Ğ), END );
			}
			break;
        case 5: // Send Backward
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(Ğ), END );
			}
			break;
        case 6: // Bring Forward
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(Ü), END );
			}
			break;
        case 7: // Show/Hide Grid
			if (record->event.pressed) {
				return MACRO( T(LCTRL), T(G), END );
			}
			break;
        case 8: // Text Align Left
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(L), END );
			}
			break;
        case 9: // Text Align Right
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(R), END );
			}
			break;
        case 10: // Text Align Center
			if (record->event.pressed) {
				return MACRO( T(LALT), T(LGUI), T(T), END );
			}
			break;
        case 11: // Run Last Plugin
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(LALT), T(P), END );
			}
			break;
        case 12: // Auto Layout
			if (record->event.pressed) {
				return MACRO( T(LSHIFT), T(A), END );
			}
			break;
        case 13: // Remove Auto Layout
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(LSHIFT), T(A), END );
			}
			break;
        case 14: // Copy Style
            //RETURN
			}
			break;
        case 15: // Paste Style
			if (record->event.pressed) {
				return MACRO( T(LGUI), T(LALT), T(V), END );
			}
			break;

			
	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
