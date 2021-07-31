# Thank you so much MR. GUS KHAWAJA for teaching me how to do this.

import socket
import threading
import argparse


def serveClient(clientToServSocket, clientIPAddress, portNumber):
    pass

def startServer(portNumber):
    pass

def main():
    parser = argparse.ArgumentParser('TCP server')
    parser.add_argument("-p", "--port", type=int,  default = 4444, help = "The port number to connect with")
    args = parser.parse_args()
    
    portNumber = args.port

    # call the start server function
    startServer(portNumber)
    




if __name__ == "__main__":
    main()