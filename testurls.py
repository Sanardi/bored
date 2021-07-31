from makerequest import makeGoodRequest
from makerequest import makeNormalRequest

str1 = "https://static1.squarespace.com/static/54e8ba93e4b07c3f655b452e/t/56c2a04520c64707756f4267/1493764650017/"

str2 = "https://static1.squarespace.com/static/54e8ba93e4b07c3f655b452e/t/56c2a04520c64707756f4267/1493764650017/"

stringlist1 = str1.split()
# print(stringlist1)


for letter in zip(str1, str2):
    
    if letter[0] != letter[1]:
        print(letter[0] + " mismatch!")
    #else: 
        #print(letter[0] + " match")

    
url = "http://35.190.155.168/ae0c2c6525/page/4"

response = makeGoodRequest(url)
print(response.text)


response = makeNormalRequest(url)
print(response.text)

        


