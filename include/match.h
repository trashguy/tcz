/*

.-----------------------------------------------------------------------------.
| The Chatting Zone (TCZ)                            (C) J.P.Boggis 1993-2004 |
| ~~~~~~~~~~~~~~~~~~~~~~~                            ~~~~~~~~~~~~~~~~~~~~~~~~ |
|-----------------------------------------------------------------------------|
| MATCH.H  -  Definitions for MATCH.C, implementing hierarchical object       |
|             matching (Used extensively throughout TCZ.)                     |
|                                                                             |
|             #define _MATCH_H_ARRAYS to include matching arrays into source  |
|             file.                                                           |
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

  $Id: match.h,v 1.1.1.1 2004/12/02 17:43:26 jpboggis Exp $

*/


/* ---->  Match phases  <---- */
#define MATCH_PHASE_KEYWORD   0  /*  Match keyword or direct reference  */
#define MATCH_PHASE_SELF      1  /*  Search object's contents  */
#define MATCH_PHASE_LOCATION  2  /*  Search object's location  */
#define MATCH_PHASE_AREA      3  /*  Search up area of object's location  */
#define MATCH_PHASE_GLOBAL    4  /*  Search global location (GLOBAL_COMMANDS)  */


/* ---->  Match options  <---- */
#define MATCH_OPTION_SINGLE             0x0001  /*  Match for single occurence only (Non-restartable)  */
#define MATCH_OPTION_MULTIPLE           0x0002  /*  Match for multiple occurences (Fully restartable)  */
#define MATCH_OPTION_PREFERED           0x0004  /*  Matching prefered object type(s) within match_prefered()  */
#define MATCH_OPTION_CONTINUE           0x0008  /*  Continue match  */
#define MATCH_OPTION_ATTACHED           0x0010  /*  Multiple (Attached) match (<OBJECT>:<OBJECT>[:...])  */
#define MATCH_OPTION_PRESERVE           0x0020  /*  Preserve pointers to match search strings when match is popped off the stack  */
#define MATCH_OPTION_NOTIFY             0x0040  /*  Notify user with appropriate error messages during match  */
#define MATCH_OPTION_LISTS              0x0080  /*  Match within object lists of current object  */
#define MATCH_OPTION_SKIP_INVISIBLE     0x0100  /*  Skip objects set INVISIBLE  */
#define MATCH_OPTION_SKIP_ROOMZERO      0x0200  /*  Skip objects located in ROOMZERO (#0)  */
#define MATCH_OPTION_ABSOLUTE_LOCATION  0x0400  /*  If match phase > MATCH_PHASE SELF, specified starting location will be used instead of adjusting to match phase (Used by '.login', '.logout', etc.)  */
#define MATCH_OPTION_COMMAND            0x1000  /*  Match first word of compound command instead of exact match  */
#define MATCH_OPTION_PARENT             0x2000  /*  Set PARENT_OBJECT appropriately  */
#define MATCH_OPTION_RESTRICTED         0x4000  /*  Apply extra contraints to matching objects by #ID (Prevents Experienced Builders, etc. from executing compound commands in (Usually) inaccessible areas and those attached to other characters.)  */
#define MATCH_OPTION_FORCE_EXACT        0x8000  /*  Force exact match on object name  */

#define MATCH_OPTION_DEFAULT               (MATCH_OPTION_SINGLE|MATCH_OPTION_NOTIFY)
#define MATCH_OPTION_DEFAULT_COMMAND       (MATCH_OPTION_MULTIPLE|MATCH_OPTION_RESTRICTED|MATCH_OPTION_PARENT|MATCH_OPTION_SKIP_ROOMZERO)
#define MATCH_OPTION_DEFAULT_AREA_COMMAND  (MATCH_OPTION_DEFAULT_COMMAND|MATCH_OPTION_ABSOLUTE_LOCATION)


/* ---->  Matching types  <---- */
#define MATCH_TYPE_EXACT    0x01  /*  Exact match on object name       */
#define MATCH_TYPE_PARTIAL  0x02  /*  Partial match on object name     */
#define MATCH_TYPE_PREFIX   0x04  /*  Prefix match on object name      */
#define MATCH_TYPE_FIRST    0x08  /*  First word match on object name  */
#define MATCH_TYPE_LIST     0x80  /*  Match within LIST_SEPARATOR (';') separated list  */


/* --->  Order of matching, for each phase  <---- */
struct match_order_data {
       int phase[4];
};


/* ---->  Cnversion of object type NAME to TYPE_...  <---- */
struct name_to_type_data {
       char          *name;
       unsigned char len;
       int           type;
};


#ifdef _MATCH_H_ARRAYS


/* ---->  Order of matching, for each phase  <---- */
struct match_order_data match_order[] = {

/* Self:             Location:       Area:         Global:  */
/* ~~~~~             ~~~~~~~~~       ~~~~~         ~~~~~~~  */
   {{TYPE_CHARACTER, TYPE_CHARACTER, TYPE_COMMAND, TYPE_COMMAND}},
   {{TYPE_THING,     TYPE_THING,     NOTHING,      NOTHING}},
   {{TYPE_EXIT,      TYPE_EXIT,      NOTHING,      NOTHING}},
   {{TYPE_COMMAND,   TYPE_COMMAND,   NOTHING,      NOTHING}},
   {{TYPE_VARIABLE,  NOTHING,        NOTHING,      NOTHING}},
   {{TYPE_PROPERTY,  NOTHING,        NOTHING,      NOTHING}},
   {{TYPE_ARRAY,     NOTHING,        NOTHING,      NOTHING}},
   {{TYPE_FUSE,      NOTHING,        NOTHING,      NOTHING}},
   {{TYPE_ALARM,     NOTHING,        NOTHING,      NOTHING}},
   {{TYPE_ROOM,      NOTHING,        NOTHING,      NOTHING}},
   {{NOTHING,        NOTHING,        NOTHING,      NOTHING}},
};


/*  ---->  Matching type for each object type  <---- */
int match_types[] = {
    0,                                 /*  Free              */
    MATCH_TYPE_PARTIAL,                /*  Thing             */
    MATCH_TYPE_EXACT|MATCH_TYPE_LIST,  /*  Exit              */
    MATCH_TYPE_PARTIAL,                /*  Character         */
    MATCH_TYPE_EXACT,                  /*  Room              */
    MATCH_TYPE_EXACT|MATCH_TYPE_LIST,  /*  Compound Command  */
    MATCH_TYPE_EXACT,                  /*  Fuse              */
    MATCH_TYPE_EXACT,                  /*  Alarm             */
    MATCH_TYPE_EXACT,                  /*  Variable          */
    MATCH_TYPE_EXACT,                  /*  Dynamic Array     */
    MATCH_TYPE_EXACT,                  /*  Property          */
};


/* ---->  Types matched within contents of each object type  <---- */
int match_contents[] = {
    0,                                             /*  Free              */
    SEARCH_COMMAND|SEARCH_CHARACTER|SEARCH_THING,  /*  Thing             */
    SEARCH_COMMAND,                                /*  Exit              */
    0,                                             /*  Character         */
    0,                                             /*  Room              */
    SEARCH_COMMAND,                                /*  Compound Command  */
    0,                                             /*  Fuse              */
    0,                                             /*  Alarm             */
    SEARCH_ARRAY|SEARCH_VARIABLE|SEARCH_PROPERTY,  /*  Variable          */
    SEARCH_ARRAY|SEARCH_VARIABLE|SEARCH_PROPERTY,  /*  Dynamic Array     */
    SEARCH_ARRAY|SEARCH_VARIABLE|SEARCH_PROPERTY,  /*  Property          */
};


/* ---->  Conversion of TYPE_... to SEARCH_...  <---- */
int type_to_search[] = {
    0,                 /*  Free              */
    SEARCH_THING,      /*  Thing             */
    SEARCH_EXIT,       /*  Exit              */
    SEARCH_CHARACTER,  /*  Character         */
    SEARCH_ROOM,       /*  Room              */
    SEARCH_COMMAND,    /*  Compound Command  */
    SEARCH_FUSE,       /*  Fuse              */
    SEARCH_ALARM,      /*  Alarm             */
    SEARCH_VARIABLE,   /*  Variable          */
    SEARCH_ARRAY,      /*  Dynamic Array     */
    SEARCH_PROPERTY,   /*  Property          */
};


/* ---->  Conversion of object type NAME to TYPE_...  <---- */
struct name_to_type_data name_to_type[] = {
       {"Alarm",             0, TYPE_ALARM},
       {"Alarms",            0, TYPE_ALARM},
       {"Array",             0, TYPE_ARRAY},
       {"Arrays",            0, TYPE_ARRAY},
       {"Char",              0, TYPE_CHARACTER},
       {"Character",         0, TYPE_CHARACTER},
       {"Characters",        0, TYPE_CHARACTER},
       {"Chars",             0, TYPE_CHARACTER},
       {"Cmd",               0, TYPE_COMMAND},
       {"Cmds",              0, TYPE_COMMAND},
       {"Command",           0, TYPE_COMMAND},
       {"Commands",          0, TYPE_COMMAND},
       {"Compound Command",  0, TYPE_COMMAND},
       {"Compound Commands", 0, TYPE_COMMAND},
       {"CompoundCommand",   0, TYPE_COMMAND},
       {"CompoundCommands",  0, TYPE_COMMAND},
       {"Dynamic Array",     0, TYPE_ARRAY},
       {"Dynamic Arrays",    0, TYPE_ARRAY},
       {"DynamicArray",      0, TYPE_ARRAY},
       {"DynamicArrays",     0, TYPE_ARRAY},
       {"Exit",              0, TYPE_EXIT},
       {"Exits",             0, TYPE_EXIT},
       {"Fuse",              0, TYPE_FUSE},
       {"Fuses",             0, TYPE_FUSE},
       {"Prop",              0, TYPE_PROPERTY},
       {"Property",          0, TYPE_PROPERTY},
       {"Properties",        0, TYPE_PROPERTY},
       {"Props",             0, TYPE_PROPERTY},
       {"Room",              0, TYPE_ROOM},
       {"Rooms",             0, TYPE_ROOM},
       {"Thing",             0, TYPE_THING},
       {"Things",            0, TYPE_THING},
       {"Var",               0, TYPE_VARIABLE},
       {"Variable",          0, TYPE_VARIABLE},
       {"Variables",         0, TYPE_VARIABLE},
       {"Vars",              0, TYPE_VARIABLE},
       {NULL,                0, 0},
};

#else

extern struct match_order_data  match_order    [];
extern        int               match_types    [];
extern        int               match_contents [];
extern        int               type_to_search [];
extern struct name_to_type_data name_to_type   [];

#endif
