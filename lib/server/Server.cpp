#include "Server.h"


Server::Server( int port ) : port( port ), acceptor( ioService, tcp::endpoint( tcp::v4(), port ) ), socket( ioService ) {

}

Server::~Server( ) {
}

void Server::start( ) {
    loadWorld( );

    listenForConnections( );
    handleCommands( );

    ioService.run( );
}

void Server::loadWorld( ) {
    world = make_shared<World>();
}

void Server::listenForConnections( ) {
    std::cout << "waiting on port = " << port << std::endl;

    acceptor.async_accept( socket,
        [this]( boost::system::error_code errorCode ) {
            if( !errorCode ) {
                sessions.emplace_back( std::make_shared<Session>( std::move( socket ) ) );
                sessions.back( )->listenForCommands( );
                sessions.back( )->offerOptionToRegisterOrLogin( );
            }

            listenForConnections();
        }
    );
}

void Server::handleCommands( ) {
    world->performResets( );

    for( auto &session : sessions ) {
        // handle commands that will manipulate the world
        // send data back to clients
        // wait untill next tick
        try {
            if( session->isAlive( ) && session->isLoggedIn( ) ) {
                auto nextCommand = session->getNextCommand( );
                if( nextCommand.compare( "" ) != 0 ) {
                    session->sendMessage( session->executeCommand( nextCommand ) );
                }
            }
        } catch( std::exception &e ) {
            session->kill( );
        }
    }

    try{
        boost::asio::deadline_timer timer( ioService, boost::posix_time::millisec( 16 ) );
        timer.async_wait( boost::bind( &Server::handleCommands, this ) );
    } catch( std::exception &e ) {
        std::cerr << e.what( ) << std::endl;
    }
}
