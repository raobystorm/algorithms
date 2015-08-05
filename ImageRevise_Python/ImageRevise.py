import os
import Image
import xml.etree.ElementTree

# the general name of the folder of bounding box
bbFolderStr = "BoundingBox"
# the size of processed image
reSize = [224, 224]

# this is the location of the folder contains image folders
imgFolder = "/media/raoby/UnixExt/ILSVRC2012/train"
# this is the location of the folder contians bounding boxes
bbFolder = "/media/raoby/UnixExt/ILSVRC2012/BoundingBox"

def ImageRevise(imgFolderLoc, bbFolderLoc):
	# The function for all image pre-process
	# @param {imgFolderLoc} the string of folder contains all the folders of all classes
	# @param {bbFolderLoc} the string of folder contains all the xml files for bouding boxes
	# @return {errMsg} the results of the function or the exceptions
	for folder in os.listdir(imgFolderLoc):
		print "ImageRevise is processing the class: " + folder
		folderLoc = imgFolderLoc + "/" + folder
		imgList = os.listdir(folderLoc)
		for imgStr in imgList:
			# processing one image of the class in {folder}
			imgStr = imgStr[0 : imgStr.rfind(".")]
			xmin, xmax, ymin, ymax = 0, 224, 0, 224
			currImg = Image.open(folderLoc + "/" + imgStr + ".JPEG")
			if currImg is not None:
				xmax, ymax = currImg.size
			xmlFileLoc = bbFolderLoc + "/" + folder + "/" + imgStr + ".xml"
			root = xml.etree.ElementTree.parse(xmlFileLoc).getroot()
			if root is not None:
				xmin = int(root.find("object").find("bndbox").find("xmin").text)
				xmax = int(root.find("object").find("bndbox").find("xmax").text)
				ymin = int(root.find("object").find("bndbox").find("ymin").text)
				ymax = int(root.find("object").find("bndbox").find("ymax").text)
			

def singleRevise(imgLoc, xmlFileLoc):
	xmin, xmax, ymin, ymax = 0, 224, 0, 224
	currImg = Image.open(imgLoc);
	if currImg is not None:
		w, h = currImg.size
	root = xml.etree.ElementTree.parse(xmlFileLoc).getroot()
	if root is not None:
		xmin = int(root.find("object").find("bndbox").find("xmin").text)
		xmax = int(root.find("object").find("bndbox").find("xmax").text)
		ymin = int(root.find("object").find("bndbox").find("ymin").text)
		ymax = int(root.find("object").find("bndbox").find("ymax").text)
	currImg = currImg.crop((xmin, h - ymax, xmax, h - ymin))
	currImg = currImg.resize(reSize)
	currImg.save(imgLoc, "JPEG")


singleRevise( "/media/raoby/UnixExt/ILSVRC2012/train/n02132136/n02132136_16.JPEG" ,"/media/raoby/UnixExt/ILSVRC2012/BoundingBox/n02132136/n02132136_16.xml")