# -*- coding: utf-8 -*-
"""
Created on Fri Feb  7 17:56:07 2020
Author: Cathrine Azam"""


import regex as re
import pandas as pd
import time;
from random import randint
import os
import os.path
import errno
from datetime import datetime
from tika import parser
import zipfile


class PdfParser:
    """A simple python pdf-scanner that receives 3 desired keywords in a textfile
    and generates a folder where it places the those pdf's that contain the keywords.
    This is useful for pre-selecting CV's from all candidates for specific skills.
    On linux make sure you have done:
    sudo apt install build-essential libpoppler-cpp-dev pkg-config python3-dev"""

    def __init__(self, keywords='desired_skills.txt', cvs='cvs.zip'):
        
        self.zipfolder = cvs
        self.keywords = keywords

        with open(keywords) as f:
            self.keywords_words = f.read().splitlines()
            print(self.keywords_words)


    def make_dir_matches(self):
    
        date_of_search = datetime.now().strftime('%Y-%m-%d_%H-%M-%S')
        directory1 = str(date_of_search) + "great_fit"
        try:
            os.makedirs(directory1)
        except OSError as e:
            if e.errno != errno.EEXIST:
                raise
    
        file_name = os.path.splitext(os.path.basename(os.path.realpath(__file__)))[0]
        full_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), directory1)
        print(full_path)

        if not os.path.exists(full_path):
           os.mkdir(full_path)

        file_name_final = r'\great.csv'

        file2write = open(full_path + file_name_final, 'w')
        file2write.write("here goes the data")
        file2write.close()

    def scan_cvs(self):
        directory2 = "tmp_cvs"
        tmp_cvs_path = os.path.join(os.path.dirname(
            os.path.realpath(__file__)), directory2)
        with zipfile.ZipFile(self.zipfolder, 'r') as zip_ref:
            zip_ref.extractall(directory2)

        raw = parser.from_file(r'tmp_cvs/cvs/resume.pdf')
        print(raw['content'])


if __name__ == '__main__':
    run_routine = PdfParser()
    run_routine.make_dir_matches()
    run_routine.scan_cvs()
