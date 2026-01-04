import cv2
import numpy as np

# Load image
img = cv2.imread("image.jpg")
if img is None:
    raise FileNotFoundError("image.jpg not found")

# Convert BGR (OpenCV default) → YUV
yuv = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)

# Convert back YUV → BGR
rgb_back = cv2.cvtColor(yuv, cv2.COLOR_YUV2BGR)

# Show results
cv2.imshow("Original", img)
cv2.imshow("YUV Converted Back", rgb_back)

cv2.waitKey(0)
cv2.destroyAllWindows()
