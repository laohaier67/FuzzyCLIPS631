   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*                  A Product Of The                   */
   /*             Software Technology Branch              */
   /*             NASA - Johnson Space Center             */
   /*                                                     */
   /*             CLIPS Version 6.00  05/12/93            */
   /*                                                     */
   /*             FUZZY MODIFIER HEADER FILE              */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*      Brian L. Donnell                                     */
/*      Bob Orchard (NRCC - Nat'l Research Council of Canada)*/
/*                  (Fuzzy reasoning extensions)             */
/*                  (certainty factors for facts and rules)  */
/*                  (extensions to run command)              */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*************************************************************/



#ifndef _H_fuzzymod
#define _H_fuzzymod

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _FUZZYMOD_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif


#ifndef _H_setup
#include "setup.h"
#endif


#ifndef _H_fuzzyval
#include "fuzzyval.h"
#endif

#ifndef _H_dffnxfun
#include "dffnxfun.h"
#endif


#ifndef _H_extnfunc
#include "extnfunc.h"
#endif


/* structures for the list of modifier functions */

struct modifierListItem
  {
     char *name;   /* name of the modifier */
     void (*modfunc)(void *,struct fuzzy_value *fv);
     struct FunctionDefinition *modClipsfunc;
#if DEFFUNCTION_CONSTRUCT
     DEFFUNCTION *modDeffunc;
#endif      
     struct modifierListItem *next;
  };



/* routines globally accessible and defined in fuzzycom.c */

     LOCALE void initFuzzyModifierList(void *theEnv);
     LOCALE void executeModifyFunction(void *theEnv,struct fuzzy_value *, struct modifierListItem *);
     LOCALE int  AddFuzzyModifier(void *,const char *, void (*)(void *,struct fuzzy_value *),
                                  struct FunctionDefinition *
#if DEFFUNCTION_CONSTRUCT
                                  ,DEFFUNCTION *
#endif
                                 );
     LOCALE void RemoveFuzzyModifier(void *theEnv,const char *);
     LOCALE struct modifierListItem *FindModifier(void *theEnv,const char *mod_name);



#endif /* _H_fuzzymod */
