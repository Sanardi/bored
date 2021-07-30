import socket

def connect(server, port):
    # open a connection to vulnserver
    s = socket.socket (socket.AF_INET, socket.SOCK_STREAM)
    s.connect ((server, port))
    return s

def read_until(s, delim=b':'):
    buf = b''
    while not buf.endswith(delim):
        buf += s.recv(1)
    return buf
    
def overflow_input(num_chars=128):
    for i in range(1, num_chars):
        try:
            s = connect(SERVER, PORT)
            read_until(s)
            data = 'A' * i + '\n'
            data = bytes(data, encoding='utf-8')
            s.send(data)
        except:
            print(f"Server crashed with input size {i}")
        finally:
            s.close()

if __name__ == "__main__":
    PORT = 12345
    SERVER = '<THE HOSTNAME OR IP>'    
    s = connect(SERVER, PORT)
    print(read_until(s))
    

