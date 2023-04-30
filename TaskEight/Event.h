#ifndef TASKEIGHT_EVENT_H
#define TASKEIGHT_EVENT_H


const int emptyEvent = 0;
const int notEmptyEvent = 100;
const int addObject = 1;
const int deleteObject = 2;
const int displayAbbrnAllOjb = 3;
const int displayAll = 4;
const int createGroup = 6;
const int quit = 101;

struct TEvent {
    int what;
    int command;
    int a;
};

#endif
