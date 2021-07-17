#define PATH(name)                      "/home/testninja/.scripts/"name

#define CMDOUTLENGTH                    50

/* DELIMITERENDCHAR must be less than 32.
 * At max, DELIMITERENDCHAR - 1 number of clickable blocks are allowed.
 * Raw characters larger than DELIMITERENDCHAR and smaller than ' ' in ASCII
   character set can be used for signaling color change in status.
 * The character corresponding to DELIMITERENDCHAR + 1 ('\x0b' when
   DELIMITERENDCHAR is 10) will switch the active colorscheme to the first one
   defined in colors array in dwm's config.h and so on.
 * If you wish to change DELIMITERENDCHAR, don't forget to update its value in
   dwm.c and color codes in your pathu programs. */
#define DELIMITERENDCHAR                10

static const char delimiter[] = { ' ', ' ', DELIMITERENDCHAR };

#include "block.h"

/* If interval of a block is set to 0, the block will only be updated once at
   startup.
 * If interval is set to a negative value, the block will never be updated in
   the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the
   block.
 * Signal must be less than DELIMITERENDCHAR for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be
   delivered first. */

/* 1 interval = INTERVALs seconds, INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0

static Block blocks[] = {
/*      pathu                                   pathc                                    interval       signal */
        { PATH("keyboard_layout.sh"),           NULL,                                    3600,          5},
        { PATH("music.sh"),                     PATH("music.sh"),                        5,             6},
        { PATH("toggle_lockscreen_timeout.sh"), PATH("toggle_lockscreen_timeout.sh"),    300,           1},
        { PATH("mic.sh"),                       PATH("mic.sh"),                          300,           4},
        { PATH("volume.sh"),                    PATH("volume.sh"),                       3600,          3},
        { PATH("memory.sh"),                    NULL,                                    3,             0},
        { PATH("cpu_usage.sh"),                 NULL,                                    3,             0},
        { PATH("net_speed.sh"),                 NULL,                                    1,             0},
        { PATH("net_usage.sh"),                 NULL,                                    10,            0},
        { PATH("battery.sh"),                   NULL,                                    300,           0},
        { PATH("datetime.sh"),                  PATH("datetime.sh"),                     60,            2},
        { NULL }
};
