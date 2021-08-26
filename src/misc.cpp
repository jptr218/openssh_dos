#include "hdr.h"

string ran_str(int len) {
    string lc = "abcdefghijklmnopqrstuvwxyz";

    string o;
    for (int i = 0; i < len; i++) {
        o += lc[rand() % 26];
    }

    return o;
}

void waitForCrash(string target, string port) {
    while (1) {
        ssh_session ssh = ssh_new();

        ssh_options_set(ssh, SSH_OPTIONS_HOST, target.c_str());
        ssh_options_set(ssh, SSH_OPTIONS_PORT_STR, port.c_str());
        if (ssh_connect(ssh) == SSH_ERROR) {
            return;
        }
        ssh_disconnect(ssh);
    }
}