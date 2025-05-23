#ifndef CONFIG_H
#define CONFIG_H
#include "./dwm.h"
#include "./exitdwm.h"

/* border pixel of windows */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 1;    /* gaps between windows */
static const unsigned int snap = 1;     /* snap pixel */

/* systray */
static const unsigned int systraypinning =
    0; // 0: sloppy systray follows selected monitor, >0: pin systray to monitor
       // X
static const unsigned int systrayonleft =
    0; // 0: systray in the right corner, >0: systray on left of status text
static const unsigned int systrayspacing = 1; // systray spacing
static const int systraypinningfailfirst =
    1; // 1: if pinning fails, display systray on the first monitor, False:
       // display systray on the last monitor
static const int showsystray = 1; // 0 means no systray

static const int showbar = 1; // 0 means no bar
static const int topbar = 1;  // 0 means bottom bar

static const char *fonts[] = {"Hack Nerd Font:size=10"}; // fonts
static const char dmenufont[] = "Hack Nerd Font:size=10";          // dmenu font

// colors
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";

// themes
struct Theme {
  const char *inactive;
  const char *active;
  const char *bg;
  const char *focus;
};

static const struct Theme material = {
    .inactive = "#4c566a",
    .active = "#1e1e2e",
    .bg = "#0f101a",
    .focus = "#e2e4e5",
};

static const struct Theme onedark = {
    .inactive = "#4c566a",
    .active = "#222222",
    .bg = "#1e2127",
    .focus = "#E06C75",
};

static const struct Theme nord = {
    .inactive = "#4c566a",
    .active = "#222222",
    .bg = "#2e3440",
    .focus = "#81a1c1",
};

static const struct Theme monokai_pro = {
    .inactive = "#727072",
    .active = "#2d2a2e",
    .bg = "#2d2a2e",
    .focus = "#a9dc76",
};

static const struct Theme gruvbox = {
    .inactive = "#928374",
    .active = "#fbf1c7",
    .bg = "#282828",
    .focus = "#83a598",
};

static const struct Theme solarized_dark = {
    .inactive = "#657b83",
    .active = "#93a1a1",
    .bg = "#002b36",
    .focus = "#b58900",
};

static const struct Theme dracula = {
    .inactive = "#6272a4",
    .active = "#f8f8f2",
    .bg = "#282a36",
    .focus = "#ff79c6",
};

static const struct Theme tomorrow_night = {
    .inactive = "#4d4d4c",
    .active = "#222222",
    .bg = "#1d1f21",
    .focus = "#cc6666",
};

static const char window_border[] = "#000000";

// colors
static const char *colors[][3] = {
    // fg                 bg             border
    // Tema Material
    {material.inactive, material.bg, window_border},
    {material.active, material.focus, material.focus},

    // Tema Dracula
    {dracula.inactive, dracula.bg, window_border},
    {dracula.active, dracula.focus, dracula.focus},

    // Tema Nord
    {nord.inactive, nord.bg, window_border},
    {nord.active, nord.focus, nord.focus},

    // Tema Monokai Pro
    {monokai_pro.inactive, monokai_pro.bg, window_border},
    {monokai_pro.active, monokai_pro.focus, monokai_pro.focus},

    // Tema Onedark
    {onedark.inactive, onedark.bg, window_border},
    {onedark.active, onedark.focus, onedark.focus},

    // Tema Gruvbox
    {gruvbox.inactive, gruvbox.bg, window_border},
    {gruvbox.active, gruvbox.focus, gruvbox.focus},

    // Tema Solarized Dark
    {solarized_dark.inactive, solarized_dark.bg, window_border},
    {solarized_dark.active, solarized_dark.focus, solarized_dark.focus},

    // Tema Tomorrow Night
    {tomorrow_night.inactive, tomorrow_night.bg, window_border},
    {tomorrow_night.active, tomorrow_night.focus, tomorrow_night.focus},
};

static const char *tags[] = {" ", "", "", "", "", "", ""}; // tags

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */

static const float mfact = 0.5; // factor of master area size [0.05..0.95]
static const int nmaster = 1;   // number of clients in master area */
static const int resizehints =
    1; // 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; // 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {
        " ",
        tile,
    }, /* first entry is default */
    {
        " ",
        NULL,
    }, /* no layout function means floating behavior */
    {
        "",
        monocle,
    },
};

/* función para mover el tag izquierdo*/
void
viewtoleft(const Arg *arg) {
  unsigned int i = 0;
  for (; i < LENGTH(tags); i++) {
    if (selmon->tagset[selmon->seltags] & (1 << i)) {
      if (i == 0) {
        view(&(Arg){.ui = 1 << (LENGTH(tags) - 1)}); // si es el primer tag, ir al ultimo
      } else {
        view(&(Arg){.ui = 1 << (i - 1)}); // mover al tag anterior
      }
      break;
    }
  }
}

/*función para */
void
viewtoright(const Arg *arg) {
  unsigned int i = 0;
  for (; i < LENGTH(tags); i++) {
    if (selmon->tagset[selmon->seltags] & (1 << i)) {
      if (i == LENGTH(tags) - 1) {
        view(&(Arg){.ui = 1 << 0}); // si es el primer tag, ir al primero
      } else {
        view(&(Arg){.ui = 1 << (i + 1)}); // mover al siguiente tag
      }
      break;
    }
  }
}

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

#define STATUSBAR "dwmblocks"

// Helper for spawning shell commands
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
/* component of dmenucmd, manipulated in spawn() */
static char *dmenucmd[] = {"dmenu_run"};
static char dmenumon[2] = "0";

static char *screenshot[] = {
    "flameshot", "screen", "--path", NULL, NULL,
};

#include <X11/XF86keysym.h>

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, SHCMD("dmenu_run")},
    {MODKEY, XK_r, spawn, SHCMD("i3-dmenu-desktop")},
    {MODKEY | ShiftMask, XK_d, spawn, SHCMD("rofi -show drun -show-icons")},
    {MODKEY, XK_t, spawn, SHCMD("st")},
    //{MODKEY, XK_f, spawn, SHCMD("firefox")},

    /* volume control */
    {0, XF86XK_AudioRaiseVolume, spawn,
     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +2%")},
    {0, XF86XK_AudioLowerVolume, spawn,
     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -2%")}, // volume down
    {0, XF86XK_AudioMute, spawn,
     SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")}, // mute
    {0, XK_Print, spawn, SHCMD("shotgun")},      // screenshot
    {MODKEY, XK_Print, spawn, SHCMD("kazam")},
    
    /* Brightness control */
    { 0, XF86XK_MonBrightnessUp,   spawn, SHCMD("brightnessctl set +2%") },
    { 0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 2%-") },

    {MODKEY, XK_e, spawn, SHCMD("thunar")}, // file explorer
    {MODKEY, XK_f, spawn, SHCMD("firefox")}, // browser
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_Left, focusstack, {.i = -1} },
    {MODKEY, XK_Right, focusstack, {.i = +1} },
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY | Mod1Mask, XK_Left, viewtoleft, {0} }, // move to left
    {MODKEY | Mod1Mask, XK_Right, viewtoright, {0} }, //move to right
    {MODKEY | ShiftMask, XK_a, spawn, SHCMD("dmenu-script1") }, //script personalizado
    //{MODKEY | ShiftMask, XK_t, schemeToggle, {0}},
    {MODKEY | ShiftMask, XK_z, schemeCycle, {0}},
    {MODKEY, XK_p, incnmaster, {.i = -1}},
    {MODKEY, XK_Up, setmfact, {.f = -0.05}},
    {MODKEY, XK_Down, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_c, killclient, {0}},
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY | ShiftMask, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_s, togglesticky, {0}}, // toggle sticky
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_plus, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_s, exitdwm, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, sigstatusbar, {.i = 1}},
    {ClkStatusText, 0, Button2, sigstatusbar, {.i = 2}},
    {ClkStatusText, 0, Button3, sigstatusbar, {.i = 3}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};

#endif
