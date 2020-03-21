#import moduels recquired for face detection
import numpy as np
import argparse
import cv2

#code for parsing the command line arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",recquired = True,
	help ="path to input file")
ap.add_argument("-p","--prototxt",recquired = True,
	help = "path to caffe 'deploy' prototype prototxt file")
ap.add_argument("-m","--model",recquired = True,
	help = "path to caffe pre-trained model")
ap.add_argument("-c","--confidence",type=float,default = 0.5,
	help="minimum probability to filter weak detections")
args = vars(ap.parse_args())
# load our serialized model from disk
print("[INFO] loading model...")
net = cv2.dnn.readNetFromCaffe(args["prototxt"], args["model"])
 
# load the input image and construct an input blob for the image
# by resizing to a fixed 300x300 pixels and then normalizing it
image = cv2.imread(args["image"])
(h, w) = image.shape[:2]
blob = cv2.dnn.blobFromImage(cv2.resize(image, (300, 300)), 1.0,
	(300, 300), (104.0, 177.0, 123.0))
