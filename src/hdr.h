#pragma once
#include <iostream>
#include <thread>
#include <libssh\libssh.h>

#pragma comment (lib, "ssh.lib")

using namespace std;

string ran_str(int len);
void waitForCrash(string target, string port);
