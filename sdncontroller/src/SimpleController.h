//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __SDNCONTROLLER_SIMPLECONTROLLER_H_
#define __SDNCONTROLLER_SIMPLECONTROLLER_H_

#include <omnetpp.h>
#include <map>
#include <cstdlib>
#include <fstream>

#include "other/functions.h"
#include "ofpmessages.h"
#include "includes.h"
#include "other/timer_m.h"

using namespace omnetpp;
using namespace inet;
/**
 * Enums (timers, state of controller)
 */
enum states_of_controller {
    CS_CLOSED = -0x1,
    CS_HELLO_WAIT = 0x0,
    CS_FEATURE_WAIT = 0x1,
    CS_ESTABLISHED = 0x2,
};
//Timers are specified in timer.msg
/**
 * Class represents SimpleSdnController created by swiru95 at Military University of Technology from Warsaw (PL).
 * @Author: Chris Świdrak (kswidrak95@gmail.com) Military University of Technology Warsaw(PL) 2019 year.
 *
 * SimpleController implementation.
 */
class SimpleController: public cSimpleModule, public ILifecycle {
public:
    /**
     * ALL OF METHODS inputs are &queue -> chunkQueue with messages to controller
     * and
     * connId -> identifier of connection (which switch connected to controller is talking).
     */
    /**
     * PacketIn handler.
     */
    virtual void handleOfpPacketIn(ChunkQueue &queue, int connId);
    /**
     * Open Flow Error handler.
     */
    virtual void handleOfpError(ChunkQueue &queue, int connId);
    /**
     * Open Flow Statistics handler (msg from switch!).
     */
    virtual void handleOfpStat(ChunkQueue &queue, int connId);
    /**
     * Open Flow Feature handler.
     */
    virtual void handleOfpFeature(ChunkQueue &queue, int connId, uint16_t headLen);
    /**
     * Open Flow FlowRemoved handler.
     */
    virtual void handleOfpFlowRemoved(ChunkQueue &queue, int connId);
    /**
     * Open Flow Configuration handler. (response to getConf req)
     */
    virtual void handleOfpConfig(ChunkQueue &queue, int connId);
    /**
     * Port Status Handler (ports from switch).
     */
    virtual void handleOfpPortStatus(ChunkQueue &queue, int connId);

    /**
     * Applications are described in api.cc and others...
     * There are only declarations
     */
    virtual void sendingStraightWayARPSwitchApp(ChunkQueue &queue, int connId);
    virtual void sendingResponseARPSwitchApp(ChunkQueue &queue, int connId);
    virtual void sqlExampleApp(ChunkQueue &queue, int connId);
    virtual void floodingARPSwitchApp(ChunkQueue &queue, int connId);
    virtual void sendingResponseAndShuttingDownPortARPSwitchApp(ChunkQueue &queue, int connId);
    virtual void simpleSwitch(ChunkQueue &queue, int connId);
    //YOU CAN ADD YOUR OWN APPLICATION THERE


protected:
    TcpSocket socket;
    map<int,timer*> timersMap;
    map<int,timer*>::iterator itTM;


    //TIME INTERVALS
    simtime_t echoInterval,             //time from any ofp msg->echo
              echoCancelInterval,       //waiting time for echo resp.
              portBlockTimeout,         //period of blocking port (app5)
              helloWaitInterval,        //period of waiting for Hello from switch
              featuresWaitInterval;     //period of waiting for Featurs from switch

    /**
     * There are Open Flow messages statistics (counters).
     */
    int helloRec, helloSend, echoReqRec, echoReqSend, echoRepRec, echoRepSend,
            errorRec, errorSend, featSend, featRec, getConReqSend, getConRepRec,
            setConSend, packInRec, packOutSend, flRemRec, flModSend, portStRec,
            portModSend, statReqSend, statRepRec, barReqSend, barRepRec;
    simsignal_t stateSignal;
    simsignal_t packetSignal;
    /**
     * There are also network messages delivered by PacketIn msgs counters.
     * Can be added for your own need.
     */
    int arpReqRec, arpReqSend, arpRepRec, arpRepSend,
        ipV4Rec, ipV4Send, ipV6Rec;

    //others
    /**
     * Controller state.
     */
    int state;
    //some times for OF
    uint16_t tIdle, tHard;
    //controller steerings
    bool runMininet = false, log2file=false;
    //Choosen application name.
    string application="";
    string dbIpAddr;
    string dbPort;
    string dbUser;
    string dbPassword;
    string dbName;

    /**
     * All connection has own id and created and connected Queue of Chunks.
     */
    std::map<int, ChunkQueue> socketQueue;
    std::map<int, ChunkQueue>::iterator itSQ;
    /**
     * All connected switch has his own SwitchProfile mapped with name (ex. 's1')
     * Its just for human understanding ;-)
     */
    std::map<std::string, SwitchProfile*> switchMap;
    std::map<std::string, SwitchProfile*>::iterator itSM;

    /**
     * Map resolve connection identifier (read up) with switch name
     * (ex. connId=123425 and sw. name='s1')
     */
    std::map<int, std::string> con2switch;
    std::map<int, std::string>::iterator itC2S;

    /*
     *  Other Basic OMNeTpp methods.
     */
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleSelfMessage(cMessage*);
    virtual void finish() override;
    /*
     * Openflow special methods.
     */
    virtual void sendBack(cMessage *msg);
    //Theese methods input is connId
    virtual void sendHello(int);
    virtual void sendFeatureReq(int);
    virtual void sendEchoReq(int);
    virtual void sendEchoRep(int, int);
    virtual void sendBarrierReq(int);
    //connId, flag, len
    virtual void setConfig(int, uint16_t, uint16_t);

    //Standard InitStage and OperationStage INET methods
    virtual int numInitStages() const override {
        return NUM_INIT_STAGES;
    }
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage,
            IDoneCallback *doneCallback) override
            {
        Enter_Method_Silent(); throw cRuntimeError("Unsupported lifecycle operation '%s'", operation->getClassName()); return true;}
};

#endif
