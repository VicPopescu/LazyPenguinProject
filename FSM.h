#ifndef FSM_H
#define FSM_H

/*
*   Game State Machine - Handle game states
*   This class will handle:
*       -Removing one state and adding another -> Change states without leaving option to return
*       -Adding one state without removing the previous one -> Pause menus etc.
*       -Removing one state without adding another ->Remove pause states or other state that had been pushed on top of another one
*/


class FSM
{
    public:
        FSM();
        ~FSM();
    protected:
    private:
};

#endif // FSM_H
