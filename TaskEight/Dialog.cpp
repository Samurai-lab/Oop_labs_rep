#include "Dialog.h"

Dialog::Dialog() : Vector() {
    EndState = 0;
}


Dialog::~Dialog()
= default;


void Dialog::GetEvent(TEvent &event) {
    std::string OpInt = "+-mszq";
    std::string s;
    std::string param;

    char code;
    std::cout << '>';
    std::cin >> s;
    code = s[0];
    if (OpInt.find(code) >= 0) {
        event.what = notEmptyEvent;
        switch (code) {
            case 'm':
                event.command = createGroup;
                break;
            case 's':
                event.command = displayAll;
                break;
            case 'z':
                event.command = displayAbbrnAllOjb;
                break;
            case '+':
                event.command = addObject;
                break;
            case '-':
                event.command = deleteObject;
                break;
            case 'q':
                event.command = quit;
                break;
        }


        if (s.length() > 1) {
            param = s.substr(1, s.length() - 1);
            int A = atoi(param.c_str());
            event.a = A;
        }
    } else event.what = emptyEvent;//пустое событие
}

int Dialog::Execute() {
    TEvent event{};
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);

    } while (!Valid());
    return EndState;
}

int Dialog::Valid() const {
    if (EndState == 0) return 0; else return 1;
}

void Dialog::ClearEvent(TEvent &event) {
    event.what = emptyEvent;//пустое событие
}

void Dialog::EndExec() {
    EndState = 1;
}

//обработчик событий
void Dialog::HandleEvent(TEvent &event) {
    if (event.what == notEmptyEvent) {
        switch (event.command) {
            case createGroup:
                size = event.a;
                beg = new Object *[size];
                cur = 0;
                ClearEvent(event);
                break;
            case addObject:
                Add();
                ClearEvent(event);
                break;
            case deleteObject:
                Del();
                ClearEvent(event);
                break;
            case displayAll:
                Show();
                ClearEvent(event);
                break;
            case quit:
                EndExec();
                ClearEvent(event);
                break;
            case displayAbbrnAllOjb:
                AvgAge();
                ClearEvent(event);
                break;
            default:
                ClearEvent(event);
                HandleEvent(event);
        };
    };
}
