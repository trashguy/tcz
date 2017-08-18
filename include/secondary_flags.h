/*

.-----------------------------------------------------------------------------.
| The Chatting Zone (TCZ)                            (C) J.P.Boggis 1993-2004 |
| ~~~~~~~~~~~~~~~~~~~~~~~                            ~~~~~~~~~~~~~~~~~~~~~~~~ |
|-----------------------------------------------------------------------------|
| SECONDARY_FLAGS.H  -  Definitions of secondary object/character flags.      |
|                                                                             |
|                       #define _SECONDARY_FLAGS_H_ARRAYS to include          |
|                       secondary flag list array into source file.           |
|--------------------------[ Copyright Information ]--------------------------|
| This program is free software; you can redistribute it and/or modify        |
| it under the terms of the GNU General Public License as published by        |
| the Free Software Foundation; either version 2 of the License, or           |
| (at your option) any later version.                                         |
|                                                                             |
| This program is distributed in the hope that it will be useful,             |
| but WITHOUT ANY WARRANTY; without even the implied warranty of              |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
| GNU General Public License for more details.                                |
|                                                                             |
| You should have received a copy of the GNU General Public License           |
| along with this program; if not, write to the Free Software                 |
| Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA   |
|-----------------------[ Credits & Acknowledgements ]------------------------|
| For full details of authors and contributers to TCZ, please see the files   |
| MODULES and CONTRIBUTERS.  For copyright and license information, please    |
| see LICENSE and COPYRIGHT.                                                  |
|                                                                             |
| Module originally designed and written by:  J.P.Boggis 15/03/2000.          |
|-------------------------[ The Chatting Zone (TCZ) ]-------------------------|
|                For more information about TCZ, please visit:                |
|                   http://www.sourceforge.net/projects/tcz                   |
`-----------------------------------------------------------------------------'

  $Id: secondary_flags.h,v 1.1.1.1 2004/12/02 17:43:34 jpboggis Exp $

*/


/* ---->  Secondary object flags (db[x].flags2)  <---- */
#define EDIT_OVERWRITE  0x00000001  /*  Text overwrite mode (Editor)?  */
#define VISIT           0x00000001  /*  (Re-used EDIT_OVERWRITE)  Users may only be unconditionally visited (Via VISIT friend flag) if the room/thing they are in has this flag set  */
#define EDIT_EVALUATE   0x00000002  /*  Evaluate {}'s, $'s and \'s (Editor)?  */
#define WARP            0x00000002  /*  (Re-used EDIT_EVALUATE)  Rooms/things without this flag will never be 'warp'ed to, even if they are set ABODE  */
#define LFTOCR_LFCR     0x00000004  /*  Lines should be terminated with LF+CR  */
#define LFTOCR_CRLF     0x00000008  /*  Lines should be terminated with CR+LF  */
#define LFTOCR_CR       0x0000000C  /*  Lines should be terminated with CR  */
#define LFTOCR_MASK     0x0000000C  /*  Used to mask off LFTOCR bits  */
#define CHAT_OPERATOR   0x00000010  /*  Operator of current chatting channel?  */
#define EXPIRY          0x00000010  /*  (Re-used CHAT_OPERATOR)  Object expiry based on creation date rather than last usage date  */
#define CHAT_PRIVATE    0x00000020  /*  Operator has made channel private?  */
#define TRANSPORT       0x00000020  /*  (Re-used CHAT_PRIVATE)   Object can be used as transport (Vehicle)/transport allowed in given room/thing  */
#define CONNECTED       0x00000040  /*  Is character currently connected to TCZ?  */
#define ABORTFUSE       0x00000040  /*  (Re-used CONNECTED)  Fuse intercepts user command and prevents execution (Unless '@continue' command is used with the fuse's compound command.)  */
#define ANSI8           0x00000080  /*  Character would prefer 8 colour ANSI rather than 16  */
#define VALIDATED       0x00000080  /*  (Re-used ANSI8)  Mortal compound command validated for use as a global command  */
#define RETIRED         0x00000100  /*  Admin character has retired (Has Experienced Builder privs.)  */
#define FINANCE         0x00000100  /*  (Re-used RETIRED)  Credits can be dropped in object  */
#define PAGEBELL        0x00000200  /*  Character's terminal should beep when paged  */
#define IMMOVABLE       0x00000200  /*  (Re-used NO_PAGEBELL)  Object cannot be moved  */
/*                      0x00000400      (AVAILABLE  -  Ex. PUBLIC_EMAIL)  */
#define UNDERLINE       0x00000800  /*  Underlines should be used instead of underscores (~)  */
#define SENDHOME        0x00000800  /*  (Re-used UNDERLINE)  Object should be sent to its home on restart of TCZ.  */
#define FRIENDS_CHAT    0x00001000  /*  Friends chatting channel on/off?  */
#define SECURE          0x00001000  /*  (Re-used FRIENDS_CHAT)  Credit dropped in object cannot be taken (Except by object's owner.)  */
#define HTML            0x00002000  /*  World Wide Web Interface currently in use by character (HTML connection through World Wide Web browser)  */
#define INHERITABLE     0x00004000  /*  Someone else can make object a parent without being able to control it  */
#define ORIGINAL        0x00008000  /*  Used during DB dump  -  Object without this flag has been destroyed and re-created during dump (Also used by boolean expression (Object locks) sanity check)  */
#define LOCAL_ECHO      0x00010000  /*  TCZ should echo text typed by user back to their terminal?  */
#define SKIPOBJECTS     0x00010000  /*  (Re-used LOCAL_ECHO)  Non-Admin/owner owned compound commands attached to objects in room/thing will not be executed  */
/*                      0x00020000      (1st bit of Article)  */
/*                      0x00040000      (2nd bit of Article)  */
#define SECRET          0x00080000  /*  Character's current location will not be given away on WHERE and SCAN (If flag is set on character, or room/thing they're in)  */
#define READONLYDESC    0x00100000  /*  Object's description read-only?  */
#define EDIT_NUMBERING  0x00200000  /*  Display line numbers (Editor)?  */
#define MORE_PAGER      0x00400000  /*  Use 'more' paging facility to page large output?  */
#define NON_EXECUTABLE  0x00800000  /*  Compound command/fuse with this flag set cannot be executed  */
#define FORWARD_EMAIL   0x00800000  /*  (Re-used NON-EXECUTABLE)  E-mail forwarding ('tcz.user.name@tczserver.domain') is available for user (Dependant on setting of valid E-mail address.)  */
#define BBS             0x40000000  /*  Character may post messages to the BBS  */
#define MAIL            0x80000000  /*  Character may send mail to other characters  */


/* ---->  Object article flags  <---- */
#define ARTICLE_SHIFT        17
#define ARTICLE_CONSONANT    0x1         /*  Consonant article   (A)  */
#define ARTICLE_VOWEL        0x2         /*  Vowel article      (An)  */
#define ARTICLE_PLURAL       0x3         /*  Plural article   (Some)  */
#define ARTICLE_MASK         0x60000

#define LOWER                0x0         /*  Lowercase                */
#define UPPER                0x1         /*  Uppercase (Capitalised)  */
#define INDEFINITE           0x2         /*  Indefinite article       */
#define DEFINITE             0x4         /*  Definite article         */


#ifdef _SECONDARY_FLAGS_H_ARRAYS


/* ---->  Telnet line termination preference flags  <---- */
struct flag_data flag_list_prefs[] =
{
       {"LFCR",                LFTOCR_MASK,    LFTOCR_LFCR,    '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY, BOOLFLAG_LFTOCR_LFCR},
       {"LF+CR",               LFTOCR_MASK,    LFTOCR_LFCR,    '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION, BOOLFLAG_LFTOCR_LFCR},
       {"CR",                  LFTOCR_MASK,    LFTOCR_CR,      '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION, BOOLFLAG_LFTOCR_CR},
       {"CRLF",                LFTOCR_MASK,    LFTOCR_CRLF,    '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_DISPLAY, BOOLFLAG_LFTOCR_CRLF},
       {"CR+LF",               LFTOCR_MASK,    LFTOCR_CRLF,    '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION, BOOLFLAG_LFTOCR_CRLF},
};


/* ---->  Secondary object flags  <---- */
struct flag_data *flag_list2 =
{
       {"Abort",               ABORTFUSE,      ABORTFUSE,      'a',  4|FLAG_NOT_CHARACTER, 0},
       {"BBS",                 BBS,            BBS,            'b',  4|FLAG_LOG_CHARACTER|FLAG_REASON|FLAG_NOT_INCOMMAND|FLAG_NOT_OWN|FLAG_APPRENTICE|FLAG_PERMISSION, BOOLFLAG_BBS},
       {"Read-Only-Desc",      READONLYDESC,   READONLYDESC,   'd',  8|FLAG_PERMISSION, BOOLFLAG_READONLYDESC},
       {"HTML",                HTML,           HTML,           'h',  8|FLAG_INTERNAL, BOOLFLAG_HTML},
       {"Inheritable",         INHERITABLE,    INHERITABLE,    'i',  8|FLAG_NOT_CHCOMMAND|FLAG_NOT_OWN|FLAG_PERMISSION, BOOLFLAG_INHERITABLE},
       {"SkipObjects",         SKIPOBJECTS,    SKIPOBJECTS,    'o',  8|FLAG_PERMISSION|FLAG_NOT_CHARACTER|FLAG_NOT_INCOMMAND, 0},
       {"Secret",              SECRET,         SECRET,         's',  8, BOOLFLAG_SECRET},
       {"Warp",                WARP,           WARP,           'w',  8|FLAG_NOT_CHARACTER, 0},
       {"Expiry",              EXPIRY,         EXPIRY,         'x',  8|FLAG_NOT_CHARACTER, 0},
       {"Finance",             FINANCE,        FINANCE,        'F',  8|FLAG_NOT_CHARACTER, 0},
       {"SendHome",            SENDHOME,       SENDHOME,       'H',  8|FLAG_NOT_CHARACTER, 0},
       {"Immovable",           IMMOVABLE,      IMMOVABLE,      'I',  8|FLAG_NOT_CHARACTER, 0},
       {"Mail",                MAIL,           MAIL,           'M',  4|FLAG_LOG_CHARACTER|FLAG_REASON|FLAG_NOT_INCOMMAND|FLAG_NOT_OWN|FLAG_APPRENTICE|FLAG_PERMISSION, BOOLFLAG_MAIL},
       {"Visit",               VISIT,          VISIT,          'V',  8|FLAG_NOT_CHARACTER, 0},
       {"Retired",             RETIRED,        RETIRED,        'R',  4|FLAG_LOG_CHARACTER|FLAG_NOT_INCOMMAND|FLAG_NOT_PUPPET|FLAG_NOT_OWN|FLAG_REASON|FLAG_NOT_OBJECT, BOOLFLAG_RETIRED},
       {"Secure",              SECURE,         SECURE,         'S',  8|FLAG_NOT_CHARACTER, 0},
       {"Transport",           TRANSPORT,      TRANSPORT,      'T',  8|FLAG_NOT_CHARACTER, 0},
       {"Validated",           VALIDATED,      VALIDATED,      '@',  4|FLAG_NOT_CHARACTER|FLAG_NOT_INCOMMAND|FLAG_LOG_OBJECT, 0},
       {"8ColourANSI",         ANSI8,          ANSI8,          '\0', 8|FLAG_NOT_OBJECT|FLAG_INTERNAL|FLAG_NOT_DISPLAY, 0},
       {"8-Colour-ANSI",       ANSI8,          ANSI8,          '\0', 8|FLAG_NOT_OBJECT|FLAG_INTERNAL|FLAG_PERMISSION, 0},
       {"ChannelOperator",     CHAT_OPERATOR,  CHAT_OPERATOR,  '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, BOOLFLAG_CHAT_OPERATOR},
       {"Channel-Operator",    CHAT_OPERATOR,  CHAT_OPERATOR,  '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT, BOOLFLAG_CHAT_OPERATOR},
       {"ChatOperator",        CHAT_OPERATOR,  CHAT_OPERATOR,  '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_OPERATOR},
       {"Chat-Operator",       CHAT_OPERATOR,  CHAT_OPERATOR,  '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_OPERATOR},
       {"ChannelPrivate",      CHAT_PRIVATE,   CHAT_PRIVATE,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_PRIVATE},
       {"Channel-Private",     CHAT_PRIVATE,   CHAT_PRIVATE,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_PRIVATE},
       {"ChatPrivate",         CHAT_PRIVATE,   CHAT_PRIVATE,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_PRIVATE},
       {"Chat-Private",        CHAT_PRIVATE,   CHAT_PRIVATE,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT|FLAG_NOT_DISPLAY, BOOLFLAG_CHAT_PRIVATE},
       {"Echo",                LOCAL_ECHO,     LOCAL_ECHO,     '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_ECHO},
       {"Evaluate",            EDIT_EVALUATE,  EDIT_EVALUATE,  '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_EVALUATE},
       {"Financial",           FINANCE,        FINANCE,        '\0', 8|FLAG_NOT_DISPLAY|FLAG_NOT_CHARACTER, 0},
       {"ForwardEmail",        FORWARD_EMAIL,  FORWARD_EMAIL,  '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, 0},
       {"FriendsChat",         FRIENDS_CHAT,   FRIENDS_CHAT,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, 0},
       {"Friends-Chat",        FRIENDS_CHAT,   FRIENDS_CHAT,   '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT, 0},
       {"GoHome",              SENDHOME,       SENDHOME,       '\0', 8|FLAG_NOT_DISPLAY|FLAG_NOT_CHARACTER, 0},
       {"Home",                SENDHOME,       SENDHOME,       '\0', 8|FLAG_NOT_DISPLAY|FLAG_NOT_CHARACTER, 0},
       {"LineNumbers",         EDIT_NUMBERING, EDIT_NUMBERING, '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_NUMBERING},
       {"Line-Numbers",        EDIT_NUMBERING, EDIT_NUMBERING, '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_NUMBERING},
       {"MorePager",           MORE_PAGER,     MORE_PAGER,     '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY, BOOLFLAG_MORE},
       {"More-Pager",          MORE_PAGER,     MORE_PAGER,     '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION, BOOLFLAG_MORE},
       {"NonExecutable",       NON_EXECUTABLE, NON_EXECUTABLE, '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_CHARACTER, 0},
       {"Non-Executable",      NON_EXECUTABLE, NON_EXECUTABLE, '\0', 8|FLAG_INTERNAL|FLAG_NOT_CHARACTER, 0},
       {"Numbering",           EDIT_NUMBERING, EDIT_NUMBERING, '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_NUMBERING},
       {"Numbers",             EDIT_NUMBERING, EDIT_NUMBERING, '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_NUMBERING},
       {"Overwrite",           EDIT_OVERWRITE, EDIT_OVERWRITE, '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_EDIT_OVERWRITE},
       {"PageBell",            PAGEBELL,       PAGEBELL,       '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_PAGEBELL},
       {"Pager",               MORE_PAGER,     MORE_PAGER,     '\0', 8|FLAG_INTERNAL|FLAG_NOT_DISPLAY, BOOLFLAG_MORE},
       {"ReadOnlyDesc",        READONLYDESC,   READONLYDESC,   '\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_READONLYDESC},
       {"Read-OnlyDesc",       READONLYDESC,   READONLYDESC,   '\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_READONLYDESC},
       {"ReadOnly-Desc",       READONLYDESC,   READONLYDESC,   '\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_READONLYDESC},
       {"Security",            SECURE,         SECURE,         '\0', 8|FLAG_NOT_DISPLAY|FLAG_NOT_CHARACTER, 0},
       {"Underline",           UNDERLINE,      UNDERLINE,      '\0', 8|FLAG_INTERNAL|FLAG_PERMISSION|FLAG_NOT_OBJECT, BOOLFLAG_UNDERLINE},
       {"Connected",           CONNECTED,      CONNECTED,      '\0', 8|FLAG_INTERNAL|FLAG_NOT_OBJECT, BOOLFLAG_CONNECTED},

       /* ---->  Article flags  <---- */
       {"Consonant (A)",       ARTICLE_MASK,   ARTICLE_CONSONANT << ARTICLE_SHIFT,'\0', 8|FLAG_PERMISSION, BOOLFLAG_ARTICLE_CONSONANT},
       {"Plural (Some)",       ARTICLE_MASK,   ARTICLE_PLURAL    << ARTICLE_SHIFT,'\0', 8|FLAG_PERMISSION, BOOLFLAG_ARTICLE_PLURAL},
       {"Vowel (An)",          ARTICLE_MASK,   ARTICLE_VOWEL     << ARTICLE_SHIFT,'\0', 8|FLAG_PERMISSION, BOOLFLAG_ARTICLE_VOWEL},
       {"Consonant",           ARTICLE_MASK,   ARTICLE_CONSONANT << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_CONSONANT},
       {"Plural",              ARTICLE_MASK,   ARTICLE_PLURAL    << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_PLURAL},
       {"Vowel",               ARTICLE_MASK,   ARTICLE_VOWEL     << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_VOWEL},
       {"A",                   ARTICLE_MASK,   ARTICLE_CONSONANT << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_CONSONANT},
       {"An",                  ARTICLE_MASK,   ARTICLE_VOWEL     << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_VOWEL},
       {"Some",                ARTICLE_MASK,   ARTICLE_PLURAL    << ARTICLE_SHIFT,'\0', 8|FLAG_NOT_DISPLAY, BOOLFLAG_ARTICLE_PLURAL},
       {NULL,                  0,              0,              '\0', 8|FLAG_INTERNAL, 0}
};

#else

extern struct flag_data *flag_list_prefs;
extern struct flag_data *flag_list2;

#endif
