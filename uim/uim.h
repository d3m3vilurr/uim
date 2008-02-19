/*

  Copyright (c) 2003-2008 uim Project http://uim.freedesktop.org/

  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
  3. Neither the name of authors nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.

*/

/* API and ABI is unstable */
#ifndef _uim_h_included_
#define _uim_h_included_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UIM_VERSION_MAJOR      (1)
#define UIM_VERSION_MINOR      (4)
#define UIM_VERSION_PATCHLEVEL (2)
#define UIM_VERSION_REQUIRE(major, minor, patchlevel)			     \
  ((major) < UIM_VERSION_MAJOR						     \
   || ((major) == UIM_VERSION_MAJOR && (minor) < UIM_VERSION_MINOR)	     \
   || ((major) == UIM_VERSION_MAJOR && (minor) == UIM_VERSION_MINOR	     \
       && (patchlevel) <= UIM_VERSION_PATCHLEVEL))

/*
 * A boolean type for uim to explicitly indicate intention about values
 *
 *                           *** IMPORTANT ***
 *
 * Do not test a value with (val == UIM_TRUE). The UIM_TRUE is only A TYPICAL
 * VALUE FOR TRUE. Use (val) or (val != UIM_FALSE) instead.
 *
 */
typedef int uim_bool;

#define UIM_FALSE 0
#define UIM_TRUE 1


typedef struct uim_context_ *uim_context;

typedef struct uim_candidate_ *uim_candidate;

/* FIXME: We need reorganize of key event handling...*/
enum UKey {
  UKey_0 = 48,
  UKey_1 = 49,
  UKey_2 = 50,
  UKey_3 = 51,
  UKey_4 = 52,
  UKey_5 = 53,
  UKey_6 = 54,
  UKey_7 = 55,
  UKey_8 = 56,
  UKey_9 = 57,
  UKey_Yen = 165,
  UKey_Escape = 256,
  UKey_Tab,
  UKey_Backspace,
  UKey_Delete,
  UKey_Return,
  UKey_Left,
  UKey_Up ,
  UKey_Right ,
  UKey_Down ,
  UKey_Prior , /* page up */
  UKey_Next , /* page down */
  UKey_Home,
  UKey_End,
  UKey_Multi_key, /* multi-key character compose */
  UKey_Mode_switch, /* charcter set switch */
  UKey_Kanji, /* kanji, kanji convert */
  UKey_Muhenkan, /* cancel conversion */
  UKey_Henkan_Mode, /* start/stop conversion */
  UKey_Henkan = UKey_Henkan_Mode, /* alias for Henkan_Mode */
  UKey_Romaji,
  UKey_Hiragana,
  UKey_Katakana,
  UKey_Hiragana_Katakana, /* hiragana/katakana toggle */
  UKey_Zenkaku,
  UKey_Hankaku,
  UKey_Zenkaku_Hankaku, /* zenkaku/hankaku toggle */
  UKey_Touroku,
  UKey_Massyo,
  UKey_Kana_Lock,
  UKey_Kana_Shift,
  UKey_Eisu_Shift, /* alphanumeric shift */
  UKey_Eisu_toggle, /* alphanumeric toggle */
  UKey_F1,
  UKey_F2,
  UKey_F3,
  UKey_F4,
  UKey_F5,
  UKey_F6,
  UKey_F7,
  UKey_F8,
  UKey_F9,
  UKey_F10,
  UKey_F11,
  UKey_F12,
  UKey_F13,
  UKey_F14,
  UKey_F15,
  UKey_F16,
  UKey_F17,
  UKey_F18,
  UKey_F19,
  UKey_F20,
  UKey_F21,
  UKey_F22,
  UKey_F23,
  UKey_F24,
  UKey_F25,
  UKey_F26,
  UKey_F27,
  UKey_F28,
  UKey_F29,
  UKey_F30,
  UKey_F31,
  UKey_F32,
  UKey_F33,
  UKey_F34,
  UKey_F35, /* X, Gtk and Qt supports up to F35 */
  /* non-standard platform specific keys (e.g. Zaurus PDA) */
  UKey_Private1,
  UKey_Private2,
  UKey_Private3,
  UKey_Private4,
  UKey_Private5,
  UKey_Private6,
  UKey_Private7,
  UKey_Private8,
  UKey_Private9,
  UKey_Private10,
  UKey_Private11,
  UKey_Private12,
  UKey_Private13,
  UKey_Private14,
  UKey_Private15,
  UKey_Private16,
  UKey_Private17,
  UKey_Private18,
  UKey_Private19,
  UKey_Private20,
  UKey_Private21,
  UKey_Private22,
  UKey_Private23,
  UKey_Private24,
  UKey_Private25,
  UKey_Private26,
  UKey_Private27,
  UKey_Private28,
  UKey_Private29,
  UKey_Private30,
  /* this part is especially unstable */
  /* modifier keys: "_key" suffix should be removed in the future */
  UKey_Shift_key,
  UKey_Control_key,
  UKey_Alt_key,
  UKey_Meta_key,
  UKey_Super_key,
  UKey_Hyper_key,
  UKey_Insert,

  /* These new keys added at uim 1.3.0 are placed here to keep (virtually)
   * backward-compatible ABI. It will be relocated to appropriate place when
   * an backward-incompatible ABI change has occur. */
  UKey_Codeinput,
  UKey_SingleCandidate,
  UKey_MultipleCandidate,
  UKey_PreviousCandidate,

  UKey_Hangul,
  UKey_Hangul_Start,
  UKey_Hangul_End,
  UKey_Hangul_Hanja,
  UKey_Hangul_Jamo,
  UKey_Hangul_Romaja,
  UKey_Hangul_Codeinput,
  UKey_Hangul_Jeonja,
  UKey_Hangul_Banja,
  UKey_Hangul_PreHanja,
  UKey_Hangul_PostHanja,
  UKey_Hangul_SingleCandidate,
  UKey_Hangul_MultipleCandidate,
  UKey_Hangul_PreviousCandidate,
  UKey_Hangul_Special,

  /* dead keys */
  UKey_Dead_Grave,
  UKey_Dead_Acute,
  UKey_Dead_Circumflex,
  UKey_Dead_Tilde,
  UKey_Dead_Macron,
  UKey_Dead_Breve,
  UKey_Dead_Abovedot,
  UKey_Dead_Diaeresis,
  UKey_Dead_Abovering,
  UKey_Dead_Doubleacute,
  UKey_Dead_Caron,
  UKey_Dead_Cedilla,
  UKey_Dead_Ogonek,
  UKey_Dead_Iota,
  UKey_Dead_VoicedSound,
  UKey_Dead_SemivoicedSound,
  UKey_Dead_Belowdot,
  UKey_Dead_Hook,
  UKey_Dead_Horn,

  /* Kana keys */
  UKey_Kana_Fullstop,
  UKey_Kana_OpeningBracket,
  UKey_Kana_ClosingBracket,
  UKey_Kana_Comma,
  UKey_Kana_Conjunctive,
  UKey_Kana_WO,
  UKey_Kana_a,
  UKey_Kana_i,
  UKey_Kana_u,
  UKey_Kana_e,
  UKey_Kana_o,
  UKey_Kana_ya,
  UKey_Kana_yu,
  UKey_Kana_yo,
  UKey_Kana_tsu,
  UKey_Kana_ProlongedSound,
  UKey_Kana_A,
  UKey_Kana_I,
  UKey_Kana_U,
  UKey_Kana_E,
  UKey_Kana_O,
  UKey_Kana_KA,
  UKey_Kana_KI,
  UKey_Kana_KU,
  UKey_Kana_KE,
  UKey_Kana_KO,
  UKey_Kana_SA,
  UKey_Kana_SHI,
  UKey_Kana_SU,
  UKey_Kana_SE,
  UKey_Kana_SO,
  UKey_Kana_TA,
  UKey_Kana_CHI,
  UKey_Kana_TSU,
  UKey_Kana_TE,
  UKey_Kana_TO,
  UKey_Kana_NA,
  UKey_Kana_NI,
  UKey_Kana_NU,
  UKey_Kana_NE,
  UKey_Kana_NO,
  UKey_Kana_HA,
  UKey_Kana_HI,
  UKey_Kana_FU,
  UKey_Kana_HE,
  UKey_Kana_HO,
  UKey_Kana_MA,
  UKey_Kana_MI,
  UKey_Kana_MU,
  UKey_Kana_ME,
  UKey_Kana_MO,
  UKey_Kana_YA,
  UKey_Kana_YU,
  UKey_Kana_YO,
  UKey_Kana_RA,
  UKey_Kana_RI,
  UKey_Kana_RU,
  UKey_Kana_RE,
  UKey_Kana_RO,
  UKey_Kana_WA,
  UKey_Kana_N,
  UKey_Kana_VoicedSound,
  UKey_Kana_SemivoicedSound,

  UKey_Caps_Lock,
  UKey_Num_Lock,
  UKey_Scroll_Lock,

  UKey_Other = 1000
};
  
enum UKeyModifier {
  UMod_Shift = 1,
  UMod_Control = 2,
  UMod_Alt = 4,
  UMod_Meta = 8,
  UMod_Pseudo0 = 16,
  UMod_Pseudo1 = 32,
  UMod_Super = 64,
  UMod_Hyper = 128
};
  
enum UPreeditAttr {
  UPreeditAttr_None = 0,
  UPreeditAttr_UnderLine = 1,
  UPreeditAttr_Reverse = 2,
  UPreeditAttr_Cursor = 4,
  UPreeditAttr_Separator = 8
};

/* Cursor of clipboard text is always positioned at end. */
enum UTextArea {
  UTextArea_Unspecified = 0,
  UTextArea_Primary     = 1,  /* primary text area which IM commits to */
  UTextArea_Selection   = 2,  /* user-selected region of primary text area */
  UTextArea_Clipboard   = 4   /* clipboard text */
};

enum UTextOrigin {
  UTextOrigin_Unspecified = 0,
  UTextOrigin_Cursor      = 1,  /* current position of the cursor */
  UTextOrigin_Beginning   = 2,  /* beginning of the text */
  UTextOrigin_End         = 3   /* end of the text */
};

/*
 * Text extent specifiers
 *
 * All bridges that support the text acquisition API must implement the
 * handlings for these 'required' text extent specifiers.
 *
 *   required:
 *     - zero and positive numbers
 *     - UTextExtent_Full
 *     - UTextExtent_Line
 *
 * Zero and positive numbers are interpreted as string length (counted in
 * characters, not bytes).
 *
 *
 * Following language-specific extent specifiers are recommended to be
 * implemented although experimental. Input methods that use these specifiers
 * should separate the features based on the specifiers as "experimental
 * features" and off by default.  And do not assume correct result is always
 * returned. These specifiers may be re-categorized as 'required' when we have
 * been well-experimented and it is considered as appropriate.
 *
 *   recommended:
 *     - UTextExtent_Paragraph
 *     - UTextExtent_Sentence
 *     - UTextExtent_Word
 *
 *
 * These specifiers are experimental and reserved for future use.
 *
 *   experimental:
 *     - UTextExtent_CharFrags
 *     - UTextExtent_DispRect
 *     - UTextExtent_DispLine
 *
 * UTextExtent_CharFrags stands for "character fragments" such as Thai
 * combining marks, Hangul jamo, Japanese voiced consonant marks etc. It is
 * supposed to be used for the "surrounding text" acquisition. Bridges should
 * supply only such combinable characters if this specifier is passed.
 */
enum UTextExtent {
  UTextExtent_Unspecified = -1,  /* invalid */

  /* logical extents */
  UTextExtent_Full      = -2,   /* beginning or end of the whole text */
  UTextExtent_Paragraph = -3,   /* the paragraph which the origin is included */
  UTextExtent_Sentence  = -5,   /* the sentence which the origin is included */
  UTextExtent_Word      = -9,   /* the word which the origin is included */
  UTextExtent_CharFrags = -17,  /* character fragments around the origin */

  /* physical extents */
  UTextExtent_DispRect  = -33,  /* the text region displayed in the widget */
  UTextExtent_DispLine  = -65,  /* displayed line (eol: linebreak) */
  UTextExtent_Line      = -129  /* real line      (eol: newline char) */
};

/* abstracting platform-dependent character code conversion method */
struct uim_code_converter {
  int  (*is_convertible)(const char *tocode, const char *fromcode);
  void *(*create)(const char *tocode, const char *fromcode);
  char *(*convert)(void *obj, const char *str);
  void (*release)(void *obj);
};

/**
 * Initialize and allocate resources to start to input.  This function
 * must be called before any other uim functions are called.  The
 * second calling of this function makes no sense. This function
 * performs setlocale(3). Be careful if your code also performs it.
 *
 * @return 0 on success, otherwise -1
 */
int
uim_init(void);

/**
 * Finalize uim library by freeing all resources allocated by uim.
 */
void
uim_quit(void);

/**
 * Create new input context.
 * param lang and engine is used to specify appropriate input method tied to returning input context.
 * Currently selected input method is used if you specify both as NULL.
 *
 * @param ptr cookie value which is passed as an argument of uim's callback functions.
 * @param enc iconv-acceptable name of client encoding. Say "UTF-8" to use most of input methods.
 * @param lang name language you want to input
 * @param engine name of conversion engine you want to use
 * @param conv character code converter. Say "uim_iconv" or place your own platform-specific, preferable implementation. See struct uim_code_converter.
 * @param commit_cb callback function which is called when there comes somestring to commit. 1st argument of this callback function is "ptr" and 2nd argument the string to commit.
 *
 * @return uim_context which newly created.
 */ 
uim_context
uim_create_context(void *ptr,
		   const char *enc,
		   const char *lang,
		   const char *engine,
		   struct uim_code_converter *conv,
		   void (*commit_cb)(void *ptr, const char *str));

/**
 * Release input context which is created by uim_create_context.
 *
 * @param uc input cotext to be released.
 * @see uim_create_context
 */
void
uim_release_context(uim_context uc);

/**
 * Reset input context to neutral state.
 *
 * This handler MUST NOT commit a string and/or update the preedit. If a
 * preedit string is existing on a GUI toolkit-level reset, the bridge is
 * responsible to clear it. Internal state that considered as 'global' is
 * permitted to be kept.
 *
 * @param uc input context to be reset
 */
void
uim_reset_context(uim_context uc);

/**
 * Notify input context that the textarea is being focused in.
 *
 * The input context is permitted to commit a string and/or update the
 * preedit.
 *
 * @param uc input context
 */
void
uim_focus_in_context(uim_context uc);

/**
 * Notify input context that the textarea is being focused out.
 *
 * The input context is permitted to commit a string and/or update the
 * preedit.
 *
 * @param uc input context
 */
void
uim_focus_out_context(uim_context uc);

/**
 * Notify input context that the input point has been relocated.
 *
 * This notifies an input context that the input point (textarea and/or cursor
 * position) has been relocated. The input context is permitted to commit a
 * string and/or update the preedit.
 *
 * @param uc input context
 */
void
uim_place_context(uim_context uc);

/**
 * Notify input context that the input at the position has been discontinued.
 *
 * This notifies an input context that input at current input point (textarea
 * and/or cursor position) has been discontinued. The input context is
 * permitted to commit a string, but must not update/clear the
 * preedit. Bridge-level preedit must be cleared by bridge itself. uim-level
 * preedit is permitted to be preserved for subsequent 'place' handler call,
 * or else silently cleared.
 *
 * @param uc input context
 */
void
uim_displace_context(uim_context uc);

/**
 * Set callback functions to be called when the preedit string changes.
 * Preedit string is passed to applications by sequential calls of pushback_cb, between the calls of clear_cb and update_cb.
 * Each callback's 1st argument "ptr" corresponds to the 1st argument of uim_create_context.
 *
 * @param uc input context
 * @param clear_cb called when preedit string should be cleared.
 * @param pushback_cb called when additional preedit string comes. 2nd argument is the attribute of preedit string and 3rd argument is additonal preedit string.
 * @param update_cb called when the changes of preedit string should be updated graphically.
 *
 * @see uim_create_context
 */
void
uim_set_preedit_cb(uim_context uc,
		   void (*clear_cb)(void *ptr),
		   void (*pushback_cb)(void *ptr,
				       int attr,
				       const char *str),
		   /* page change cb .. etc will be here */
		   void (*update_cb)(void *ptr));

/* dealing pressing key */
/**
 * Send key press event to uim context
 *
 * @param uc input context which event goes to
 * @param key keycode and value is 32 to 126.
 * @param state keystate
 *
 * @return 0 if IM not handle the event, otherwise the event is handled by IM so please stop key event handling.
 */
int
uim_press_key(uim_context uc, int key, int state);
/**
 * Send key press release to uim context
 *
 * @param uc input context which event goes to
 * @param key keycode and valued is 32 to 126.
 * @param state keystate
 *
 * @return 0 if IM not handle the event, otherwise the event is handled by IM so please stop key event handling.
 */
int
uim_release_key(uim_context uc, int key, int state);



/* im list */
/**
 * Get the number of input methods with same encoding and language of the passed context.
 *
 * @param uc input context
 *
 * @return number of input methods
 */
int uim_get_nr_im(uim_context uc);

/**
 * Get the name of nth input method.
 *
 * @warning you must not free the result.
 *
 * @param uc input context
 * @param nth index of input method.
 *
 * @return name of nth input method
 */
const char *uim_get_im_name(uim_context uc, int nth);

/**
 * Get the language of nth input method.
 *
 * @warning you must not free the result.
 *
 * @param uc input context
 * @param nth index of input method
 */
const char *uim_get_im_language(uim_context uc, int nth);

/**
 * Get the short description of nth input method.
 *
 * @warning you must not free the result.
 *
 * @param uc input context
 * @param nth index of input method
 */
const char *uim_get_im_short_desc(uim_context uc, int nth);

/**
 * Get the encoding of nth input method.
 *
 * @warning you must not free the result
 *
 * @param uc input context
 * @param nth index of input method
 *
 * @return nth input method's encoding
 */
const char *uim_get_im_encoding(uim_context uc, int nth);


/**
 * Get the default input method engine name.
 *
 * @warning you must not free the result
 *
 * @param localename locale name
 *
 * @return input method name.
 */
const char *uim_get_default_im_name(const char *localename);

/**
 * Get the most preferable input method engine name for the localename.
 *
 * @warning you must not free the result
 *
 * @param localename locale name
 *
 * @return input method name.
 */
const char *uim_get_im_name_for_locale(const char *localename);

/* candidate */
/**
 * Set callback functions to be called when the candidate-selection occurs.
 * Each callback's 1st argument "ptr" corresponds to the 1st argument of uim_create_context.
 *
 * @param uc input context
 * @param activate_cb called when candidate window should be activated.
 * @param select_cb called when a candidate is selected and its index is 2nd argument. 
 * @param shift_page_cb 
 * @param deactivate_cb called when candidate window should be deactivated.
 *
 * @see uim_create_context
 */
int uim_set_candidate_selector_cb(uim_context uc,
				  void (*activate_cb)(void *ptr, int nr, int display_limit),
				  void (*select_cb)(void *ptr, int index),
				  void (*shift_page_cb)(void *ptr, int direction),
				  void (*deactivate_cb)(void *ptr));

/**
 * Get candidate data.
 *
 * @param uc input context
 * @param index index of the candidate you want to get
 * @param accel_enumeration_hint
 *
 * @warning You must free the result by uim_candidate_free
 *
 * @see uim_candidate_free
 *
 * @return data of candidate
 */
uim_candidate uim_get_candidate(uim_context uc, int index, int accel_enumeration_hint);
/**
 * Free the result of uim_get_candidate.
 *
 * @param cand the data you want to free
 */
void uim_candidate_free(uim_candidate cand);

int   uim_get_candidate_index(uim_context uc);
/**
 * Select the candidate by specifying $index
 *
 * @param uc input context
 * @param index index of the candidate you want to select
 */
void  uim_set_candidate_index(uim_context uc, int index);

/**
 * Get the string of candidate.
 *
 * @warning You must not free the result. All datas are freed by calling uim_candidate_free.
 *
 * @param cand the data you got by calling uim_get_candidate
 *
 * @see uim_get_candidate
 *
 * @return string of candidate data
 */
const char *uim_candidate_get_cand_str(uim_candidate cand);
/**
 * Get the string of candidate's heading label.
 *
 * @warning You must not free the result. All datas are freed by calling uim_candidate_free.
 *
 * @param cand the data you got by uim_get_candidate
 *
 * @see uim_get_candidate
 *
 * @return string of candidate data's heading label
 */
const char *uim_candidate_get_heading_label(uim_candidate cand);

/**
 * Get the string of candidate's annotation.
 *
 * @warning You must not free the result. All datas are freed by calling uim_candidate_free.
 * @warning If no data is available, return string is "" (empty string).
 *
 * @param cand the data you got by uim_get_candidate
 *
 * @see uim_get_candidate
 *
 * @return string of candidate's annotation str
 */
const char *uim_candidate_get_annotation_str(uim_candidate cand);

/*property*/
/**
 * Set callback function to be called when property list is updated.
 *
 * @param uc input context
 * @param update_cb called when property list is updated.
 *        1st argument "ptr" corresponds to the 1st argument of uim_create_context.
 *        2nd argument is the message to be sent to the helper server with "prop_list_update" command and charset info.
 */
void
uim_set_prop_list_update_cb(uim_context uc,
			    void (*update_cb)(void *ptr, const char *str));
/**
 * Force to input context to update property list.
 *
 * @param uc input context
 */
void
uim_prop_list_update(uim_context uc);

/**
 * Obsolete. Only existing for Backward compatibility and should not
 * be called.
 */
void
uim_set_prop_label_update_cb(uim_context uc,
			     void (*update_cb)(void *ptr, const char *str));
/**
 * Obsolete. Only existing for Backward compatibility and should not
 * be called.
 */
void
uim_prop_label_update(uim_context uc);
void
uim_prop_activate(uim_context uc, const char *str);
void
uim_prop_update_custom(uim_context uc, const char *custom, const char *val);
uim_bool
uim_prop_reload_configs(void);

/* mode is obsoleted by property, so please use property API instead of mode API */
int
uim_get_current_mode(uim_context uc);
void
uim_set_mode(uim_context uc, int nth);
void
uim_set_mode_cb(uim_context uc, void (*update_cb)(void *ptr,
						  int mode));
/* mode list */
int
uim_get_nr_modes(uim_context uc);
/* you must not free the result */
const char *
uim_get_mode_name(uim_context uc, int nth);
void
uim_set_mode_list_update_cb(uim_context uc,
			    void (*update_cb)(void *ptr));

/* text acquisition */
/*
 * Consideration about text update interface
 *
 * In under-development composer framework, a single commit event of a
 * composer instance can commit a text, update the preedit, and delete
 * surrounding texts atomically to reduce text flicker. But because
 * introducing this interface to current uim breaks backward compatibility
 * completely, adding separated surrounding text deletion interface is better
 * solution at now.  -- YamaKen 2006-10-07
 *
 * http://anonsvn.freedesktop.org/svn/uim/branches/composer/scm/event.scm
 *
 * (define-event 'commit
 *   upward-event-rec-spec
 *   '((utext           ())   ;; can include cursor position info
 *     (preedit-updated #t)   ;; can also update preedit as atomic event
 *     (former-del-len  0)    ;; for surrounding text operation
 *     (latter-del-len  0)))  ;; for surrounding text operation
 */
/**
 * Set callback functions for text acquisition and modification.
 *
 * All "former_len" and "latter_len" can be specified by zero, positive
 * numbers or enum UTextExtent. The text length is counted in singlebyte or
 * multibyte characters (not counted in bytes). Bridges may return a string
 * shorter than requested if the text is actually shorter than the requested
 * length, or the target textarea does not have the text acquisition
 * ability. Otherwise exact length string must be returned.
 *
 * Both @a acquire_cb and @a delete_cb returns zero if succeeded, otherwise
 * returns a negative integer if the bridge does not support the specified
 * text operation. But even if zero is returned, actual length of acquired
 * strings cannot be assumed (i.e. may be shorter than requested).
 *
 * @param uc input context
 * @param acquire_cb called back when the input context want to acquire a
 *        bridge-side text.
 *        1st argument "ptr" passes back the 1st argument of
 *                     uim_create_context.
 *        2nd argument "text_id" specifies a textarea having target text.
 *        3rd argument "origin" specifies the origin which former_len and
 *                     latter_len refers.
 *        4th argument "former_len" specifies length of the text preceding the
 *                     text origin to be acquired.
 *        5th argument "latter_len" specifies length of the text following the
 *                     text origin to be acquired.
 *        6th argument "former" passes a pointer reference to receive the
 *                     former part of the acquired text. The returned pointer
 *                     may be NULL and object ownership is transferred to
 *                     libuim.
 *        7th argument "latter" passes a pointer reference to receive the
 *                     latter part of the acquired text. The returned pointer
 *                     may be NULL and object ownership is transferred to
 *                     libuim.
 * @param delete_cb called back when the input context want to delete a
 *        bridge-side text.
 *        1st argument "ptr" passes back the 1st argument of
 *                     uim_create_context.
 *        2nd argument "text_id" specifies a textarea which is going to be
 *                     operated on.
 *        3rd argument "origin" specifies the origin which former_len and
 *                     latter_len refers.
 *        4th argument "former_len" specifies length of the text preceding the
 *                     text origin to be deleted.
 *        5th argument "latter_len" specifies length of the text following the
 *                     text origin to be deleted.
 */
void
uim_set_text_acquisition_cb(uim_context uc,
			    int (*acquire_cb)(void *ptr,
					      enum UTextArea text_id,
					      enum UTextOrigin origin,
					      int former_len, int latter_len,
					      char **former, char **latter),
			    int (*delete_cb)(void *ptr,
					     enum UTextArea text_id,
					     enum UTextOrigin origin,
					     int former_len, int latter_len));

/**
 * Input arbitrary string into input context.
 *
 * @param uc the input context tied with the text area.
 * @param str the string to be input into.
 *
 * @return true if @a str is accepted (consumed) by the input context.
 */
uim_bool
uim_input_string(uim_context uc, const char *str);

/*
 * Set callback function to be called when configuration of input
 * context is changed.
 *
 * @param uc input context
 * @param changed_cb called when configuration of the input context is changed.
 *        1st argument "ptr" corresponds to the 1st argument of uim_create_context.
 */
void
uim_set_configuration_changed_cb(uim_context uc,
				 void (*changed_cb)(void *ptr));

/*
 * Set callback functions called when IM-switching of specific set of context
 * is requested.
 *
 * When the functions are called back, bridges should re-initialize the
 * specified input contexts with the IM specified by 2nd argument
 * 'name'. Since the re-initialization method of specified contexts vary for
 * each IM environment, it is delegated to bridges via the callback. For
 * example, ordinary desktop system should send the helper message
 * im_change_whole_desktop in response to @a sw_system_im_cb. But in embedded
 * systems such as Qtopia, nothing to do with @a sw_system_im_cb since only
 * one input context is running on the window system and so system-global.
 *
 * @param uc input context

 * @param sw_app_im_cb called when re-initialization of all contexts within
 *        the application that @a uc belongs to, with specified IM is
 *        requested. 1st argument "ptr" corresponds to the 1st argument of
 *        uim_create_context, and 2nd "name" is requested idname of IM. The
 *        originating context is supposed to already be switched, and must not
 *        switched by the callback.
 * @param sw_system_im_cb called when re-initialization of all contexts
 *        running on the system that @a uc is running on, with specified IM is
 *        requested. The originating context is supposed to already be
 *        switched.
 */
void
uim_set_im_switch_request_cb(uim_context uc,
			     void (*sw_app_im_cb)(void *ptr, const char *name),
			     void (*sw_system_im_cb)(void *ptr, const char *name));

/* Utility functions */
int
uim_ipc_open_command(int old_pid, FILE **read_handler, FILE **write_handler, const char *command);
int
uim_ipc_open_command_with_option(int old_pid, FILE **read_handler, FILE **write_handler, const char *command, const char *option);
char *
uim_ipc_send_command(int *pid, FILE **read_handler,
		     FILE **write_handler, const char *command, const char *str);

/* will be deprecated. use custom API (uim-custom.h) instead */
char *uim_symbol_value_str(const char *symbol_str);

/* an uim_code_converter implementation using iconv */
extern struct uim_code_converter *uim_iconv;

#ifdef __cplusplus
}
#endif

#endif /* _uim_h_included_ */
