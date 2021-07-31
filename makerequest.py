# -*- coding: utf-8 -*-
"""
Created on Sat Jun 20 18:12:23 2020

@author: Marzia Azam
"""

#import urllib.request
import requests
import random 
from collections import OrderedDict
#import urllib.parse, urllib.error

# This data was created by using the curl method explained above
headers_list = [
    # Firefox 77 Mac
     {
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:77.0) Gecko/20100101 Firefox/77.0",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
        "Accept-Language": "en-US,en;q=0.5",
        "Referer": "https://www.google.com/",
        "DNT": "1",
        "Connection": "keep-alive",
        "Upgrade-Insecure-Requests": "1"
    },
    # Firefox 77 Windows
    {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:77.0) Gecko/20100101 Firefox/77.0",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
        "Accept-Language": "en-US,en;q=0.5",
        "Accept-Encoding": "gzip, deflate, br",
        "Referer": "https://www.google.com/",
        "DNT": "1",
        "Connection": "keep-alive",
        "Upgrade-Insecure-Requests": "1"
    },
    # Chrome 83 Mac
    {
        "Connection": "keep-alive",
        "DNT": "1",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97 Safari/537.36",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
        "Sec-Fetch-Site": "none",
        "Sec-Fetch-Mode": "navigate",
        "Sec-Fetch-Dest": "document",
        "Referer": "https://www.google.com/",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "en-GB,en-US;q=0.9,en;q=0.8"
    },
    # Chrome 83 Windows 
    {
        "Connection": "keep-alive",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97 Safari/537.36",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
        "Sec-Fetch-Site": "same-origin",
        "Sec-Fetch-Mode": "navigate",
        "Sec-Fetch-User": "?1",
        "Sec-Fetch-Dest": "document",
        "Referer": "https://www.google.com/",
        "Accept-Encoding": "gzip, deflate, br",
        "Accept-Language": "en-US,en;q=0.9"
    }
]

proxy_list = [
         {'http': 'http://info61:d4b5953d@188.215.96.128:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.96.202:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.98.27:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.98.198:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.98.219:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.99.207:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.99.213:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.99.233:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.97.167:60099/'},
         {'http': 'http://info61:d4b5953d@188.215.97.196:60099/'},
         {'http': 'http://info61:d4b5953d@195.206.107.162:60099/'},
         
         
         
         ]
         
# Create ordered dict from Headers above
ordered_headers_list = []
for headers in headers_list:
    h = OrderedDict()
    for header,value in headers.items():
        h[header]=value
    ordered_headers_list.append(h)
    
def makeGoodRequest(url):
    
    #url = 'https://httpbin.org/headers'

    for i in range(1):
        #Pick a random browser headers
        proxys = random.choice(proxy_list)
        #headers = random.choice(headers_list)
        #Create a request session
        r = requests.Session()
        r.headers = headers
        r.proxies = proxys
    
    response = r.get(url)
    
    return response


def makeNormalRequest(url):
    response = requests.get(url, auth=('ae0c2c6525', '4'), headers= {"Accept":"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8", "Accept-Encoding":"gzip, deflate", "Accept-Language":"en-GB,en;q=0.5", "Host":"35.190.155.168", "Cache-Control":"max-age=0", "Sec-GPC":"1", "Connection":"keep-alive", "content-type":"application/json","Referer":"http://35.190.155.168/ae0c2c6525/"} )
    
    return response

def makePostRequest(url):
    r = requests.post(url, json={'query': body, 'variables' : variables},  headers={"content-type":"application/json", "x-developer-secret" : key})
    print(r.status_code)
    return r.status_code