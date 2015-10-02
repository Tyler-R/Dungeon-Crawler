#include "Server.h"
// extern "C" {
//     int uv_tcp_init(uv_loop_t *loop, uv_tcp_t *handler);
// }

Server::Server() {
    using namespace std;
    cout << "waiting for client to connect" << endl;
    uv_loop_t *loop = (uv_loop_t*)malloc(sizeof(*loop));
    cout << loop->data << endl;
    free(loop);

    uv_tcp_t server;
    uv_tcp_init(loop, &server);



    cout << "hello world this is the real server" << endl;

}

Server::~Server() {


}
