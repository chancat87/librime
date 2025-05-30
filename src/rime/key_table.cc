
#include <stddef.h>
#include <string.h>
#include <X11/keysym.h>
#include <rime_api.h>

static const char* modifier_name[] = {
    "Shift",                            // 0
    "Lock",                             // 1
    "Control",                          // 2
    "Alt",                              // 3
    "Mod2",                             // 4
    "Mod3",                             // 5
    "Mod4",                             // 6
    "Mod5",                             // 7
    "Button1",                          // 8
    "Button2",                          // 9
    "Button3",                          // 10
    "Button4",                          // 11
    "Button5",                          // 12
    NULL,      NULL, NULL, NULL, NULL,  // 13 - 17
    NULL,      NULL, NULL, NULL, NULL,  // 18 - 22
    NULL,      NULL, NULL,              // 23 - 25
    "Super",                            // 26
    "Hyper",                            // 27
    "Meta",                             // 28
    NULL,                               // 29
    "Release",                          // 30
    NULL,                               // 31
};

static const char key_names[] =
    "space\0"
    "exclam\0"
    "quotedbl\0"
    "numbersign\0"
    "dollar\0"
    "percent\0"
    "ampersand\0"
    "apostrophe\0"
    "quoteright\0"
    "parenleft\0"
    "parenright\0"
    "asterisk\0"
    "plus\0"
    "comma\0"
    "minus\0"
    "period\0"
    "slash\0"
    "0\0"
    "1\0"
    "2\0"
    "3\0"
    "4\0"
    "5\0"
    "6\0"
    "7\0"
    "8\0"
    "9\0"
    "colon\0"
    "semicolon\0"
    "less\0"
    "equal\0"
    "greater\0"
    "question\0"
    "at\0"
    "A\0"
    "B\0"
    "C\0"
    "D\0"
    "E\0"
    "F\0"
    "G\0"
    "H\0"
    "I\0"
    "J\0"
    "K\0"
    "L\0"
    "M\0"
    "N\0"
    "O\0"
    "P\0"
    "Q\0"
    "R\0"
    "S\0"
    "T\0"
    "U\0"
    "V\0"
    "W\0"
    "X\0"
    "Y\0"
    "Z\0"
    "bracketleft\0"
    "backslash\0"
    "bracketright\0"
    "asciicircum\0"
    "underscore\0"
    "grave\0"
    "quoteleft\0"
    "a\0"
    "b\0"
    "c\0"
    "d\0"
    "e\0"
    "f\0"
    "g\0"
    "h\0"
    "i\0"
    "j\0"
    "k\0"
    "l\0"
    "m\0"
    "n\0"
    "o\0"
    "p\0"
    "q\0"
    "r\0"
    "s\0"
    "t\0"
    "u\0"
    "v\0"
    "w\0"
    "x\0"
    "y\0"
    "z\0"
    "braceleft\0"
    "bar\0"
    "braceright\0"
    "asciitilde\0"
    "nobreakspace\0"
    "exclamdown\0"
    "cent\0"
    "sterling\0"
    "currency\0"
    "yen\0"
    "brokenbar\0"
    "section\0"
    "diaeresis\0"
    "copyright\0"
    "ordfeminine\0"
    "guillemotleft\0"
    "notsign\0"
    "hyphen\0"
    "registered\0"
    "macron\0"
    "degree\0"
    "plusminus\0"
    "twosuperior\0"
    "threesuperior\0"
    "acute\0"
    "mu\0"
    "paragraph\0"
    "periodcentered\0"
    "cedilla\0"
    "onesuperior\0"
    "masculine\0"
    "guillemotright\0"
    "onequarter\0"
    "onehalf\0"
    "threequarters\0"
    "questiondown\0"
    "Agrave\0"
    "Aacute\0"
    "Acircumflex\0"
    "Atilde\0"
    "Adiaeresis\0"
    "Aring\0"
    "AE\0"
    "Ccedilla\0"
    "Egrave\0"
    "Eacute\0"
    "Ecircumflex\0"
    "Ediaeresis\0"
    "Igrave\0"
    "Iacute\0"
    "Icircumflex\0"
    "Idiaeresis\0"
    "ETH\0"
    "Eth\0"
    "Ntilde\0"
    "Ograve\0"
    "Oacute\0"
    "Ocircumflex\0"
    "Otilde\0"
    "Odiaeresis\0"
    "multiply\0"
    "Ooblique\0"
    "Ugrave\0"
    "Uacute\0"
    "Ucircumflex\0"
    "Udiaeresis\0"
    "Yacute\0"
    "THORN\0"
    "Thorn\0"
    "ssharp\0"
    "agrave\0"
    "aacute\0"
    "acircumflex\0"
    "atilde\0"
    "adiaeresis\0"
    "aring\0"
    "ae\0"
    "ccedilla\0"
    "egrave\0"
    "eacute\0"
    "ecircumflex\0"
    "ediaeresis\0"
    "igrave\0"
    "iacute\0"
    "icircumflex\0"
    "idiaeresis\0"
    "eth\0"
    "ntilde\0"
    "ograve\0"
    "oacute\0"
    "ocircumflex\0"
    "otilde\0"
    "odiaeresis\0"
    "division\0"
    "oslash\0"
    "ugrave\0"
    "uacute\0"
    "ucircumflex\0"
    "udiaeresis\0"
    "yacute\0"
    "thorn\0"
    "ydiaeresis\0"
    "Aogonek\0"
    "breve\0"
    "Lstroke\0"
    "Lcaron\0"
    "Sacute\0"
    "Scaron\0"
    "Scedilla\0"
    "Tcaron\0"
    "Zacute\0"
    "Zcaron\0"
    "Zabovedot\0"
    "aogonek\0"
    "ogonek\0"
    "lstroke\0"
    "lcaron\0"
    "sacute\0"
    "caron\0"
    "scaron\0"
    "scedilla\0"
    "tcaron\0"
    "zacute\0"
    "doubleacute\0"
    "zcaron\0"
    "zabovedot\0"
    "Racute\0"
    "Abreve\0"
    "Lacute\0"
    "Cacute\0"
    "Ccaron\0"
    "Eogonek\0"
    "Ecaron\0"
    "Dcaron\0"
    "Dstroke\0"
    "Nacute\0"
    "Ncaron\0"
    "Odoubleacute\0"
    "Rcaron\0"
    "Uring\0"
    "Udoubleacute\0"
    "Tcedilla\0"
    "racute\0"
    "abreve\0"
    "lacute\0"
    "cacute\0"
    "ccaron\0"
    "eogonek\0"
    "ecaron\0"
    "dcaron\0"
    "dstroke\0"
    "nacute\0"
    "ncaron\0"
    "odoubleacute\0"
    "rcaron\0"
    "uring\0"
    "udoubleacute\0"
    "tcedilla\0"
    "abovedot\0"
    "Hstroke\0"
    "Hcircumflex\0"
    "Iabovedot\0"
    "Gbreve\0"
    "Jcircumflex\0"
    "hstroke\0"
    "hcircumflex\0"
    "idotless\0"
    "gbreve\0"
    "jcircumflex\0"
    "Cabovedot\0"
    "Ccircumflex\0"
    "Gabovedot\0"
    "Gcircumflex\0"
    "Ubreve\0"
    "Scircumflex\0"
    "cabovedot\0"
    "ccircumflex\0"
    "gabovedot\0"
    "gcircumflex\0"
    "ubreve\0"
    "scircumflex\0"
    "kappa\0"
    "kra\0"
    "Rcedilla\0"
    "Itilde\0"
    "Lcedilla\0"
    "Emacron\0"
    "Gcedilla\0"
    "Tslash\0"
    "rcedilla\0"
    "itilde\0"
    "lcedilla\0"
    "emacron\0"
    "gcedilla\0"
    "tslash\0"
    "ENG\0"
    "eng\0"
    "Amacron\0"
    "Iogonek\0"
    "Eabovedot\0"
    "Imacron\0"
    "Ncedilla\0"
    "Omacron\0"
    "Kcedilla\0"
    "Uogonek\0"
    "Utilde\0"
    "Umacron\0"
    "amacron\0"
    "iogonek\0"
    "eabovedot\0"
    "imacron\0"
    "ncedilla\0"
    "omacron\0"
    "kcedilla\0"
    "uogonek\0"
    "utilde\0"
    "umacron\0"
    "overline\0"
    "kana_fullstop\0"
    "kana_openingbracket\0"
    "kana_closingbracket\0"
    "kana_comma\0"
    "kana_conjunctive\0"
    "kana_middledot\0"
    "kana_WO\0"
    "kana_a\0"
    "kana_i\0"
    "kana_u\0"
    "kana_e\0"
    "kana_o\0"
    "kana_ya\0"
    "kana_yu\0"
    "kana_yo\0"
    "kana_tsu\0"
    "kana_tu\0"
    "prolongedsound\0"
    "kana_A\0"
    "kana_I\0"
    "kana_U\0"
    "kana_E\0"
    "kana_O\0"
    "kana_KA\0"
    "kana_KI\0"
    "kana_KU\0"
    "kana_KE\0"
    "kana_KO\0"
    "kana_SA\0"
    "kana_SHI\0"
    "kana_SU\0"
    "kana_SE\0"
    "kana_SO\0"
    "kana_TA\0"
    "kana_CHI\0"
    "kana_TI\0"
    "kana_TSU\0"
    "kana_TU\0"
    "kana_TE\0"
    "kana_TO\0"
    "kana_NA\0"
    "kana_NI\0"
    "kana_NU\0"
    "kana_NE\0"
    "kana_NO\0"
    "kana_HA\0"
    "kana_HI\0"
    "kana_FU\0"
    "kana_HU\0"
    "kana_HE\0"
    "kana_HO\0"
    "kana_MA\0"
    "kana_MI\0"
    "kana_MU\0"
    "kana_ME\0"
    "kana_MO\0"
    "kana_YA\0"
    "kana_YU\0"
    "kana_YO\0"
    "kana_RA\0"
    "kana_RI\0"
    "kana_RU\0"
    "kana_RE\0"
    "kana_RO\0"
    "kana_WA\0"
    "kana_N\0"
    "voicedsound\0"
    "semivoicedsound\0"
    "Arabic_comma\0"
    "Arabic_semicolon\0"
    "Arabic_question_mark\0"
    "Arabic_hamza\0"
    "Arabic_maddaonalef\0"
    "Arabic_hamzaonalef\0"
    "Arabic_hamzaonwaw\0"
    "Arabic_hamzaunderalef\0"
    "Arabic_hamzaonyeh\0"
    "Arabic_alef\0"
    "Arabic_beh\0"
    "Arabic_tehmarbuta\0"
    "Arabic_teh\0"
    "Arabic_theh\0"
    "Arabic_jeem\0"
    "Arabic_hah\0"
    "Arabic_khah\0"
    "Arabic_dal\0"
    "Arabic_thal\0"
    "Arabic_ra\0"
    "Arabic_zain\0"
    "Arabic_seen\0"
    "Arabic_sheen\0"
    "Arabic_sad\0"
    "Arabic_dad\0"
    "Arabic_tah\0"
    "Arabic_zah\0"
    "Arabic_ain\0"
    "Arabic_ghain\0"
    "Arabic_tatweel\0"
    "Arabic_feh\0"
    "Arabic_qaf\0"
    "Arabic_kaf\0"
    "Arabic_lam\0"
    "Arabic_meem\0"
    "Arabic_noon\0"
    "Arabic_ha\0"
    "Arabic_heh\0"
    "Arabic_waw\0"
    "Arabic_alefmaksura\0"
    "Arabic_yeh\0"
    "Arabic_fathatan\0"
    "Arabic_dammatan\0"
    "Arabic_kasratan\0"
    "Arabic_fatha\0"
    "Arabic_damma\0"
    "Arabic_kasra\0"
    "Arabic_shadda\0"
    "Arabic_sukun\0"
    "Serbian_dje\0"
    "Macedonia_gje\0"
    "Cyrillic_io\0"
    "Ukrainian_ie\0"
    "Ukranian_je\0"
    "Macedonia_dse\0"
    "Ukrainian_i\0"
    "Ukranian_i\0"
    "Ukrainian_yi\0"
    "Ukranian_yi\0"
    "Cyrillic_je\0"
    "Serbian_je\0"
    "Cyrillic_lje\0"
    "Serbian_lje\0"
    "Cyrillic_nje\0"
    "Serbian_nje\0"
    "Serbian_tshe\0"
    "Macedonia_kje\0"
    "Byelorussian_shortu\0"
    "Cyrillic_dzhe\0"
    "Serbian_dze\0"
    "numerosign\0"
    "Serbian_DJE\0"
    "Macedonia_GJE\0"
    "Cyrillic_IO\0"
    "Ukrainian_IE\0"
    "Ukranian_JE\0"
    "Macedonia_DSE\0"
    "Ukrainian_I\0"
    "Ukranian_I\0"
    "Ukrainian_YI\0"
    "Ukranian_YI\0"
    "Cyrillic_JE\0"
    "Serbian_JE\0"
    "Cyrillic_LJE\0"
    "Serbian_LJE\0"
    "Cyrillic_NJE\0"
    "Serbian_NJE\0"
    "Serbian_TSHE\0"
    "Macedonia_KJE\0"
    "Byelorussian_SHORTU\0"
    "Cyrillic_DZHE\0"
    "Serbian_DZE\0"
    "Cyrillic_yu\0"
    "Cyrillic_a\0"
    "Cyrillic_be\0"
    "Cyrillic_tse\0"
    "Cyrillic_de\0"
    "Cyrillic_ie\0"
    "Cyrillic_ef\0"
    "Cyrillic_ghe\0"
    "Cyrillic_ha\0"
    "Cyrillic_i\0"
    "Cyrillic_shorti\0"
    "Cyrillic_ka\0"
    "Cyrillic_el\0"
    "Cyrillic_em\0"
    "Cyrillic_en\0"
    "Cyrillic_o\0"
    "Cyrillic_pe\0"
    "Cyrillic_ya\0"
    "Cyrillic_er\0"
    "Cyrillic_es\0"
    "Cyrillic_te\0"
    "Cyrillic_u\0"
    "Cyrillic_zhe\0"
    "Cyrillic_ve\0"
    "Cyrillic_softsign\0"
    "Cyrillic_yeru\0"
    "Cyrillic_ze\0"
    "Cyrillic_sha\0"
    "Cyrillic_e\0"
    "Cyrillic_shcha\0"
    "Cyrillic_che\0"
    "Cyrillic_hardsign\0"
    "Cyrillic_YU\0"
    "Cyrillic_A\0"
    "Cyrillic_BE\0"
    "Cyrillic_TSE\0"
    "Cyrillic_DE\0"
    "Cyrillic_IE\0"
    "Cyrillic_EF\0"
    "Cyrillic_GHE\0"
    "Cyrillic_HA\0"
    "Cyrillic_I\0"
    "Cyrillic_SHORTI\0"
    "Cyrillic_KA\0"
    "Cyrillic_EL\0"
    "Cyrillic_EM\0"
    "Cyrillic_EN\0"
    "Cyrillic_O\0"
    "Cyrillic_PE\0"
    "Cyrillic_YA\0"
    "Cyrillic_ER\0"
    "Cyrillic_ES\0"
    "Cyrillic_TE\0"
    "Cyrillic_U\0"
    "Cyrillic_ZHE\0"
    "Cyrillic_VE\0"
    "Cyrillic_SOFTSIGN\0"
    "Cyrillic_YERU\0"
    "Cyrillic_ZE\0"
    "Cyrillic_SHA\0"
    "Cyrillic_E\0"
    "Cyrillic_SHCHA\0"
    "Cyrillic_CHE\0"
    "Cyrillic_HARDSIGN\0"
    "Greek_ALPHAaccent\0"
    "Greek_EPSILONaccent\0"
    "Greek_ETAaccent\0"
    "Greek_IOTAaccent\0"
    "Greek_IOTAdieresis\0"
    "Greek_IOTAdiaeresis\0"
    "Greek_OMICRONaccent\0"
    "Greek_UPSILONaccent\0"
    "Greek_UPSILONdieresis\0"
    "Greek_OMEGAaccent\0"
    "Greek_accentdieresis\0"
    "Greek_horizbar\0"
    "Greek_alphaaccent\0"
    "Greek_epsilonaccent\0"
    "Greek_etaaccent\0"
    "Greek_iotaaccent\0"
    "Greek_iotadieresis\0"
    "Greek_iotaaccentdieresis\0"
    "Greek_omicronaccent\0"
    "Greek_upsilonaccent\0"
    "Greek_upsilondieresis\0"
    "Greek_upsilonaccentdieresis\0"
    "Greek_omegaaccent\0"
    "Greek_ALPHA\0"
    "Greek_BETA\0"
    "Greek_GAMMA\0"
    "Greek_DELTA\0"
    "Greek_EPSILON\0"
    "Greek_ZETA\0"
    "Greek_ETA\0"
    "Greek_THETA\0"
    "Greek_IOTA\0"
    "Greek_KAPPA\0"
    "Greek_LAMBDA\0"
    "Greek_LAMDA\0"
    "Greek_MU\0"
    "Greek_NU\0"
    "Greek_XI\0"
    "Greek_OMICRON\0"
    "Greek_PI\0"
    "Greek_RHO\0"
    "Greek_SIGMA\0"
    "Greek_TAU\0"
    "Greek_UPSILON\0"
    "Greek_PHI\0"
    "Greek_CHI\0"
    "Greek_PSI\0"
    "Greek_OMEGA\0"
    "Greek_alpha\0"
    "Greek_beta\0"
    "Greek_gamma\0"
    "Greek_delta\0"
    "Greek_epsilon\0"
    "Greek_zeta\0"
    "Greek_eta\0"
    "Greek_theta\0"
    "Greek_iota\0"
    "Greek_kappa\0"
    "Greek_lambda\0"
    "Greek_lamda\0"
    "Greek_mu\0"
    "Greek_nu\0"
    "Greek_xi\0"
    "Greek_omicron\0"
    "Greek_pi\0"
    "Greek_rho\0"
    "Greek_sigma\0"
    "Greek_finalsmallsigma\0"
    "Greek_tau\0"
    "Greek_upsilon\0"
    "Greek_phi\0"
    "Greek_chi\0"
    "Greek_psi\0"
    "Greek_omega\0"
    "leftradical\0"
    "topleftradical\0"
    "horizconnector\0"
    "topintegral\0"
    "botintegral\0"
    "vertconnector\0"
    "topleftsqbracket\0"
    "botleftsqbracket\0"
    "toprightsqbracket\0"
    "botrightsqbracket\0"
    "topleftparens\0"
    "botleftparens\0"
    "toprightparens\0"
    "botrightparens\0"
    "leftmiddlecurlybrace\0"
    "rightmiddlecurlybrace\0"
    "topleftsummation\0"
    "botleftsummation\0"
    "topvertsummationconnector\0"
    "botvertsummationconnector\0"
    "toprightsummation\0"
    "botrightsummation\0"
    "rightmiddlesummation\0"
    "lessthanequal\0"
    "notequal\0"
    "greaterthanequal\0"
    "integral\0"
    "therefore\0"
    "variation\0"
    "infinity\0"
    "nabla\0"
    "approximate\0"
    "similarequal\0"
    "ifonlyif\0"
    "implies\0"
    "identical\0"
    "radical\0"
    "includedin\0"
    "includes\0"
    "intersection\0"
    "union\0"
    "logicaland\0"
    "logicalor\0"
    "partialderivative\0"
    "function\0"
    "leftarrow\0"
    "uparrow\0"
    "rightarrow\0"
    "downarrow\0"
    "blank\0"
    "soliddiamond\0"
    "checkerboard\0"
    "ht\0"
    "ff\0"
    "cr\0"
    "lf\0"
    "nl\0"
    "vt\0"
    "lowrightcorner\0"
    "uprightcorner\0"
    "upleftcorner\0"
    "lowleftcorner\0"
    "crossinglines\0"
    "horizlinescan1\0"
    "horizlinescan3\0"
    "horizlinescan5\0"
    "horizlinescan7\0"
    "horizlinescan9\0"
    "leftt\0"
    "rightt\0"
    "bott\0"
    "topt\0"
    "vertbar\0"
    "emspace\0"
    "enspace\0"
    "em3space\0"
    "em4space\0"
    "digitspace\0"
    "punctspace\0"
    "thinspace\0"
    "hairspace\0"
    "emdash\0"
    "endash\0"
    "signifblank\0"
    "ellipsis\0"
    "doubbaselinedot\0"
    "onethird\0"
    "twothirds\0"
    "onefifth\0"
    "twofifths\0"
    "threefifths\0"
    "fourfifths\0"
    "onesixth\0"
    "fivesixths\0"
    "careof\0"
    "figdash\0"
    "leftanglebracket\0"
    "decimalpoint\0"
    "rightanglebracket\0"
    "marker\0"
    "oneeighth\0"
    "threeeighths\0"
    "fiveeighths\0"
    "seveneighths\0"
    "trademark\0"
    "signaturemark\0"
    "trademarkincircle\0"
    "leftopentriangle\0"
    "rightopentriangle\0"
    "emopencircle\0"
    "emopenrectangle\0"
    "leftsinglequotemark\0"
    "rightsinglequotemark\0"
    "leftdoublequotemark\0"
    "rightdoublequotemark\0"
    "prescription\0"
    "minutes\0"
    "seconds\0"
    "latincross\0"
    "hexagram\0"
    "filledrectbullet\0"
    "filledlefttribullet\0"
    "filledrighttribullet\0"
    "emfilledcircle\0"
    "emfilledrect\0"
    "enopencircbullet\0"
    "enopensquarebullet\0"
    "openrectbullet\0"
    "opentribulletup\0"
    "opentribulletdown\0"
    "openstar\0"
    "enfilledcircbullet\0"
    "enfilledsqbullet\0"
    "filledtribulletup\0"
    "filledtribulletdown\0"
    "leftpointer\0"
    "rightpointer\0"
    "club\0"
    "diamond\0"
    "heart\0"
    "maltesecross\0"
    "dagger\0"
    "doubledagger\0"
    "checkmark\0"
    "ballotcross\0"
    "musicalsharp\0"
    "musicalflat\0"
    "malesymbol\0"
    "femalesymbol\0"
    "telephone\0"
    "telephonerecorder\0"
    "phonographcopyright\0"
    "caret\0"
    "singlelowquotemark\0"
    "doublelowquotemark\0"
    "cursor\0"
    "leftcaret\0"
    "rightcaret\0"
    "downcaret\0"
    "upcaret\0"
    "overbar\0"
    "downtack\0"
    "upshoe\0"
    "downstile\0"
    "underbar\0"
    "jot\0"
    "quad\0"
    "uptack\0"
    "circle\0"
    "upstile\0"
    "downshoe\0"
    "rightshoe\0"
    "leftshoe\0"
    "lefttack\0"
    "righttack\0"
    "hebrew_doublelowline\0"
    "hebrew_aleph\0"
    "hebrew_bet\0"
    "hebrew_beth\0"
    "hebrew_gimel\0"
    "hebrew_gimmel\0"
    "hebrew_dalet\0"
    "hebrew_daleth\0"
    "hebrew_he\0"
    "hebrew_waw\0"
    "hebrew_zain\0"
    "hebrew_zayin\0"
    "hebrew_chet\0"
    "hebrew_het\0"
    "hebrew_tet\0"
    "hebrew_teth\0"
    "hebrew_yod\0"
    "hebrew_finalkaph\0"
    "hebrew_kaph\0"
    "hebrew_lamed\0"
    "hebrew_finalmem\0"
    "hebrew_mem\0"
    "hebrew_finalnun\0"
    "hebrew_nun\0"
    "hebrew_samech\0"
    "hebrew_samekh\0"
    "hebrew_ayin\0"
    "hebrew_finalpe\0"
    "hebrew_pe\0"
    "hebrew_finalzade\0"
    "hebrew_finalzadi\0"
    "hebrew_zade\0"
    "hebrew_zadi\0"
    "hebrew_kuf\0"
    "hebrew_qoph\0"
    "hebrew_resh\0"
    "hebrew_shin\0"
    "hebrew_taf\0"
    "hebrew_taw\0"
    "Thai_kokai\0"
    "Thai_khokhai\0"
    "Thai_khokhuat\0"
    "Thai_khokhwai\0"
    "Thai_khokhon\0"
    "Thai_khorakhang\0"
    "Thai_ngongu\0"
    "Thai_chochan\0"
    "Thai_choching\0"
    "Thai_chochang\0"
    "Thai_soso\0"
    "Thai_chochoe\0"
    "Thai_yoying\0"
    "Thai_dochada\0"
    "Thai_topatak\0"
    "Thai_thothan\0"
    "Thai_thonangmontho\0"
    "Thai_thophuthao\0"
    "Thai_nonen\0"
    "Thai_dodek\0"
    "Thai_totao\0"
    "Thai_thothung\0"
    "Thai_thothahan\0"
    "Thai_thothong\0"
    "Thai_nonu\0"
    "Thai_bobaimai\0"
    "Thai_popla\0"
    "Thai_phophung\0"
    "Thai_fofa\0"
    "Thai_phophan\0"
    "Thai_fofan\0"
    "Thai_phosamphao\0"
    "Thai_moma\0"
    "Thai_yoyak\0"
    "Thai_rorua\0"
    "Thai_ru\0"
    "Thai_loling\0"
    "Thai_lu\0"
    "Thai_wowaen\0"
    "Thai_sosala\0"
    "Thai_sorusi\0"
    "Thai_sosua\0"
    "Thai_hohip\0"
    "Thai_lochula\0"
    "Thai_oang\0"
    "Thai_honokhuk\0"
    "Thai_paiyannoi\0"
    "Thai_saraa\0"
    "Thai_maihanakat\0"
    "Thai_saraaa\0"
    "Thai_saraam\0"
    "Thai_sarai\0"
    "Thai_saraii\0"
    "Thai_saraue\0"
    "Thai_sarauee\0"
    "Thai_sarau\0"
    "Thai_sarauu\0"
    "Thai_phinthu\0"
    "Thai_maihanakat_maitho\0"
    "Thai_baht\0"
    "Thai_sarae\0"
    "Thai_saraae\0"
    "Thai_sarao\0"
    "Thai_saraaimaimuan\0"
    "Thai_saraaimaimalai\0"
    "Thai_lakkhangyao\0"
    "Thai_maiyamok\0"
    "Thai_maitaikhu\0"
    "Thai_maiek\0"
    "Thai_maitho\0"
    "Thai_maitri\0"
    "Thai_maichattawa\0"
    "Thai_thanthakhat\0"
    "Thai_nikhahit\0"
    "Thai_leksun\0"
    "Thai_leknung\0"
    "Thai_leksong\0"
    "Thai_leksam\0"
    "Thai_leksi\0"
    "Thai_lekha\0"
    "Thai_lekhok\0"
    "Thai_lekchet\0"
    "Thai_lekpaet\0"
    "Thai_lekkao\0"
    "Hangul_Kiyeog\0"
    "Hangul_SsangKiyeog\0"
    "Hangul_KiyeogSios\0"
    "Hangul_Nieun\0"
    "Hangul_NieunJieuj\0"
    "Hangul_NieunHieuh\0"
    "Hangul_Dikeud\0"
    "Hangul_SsangDikeud\0"
    "Hangul_Rieul\0"
    "Hangul_RieulKiyeog\0"
    "Hangul_RieulMieum\0"
    "Hangul_RieulPieub\0"
    "Hangul_RieulSios\0"
    "Hangul_RieulTieut\0"
    "Hangul_RieulPhieuf\0"
    "Hangul_RieulHieuh\0"
    "Hangul_Mieum\0"
    "Hangul_Pieub\0"
    "Hangul_SsangPieub\0"
    "Hangul_PieubSios\0"
    "Hangul_Sios\0"
    "Hangul_SsangSios\0"
    "Hangul_Ieung\0"
    "Hangul_Jieuj\0"
    "Hangul_SsangJieuj\0"
    "Hangul_Cieuc\0"
    "Hangul_Khieuq\0"
    "Hangul_Tieut\0"
    "Hangul_Phieuf\0"
    "Hangul_Hieuh\0"
    "Hangul_A\0"
    "Hangul_AE\0"
    "Hangul_YA\0"
    "Hangul_YAE\0"
    "Hangul_EO\0"
    "Hangul_E\0"
    "Hangul_YEO\0"
    "Hangul_YE\0"
    "Hangul_O\0"
    "Hangul_WA\0"
    "Hangul_WAE\0"
    "Hangul_OE\0"
    "Hangul_YO\0"
    "Hangul_U\0"
    "Hangul_WEO\0"
    "Hangul_WE\0"
    "Hangul_WI\0"
    "Hangul_YU\0"
    "Hangul_EU\0"
    "Hangul_YI\0"
    "Hangul_I\0"
    "Hangul_J_Kiyeog\0"
    "Hangul_J_SsangKiyeog\0"
    "Hangul_J_KiyeogSios\0"
    "Hangul_J_Nieun\0"
    "Hangul_J_NieunJieuj\0"
    "Hangul_J_NieunHieuh\0"
    "Hangul_J_Dikeud\0"
    "Hangul_J_Rieul\0"
    "Hangul_J_RieulKiyeog\0"
    "Hangul_J_RieulMieum\0"
    "Hangul_J_RieulPieub\0"
    "Hangul_J_RieulSios\0"
    "Hangul_J_RieulTieut\0"
    "Hangul_J_RieulPhieuf\0"
    "Hangul_J_RieulHieuh\0"
    "Hangul_J_Mieum\0"
    "Hangul_J_Pieub\0"
    "Hangul_J_PieubSios\0"
    "Hangul_J_Sios\0"
    "Hangul_J_SsangSios\0"
    "Hangul_J_Ieung\0"
    "Hangul_J_Jieuj\0"
    "Hangul_J_Cieuc\0"
    "Hangul_J_Khieuq\0"
    "Hangul_J_Tieut\0"
    "Hangul_J_Phieuf\0"
    "Hangul_J_Hieuh\0"
    "Hangul_RieulYeorinHieuh\0"
    "Hangul_SunkyeongeumMieum\0"
    "Hangul_SunkyeongeumPieub\0"
    "Hangul_PanSios\0"
    "Hangul_KkogjiDalrinIeung\0"
    "Hangul_SunkyeongeumPhieuf\0"
    "Hangul_YeorinHieuh\0"
    "Hangul_AraeA\0"
    "Hangul_AraeAE\0"
    "Hangul_J_PanSios\0"
    "Hangul_J_KkogjiDalrinIeung\0"
    "Hangul_J_YeorinHieuh\0"
    "Korean_Won\0"
    "OE\0"
    "oe\0"
    "Ydiaeresis\0"
    "EcuSign\0"
    "ColonSign\0"
    "CruzeiroSign\0"
    "FFrancSign\0"
    "LiraSign\0"
    "MillSign\0"
    "NairaSign\0"
    "PesetaSign\0"
    "RupeeSign\0"
    "WonSign\0"
    "NewSheqelSign\0"
    "DongSign\0"
    "EuroSign\0"
    "3270_Duplicate\0"
    "3270_FieldMark\0"
    "3270_Right2\0"
    "3270_Left2\0"
    "3270_BackTab\0"
    "3270_EraseEOF\0"
    "3270_EraseInput\0"
    "3270_Reset\0"
    "3270_Quit\0"
    "3270_PA1\0"
    "3270_PA2\0"
    "3270_PA3\0"
    "3270_Test\0"
    "3270_Attn\0"
    "3270_CursorBlink\0"
    "3270_AltCursor\0"
    "3270_KeyClick\0"
    "3270_Jump\0"
    "3270_Ident\0"
    "3270_Rule\0"
    "3270_Copy\0"
    "3270_Play\0"
    "3270_Setup\0"
    "3270_Record\0"
    "3270_ChangeScreen\0"
    "3270_DeleteWord\0"
    "3270_ExSelect\0"
    "3270_CursorSelect\0"
    "3270_PrintScreen\0"
    "3270_Enter\0"
    "ISO_Lock\0"
    "ISO_Level2_Latch\0"
    "ISO_Level3_Shift\0"
    "ISO_Level3_Latch\0"
    "ISO_Level3_Lock\0"
    "ISO_Group_Latch\0"
    "ISO_Group_Lock\0"
    "ISO_Next_Group\0"
    "ISO_Next_Group_Lock\0"
    "ISO_Prev_Group\0"
    "ISO_Prev_Group_Lock\0"
    "ISO_First_Group\0"
    "ISO_First_Group_Lock\0"
    "ISO_Last_Group\0"
    "ISO_Last_Group_Lock\0"
    "ISO_Left_Tab\0"
    "ISO_Move_Line_Up\0"
    "ISO_Move_Line_Down\0"
    "ISO_Partial_Line_Up\0"
    "ISO_Partial_Line_Down\0"
    "ISO_Partial_Space_Left\0"
    "ISO_Partial_Space_Right\0"
    "ISO_Set_Margin_Left\0"
    "ISO_Set_Margin_Right\0"
    "ISO_Release_Margin_Left\0"
    "ISO_Release_Margin_Right\0"
    "ISO_Release_Both_Margins\0"
    "ISO_Fast_Cursor_Left\0"
    "ISO_Fast_Cursor_Right\0"
    "ISO_Fast_Cursor_Up\0"
    "ISO_Fast_Cursor_Down\0"
    "ISO_Continuous_Underline\0"
    "ISO_Discontinuous_Underline\0"
    "ISO_Emphasize\0"
    "ISO_Center_Object\0"
    "ISO_Enter\0"
    "dead_grave\0"
    "dead_acute\0"
    "dead_circumflex\0"
    "dead_tilde\0"
    "dead_macron\0"
    "dead_breve\0"
    "dead_abovedot\0"
    "dead_diaeresis\0"
    "dead_abovering\0"
    "dead_doubleacute\0"
    "dead_caron\0"
    "dead_cedilla\0"
    "dead_ogonek\0"
    "dead_iota\0"
    "dead_voiced_sound\0"
    "dead_semivoiced_sound\0"
    "dead_belowdot\0"
    "dead_hook\0"
    "dead_horn\0"
    "AccessX_Enable\0"
    "AccessX_Feedback_Enable\0"
    "RepeatKeys_Enable\0"
    "SlowKeys_Enable\0"
    "BounceKeys_Enable\0"
    "StickyKeys_Enable\0"
    "MouseKeys_Enable\0"
    "MouseKeys_Accel_Enable\0"
    "Overlay1_Enable\0"
    "Overlay2_Enable\0"
    "AudibleBell_Enable\0"
    "First_Virtual_Screen\0"
    "Prev_Virtual_Screen\0"
    "Next_Virtual_Screen\0"
    "Last_Virtual_Screen\0"
    "Terminate_Server\0"
    "Pointer_Left\0"
    "Pointer_Right\0"
    "Pointer_Up\0"
    "Pointer_Down\0"
    "Pointer_UpLeft\0"
    "Pointer_UpRight\0"
    "Pointer_DownLeft\0"
    "Pointer_DownRight\0"
    "Pointer_Button_Dflt\0"
    "Pointer_Button1\0"
    "Pointer_Button2\0"
    "Pointer_Button3\0"
    "Pointer_Button4\0"
    "Pointer_Button5\0"
    "Pointer_DblClick_Dflt\0"
    "Pointer_DblClick1\0"
    "Pointer_DblClick2\0"
    "Pointer_DblClick3\0"
    "Pointer_DblClick4\0"
    "Pointer_DblClick5\0"
    "Pointer_Drag_Dflt\0"
    "Pointer_Drag1\0"
    "Pointer_Drag2\0"
    "Pointer_Drag3\0"
    "Pointer_Drag4\0"
    "Pointer_EnableKeys\0"
    "Pointer_Accelerate\0"
    "Pointer_DfltBtnNext\0"
    "Pointer_DfltBtnPrev\0"
    "Pointer_Drag5\0"
    "BackSpace\0"
    "Tab\0"
    "Linefeed\0"
    "Clear\0"
    "Return\0"
    "Pause\0"
    "Scroll_Lock\0"
    "Sys_Req\0"
    "Escape\0"
    "Multi_key\0"
    "Kanji\0"
    "Muhenkan\0"
    "Henkan\0"
    "Henkan_Mode\0"
    "Romaji\0"
    "Hiragana\0"
    "Katakana\0"
    "Hiragana_Katakana\0"
    "Zenkaku\0"
    "Hankaku\0"
    "Zenkaku_Hankaku\0"
    "Touroku\0"
    "Massyo\0"
    "Kana_Lock\0"
    "Kana_Shift\0"
    "Eisu_Shift\0"
    "Eisu_toggle\0"
    "Hangul\0"
    "Hangul_Start\0"
    "Hangul_End\0"
    "Hangul_Hanja\0"
    "Hangul_Jamo\0"
    "Hangul_Romaja\0"
    "Codeinput\0"
    "Hangul_Jeonja\0"
    "Hangul_Banja\0"
    "Hangul_PreHanja\0"
    "Hangul_PostHanja\0"
    "SingleCandidate\0"
    "MultipleCandidate\0"
    "PreviousCandidate\0"
    "Hangul_Special\0"
    "Home\0"
    "Left\0"
    "Up\0"
    "Right\0"
    "Down\0"
    "Page_Up\0"
    "Prior\0"
    "Page_Down\0"
    "Next\0"
    "End\0"
    "Begin\0"
    "Select\0"
    "Print\0"
    "Execute\0"
    "Insert\0"
    "Undo\0"
    "Redo\0"
    "Menu\0"
    "Find\0"
    "Cancel\0"
    "Help\0"
    "Break\0"
    "Arabic_switch\0"
    "Greek_switch\0"
    "Hangul_switch\0"
    "Hebrew_switch\0"
    "ISO_Group_Shift\0"
    "Mode_switch\0"
    "kana_switch\0"
    "script_switch\0"
    "Num_Lock\0"
    "KP_Space\0"
    "KP_Tab\0"
    "KP_Enter\0"
    "KP_F1\0"
    "KP_F2\0"
    "KP_F3\0"
    "KP_F4\0"
    "KP_Home\0"
    "KP_Left\0"
    "KP_Up\0"
    "KP_Right\0"
    "KP_Down\0"
    "KP_Page_Up\0"
    "KP_Prior\0"
    "KP_Page_Down\0"
    "KP_Next\0"
    "KP_End\0"
    "KP_Begin\0"
    "KP_Insert\0"
    "KP_Delete\0"
    "KP_Multiply\0"
    "KP_Add\0"
    "KP_Separator\0"
    "KP_Subtract\0"
    "KP_Decimal\0"
    "KP_Divide\0"
    "KP_0\0"
    "KP_1\0"
    "KP_2\0"
    "KP_3\0"
    "KP_4\0"
    "KP_5\0"
    "KP_6\0"
    "KP_7\0"
    "KP_8\0"
    "KP_9\0"
    "KP_Equal\0"
    "F1\0"
    "F2\0"
    "F3\0"
    "F4\0"
    "F5\0"
    "F6\0"
    "F7\0"
    "F8\0"
    "F9\0"
    "F10\0"
    "F11\0"
    "F12\0"
    "F13\0"
    "F14\0"
    "F15\0"
    "F16\0"
    "F17\0"
    "F18\0"
    "F19\0"
    "F20\0"
    "F21\0"
    "F22\0"
    "F23\0"
    "F24\0"
    "F25\0"
    "F26\0"
    "F27\0"
    "F28\0"
    "F29\0"
    "F30\0"
    "F31\0"
    "F32\0"
    "F33\0"
    "F34\0"
    "F35\0"
    "Shift_L\0"
    "Shift_R\0"
    "Control_L\0"
    "Control_R\0"
    "Caps_Lock\0"
    "Shift_Lock\0"
    "Meta_L\0"
    "Meta_R\0"
    "Alt_L\0"
    "Alt_R\0"
    "Super_L\0"
    "Super_R\0"
    "Hyper_L\0"
    "Hyper_R\0"
    "Delete\0"
    "VoidSymbol\0";

typedef struct {
  int keyval;
  int offset;
} key_entry;

static const key_entry keys_by_keyval[] = {
    {0x000020, 0},     {0x000021, 6},     {0x000022, 13},    {0x000023, 22},
    {0x000024, 33},    {0x000025, 40},    {0x000026, 48},    {0x000027, 58},
    {0x000027, 69},    {0x000028, 80},    {0x000029, 90},    {0x00002a, 101},
    {0x00002b, 110},   {0x00002c, 115},   {0x00002d, 121},   {0x00002e, 127},
    {0x00002f, 134},   {0x000030, 140},   {0x000031, 142},   {0x000032, 144},
    {0x000033, 146},   {0x000034, 148},   {0x000035, 150},   {0x000036, 152},
    {0x000037, 154},   {0x000038, 156},   {0x000039, 158},   {0x00003a, 160},
    {0x00003b, 166},   {0x00003c, 176},   {0x00003d, 181},   {0x00003e, 187},
    {0x00003f, 195},   {0x000040, 204},   {0x000041, 207},   {0x000042, 209},
    {0x000043, 211},   {0x000044, 213},   {0x000045, 215},   {0x000046, 217},
    {0x000047, 219},   {0x000048, 221},   {0x000049, 223},   {0x00004a, 225},
    {0x00004b, 227},   {0x00004c, 229},   {0x00004d, 231},   {0x00004e, 233},
    {0x00004f, 235},   {0x000050, 237},   {0x000051, 239},   {0x000052, 241},
    {0x000053, 243},   {0x000054, 245},   {0x000055, 247},   {0x000056, 249},
    {0x000057, 251},   {0x000058, 253},   {0x000059, 255},   {0x00005a, 257},
    {0x00005b, 259},   {0x00005c, 271},   {0x00005d, 281},   {0x00005e, 294},
    {0x00005f, 306},   {0x000060, 317},   {0x000060, 323},   {0x000061, 333},
    {0x000062, 335},   {0x000063, 337},   {0x000064, 339},   {0x000065, 341},
    {0x000066, 343},   {0x000067, 345},   {0x000068, 347},   {0x000069, 349},
    {0x00006a, 351},   {0x00006b, 353},   {0x00006c, 355},   {0x00006d, 357},
    {0x00006e, 359},   {0x00006f, 361},   {0x000070, 363},   {0x000071, 365},
    {0x000072, 367},   {0x000073, 369},   {0x000074, 371},   {0x000075, 373},
    {0x000076, 375},   {0x000077, 377},   {0x000078, 379},   {0x000079, 381},
    {0x00007a, 383},   {0x00007b, 385},   {0x00007c, 395},   {0x00007d, 399},
    {0x00007e, 410},   {0x0000a0, 421},   {0x0000a1, 434},   {0x0000a2, 445},
    {0x0000a3, 450},   {0x0000a4, 459},   {0x0000a5, 468},   {0x0000a6, 472},
    {0x0000a7, 482},   {0x0000a8, 490},   {0x0000a9, 500},   {0x0000aa, 510},
    {0x0000ab, 522},   {0x0000ac, 536},   {0x0000ad, 544},   {0x0000ae, 551},
    {0x0000af, 562},   {0x0000b0, 569},   {0x0000b1, 576},   {0x0000b2, 586},
    {0x0000b3, 598},   {0x0000b4, 612},   {0x0000b5, 618},   {0x0000b6, 621},
    {0x0000b7, 631},   {0x0000b8, 646},   {0x0000b9, 654},   {0x0000ba, 666},
    {0x0000bb, 676},   {0x0000bc, 691},   {0x0000bd, 702},   {0x0000be, 710},
    {0x0000bf, 724},   {0x0000c0, 737},   {0x0000c1, 744},   {0x0000c2, 751},
    {0x0000c3, 763},   {0x0000c4, 770},   {0x0000c5, 781},   {0x0000c6, 787},
    {0x0000c7, 790},   {0x0000c8, 799},   {0x0000c9, 806},   {0x0000ca, 813},
    {0x0000cb, 825},   {0x0000cc, 836},   {0x0000cd, 843},   {0x0000ce, 850},
    {0x0000cf, 862},   {0x0000d0, 873},   {0x0000d0, 877},   {0x0000d1, 881},
    {0x0000d2, 888},   {0x0000d3, 895},   {0x0000d4, 902},   {0x0000d5, 914},
    {0x0000d6, 921},   {0x0000d7, 932},   {0x0000d8, 941},   {0x0000d9, 950},
    {0x0000da, 957},   {0x0000db, 964},   {0x0000dc, 976},   {0x0000dd, 987},
    {0x0000de, 994},   {0x0000de, 1000},  {0x0000df, 1006},  {0x0000e0, 1013},
    {0x0000e1, 1020},  {0x0000e2, 1027},  {0x0000e3, 1039},  {0x0000e4, 1046},
    {0x0000e5, 1057},  {0x0000e6, 1063},  {0x0000e7, 1066},  {0x0000e8, 1075},
    {0x0000e9, 1082},  {0x0000ea, 1089},  {0x0000eb, 1101},  {0x0000ec, 1112},
    {0x0000ed, 1119},  {0x0000ee, 1126},  {0x0000ef, 1138},  {0x0000f0, 1149},
    {0x0000f1, 1153},  {0x0000f2, 1160},  {0x0000f3, 1167},  {0x0000f4, 1174},
    {0x0000f5, 1186},  {0x0000f6, 1193},  {0x0000f7, 1204},  {0x0000f8, 1213},
    {0x0000f9, 1220},  {0x0000fa, 1227},  {0x0000fb, 1234},  {0x0000fc, 1246},
    {0x0000fd, 1257},  {0x0000fe, 1264},  {0x0000ff, 1270},  {0x0001a1, 1281},
    {0x0001a2, 1289},  {0x0001a3, 1295},  {0x0001a5, 1303},  {0x0001a6, 1310},
    {0x0001a9, 1317},  {0x0001aa, 1324},  {0x0001ab, 1333},  {0x0001ac, 1340},
    {0x0001ae, 1347},  {0x0001af, 1354},  {0x0001b1, 1364},  {0x0001b2, 1372},
    {0x0001b3, 1379},  {0x0001b5, 1387},  {0x0001b6, 1394},  {0x0001b7, 1401},
    {0x0001b9, 1407},  {0x0001ba, 1414},  {0x0001bb, 1423},  {0x0001bc, 1430},
    {0x0001bd, 1437},  {0x0001be, 1449},  {0x0001bf, 1456},  {0x0001c0, 1466},
    {0x0001c3, 1473},  {0x0001c5, 1480},  {0x0001c6, 1487},  {0x0001c8, 1494},
    {0x0001ca, 1501},  {0x0001cc, 1509},  {0x0001cf, 1516},  {0x0001d0, 1523},
    {0x0001d1, 1531},  {0x0001d2, 1538},  {0x0001d5, 1545},  {0x0001d8, 1558},
    {0x0001d9, 1565},  {0x0001db, 1571},  {0x0001de, 1584},  {0x0001e0, 1593},
    {0x0001e3, 1600},  {0x0001e5, 1607},  {0x0001e6, 1614},  {0x0001e8, 1621},
    {0x0001ea, 1628},  {0x0001ec, 1636},  {0x0001ef, 1643},  {0x0001f0, 1650},
    {0x0001f1, 1658},  {0x0001f2, 1665},  {0x0001f5, 1672},  {0x0001f8, 1685},
    {0x0001f9, 1692},  {0x0001fb, 1698},  {0x0001fe, 1711},  {0x0001ff, 1720},
    {0x0002a1, 1729},  {0x0002a6, 1737},  {0x0002a9, 1749},  {0x0002ab, 1759},
    {0x0002ac, 1766},  {0x0002b1, 1778},  {0x0002b6, 1786},  {0x0002b9, 1798},
    {0x0002bb, 1807},  {0x0002bc, 1814},  {0x0002c5, 1826},  {0x0002c6, 1836},
    {0x0002d5, 1848},  {0x0002d8, 1858},  {0x0002dd, 1870},  {0x0002de, 1877},
    {0x0002e5, 1889},  {0x0002e6, 1899},  {0x0002f5, 1911},  {0x0002f8, 1921},
    {0x0002fd, 1933},  {0x0002fe, 1940},  {0x0003a2, 1952},  {0x0003a2, 1958},
    {0x0003a3, 1962},  {0x0003a5, 1971},  {0x0003a6, 1978},  {0x0003aa, 1987},
    {0x0003ab, 1995},  {0x0003ac, 2004},  {0x0003b3, 2011},  {0x0003b5, 2020},
    {0x0003b6, 2027},  {0x0003ba, 2036},  {0x0003bb, 2044},  {0x0003bc, 2053},
    {0x0003bd, 2060},  {0x0003bf, 2064},  {0x0003c0, 2068},  {0x0003c7, 2076},
    {0x0003cc, 2084},  {0x0003cf, 2094},  {0x0003d1, 2102},  {0x0003d2, 2111},
    {0x0003d3, 2119},  {0x0003d9, 2128},  {0x0003dd, 2136},  {0x0003de, 2143},
    {0x0003e0, 2151},  {0x0003e7, 2159},  {0x0003ec, 2167},  {0x0003ef, 2177},
    {0x0003f1, 2185},  {0x0003f2, 2194},  {0x0003f3, 2202},  {0x0003f9, 2211},
    {0x0003fd, 2219},  {0x0003fe, 2226},  {0x00047e, 2234},  {0x0004a1, 2243},
    {0x0004a2, 2257},  {0x0004a3, 2277},  {0x0004a4, 2297},  {0x0004a5, 2308},
    {0x0004a5, 2325},  {0x0004a6, 2340},  {0x0004a7, 2348},  {0x0004a8, 2355},
    {0x0004a9, 2362},  {0x0004aa, 2369},  {0x0004ab, 2376},  {0x0004ac, 2383},
    {0x0004ad, 2391},  {0x0004ae, 2399},  {0x0004af, 2407},  {0x0004af, 2416},
    {0x0004b0, 2424},  {0x0004b1, 2439},  {0x0004b2, 2446},  {0x0004b3, 2453},
    {0x0004b4, 2460},  {0x0004b5, 2467},  {0x0004b6, 2474},  {0x0004b7, 2482},
    {0x0004b8, 2490},  {0x0004b9, 2498},  {0x0004ba, 2506},  {0x0004bb, 2514},
    {0x0004bc, 2522},  {0x0004bd, 2531},  {0x0004be, 2539},  {0x0004bf, 2547},
    {0x0004c0, 2555},  {0x0004c1, 2563},  {0x0004c1, 2572},  {0x0004c2, 2580},
    {0x0004c2, 2589},  {0x0004c3, 2597},  {0x0004c4, 2605},  {0x0004c5, 2613},
    {0x0004c6, 2621},  {0x0004c7, 2629},  {0x0004c8, 2637},  {0x0004c9, 2645},
    {0x0004ca, 2653},  {0x0004cb, 2661},  {0x0004cc, 2669},  {0x0004cc, 2677},
    {0x0004cd, 2685},  {0x0004ce, 2693},  {0x0004cf, 2701},  {0x0004d0, 2709},
    {0x0004d1, 2717},  {0x0004d2, 2725},  {0x0004d3, 2733},  {0x0004d4, 2741},
    {0x0004d5, 2749},  {0x0004d6, 2757},  {0x0004d7, 2765},  {0x0004d8, 2773},
    {0x0004d9, 2781},  {0x0004da, 2789},  {0x0004db, 2797},  {0x0004dc, 2805},
    {0x0004dd, 2813},  {0x0004de, 2820},  {0x0004df, 2832},  {0x0005ac, 2848},
    {0x0005bb, 2861},  {0x0005bf, 2878},  {0x0005c1, 2899},  {0x0005c2, 2912},
    {0x0005c3, 2931},  {0x0005c4, 2950},  {0x0005c5, 2968},  {0x0005c6, 2990},
    {0x0005c7, 3008},  {0x0005c8, 3020},  {0x0005c9, 3031},  {0x0005ca, 3049},
    {0x0005cb, 3060},  {0x0005cc, 3072},  {0x0005cd, 3084},  {0x0005ce, 3095},
    {0x0005cf, 3107},  {0x0005d0, 3118},  {0x0005d1, 3130},  {0x0005d2, 3140},
    {0x0005d3, 3152},  {0x0005d4, 3164},  {0x0005d5, 3177},  {0x0005d6, 3188},
    {0x0005d7, 3199},  {0x0005d8, 3210},  {0x0005d9, 3221},  {0x0005da, 3232},
    {0x0005e0, 3245},  {0x0005e1, 3260},  {0x0005e2, 3271},  {0x0005e3, 3282},
    {0x0005e4, 3293},  {0x0005e5, 3304},  {0x0005e6, 3316},  {0x0005e7, 3328},
    {0x0005e7, 3338},  {0x0005e8, 3349},  {0x0005e9, 3360},  {0x0005ea, 3379},
    {0x0005eb, 3390},  {0x0005ec, 3406},  {0x0005ed, 3422},  {0x0005ee, 3438},
    {0x0005ef, 3451},  {0x0005f0, 3464},  {0x0005f1, 3477},  {0x0005f2, 3491},
    {0x0006a1, 3504},  {0x0006a2, 3516},  {0x0006a3, 3530},  {0x0006a4, 3542},
    {0x0006a4, 3555},  {0x0006a5, 3567},  {0x0006a6, 3581},  {0x0006a6, 3593},
    {0x0006a7, 3604},  {0x0006a7, 3617},  {0x0006a8, 3629},  {0x0006a8, 3641},
    {0x0006a9, 3652},  {0x0006a9, 3665},  {0x0006aa, 3677},  {0x0006aa, 3690},
    {0x0006ab, 3702},  {0x0006ac, 3715},  {0x0006ae, 3729},  {0x0006af, 3749},
    {0x0006af, 3763},  {0x0006b0, 3775},  {0x0006b1, 3786},  {0x0006b2, 3798},
    {0x0006b3, 3812},  {0x0006b4, 3824},  {0x0006b4, 3837},  {0x0006b5, 3849},
    {0x0006b6, 3863},  {0x0006b6, 3875},  {0x0006b7, 3886},  {0x0006b7, 3899},
    {0x0006b8, 3911},  {0x0006b8, 3923},  {0x0006b9, 3934},  {0x0006b9, 3947},
    {0x0006ba, 3959},  {0x0006ba, 3972},  {0x0006bb, 3984},  {0x0006bc, 3997},
    {0x0006be, 4011},  {0x0006bf, 4031},  {0x0006bf, 4045},  {0x0006c0, 4057},
    {0x0006c1, 4069},  {0x0006c2, 4080},  {0x0006c3, 4092},  {0x0006c4, 4105},
    {0x0006c5, 4117},  {0x0006c6, 4129},  {0x0006c7, 4141},  {0x0006c8, 4154},
    {0x0006c9, 4166},  {0x0006ca, 4177},  {0x0006cb, 4193},  {0x0006cc, 4205},
    {0x0006cd, 4217},  {0x0006ce, 4229},  {0x0006cf, 4241},  {0x0006d0, 4252},
    {0x0006d1, 4264},  {0x0006d2, 4276},  {0x0006d3, 4288},  {0x0006d4, 4300},
    {0x0006d5, 4312},  {0x0006d6, 4323},  {0x0006d7, 4336},  {0x0006d8, 4348},
    {0x0006d9, 4366},  {0x0006da, 4380},  {0x0006db, 4392},  {0x0006dc, 4405},
    {0x0006dd, 4416},  {0x0006de, 4431},  {0x0006df, 4444},  {0x0006e0, 4462},
    {0x0006e1, 4474},  {0x0006e2, 4485},  {0x0006e3, 4497},  {0x0006e4, 4510},
    {0x0006e5, 4522},  {0x0006e6, 4534},  {0x0006e7, 4546},  {0x0006e8, 4559},
    {0x0006e9, 4571},  {0x0006ea, 4582},  {0x0006eb, 4598},  {0x0006ec, 4610},
    {0x0006ed, 4622},  {0x0006ee, 4634},  {0x0006ef, 4646},  {0x0006f0, 4657},
    {0x0006f1, 4669},  {0x0006f2, 4681},  {0x0006f3, 4693},  {0x0006f4, 4705},
    {0x0006f5, 4717},  {0x0006f6, 4728},  {0x0006f7, 4741},  {0x0006f8, 4753},
    {0x0006f9, 4771},  {0x0006fa, 4785},  {0x0006fb, 4797},  {0x0006fc, 4810},
    {0x0006fd, 4821},  {0x0006fe, 4836},  {0x0006ff, 4849},  {0x0007a1, 4867},
    {0x0007a2, 4885},  {0x0007a3, 4905},  {0x0007a4, 4921},  {0x0007a5, 4938},
    {0x0007a5, 4957},  {0x0007a7, 4977},  {0x0007a8, 4997},  {0x0007a9, 5017},
    {0x0007ab, 5039},  {0x0007ae, 5057},  {0x0007af, 5078},  {0x0007b1, 5093},
    {0x0007b2, 5111},  {0x0007b3, 5131},  {0x0007b4, 5147},  {0x0007b5, 5164},
    {0x0007b6, 5183},  {0x0007b7, 5208},  {0x0007b8, 5228},  {0x0007b9, 5248},
    {0x0007ba, 5270},  {0x0007bb, 5298},  {0x0007c1, 5316},  {0x0007c2, 5328},
    {0x0007c3, 5339},  {0x0007c4, 5351},  {0x0007c5, 5363},  {0x0007c6, 5377},
    {0x0007c7, 5388},  {0x0007c8, 5398},  {0x0007c9, 5410},  {0x0007ca, 5421},
    {0x0007cb, 5433},  {0x0007cb, 5446},  {0x0007cc, 5458},  {0x0007cd, 5467},
    {0x0007ce, 5476},  {0x0007cf, 5485},  {0x0007d0, 5499},  {0x0007d1, 5508},
    {0x0007d2, 5518},  {0x0007d4, 5530},  {0x0007d5, 5540},  {0x0007d6, 5554},
    {0x0007d7, 5564},  {0x0007d8, 5574},  {0x0007d9, 5584},  {0x0007e1, 5596},
    {0x0007e2, 5608},  {0x0007e3, 5619},  {0x0007e4, 5631},  {0x0007e5, 5643},
    {0x0007e6, 5657},  {0x0007e7, 5668},  {0x0007e8, 5678},  {0x0007e9, 5690},
    {0x0007ea, 5701},  {0x0007eb, 5713},  {0x0007eb, 5726},  {0x0007ec, 5738},
    {0x0007ed, 5747},  {0x0007ee, 5756},  {0x0007ef, 5765},  {0x0007f0, 5779},
    {0x0007f1, 5788},  {0x0007f2, 5798},  {0x0007f3, 5810},  {0x0007f4, 5832},
    {0x0007f5, 5842},  {0x0007f6, 5856},  {0x0007f7, 5866},  {0x0007f8, 5876},
    {0x0007f9, 5886},  {0x0008a1, 5898},  {0x0008a2, 5910},  {0x0008a3, 5925},
    {0x0008a4, 5940},  {0x0008a5, 5952},  {0x0008a6, 5964},  {0x0008a7, 5978},
    {0x0008a8, 5995},  {0x0008a9, 6012},  {0x0008aa, 6030},  {0x0008ab, 6048},
    {0x0008ac, 6062},  {0x0008ad, 6076},  {0x0008ae, 6091},  {0x0008af, 6106},
    {0x0008b0, 6127},  {0x0008b1, 6149},  {0x0008b2, 6166},  {0x0008b3, 6183},
    {0x0008b4, 6209},  {0x0008b5, 6235},  {0x0008b6, 6253},  {0x0008b7, 6271},
    {0x0008bc, 6292},  {0x0008bd, 6306},  {0x0008be, 6315},  {0x0008bf, 6332},
    {0x0008c0, 6341},  {0x0008c1, 6351},  {0x0008c2, 6361},  {0x0008c5, 6370},
    {0x0008c8, 6376},  {0x0008c9, 6388},  {0x0008cd, 6401},  {0x0008ce, 6410},
    {0x0008cf, 6418},  {0x0008d6, 6428},  {0x0008da, 6436},  {0x0008db, 6447},
    {0x0008dc, 6456},  {0x0008dd, 6469},  {0x0008de, 6475},  {0x0008df, 6486},
    {0x0008ef, 6496},  {0x0008f6, 6514},  {0x0008fb, 6523},  {0x0008fc, 6533},
    {0x0008fd, 6541},  {0x0008fe, 6552},  {0x0009df, 6562},  {0x0009e0, 6568},
    {0x0009e1, 6581},  {0x0009e2, 6594},  {0x0009e3, 6597},  {0x0009e4, 6600},
    {0x0009e5, 6603},  {0x0009e8, 6606},  {0x0009e9, 6609},  {0x0009ea, 6612},
    {0x0009eb, 6627},  {0x0009ec, 6641},  {0x0009ed, 6654},  {0x0009ee, 6668},
    {0x0009ef, 6682},  {0x0009f0, 6697},  {0x0009f1, 6712},  {0x0009f2, 6727},
    {0x0009f3, 6742},  {0x0009f4, 6757},  {0x0009f5, 6763},  {0x0009f6, 6770},
    {0x0009f7, 6775},  {0x0009f8, 6780},  {0x000aa1, 6788},  {0x000aa2, 6796},
    {0x000aa3, 6804},  {0x000aa4, 6813},  {0x000aa5, 6822},  {0x000aa6, 6833},
    {0x000aa7, 6844},  {0x000aa8, 6854},  {0x000aa9, 6864},  {0x000aaa, 6871},
    {0x000aac, 6878},  {0x000aae, 6890},  {0x000aaf, 6899},  {0x000ab0, 6915},
    {0x000ab1, 6924},  {0x000ab2, 6934},  {0x000ab3, 6943},  {0x000ab4, 6953},
    {0x000ab5, 6965},  {0x000ab6, 6976},  {0x000ab7, 6985},  {0x000ab8, 6996},
    {0x000abb, 7003},  {0x000abc, 7011},  {0x000abd, 7028},  {0x000abe, 7041},
    {0x000abf, 7059},  {0x000ac3, 7066},  {0x000ac4, 7076},  {0x000ac5, 7089},
    {0x000ac6, 7101},  {0x000ac9, 7114},  {0x000aca, 7124},  {0x000acb, 7138},
    {0x000acc, 7156},  {0x000acd, 7173},  {0x000ace, 7191},  {0x000acf, 7204},
    {0x000ad0, 7220},  {0x000ad1, 7240},  {0x000ad2, 7261},  {0x000ad3, 7281},
    {0x000ad4, 7302},  {0x000ad6, 7315},  {0x000ad7, 7323},  {0x000ad9, 7331},
    {0x000ada, 7342},  {0x000adb, 7351},  {0x000adc, 7368},  {0x000add, 7388},
    {0x000ade, 7409},  {0x000adf, 7424},  {0x000ae0, 7437},  {0x000ae1, 7454},
    {0x000ae2, 7473},  {0x000ae3, 7488},  {0x000ae4, 7504},  {0x000ae5, 7522},
    {0x000ae6, 7531},  {0x000ae7, 7550},  {0x000ae8, 7567},  {0x000ae9, 7585},
    {0x000aea, 7605},  {0x000aeb, 7617},  {0x000aec, 7630},  {0x000aed, 7635},
    {0x000aee, 7643},  {0x000af0, 7649},  {0x000af1, 7662},  {0x000af2, 7669},
    {0x000af3, 7682},  {0x000af4, 7692},  {0x000af5, 7704},  {0x000af6, 7717},
    {0x000af7, 7729},  {0x000af8, 7740},  {0x000af9, 7753},  {0x000afa, 7763},
    {0x000afb, 7781},  {0x000afc, 7801},  {0x000afd, 7807},  {0x000afe, 7826},
    {0x000aff, 7845},  {0x000ba3, 7852},  {0x000ba6, 7862},  {0x000ba8, 7873},
    {0x000ba9, 7883},  {0x000bc0, 7891},  {0x000bc2, 7899},  {0x000bc3, 7908},
    {0x000bc4, 7915},  {0x000bc6, 7925},  {0x000bca, 7934},  {0x000bcc, 7938},
    {0x000bce, 7943},  {0x000bcf, 7950},  {0x000bd3, 7957},  {0x000bd6, 7965},
    {0x000bd8, 7974},  {0x000bda, 7984},  {0x000bdc, 7993},  {0x000bfc, 8002},
    {0x000cdf, 8012},  {0x000ce0, 8033},  {0x000ce1, 8046},  {0x000ce1, 8057},
    {0x000ce2, 8069},  {0x000ce2, 8082},  {0x000ce3, 8096},  {0x000ce3, 8109},
    {0x000ce4, 8123},  {0x000ce5, 8133},  {0x000ce6, 8144},  {0x000ce6, 8156},
    {0x000ce7, 8169},  {0x000ce7, 8181},  {0x000ce8, 8192},  {0x000ce8, 8203},
    {0x000ce9, 8215},  {0x000cea, 8226},  {0x000ceb, 8243},  {0x000cec, 8255},
    {0x000ced, 8268},  {0x000cee, 8284},  {0x000cef, 8295},  {0x000cf0, 8311},
    {0x000cf1, 8322},  {0x000cf1, 8336},  {0x000cf2, 8350},  {0x000cf3, 8362},
    {0x000cf4, 8377},  {0x000cf5, 8387},  {0x000cf5, 8404},  {0x000cf6, 8421},
    {0x000cf6, 8433},  {0x000cf7, 8445},  {0x000cf7, 8456},  {0x000cf8, 8468},
    {0x000cf9, 8480},  {0x000cfa, 8492},  {0x000cfa, 8503},  {0x000da1, 8514},
    {0x000da2, 8525},  {0x000da3, 8538},  {0x000da4, 8552},  {0x000da5, 8566},
    {0x000da6, 8579},  {0x000da7, 8595},  {0x000da8, 8607},  {0x000da9, 8620},
    {0x000daa, 8634},  {0x000dab, 8648},  {0x000dac, 8658},  {0x000dad, 8671},
    {0x000dae, 8683},  {0x000daf, 8696},  {0x000db0, 8709},  {0x000db1, 8722},
    {0x000db2, 8741},  {0x000db3, 8757},  {0x000db4, 8768},  {0x000db5, 8779},
    {0x000db6, 8790},  {0x000db7, 8804},  {0x000db8, 8819},  {0x000db9, 8833},
    {0x000dba, 8843},  {0x000dbb, 8857},  {0x000dbc, 8868},  {0x000dbd, 8882},
    {0x000dbe, 8892},  {0x000dbf, 8905},  {0x000dc0, 8916},  {0x000dc1, 8932},
    {0x000dc2, 8942},  {0x000dc3, 8953},  {0x000dc4, 8964},  {0x000dc5, 8972},
    {0x000dc6, 8984},  {0x000dc7, 8992},  {0x000dc8, 9004},  {0x000dc9, 9016},
    {0x000dca, 9028},  {0x000dcb, 9039},  {0x000dcc, 9050},  {0x000dcd, 9063},
    {0x000dce, 9073},  {0x000dcf, 9087},  {0x000dd0, 9102},  {0x000dd1, 9113},
    {0x000dd2, 9129},  {0x000dd3, 9141},  {0x000dd4, 9153},  {0x000dd5, 9164},
    {0x000dd6, 9176},  {0x000dd7, 9188},  {0x000dd8, 9201},  {0x000dd9, 9212},
    {0x000dda, 9224},  {0x000dde, 9237},  {0x000ddf, 9260},  {0x000de0, 9270},
    {0x000de1, 9281},  {0x000de2, 9293},  {0x000de3, 9304},  {0x000de4, 9323},
    {0x000de5, 9343},  {0x000de6, 9360},  {0x000de7, 9374},  {0x000de8, 9389},
    {0x000de9, 9400},  {0x000dea, 9412},  {0x000deb, 9424},  {0x000dec, 9441},
    {0x000ded, 9458},  {0x000df0, 9472},  {0x000df1, 9484},  {0x000df2, 9497},
    {0x000df3, 9510},  {0x000df4, 9522},  {0x000df5, 9533},  {0x000df6, 9544},
    {0x000df7, 9556},  {0x000df8, 9569},  {0x000df9, 9582},  {0x000ea1, 9594},
    {0x000ea2, 9608},  {0x000ea3, 9627},  {0x000ea4, 9645},  {0x000ea5, 9658},
    {0x000ea6, 9676},  {0x000ea7, 9694},  {0x000ea8, 9708},  {0x000ea9, 9727},
    {0x000eaa, 9740},  {0x000eab, 9759},  {0x000eac, 9777},  {0x000ead, 9795},
    {0x000eae, 9812},  {0x000eaf, 9830},  {0x000eb0, 9849},  {0x000eb1, 9867},
    {0x000eb2, 9880},  {0x000eb3, 9893},  {0x000eb4, 9911},  {0x000eb5, 9928},
    {0x000eb6, 9940},  {0x000eb7, 9957},  {0x000eb8, 9970},  {0x000eb9, 9983},
    {0x000eba, 10001}, {0x000ebb, 10014}, {0x000ebc, 10028}, {0x000ebd, 10041},
    {0x000ebe, 10055}, {0x000ebf, 10068}, {0x000ec0, 10077}, {0x000ec1, 10087},
    {0x000ec2, 10097}, {0x000ec3, 10108}, {0x000ec4, 10118}, {0x000ec5, 10127},
    {0x000ec6, 10138}, {0x000ec7, 10148}, {0x000ec8, 10157}, {0x000ec9, 10167},
    {0x000eca, 10178}, {0x000ecb, 10188}, {0x000ecc, 10198}, {0x000ecd, 10207},
    {0x000ece, 10218}, {0x000ecf, 10228}, {0x000ed0, 10238}, {0x000ed1, 10248},
    {0x000ed2, 10258}, {0x000ed3, 10268}, {0x000ed4, 10277}, {0x000ed5, 10293},
    {0x000ed6, 10314}, {0x000ed7, 10334}, {0x000ed8, 10349}, {0x000ed9, 10369},
    {0x000eda, 10389}, {0x000edb, 10405}, {0x000edc, 10420}, {0x000edd, 10441},
    {0x000ede, 10461}, {0x000edf, 10481}, {0x000ee0, 10500}, {0x000ee1, 10520},
    {0x000ee2, 10541}, {0x000ee3, 10561}, {0x000ee4, 10576}, {0x000ee5, 10591},
    {0x000ee6, 10610}, {0x000ee7, 10624}, {0x000ee8, 10643}, {0x000ee9, 10658},
    {0x000eea, 10673}, {0x000eeb, 10688}, {0x000eec, 10704}, {0x000eed, 10719},
    {0x000eee, 10735}, {0x000eef, 10750}, {0x000ef0, 10774}, {0x000ef1, 10799},
    {0x000ef2, 10824}, {0x000ef3, 10839}, {0x000ef4, 10864}, {0x000ef5, 10890},
    {0x000ef6, 10909}, {0x000ef7, 10922}, {0x000ef8, 10936}, {0x000ef9, 10953},
    {0x000efa, 10980}, {0x000eff, 11001}, {0x0013bc, 11012}, {0x0013bd, 11015},
    {0x0013be, 11018}, {0x0020a0, 11029}, {0x0020a1, 11037}, {0x0020a2, 11047},
    {0x0020a3, 11060}, {0x0020a4, 11071}, {0x0020a5, 11080}, {0x0020a6, 11089},
    {0x0020a7, 11099}, {0x0020a8, 11110}, {0x0020a9, 11120}, {0x0020aa, 11128},
    {0x0020ab, 11142}, {0x0020ac, 11151}, {0x00fd01, 11160}, {0x00fd02, 11175},
    {0x00fd03, 11190}, {0x00fd04, 11202}, {0x00fd05, 11213}, {0x00fd06, 11226},
    {0x00fd07, 11240}, {0x00fd08, 11256}, {0x00fd09, 11267}, {0x00fd0a, 11277},
    {0x00fd0b, 11286}, {0x00fd0c, 11295}, {0x00fd0d, 11304}, {0x00fd0e, 11314},
    {0x00fd0f, 11324}, {0x00fd10, 11341}, {0x00fd11, 11356}, {0x00fd12, 11370},
    {0x00fd13, 11380}, {0x00fd14, 11391}, {0x00fd15, 11401}, {0x00fd16, 11411},
    {0x00fd17, 11421}, {0x00fd18, 11432}, {0x00fd19, 11444}, {0x00fd1a, 11462},
    {0x00fd1b, 11478}, {0x00fd1c, 11492}, {0x00fd1d, 11510}, {0x00fd1e, 11527},
    {0x00fe01, 11538}, {0x00fe02, 11547}, {0x00fe03, 11564}, {0x00fe04, 11581},
    {0x00fe05, 11598}, {0x00fe06, 11614}, {0x00fe07, 11630}, {0x00fe08, 11645},
    {0x00fe09, 11660}, {0x00fe0a, 11680}, {0x00fe0b, 11695}, {0x00fe0c, 11715},
    {0x00fe0d, 11731}, {0x00fe0e, 11752}, {0x00fe0f, 11767}, {0x00fe20, 11787},
    {0x00fe21, 11800}, {0x00fe22, 11817}, {0x00fe23, 11836}, {0x00fe24, 11856},
    {0x00fe25, 11878}, {0x00fe26, 11901}, {0x00fe27, 11925}, {0x00fe28, 11945},
    {0x00fe29, 11966}, {0x00fe2a, 11990}, {0x00fe2b, 12015}, {0x00fe2c, 12040},
    {0x00fe2d, 12061}, {0x00fe2e, 12083}, {0x00fe2f, 12102}, {0x00fe30, 12123},
    {0x00fe31, 12148}, {0x00fe32, 12176}, {0x00fe33, 12190}, {0x00fe34, 12208},
    {0x00fe50, 12218}, {0x00fe51, 12229}, {0x00fe52, 12240}, {0x00fe53, 12256},
    {0x00fe54, 12267}, {0x00fe55, 12279}, {0x00fe56, 12290}, {0x00fe57, 12304},
    {0x00fe58, 12319}, {0x00fe59, 12334}, {0x00fe5a, 12351}, {0x00fe5b, 12362},
    {0x00fe5c, 12375}, {0x00fe5d, 12387}, {0x00fe5e, 12397}, {0x00fe5f, 12415},
    {0x00fe60, 12437}, {0x00fe61, 12451}, {0x00fe62, 12461}, {0x00fe70, 12471},
    {0x00fe71, 12486}, {0x00fe72, 12510}, {0x00fe73, 12528}, {0x00fe74, 12544},
    {0x00fe75, 12562}, {0x00fe76, 12580}, {0x00fe77, 12597}, {0x00fe78, 12620},
    {0x00fe79, 12636}, {0x00fe7a, 12652}, {0x00fed0, 12671}, {0x00fed1, 12692},
    {0x00fed2, 12712}, {0x00fed4, 12732}, {0x00fed5, 12752}, {0x00fee0, 12769},
    {0x00fee1, 12782}, {0x00fee2, 12796}, {0x00fee3, 12807}, {0x00fee4, 12820},
    {0x00fee5, 12835}, {0x00fee6, 12851}, {0x00fee7, 12868}, {0x00fee8, 12886},
    {0x00fee9, 12906}, {0x00feea, 12922}, {0x00feeb, 12938}, {0x00feec, 12954},
    {0x00feed, 12970}, {0x00feee, 12986}, {0x00feef, 13008}, {0x00fef0, 13026},
    {0x00fef1, 13044}, {0x00fef2, 13062}, {0x00fef3, 13080}, {0x00fef4, 13098},
    {0x00fef5, 13116}, {0x00fef6, 13130}, {0x00fef7, 13144}, {0x00fef8, 13158},
    {0x00fef9, 13172}, {0x00fefa, 13191}, {0x00fefb, 13210}, {0x00fefc, 13230},
    {0x00fefd, 13250}, {0x00ff08, 13264}, {0x00ff09, 13274}, {0x00ff0a, 13278},
    {0x00ff0b, 13287}, {0x00ff0d, 13293}, {0x00ff13, 13300}, {0x00ff14, 13306},
    {0x00ff15, 13318}, {0x00ff1b, 13326}, {0x00ff20, 13333}, {0x00ff21, 13343},
    {0x00ff22, 13349}, {0x00ff23, 13358}, {0x00ff23, 13365}, {0x00ff24, 13377},
    {0x00ff25, 13384}, {0x00ff26, 13393}, {0x00ff27, 13402}, {0x00ff28, 13420},
    {0x00ff29, 13428}, {0x00ff2a, 13436}, {0x00ff2b, 13452}, {0x00ff2c, 13460},
    {0x00ff2d, 13467}, {0x00ff2e, 13477}, {0x00ff2f, 13488}, {0x00ff30, 13499},
    {0x00ff31, 13511}, {0x00ff32, 13518}, {0x00ff33, 13531}, {0x00ff34, 13542},
    {0x00ff35, 13555}, {0x00ff36, 13567}, {0x00ff37, 13581}, {0x00ff38, 13591},
    {0x00ff39, 13605}, {0x00ff3a, 13618}, {0x00ff3b, 13634}, {0x00ff3c, 13651},
    {0x00ff3d, 13667}, {0x00ff3e, 13685}, {0x00ff3f, 13703}, {0x00ff50, 13718},
    {0x00ff51, 13723}, {0x00ff52, 13728}, {0x00ff53, 13731}, {0x00ff54, 13737},
    {0x00ff55, 13742}, {0x00ff55, 13750}, {0x00ff56, 13756}, {0x00ff56, 13766},
    {0x00ff57, 13771}, {0x00ff58, 13775}, {0x00ff60, 13781}, {0x00ff61, 13788},
    {0x00ff62, 13794}, {0x00ff63, 13802}, {0x00ff65, 13809}, {0x00ff66, 13814},
    {0x00ff67, 13819}, {0x00ff68, 13824}, {0x00ff69, 13829}, {0x00ff6a, 13836},
    {0x00ff6b, 13841}, {0x00ff7e, 13847}, {0x00ff7e, 13861}, {0x00ff7e, 13874},
    {0x00ff7e, 13888}, {0x00ff7e, 13902}, {0x00ff7e, 13918}, {0x00ff7e, 13930},
    {0x00ff7e, 13942}, {0x00ff7f, 13956}, {0x00ff80, 13965}, {0x00ff89, 13974},
    {0x00ff8d, 13981}, {0x00ff91, 13990}, {0x00ff92, 13996}, {0x00ff93, 14002},
    {0x00ff94, 14008}, {0x00ff95, 14014}, {0x00ff96, 14022}, {0x00ff97, 14030},
    {0x00ff98, 14036}, {0x00ff99, 14045}, {0x00ff9a, 14053}, {0x00ff9a, 14064},
    {0x00ff9b, 14073}, {0x00ff9b, 14086}, {0x00ff9c, 14094}, {0x00ff9d, 14101},
    {0x00ff9e, 14110}, {0x00ff9f, 14120}, {0x00ffaa, 14130}, {0x00ffab, 14142},
    {0x00ffac, 14149}, {0x00ffad, 14162}, {0x00ffae, 14174}, {0x00ffaf, 14185},
    {0x00ffb0, 14195}, {0x00ffb1, 14200}, {0x00ffb2, 14205}, {0x00ffb3, 14210},
    {0x00ffb4, 14215}, {0x00ffb5, 14220}, {0x00ffb6, 14225}, {0x00ffb7, 14230},
    {0x00ffb8, 14235}, {0x00ffb9, 14240}, {0x00ffbd, 14245}, {0x00ffbe, 14254},
    {0x00ffbf, 14257}, {0x00ffc0, 14260}, {0x00ffc1, 14263}, {0x00ffc2, 14266},
    {0x00ffc3, 14269}, {0x00ffc4, 14272}, {0x00ffc5, 14275}, {0x00ffc6, 14278},
    {0x00ffc7, 14281}, {0x00ffc8, 14285}, {0x00ffc9, 14289}, {0x00ffca, 14293},
    {0x00ffcb, 14297}, {0x00ffcc, 14301}, {0x00ffcd, 14305}, {0x00ffce, 14309},
    {0x00ffcf, 14313}, {0x00ffd0, 14317}, {0x00ffd1, 14321}, {0x00ffd2, 14325},
    {0x00ffd3, 14329}, {0x00ffd4, 14333}, {0x00ffd5, 14337}, {0x00ffd6, 14341},
    {0x00ffd7, 14345}, {0x00ffd8, 14349}, {0x00ffd9, 14353}, {0x00ffda, 14357},
    {0x00ffdb, 14361}, {0x00ffdc, 14365}, {0x00ffdd, 14369}, {0x00ffde, 14373},
    {0x00ffdf, 14377}, {0x00ffe0, 14381}, {0x00ffe1, 14385}, {0x00ffe2, 14393},
    {0x00ffe3, 14401}, {0x00ffe4, 14411}, {0x00ffe5, 14421}, {0x00ffe6, 14431},
    {0x00ffe7, 14442}, {0x00ffe8, 14449}, {0x00ffe9, 14456}, {0x00ffea, 14462},
    {0x00ffeb, 14468}, {0x00ffec, 14476}, {0x00ffed, 14484}, {0x00ffee, 14492},
    {0x00ffff, 14500}, {0xffffff, 14507}};

static const key_entry keys_by_name[] = {
    {0x000030, 140},   {0x000031, 142},   {0x000032, 144},   {0x000033, 146},
    {0x00fd10, 11341}, {0x00fd0e, 11314}, {0x00fd05, 11213}, {0x00fd19, 11444},
    {0x00fd15, 11401}, {0x00fd0f, 11324}, {0x00fd1c, 11492}, {0x00fd1a, 11462},
    {0x00fd01, 11160}, {0x00fd1e, 11527}, {0x00fd06, 11226}, {0x00fd07, 11240},
    {0x00fd1b, 11478}, {0x00fd02, 11175}, {0x00fd13, 11380}, {0x00fd12, 11370},
    {0x00fd11, 11356}, {0x00fd04, 11202}, {0x00fd0a, 11277}, {0x00fd0b, 11286},
    {0x00fd0c, 11295}, {0x00fd16, 11411}, {0x00fd1d, 11510}, {0x00fd09, 11267},
    {0x00fd18, 11432}, {0x00fd08, 11256}, {0x00fd03, 11190}, {0x00fd14, 11391},
    {0x00fd17, 11421}, {0x00fd0d, 11304}, {0x000034, 148},   {0x000035, 150},
    {0x000036, 152},   {0x000037, 154},   {0x000038, 156},   {0x000039, 158},
    {0x000041, 207},   {0x0000c6, 787},   {0x0000c1, 744},   {0x0001c3, 1473},
    {0x00fe70, 12471}, {0x00fe71, 12486}, {0x0000c2, 751},   {0x0000c4, 770},
    {0x0000c0, 737},   {0x00ffe9, 14456}, {0x00ffea, 14462}, {0x0003c0, 2068},
    {0x0001a1, 1281},  {0x0005d9, 3221},  {0x0005c7, 3008},  {0x0005e9, 3360},
    {0x0005c8, 3020},  {0x0005ac, 2848},  {0x0005d6, 3188},  {0x0005cf, 3107},
    {0x0005ef, 3451},  {0x0005ec, 3406},  {0x0005ee, 3438},  {0x0005eb, 3390},
    {0x0005e1, 3260},  {0x0005da, 3232},  {0x0005e7, 3328},  {0x0005cd, 3084},
    {0x0005c1, 2899},  {0x0005c3, 2931},  {0x0005c4, 2950},  {0x0005c6, 2990},
    {0x0005c5, 2968},  {0x0005e7, 3338},  {0x0005cc, 3072},  {0x0005e3, 3282},
    {0x0005f0, 3464},  {0x0005ed, 3422},  {0x0005ce, 3095},  {0x0005e4, 3293},
    {0x0005c2, 2912},  {0x0005e5, 3304},  {0x0005e6, 3316},  {0x0005e2, 3271},
    {0x0005bf, 2878},  {0x0005d1, 3130},  {0x0005d5, 3177},  {0x0005d3, 3152},
    {0x0005bb, 2861},  {0x0005f1, 3477},  {0x0005d4, 3164},  {0x0005f2, 3491},
    {0x00ff7e, 13847}, {0x0005d7, 3199},  {0x0005e0, 3245},  {0x0005ca, 3049},
    {0x0005c9, 3031},  {0x0005d0, 3118},  {0x0005cb, 3060},  {0x0005e8, 3349},
    {0x0005ea, 3379},  {0x0005d8, 3210},  {0x0005d2, 3140},  {0x0000c5, 781},
    {0x0000c3, 763},   {0x00fe7a, 12652}, {0x000042, 209},   {0x00ff08, 13264},
    {0x00ff58, 13775}, {0x00fe74, 12544}, {0x00ff6b, 13841}, {0x0006be, 4011},
    {0x0006ae, 3729},  {0x000043, 211},   {0x0002c5, 1826},  {0x0001c6, 1487},
    {0x00ff69, 13829}, {0x00ffe5, 14421}, {0x0001c8, 1494},  {0x0000c7, 790},
    {0x0002c6, 1836},  {0x00ff0b, 13287}, {0x00ff37, 13581}, {0x0020a1, 11037},
    {0x00ffe3, 14401}, {0x00ffe4, 14411}, {0x0020a2, 11047}, {0x0006e1, 4474},
    {0x0006e2, 4485},  {0x0006fe, 4836},  {0x0006e4, 4510},  {0x0006bf, 4031},
    {0x0006fc, 4810},  {0x0006e6, 4534},  {0x0006ec, 4610},  {0x0006ed, 4622},
    {0x0006ee, 4634},  {0x0006f2, 4681},  {0x0006f3, 4693},  {0x0006e7, 4546},
    {0x0006e8, 4559},  {0x0006ff, 4849},  {0x0006e9, 4571},  {0x0006e5, 4522},
    {0x0006b3, 3812},  {0x0006b8, 3911},  {0x0006eb, 4598},  {0x0006b9, 3934},
    {0x0006ba, 3959},  {0x0006ef, 4646},  {0x0006f0, 4657},  {0x0006fb, 4797},
    {0x0006fd, 4821},  {0x0006ea, 4582},  {0x0006f8, 4753},  {0x0006f4, 4705},
    {0x0006e3, 4497},  {0x0006f5, 4717},  {0x0006f7, 4741},  {0x0006f1, 4669},
    {0x0006f9, 4771},  {0x0006e0, 4462},  {0x0006fa, 4785},  {0x0006f6, 4728},
    {0x0006c1, 4069},  {0x0006c2, 4080},  {0x0006de, 4431},  {0x0006c4, 4105},
    {0x0006af, 3749},  {0x0006dc, 4405},  {0x0006c6, 4129},  {0x0006cc, 4205},
    {0x0006cd, 4217},  {0x0006ce, 4229},  {0x0006d2, 4276},  {0x0006d3, 4288},
    {0x0006c7, 4141},  {0x0006c8, 4154},  {0x0006df, 4444},  {0x0006c9, 4166},
    {0x0006c5, 4117},  {0x0006a3, 3530},  {0x0006a8, 3629},  {0x0006cb, 4193},
    {0x0006a9, 3652},  {0x0006aa, 3677},  {0x0006cf, 4241},  {0x0006d0, 4252},
    {0x0006db, 4392},  {0x0006dd, 4416},  {0x0006ca, 4177},  {0x0006d8, 4348},
    {0x0006d4, 4300},  {0x0006c3, 4092},  {0x0006d5, 4312},  {0x0006d7, 4336},
    {0x0006d1, 4264},  {0x0006d9, 4366},  {0x0006c0, 4057},  {0x0006da, 4380},
    {0x0006d6, 4323},  {0x000044, 213},   {0x0001cf, 1516},  {0x00ffff, 14500},
    {0x0020ab, 11142}, {0x00ff54, 13737}, {0x0001d0, 1523},  {0x000045, 215},
    {0x0003bd, 2060},  {0x0000d0, 873},   {0x0003cc, 2084},  {0x0000c9, 806},
    {0x0001cc, 1509},  {0x0000ca, 813},   {0x0020a0, 11029}, {0x0000cb, 825},
    {0x0000c8, 799},   {0x00ff2f, 13488}, {0x00ff30, 13499}, {0x0003aa, 1987},
    {0x00ff57, 13771}, {0x0001ca, 1501},  {0x00ff1b, 13326}, {0x0000d0, 877},
    {0x0020ac, 11151}, {0x00ff62, 13794}, {0x000046, 217},   {0x00ffbe, 14254},
    {0x00ffc7, 14281}, {0x00ffc8, 14285}, {0x00ffc9, 14289}, {0x00ffca, 14293},
    {0x00ffcb, 14297}, {0x00ffcc, 14301}, {0x00ffcd, 14305}, {0x00ffce, 14309},
    {0x00ffcf, 14313}, {0x00ffd0, 14317}, {0x00ffbf, 14257}, {0x00ffd1, 14321},
    {0x00ffd2, 14325}, {0x00ffd3, 14329}, {0x00ffd4, 14333}, {0x00ffd5, 14337},
    {0x00ffd6, 14341}, {0x00ffd7, 14345}, {0x00ffd8, 14349}, {0x00ffd9, 14353},
    {0x00ffda, 14357}, {0x00ffc0, 14260}, {0x00ffdb, 14361}, {0x00ffdc, 14365},
    {0x00ffdd, 14369}, {0x00ffde, 14373}, {0x00ffdf, 14377}, {0x00ffe0, 14381},
    {0x00ffc1, 14263}, {0x00ffc2, 14266}, {0x00ffc3, 14269}, {0x00ffc4, 14272},
    {0x00ffc5, 14275}, {0x00ffc6, 14278}, {0x0020a3, 11060}, {0x00ff68, 13824},
    {0x00fed0, 12671}, {0x000047, 219},   {0x0002d5, 1848},  {0x0002ab, 1759},
    {0x0003ab, 1995},  {0x0002d8, 1858},  {0x0007c1, 5316},  {0x0007a1, 4867},
    {0x0007c2, 5328},  {0x0007d7, 5564},  {0x0007c4, 5351},  {0x0007c5, 5363},
    {0x0007a2, 4885},  {0x0007c7, 5388},  {0x0007a3, 4905},  {0x0007c3, 5339},
    {0x0007c9, 5410},  {0x0007a4, 4921},  {0x0007a5, 4957},  {0x0007a5, 4938},
    {0x0007ca, 5421},  {0x0007cb, 5433},  {0x0007cb, 5446},  {0x0007cc, 5458},
    {0x0007cd, 5467},  {0x0007d9, 5584},  {0x0007ab, 5039},  {0x0007cf, 5485},
    {0x0007a7, 4977},  {0x0007d6, 5554},  {0x0007d0, 5499},  {0x0007d8, 5574},
    {0x0007d1, 5508},  {0x0007d2, 5518},  {0x0007d4, 5530},  {0x0007c8, 5398},
    {0x0007d5, 5540},  {0x0007a8, 4997},  {0x0007a9, 5017},  {0x0007ce, 5476},
    {0x0007c6, 5377},  {0x0007ae, 5057},  {0x0007e1, 5596},  {0x0007b1, 5093},
    {0x0007e2, 5608},  {0x0007f7, 5866},  {0x0007e4, 5631},  {0x0007e5, 5643},
    {0x0007b2, 5111},  {0x0007e7, 5668},  {0x0007b3, 5131},  {0x0007f3, 5810},
    {0x0007e3, 5619},  {0x0007af, 5078},  {0x0007e9, 5690},  {0x0007b4, 5147},
    {0x0007b6, 5183},  {0x0007b5, 5164},  {0x0007ea, 5701},  {0x0007eb, 5713},
    {0x0007eb, 5726},  {0x0007ec, 5738},  {0x0007ed, 5747},  {0x0007f9, 5886},
    {0x0007bb, 5298},  {0x0007ef, 5765},  {0x0007b7, 5208},  {0x0007f6, 5856},
    {0x0007f0, 5779},  {0x0007f8, 5876},  {0x0007f1, 5788},  {0x0007f2, 5798},
    {0x00ff7e, 13861}, {0x0007f4, 5832},  {0x0007e8, 5678},  {0x0007f5, 5842},
    {0x0007b8, 5228},  {0x0007ba, 5270},  {0x0007b9, 5248},  {0x0007ee, 5756},
    {0x0007e6, 5657},  {0x000048, 221},   {0x00ff31, 13511}, {0x000ebf, 10068},
    {0x000ec0, 10077}, {0x000ef6, 10909}, {0x000ef7, 10922}, {0x00ff39, 13605},
    {0x000eba, 10001}, {0x000ea7, 9694},  {0x000ec4, 10118}, {0x000ec3, 10108},
    {0x000ed1, 10248}, {0x00ff33, 13531}, {0x00ff34, 13542}, {0x000ebe, 10055},
    {0x000ed3, 10268}, {0x000eb7, 9957},  {0x000eea, 10673}, {0x000eda, 10389},
    {0x000eee, 10735}, {0x000ee8, 10643}, {0x000ee9, 10658}, {0x000eeb, 10688},
    {0x000ed4, 10277}, {0x000ed6, 10314}, {0x000ef9, 10953}, {0x000ee3, 10561},
    {0x000ed7, 10334}, {0x000ed9, 10369}, {0x000ed8, 10349}, {0x000ef8, 10936},
    {0x000eed, 10719}, {0x000ee4, 10576}, {0x000ee5, 10591}, {0x000edb, 10405},
    {0x000ee2, 10541}, {0x000edc, 10420}, {0x000edd, 10441}, {0x000ee1, 10520},
    {0x000ede, 10461}, {0x000edf, 10481}, {0x000ee0, 10500}, {0x000ee6, 10610},
    {0x000ed5, 10293}, {0x000ee7, 10624}, {0x000eec, 10704}, {0x000efa, 10980},
    {0x00ff35, 13555}, {0x00ff38, 13591}, {0x000eb8, 9970},  {0x000ebb, 10014},
    {0x000ea1, 9594},  {0x000ea3, 9627},  {0x000ef3, 10839}, {0x000eb1, 9867},
    {0x000ea4, 9645},  {0x000ea6, 9676},  {0x000ea5, 9658},  {0x000ec7, 10148},
    {0x000eca, 10178}, {0x000ef2, 10824}, {0x000ebd, 10041}, {0x000eb2, 9880},
    {0x000eb4, 9911},  {0x00ff3b, 13634}, {0x00ff3a, 13618}, {0x000ea9, 9727},
    {0x000eb0, 9849},  {0x000eaa, 9740},  {0x000eab, 9759},  {0x000eaf, 9830},
    {0x000eac, 9777},  {0x000ead, 9795},  {0x000eae, 9812},  {0x000eef, 10750},
    {0x00ff36, 13567}, {0x000eb5, 9928},  {0x00ff3f, 13703}, {0x000ea8, 9708},
    {0x000eb9, 9983},  {0x000ea2, 9608},  {0x000eb3, 9893},  {0x000eb6, 9940},
    {0x00ff32, 13518}, {0x000ef0, 10774}, {0x000ef4, 10864}, {0x000ef1, 10799},
    {0x000ebc, 10028}, {0x000ecc, 10198}, {0x000ec8, 10157}, {0x000ec9, 10167},
    {0x000ece, 10218}, {0x000ecd, 10207}, {0x000ecf, 10228}, {0x000ec1, 10087},
    {0x000ec2, 10097}, {0x000ec6, 10138}, {0x000ec5, 10127}, {0x000ed2, 10258},
    {0x000ecb, 10188}, {0x000ed0, 10238}, {0x000ef5, 10890}, {0x00ff7e, 13874},
    {0x00ff29, 13428}, {0x0002a6, 1737},  {0x00ff7e, 13888}, {0x00ff6a, 13836},
    {0x00ff23, 13358}, {0x00ff23, 13365}, {0x00ff25, 13384}, {0x00ff27, 13402},
    {0x00ff50, 13718}, {0x0002a1, 1729},  {0x00ffed, 14484}, {0x00ffee, 14492},
    {0x000049, 223},   {0x00fe33, 12190}, {0x00fe30, 12123}, {0x00fe31, 12148},
    {0x00fe32, 12176}, {0x00fe34, 12208}, {0x00fe2f, 12102}, {0x00fe2c, 12040},
    {0x00fe2d, 12061}, {0x00fe2e, 12083}, {0x00fe0c, 11715}, {0x00fe0d, 11731},
    {0x00fe06, 11614}, {0x00fe07, 11630}, {0x00ff7e, 13902}, {0x00fe0e, 11752},
    {0x00fe0f, 11767}, {0x00fe20, 11787}, {0x00fe02, 11547}, {0x00fe04, 11581},
    {0x00fe05, 11598}, {0x00fe03, 11564}, {0x00fe01, 11538}, {0x00fe22, 11817},
    {0x00fe21, 11800}, {0x00fe08, 11645}, {0x00fe09, 11660}, {0x00fe24, 11856},
    {0x00fe23, 11836}, {0x00fe25, 11878}, {0x00fe26, 11901}, {0x00fe0a, 11680},
    {0x00fe0b, 11695}, {0x00fe2b, 12015}, {0x00fe29, 11966}, {0x00fe2a, 11990},
    {0x00fe27, 11925}, {0x00fe28, 11945}, {0x0002a9, 1749},  {0x0000cd, 843},
    {0x0000ce, 850},   {0x0000cf, 862},   {0x0000cc, 836},   {0x0003cf, 2094},
    {0x00ff63, 13802}, {0x0003c7, 2076},  {0x0003a5, 1971},  {0x00004a, 225},
    {0x0002ac, 1766},  {0x00004b, 227},   {0x00ffb0, 14195}, {0x00ffb1, 14200},
    {0x00ffb2, 14205}, {0x00ffb3, 14210}, {0x00ffb4, 14215}, {0x00ffb5, 14220},
    {0x00ffb6, 14225}, {0x00ffb7, 14230}, {0x00ffb8, 14235}, {0x00ffb9, 14240},
    {0x00ffab, 14142}, {0x00ff9d, 14101}, {0x00ffae, 14174}, {0x00ff9f, 14120},
    {0x00ffaf, 14185}, {0x00ff99, 14045}, {0x00ff9c, 14094}, {0x00ff8d, 13981},
    {0x00ffbd, 14245}, {0x00ff91, 13990}, {0x00ff92, 13996}, {0x00ff93, 14002},
    {0x00ff94, 14008}, {0x00ff95, 14014}, {0x00ff9e, 14110}, {0x00ff96, 14022},
    {0x00ffaa, 14130}, {0x00ff9b, 14086}, {0x00ff9b, 14073}, {0x00ff9a, 14053},
    {0x00ff9a, 14064}, {0x00ff98, 14036}, {0x00ffac, 14149}, {0x00ff80, 13965},
    {0x00ffad, 14162}, {0x00ff89, 13974}, {0x00ff97, 14030}, {0x00ff2d, 13467},
    {0x00ff2e, 13477}, {0x00ff21, 13343}, {0x00ff26, 13393}, {0x0003d3, 2119},
    {0x000eff, 11001}, {0x00004c, 229},   {0x0001c5, 1480},  {0x00fed4, 12732},
    {0x0001a5, 1303},  {0x0003a6, 1978},  {0x00ff51, 13723}, {0x00ff0a, 13278},
    {0x0020a4, 11071}, {0x0001a3, 1295},  {0x00004d, 231},   {0x0006b5, 3849},
    {0x0006b2, 3798},  {0x0006bc, 3997},  {0x0006a5, 3567},  {0x0006a2, 3516},
    {0x0006ac, 3715},  {0x00ff2c, 13460}, {0x00ff67, 13819}, {0x00ffe7, 14442},
    {0x00ffe8, 14449}, {0x0020a5, 11080}, {0x00ff7e, 13918}, {0x00fe77, 12597},
    {0x00fe76, 12580}, {0x00ff22, 13349}, {0x00ff20, 13333}, {0x00ff3d, 13667},
    {0x00004e, 233},   {0x0001d1, 1531},  {0x0020a6, 11089}, {0x0001d2, 1538},
    {0x0003d1, 2102},  {0x0020aa, 11128}, {0x00ff56, 13766}, {0x00fed2, 12712},
    {0x0000d1, 881},   {0x00ff7f, 13956}, {0x00004f, 235},   {0x0013bc, 11012},
    {0x0000d3, 895},   {0x0000d4, 902},   {0x0000d6, 921},   {0x0001d5, 1545},
    {0x0000d2, 888},   {0x0003d2, 2111},  {0x0000d8, 941},   {0x0000d5, 914},
    {0x00fe78, 12620}, {0x00fe79, 12636}, {0x000050, 237},   {0x00ff56, 13756},
    {0x00ff55, 13742}, {0x00ff13, 13300}, {0x0020a7, 11099}, {0x00fefa, 13191},
    {0x00fee9, 12906}, {0x00feea, 12922}, {0x00feeb, 12938}, {0x00feec, 12954},
    {0x00feed, 12970}, {0x00fee8, 12886}, {0x00feef, 13008}, {0x00fef0, 13026},
    {0x00fef1, 13044}, {0x00fef2, 13062}, {0x00fef3, 13080}, {0x00feee, 12986},
    {0x00fefb, 13210}, {0x00fefc, 13230}, {0x00fee3, 12807}, {0x00fee6, 12851},
    {0x00fee7, 12868}, {0x00fef5, 13116}, {0x00fef6, 13130}, {0x00fef7, 13144},
    {0x00fef8, 13158}, {0x00fefd, 13250}, {0x00fef4, 13098}, {0x00fef9, 13172},
    {0x00fee0, 12769}, {0x00fee1, 12782}, {0x00fee2, 12796}, {0x00fee4, 12820},
    {0x00fee5, 12835}, {0x00fed1, 12692}, {0x00ff3e, 13685}, {0x00ff61, 13788},
    {0x00ff55, 13750}, {0x000051, 239},   {0x000052, 241},   {0x0001c0, 1466},
    {0x0001d8, 1558},  {0x0003a3, 1962},  {0x00ff66, 13814}, {0x00fe72, 12510},
    {0x00ff0d, 13293}, {0x00ff53, 13731}, {0x00ff24, 13377}, {0x0020a8, 11110},
    {0x000053, 243},   {0x0001a6, 1310},  {0x0001a9, 1317},  {0x0001aa, 1324},
    {0x0002de, 1877},  {0x00ff14, 13306}, {0x00ff60, 13781}, {0x0006b1, 3786},
    {0x0006bf, 4045},  {0x0006b8, 3923},  {0x0006b9, 3947},  {0x0006ba, 3972},
    {0x0006bb, 3984},  {0x0006a1, 3504},  {0x0006af, 3763},  {0x0006a8, 3641},
    {0x0006a9, 3665},  {0x0006aa, 3690},  {0x0006ab, 3702},  {0x00ffe1, 14385},
    {0x00ffe6, 14431}, {0x00ffe2, 14393}, {0x00ff3c, 13651}, {0x00fe73, 12528},
    {0x00fe75, 12562}, {0x00ffeb, 14468}, {0x00ffec, 14476}, {0x00ff15, 13318},
    {0x000054, 245},   {0x0000de, 994},   {0x00ff09, 13274}, {0x0001ab, 1333},
    {0x0001de, 1584},  {0x00fed5, 12752}, {0x000ddf, 9260},  {0x000dba, 8843},
    {0x000da8, 8607},  {0x000daa, 8634},  {0x000da9, 8620},  {0x000dac, 8658},
    {0x000dae, 8683},  {0x000db4, 8768},  {0x000dbd, 8882},  {0x000dbf, 8905},
    {0x000dcb, 9039},  {0x000dce, 9073},  {0x000da2, 8525},  {0x000da5, 8566},
    {0x000da3, 8538},  {0x000da4, 8552},  {0x000da6, 8579},  {0x000da1, 8514},
    {0x000de5, 9343},  {0x000df7, 9556},  {0x000df5, 9533},  {0x000df6, 9544},
    {0x000df9, 9582},  {0x000df1, 9484},  {0x000df8, 9569},  {0x000df3, 9510},
    {0x000df4, 9522},  {0x000df2, 9497},  {0x000df0, 9472},  {0x000dcc, 9050},
    {0x000dc5, 8972},  {0x000dc6, 8984},  {0x000deb, 9424},  {0x000de8, 9389},
    {0x000dd1, 9113},  {0x000dde, 9237},  {0x000de7, 9374},  {0x000de9, 9400},
    {0x000dea, 9412},  {0x000de6, 9360},  {0x000dc1, 8932},  {0x000da7, 8595},
    {0x000ded, 9458},  {0x000db3, 8757},  {0x000db9, 8833},  {0x000dcd, 9063},
    {0x000dcf, 9087},  {0x000dda, 9224},  {0x000dbe, 8892},  {0x000dbc, 8868},
    {0x000dc0, 8916},  {0x000dbb, 8857},  {0x000dc3, 8953},  {0x000dc4, 8964},
    {0x000dd0, 9102},  {0x000dd2, 9129},  {0x000de1, 9281},  {0x000de4, 9323},
    {0x000de3, 9304},  {0x000dd3, 9141},  {0x000de0, 9270},  {0x000dd4, 9153},
    {0x000dd5, 9164},  {0x000de2, 9293},  {0x000dd8, 9201},  {0x000dd6, 9176},
    {0x000dd7, 9188},  {0x000dd9, 9212},  {0x000dc9, 9016},  {0x000dc8, 9004},
    {0x000dab, 8648},  {0x000dca, 9028},  {0x000dec, 9441},  {0x000db1, 8722},
    {0x000db2, 8741},  {0x000db7, 8804},  {0x000db0, 8709},  {0x000db8, 8819},
    {0x000db6, 8790},  {0x000daf, 8696},  {0x000db5, 8779},  {0x000dc7, 8992},
    {0x000dc2, 8942},  {0x000dad, 8671},  {0x0000de, 1000},  {0x00ff2b, 13452},
    {0x0003ac, 2004},  {0x000055, 247},   {0x0000da, 957},   {0x0002dd, 1870},
    {0x0000db, 964},   {0x0000dc, 976},   {0x0001db, 1571},  {0x0000d9, 950},
    {0x0006b6, 3863},  {0x0006b4, 3824},  {0x0006b7, 3886},  {0x0006a6, 3581},
    {0x0006a4, 3542},  {0x0006a7, 3604},  {0x0006b6, 3875},  {0x0006b4, 3837},
    {0x0006b7, 3899},  {0x0006a6, 3593},  {0x0006a4, 3555},  {0x0006a7, 3617},
    {0x0003de, 2143},  {0x00ff65, 13809}, {0x0003d9, 2128},  {0x00ff52, 13728},
    {0x0001d9, 1565},  {0x0003dd, 2136},  {0x000056, 249},   {0xffffff, 14507},
    {0x000057, 251},   {0x0020a9, 11120}, {0x000058, 253},   {0x000059, 255},
    {0x0000dd, 987},   {0x0013be, 11018}, {0x00005a, 257},   {0x0001af, 1354},
    {0x0001ac, 1340},  {0x0001ae, 1347},  {0x00ff28, 13420}, {0x00ff2a, 13436},
    {0x000061, 333},   {0x0000e1, 1020},  {0x0001ff, 1720},  {0x0001e3, 1600},
    {0x0000e2, 1027},  {0x0000b4, 612},   {0x0000e4, 1046},  {0x0000e6, 1063},
    {0x0000e0, 1013},  {0x0003e0, 2151},  {0x000026, 48},    {0x0001b1, 1364},
    {0x000027, 58},    {0x0008c8, 6376},  {0x0000e5, 1057},  {0x00005e, 294},
    {0x00007e, 410},   {0x00002a, 101},   {0x000040, 204},   {0x0000e3, 1039},
    {0x000062, 335},   {0x00005c, 271},   {0x000af4, 7692},  {0x00007c, 395},
    {0x0009df, 6562},  {0x0008a5, 5952},  {0x0008ac, 6062},  {0x0008a8, 5995},
    {0x0008b2, 6166},  {0x0008ae, 6091},  {0x0008aa, 6030},  {0x0008b6, 6253},
    {0x0009f6, 6770},  {0x0008b4, 6209},  {0x00007b, 385},   {0x00007d, 399},
    {0x00005b, 259},   {0x00005d, 281},   {0x0001a2, 1289},  {0x0000a6, 472},
    {0x000063, 337},   {0x0002e5, 1889},  {0x0001e6, 1614},  {0x000ab8, 6996},
    {0x000afc, 7801},  {0x0001b7, 1401},  {0x0001e8, 1621},  {0x0000e7, 1066},
    {0x0002e6, 1899},  {0x0000b8, 646},   {0x0000a2, 445},   {0x0009e1, 6581},
    {0x000af3, 7682},  {0x000bcf, 7950},  {0x000aec, 7630},  {0x00003a, 160},
    {0x00002c, 115},   {0x0000a9, 500},   {0x0009e4, 6600},  {0x0009ee, 6668},
    {0x0000a4, 459},   {0x000aff, 7845},  {0x000064, 339},   {0x000af1, 7662},
    {0x0001ef, 1643},  {0x00fe56, 12290}, {0x00fe58, 12319}, {0x00fe51, 12229},
    {0x00fe60, 12437}, {0x00fe55, 12279}, {0x00fe5a, 12351}, {0x00fe5b, 12362},
    {0x00fe52, 12240}, {0x00fe57, 12304}, {0x00fe59, 12334}, {0x00fe50, 12218},
    {0x00fe61, 12451}, {0x00fe62, 12461}, {0x00fe5d, 12387}, {0x00fe54, 12267},
    {0x00fe5c, 12375}, {0x00fe5f, 12415}, {0x00fe53, 12256}, {0x00fe5e, 12397},
    {0x000abd, 7028},  {0x0000b0, 569},   {0x0000a8, 490},   {0x000aed, 7635},
    {0x000aa5, 6822},  {0x0000f7, 1204},  {0x000024, 33},    {0x000aaf, 6899},
    {0x0001bd, 1437},  {0x000af2, 7669},  {0x000afe, 7826},  {0x0008fe, 6552},
    {0x000ba8, 7873},  {0x000bd6, 7965},  {0x000bc4, 7915},  {0x000bc2, 7899},
    {0x0001f0, 1650},  {0x000065, 341},   {0x0003ec, 2167},  {0x0000e9, 1082},
    {0x0001ec, 1636},  {0x0000ea, 1089},  {0x0000eb, 1101},  {0x0000e8, 1075},
    {0x000aae, 6890},  {0x000aa3, 6804},  {0x000aa4, 6813},  {0x0003ba, 2036},
    {0x000aa9, 6864},  {0x000ade, 7409},  {0x000adf, 7424},  {0x000ace, 7191},
    {0x000acf, 7204},  {0x000aa1, 6788},  {0x000aaa, 6871},  {0x000ae6, 7531},
    {0x000ae7, 7550},  {0x0003bf, 2064},  {0x000ae0, 7437},  {0x000ae1, 7454},
    {0x000aa2, 6796},  {0x0001ea, 1628},  {0x00003d, 181},   {0x0000f0, 1149},
    {0x000021, 6},     {0x0000a1, 434},   {0x000066, 343},   {0x000af8, 7740},
    {0x0009e3, 6597},  {0x000abb, 7003},  {0x000adc, 7368},  {0x000adb, 7351},
    {0x000add, 7388},  {0x000ae9, 7585},  {0x000ae8, 7567},  {0x000ac5, 7089},
    {0x000ab7, 6985},  {0x000ab5, 6965},  {0x0008f6, 6514},  {0x000067, 345},
    {0x0002f5, 1911},  {0x0002bb, 1807},  {0x0003bb, 2044},  {0x0002f8, 1921},
    {0x000060, 317},   {0x00003e, 187},   {0x0008be, 6315},  {0x0000ab, 522},
    {0x0000bb, 676},   {0x000068, 347},   {0x000aa8, 6854},  {0x0002b6, 1786},
    {0x000aee, 7643},  {0x000ce0, 8033},  {0x000cf2, 8350},  {0x000ce1, 8046},
    {0x000ce1, 8057},  {0x000ce7, 8169},  {0x000ce3, 8096},  {0x000ce3, 8109},
    {0x000cdf, 8012},  {0x000cea, 8226},  {0x000ced, 8268},  {0x000cef, 8295},
    {0x000cf3, 8362},  {0x000cf5, 8387},  {0x000cf5, 8404},  {0x000ce2, 8069},
    {0x000ce2, 8082},  {0x000ce4, 8123},  {0x000ce7, 8181},  {0x000ceb, 8243},
    {0x000cf7, 8445},  {0x000cec, 8255},  {0x000cee, 8284},  {0x000cf0, 8311},
    {0x000cf4, 8377},  {0x000cf7, 8456},  {0x000cf8, 8468},  {0x000cf1, 8322},
    {0x000cf1, 8336},  {0x000cf9, 8480},  {0x000cfa, 8492},  {0x000cfa, 8503},
    {0x000ce8, 8192},  {0x000ce8, 8203},  {0x000ce5, 8133},  {0x000ce9, 8215},
    {0x000cf6, 8421},  {0x000cf6, 8433},  {0x000ce6, 8144},  {0x000ce6, 8156},
    {0x000ada, 7342},  {0x0008a3, 5925},  {0x0009ef, 6682},  {0x0009f0, 6697},
    {0x0009f1, 6712},  {0x0009f2, 6727},  {0x0009f3, 6742},  {0x0002b1, 1778},
    {0x0009e2, 6594},  {0x0000ad, 544},   {0x000069, 349},   {0x0000ed, 1119},
    {0x0000ee, 1126},  {0x0008cf, 6418},  {0x0000ef, 1138},  {0x0002b9, 1798},
    {0x0008cd, 6401},  {0x0000ec, 1112},  {0x0003ef, 2177},  {0x0008ce, 6410},
    {0x0008da, 6436},  {0x0008db, 6447},  {0x0008c2, 6361},  {0x0008bf, 6332},
    {0x0008dc, 6456},  {0x0003e7, 2159},  {0x0003b5, 2020},  {0x00006a, 351},
    {0x0002bc, 1814},  {0x000bca, 7934},  {0x00006b, 353},   {0x0004b1, 2439},
    {0x0004c1, 2563},  {0x0004b4, 2460},  {0x0004cc, 2669},  {0x0004ca, 2653},
    {0x0004cd, 2685},  {0x0004cb, 2661},  {0x0004ce, 2693},  {0x0004cc, 2677},
    {0x0004b2, 2446},  {0x0004b6, 2474},  {0x0004b9, 2498},  {0x0004b7, 2482},
    {0x0004ba, 2506},  {0x0004b8, 2490},  {0x0004cf, 2701},  {0x0004d2, 2725},
    {0x0004d0, 2709},  {0x0004d3, 2733},  {0x0004d1, 2717},  {0x0004dd, 2813},
    {0x0004c5, 2613},  {0x0004c8, 2637},  {0x0004c6, 2621},  {0x0004c9, 2645},
    {0x0004c7, 2629},  {0x0004b5, 2467},  {0x0004d7, 2765},  {0x0004da, 2789},
    {0x0004d8, 2773},  {0x0004db, 2797},  {0x0004d9, 2781},  {0x0004bb, 2514},
    {0x0004be, 2539},  {0x0004bc, 2522},  {0x0004bf, 2547},  {0x0004bd, 2531},
    {0x0004c0, 2555},  {0x0004c3, 2597},  {0x0004c1, 2572},  {0x0004c4, 2605},
    {0x0004c2, 2580},  {0x0004c2, 2589},  {0x0004b3, 2453},  {0x0004dc, 2805},
    {0x0004a6, 2340},  {0x0004d4, 2741},  {0x0004d6, 2757},  {0x0004d5, 2749},
    {0x0004a7, 2348},  {0x0004a3, 2277},  {0x0004a4, 2297},  {0x0004a5, 2308},
    {0x0004aa, 2369},  {0x0004a1, 2243},  {0x0004a8, 2355},  {0x0004a5, 2325},
    {0x0004ab, 2376},  {0x0004a2, 2257},  {0x00ff7e, 13930}, {0x0004af, 2407},
    {0x0004af, 2416},  {0x0004a9, 2362},  {0x0004ac, 2383},  {0x0004ae, 2399},
    {0x0004ad, 2391},  {0x0003a2, 1952},  {0x0003f3, 2202},  {0x0003a2, 1958},
    {0x00006c, 355},   {0x0001e5, 1607},  {0x000ad9, 7331},  {0x0001b5, 1387},
    {0x0003b6, 2027},  {0x000abc, 7011},  {0x0008fb, 6523},  {0x000ba3, 7852},
    {0x000ad2, 7261},  {0x0008af, 6106},  {0x000acc, 7156},  {0x000aea, 7605},
    {0x0008a1, 5898},  {0x000bda, 7984},  {0x000ad0, 7220},  {0x0009f4, 6757},
    {0x000bdc, 7993},  {0x00003c, 176},   {0x0008bc, 6292},  {0x0009e5, 6603},
    {0x0008de, 6475},  {0x0008df, 6486},  {0x0009ed, 6654},  {0x0009ea, 6612},
    {0x0001b3, 1379},  {0x00006d, 357},   {0x0000af, 562},   {0x000af7, 7729},
    {0x000af0, 7649},  {0x000abf, 7059},  {0x0000ba, 666},   {0x00002d, 121},
    {0x000ad6, 7315},  {0x0000b5, 618},   {0x0000d7, 932},   {0x000af6, 7717},
    {0x000af5, 7704},  {0x00006e, 359},   {0x0008c5, 6370},  {0x0001f1, 1658},
    {0x0001f2, 1665},  {0x0003f1, 2185},  {0x0009e8, 6606},  {0x0000a0, 421},
    {0x0008bd, 6306},  {0x0000ac, 536},   {0x0000f1, 1153},  {0x000023, 22},
    {0x0006b0, 3775},  {0x00006f, 361},   {0x0000f3, 1167},  {0x0000f4, 1174},
    {0x0000f6, 1193},  {0x0001f5, 1672},  {0x0013bd, 11015}, {0x0001b2, 1372},
    {0x0000f2, 1160},  {0x0003f2, 2194},  {0x000ac3, 7066},  {0x000ab2, 6934},
    {0x0000bd, 702},   {0x0000bc, 691},   {0x000ab6, 6976},  {0x0000b9, 654},
    {0x000ab0, 6915},  {0x000ae2, 7473},  {0x000ae5, 7522},  {0x000ae4, 7504},
    {0x000ae3, 7488},  {0x0000aa, 510},   {0x0000f8, 1213},  {0x0000f5, 1186},
    {0x000bc0, 7891},  {0x00047e, 2234},  {0x000070, 363},   {0x0000b6, 621},
    {0x000028, 80},    {0x000029, 90},    {0x0008ef, 6496},  {0x000025, 40},
    {0x00002e, 127},   {0x0000b7, 631},   {0x000afb, 7781},  {0x00002b, 110},
    {0x0000b1, 576},   {0x000ad4, 7302},  {0x0004b0, 2424},  {0x000aa6, 6833},
    {0x000071, 365},   {0x000bcc, 7938},  {0x00003f, 195},   {0x0000bf, 724},
    {0x000022, 13},    {0x000060, 323},   {0x000027, 69},    {0x000072, 367},
    {0x0001e0, 1593},  {0x0008d6, 6428},  {0x0001f8, 1685},  {0x0003b3, 2011},
    {0x0000ae, 551},   {0x000abe, 7041},  {0x0008fd, 6541},  {0x000ba6, 7862},
    {0x000ad3, 7281},  {0x0008b0, 6127},  {0x0008b7, 6271},  {0x000acd, 7173},
    {0x000aeb, 7617},  {0x000bd8, 7974},  {0x000ad1, 7240},  {0x0009f5, 6763},
    {0x000bfc, 8002},  {0x000073, 369},   {0x0001b6, 1394},  {0x0001b9, 1407},
    {0x0001ba, 1414},  {0x0002fe, 1940},  {0x00ff7e, 13942}, {0x000ad7, 7323},
    {0x0000a7, 482},   {0x00003b, 166},   {0x0004df, 2832},  {0x000ac6, 7101},
    {0x000aca, 7124},  {0x000aac, 6878},  {0x0008c9, 6388},  {0x000afd, 7807},
    {0x00002f, 134},   {0x0009e0, 6568},  {0x000020, 0},     {0x0000df, 1006},
    {0x0000a3, 450},   {0x000074, 371},   {0x0001bb, 1423},  {0x0001fe, 1711},
    {0x000af9, 7753},  {0x000afa, 7763},  {0x0008c0, 6341},  {0x000aa7, 6844},
    {0x0000fe, 1264},  {0x000ac4, 7076},  {0x000ab4, 6953},  {0x0000be, 710},
    {0x0000b3, 598},   {0x0008a4, 5940},  {0x0008ab, 6048},  {0x0008a2, 5910},
    {0x0008a7, 5978},  {0x0008b1, 6149},  {0x0008ad, 6076},  {0x0008a9, 6012},
    {0x0008b5, 6235},  {0x0009f7, 6775},  {0x0008b3, 6183},  {0x000ac9, 7114},
    {0x000acb, 7138},  {0x0003bc, 2053},  {0x000ab3, 6943},  {0x0000b2, 586},
    {0x000ab1, 6924},  {0x000075, 373},   {0x0000fa, 1227},  {0x0002fd, 1933},
    {0x0000fb, 1234},  {0x0000fc, 1246},  {0x0001fb, 1698},  {0x0000f9, 1220},
    {0x0003fe, 2226},  {0x000bc6, 7925},  {0x00005f, 306},   {0x0008dd, 6469},
    {0x0003f9, 2211},  {0x0008fc, 6533},  {0x000ba9, 7883},  {0x0009ec, 6641},
    {0x0009eb, 6627},  {0x000bc3, 7908},  {0x000bd3, 7957},  {0x000bce, 7943},
    {0x0001f9, 1692},  {0x0003fd, 2219},  {0x000076, 375},   {0x0008c1, 6351},
    {0x0009f8, 6780},  {0x0008a6, 5964},  {0x0004de, 2820},  {0x0009e9, 6609},
    {0x000077, 377},   {0x000078, 379},   {0x000079, 381},   {0x0000fd, 1257},
    {0x0000ff, 1270},  {0x0000a5, 468},   {0x00007a, 383},   {0x0001bf, 1456},
    {0x0001bc, 1430},  {0x0001be, 1449}};

RIME_DLL int RimeGetModifierByName(const char* name) {
  const int n = sizeof(modifier_name) / sizeof(const char*);
  if (!name)
    return 0;
  for (int i = 0; i < n; ++i) {
    if (modifier_name[i] && !strcmp(name, modifier_name[i])) {
      return (1 << i);
    }
  }
  return 0;
}

RIME_DLL const char* RimeGetModifierName(int modifier) {
  const int n = sizeof(modifier_name) / sizeof(const char*);
  for (int i = 0; i < n && modifier != 0; ++i) {
    if ((modifier & 1) != 0) {
      return modifier_name[i];
    }
    modifier >>= 1;
  }
  return NULL;
}

RIME_DLL int RimeGetKeycodeByName(const char* name) {
  for (const key_entry* p = keys_by_keyval; p->keyval != XK_VoidSymbol; ++p) {
    if (!strcmp(name, key_names + p->offset)) {
      return p->keyval;
    }
  }
  return XK_VoidSymbol;
}

RIME_DLL const char* RimeGetKeyName(int keycode) {
  const int n = sizeof(keys_by_name) / sizeof(const key_entry);
  for (int i = 0; i < n; ++i) {
    if (keycode == keys_by_name[i].keyval) {
      return key_names + keys_by_name[i].offset;
    }
  }
  return NULL;
}
