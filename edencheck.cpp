#include <eosio/eosio.hpp>
#include <members.hpp>

using namespace eosio;

namespace sx {
class [[eosio::contract("edencheck")]] edencheck : public contract {
public:
    using contract::contract;

    [[eosio::action]]
    void check(const name account ) {
        eden::member_v0 _member( "genesis.eden"_n, 0 );
        auto itr = _member.find( account.value );

        if ( itr != _member.end() ) {
            print("exists");
        } else {
            print("does not exists")
        }
    };
}