import os
import Image
import xml.etree.ElementTree

# the general name of the folder of bounding box
bbFolderStr = "BoundingBox"
# the size of processed image
width, height = 224, 224

# this is the location of the folder contains image folders
imgSrcFolder = "/media/raoby/UnixExt/ILSVRC2012/trainOriginal"
# this is the destination of the image files
imgDstFolder = "/media/raoby/UnixExt/ILSVRC2012/train"
# this is the location of the folder contians bounding boxes
bbFolder = "/media/raoby/UnixExt/ILSVRC2012/bnb"
# this is the location of the folder contains validation images
valSrcFolder = "/media/raoby/UnixExt/ILSVRC2012/validationOriginal"
# this is the output of validation images
valDstFolder = "/media/raoby/UnixExt/ILSVRC2012/validation"
# this is the location contains the bounding boxes of val set
valbbFolder = "/media/raoby/UnixExt/ILSVRC2012/valbnb"

def singleRevise(imgSrcLoc, imgDstLoc, xmlFileLoc):
	# The function is used for revise single image
	# @param {imgLoc} the location of target image
	# @param {imgDstLoc} the location of output images
	# @param {xmlFileLoc} the location of the bounding box of current image
	xmin, xmax, ymin, ymax = 0, 0, 0, 0
	currImg = Image.open(imgSrcLoc);
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
			currImg = currImg.crop((xmin, ymin, xmax, ymax))
	except IOError, e:
		try:
			os.remove(imgDstLoc)
		except OSError, ee:
			pass
		return

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
	desImg.save(imgDstLoc, "JPEG")


def ImageRevise(imgSrcFolder, imgDstFolder, bbFolderLoc):
	# The function for all image pre-process
	# @param {imgSrcFolder} the string of folder contains all the folders of all classes
	# @param {imgDstLoc} the location of output images
	# @param {bbFolderLoc} the string of folder contains all the xml files for bouding boxes
	count = 0
	for folder in os.listdir(imgSrcFolder):
		count = count + 1
		print "ImageRevise is processing the class: " + folder + "(" + str(count) + "/1000)"
		folderLoc = imgSrcFolder + "/" + folder
		dstFolder = imgDstFolder + "/" + folder
		imgList = os.listdir(folderLoc)
		for imgStr in imgList:
			# processing one image of the class in {folder}
			imgStr = imgStr[0 : imgStr.rfind(".")]
			xmin, xmax, ymin, ymax = 0, 0, 0, 0
			srcImgLoc = folderLoc + "/" + imgStr + ".JPEG"
			dstImgLoc = dstFolder + "/" + imgStr + ".JPEG"
			xmlFileLoc = bbFolderLoc + "/" + folder + "/" + imgStr + ".xml"
			singleRevise(srcImgLoc, dstImgLoc, xmlFileLoc)

def TestSetRevise(imgSrcFolder, imgDstFolder, bbFolderLoc):
	# The function for all image pre-process
	# @param {imgSrcFolder} the string of folder contains the validation images
	# @param {imgDstLoc} the location of output images
	# @param {bbFolderLoc} the string of folder contains all the xml files for bouding boxes
	print "Processing the validation set..."
	for imgStr in os.listdir(imgSrcFolder):
		imgStr = imgStr[0:imgStr.rfind(".")]
		srcImgLoc = imgSrcFolder + "/" + imgStr + ".JPEG"
		dstImgLoc = imgDstFolder + "/" + imgStr + ".JPEG"
		xmlFileLoc = bbFolderLoc + "/" + imgStr + ".xml"
		singleRevise(srcImgLoc, dstImgLoc, xmlFileLoc)


#singleRevise('/media/raoby/UnixExt/ILSVRC2012/TrainingSet/n01440764/n01440764_39.JPEG', '/media/raoby/UnixExt/ILSVRC2012/train/n01440764/n01440764_39.JPEG', '/media/raoby/UnixExt/ILSVRC2012/bnb/n01440764/n01440764_39.xml')

#ImageRevise( imgSrcFolder, imgDstFolder, bbFolder)

TestSetRevise(valSrcFolder, valDstFolder, valbbFolder)