from variables import *
from convolution import *
from maxpool import *
from perceptron import *
from coeff3x3 import *
from reshape import *


CNN_Layers = {
    "conv1" : any,
    "conv2" : any,
    "conv3" : any,
    "maxpool1" : any,
    "maxpool2" : any,
    "maxpool3" : any,
    "reshape" : any,
    "perceptron" : any
}

def cnn_archi():
    print("Setting the layers of the CNN.")
    get_weights_and_biases()

    # conv1
    print("Setting the 1st convolutional layer.")
    CNN_Layers["conv1"] = ConvolutionalLayer(64, 3, 3, (24, 24))
    CNN_Layers["conv1"].weights = Weights['conv1']
    CNN_Layers["conv1"].biases = Biases['conv1']

    # maxpool 1
    print("Setting the 1st maxpool layer.")
    CNN_Layers["maxpool1"] = MaxpoolLayer(2, 3)

    # conv2
    print("Setting the 2nd convolutional layer.")
    CNN_Layers["conv2"] = ConvolutionalLayer(32, 3, 64, (12, 12))
    CNN_Layers["conv2"].weights = Weights['conv2']
    CNN_Layers["conv2"].biases = Biases['conv2']

    # maxpool 2
    print("Setting the 2nd maxpool layer.")
    CNN_Layers["maxpool2"] = MaxpoolLayer(2, 3)


    # conv3
    print("Setting the 3rd convolutional layer.")
    CNN_Layers["conv3"] = ConvolutionalLayer(20, 3, 32, (6, 6))
    CNN_Layers["conv3"].weights = Weights['conv3']
    CNN_Layers["conv3"].biases = Biases['conv3']

    # maxpool 3
    print("Setting the 3rd maxpool layer.")
    CNN_Layers["maxpool3"] = MaxpoolLayer(2, 3)

    # reshape layer
    print("Setting the reshape layer.")
    CNN_Layers["reshape"] = reshape

    # perceptron
    print("Setting the Perceptron layer.")
    CNN_Layers["perceptron"] = PerceptronLayer(180, 10)
    CNN_Layers["perceptron"].weights = Weights['local3']
    CNN_Layers["perceptron"].biases = Biases['local3']

    print("CNN architecture configuaration terminated.")