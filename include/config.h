#ifndef __CONFIG_H
#define __CONFIG_H

/**************** Server Config ****************/
#define DEBUG_MODE true

// For Proxy networking
#define NET_PROXY_IP "localhost"            // my IP
#define NET_PROXY_RECV_DC_SERVER_JOIN_PORT 3001
#define NET_PROXY_RECV_WRITE_REQ_PORT 3002
#define NET_PROXY_RECV_ACK_PORT 3003

// Config for DC servers
#define INIT_DC_SERVER_ID 101

// Global Config
#define WRITE_THRESHOLD 3

#endif // __CONFIG_H
