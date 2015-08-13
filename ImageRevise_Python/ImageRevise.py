import os
import Image
import xml.etree.ElementTree

# the general name of the folder of bounding box
bbFolderStr = "BoundingBox"
# the size of processed image
width, height = 224, 224

# this is the location of the folder contains image folders
imgFolder = "/media/raoby/UnixExt/ILSVRC2012/train"
# this is the location of the folder contians bounding boxes
bbFolder = "/media/raoby/UnixExt/ILSVRC2012/BoundingBox"

def singleRevise(imgLoc, xmlFileLoc):
	# The function is used for revise single image
	# @param {imgLoc} the location of target image
	# @param {xmlFileLoc} the location of the bounding box of current image
	# @return {errMsg} the results of the execution
	xmin, xmax, ymin, ymax = 0, 0, 0, 0
	currImg = Image.open(imgLoc);
	if currImg is not None:
		w, h = currImg.size
	try:
		root = xml.etree.ElementTree.parse(xmlFileLoc).getroot()
		# should be careful for the case no bounding box found
		if root is not None:
			xmin = int(root.find("object").find("bndbox").find("xmin").text)
			xmax = int(root.find("object").find("bndbox").find("xmax").text)
			ymin = int(root.find("object").find("bndbox").find("ymin").text)
			ymax = int(root.find("object").find("bndbox").find("ymax").text)
			# because the coordinate for the xml and PIL is different, we need calculate
			currImg = currImg.crop((xmin, h - ymax, xmax, h - ymin))
	except IOError, e:
		# many images are lack of bnb file, ignore the exception
		pass

	desImg = Image.new(currImg.mode, (width, height))
	
	w, h = currImg.size
	# discuss the situation separetely, keep the ratio of image unchange
	if width*1.0/w < height*1.0/h:
		ratio = width*1.0/w
		currImg = currImg.resize((int(w*ratio), int(h*ratio)))
		w, h = currImg.size
		desImg.paste(currImg, (0, (height - h)/2))
	else:
		ratio = height*1.0/h
		currImg = currImg.resize((int(w*ratio), int(h*ratio)))
		w, h = currImg.size
		desImg.paste(currImg, ((width - w)/2, 0))
	desImg.save(imgLoc, "JPEG")


def ImageRevise(imgFolderLoc, bbFolderLoc):
	# The function for all image pre-process
	# @param {imgFolderLoc} the string of folder contains all the folders of all classes
	# @param {bbFolderLoc} the string of folder contains all the xml files for bouding boxes
	# @return {errMsg} the results of the function or the exceptions
	count = 0
	for folder in os.listdir(imgFolderLoc):
		count = count + 1
		print "ImageRevise is processing the class: " + folder + "(" + count + "/1000)"
		folderLoc = imgFolderLoc + "/" + folder
		imgList = os.listdir(folderLoc)
		for imgStr in imgList:
			# processing one image of the class in {folder}
			imgStr = imgStr[0 : imgStr.rfind(".")]
			xmin, xmax, ymin, ymax = 0, 0, 0, 0
			currImgLoc = folderLoc + "/" + imgStr + ".JPEG"
			xmlFileLoc = bbFolderLoc + "/" + folder + "/" + imgStr + ".xml"
			singleRevise(currImgLoc, xmlFileLoc)

ImageRevise( '/media/raoby/UnixExt/ILSVRC2012/train', '/media/raoby/UnixExt/ILSVRC2012/BoundingBox')