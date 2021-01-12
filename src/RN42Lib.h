#ifndef RN42Lib_H
#define RN42Lib_H

#include "Arduino.h"

class RN42{
    public:
    Rn42(Stream port);
    
    bool setBluetoothProfile( char mode[], char deviceName[]);
    bool sendCmd();
    bool connected();

    void sendASCIIByte();
    void sendASCIIChar();
    void sendASCIIInt();
    void sendASCIIFloat();
    void sendASCIILong();
    void sendASCIIString();

    void keyboardPress(char letter, byte modifier);
    void keyboardRelease(char letter, byte modifier);
    void keyboardReleaseAll();

    void mouseClick(byte mouseButton);
    void mouseMove(signed int XAxis, signed int YAxis);
    void mouseWheel(signed int wheel);
    void mouseRelease(byte mouseButton);
    void mouseReleaseAll();

    void audioButtonPress(byte audioButton);
    void audioButtonRelease();

    void JoyPadPress(int buttonNum);

    byte readRaw();

    int available();

    private:

    char nextMessage[];
    void loadNextMessage();
    byte getNextMessageByte();
    bool isWantedResponse(char response[]);

    

};
#endif