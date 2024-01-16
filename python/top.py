from variables import *
from cnn import *
from normalization import *
import matplotlib as plt
from save import *

true_detected = []
false_detected = []
n = 1

def main():
    cnn_archi()
    
    test_images = get_images()
    
    for i in range(n):
        j = i
        image_input = test_images[i]
        #print(f"Img input  {j} feature 0 = \n", image_input[1][0])
        #print(f"Img type  {j} type = {type(image_input[1][0][0][0])} \n")
    
        img_conv1 = CNN_Layers['conv1']._convolution_padding(image_input)
        #print(f"Conv1 coeff : {CNN_Layers['conv1'].weights}\n")
        #print(f"Conv1 output {j} feature 0 shape = \n", img_conv1[1][0].shape)
        #print(f"Conv1 output {j} feature 0 = \n", img_conv1[1][0])
        
        img_maxp1 = CNN_Layers['maxpool1'].maxpool(img_conv1)
        #print(f"Maxpool1 output {j} feature 0 = \n", img_maxp1[1][0])
        
        img_conv2 = CNN_Layers['conv2']._convolution_padding(img_maxp1)
        #print(f"Conv2 output {j} feature 0 = \n", img_conv2[1][0])
        
        img_maxp2 = CNN_Layers['maxpool2'].maxpool(img_conv2)
        #print(f"Maxpool2 output {j} feature 0 = \n", img_maxp2[1])
    
        img_conv3 = CNN_Layers['conv3']._convolution_padding(img_maxp2)
        #print(f"Conv3 output {j} feature 0 = \n", img_conv3[1][0])
        
        img_maxp3 = CNN_Layers['maxpool3'].maxpool(img_conv3)
        #print(f"Maxpool3 output {j} feature 0 = \n", img_maxp3[1])
    
        img_reshape = CNN_Layers['reshape'](img_maxp3)
        #print(f"Reshape output {j} = \n", img_maxp3)

        img_percp =  CNN_Layers['perceptron']._apply_perceptron(img_reshape)
    
        #print("\n")
        #print(f"CNN output {j} = \n", img_percp)
        
        max_index = np.argmax(img_percp[1])

        print(f"label = {max_index}")
        
        if(max_index == img_percp[0]):
            true_detected.append(j)
        else:
            false_detected.append(j)

    print("\n")
    print(f'\nThe images detected correctly in range [0, {n-1}] are : \n {true_detected} ')
    print(f'Le taux de prédiction = {(len(true_detected) / n)*100}% pour {n} images\n ')

    print(f'\nThe images detected wrongly in range [0, {n-1}] are : \n {false_detected} ')
    print(f"Le taux d'echec = {(len(false_detected) / n)*100}% pour {n} images\n ")

main()