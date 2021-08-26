### Since OpenSSH servers don't restrict the login password length, you can cause these servers to crash by sending very long passwords which use massive amounts of a the server's CPU to hash. This vulnerability is known as [CVE-2016-6515](https://nvd.nist.gov/vuln/detail/CVE-2016-6515).
## My POC can be downloaded [here](https://github.com/jptr218/openssh_dos/raw/main/openssh_dos.zip) (you will need to unzip)
### Usage:

### `openssh_dos [target IP] [target port] `
