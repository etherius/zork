/* INIT-- DUNGEON INITIALIZATION SUBROUTINE */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include <stdio.h>

#ifdef __AMOS__
#include <amos.h>
#endif

#include "funcs.h"
#include "vars.h"
#include "DatabaseHandler.h"
#include "Messages.h"

/* This is here to avoid depending on the existence of <stdlib.h> */

extern void srand P((unsigned int));

FILE *dbfile;

#ifndef TEXTFILE
#ifdef __AMOS__
#define TEXTFILE "lib:dtextc.dat"
#else /* ! __AMOS__ */
#ifdef unix
#define TEXTFILE "/usr/games/lib/dunlib/dtextc.dat"
#else /* ! unix */
 I need a definition for TEXTFILE
#endif /* ! unix */
#endif /* ! __AMOS__ */
#endif /* ! TEXTFILE */

#ifndef LOCALTEXTFILE
#define LOCALTEXTFILE "dtextc.dat"
#endif

logical InitialiseGame()
{
    /* System generated locals */
    int i__1;

    /* Local variables */
    int xmax, r2max, dirmax, recno;
    int i, j, k;
    register int ch;
    register FILE *indxfile;
    int mmax, omax, rmax, vmax, amax, cmax, fmax, smax;

    more_init();

/* FIRST CHECK FOR PROTECTION VIOLATION */

    if (protected()) {
	   goto L10000;
    }
    ProtectionViolationMessage();
    ExitGame();

/* NOW START INITIALIZATION PROPER */

L10000:
    mmax = 1050;
/* 						!SET UP ARRAY LIMITS. */
    omax = 220;
    rmax = 200;
    vmax = 4;
    amax = 4;
    cmax = 25;
    fmax = 46;
    smax = 22;
    xmax = 900;
    r2max = 20;
    dirmax = 15;

    rmsg_1.mlnt = 0;
/* 						!INIT ARRAY COUNTERS. */
    objcts_1.olnt = 0;
    rooms_1.rlnt = 0;
    vill_1.vlnt = 0;
    advs_1.alnt = 0;
    cevent_1.clnt = 0;
    exits_1.xlnt = 1;
    oroom2_1.r2lnt = 0;

    state_1.ltshft = 10;
/* 						!SET UP STATE VARIABLES. */
    state_1.mxscor = state_1.ltshft;
    state_1.egscor = 0;
    state_1.egmxsc = 0;
    state_1.mxload = 100;
    state_1.rwscor = 0;
    state_1.deaths = 0;
    state_1.moves = 0;
    time_1.pltime = 0;
    state_1.mungrm = 0;
    state_1.hs = 0;
    prsvec_1.prsa = 0;
/* 						!CLEAR PARSE VECTOR. */
    prsvec_1.prsi = 0;
    prsvec_1.prso = 0;
    prsvec_1.prscon = 1;
    orphs_1.oflag = 0;
/* 						!CLEAR ORPHANS. */
    orphs_1.oact = 0;
    orphs_1.oslot = 0;
    orphs_1.oprep = 0;
    orphs_1.oname = 0;
    hack_1.thfflg = FALSE_;
/* 						!THIEF NOT INTRODUCED BUT */
    hack_1.thfact = TRUE_;
/* 						!IS ACTIVE. */
    hack_1.swdact = FALSE_;
/* 						!SWORD IS INACTIVE. */
    hack_1.swdsta = 0;
/* 						!SWORD IS OFF. */

    recno = 1;
/* 						!INIT DB FILE POINTER. */
    star_1.mbase = 0;
/* 						!INIT MELEE BASE. */
/* INIT, PAGE 3 */

/* INIT ALL ARRAYS. */

    i__1 = cmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR CLOCK EVENTS */
	cevent_1.cflag[i - 1] = FALSE_;
	cevent_1.ctick[i - 1] = 0;
	cevent_1.cactio[i - 1] = 0;
/* L5: */
    }

    i__1 = fmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR FLAGS. */
	flags[i - 1] = FALSE_;
/* L10: */
    }
    findex_1.buoyf = TRUE_;
/* 						!SOME START AS TRUE. */
    findex_1.egyptf = TRUE_;
    findex_1.cagetf = TRUE_;
    findex_1.mr1f = TRUE_;
    findex_1.mr2f = TRUE_;
    findex_1.follwf = TRUE_;
    i__1 = smax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR SWITCHES. */
	switch_[i - 1] = 0;
/* L12: */
    }
    findex_1.ormtch = 4;
/* 						!NUMBER OF MATCHES. */
    findex_1.lcell = 1;
    findex_1.pnumb = 1;
    findex_1.mdir = 270;
    findex_1.mloc = rindex_1.mrb;
    findex_1.cphere = 10;

    i__1 = r2max;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR ROOM 2 ARRAY. */
	oroom2_1.rroom2[i - 1] = 0;
	oroom2_1.oroom2[i - 1] = 0;
/* L15: */
    }

    i__1 = xmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR TRAVEL ARRAY. */
	exits_1.travel[i - 1] = 0;
/* L20: */
    }

    i__1 = vmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR VILLAINS ARRAYS. */
	vill_1.vopps[i - 1] = 0;
	vill_1.vprob[i - 1] = 0;
	vill_1.villns[i - 1] = 0;
	vill_1.vbest[i - 1] = 0;
	vill_1.vmelee[i - 1] = 0;
/* L30: */
    }

    i__1 = omax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR OBJECT ARRAYS. */
	objcts_1.odesc1[i - 1] = 0;
	objcts_1.odesc2[i - 1] = 0;
	objcts_1.odesco[i - 1] = 0;
	objcts_1.oread[i - 1] = 0;
	objcts_1.oactio[i - 1] = 0;
	objcts_1.oflag1[i - 1] = 0;
	objcts_1.oflag2[i - 1] = 0;
	objcts_1.ofval[i - 1] = 0;
	objcts_1.otval[i - 1] = 0;
	objcts_1.osize[i - 1] = 0;
	objcts_1.ocapac[i - 1] = 0;
	objcts_1.ocan[i - 1] = 0;
	objcts_1.oadv[i - 1] = 0;
	objcts_1.oroom[i - 1] = 0;
/* L40: */
    }

    i__1 = rmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR ROOM ARRAYS. */
	rooms_1.rdesc1[i - 1] = 0;
	rooms_1.rdesc2[i - 1] = 0;
	rooms_1.ractio[i - 1] = 0;
	rooms_1.rflag[i - 1] = 0;
	rooms_1.rval[i - 1] = 0;
	rooms_1.rexit[i - 1] = 0;
/* L50: */
    }

    i__1 = mmax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR MESSAGE DIRECTORY. */
	rmsg_1.rtext[i - 1] = 0;
/* L60: */
    }

    i__1 = amax;
    for (i = 1; i <= i__1; ++i) {
/* 						!CLEAR ADVENTURER'S ARRAYS. */
	advs_1.aroom[i - 1] = 0;
	advs_1.ascore[i - 1] = 0;
	advs_1.avehic[i - 1] = 0;
	advs_1.aobj[i - 1] = 0;
	advs_1.aactio[i - 1] = 0;
	advs_1.astren[i - 1] = 0;
	advs_1.aflag[i - 1] = 0;
/* L70: */
    }

    debug_1.dbgflg = 0;
    debug_1.prsflg = 0;
    debug_1.gdtflg = 0;

#ifdef ALLOW_GDT

/* allow setting gdtflg true if user id matches wizard id */
/* this way, the wizard doesn't have to recompile to use gdt */

    if (wizard()) {
	debug_1.gdtflg = 1;
    }

#endif /* ALLOW_GDT */

    screen_1.fromdr = 0;
/* 						!INIT SCOL GOODIES. */
    screen_1.scolrm = 0;
    screen_1.scolac = 0;
/* INIT, PAGE 4 */

/* NOW RESTORE FROM EXISTING INDEX FILE. */

#ifdef __AMOS__
    if ((dbfile = fdopen(ropen(LOCALTEXTFILE, 0), BINREAD)) == NULL &&
	(dbfile = fdopen(ropen(TEXTFILE, 0), BINREAD)) == NULL) { 
#else
    if ((dbfile = fopen(LOCALTEXTFILE, BINREAD)) == NULL &&
	(dbfile = fopen(TEXTFILE, BINREAD)) == NULL) {
#endif
	       ErrorOpeningDatabase();
        InitializationFailureMessage();
        return FALSE_;
    }

    indxfile = dbfile;

    i = ReadInteger(indxfile);
    j = ReadInteger(indxfile);
    k = ReadInteger(indxfile);

/* 						!GET VERSION. */
    if (i != vers_1.vmaj || j != vers_1.vmin) {
	    WrongVersion(i,j,k,vers_1.vmaj,vers_1.vmin,vers_1.vedit);
        InitializationFailureMessage();
        return FALSE_;
    }

    state_1.mxscor = ReadInteger(indxfile);
    star_1.strbit = ReadInteger(indxfile);
    state_1.egmxsc = ReadInteger(indxfile);

    rooms_1.rlnt = ReadInteger(indxfile);
    ReadIntegerArray(rooms_1.rlnt, &rooms_1.rdesc1[0], indxfile);
    ReadIntegerArray(rooms_1.rlnt, &rooms_1.rdesc2[0], indxfile);
    ReadIntegerArray(rooms_1.rlnt, &rooms_1.rexit[0], indxfile);
    ReadKeyValueArray(rooms_1.rlnt, &rooms_1.ractio[0], indxfile);
    ReadKeyValueArray(rooms_1.rlnt, &rooms_1.rval[0], indxfile);
    ReadIntegerArray(rooms_1.rlnt, &rooms_1.rflag[0], indxfile);

    exits_1.xlnt = ReadInteger(indxfile);
    ReadIntegerArray(exits_1.xlnt, &exits_1.travel[0], indxfile);

    objcts_1.olnt = ReadInteger(indxfile);
    ReadIntegerArray(objcts_1.olnt, &objcts_1.odesc1[0], indxfile);
    ReadIntegerArray(objcts_1.olnt, &objcts_1.odesc2[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.odesco[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.oactio[0], indxfile);
    ReadIntegerArray(objcts_1.olnt, &objcts_1.oflag1[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.oflag2[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.ofval[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.otval[0], indxfile);
    ReadIntegerArray(objcts_1.olnt, &objcts_1.osize[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.ocapac[0], indxfile);
    ReadIntegerArray(objcts_1.olnt, &objcts_1.oroom[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.oadv[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.ocan[0], indxfile);
    ReadKeyValueArray(objcts_1.olnt, &objcts_1.oread[0], indxfile);

    oroom2_1.r2lnt = ReadInteger(indxfile);
    ReadIntegerArray(oroom2_1.r2lnt, &oroom2_1.oroom2[0], indxfile);
    ReadIntegerArray(oroom2_1.r2lnt, &oroom2_1.rroom2[0], indxfile);

    cevent_1.clnt = ReadInteger(indxfile);
    ReadIntegerArray(cevent_1.clnt, &cevent_1.ctick[0], indxfile);
    ReadIntegerArray(cevent_1.clnt, &cevent_1.cactio[0], indxfile);
    ReadFlagArray(cevent_1.clnt, &cevent_1.cflag[0], indxfile);

    vill_1.vlnt = ReadInteger(indxfile);
    ReadIntegerArray(vill_1.vlnt, &vill_1.villns[0], indxfile);
    ReadKeyValueArray(vill_1.vlnt, &vill_1.vprob[0], indxfile);
    ReadKeyValueArray(vill_1.vlnt, &vill_1.vopps[0], indxfile);
    ReadIntegerArray(vill_1.vlnt, &vill_1.vbest[0], indxfile);
    ReadIntegerArray(vill_1.vlnt, &vill_1.vmelee[0], indxfile);

    advs_1.alnt = ReadInteger(indxfile);
    ReadIntegerArray(advs_1.alnt, &advs_1.aroom[0], indxfile);
    ReadKeyValueArray(advs_1.alnt, &advs_1.ascore[0], indxfile);
    ReadKeyValueArray(advs_1.alnt, &advs_1.avehic[0], indxfile);
    ReadIntegerArray(advs_1.alnt, &advs_1.aobj[0], indxfile);
    ReadIntegerArray(advs_1.alnt, &advs_1.aactio[0], indxfile);
    ReadIntegerArray(advs_1.alnt, &advs_1.astren[0], indxfile);
    ReadKeyValueArray(advs_1.alnt, &advs_1.aflag[0], indxfile);

    star_1.mbase = ReadInteger(indxfile);
    rmsg_1.mlnt = ReadInteger(indxfile);
    ReadIntegerArray(rmsg_1.mlnt, &rmsg_1.rtext[0], indxfile);

/* Save location of start of message text */
    rmsg_1.mrloc = ftell(indxfile);

/* 						!INIT DONE. */

/* INIT, PAGE 5 */

/* THE INTERNAL DATA BASE IS NOW ESTABLISHED. */
/* SET UP TO PLAY THE GAME. */

    itime_(&time_1.shour, &time_1.smin, &time_1.ssec);
/*    srand(time_1.shour ^ (time_1.smin ^ time_1.ssec)); */

    play_1.winner = aindex_1.player;
    last_1.lastit = advs_1.aobj[aindex_1.player - 1];
    play_1.here = advs_1.aroom[play_1.winner - 1];
    hack_1.thfpos = objcts_1.oroom[oindex_1.thief - 1];
    state_1.bloc = objcts_1.oroom[oindex_1.ballo - 1];

    return TRUE_;
}

void ErrorOpeningDatabase() {
    printf("I can't open %s.\n", TEXTFILE);
}

void WrongVersion(int i , int j , int k , int real_i , int real_j , int real_k) {
    printf("%s is version %1d.%1d%c.\n", TEXTFILE, i, j, k);
    printf("I require version %1d.%1d%c.\n", real_i, real_j,
       real_k);
}
