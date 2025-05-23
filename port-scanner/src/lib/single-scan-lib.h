#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

#define PACKET_LEN 320

/**
 * @brief Structure to hold arguments for port scanning threads.
 *
 * This structure is passed to each scanning thread and contains:
 * - The target server's address information
 * - The port number to scan
 * - The original hostname or IP address as a string for logging
 */
typedef struct port_scan_thread_args_struct
{
    struct sockaddr_in server;
    uint16_t port;
    char hostname[64];
} port_scan_args;

/**
 * @brief Thread function to check if a specific port is open on a host.
 *
 * @param params_in Pointer to port_scan_args struct with target IP and port.
 * @return void* Always returns NULL. Terminates the thread.
 */
void *check_port_vanilla(void *params_in);
void *check_port_syn(void *params_in);

/**
 * @brief Thread function used for sweep scan. Checks port 5000 on a single host.
 *
 * @param params_in Pointer to port_scan_args struct containing target host and port.
 * @return void* Always returns NULL. Terminates the thread.
 */
void *check_port_in_sweep_vanilla(void *params_in);
void *check_port_in_sweep_syn(void *params_in);

struct iphdr
{
    unsigned char iph_ihl : 5, iph_ver : 4;
    unsigned char iph_tos;
    unsigned short int iph_len;
    unsigned short int iph_ident;
    unsigned char iph_flag;
    unsigned short int iph_offset;
    unsigned char iph_ttl;
    unsigned char iph_protocol;
    unsigned short int iph_chksum;
    unsigned int iph_sourceip;
    unsigned int iph_destip;
};
