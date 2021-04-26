import numpy as np

imagen = np.array([[1,2,3,4,5,6],[7,8,9,10,11,12],[0,0,1,16,17,18],[0,1,0,7,23,24],[1,7,6,5,4,3]])
kernell1 = np.array([[1,1,1],[0,0,0],[2,10,3]])

print(imagen.shape)
print(kernell1.shape)

def Convolution(image, kernel):
    i_fila,i_columna = image.shape
    conv = 0.0

    for i in range(i_fila):
        for j in range(i_columna):
            conv += image[i,j]*kernel[i,j]

    return conv


Convolution(imagen,kernell1)