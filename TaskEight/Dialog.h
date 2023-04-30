#ifndef TASKEIGHT_DIALOG_H
#define TASKEIGHT_DIALOG_H
#include "Vector.h"

class Dialog: public Vector{
public:
    Dialog();
    virtual ~Dialog();
    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent (TEvent& event);
    virtual void ClearEvent (TEvent& event);
    [[nodiscard]] int Valid() const;
    void EndExec();
protected:
    int EndState;
};


#endif
