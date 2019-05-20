/*
 * SwitchProfile.h
 *
 *  Created on: Mar 8, 2019
 *      Author: root
 */

#ifndef OTHER_SWITCHPROFILE_H_
#define OTHER_SWITCHPROFILE_H_
#include <string>
#include <vector>
#include "ofpmessages.h"
using namespace std;
namespace inet {

class SwitchProfile {
public:
    SwitchProfile(uint64_t dp, MacAddress ma, uint8_t sp, int pn, int conn);

    uint64_t getDatapathId() const {
        return datapathId;
    }

    void setDatapathId(uint64_t datapathId = 0) {
        this->datapathId = datapathId;
    }

    const MacAddress& getMac() const {
        return mac;
    }

    void setMac(const MacAddress& mac) {
        this->mac = mac;
    }

    int getPortNumber() const {
        return portNumbers;
    }

    void setPortNumber(int portNumbers = 1) {
        this->portNumbers = portNumbers;
    }

    uint8_t getSwitchPort() const {
        return switchPort;
    }

    void setSwitchPort(uint8_t switchPort) {
        this->switchPort = switchPort;
    }

    int getConnId() const {
        return connId;
    }

    void setConnId(int connId = -1) {
        this->connId = connId;
    }

    int getEthPortNum() const {
        return ethPortNum;
    }

    void setEthPortNum(int ethPortNum = 0) {
        this->ethPortNum = ethPortNum;
    }

    const char* getEthPorts(int k) const {
        return ethPorts[k].c_str();
    }

    void setEthPorts(const char* name) {
        this->ethPorts.push_back(name);
    }
    void setPortHw(uint16_t k,MacAddress mac){
        this->portHwAddr[k]=mac;
    }
    MacAddress getPortHw(uint16_t k){
        return this->portHwAddr.find(k)->second;
    }

private:
    uint64_t datapathId = 0;
    MacAddress mac;
    uint8_t switchPort;
    int portNumbers = 1;
    int ethPortNum = 0;
    int connId = -1;
    vector<string> ethPorts;
    std::map<uint16_t,MacAddress> portHwAddr;

};

} /* namespace inet */

#endif /* OTHER_SWITCHPROFILE_H_ */
