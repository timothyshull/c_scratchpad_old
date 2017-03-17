cmake_minimum_required(VERSION 3.3)
project(libapue.a)

include_directories(../include)

set(SOURCE_FILES
        bufargs.c
        cliconn.c
        clrfl.c
        daemonize.c
        error.c
        errorlog.c
        lockreg.c
        locktest.c
        Makefile
        nspipe.c
        openmax.c
        Orecvfd.c
        pathalloc.c
        popen.c
        prexit.c
        prmask.c
        ptyfork.c
        ptyopen.c
        readn.c
        recvfd.c
        semaph.c
        senderr.c
        sendfd.c
        servaccept.c
        servlisten.c
        setfd.c
        setfl.c
        signal.c
        signalintr.c
        sleep.c
        sleepus.c
        spipe.c
        strerror.c
        tellwait.c
        ttymodes.c
        writen.c ../ch_3/3_1_main.c)

add_library(apue ${SOURCE_FILES})