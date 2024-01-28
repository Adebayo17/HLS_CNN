from variables import *
from cnn import *
from normalization import *
import matplotlib as plt
from save import *

true_detected = []
false_detected = []
n = 10

def main():
    cnn_archi()
    
    test_images = get_images()
    
    for i in range(n):
        j = i
        image_input = test_images[i]
    
        img_conv1 = CNN_Layers['conv1']._convolution_padding(image_input)
        
        img_maxp1 = CNN_Layers['maxpool1'].maxpool(img_conv1)
        
        img_conv2 = CNN_Layers['conv2']._convolution_padding(img_maxp1)
        
        img_maxp2 = CNN_Layers['maxpool2'].maxpool(img_conv2)
    
        img_conv3 = CNN_Layers['conv3']._convolution_padding(img_maxp2)
        
        img_maxp3 = CNN_Layers['maxpool3'].maxpool(img_conv3)
    
        img_reshape = CNN_Layers['reshape'](img_maxp3)

        img_percp =  CNN_Layers['perceptron']._apply_perceptron(img_reshape)
        
        max_index = np.argmax(img_percp[1])
        
        if(max_index == img_percp[0]):
            true_detected.append(j)
        else:
            false_detected.append(j)

    #print("\n")
    print(f'\nThe images detected correctly in range [0, {n-1}] are : \n {true_detected} ')
    print(f'Le taux de prédiction = {(len(true_detected) / n)*100}% pour {n} images\n ')

    print(f'\nThe images detected wrongly in range [0, {n-1}] are : \n {false_detected} ')
    print(f"Le taux d'echec = {(len(false_detected) / n)*100}% pour {n} images\n ")

main()