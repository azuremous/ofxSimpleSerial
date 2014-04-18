#pragma once

#include "ofSerial.h"
#include "ofEvents.h"
#include "ofThread.h"

#define NUM_BYTES 1

using namespace std;

class ofxSimpleSerial : public ofSerial, public ofThread{
public:
	string message;

	ofxSimpleSerial();
	void sendRequest();
    void start(bool _blocking = true, bool _verbose = false) { startThread(_blocking, _verbose); }
	void startContinuousRead(bool writeByte = true);
	void stopContinuousRead();
	void writeString(string message);

	ofEvent<string> NEW_MESSAGE;

protected:
	string			messageBuffer;
	unsigned char	bytesReturned[NUM_BYTES];
	bool			continuousRead;
	bool			bWriteByte;
	void			initSetup();
    void            threadedFunction();
	//void			update(ofEventArgs & args);
	void			read();
};

