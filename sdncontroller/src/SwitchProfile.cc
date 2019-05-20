#include "SwitchProfile.h"
using namespace std;
using namespace inet;
SwitchProfile::SwitchProfile(uint64_t dp, MacAddress ma, uint8_t sp, int pn,
        int conn) {
    this->datapathId = dp;
    this->mac = ma;
    this->switchPort = sp;
    this->portNumbers = pn;
    this->connId = conn;
    this->ethPortNum = this->portNumbers - 1;
}
ostream& operator<<(ostream& s, SwitchProfile* sp) {
    s << "Switch connId=" << sp->getConnId() << endl << "EthPorts:" << endl;
    int i = 0;
    while (i < sp->getEthPortNum()) {
        s << i << ") " << sp->getEthPorts(i)<<" mac: "<<sp->getEthPorts(i)<<endl;
        i++;
    }
    return s;
}
