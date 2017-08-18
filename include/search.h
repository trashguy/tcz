/*

.-----------------------------------------------------------------------------.
| The Chatting Zone (TCZ)                            (C) J.P.Boggis 1993-2004 |
| ~~~~~~~~~~~~~~~~~~~~~~~                            ~~~~~~~~~~~~~~~~~~~~~~~~ |
|-----------------------------------------------------------------------------|
| SEARCH.H  -  Definitions for SEARCH.C, implementing object search/listing   |
|              commands such as '@find', '@list', etc.                        |
|                                                                             |
|              #define _SEARCH_H_ARRAYS to include search flag list arrays    |
|              into source file.                                              |
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
| Module originally designed and written by:  J.P.Boggis 03/06/1999.          |
|-------------------------[ The Chatting Zone (TCZ) ]-------------------------|
|                For more information about TCZ, please visit:                |
|                   http://www.sourceforge.net/projects/tcz                   |
`-----------------------------------------------------------------------------'

  $Id: search.h,v 1.1.1.1 2004/12/02 17:43:34 jpboggis Exp $

*/


/* ---->  Search flags for object types  <---- */
#define SEARCH_ALL           0xFFFFFFFF
#define SEARCH_ALL_OBJECTS   (SEARCH_CHARACTER|SEARCH_PROPERTY|SEARCH_VARIABLE|SEARCH_COMMAND|SEARCH_ALARM|SEARCH_ARRAY|SEARCH_THING|SEARCH_EXIT|SEARCH_FUSE|SEARCH_ROOM)
#define SEARCH_ALL_TYPES     (SEARCH_ALL & ~(SEARCH_NOT_OBJECT|SEARCH_NOT_CHARACTER))

#define SEARCH_CHARACTER     0x00000001
#define SEARCH_PROPERTY      0x00000002
#define SEARCH_VARIABLE      0x00000004
#define SEARCH_COMMAND       0x00000008
#define SEARCH_PUPPET        0x00000010
#define SEARCH_ALARM         0x00000020
#define SEARCH_ARRAY         0x00000040
#define SEARCH_THING         0x00000080
#define SEARCH_EXIT          0x00000100
#define SEARCH_FUSE          0x00000200
#define SEARCH_ROOM          0x00000400

#define SEARCH_GLOBAL        0x00400000  /*  Search for global compound commands  */
#define SEARCH_BANNED        0x00800000  /*  Search for banned characters  */
#define SEARCH_JUNKED        0x01000000  /*  Search for objects which have been junked (I.e:  Objects located in #0 (ROOMZERO))  */
#define SEARCH_FLOATING      0x02000000  /*  Search for floating objects (I.e:  Objects not in any linked list attached to another object)  */
#define SEARCH_ANYTHING      0x04000000  /*  Override for above to allow SEARCH_ALL to work correctly  */

#define SEARCH_FRIENDS       0x08000000  /*  '@with':  Process list of friends  */
#define SEARCH_ENEMIES       0x10000000  /*  '@with':  Process list of enemies  */
#define SEARCH_CONNECTED     0x20000000  /*  '@with':  Process list of connected characters  */

#define SEARCH_NOT_OBJECT    0x40000000  /*  Do not search objects (For flags that can only be set on characters.)  */
#define SEARCH_NOT_CHARACTER 0x80000000  /*  Do not search characters (For flags that can only be set on objects.)  */

#define SEARCH_CONTENTS      (SEARCH_CHARACTER|SEARCH_THING|SEARCH_ROOM)
#define SEARCH_PREFERED      (SEARCH_CHARACTER|SEARCH_THING)


/* ---->  Search flags for field types (Fields attached to objects)  <---- */
#define SEARCH_NAME          0x00000001
#define SEARCH_DESC          0x00000002
#define SEARCH_ODESC         0x00000004
#define SEARCH_SUCC          0x00000008
#define SEARCH_OSUCC         0x00000010
#define SEARCH_FAIL          0x00000020
#define SEARCH_OFAIL         0x00000040
#define SEARCH_DROP          0x00000080
#define SEARCH_ODROP         0x00000100
#define SEARCH_AREANAME      0x00000200
#define SEARCH_CSTRING       0x00000400
#define SEARCH_ESTRING       0x00000800
#define SEARCH_INDEX         0x00001000

#define SEARCH_WWW           SEARCH_ODESC
#define SEARCH_RACE          SEARCH_FAIL
#define SEARCH_EMAIL         SEARCH_DROP
#define SEARCH_TITLE         SEARCH_ODROP
#define SEARCH_PREFIX        SEARCH_SUCC
#define SEARCH_SUFFIX        SEARCH_OSUCC
#define SEARCH_LASTSITE      SEARCH_OFAIL


/* ---->  Creation date/last usage date constants  <---- */
#define OP_LT 1
#define OP_GT 2
#define OP_LE 3
#define OP_GE 4


#ifdef _SEARCH_H_ARRAYS


/* ---->  Search list entry  <---- */
struct search_data {
       const char *name;
       int        value;
       int        mask;
       int        alt;
};


/* ---->  Standard object type based search list  <---- */
struct search_data search_objecttype[] =
{
       {"Alarms",           SEARCH_ALARM,     0, 0},
       {"Arrays",           SEARCH_ARRAY,     0, 0},
       {"BannedCharacters", SEARCH_BANNED,    0, 0},
       {"BannedPlayers",    SEARCH_BANNED,    0, 0},
       {"Characters",       SEARCH_CHARACTER, 0, 0},
       {"Chars",            SEARCH_CHARACTER, 0, 0},
       {"Commands",         SEARCH_COMMAND,   0, 0},
       {"CompoundCommands", SEARCH_COMMAND,   0, 0},
       {"Contents",         SEARCH_CONTENTS,  0, 0},
       {"DynamicArrays",    SEARCH_ARRAY,     0, 0},
       {"Exits",            SEARCH_EXIT,      0, 0},
       {"Fuses",            SEARCH_FUSE,      0, 0},
       {"FloatingObjects",  SEARCH_FLOATING,  0, 0},
       {"Globals",          SEARCH_GLOBAL,    0, 0},
       {"GlobalCommands",   SEARCH_GLOBAL,    0, 0},
       {"GlobalCompoundCommands", SEARCH_GLOBAL, 0, 0},
       {"JunkedObjects",    SEARCH_JUNKED,    0, 0},
       {"JunkObjects",      SEARCH_JUNKED,    0, 0},
       {"Locations",        SEARCH_ROOM,      0, 0},
       {"Objects",          SEARCH_THING,     0, 0},
       {"Players",          SEARCH_CHARACTER, 0, 0},
       {"Properties",       SEARCH_PROPERTY,  0, 0},
       {"Puppets",          SEARCH_PUPPET,    0, 0},
       {"Rooms",            SEARCH_ROOM,      0, 0},
       {"Things",           SEARCH_THING,     0, 0},
       {"Variables",        SEARCH_VARIABLE,  0, 0},
       {"Vars",             SEARCH_VARIABLE,  0, 0},
       {NULL,               0,                0, 0}
};


/* ---->  Standard object field based search list  <---- */
struct search_data search_fieldtype[] =
{
       {"Areanames",           SEARCH_AREANAME, 0, SEARCH_NOT_CHARACTER},
       {"Adescriptions",       SEARCH_DESC,     0, SEARCH_ALARM},
       {"Anames",              SEARCH_NAME,     0, SEARCH_ALARM},
       {"Contentsstrings",     SEARCH_CSTRING,  0, SEARCH_NOT_CHARACTER},
       {"Cdescriptions",       SEARCH_DESC,     0, SEARCH_COMMAND},
       {"Cnames",              SEARCH_NAME,     0, SEARCH_COMMAND},
       {"Cstrings",            SEARCH_CSTRING,  0, SEARCH_NOT_CHARACTER},
       {"Descriptions",        SEARCH_DESC,     0, 0},
       {"Drops",               SEARCH_DROP,     0, SEARCH_NOT_CHARACTER},
       {"Emails",              SEARCH_EMAIL,    0, SEARCH_CHARACTER},
       {"Edescriptions",       SEARCH_DESC,     0, SEARCH_EXIT},
       {"Enames",              SEARCH_NAME,     0, SEARCH_EXIT},
       {"Estrings",            SEARCH_ESTRING,  0, SEARCH_NOT_CHARACTER},
       {"Exitstrings",         SEARCH_ESTRING,  0, SEARCH_NOT_CHARACTER},
       {"Exitsstrings",        SEARCH_ESTRING,  0, SEARCH_NOT_CHARACTER},
       {"E-mails",             SEARCH_EMAIL,    0, SEARCH_NOT_OBJECT},
       {"Failures",            SEARCH_FAIL,     0, SEARCH_NOT_CHARACTER},
       {"Fdescriptions",       SEARCH_DESC,     0, SEARCH_FUSE},
       {"Fnames",              SEARCH_NAME,     0, SEARCH_FUSE},
       {"Homepages",           SEARCH_WWW,      0, SEARCH_NOT_OBJECT},
       {"Lastsites",           SEARCH_LASTSITE, 0, SEARCH_NOT_OBJECT},
       {"Names",               SEARCH_NAME,     0, 0},
       {"Nameprefixes",        SEARCH_PREFIX,   0, SEARCH_NOT_OBJECT},
       {"Namesuffixes",        SEARCH_SUFFIX,   0, SEARCH_NOT_OBJECT},
       {"Odescriptions",       SEARCH_ODESC,    0, SEARCH_NOT_CHARACTER},
       {"Odrops",              SEARCH_ODROP,    0, SEARCH_NOT_CHARACTER},
       {"Ofailures",           SEARCH_OFAIL,    0, SEARCH_NOT_CHARACTER},
       {"Osuccesses",          SEARCH_OSUCC,    0, SEARCH_NOT_CHARACTER},
       {"Othersdescriptions",  SEARCH_ODESC,    0, SEARCH_NOT_CHARACTER},
       {"Othersdrops",         SEARCH_ODROP,    0, SEARCH_NOT_CHARACTER},
       {"Othersfailures",      SEARCH_OFAIL,    0, SEARCH_NOT_CHARACTER},
       {"Otherssuccesses",     SEARCH_OSUCC,    0, SEARCH_NOT_CHARACTER},
       {"Outside",             SEARCH_ODESC,    0, SEARCH_NOT_CHARACTER},
       {"Outsidedescriptions", SEARCH_ODESC,    0, SEARCH_NOT_CHARACTER},
       {"Prefixes",            SEARCH_PREFIX,   0, SEARCH_NOT_OBJECT},
       {"Pdescriptions",       SEARCH_DESC,     0, SEARCH_NOT_OBJECT},
       {"Pnames",              SEARCH_NAME,     0, SEARCH_NOT_OBJECT},
       {"Races",               SEARCH_RACE,     0, SEARCH_NOT_OBJECT},
       {"Rdescriptions",       SEARCH_DESC,     0, SEARCH_ROOM},
       {"Rnames",              SEARCH_NAME,     0, SEARCH_ROOM},
       {"Successes",           SEARCH_SUCC,     0, SEARCH_NOT_CHARACTER},
       {"Sites",               SEARCH_LASTSITE, 0, SEARCH_NOT_OBJECT},
       {"Strings",             SEARCH_CSTRING,  0, SEARCH_NOT_CHARACTER},
       {"Suffixes",            SEARCH_SUFFIX,   0, SEARCH_NOT_OBJECT},
       {"Tdescriptions",       SEARCH_DESC,     0, SEARCH_THING},
       {"Titles",              SEARCH_TITLE,    0, SEARCH_NOT_OBJECT},
       {"Tnames",              SEARCH_NAME,     0, SEARCH_THING},
       {"Vdescriptions",       SEARCH_DESC,     0, SEARCH_VARIABLE},
       {"Vnames",              SEARCH_NAME,     0, SEARCH_VARIABLE},
       {"Whomessages",         SEARCH_TITLE,    0, SEARCH_NOT_OBJECT},
       {"Whostrings",          SEARCH_TITLE,    0, SEARCH_NOT_OBJECT},
       {"Webpages",            SEARCH_WWW,      0, SEARCH_NOT_OBJECT},
       {"WorldWideWeb",        SEARCH_WWW,      0, SEARCH_NOT_OBJECT},
       {"WWW",                 SEARCH_WWW,      0, SEARCH_NOT_OBJECT},
       {"@areanames",          SEARCH_AREANAME, 0, SEARCH_NOT_CHARACTER},
       {"@cstrings",           SEARCH_CSTRING,  0, SEARCH_NOT_CHARACTER},
       {"@descriptions",       SEARCH_DESC,     0, 0},
       {"@drops",              SEARCH_DROP,     0, SEARCH_NOT_CHARACTER},
       {"@emails",             SEARCH_EMAIL,    0, SEARCH_NOT_OBJECT},
       {"@estrings",           SEARCH_ESTRING,  0, SEARCH_NOT_CHARACTER},
       {"@failures",           SEARCH_FAIL,     0, SEARCH_NOT_CHARACTER},
       {"@names",              SEARCH_NAME,     0, 0},
       {"@odescriptions",      SEARCH_ODESC,    0, SEARCH_NOT_CHARACTER},
       {"@odrops",             SEARCH_ODROP,    0, SEARCH_NOT_CHARACTER},
       {"@ofailures",          SEARCH_OFAIL,    0, SEARCH_NOT_CHARACTER},
       {"@osuccesses",         SEARCH_OSUCC,    0, SEARCH_NOT_CHARACTER},
       {"@prefixes",           SEARCH_PREFIX,   0, SEARCH_NOT_OBJECT},
       {"@races",              SEARCH_RACE,     0, SEARCH_NOT_OBJECT},
       {"@suffixes",           SEARCH_SUFFIX,   0, SEARCH_NOT_OBJECT},
       {"@whomessages",        SEARCH_TITLE,    0, SEARCH_NOT_OBJECT},
       {"@whostrings",         SEARCH_TITLE,    0, SEARCH_NOT_OBJECT},
       {"@www",                SEARCH_WWW,      0, SEARCH_NOT_OBJECT},
       {NULL,                  0,               0, 0}
};


/* ---->  Primary flags based search list  <---- */
struct search_data search_flagtype[] =
{
       {"Abodes",            ABODE,                         0,           0},
       {"Administrators",    APPRENTICE|WIZARD|ELDER|DEITY, 0,           SEARCH_NOT_OBJECT},
       {"Administration",    APPRENTICE|WIZARD|ELDER|DEITY, 0,           SEARCH_NOT_OBJECT},
       {"Ashcanned",         ASHCAN,                        0,           0},
       {"Ansicolours",       ANSI,                          0,           SEARCH_NOT_OBJECT},
       {"Ansicolors",        ANSI,                          0,           SEARCH_NOT_OBJECT},
       {"Apprentices",       APPRENTICE,                    0,           0},
       {"Apps",              APPRENTICE,                    0,           0},
       {"Assistants",        ASSISTANT,                     0,           SEARCH_NOT_OBJECT},
       {"BBSInform",         BBS_INFORM,                    0,           SEARCH_NOT_OBJECT},
       {"BBS-Inform",        BBS_INFORM,                    0,           SEARCH_NOT_OBJECT},
       {"BBSNotify",         BBS_INFORM,                    0,           SEARCH_NOT_OBJECT},
       {"BBS-Notify",        BBS_INFORM,                    0,           SEARCH_NOT_OBJECT},
       {"Beings",            BEING,                         0,           SEARCH_NOT_OBJECT},
       {"Boot",              BOOT,                          0,           SEARCH_NOT_OBJECT},
       {"Boys",              GENDER_MALE << GENDER_SHIFT,   GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Builders",          BUILDER,                       0,           SEARCH_NOT_OBJECT},
       {"Censored",          CENSOR,                        0,           0},
       {"Censorship",        CENSOR,                        0,           0},
       {"Chown_OK",          TRANSFERABLE,                  0,           0},
       {"ChownOK",           TRANSFERABLE,                  0,           0},
       {"Colours",           ANSI,                          0,           SEARCH_NOT_OBJECT},
       {"Colors",            ANSI,                          0,           SEARCH_NOT_OBJECT},
       {"CombatAreas",       COMBAT,                        0,           SEARCH_NOT_CHARACTER},
       {"Constructors",      BUILDER,                       0,           SEARCH_NOT_OBJECT},
       {"Containers",        OPEN|OPENABLE,                 0,           0},
       {"Dark",              INVISIBLE,                     0,           0},
       {"Deities",           DEITY,                         0,           0},
       {"Deity",             DEITY,                         0,           0},
       {"Druids",            DRUID,                         0,           SEARCH_NOT_OBJECT},
       {"Elders",            ELDER,                         0,           0},
       {"Engaged",           ENGAGED,                       0,           SEARCH_NOT_OBJECT},
       {"Experienced",       EXPERIENCED,                   0,           SEARCH_NOT_OBJECT},
       {"Females",           GENDER_FEMALE << GENDER_SHIFT, GENDER_MASK, SEARCH_NOT_OBJECT},
       {"FriendsInform",     FRIENDS_INFORM,                0,           SEARCH_NOT_OBJECT},
       {"FriendsNotify",     FRIENDS_INFORM,                0,           SEARCH_NOT_OBJECT},
       {"Friends-Inform",    FRIENDS_INFORM,                0,           SEARCH_NOT_OBJECT},
       {"Friends-Notify",    FRIENDS_INFORM,                0,           SEARCH_NOT_OBJECT},
       {"Girls",             GENDER_FEMALE << GENDER_SHIFT, GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Gods",              DEITY,                         0,           SEARCH_NOT_OBJECT},
       {"Havened",           HAVEN,                         0,           0},
       {"Help",              EXPERIENCED|HELP,              0,           SEARCH_NOT_OBJECT},
       {"Invisible",         INVISIBLE,                     0,           0},
       {"Listeners",         LISTEN,                        0,           SEARCH_NOT_OBJECT},
       {"Locked",            LOCKED,                        0,           SEARCH_NOT_CHARACTER},
       {"Locks",             LOCKED,                        0,           SEARCH_NOT_CHARACTER},
       {"Males",             GENDER_MALE << GENDER_SHIFT,   GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Marry",             MARRIED,                       0,           SEARCH_NOT_OBJECT},
       {"Married",           MARRIED,                       0,           SEARCH_NOT_OBJECT},
       {"Men",               GENDER_MALE << GENDER_SHIFT,   GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Morons",            MORON,                         0,           SEARCH_NOT_OBJECT},
       {"Neutered",          GENDER_NEUTER << GENDER_SHIFT, GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Number",            NUMBER,                        0,           SEARCH_NOT_OBJECT},
       {"Object",            OBJECT,                        0,           0},
       {"Opaque",            OPAQUE,                        0,           SEARCH_NOT_CHARACTER},
       {"Openable",          OPENABLE,                      0,           SEARCH_NOT_CHARACTER},
       {"Opened",            OPEN,                          0,           SEARCH_NOT_CHARACTER},
       {"Permanent",         PERMANENT,                     0,           0},
       {"Private",           PRIVATE,                       0,           0},
       {"Quiet",             QUIET,                         0,           0},
       {"ReadOnly",          READONLY,                      0,           0},
       {"Read-Only",         READONLY,                      0,           0},
       {"Sharable",          SHARABLE,                      0,           0},
       {"Shout",             SHOUT,                         0,           SEARCH_NOT_OBJECT},
       {"Sticky",            STICKY,                        0,           0},
       {"Tom",               TOM,                           0,           SEARCH_NOT_CHARACTER},
       {"Tracing",           TRACING,                       0,           0},
       {"Transferable",      TRANSFERABLE,                  0,           0},
       {"Visible",           VISIBLE,                       0,           0},
       {"Wizards",           WIZARD,                        0,           0},
       {"Wizes",             WIZARD,                        0,           0},
       {"Wizs",              WIZARD,                        0,           0},
       {"Women",             GENDER_FEMALE << GENDER_SHIFT, GENDER_MASK, SEARCH_NOT_OBJECT},
       {"Yell",              YELL,                          0,           0},
       {NULL,                0,                             0,           0}
};


/* ---->  Secondary flags based search list  <---- */
struct search_data search_flagtype2[] =
{
       {"8ColorAnsi",        ANSI8,                         0,           SEARCH_NOT_OBJECT},
       {"8ColourAnsi",       ANSI8,                         0,           SEARCH_NOT_OBJECT},
       {"8-Color-Ansi",      ANSI8,                         0,           SEARCH_NOT_OBJECT},
       {"8-Colour-Ansi",     ANSI8,                         0,           SEARCH_NOT_OBJECT},
       {"A",                 ARTICLE_CONSONANT << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"Abort",             ABORTFUSE,                     0,           SEARCH_FUSE},
       {"AbortFuses",        ABORTFUSE,                     0,           SEARCH_FUSE},
       {"An",                ARTICLE_VOWEL     << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"BBS",               BBS,                           0,           SEARCH_NOT_OBJECT},
       {"ChannelOperator",   CHAT_OPERATOR,                 0,           SEARCH_NOT_OBJECT},
       {"Channel-Operator",  CHAT_OPERATOR,                 0,           SEARCH_NOT_OBJECT},
       {"ChatOperator",      CHAT_OPERATOR,                 0,           SEARCH_NOT_OBJECT},
       {"Chat-Operator",     CHAT_OPERATOR,                 0,           SEARCH_NOT_OBJECT},
       {"ChannelPrivate",    CHAT_PRIVATE,                  0,           SEARCH_NOT_OBJECT},
       {"Channel-Private",   CHAT_PRIVATE,                  0,           SEARCH_NOT_OBJECT},
       {"ChatPrivate",       CHAT_PRIVATE,                  0,           SEARCH_NOT_OBJECT},
       {"Chat-Private",      CHAT_PRIVATE,                  0,           SEARCH_NOT_OBJECT},
       {"Connected",         CONNECTED,                     0,           SEARCH_NOT_OBJECT},
       {"Consonants",        ARTICLE_CONSONANT << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"CR",                LFTOCR_CR,                     LFTOCR_MASK, SEARCH_NOT_OBJECT},
       {"CR+LF",             LFTOCR_CRLF,                   LFTOCR_MASK, SEARCH_NOT_OBJECT},
       {"Echo",              LOCAL_ECHO,                    0,           SEARCH_NOT_OBJECT},
       {"Evaluate",          EDIT_EVALUATE,                 0,           SEARCH_NOT_OBJECT},
       {"Expiry",            EXPIRY,                        0,           SEARCH_NOT_CHARACTER},
       {"FChat",             FRIENDS_CHAT,                  0,           SEARCH_NOT_OBJECT},
       {"ForwardEmail",      FORWARD_EMAIL,                 0,           SEARCH_NOT_OBJECT},
       {"Friends-Chat",      FRIENDS_CHAT,                  0,           SEARCH_NOT_OBJECT},
       {"FriendsChat",       FRIENDS_CHAT,                  0,           SEARCH_NOT_OBJECT},
       {"GoHome",            SENDHOME,                      0,           SEARCH_NOT_CHARACTER},
       {"Home",              SENDHOME,                      0,           SEARCH_NOT_CHARACTER},
       {"HTML",              HTML,                          0,           SEARCH_NOT_OBJECT},
       {"Immovable",         IMMOVABLE,                     0,           SEARCH_NOT_CHARACTER},
       {"Inheritable",       INHERITABLE,                   0,           0},
       {"LF+CR",             LFTOCR_LFCR,                   LFTOCR_MASK, SEARCH_NOT_OBJECT},
       {"LocalEcho",         LOCAL_ECHO,                    0,           SEARCH_NOT_OBJECT},
       {"Mail",              MAIL,                          0,           SEARCH_NOT_OBJECT},
       {"More-Paging",       MORE_PAGER,                    0,           SEARCH_NOT_OBJECT},
       {"More-Pager",        MORE_PAGER,                    0,           SEARCH_NOT_OBJECT},
       {"MorePager",         MORE_PAGER,                    0,           SEARCH_NOT_OBJECT},
       {"MorePaging",        MORE_PAGER,                    0,           SEARCH_NOT_OBJECT},
       {"Overwrite",         EDIT_OVERWRITE,                0,           SEARCH_NOT_OBJECT},
       {"PageBell",          PAGEBELL,                      0,           SEARCH_NOT_OBJECT},
       {"Pager",             MORE_PAGER,                    0,           SEARCH_NOT_OBJECT},
       {"Plurals",           ARTICLE_PLURAL << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"RetiredAdministators", RETIRED,                    0,           SEARCH_NOT_OBJECT},
       {"RetiredAdministation", RETIRED,                    0,           SEARCH_NOT_OBJECT},
       {"Secret",            SECRET,                        0,           0},
       {"SendHome",          SENDHOME,                      0,           SEARCH_NOT_CHARACTER},
       {"Some",              ARTICLE_PLURAL << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"Transport",         TRANSPORT,                     0,           SEARCH_NOT_CHARACTER},
       {"Underline",         UNDERLINE,                     0,           SEARCH_NOT_OBJECT},
       {"Validated",         VALIDATED,                     0,           SEARCH_NOT_CHARACTER},
       {"Vehicles",          TRANSPORT,                     0,           SEARCH_NOT_CHARACTER},
       {"Visit",             VISIT,                         0,           SEARCH_NOT_CHARACTER},
       {"Vowels",            ARTICLE_VOWEL  << ARTICLE_SHIFT, ARTICLE_MASK, 0},
       {"Warp",              WARP,                          0,           SEARCH_NOT_CHARACTER},
       {NULL,                0,                             0,           0}
};

#else

extern struct search_data search_objecttype[];
extern struct search_data search_fieldtype[];
extern struct search_data search_flagtype[];
extern struct search_data search_flagtype2[];

#endif
