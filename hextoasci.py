filehandle = "ncfile.txt"

filelist = []
with open(filehandle) as f:
    lines = f.readlines()
    filelist = [line.replace(" \n", "") for line in lines]
    f.close()

print(filelist)

stroutput = ""
for char in filelist:
    # byte_array = bytearray.fromahex(char)
    # chardecoded = byte_array.decode()
    chardecoded = chr(int(char))
    stroutput += chardecoded

print(stroutput)


