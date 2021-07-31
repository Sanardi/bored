# Thank you so much MR. GUS KHAWAJA for teaching me how to do this.

import argparse
from socket import *

# Usage python3 PortScanner.py - a 192.168.0.1 -p 21,80,8080,8081,8443

def printBanner(connSock, tgtPort):
    try:
        # Send data to target
        if tgtPort == 80:
            connSock.send("GET HTTP/1.1 \r\n")
        else:
            connSock.send("\r\n")
        # Receive data from target
        results = connSock.recv(4096)
        # Print the banner
        print('[+] Banner: '+ str(results))
    except:
        print(" [+] Banner not available\n")


def connScan(tgtHost, tgtPort):
    try:
        # Create the socket object
        connSock=socket(AF_INET,SOCK_STREAM)
        # try to connect with the target
        connSock.connect((tgtHost,tgtPort))
        print('[+] {} tcp open'.format(tgtPort))
        printBanner(connSock,tgtPort)
    except:
        # Print failure
        print(' [+] {} tcp closed'.format(tgtPort))
    finally:
        # close the socket object
        connSock.close()


def portScan(tgtHost, tgtPorts):
    try:
        # if -a was not an IP address the will resolve it to an IP
        tgtIP = gethostbyname(tgtHost)
    except:
        print("[-] Error Unknown Host")
        exit(0)
    try:
        # if the domain can be resolved
        tgtName = gethostbyaddr(tgtIP)
        print("[+] --- Scan result for: " + tgtName[0] + " ---")
    except:
        print("[+] --- Scan result for: " + tgtIP+ " ---")

    setdefaulttimeout(10)
    # For each port number call connScan function
    for tgtPort in tgtPorts:
        connScan(tgtHost, int(tgtPort))


def main():
    # Parse the command line arguments:
    parser = argparse.ArgumentParser("Smart TCP Client Scanner")
    parser.add_argument("-a", "--address", type=str, help="the target IP address")
    parser.add_argument("-p", "--port", type=str, help="the target port")
    args = parser.parse_args()
    print(args)
    # Store the argument values
    ipAddress = args.address
    portNumbers = args.port.split(',')
    portScan(ipAddress, portNumbers)
    print(portNumbers)



if __name__ == "__main__":
    main()