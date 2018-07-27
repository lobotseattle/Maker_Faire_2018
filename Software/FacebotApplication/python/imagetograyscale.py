import cv2
 
img_rgb = cv2.imread("img_example.jpg")
img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)

img_gray_inv = 255 - img_gray

img_blur = cv2.GaussianBlur(img_gray_inv, ksize=(21, 21),
                            sigmaX=0, sigmaY=0)

def dodgeV2(image, mask):
  return cv2.divide(image, 255-mask, scale=256)


def burnV2(image, mask):
    return 255 - cv2.divide(255-image, 255-mask, scale=256)
  #h=cv2.divide(255-image, 255-mask, scale=256)
  #i=255 – h
  #return h

img_blend = dodgeV2(img_gray, img_blur)
cv2.imshow("pencil sketch", img_blend)
cv2.imwrite("pencil_sketch1.png",img_blend)


image = cv2.imread("img_example.jpg")
raw = image.flatten()
cv2.imwrite("vector_sketch1.png",raw)

#img_canvas = cv2.imread("pencilsketch_bg.jpg")
#img_blend = cv2.multiply(img_blend, img_canvas, scale=1/256)