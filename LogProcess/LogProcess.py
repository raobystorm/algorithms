
import os

patternStr = 'Test net output #8'
LogFileSrc = "/home/raoby/algorithms/LogProcess/log1"
LogFileDst = "/home/raoby/algorithms/LogProcess/log(imageProcessed)"

def logProcess(logSrcLoc, logDstLoc, patternStr):
	# @param {logSrcLoc} the source location of the log file
	# @param {logDstLoc} the destination location of the log file
	srcLog = open(logSrcLoc, 'r')
	dstLog = open(logDstLoc, 'w+')
	for line in srcLog:
		if patternStr in line:
			dstLog.writelines(line[line.rfind(' '):])

logProcess(LogFileSrc, LogFileDst, patternStr)