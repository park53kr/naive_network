#include <algorithm>

#include "net.hpp"
#include "node.hpp"

namespace naive {
    void net::initialize() {
    // TODO:
    // 1. 접속할 수 있는 Peer 리스트를 가져와야 함
    // 2. 접속한 피어들을 자신의 list에 등록하고 상대방 peer도 자신을 등록할 수 있도록 해야 함(handshake)
    // 3. 각종 이벤트 핸들러 등록 (thread)

        node my();

        auto peer_list = get_peerlist();
        for (auto peer : peer_list) {
            bool alive = is_alive(peer);
            if (alive)
                node_list.push_back(peer);
        }

        for_each(node_list, [](node &n) {
            n.refresh_peer_list(my);
        });
    }

    void net::start() {

    }

    void net::shutdown() {

    }
}