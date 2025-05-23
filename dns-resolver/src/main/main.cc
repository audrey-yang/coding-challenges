#include "src/lib/dns-resolver-lib.h"

int main(int argc, char **argv)
{
    std::cerr << "Attemping to resolve DNS for " << argv[1] << std::endl;
    in_addr_t ip_addr = resolve_dns(argv[1]);

    if (ip_addr != INADDR_NONE)
    {
        in_addr addr;
        addr.s_addr = ip_addr;
        std::cerr << "Success! Found " << inet_ntoa(addr) << std::endl;
    }
}