import json
import list_files_googledrive_working

# External Imports
import os
import sys
import xml.etree.ElementTree as ET

if __name__ == "__main__":
    print ("start downloading gcode")
    downloadedfilepath,fileid = list_files_googledrive_working.downloadfile()
    print ("Downloaded gcode to: " + downloadedfilepath)
    list_files_googledrive_working.deletefile(fileid)
    print (fileid)
