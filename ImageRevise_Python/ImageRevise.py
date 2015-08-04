import os
import Image

def ImageRevise(imgFolderLoc, reviseMode):
	folderList = os.listdir(imgFolderLoc)
	for (folder in folderList):
		imgList = os.listdir(folder)
		
	